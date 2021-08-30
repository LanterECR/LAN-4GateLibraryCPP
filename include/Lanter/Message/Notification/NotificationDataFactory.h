#ifndef LAN_4GATELIBRARYCPP_NOTIFICATIONDATAFACTORY_H
#define LAN_4GATELIBRARYCPP_NOTIFICATIONDATAFACTORY_H

#include <memory>

#include "INotificationData.h"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Message {
        namespace Notification {
            /// \brief Фабричный класс, возвращающий объект уведомления
            class LANTER_VISIBILITY NotificationDataFactory {
            public:
                /// \brief Возвращает указатель на объект интерфейса INotificationData и заполняет поле NotificationCode
                /// \param[in] code Код уведомления
                /// \return Указатель на объект интерфейса INotificationData
                static std::shared_ptr<INotificationData> getNotificationData(NotificationCode code);

                /// \brief Возвращает указатель на объект интерфейса INotificationData
                /// \return Указатель на объект интерфейса INotificationData
                static std::shared_ptr<INotificationData> getNotificationData();

            };//class NotificationDataFactory
        }//namespace Notification
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_NOTIFICATIONDATAFACTORY_H
