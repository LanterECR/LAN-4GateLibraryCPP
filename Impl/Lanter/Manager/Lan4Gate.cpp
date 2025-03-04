#include "Lan4Gate.h"

#include <random>
#include <chrono>

#include "Lanter/Utils/FieldRangeChecker.h"
#include "Lanter/Message/Request/RequestDataFactory.h"
#include "Lanter/Message/Response/ResponseDataFactory.h"
#include "Lanter/Message/Notification/NotificationDataFactory.h"
#include "Lanter/Message/Interface/InterfaceDataFactory.h"
#include "Lanter/Message/Gateway/GatewayDataFactory.h"
#include "Lanter/Message/Interaction/InteractionDataFactory.h"
#include "Lanter/Message/Receipt/ReceiptDataFactory.h"
#include "Lanter/MessageProcessor/Parser/MessageParserFactory.h"
#include "Lanter/MessageProcessor/Builder/MessageBuilderFactory.h"
#include "Lanter/Manager/Lan4GateLogger.h"

namespace Lanter
{
    namespace Manager
    {
        Lan4Gate::Lan4Gate() : m_IsStarted(false) {}

        Lan4Gate::~Lan4Gate()
        {
            Lan4Gate::stop();
        }

        bool Lan4Gate::setEcrNumber(int64_t ecrNumber)
        {
            if(!m_IsStarted)
            {
                if(Utils::checkEcrNumberRange(ecrNumber))
                {
                    m_EcrNumber = ecrNumber;
                    return true;
                }
            }

            return false;
        }

        int64_t Lan4Gate::getEcrNumber() const
        {
            return m_EcrNumber;
        }

        ILan4Gate::Status Lan4Gate::start()
        {
            if(!m_IsStarted) {
                m_IsStarted = m_Communication != nullptr;
                m_IsStarted = m_IsStarted && createParser();
                m_IsStarted = m_IsStarted && createBuilder();
                m_IsStarted = m_IsStarted && openConnection();
            }
            return m_IsStarted ? ILan4Gate::Status::Success : ILan4Gate::Status::Error;
        }

        ILan4Gate::Status Lan4Gate::stop()
        {
            m_IsStarted = false;

            if(m_MainThread != nullptr)
            {
                m_MainThread->join();
                m_MainThread.reset();
            }

            closeConnection();
            waitFuture();
            return m_IsStarted ? ILan4Gate::Status::Error : ILan4Gate::Status::Success;
        }

        bool Lan4Gate::isStarted() const
        {
            return m_IsStarted;
        }

        void Lan4Gate::doLan4Gate()
        {
            try
            {
                if (m_IsStarted)
                {
                    doCommunication();
                    if (isConnected())
                    {
                        sendData();
                        receiveData();
                        notify();
                    }
                    else
                    {
                        connect();
                    }
                }
                else
                {
                    closeConnection();
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        ILan4Gate::Status Lan4Gate::runOnThread()
        {
            Status result = ILan4Gate::Status::Error;

            try
            {
                if(m_MainThread == nullptr)
                {
                    auto threadLoop = [this]()
                    {
                        while(isStarted())
                        {
                            doLan4Gate();
                            int sleepTimeout = 1; //ms
                            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeout));
                        }
                    };

                    if(start() == ILan4Gate::Status::Success)
                    {
                        m_MainThread = std::make_shared<std::thread>(threadLoop);
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }

            if(m_MainThread != nullptr && m_MainThread->joinable() && isStarted())
            {
                result = ILan4Gate::Status::Success;
            }

            return result;
        }

        bool Lan4Gate::setCommunication(std::shared_ptr<Communication::ICommunication> communication)
        {
            if(resetCommunication())
            {
                m_Communication = communication;
            }
            return m_Communication == communication;
        }

        bool Lan4Gate::resetCommunication()
        {
            if(m_Communication)
            {
                if(closeConnection())
                {
                    m_Communication.reset();
                }
            }
            return m_Communication == nullptr;
        }

        std::shared_ptr<Communication::ICommunication> Lan4Gate::getCommunication() const
        {
            return m_Communication;
        }

        size_t Lan4Gate::addRequestCallback(Callback::IRequestCallback &callback)
        {
            size_t id = generateID();
            while (m_RequestCallbacks.find(id) != m_RequestCallbacks.end())
            {
                id = generateID();
            }

            m_RequestCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeRequestCallback(size_t id)
        {
            auto item = m_RequestCallbacks.find(id);
            if(item != m_RequestCallbacks.end())
            {
                const size_t size = m_RequestCallbacks.size();
                m_RequestCallbacks.erase(item);

                return ((size - m_RequestCallbacks.size()) > 0);
            }

            return false;
        }

        size_t Lan4Gate::requestCallbacksCount() const
        {
            return m_RequestCallbacks.size();
        }

        size_t Lan4Gate::addResponseCallback(Callback::IResponseCallback &callback)
        {
            size_t id = generateID();
            while (m_ResponseCallbacks.find(id) != m_ResponseCallbacks.end())
            {
                id = generateID();
            }

            m_ResponseCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeResponseCallback(size_t id)
        {
            auto item = m_ResponseCallbacks.find(id);
            if(item != m_ResponseCallbacks.end())
            {
                const size_t size = m_ResponseCallbacks.size();
                m_ResponseCallbacks.erase(item);

                return ((size - m_ResponseCallbacks.size()) > 0);
            }

            return false;
        }

        size_t Lan4Gate::responseCallbacksCount() const
        {
            return m_ResponseCallbacks.size();
        }

        size_t Lan4Gate::addNotificationCallback(Callback::INotificationCallback &callback)
        {
            size_t id = generateID();
            while (m_NotificationCallbacks.find(id) != m_NotificationCallbacks.end())
            {
                id = generateID();
            }

            m_NotificationCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeNotificationCallback(const size_t& id)
        {
            auto item = m_NotificationCallbacks.find(id);
            if(item != m_NotificationCallbacks.end())
            {
                const size_t size = m_NotificationCallbacks.size();
                m_NotificationCallbacks.erase(item);

                return (size - m_NotificationCallbacks.size() > 0);
            }

            return false;
        }

        size_t Lan4Gate::notificationCallbacksCount() const
        {
            return m_NotificationCallbacks.size();
        }

        size_t Lan4Gate::addInterfaceCallback(Callback::IInterfaceCallback& callback)
        {
            size_t id = generateID();
            while (m_InterfaceCallbacks.find(id) != m_InterfaceCallbacks.end())
            {
                id = generateID();
            }

            m_InterfaceCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeInterfaceCallback(const size_t& id)
        {
            auto item = m_InterfaceCallbacks.find(id);
            if (item != m_InterfaceCallbacks.end())
            {
                const size_t size = m_InterfaceCallbacks.size();
                m_InterfaceCallbacks.erase(item);

                return (size - m_InterfaceCallbacks.size() > 0);
            }

            return false;
        }

        size_t Lan4Gate::interfaceCallbacksCount() const
        {
            return m_InterfaceCallbacks.size();
        }

        size_t Lan4Gate::addGatewayCallback(Callback::IGatewayCallback& callback)
        {
            size_t id = generateID();
            while (m_GatewayCallbacks.find(id) != m_GatewayCallbacks.end())
            {
                id = generateID();
            }

            m_GatewayCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeGatewayCallback(const size_t& id)
        {
            auto item = m_GatewayCallbacks.find(id);
            if (item != m_GatewayCallbacks.end())
            {
                const size_t size = m_GatewayCallbacks.size();
                m_GatewayCallbacks.erase(item);

                return (size - m_GatewayCallbacks.size() > 0);
            }

            return false;
        }

        size_t Lan4Gate::gatewayCallbacksCount() const
        {
            return m_GatewayCallbacks.size();
        }

        size_t Lan4Gate::addInteractionCallback(Callback::IInteractionCallback &callback)
        {
            size_t id = generateID();
            while (m_InteractionCallbacks.find(id) != m_InteractionCallbacks.end())
            {
                id = generateID();
            }

            m_InteractionCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeInteractionCallback(const size_t& id)
        {
            auto item = m_InteractionCallbacks.find(id);
            if(item != m_InteractionCallbacks.end())
            {
                const size_t size = m_InteractionCallbacks.size();
                m_InteractionCallbacks.erase(item);

                return (size - m_InteractionCallbacks.size() > 0);
            }

            return false;
        }

        size_t Lan4Gate::interactionCallbacksCount() const
        {
            return m_InteractionCallbacks.size();
        }

        size_t Lan4Gate::addReceiptCallback(Callback::IReceiptCallback& callback)
        {
            size_t id = generateID();
            while (m_ReceiptCallbacks.find(id) != m_ReceiptCallbacks.end())
            {
                id = generateID();
            }

            m_ReceiptCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeReceiptCallback(const size_t& id)
        {
            auto item = m_ReceiptCallbacks.find(id);
            if (item != m_ReceiptCallbacks.end())
            {
                const size_t size = m_ReceiptCallbacks.size();
                m_ReceiptCallbacks.erase(item);

                return (size - m_ReceiptCallbacks.size() > 0);
            }

            return false;
        }

        size_t Lan4Gate::receiptCallbacksCount() const
        {
            return m_ReceiptCallbacks.size();
        }

        size_t Lan4Gate::addConnectionCallback(Callback::IConnectionCallback &callback)
        {
            size_t id = generateID();
            while (m_ConnectionCallbacks.find(id) != m_ConnectionCallbacks.end())
            {
                id = generateID();
            }

            m_ConnectionCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeConnectionCallback(size_t id)
        {
            bool result = false;

            auto item = m_ConnectionCallbacks.find(id);
            if(item != m_ConnectionCallbacks.end())
            {
                size_t size = m_ConnectionCallbacks.size();

                m_ConnectionCallbacks.erase(item);

                result = size - m_ConnectionCallbacks.size() > 0;
            }

            return result;
        }

        size_t Lan4Gate::connectionCallbacksCount() const
        {
            return m_ConnectionCallbacks.size();
        }

        std::shared_ptr<Message::Request::IRequestData> Lan4Gate::getPreparedRequest(Message::OperationCode operationCode)
        {
            return Message::Request::RequestDataFactory::getRequestData(operationCode, (int16_t)m_EcrNumber);
        }

        std::shared_ptr<Message::Response::IResponseData> Lan4Gate::getPreparedResponse(Message::OperationCode operationCode)
        {
            return Message::Response::ResponseDataFactory::getResponseData(operationCode, (int16_t)m_EcrNumber);
        }

        std::shared_ptr<Message::Notification::INotificationData> Lan4Gate::getPreparedNotification(Message::Notification::NotificationCode notificationCode)
        {
            return Message::Notification::NotificationDataFactory::getNotificationData(notificationCode);
        }

        std::shared_ptr<Message::Interface::IInterfaceData> Lan4Gate::getPreparedInterface(Message::Interface::InterfaceType uiType)
        {
            return Message::Interface::InterfaceDataFactory::getInterfaceData(uiType);
        }

        std::shared_ptr<Message::Gateway::IGatewayData> Lan4Gate::getPreparedGateway(Message::Gateway::GatewayCode gatewayCode)
        {
            return Message::Gateway::GatewayDataFactory::getGatewayData(gatewayCode);
        }

        std::shared_ptr<Message::Interaction::IInteractionData> Lan4Gate::getPreparedInteraction(Message::Interaction::InteractionCode interactionCode)
        {
            return Message::Interaction::InteractionDataFactory::getInteractionData(interactionCode);
        }

        std::shared_ptr<Message::Receipt::IReceiptData> Lan4Gate::getPreparedReceipt(Message::Receipt::ReceiptCode receiptCode)
        {
            return Message::Receipt::ReceiptDataFactory::getReceiptData(receiptCode);
        }

        //TODO оптимизировать блокировки очереди
        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Request::IRequestData> request)
        {
            try
            {
                if(m_MessageBuilder != nullptr)
                {
                    std::vector<uint8_t> message;

                    if (m_MessageBuilder->createMessage(request, message))
                    {
                        return pushToQueue(message);
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
            return false;
        }

        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Response::IResponseData> response)
        {
            try
            {
                if(m_MessageBuilder != nullptr)
                {
                    std::vector<uint8_t> message;

                    if (m_MessageBuilder->createMessage(response, message))
                    {
                        return pushToQueue(message);
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
            return false;
        }

        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Notification::INotificationData> notification)
        {
            try
            {
                if(m_MessageBuilder != nullptr)
                {
                    std::vector<uint8_t> message;

                    if (m_MessageBuilder->createMessage(notification, message))
                    {
                        return pushToQueue(message);
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
            return false;
        }

        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Interface::IInterfaceData> ui)
        {
            try
            {
                if (m_MessageBuilder != nullptr)
                {
                    std::vector<uint8_t> message;

                    if (m_MessageBuilder->createMessage(ui, message))
                    {
                        return pushToQueue(message);
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
            return false;
        }

        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Gateway::IGatewayData> gateway)
        {
            try
            {
                if (m_MessageBuilder != nullptr)
                {
                    std::vector<uint8_t> message;

                    if (m_MessageBuilder->createMessage(gateway, message))
                    {
                        return pushToQueue(message);
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
            return false;
        }

        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Interaction::IInteractionData> interaction)
        {
            try
            {
                if(m_MessageBuilder != nullptr)
                {
                    std::vector<uint8_t> message;

                    if (m_MessageBuilder->createMessage(interaction, message))
                    {
                        return pushToQueue(message);
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
            return false;
        }

        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Receipt::IReceiptData> receipt)
        {
            try
            {
                if (m_MessageBuilder != nullptr)
                {
                    std::vector<uint8_t> message;

                    if (m_MessageBuilder->createMessage(receipt, message))
                    {
                        return pushToQueue(message);
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
            return false;
        }

        bool Lan4Gate::pushToQueue(const std::vector<uint8_t> &data)
        {
            try
            {
                std::lock_guard<std::mutex> lock(m_QueueMutex);

                const auto size = m_MessageQueue.size();
                m_MessageQueue.push(data);
                //Для определения, что сообщение добавлено в очередь
                return m_MessageQueue.size() - size;
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        void Lan4Gate::popFromQueue(std::vector<uint8_t> &data)
        {
            try
            {
                std::lock_guard<std::mutex> lock(m_QueueMutex);

                if(!m_MessageQueue.empty())
                {
                    data = std::move(m_MessageQueue.front());
                    m_MessageQueue.pop();
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        bool Lan4Gate::createParser()
        {
            if (m_MessageParser == nullptr)
            {
                m_MessageParser = MessageProcessor::Parser::MessageParserFactory::getMessageParser();
            }
            return m_MessageParser != nullptr;
        }

        bool Lan4Gate::createBuilder()
        {
            if(m_MessageBuilder == nullptr)
            {
                m_MessageBuilder = MessageProcessor::Builder::MessageBuilderFactory::getMessageBuilder();
            }
            return m_MessageBuilder != nullptr;
        }

        size_t Lan4Gate::generateID()
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<size_t> distrib((size_t)1, (size_t)SIZE_MAX);

            return distrib(gen);
        }

        bool Lan4Gate::openConnection()
        {
            bool result = m_Communication->isOpen();

            if (!result)
            {
                result = m_Communication->open();
            }

            return result;
        }

        bool Lan4Gate::deleteParser()
        {
            m_MessageParser.reset();
            return m_MessageParser == nullptr;
        }

        bool Lan4Gate::deleteBuilder()
        {
            m_MessageBuilder.reset();
            return m_MessageBuilder == nullptr;
        }

        bool Lan4Gate::closeConnection()
        {
            bool result = true;
            if(m_Communication != nullptr && m_Communication->isOpen())
            {
                result = m_Communication->close();
            }
            return result;
        }

        void Lan4Gate::sendData()
        {
            std::vector<uint8_t> data;
            popFromQueue(data);

            if(!data.empty())
            {
                m_Communication->send(data);
            }
        }

        //TODO исправить логику. Возможны проблемы с приемом кусков данных
        void Lan4Gate::receiveData()
        {
            std::vector<uint8_t> data;

            try
            {
                m_Communication->receive(data);

                if (!data.empty())
                {
                    m_MessageParser->parseMessage(data);
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        void Lan4Gate::notify()
        {
            try
            {
                auto notificationLambda = [&]()
                {
                    this->notifyRequest();
                    this->notifyResponse();
                    this->notifyNotification();
                    this->notifyInterface();
                    this->notifyGateway();
                    this->notifyInteraction();
                    this->notifyReceipt();
                };

                if(m_CallbackNotificationType == CallbackNotificationType::Async)
                {
                    if (!m_CallbacksFuture.valid() || m_CallbacksFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
                    {
                        m_CallbacksFuture = std::async(std::launch::async, notificationLambda);
                    }
                }
                else
                {
                    notificationLambda();
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        void Lan4Gate::notifyRequest()
        {
            try
            {
                if(m_MessageParser->requestCount() > 0)
                {
                    auto request = m_MessageParser->nextRequestData();

                    if (request)
                    {
                        for (const auto &callback: m_RequestCallbacks)
                        {
                            callback.second.newData(request);
                        }
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        void Lan4Gate::notifyResponse()
        {
            try
            {
                if(m_MessageParser->responseCount() > 0)
                {
                    auto response = m_MessageParser->nextResponseData();
                    if (response)
                    {
                        for (const auto &callback: m_ResponseCallbacks)
                        {
                            callback.second.newData(response);
                        }
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        void Lan4Gate::notifyNotification()
        {
            try
            {
                if(m_MessageParser->notificationCount() > 0)
                {
                    auto notification = m_MessageParser->nextNotificationData();
                    if (notification)
                    {
                        for (const auto &callback: m_NotificationCallbacks)
                        {
                            callback.second.newData(notification);
                        }
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        void Lan4Gate::notifyInterface()
        {
            try
            {
                if (m_MessageParser->interfaceCount() > 0)
                {
                    auto interface = m_MessageParser->nextInterfaceData();
                    if (interface)
                    {
                        for (const auto& callback : m_InterfaceCallbacks)
                        {
                            const std::string result = callback.second.newData(interface);
                            try
                            {
                                auto response = Message::Interface::InterfaceDataFactory::getInterfaceData(interface->getType());
                                if (m_MessageBuilder != nullptr && response != nullptr)
                                {
                                    response->setResult(result);

                                    std::vector<uint8_t> message;
                                    if (m_MessageBuilder->createMessage(response, message))
                                    {
                                        pushToQueue(message);
                                    }
                                }
                            }
                            catch (const std::exception&)
                            {
                                throw;
                            }
                        }
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        void Lan4Gate::notifyGateway()
        {
            try
            {
                if (m_MessageParser->gatewayCount() > 0)
                {
                    auto gateway = m_MessageParser->nextGatewayData();
                    if (gateway)
                    {
                        for (const auto& callback : m_GatewayCallbacks)
                        {
                            const int status = callback.second.newData(gateway);
                            try
                            {
                                Message::Gateway::GatewayCode code = gateway->getCode();
                                auto response = Message::Gateway::GatewayDataFactory::getGatewayData(code);
                                // отсылаем только по 1(open) и по 2(close)
                                const bool isConnectOrDisconnet = code == Message::Gateway::GatewayCode::Connect || code == Message::Gateway::GatewayCode::Disconnect;
                                if (m_MessageBuilder != nullptr && response != nullptr && isConnectOrDisconnet)
                                {
                                    response->setStatus(status);
                                    response->setLink(gateway->getLink());

                                    std::vector<uint8_t> message;
                                    if (m_MessageBuilder->createMessage(response, message))
                                    {
                                        pushToQueue(message);
                                    }
                                }
                            }
                            catch (const std::exception&)
                            {
                                throw;
                            }
                        }
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        void Lan4Gate::notifyInteraction()
        {
            try
            {
                if(m_MessageParser->interactionCount() > 0)
                {
                    auto interaction = m_MessageParser->nextInteractionData();
                    if (interaction)
                    {
                        for (const auto &callback: m_InteractionCallbacks)
                        {
                            callback.second.newData(interaction);
                        }
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        void Lan4Gate::notifyReceipt()
        {
            try
            {
                if (m_MessageParser->receiptCount() > 0)
                {
                    auto receipt = m_MessageParser->nextReceiptData();
                    if (receipt)
                    {
                        for (const auto& callback : m_ReceiptCallbacks)
                        {
                            callback.second.newData(receipt);
                        }
                    }
                }
            }
            catch (const std::exception&)
            {
                throw;
            }
        }

        void Lan4Gate::notifyConnectionStatus(bool status)
        {
            for(const auto & callback : m_ConnectionCallbacks)
            {
                callback.second.newState(status);
            }
        }

        bool Lan4Gate::waitFuture()
        {
            bool result = true;
            if(m_CallbacksFuture.valid())
            {
                result = m_CallbacksFuture.wait_for(std::chrono::milliseconds(50)) == std::future_status::ready;
            }
            return result;
        }

        bool Lan4Gate::setCallbackNotificationType(ILan4Gate::CallbackNotificationType type)
        {
            if(!m_IsStarted)
            {
                m_CallbackNotificationType = type;
            }
            return m_CallbackNotificationType == type;
        }

        void Lan4Gate::connect()
        {
            if(m_Communication != nullptr)
            {
                m_Communication->connect();
            }
        }

        bool Lan4Gate::isConnected()
        {
            bool result = false;
            if(m_Communication != nullptr)
            {
                result = m_Communication->isConnected();
                if (result != m_PreviousConnectionStatus)
                {
                    m_PreviousConnectionStatus = result;
                    notifyConnectionStatus(result);
                }
            }
            return result;
        }

        void Lan4Gate::doCommunication()
        {
            if(m_Communication != nullptr)
            {
                m_Communication->doCommunication();
            }
        }
    }
}