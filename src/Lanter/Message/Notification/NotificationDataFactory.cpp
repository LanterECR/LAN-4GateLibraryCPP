#include "Lanter/Message/Notification/NotificationData.h"
#include "Lanter/Message/Notification/NotificationDataFactory.h"

namespace Lanter
{
    namespace Message
    {
        namespace Notification
        {
            std::shared_ptr<INotificationData> NotificationDataFactory::getNotificationData(NotificationCode code)
            {
                auto notification = std::make_shared<NotificationData>();
                if(notification != nullptr)
                {
                    notification->setCode(code);
                }

                return notification;
            }

            std::shared_ptr <INotificationData> NotificationDataFactory::getNotificationData()
            {
                return getNotificationData(NotificationCode::NoNotification);
            } //getNotificationData()
        }//namespace Notification
    }//namespace Message
}//namespace Lanter