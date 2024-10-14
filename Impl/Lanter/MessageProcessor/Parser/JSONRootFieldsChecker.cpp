#include "JSONRootFieldsChecker.h"

#include "Lanter/MessageProcessor/JSONFields/JSONRootFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            bool JSONRootFieldsChecker::checkFields(const Json::Value &root)
            {
                if (fieldExists(root, JSONRootFields::getClassField()) && fieldExists(root, JSONRootFields::getObjectField()))
                {
                    const bool classCorrect = root[JSONRootFields::getClassField()].isString();
                    const bool objectCorrect = root[JSONRootFields::getObjectField()].isObject();

                    return classCorrect && objectCorrect;
                }

                return false;
            }
        }
    }
}