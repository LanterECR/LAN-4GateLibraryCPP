//
// Created by Владимир Лысенков on 30.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_INOTIFICATIONDATA_H
#define LAN_4GATELIBRARYCPP_INOTIFICATIONDATA_H

#include <string>

#include "NotificationCode.h"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Message {
        namespace Notification {
            /// \brief Базовый класс-контейнер для получения уведомлений от финансового ПО LAN-4Tap
            class LANTER_VISIBILITY INotificationData {
            public:
                virtual ~INotificationData() = default;

                /// \brief Возвращает код полученного уведомления
                /// \return Если поле не установлено - NoNotification
                /// \sa Notifications
                virtual NotificationCode getCode() const = 0;

                /// \brief Устанавливает код уведомления
                /// \param notificationCode Код уведомления из перечисления Notification за исключением NoNotification
                /// \return true, если поле успешно установлено
                virtual bool setCode(NotificationCode notificationCode) = 0;

                /// \brief Устанавливает код уведомления на значение по умолнчанию
                /// \return true, если код успешно убран
                virtual bool resetCode() = 0;

                /// \brief Возвращает текст уведомления, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая текст уведомления, если он был передан
                virtual const std::string &getMessage() const = 0;

                /// \brief Устанавливает текст уведомления
                /// \param notificationMessage текст уведомления
                /// \return true, если поле успешно установлено
                virtual bool setMessage(const std::string &notificationMessage) = 0;

                /// \brief Очищает сообщение уведомления
                /// \return true, если сообщение успешно очищено
                virtual bool resetMessage() = 0;

                /// \brief Возвращает дополнительные данные уведомления
                /// \param notificationMessage Дополнительные данные уведомления
                virtual const std::string & getAdditional() const = 0;

                /// \brief Устанавливает дополнительнные данные уведомления
                /// \param additional Дополнительные данные уведомления
                /// \return true, если поле успешно установлено
                virtual bool setAdditional(const std::string & additional) = 0;

                /// \brief Очищает дополнительные данные уведомления
                /// \return true, если данные успешно очищены
                virtual bool resetAdditional() = 0;
            };
        }//Notifications
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_INOTIFICATIONDATA_H
