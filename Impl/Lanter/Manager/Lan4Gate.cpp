#include "Lan4Gate.h"

#include <random>
#include <chrono>

#include "Lanter/Utils/FieldRangeChecker.h"

#include "Lanter/Message/Request/RequestDataFactory.h"
#include "Lanter/Message/Response/ResponseDataFactory.h"
#include "Lanter/Message/Notification/NotificationDataFactory.h"
#include "Lanter/Message/Interaction/InteractionDataFactory.h"

#include "Lanter/MessageProcessor/Parser/MessageParserFactory.h"
#include "Lanter/MessageProcessor/Builder/MessageBuilderFactory.h"

namespace Lanter {
    namespace Manager {
        Lan4Gate::Lan4Gate() : m_IsStarted(false) {}

        Lan4Gate::~Lan4Gate() {
            Lan4Gate::stop();
        }

        bool Lan4Gate::setEcrNumber(int16_t ecrNumber) {
            bool result = false;

            if(!m_IsStarted) {
                result = Utils::checkEcrNumberRange(ecrNumber);

                if(result) {
                    m_EcrNumber = ecrNumber;
                }
            }

            return result;
        }

        int16_t Lan4Gate::getEcrNumber() const {
            return m_EcrNumber;
        }

        ILan4Gate::Status Lan4Gate::start() {
            if(!m_IsStarted) {
                m_IsStarted = m_Communication != nullptr;
                m_IsStarted = m_IsStarted && createParser();
                m_IsStarted = m_IsStarted && createBuilder();
                m_IsStarted = m_IsStarted && openConnection();
            }
            return m_IsStarted ? ILan4Gate::Status::Success : ILan4Gate::Status::Error;
        }

        ILan4Gate::Status Lan4Gate::stop() {
            m_IsStarted = false;

            if(m_MainThread != nullptr) {
                m_MainThread->join();
            }

            closeConnection();
            waitFuture();
            return m_IsStarted ? ILan4Gate::Status::Error : ILan4Gate::Status::Success;
        }

        bool Lan4Gate::isStarted() const {
            return m_IsStarted;
        }


        void Lan4Gate::doLan4Gate() {
            if(m_IsStarted) {
                doCommunication();
                if(isConnected()) {
                    sendData();
                    receiveData();
                    notify();
                } else {
                    connect();
                }
            } else {
                closeConnection();
            }
        }

        ILan4Gate::Status Lan4Gate::runOnThread() {
            Status result = ILan4Gate::Status::Error;

            if(m_MainThread == nullptr) {
                auto threadLoop = [this]() {
                    while(isStarted()) {
                        doLan4Gate();
                        int sleepTimeout = 1; //ms
                        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeout));
                    }
                };
                if(start() == ILan4Gate::Status::Success) {
                    m_MainThread = std::make_shared<std::thread>(threadLoop);
                }
            }

            if(m_MainThread != nullptr && m_MainThread->joinable() && isStarted()) {
                result = ILan4Gate::Status::Success;
            }


            return result;
        }

        bool Lan4Gate::setCommunication(std::shared_ptr<Communication::ICommunication> communication) {
            if(resetCommunication()) {
                m_Communication = communication;
            }
            return m_Communication == communication;
        }

        bool Lan4Gate::resetCommunication() {
            if(m_Communication) {
                if(closeConnection()) {
                    m_Communication.reset();
                }
            }
            return m_Communication == nullptr;
        }

        std::shared_ptr<Communication::ICommunication> Lan4Gate::getCommunication() const {
            return m_Communication;
        }

        size_t Lan4Gate::addRequestCallback(Callback::IRequestCallback &callback) {
            size_t id = generateID();
            while (m_RequestCallbacks.find(id) != m_RequestCallbacks.end()) {
                id = generateID();
            }

            m_RequestCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeRequestCallback(size_t id) {
            bool result = false;

            auto item = m_RequestCallbacks.find(id);
            if(item != m_RequestCallbacks.end()) {
                size_t size = m_RequestCallbacks.size();

                m_RequestCallbacks.erase(item);

                result = size - m_RequestCallbacks.size() > 0;
            }

            return result;
        }

        size_t Lan4Gate::requestCallbacksCount() const {
            return m_RequestCallbacks.size();
        }

        size_t Lan4Gate::addResponseCallback(Callback::IResponseCallback &callback) {
            size_t id = generateID();
            while (m_ResponseCallbacks.find(id) != m_ResponseCallbacks.end()) {
                id = generateID();
            }

            m_ResponseCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeResponseCallback(size_t id) {
            bool result = false;

            auto item = m_ResponseCallbacks.find(id);
            if(item != m_ResponseCallbacks.end()) {
                size_t size = m_ResponseCallbacks.size();

                m_ResponseCallbacks.erase(item);

                result = size - m_ResponseCallbacks.size() > 0;
            }

            return result;
        }

        size_t Lan4Gate::responseCallbacksCount() const {
            return m_ResponseCallbacks.size();
        }

        size_t Lan4Gate::addNotificationCallback(Callback::INotificationCallback &callback) {
            size_t id = generateID();
            while (m_NotificationCallbacks.find(id) != m_NotificationCallbacks.end()) {
                id = generateID();
            }

            m_NotificationCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeNotificationCallback(size_t id) {
            bool result = false;

            auto item = m_NotificationCallbacks.find(id);
            if(item != m_NotificationCallbacks.end()) {
                size_t size = m_NotificationCallbacks.size();

                m_NotificationCallbacks.erase(item);

                result = size - m_NotificationCallbacks.size() > 0;
            }

            return result;
        }

        size_t Lan4Gate::notificationCallbacksCount() const {
            return m_NotificationCallbacks.size();
        }

        size_t Lan4Gate::addInteractionCallback(Callback::IInteractionCallback &callback) {
            size_t id = generateID();
            while (m_InteractionCallbacks.find(id) != m_InteractionCallbacks.end()) {
                id = generateID();
            }

            m_InteractionCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeInteractionCallback(size_t id) {
            bool result = false;

            auto item = m_InteractionCallbacks.find(id);
            if(item != m_InteractionCallbacks.end()) {
                size_t size = m_InteractionCallbacks.size();

                m_InteractionCallbacks.erase(item);

                result = size - m_InteractionCallbacks.size() > 0;
            }

            return result;
        }

        size_t Lan4Gate::interactionCallbacksCount() const {
            return m_InteractionCallbacks.size();
        }

        size_t Lan4Gate::addConnectionCallback(Callback::IConnectionCallback &callback) {
            size_t id = generateID();
            while (m_ConnectionCallbacks.find(id) != m_ConnectionCallbacks.end()) {
                id = generateID();
            }

            m_ConnectionCallbacks.emplace(id, callback);

            return id;
        }

        bool Lan4Gate::removeConnectionCallback(size_t id) {
            bool result = false;

            auto item = m_ConnectionCallbacks.find(id);
            if(item != m_ConnectionCallbacks.end()) {
                size_t size = m_ConnectionCallbacks.size();

                m_ConnectionCallbacks.erase(item);

                result = size - m_ConnectionCallbacks.size() > 0;
            }

            return result;
        }

        size_t Lan4Gate::connectionCallbacksCount() const {
            return m_ConnectionCallbacks.size();
        }

        std::shared_ptr<Message::Request::IRequestData> Lan4Gate::getPreparedRequest(Message::OperationCode operationCode) {
            return Message::Request::RequestDataFactory::getRequestData(operationCode, m_EcrNumber);
        }

        std::shared_ptr<Message::Response::IResponseData> Lan4Gate::getPreparedResponse(Message::OperationCode operationCode) {
            return Message::Response::ResponseDataFactory::getResponseData(operationCode, m_EcrNumber);
        }

        std::shared_ptr<Message::Notification::INotificationData> Lan4Gate::getPreparedNotification(Message::Notification::NotificationCode notificationCode) {
            return Message::Notification::NotificationDataFactory::getNotificationData(notificationCode);
        }

        std::shared_ptr<Message::Interaction::IInteractionData>
        Lan4Gate::getPreparedInteraction(Message::Interaction::InteractionCode interactionCode) {
            return Message::Interaction::InteractionDataFactory::getInteractionData(interactionCode);
        }

        //TODO оптимизировать блокировки очереди
        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Request::IRequestData> request) {
            bool result = false;

            if(m_MessageBuilder != nullptr) {
                std::vector<uint8_t> message;

                if (m_MessageBuilder->createMessage(request, message)) {
                    result = pushToQueue(message);
                }
            }
            return result;
        }

        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Response::IResponseData> response) {
            bool result = false;

            if(m_MessageBuilder != nullptr) {
                std::vector<uint8_t> message;

                if (m_MessageBuilder->createMessage(response, message)) {
                    result = pushToQueue(message);
                }
            }
            return result;
        }

        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Notification::INotificationData> notification) {
            bool result = false;

            if(m_MessageBuilder != nullptr) {
                std::vector<uint8_t> message;

                if (m_MessageBuilder->createMessage(notification, message)) {
                    result = pushToQueue(message);
                }
            }

            return result;
        }

        bool Lan4Gate::sendMessage(std::shared_ptr<Message::Interaction::IInteractionData> interaction) {
            bool result = false;

            if(m_MessageBuilder != nullptr) {
                std::vector<uint8_t> message;

                if (m_MessageBuilder->createMessage(interaction, message)) {
                    result = pushToQueue(message);
                }
            }

            return result;
        }

        bool Lan4Gate::pushToQueue(const std::vector<uint8_t> &data) {
            std::lock_guard<std::mutex> lock(m_QueueMutex);

            auto size = m_MessageQueue.size();

            m_MessageQueue.push(data);

            //Для определения, что сообщение добавлено в очередь
            return m_MessageQueue.size() - size;
        }

        void Lan4Gate::popFromQueue(std::vector<uint8_t> &data) {
            std::lock_guard<std::mutex> lock(m_QueueMutex);

            if(!m_MessageQueue.empty()) {
                data = std::move(m_MessageQueue.front());
                m_MessageQueue.pop();
            }
        }

        bool Lan4Gate::createParser() {
            if(m_MessageParser == nullptr) {
                m_MessageParser = MessageProcessor::Parser::MessageParserFactory::getMessageParser();
            }
            return m_MessageParser != nullptr;
        }

        bool Lan4Gate::createBuilder() {
            if(m_MessageBuilder == nullptr) {
                m_MessageBuilder = MessageProcessor::Builder::MessageBuilderFactory::getMessageBuilder();
            }
            return m_MessageBuilder != nullptr;
        }

        size_t Lan4Gate::generateID() {
            size_t min = 1;
            size_t max = SIZE_MAX;

            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_int_distribution<size_t> distrib(min, max);

            return distrib(gen);
        }

        bool Lan4Gate::openConnection() {
            bool result = m_Communication->isOpen();

            if(!result){
                result = m_Communication->open();
            }

            return result;
        }

        bool Lan4Gate::deleteParser() {
            m_MessageParser.reset();
            return m_MessageParser == nullptr;
        }

        bool Lan4Gate::deleteBuilder() {
            m_MessageBuilder.reset();
            return m_MessageBuilder == nullptr;
        }

        bool Lan4Gate::closeConnection() {
            bool result = true;
            if(m_Communication != nullptr && m_Communication->isOpen()) {
                result = m_Communication->close();
            }
            return result;
        }

        void Lan4Gate::sendData() {
            std::vector<uint8_t> data;
            popFromQueue(data);

            if(!data.empty()) {
                m_Communication->send(data);
            }
        }

        //TODO исправить логику. Возможны проблемы с приемом кусков данных
        void Lan4Gate::receiveData() {
            std::vector<uint8_t> data;

            m_Communication->receive(data);

            if(!data.empty()) {
                m_MessageParser->parseMessage(data);
            }
        }

        void Lan4Gate::notify() {
            auto notificationLambda = [&]() {
                this->notifyRequest();
                this->notifyResponse();
                this->notifyNotification();
                this->notifyInteraction();
            };

            if(m_CallbackNotificationType == CallbackNotificationType::Async) {
                if (!m_CallbacksFuture.valid() || m_CallbacksFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
                    m_CallbacksFuture = std::async(std::launch::async, notificationLambda);
                }
            } else {
                notificationLambda();
            }
        }

        void Lan4Gate::notifyRequest() {
            if(m_MessageParser->requestCount() > 0) {

                auto request = m_MessageParser->nextRequestData();

                for(const auto& callback : m_RequestCallbacks) {
                    callback.second.newData(request);
                }
            }
        }

        void Lan4Gate::notifyResponse() {
            if(m_MessageParser->responseCount() > 0) {

                auto response = m_MessageParser->nextResponseData();

                for(const auto& callback : m_ResponseCallbacks) {
                    callback.second.newData(response);
                }
            }
        }

        void Lan4Gate::notifyNotification() {
            if(m_MessageParser->notificationCount() > 0) {

                auto notification = m_MessageParser->nextNotificationData();

                for(const auto& callback : m_NotificationCallbacks) {
                    callback.second.newData(notification);
                }
            }
        }

        void Lan4Gate::notifyInteraction() {
            if(m_MessageParser->interactionCount() > 0) {

                auto interaction = m_MessageParser->nextInteractionData();

                for(const auto& callback : m_InteractionCallbacks) {
                    callback.second.newData(interaction);
                }
            }
        }

        void Lan4Gate::notifyConnectionStatus(bool status) {
            for(const auto & callback : m_ConnectionCallbacks) {
                callback.second.newState(status);
            }
        }

        bool Lan4Gate::waitFuture() {
            bool result = true;
            if(m_CallbacksFuture.valid()) {
                result = m_CallbacksFuture.wait_for(std::chrono::milliseconds(50)) == std::future_status::ready;
            }
            return result;
        }

        bool Lan4Gate::setCallbackNotificationType(ILan4Gate::CallbackNotificationType type) {
            if(!m_IsStarted) {
                m_CallbackNotificationType = type;
            }
            return m_CallbackNotificationType == type;
        }

        void Lan4Gate::connect() {
            if(m_Communication != nullptr) {
                m_Communication->connect();
            }
        }

        bool Lan4Gate::isConnected() {
            bool result = false;
            if(m_Communication != nullptr) {
                result = m_Communication->isConnected();
                if (result != m_PreviousConnectionStatus) {
                    m_PreviousConnectionStatus = result;
                    notifyConnectionStatus(result);
                }
            }
            return result;
        }

        void Lan4Gate::doCommunication() {
            if(m_Communication != nullptr) {
                m_Communication->doCommunication();
            }

        }
    }
}