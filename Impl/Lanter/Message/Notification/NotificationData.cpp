//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "NotificationData.h"

#include "Lanter/Utils/FieldRangeChecker.h"

namespace Lanter {
    namespace Message {
        namespace Notification {

            NotificationCodes NotificationData::getCode() const {
                return m_Notification;
            }

            void NotificationData::setCode(NotificationCodes notificationCode) {
                if (Utils::checkNotificationsRange(static_cast<int32_t>(notificationCode))) {
                    m_Notification = notificationCode;
                }
            }

            const std::string &NotificationData::getMessage() const {
                return m_NotificationText;
            }

            void NotificationData::setMessage(const std::string &notificationMessage) {
                m_NotificationText = notificationMessage;
            }

            void NotificationData::setAdditional(const std::string &additional) {
                m_Additional = additional;
            }

            const std::string &NotificationData::getAdditional() const {
                return m_Additional;
            }

        }//Notifications
    }
}//Lanter