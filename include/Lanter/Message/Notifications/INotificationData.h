//
// Created by Владимир Лысенков on 30.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_INOTIFICATIONDATA_H
#define LAN_4GATELIBRARYCPP_INOTIFICATIONDATA_H

#include <string>
#include "NotificationCodes.h"

namespace Lanter {
    namespace Message {
        namespace Notification {
            /// \brief Базовый класс-контейнер для получения уведомлений от финансового ПО LAN-4Tap
            class INotificationData {
            public:
                virtual ~INotificationData() = default;

                /// \brief Возвращает код полученного уведомления
                /// \return Если поле не установлено - NoNotification
                /// \sa Notifications
                virtual NotificationCodes getNotificationCode() const = 0;

                /// \brief Устанавливает код уведомления
                /// \param notificationCode Код уведомления из перечисления Notification за исключением NoNotification
                /// \throw invalid_argument, если код уведомления вне диапазона
                virtual void setNotificationCode(NotificationCodes notificationCode) = 0;

                /// \brief Возвращает текст уведомления, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая текст уведомления, если он был передан
                virtual const std::string &getNotificationMessage() const = 0;

                /// \brief Устанавливает текст уведомления
                /// \param notificationMessage текст уведомления
                virtual void setNotificationMessage(const std::string &notificationMessage) = 0;
            };
        }//Notifications
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_INOTIFICATIONDATA_H
