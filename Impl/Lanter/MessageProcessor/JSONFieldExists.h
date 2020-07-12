//
// Created by Владимир Лысенков on 08.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_JSONFIELDEXISTS_H
#define LAN_4GATELIBRARYCPP_JSONFIELDEXISTS_H

#include "json/json.h"

namespace Lanter {
    namespace MessageProcessor {
        bool fieldExists(const Json::Value & object, const std::string & fieldName);
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONFIELDEXISTS_H
