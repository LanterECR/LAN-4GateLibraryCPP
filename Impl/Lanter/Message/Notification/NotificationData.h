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
                ~NotificationData() override = default;

                NotificationCode getCode() const override;

                bool setCode(NotificationCode notificationCode) override;

                const std::string &getMessage() const override;

                bool resetCode() override;

                bool setMessage(const std::string &notificationMessage) override;

                bool resetMessage() override;

                bool setAdditional(const std::string &additional) override;

                const std::string &getAdditional() const override;

                bool resetAdditional() override;

            private:
                NotificationCode m_Code = NotificationCode::NoNotification;
                std::string m_Message;
                std::string m_Additional;
            };
        }//Notifications
    }//Lanter
}
#endif //LAN_4GATELIBRARYCPP_NOTIFICATIONDATA_H
