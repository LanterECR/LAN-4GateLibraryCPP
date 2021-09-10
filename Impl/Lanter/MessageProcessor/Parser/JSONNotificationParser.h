#ifndef LAN_4GATELIBRARYCPP_JSONNOTIFICATIONPARSER_H
#define LAN_4GATELIBRARYCPP_JSONNOTIFICATIONPARSER_H

#include <memory>

#include "json/json.h"

#include "Lanter/Message/Notification/INotificationData.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            using namespace Message;
            using namespace Message::Notification;

            class JSONNotificationParser {
            public:
                std::shared_ptr<INotificationData> parseData(const Json::Value &object);

                bool getCode(const Json::Value &object, INotificationData &data);

                bool getAdditional(const Json::Value &object, INotificationData &data);

                bool getMessage(const Json::Value &object, INotificationData &data);
            };
        }
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONNOTIFICATIONPARSER_H
