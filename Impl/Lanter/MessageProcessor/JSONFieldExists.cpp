#include "JSONFieldExists.h"

#include <algorithm>

namespace Lanter {
    namespace MessageProcessor {

        bool fieldExists(const Json::Value & object, const std::string & fieldName) {
            bool result = false;
            if(object.isObject()) {
                auto members = object.getMemberNames();
                result = std::find(members.begin(), members.end(), fieldName) != members.end();
            }
            return result;
        }
    }
}