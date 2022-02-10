#ifndef LAN_4GATELIBRARYCPP_JSONGETFIELDSHELPER_H
#define LAN_4GATELIBRARYCPP_JSONGETFIELDSHELPER_H

#include <cstdint>

#include "json/json.h"


namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            class JSONGetFieldHelper {
            public:
                static bool getField(const Json::Value &object, const std::string &fieldName, bool &value);

                static bool getField(const Json::Value &object, const std::string &fieldName, int &value);

                static bool getField(const Json::Value &object, const std::string &fieldName, int64_t &value);

                static bool getField(const Json::Value &object, const std::string &fieldName, std::string &value);

                static bool getField(const Json::Value &object, const std::string &fieldName, Json::Value &value);
            };
        }
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONGETFIELDSHELPER_H
