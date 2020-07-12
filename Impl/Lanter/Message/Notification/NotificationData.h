//
// Created by Владимир Лысенков on 30.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_NOTIFICATIONDATA_H
#define LAN_4GATELIBRARYCPP_NOTIFICATIONDATA_H

#include "Lanter/Message/Notification/INotificationData.h"

namespace Lanter {
    namespace Message {
        namespace Notification {
            /// \brief Базовый класс-контейнер для получения уведомлений от финансового ПО LAN-4Tap
            class NotificationData : public INotificationData {
            public:
                virtual ~NotificationData() override = default;

                NotificationCodes getCode() const override;

                void setCode(NotificationCodes notificationCode) override;

                const std::string &getMessage() const override;

                void setMessage(const std::string &notificationMessage) override;

                void setAdditional(const std::string &additional) override;

                const std::string &getAdditional() const override;

            private:
                NotificationCodes m_Notification = NotificationCodes::NoNotification;
                std::string m_NotificationText;
                std::string m_Additional;
            };
        }//Notifications
    }//Lanter
}
#endif //LAN_4GATELIBRARYCPP_NOTIFICATIONDATA_H
