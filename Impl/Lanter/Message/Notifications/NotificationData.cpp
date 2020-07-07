//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "NotificationData.h"

#include "Lanter/Utils/FieldRangeChecker.h"

namespace Lanter {
    namespace Message {
        namespace Notification {

            NotificationCodes NotificationData::getNotificationCode() const {
                return m_Notification;
            }

            void NotificationData::setNotificationCode(NotificationCodes notificationCode) {
                if (Utils::checkNotificationsRange(static_cast<int32_t>(notificationCode))) {
                    m_Notification = notificationCode;
                }
            }

            const std::string &NotificationData::getNotificationMessage() const {
                return m_NotificationText;
            }

            void NotificationData::setNotificationMessage(const std::string &notificationMessage) {
                m_NotificationText = notificationMessage;
            }

        }//Notifications
    }
}//Lanter