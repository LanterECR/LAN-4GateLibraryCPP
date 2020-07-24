#include "JSONFieldExists.h"

namespace Lanter {
    namespace MessageProcessor {

        bool fieldExists(const Json::Value & object, const std::string & fieldName) {
            auto members = object.getMemberNames();
            return std::find(members.begin(), members.end(), fieldName) != members.end();
        }
    }
}