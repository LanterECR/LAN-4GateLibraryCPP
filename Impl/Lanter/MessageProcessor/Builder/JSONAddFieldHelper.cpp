#include "JSONAddFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"
#include "Lanter/Utils/Converter.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Builder
        {
            bool AddFieldsHelper::addField(Json::Value &object, const std::string &name, int64_t value)
            {
                if (!name.empty())
                {
                    object[name] = value;
                    return fieldExists(object, name);
                }

                return false;
            }

            bool AddFieldsHelper::addField(Json::Value &object, const std::string &name, const std::string &value)
            {
                if (!name.empty())
                {
                    object[name] = value;
                    return fieldExists(object, name);
                }

                return false;
            }

            bool AddFieldsHelper::addField(Json::Value &object, const std::string &name, const Json::Value &value)
            {
                if (!name.empty())
                {
                    object[name] = value;
                    return fieldExists(object, name);
                }

                return false;
            }

            bool AddFieldsHelper::addField(Json::Value& object, const std::string& name, const std::vector<int8_t>& value)
            {
                if (!name.empty())
                {
                    const std::string& valueBase64 = Utils::Conveter::bytesToBase64(value);
                    object[name] = valueBase64;
                    return fieldExists(object, name);
                }

                return false;
            }

            bool AddFieldsHelper::addArrayElement(Json::Value &array, const Json::Value &element)
            {
                const auto size = array.size();
                array.append(element);
                return (size < array.size());
            }
        }
    }
}