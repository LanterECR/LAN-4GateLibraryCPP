//
// Created by Владимир Лысенков on 12.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_JSONMESSAGEPARSER_H
#define LAN_4GATELIBRARYCPP_JSONMESSAGEPARSER_H

#include <queue>

#include "json/json.h"

#include "Lanter/MessageProcessor/MessageParser/IMessageParser.h"

namespace Lanter {
    namespace MessageProcessor {
        class JSONMessageParser : public IMessageParser {
        public:
            MessageType parseMessage(const std::vector<unsigned char> &data) override;

            std::shared_ptr<IRequestData> getNextRequestData() override;

            size_t requestCount() const override;


            std::shared_ptr<IResponseData> getNextResponseData() override;

            size_t responseCount() const override;

            std::shared_ptr<INotificationData> getNextNotificationData() override;

            size_t notificationCount() const override;

            MessageType parseObject(const Json::Value & root);
            static bool readMessage(const std::string & message, Json::Value & root);
        private:
            bool createRequest(const Json::Value & object);
            bool createNotification(const Json::Value & object);
            std::queue<std::shared_ptr<IRequestData> > m_Requests;
            std::queue<std::shared_ptr<IResponseData> > m_Responses;
            std::queue<std::shared_ptr<INotificationData> > m_Notifications;
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONMESSAGEPARSER_H
