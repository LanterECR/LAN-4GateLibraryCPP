#include "NotificationData.h"

#include "Lanter/Utils/FieldRangeChecker.h"

namespace Lanter {
    namespace Message {
        namespace Notification {

            NotificationCode NotificationData::getCode() const {
                return m_Code;
            }//getCode()

            bool NotificationData::setCode(NotificationCode notificationCode) {
                bool result = false;

                if (Utils::checkNotificationsRange(static_cast<int32_t>(notificationCode))) {
                    m_Code = notificationCode;
                    result = true;
                }//if check

                return result;
            }//setCode()

            bool NotificationData::resetCode() {
                m_Code = NotificationCode::NoNotification;
                return m_Code == NotificationCode::NoNotification;
            }//resetCode()

            const std::string &NotificationData::getMessage() const {
                return m_Message;
            }//getMessage()

            bool NotificationData::setMessage(const std::string &notificationMessage) {
                bool result = false;

                if(!notificationMessage.empty()) {
                    m_Message = notificationMessage;
                    result = true;
                }//notufucationMessage not empty

                return result;
            }//setMessage()

            bool NotificationData::resetMessage() {
                m_Message.clear();
                return m_Message.empty();
            }//resetMessage()

            const std::string &NotificationData::getAdditional() const {
                return m_Additional;
            }//getAdditional()()

            bool NotificationData::setAdditional(const std::string &additional) {
                bool result = false;

                if(!additional.empty()) {
                    m_Additional = additional;
                    result = true;
                }//if additional not empty

                return result;
            }//setAdditional()

            bool NotificationData::resetAdditional() {
                m_Additional.clear();
                return m_Additional.empty();
            }//resetAdditional()

        }//namespace Notification
    }//namespace Message
}//namespace Lanter