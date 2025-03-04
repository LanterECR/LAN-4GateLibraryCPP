#include "JSONMessageParser.h"
#include "JSONRootFieldsChecker.h"
#include "JSONMessageTypeChecker.h"
#include "JSONRequestParser.h"
#include "JSONResponseParser.h"
#include "JSONNotificationParser.h"
#include "JSONInterfaceParser.h"
#include "JSONGatewayParser.h"
#include "JSONInteractionParser.h"
#include "JSONReceiptParser.h"
#include "Lanter/Utils/StringConverter.h"
#include "Lanter/MessageProcessor/JSONFields/JSONRootFields.h"

#include <sstream>

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            MessageType JSONMessageParser::parseMessage(const std::vector<uint8_t> &data)
            {
                MessageType result = MessageType::Error;
                std::string message;

                try
                {
                    if (Utils::StringConverter::convertToString(data, message))
                    {
                        Json::Value root;
                        if (readMessage(message, root) && JSONRootFieldsChecker::checkFields(root))
                        {
                            result = parseObject(root);
                        }
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }

                return result;
            }

            std::shared_ptr<IRequestData> JSONMessageParser::nextRequestData()
            {
                std::shared_ptr<IRequestData> result = nullptr;
                if (!m_Requests.empty())
                {
                    result = m_Requests.front();
                    m_Requests.pop();
                }

                return result;
            }

            size_t JSONMessageParser::requestCount() const
            {
                return m_Requests.size();
            }

            std::shared_ptr<IResponseData> JSONMessageParser::nextResponseData()
            {
                std::shared_ptr<IResponseData> result = nullptr;
                if (!m_Responses.empty())
                {
                    result = m_Responses.front();
                    m_Responses.pop();
                }

                return result;
            }


            size_t JSONMessageParser::responseCount() const
            {
                return m_Responses.size();
            }

            std::shared_ptr<INotificationData> JSONMessageParser::nextNotificationData()
            {
                std::shared_ptr<INotificationData> result = nullptr;
                if (!m_Notifications.empty())
                {
                    result = m_Notifications.front();
                    m_Notifications.pop();
                }

                return result;
            }

            size_t JSONMessageParser::notificationCount() const
            {
                return m_Notifications.size();
            }

            std::shared_ptr<IInterfaceData> JSONMessageParser::nextInterfaceData()
            {
                std::shared_ptr<IInterfaceData> result = nullptr;
                if (!m_Interfaces.empty())
                {
                    result = m_Interfaces.front();
                    m_Interfaces.pop();
                }

                return result;
            }

            size_t JSONMessageParser::interfaceCount() const
            {
                return m_Interfaces.size();
            }

            std::shared_ptr<IGatewayData> JSONMessageParser::nextGatewayData()
            {
                std::shared_ptr<IGatewayData> result = nullptr;
                if (!m_Gateways.empty())
                {
                    result = m_Gateways.front();
                    m_Gateways.pop();
                }

                return result;
            }

            size_t JSONMessageParser::gatewayCount() const
            {
                return m_Gateways.size();
            }

            std::shared_ptr<Message::Interaction::IInteractionData> JSONMessageParser::nextInteractionData()
            {
                std::shared_ptr<IInteractionData> result = nullptr;
                if (!m_Interactions.empty())
                {
                    result = m_Interactions.front();
                    m_Interactions.pop();
                }

                return result;
            }

            size_t JSONMessageParser::interactionCount() const
            {
                return m_Interactions.size();
            }

            std::shared_ptr<Message::Receipt::IReceiptData> JSONMessageParser::nextReceiptData()
            {
                std::shared_ptr<IReceiptData> result = nullptr;
                if (!m_Receipt.empty())
                {
                    result = m_Receipt.front();
                    m_Receipt.pop();
                }

                return result;
            }

            size_t JSONMessageParser::receiptCount() const
            {
                return m_Receipt.size();
            }

            bool JSONMessageParser::readMessage(const std::string &message, Json::Value &root)
            {
                bool result = false;
                try
                {
                    std::stringstream ss(message);
                    ss >> root;
                    result = !root.empty();
                }
                catch (const std::exception &)
                {
                    throw;
                    ///result = false;
                }
                return result;
            }

            MessageType JSONMessageParser::parseObject(const Json::Value &root)
            {
                try
                {
                    MessageType result = JSONMessageTypeChecker::checkType(root);

                    const Json::Value& object = root[JSONRootFields::getObjectField()];
                    switch (result)
                    {
                        case MessageType::Error:
                            break;

                        case MessageType::Request:
                            if (!createRequest(object))
                            {
                                result = MessageType::Error;
                            }
                            break;

                        case MessageType::Response:
                            if (!createResponse(object))
                            {
                                result = MessageType::Error;
                            }
                            break;

                        case MessageType::Notification:
                            if (!createNotification(object))
                            {
                                result = MessageType::Error;
                            }
                            break;

                        case MessageType::Interface:
                            if (!createInterface(object))
                            {
                                result = MessageType::Error;
                            }
                            break;

                        case MessageType::Gateway:
                            if (!createGateway(object))
                            {
                                result = MessageType::Error;
                            }
                            break;

                        case MessageType::Interaction:
                            if(!createInteraction(object))
                            {
                                result = MessageType::Error;
                            }
                            break;

                        case MessageType::Receipt:
                            if (!createReceipt(object))
                            {
                                result = MessageType::Error;
                            }
                            break;

                        default:
                            result = MessageType::Unknown;
                            break;
                    }

                    return result;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONMessageParser::createRequest(const Json::Value &object)
            {
                JSONRequestParser parser;

                try
                {
                    auto request = parser.parseData(object);
                    bool result = request != nullptr;
                    if (result)
                    {
                        m_Requests.push(request);
                    }

                    return result;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONMessageParser::createResponse(const Json::Value &object)
            {
                JSONResponseParser parser;

                try
                {
                    auto request = parser.parseData(object);
                    bool result = request != nullptr;
                    if (result)
                    {
                        m_Responses.push(request);
                    }

                    return result;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONMessageParser::createNotification(const Json::Value &object)
            {
                JSONNotificationParser parser;

                try
                {
                    auto notification = parser.parseData(object);
                    bool result = notification != nullptr;
                    if (result)
                    {
                        m_Notifications.push(notification);
                    }

                    return result;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONMessageParser::createInterface(const Json::Value& object)
            {
                JSONInterfaceParser parser;

                try
                {
                    auto interface = parser.parseData(object);
                    bool result = interface != nullptr;
                    if (result)
                    {
                        m_Interfaces.push(interface);
                    }

                    return result;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONMessageParser::createGateway(const Json::Value& object)
            {
                JSONGatewayParser parser;

                try
                {
                    auto gateway = parser.parseData(object);
                    bool result = gateway != nullptr;
                    if (result)
                    {
                        m_Gateways.push(gateway);
                    }

                    return result;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONMessageParser::createInteraction(const Json::Value &object)
            {
                JSONInteractionParser parser;

                try
                {
                    auto interaction = parser.parseData(object);
                    bool result = interaction != nullptr;
                    if (result)
                    {
                        m_Interactions.push(interaction);
                    }

                    return result;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONMessageParser::createReceipt(const Json::Value& object)
            {
                JSONReceiptParser parser;

                try
                {
                    auto receipt = parser.parseData(object);
                    if (receipt != nullptr)
                    {
                        m_Receipt.push(receipt);
                        return true;
                    }

                    return false;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }
        }
    }
}