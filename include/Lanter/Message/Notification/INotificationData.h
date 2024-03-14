#ifndef LAN_4GATELIBRARYCPP_INOTIFICATIONDATA_H
#define LAN_4GATELIBRARYCPP_INOTIFICATIONDATA_H

#include "Lanter/Utils/VisibilityMacroses.h"
#include "NotificationCode.h"
#include <string>

namespace Lanter
{
    namespace Message
    {
        namespace Notification
        {
            /// \brief Базовый класс-контейнер для получения уведомлений от финансового ПО LAN-4Tap
            class LANTER_VISIBILITY INotificationData
            {
            public:
                virtual ~INotificationData() = default;

                /// \brief Возвращает код полученного уведомления
                /// \return Если поле не установлено - NoNotification
                /// \sa Notifications
                virtual NotificationCode getCode() const = 0;

                /// \brief Устанавливает код уведомления
                /// \param[in] notificationCode Код уведомления из перечисления Notification за исключением NoNotification
                /// \return true, если поле успешно установлено
                virtual bool setCode(NotificationCode notificationCode) = 0;

                /// \brief Устанавливает код уведомления на значение по умолчанию
                /// \return true, если код успешно убран
                virtual bool resetCode() = 0;

                /// \brief Возвращает текст уведомления, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая текст уведомления, если он был передан
                virtual const std::string &getMessage() const = 0;

                /// \brief Устанавливает текст уведомления
                /// \param[in] message текст уведомления
                /// \return true, если поле успешно установлено
                virtual bool setMessage(const std::string &message) = 0;

                /// \brief Очищает сообщение уведомления
                /// \return true, если сообщение успешно очищено
                virtual bool resetMessage() = 0;

                /// \brief Возвращает дополнительные данные уведомления
                /// \return Дополнительные данные уведомления
                virtual const std::string & getAdditional() const = 0;

                /// \brief Устанавливает дополнительные данные уведомления
                /// \param[in] additional Дополнительные данные уведомления
                /// \return true, если поле успешно установлено
                virtual bool setAdditional(const std::string & additional) = 0;

                /// \brief Очищает дополнительные данные уведомления
                /// \return true, если данные успешно очищены
                virtual bool resetAdditional() = 0;
            };//class INotificationData
        }//namespace Notifications
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_INOTIFICATIONDATA_H