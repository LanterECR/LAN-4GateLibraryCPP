#ifndef LAN_4GATELIBRARYCPP_JSONMESSAGEBUILDER_H
#define LAN_4GATELIBRARYCPP_JSONMESSAGEBUILDER_H

#include <Lanter/MessageProcessor/Builder/IMessageBuilder.h>

namespace Lanter
{
    using namespace Message;
    using namespace Message::Request;
    using namespace Message::Response;
    using namespace Message::Notification;
    using namespace Message::Interaction;
    using namespace Message::Receipt;
    using namespace Message::Interface;
    using namespace Message::Gateway;

    namespace MessageProcessor
    {
        namespace Builder
        {
            /// \brief Интерфейс сборщика сообщений на основе заполненных контейнеров IMessageBuilder
            class JSONMessageBuilder : public IMessageBuilder
            {
            public:
                ~JSONMessageBuilder() override = default;

                bool createMessage(std::shared_ptr<IRequestData> data, std::vector<uint8_t> &resultData) override;
                bool createMessage(std::shared_ptr<IResponseData> data, std::vector<uint8_t> &resultData) override;
                bool createMessage(std::shared_ptr<INotificationData> data, std::vector<uint8_t> &resultData) override;
                bool createMessage(std::shared_ptr<IInterfaceData> data, std::vector<uint8_t>& resultData) override;
                bool createMessage(std::shared_ptr<IGatewayData> data, std::vector<uint8_t>& resultData) override;
                bool createMessage(std::shared_ptr<IInteractionData> data, std::vector<uint8_t> &resultData) override;
                bool createMessage(std::shared_ptr<IReceiptData> data, std::vector<uint8_t>& resultData) override;
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_JSONMESSAGEBUILDER_H