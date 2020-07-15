//
// Created by Владимир Лысенков on 30.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_NOTIFICATIONDATAFACTORY_H
#define LAN_4GATELIBRARYCPP_NOTIFICATIONDATAFACTORY_H

#include <memory>

#include "INotificationData.h"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Message {
        namespace Notification {
            class LANTER_VISIBILITY NotificationDataFactory {
            public:
                static std::shared_ptr<INotificationData> getNotificationData();
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_NOTIFICATIONDATAFACTORY_H
