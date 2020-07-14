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

            bool NotificationData::setCode(NotificationCodes notificationCode) {
                bool result = false;
                if (Utils::checkNotificationsRange(static_cast<int32_t>(notificationCode))) {
                    m_Notification = notificationCode;
                    result = true;
                }
                return result;
            }

            const std::string &NotificationData::getMessage() const {
                return m_NotificationText;
            }

            bool NotificationData::setMessage(const std::string &notificationMessage) {
                bool result = false;
                if(!notificationMessage.empty()) {
                    m_NotificationText = notificationMessage;
                    result = true;
                }
                return result;
            }

            const std::string &NotificationData::getAdditional() const {
                return m_Additional;
            }

            bool NotificationData::setAdditional(const std::string &additional) {
                bool result = false;
                if(!additional.empty()) {
                    m_Additional = additional;
                    result = true;
                }
                return result;
            }

        }//Notifications
    }
}//Lanter