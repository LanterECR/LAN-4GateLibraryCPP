#include "Lanter/Message/Notification/NotificationData.h"

#include "Lanter/Message/Notification/NotificationDataFactory.h"

namespace Lanter {
    namespace Message {
        namespace Notification {

            std::shared_ptr <INotificationData> NotificationDataFactory::getNotificationData() {
                return std::make_shared<NotificationData>();
            }
        }
    }
}