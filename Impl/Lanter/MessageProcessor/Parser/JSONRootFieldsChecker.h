#ifndef LAN_4GATELIBRARYCPP_JSONROOTFIELDSCHECKER_H
#define LAN_4GATELIBRARYCPP_JSONROOTFIELDSCHECKER_H

#include "json/json.h"
namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            class JSONRootFieldsChecker {
            public:
                static bool checkFields(const Json::Value &root);
            };
        }
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONROOTFIELDSCHECKER_H
