//
// Created by Владимир Лысенков on 13.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_JSONMESSAGETYPECHECKER_H
#define LAN_4GATELIBRARYCPP_JSONMESSAGETYPECHECKER_H

#include "json/json.h"

#include "Lanter/MessageProcessor/MessageParser/MessageType.h"

namespace Lanter {
    namespace MessageProcessor {
        class JSONMessageTypeChecker {
        public:
            static MessageType checkType(const Json::Value & root);

        private:
            JSONMessageTypeChecker() = default;
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONMESSAGETYPECHECKER_H
