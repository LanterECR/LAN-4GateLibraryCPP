//
// Created by Владимир Лысенков on 30.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_NOTIFICATIONDATAFACTORY_H
#define LAN_4GATELIBRARYCPP_NOTIFICATIONDATAFACTORY_H

#include <memory>

#include "INotificationData.h"

namespace Lanter {
    namespace Notifications {
        class NotificationDataFactory {
        public:
            static std::shared_ptr<INotificationData> getNotificationData();
        };
    }
}
#endif //LAN_4GATELIBRARYCPP_NOTIFICATIONDATAFACTORY_H
