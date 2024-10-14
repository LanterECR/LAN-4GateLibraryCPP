#include "JSONFieldExists.h"

#include <algorithm>

namespace Lanter
{
    namespace MessageProcessor
    {
        bool fieldExists(const Json::Value& object, const std::string& fieldName)
        {
            if(object.isObject())
            {
                auto members = object.getMemberNames();
                return (std::find(members.begin(), members.end(), fieldName) != members.end());
            }
            return false;
        }
    }
}