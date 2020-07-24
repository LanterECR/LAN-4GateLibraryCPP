#ifndef LAN_4GATELIBRARYCPP_IMESSAGEPARSER_H
#define LAN_4GATELIBRARYCPP_IMESSAGEPARSER_H

#include <vector>
#include <memory>

#include "MessageType.h"

#include "Lanter/Message/Request/IRequestData.h"
#include "Lanter/Message/Response/IResponseData.h"
#include "Lanter/Message/Notification/INotificationData.h"
#include "Lanter/Utils/VisibilityMacroses.h"

using namespace Lanter::Message;
using namespace Lanter::Message::Request;
using namespace Lanter::Message::Response;
using namespace Lanter::Message::Notification;

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            /// \brief Парсер сообщений.
            /// \details Если сообщение корректно, парсер помещает его в одну из внутренних очередей, а метод parseMessage
            /// возвращает тип полученного сообщения. Для получения сообщения необходимо вызвать
            class LANTER_VISIBILITY IMessageParser {
            public:
                /// \brief Разбирает полученное сообщение и возвращает тип
                /// \param data Сообщение для разбора
                /// \return Тип сообщения из MessageType
                /// \sa MessageType
                virtual MessageType parseMessage(const std::vector<unsigned char> &data) = 0;

                /// \brief Возвращает IRequestData экземпляр, хранящийся в очереди
                /// \return nullptr, если очередь пуста
                virtual std::shared_ptr<IRequestData> nextRequestData() = 0;

                /// Сообщает о количестве запросов в очереди
                /// \return 0, если очередь пуста
                virtual size_t requestCount() const = 0;

                /// \brief Возвращает IResponseData экземпляр, хранящийся в очереди
                /// \return nullptr, если очередь пуста
                virtual std::shared_ptr<IResponseData> nextResponseData() = 0;

                /// Сообщает о количестве запросов в очереди
                /// \return 0, если очередь пуста
                virtual size_t responseCount() const = 0;

                /// \brief Возвращает INotificationData экземпляр, хранящийся в очереди
                /// \return nullptr, если очередь пуста
                virtual std::shared_ptr<INotificationData> nextNotificationData() = 0;

                /// Сообщает о количестве запросов в очереди
                /// \return 0, если очередь пуста
                virtual size_t notificationCount() const = 0;
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_IMESSAGEPARSER_H
