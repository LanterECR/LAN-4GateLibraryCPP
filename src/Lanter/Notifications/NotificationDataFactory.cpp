//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "Lanter/Notifications/NotificationDataFactory.h"

#include "Lanter/Notifications/NotificationData.h"

namespace Lanter {
    namespace Notifications {

        std::shared_ptr<INotificationData> NotificationDataFactory::getNotificationData() {
            return std::make_shared<NotificationData>();
        }
    }
}