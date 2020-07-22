//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "NotificationData.h"

#include "Lanter/Utils/FieldRangeChecker.h"

namespace Lanter {
    namespace Message {
        namespace Notification {

            NotificationCode NotificationData::getCode() const {
                return m_Code;
            }

            bool NotificationData::setCode(NotificationCode notificationCode) {
                bool result = false;
                if (Utils::checkNotificationsRange(static_cast<int32_t>(notificationCode))) {
                    m_Code = notificationCode;
                    result = true;
                }
                return result;
            }

            bool NotificationData::resetCode() {
                m_Code = NotificationCode::NoNotification;
                return m_Code == NotificationCode::NoNotification;
            }

            const std::string &NotificationData::getMessage() const {
                return m_Message;
            }

            bool NotificationData::setMessage(const std::string &notificationMessage) {
                bool result = false;
                if(!notificationMessage.empty()) {
                    m_Message = notificationMessage;
                    result = true;
                }
                return result;
            }

            bool NotificationData::resetMessage() {
                m_Message.clear();
                return m_Message.empty();
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

            bool NotificationData::resetAdditional() {
                m_Additional.clear();
                return m_Additional.empty();
            }

        }//Notifications
    }
}//Lanter