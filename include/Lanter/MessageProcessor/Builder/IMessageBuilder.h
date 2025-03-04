#ifndef LAN_4GATELIBRARYCPP_IMESSAGEBUILDER_H
#define LAN_4GATELIBRARYCPP_IMESSAGEBUILDER_H

#include <cstddef>
#include <vector>
#include <memory>

#include "Lanter/Utils/VisibilityMacroses.h"
#include "Lanter/Message/Request/IRequestData.h"
#include "Lanter/Message/Response/IResponseData.h"
#include "Lanter/Message/Notification/INotificationData.h"
#include "Lanter/Message/Interface/IInterfaceData.h"
#include "Lanter/Message/Gateway/IGatewayData.h"
#include "Lanter/Message/Interaction/IInteractionData.h"
#include "Lanter/Message/Receipt/IReceiptData.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Builder
        {
            /// \brief Интерфейс сборщика сообщений на основе заполненных контейнеров
            class LANTER_VISIBILITY IMessageBuilder
            {
            public:
                virtual ~IMessageBuilder() = default;

                /// \brief Создает сообщение на основе контейнера IRequestData
                /// \param[in] data Заполненный контейнер IRequestData
                /// \param[out] result vector из байтов, содержащий собранное сообщение
                /// \return true, если сборка сообщения прошла успешно.
                /// \sa Message::Request::IRequestData
                virtual bool createMessage(std::shared_ptr<Message::Request::IRequestData> data, std::vector<uint8_t> &result) = 0;

                /// \brief Создает сообщение на основе контейнера IResponseData
                /// \param[in] data Заполненный контейнер IResponseData
                /// \param[out] result vector из байтов, содержащий собранное сообщение
                /// \return true, если сборка сообщения прошла успешно.
                /// \sa Message::Response::IResponseData
                virtual bool createMessage(std::shared_ptr<Message::Response::IResponseData> data, std::vector<uint8_t> &result) = 0;

                /// \brief Создает сообщение на основе контейнера INotificationData
                /// \param[in] data Заполненный контейнер INotificationData
                /// \param[out] result vector из байтов, содержащий собранное сообщение
                /// \return true, если сборка сообщения прошла успешно.
                /// \sa Message::Notification::INotificationData
                virtual bool createMessage(std::shared_ptr<Message::Notification::INotificationData> data, std::vector<uint8_t> &result) = 0;

                /// \brief Создает сообщение на основе контейнера IInterfaceData
                /// \param[in] data Заполненный контейнер IInterfaceData
                /// \param[out] result vector из байтов, содержащий собранное сообщение
                /// \return true, если сборка сообщения прошла успешно.
                /// \sa Message::Interface::IInterfaceData
                virtual bool createMessage(std::shared_ptr<Message::Interface::IInterfaceData> data, std::vector<uint8_t>& result) = 0;

                /// \brief Создает сообщение на основе контейнера IGatewayData
                /// \param[in] data Заполненный контейнер IGatewayData
                /// \param[out] result vector из байтов, содержащий собранное сообщение
                /// \return true, если сборка сообщения прошла успешно.
                /// \sa Message::Gateway::IGatewayData
                virtual bool createMessage(std::shared_ptr<Message::Gateway::IGatewayData> data, std::vector<uint8_t>& resultData) = 0;

                /// \brief Создает сообщение на основе контейнера IInteractionData
                /// \param[in] data Заполненный контейнер IInteractionData
                /// \param[out] result vector из байтов, содержащий собранное сообщение
                /// \return true, если сборка сообщения прошла успешно.
                /// \sa Message::Interaction::IInteractionData
                virtual bool createMessage(std::shared_ptr<Message::Interaction::IInteractionData> data, std::vector<uint8_t> &result) = 0;

                /// \brief Создает сообщение на основе контейнера IReceiptData
                /// \param[in] data Заполненный контейнер IReceiptData
                /// \param[out] result vector из байтов, содержащий собранное сообщение
                /// \return true, если сборка сообщения прошла успешно.
                /// \sa Message::Receipt::IReceiptData
                virtual bool createMessage(std::shared_ptr<Message::Receipt::IReceiptData> data, std::vector<uint8_t>& result) = 0;
            };//class IMessageBuilder
        }//namespace Builder
    }//namespace MessageProcessor
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_IMESSAGEBUILDER_H