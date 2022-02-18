#include "JSONGetFieldHelper.h"

#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            bool JSONGetFieldHelper::getField(const Json::Value &object, const std::string &fieldName, bool &value) {
                bool result = false;
                if(fieldExists(object, fieldName)) {
                    if (object[fieldName].isInt()) {
                        value = object[fieldName].asInt();
                        result = true;
                    } else if (object[fieldName].isBool()) {
                        value = object[fieldName].asBool();
                        result = true;
                    }
                }
                return result;
            }

            bool JSONGetFieldHelper::getField(const Json::Value &object, const std::string &fieldName, int &value) {
                bool result = fieldExists(object, fieldName) && object[fieldName].isInt();
                if (result) {
                    value = object[fieldName].asInt();
                }
                return result;
            }

            bool JSONGetFieldHelper::getField(const Json::Value &object, const std::string &fieldName, int64_t &value) {
                bool result = fieldExists(object, fieldName) && object[fieldName].isInt64();
                if (result) {
                    value = object[fieldName].asInt64();
                }
                return result;
            }

            bool
            JSONGetFieldHelper::getField(const Json::Value &object, const std::string &fieldName, std::string &value) {
                bool result = fieldExists(object, fieldName) && object[fieldName].isString();
                if (result) {
                    value = object[fieldName].asString();
                }
                return result;
            }

            bool
            JSONGetFieldHelper::getField(const Json::Value &object, const std::string &fieldName, Json::Value &value) {
                bool result =
                        fieldExists(object, fieldName) && (object[fieldName].isObject() || object[fieldName].isArray());
                if (result) {
                    value = object[fieldName];
                }
                return result;
            }
        }
    }
}