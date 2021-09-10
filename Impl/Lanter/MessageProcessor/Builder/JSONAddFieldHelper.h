#ifndef LAN_4GATELIBRARYCPP_JSONADDFIELDHELPER_H
#define LAN_4GATELIBRARYCPP_JSONADDFIELDHELPER_H

#include "json/json.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Builder {
            class AddFieldsHelper {
            public:
                static bool addField(Json::Value &object, const std::string &name, int64_t value);

                static bool addField(Json::Value &object, const std::string &name, const std::string &value);

                static bool addField(Json::Value &object, const std::string &name, const Json::Value &value);

                static bool addArrayElement(Json::Value &array, const Json::Value &element);

            private:
                AddFieldsHelper() = default;
            };
        }
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONADDFIELDHELPER_H
