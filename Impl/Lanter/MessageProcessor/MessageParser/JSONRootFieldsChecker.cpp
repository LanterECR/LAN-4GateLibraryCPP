//
// Created by Владимир Лысенков on 13.07.2020.
//

#include "JSONRootFieldsChecker.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"
#include "Lanter/MessageProcessor/JSONFieldExists.h"

namespace Lanter {
    namespace MessageProcessor {

        bool JSONRootFieldsChecker::checkFields(const Json::Value &root) {
            bool result = false;

            bool fieldsExists = fieldExists(root, JSONRootFields::getClassField()) &&
                                fieldExists(root, JSONRootFields::getObjectField());
            if(fieldsExists) {
                bool classCorrect = root[JSONRootFields::getClassField()].isString();
                bool objectCorrect = root[JSONRootFields::getObjectField()].isObject();

                result = classCorrect && objectCorrect;
            }

            return result;
        }
    }
}