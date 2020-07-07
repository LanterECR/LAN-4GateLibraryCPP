//
// Created by Владимир Лысенков on 30.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_NOTIFICATIONDATA_H
#define LAN_4GATELIBRARYCPP_NOTIFICATIONDATA_H

#include "Lanter/Message/Notifications/INotificationData.h"

namespace Lanter {
    namespace Message {
        namespace Notification {
            /// \brief Базовый класс-контейнер для получения уведомлений от финансового ПО LAN-4Tap
            class NotificationData : public INotificationData {
            public:
                virtual ~NotificationData() override = default;

                NotificationCodes getNotificationCode() const override;

                void setNotificationCode(NotificationCodes notificationCode) override;

                const std::string &getNotificationMessage() const override;

                void setNotificationMessage(const std::string &notificationMessage) override;

            private:
                NotificationCodes m_Notification = NotificationCodes::NoNotification;
                std::string m_NotificationText;
            };
        }//Notifications
    }//Lanter
}
#endif //LAN_4GATELIBRARYCPP_NOTIFICATIONDATA_H
