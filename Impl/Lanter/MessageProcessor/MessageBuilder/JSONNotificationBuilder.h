//
// Created by Владимир Лысенков on 10.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_JSONNOTIFICATIONBUILDER_H
#define LAN_4GATELIBRARYCPP_JSONNOTIFICATIONBUILDER_H

#include "Lanter/Message/Notification/INotificationData.h"

#include "json/json.h"

namespace Lanter {
    using namespace Message;
    using namespace Message::Notification;

    namespace MessageProcessor {
        class JSONNotificationBuilder {
        public:
            bool createObject(const INotificationData & notificationData, Json::Value & object);

            static bool addCode(const INotificationData & notificationData, Json::Value & object);

            static bool addAdditional(const INotificationData & notificationData, Json::Value & object);

            static bool addMessage(const INotificationData & notificationData, Json::Value & object);
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONNOTIFICATIONBUILDER_H
