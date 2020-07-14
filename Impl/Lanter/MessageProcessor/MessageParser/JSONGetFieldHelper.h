//
// Created by Владимир Лысенков on 14.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_JSONGETFIELDSHELPER_H
#define LAN_4GATELIBRARYCPP_JSONGETFIELDSHELPER_H

#include <cstdint>

#include "json/json.h"


namespace Lanter {
    namespace MessageProcessor {
        class JSONGetFieldHelper {
        public:
            static bool getFieldInt(const Json::Value & object, const std::string & fieldName, int & value);
            static bool getFieldInt64(const Json::Value & object, const std::string & fieldName, int64_t & value);
            static bool getFieldString(const Json::Value & object, const std::string & fieldName, std::string & value);
            static bool getFieldObject(const Json::Value & object, const std::string & fieldName, Json::Value & value);
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONGETFIELDSHELPER_H
