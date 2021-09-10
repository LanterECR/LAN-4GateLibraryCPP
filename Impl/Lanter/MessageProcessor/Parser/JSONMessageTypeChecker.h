#ifndef LAN_4GATELIBRARYCPP_JSONMESSAGETYPECHECKER_H
#define LAN_4GATELIBRARYCPP_JSONMESSAGETYPECHECKER_H

#include "json/json.h"

#include "Lanter/MessageProcessor/Parser/MessageType.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            class JSONMessageTypeChecker {
            public:
                static MessageType checkType(const Json::Value &root);

            private:
                JSONMessageTypeChecker() = default;
            };
        }
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONMESSAGETYPECHECKER_H
