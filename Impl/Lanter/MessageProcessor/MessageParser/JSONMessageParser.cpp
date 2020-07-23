//
// Created by Владимир Лысенков on 12.07.2020.
//

#include "JSONMessageParser.h"

#include "JSONRootFieldsChecker.h"
#include "JSONMessageTypeChecker.h"

#include "Lanter/Utils/StringConverter.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "JSONRequestParser.h"
#include "JSONResponseParser.h"
#include "JSONNotificationParser.h"

namespace Lanter {
    namespace MessageProcessor {

        MessageType JSONMessageParser::parseMessage(const std::vector<unsigned char> &data) {
            MessageType result = MessageType::Error;
            std::string message;

            if(Utils::StringConverter::convertToString(data, message)) {
                Json::Value root;
                if(readMessage(message, root) && JSONRootFieldsChecker::checkFields(root)) {
                    result = parseObject(root);
                }
            }
            return result;
        }

        std::shared_ptr<IRequestData> JSONMessageParser::getNextRequestData() {
            std::shared_ptr<IRequestData> result = nullptr;
            if(!m_Requests.empty()) {
                result = m_Requests.front();
                m_Requests.pop();
            }
            return result;
        }

        size_t JSONMessageParser::requestCount() const {
            return m_Requests.size();
        }

        std::shared_ptr<IResponseData> JSONMessageParser::getNextResponseData() {
            std::shared_ptr<IResponseData> result = nullptr;
            if(!m_Responses.empty()) {
                result = m_Responses.front();
                m_Responses.pop();
            }
            return result;
        }


        size_t JSONMessageParser::responseCount() const {
            return m_Responses.size();
        }

        std::shared_ptr<INotificationData> JSONMessageParser::getNextNotificationData() {
            std::shared_ptr<INotificationData> result = nullptr;
            if(!m_Notifications.empty()) {
                result = m_Notifications.front();
                m_Notifications.pop();
            }
            return result;
        }

        size_t JSONMessageParser::notificationCount() const {
            return m_Notifications.size();
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

            const Json::Value & object = root[JSONRootFields::getObjectField()];
            switch (result) {
                case MessageType::Error:
                    break;
                case MessageType::Request:
                    if(!createRequest(object)) {
                        result = MessageType::Error;
                    }
                    break;
                case MessageType::Response:
                    if(!createResponse(object)) {
                        result = MessageType::Error;
                    }
                    break;
                case MessageType::Notification:
                    if(!createNotification(object)) {
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
            if(result) {
                m_Requests.push(request);
            }
            return result;
        }

        bool JSONMessageParser::createResponse(const Json::Value &object) {
            JSONResponseParser parser;

            auto request = parser.parseData(object);
            bool result = request != nullptr;
            if(result) {
                m_Responses.push(request);
            }
            return result;
        }

        bool JSONMessageParser::createNotification(const Json::Value &object) {
            JSONNotificationParser parser;

            auto notification = parser.parseData(object);
            bool result = notification != nullptr;
            if(result) {
                m_Notifications.push(notification);
            }
            return result;
        }


    }
}