#include "JSONRootFieldsChecker.h"

#include "Lanter/MessageProcessor/JSONFields/JSONRootFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            bool JSONRootFieldsChecker::checkFields(const Json::Value &root) {
                bool result = false;

                bool fieldsExists = fieldExists(root, JSONRootFields::getClassField()) &&
                                    fieldExists(root, JSONRootFields::getObjectField());
                if (fieldsExists) {
                    bool classCorrect = root[JSONRootFields::getClassField()].isString();
                    bool objectCorrect = root[JSONRootFields::getObjectField()].isObject();

                    result = classCorrect && objectCorrect;
                }

                return result;
            }
        }
    }
}