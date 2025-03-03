#include "JSONInterfaceParser.h"
#include "Lanter/MessageProcessor/JSONFields/JSONInterfaceFields.h"
#include "Lanter/Message/Interface/InterfaceDataFactory.h"
#include "JSONGetFieldHelper.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            std::shared_ptr<IInterfaceData> JSONInterfaceParser::parseData(const Json::Value &object)
            {
                std::shared_ptr<IInterfaceData> result = InterfaceDataFactory::getInterfaceData();
                if (result)
                {
                    try
                    {
                        if (getType(object, *result))
                        {
                            getTitle(object, *result);
                            getValue(object, *result);
                            getInfoText(object, *result);
                            getMinLen(object, *result);
                            getMaxLen(object, *result);
                            getResult(object, *result);
                        }
                        else
                        {
                            result.reset();
                        }
                    }
                    catch (const std::exception&)
                    {
                        throw;
                    }
                }
                return result;
            }

            bool JSONInterfaceParser::getType(const Json::Value &object, IInterfaceData &data)
            {
                int type;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONInterfaceFields::getType(), type))
                    {
                        return data.setType(static_cast<InterfaceType>(type));
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONInterfaceParser::getTitle(const Json::Value &object, IInterfaceData &data)
            {
                std::string title;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONInterfaceFields::getTitle(), title))
                    {
                        return data.setTitle(title);
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONInterfaceParser::getValue(const Json::Value &object, IInterfaceData &data)
            {
                std::string value;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONInterfaceFields::getValue(), value))
                    {
                        return data.setValue(value);
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONInterfaceParser::getInfoText(const Json::Value& object, IInterfaceData& data)
            {
                std::string infoText;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONInterfaceFields::getInfoText(), infoText))
                    {
                        return data.setInfoText(infoText);
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONInterfaceParser::getMinLen(const Json::Value& object, IInterfaceData& data)
            {
                std::string minLen;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONInterfaceFields::getMinLen(), minLen))
                    {
                        return data.setMinLen(minLen);
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONInterfaceParser::getMaxLen(const Json::Value& object, IInterfaceData& data)
            {
                std::string maxLen;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONInterfaceFields::getMaxLen(), maxLen))
                    {
                        return data.setMaxLen(maxLen);
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONInterfaceParser::getResult(const Json::Value& object, IInterfaceData& data)
            {
                std::string result;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONInterfaceFields::getResult(), result))
                    {
                        return data.setResult(result);
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }
        }
    }
}