#ifndef LAN_4GATELIBRARYCPP_JSONMESSAGEPARSER_H
#define LAN_4GATELIBRARYCPP_JSONMESSAGEPARSER_H

#include <queue>
#include "json/json.h"
#include "Lanter/MessageProcessor/Parser/IMessageParser.h"

namespace Lanter
{
    using namespace Message;
    using namespace Message::Request;
    using namespace Message::Response;
    using namespace Message::Notification;
    using namespace Message::Interface;
    using namespace Message::Gateway;
    using namespace Message::Interaction;
    using namespace Message::Receipt;

    namespace MessageProcessor
    {
        namespace Parser
        {
            class JSONMessageParser : public IMessageParser
            {
            public:
                MessageType parseMessage(const std::vector<uint8_t> &data) override;

                std::shared_ptr<IRequestData> nextRequestData() override;
                size_t requestCount() const override;

                std::shared_ptr<IResponseData> nextResponseData() override;
                size_t responseCount() const override;

                std::shared_ptr<INotificationData> nextNotificationData() override;
                size_t notificationCount() const override;

                std::shared_ptr<IInterfaceData> nextInterfaceData() override;
                size_t interfaceCount() const override;

                std::shared_ptr<IGatewayData> nextGatewayData() override;
                size_t gatewayCount() const override;

                std::shared_ptr<Message::Interaction::IInteractionData> nextInteractionData() override;
                size_t interactionCount() const override;

                std::shared_ptr<Message::Receipt::IReceiptData> nextReceiptData() override;
                size_t receiptCount() const override;

                MessageType parseObject(const Json::Value &root);
                static bool readMessage(const std::string &message, Json::Value &root);

            private:
                bool createRequest(const Json::Value& object);
                bool createResponse(const Json::Value& object);
                bool createNotification(const Json::Value& object);
                bool createInterface(const Json::Value& object);
                bool createGateway(const Json::Value& object);
                bool createInteraction(const Json::Value& object);
                bool createReceipt(const Json::Value& object);

                std::queue<std::shared_ptr<IRequestData> > m_Requests;
                std::queue<std::shared_ptr<IResponseData> > m_Responses;
                std::queue<std::shared_ptr<INotificationData> > m_Notifications;
                std::queue<std::shared_ptr<IInterfaceData> > m_Interfaces;
                std::queue<std::shared_ptr<IGatewayData> > m_Gateways;
                std::queue<std::shared_ptr<IInteractionData> > m_Interactions;
                std::queue<std::shared_ptr<IReceiptData> > m_Receipt;
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_JSONMESSAGEPARSER_H