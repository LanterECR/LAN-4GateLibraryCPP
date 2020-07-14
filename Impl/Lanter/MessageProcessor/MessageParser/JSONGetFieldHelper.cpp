//
// Created by Владимир Лысенков on 14.07.2020.
//

#include "JSONGetFieldHelper.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"

namespace Lanter {
    namespace MessageProcessor {

        bool JSONGetFieldHelper::getFieldInt(const Json::Value &object, const std::string &fieldName, int &value) {
            bool result = fieldExists(object, fieldName);
            if(result && object[fieldName].isInt()) {
                value = object[fieldName].asInt();
            }
            return result;
        }

        bool JSONGetFieldHelper::getFieldInt64(const Json::Value &object, const std::string &fieldName, int64_t &value) {
            bool result = fieldExists(object, fieldName);
            if(result && object[fieldName].isInt64()) {
                value = object[fieldName].asInt64();
            }
            return result;
        }

        bool JSONGetFieldHelper::getFieldString(const Json::Value &object, const std::string &fieldName, std::string &value) {
            bool result = fieldExists(object, fieldName);
            if(result && object[fieldName].isString()) {
                value = object[fieldName].asString();
            }
            return result;
        }

        bool JSONGetFieldHelper::getFieldObject(const Json::Value &object, const std::string &fieldName, Json::Value &value) {
            bool result = fieldExists(object, fieldName);
            if(result && object[fieldName].isObject()) {
                value = object[fieldName];
            }
            return result;
        }
    }
}