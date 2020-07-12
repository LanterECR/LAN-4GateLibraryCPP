//
// Created by Владимир Лысенков on 08.07.2020.
//

#include "JSONAddFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFieldExists.h"

namespace Lanter {
    namespace MessageProcessor {

        bool AddFieldsHelper::addField(Json::Value &object, const std::string &name, int64_t value) {
            bool result = false;
            if(!name.empty()) {
                object[name] = value;
                result = fieldExists(object, name);
            }
            return result;
        }

        bool AddFieldsHelper::addField(Json::Value &object, const std::string &name, const std::string &value) {
            bool result = false;
            if(!name.empty()) {
                object[name] = value;
                result = fieldExists(object, name);
            }
            return result;
        }

        bool AddFieldsHelper::addField(Json::Value &object, const std::string &name, const Json::Value &value) {
            bool result = false;
            if(!name.empty()) {
                object[name] = value;
                result = fieldExists(object, name);
            }
            return result;
        }

        bool AddFieldsHelper::addArrayElement(Json::Value & array, const Json::Value &element) {
            auto size = array.size();
            array.append(element);
            return size < array.size();
        }
    }
}