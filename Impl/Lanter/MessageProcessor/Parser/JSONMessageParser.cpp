#include "JSONMessageParser.h"

#include <sstream>

#include "JSONRootFieldsChecker.h"
#include "JSONMessageTypeChecker.h"

#include "Lanter/Utils/StringConverter.h"

#include "Lanter/MessageProcessor/JSONFields/JSONRootFields.h"

#include "JSONRequestParser.h"
#include "JSONResponseParser.h"
#include "JSONNotificationParser.h"
#include "JSONInteractionParser.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            MessageType JSONMessageParser::parseMessage(const std::vector<uint8_t> &data) {
                MessageType result = MessageType::Error;
                std::string message;

                if (Utils::StringConverter::convertToString(data, message)) {
                    Json::Value root;
                    if (readMessage(message, root) && JSONRootFieldsChecker::checkFields(root)) {
                        result = parseObject(root);
                    }
                }
                return result;
            }

            std::shared_ptr<IRequestData> JSONMessageParser::nextRequestData() {
                std::shared_ptr<IRequestData> result = nullptr;
                if (!m_Requests.empty()) {
                    result = m_Requests.front();
                    m_Requests.pop();
                }
                return result;
            }

            size_t JSONMessageParser::requestCount() const {
                return m_Requests.size();
            }

            std::shared_ptr<IResponseData> JSONMessageParser::nextResponseData() {
                std::shared_ptr<IResponseData> result = nullptr;
                if (!m_Responses.empty()) {
                    result = m_Responses.front();
                    m_Responses.pop();
                }
                return result;
            }


            size_t JSONMessageParser::responseCount() const {
                return m_Responses.size();
            }

            std::shared_ptr<INotificationData> JSONMessageParser::nextNotificationData() {
                std::shared_ptr<INotificationData> result = nullptr;
                if (!m_Notifications.empty()) {
                    result = m_Notifications.front();
                    m_Notifications.pop();
                }
                return result;
            }

            size_t JSONMessageParser::notificationCount() const {
                return m_Notifications.size();
            }

            std::shared_ptr<Message::Interaction::IInteractionData> JSONMessageParser::nextInteractionData() {
                std::shared_ptr<IInteractionData> result = nullptr;
                if (!m_Interactions.empty()) {
                    result = m_Interactions.front();
                    m_Interactions.pop();
                }
                return result;
            }

            size_t JSONMessageParser::interactionCount() const {
                return m_Interactions.size();
            }

            bool JSONMessageParser::readMessage(const std::string &message, Json::Value &root) {
                bool result = false;
                try {
                    std::stringstream ss(message);
                    ss >> root;
                    result = !root.empty();
                } catch (std::exception &) {
                    result = false;
                }
                return result;
            }

            MessageType JSONMessageParser::parseObject(const Json::Value &root) {
                MessageType result = JSONMessageTypeChecker::checkType(root);

                const Json::Value &object = root[JSONRootFields::getObjectField()];
                switch (result) {
                    case MessageType::Error:
                        break;
                    case MessageType::Request:
                        if (!createRequest(object)) {
                            result = MessageType::Error;
                        }
                        break;
                    case MessageType::Response:
                        if (!createResponse(object)) {
                            result = MessageType::Error;
                        }
                        break;
                    case MessageType::Notification:
                        if (!createNotification(object)) {
                            result = MessageType::Error;
                        }
                        break;
                    case MessageType::Interaction:
                        if(!createInteraction(object)) {
                            result = MessageType::Error;
                        }
                        break;
                    case MessageType::Communication:
                    default:
                        result = MessageType::Unknown;
                        break;
                }
                return result;
            }

            bool JSONMessageParser::createRequest(const Json::Value &object) {
                JSONRequestParser parser;

                auto request = parser.parseData(object);
                bool result = request != nullptr;
                if (result) {
                    m_Requests.push(request);
                }
                return result;
            }

            bool JSONMessageParser::createResponse(const Json::Value &object) {
                JSONResponseParser parser;

                auto request = parser.parseData(object);
                bool result = request != nullptr;
                if (result) {
                    m_Responses.push(request);
                }
                return result;
            }

            bool JSONMessageParser::createNotification(const Json::Value &object) {
                JSONNotificationParser parser;

                auto notification = parser.parseData(object);
                bool result = notification != nullptr;
                if (result) {
                    m_Notifications.push(notification);
                }
                return result;
            }

            bool JSONMessageParser::createInteraction(const Json::Value &object) {
                JSONInteractionParser parser;

                auto interaction = parser.parseData(object);
                bool result = interaction != nullptr;
                if (result) {
                    m_Interactions.push(interaction);
                }
                return result;
            }

        }
    }
}