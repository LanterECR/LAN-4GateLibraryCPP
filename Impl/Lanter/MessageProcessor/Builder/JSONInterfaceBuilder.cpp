#include "JSONInterfaceBuilder.h"
#include "JSONAddFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"
#include "Lanter/MessageProcessor/JSONFields/JSONInterfaceFields.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Builder
        {
            bool JSONInterfaceBuilder::createObject(const IInterfaceData &uiData, Json::Value &object)
            {
                try
                {
                    if (!addCode(uiData, object))
                    {
                        return false;
                    }

                    addCode(uiData, object);
                    addTitle(uiData, object);
                    addValue(uiData, object);
                    addInfoText(uiData, object);
                    addMinLen(uiData, object);
                    addMaxLen(uiData, object);
                    addResult(uiData, object);

                    return true;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONInterfaceBuilder::addCode(const IInterfaceData& uiData, Json::Value &object)
            {
                try
                {
                    if (uiData.getType() != InterfaceType::Unknown)
                    {
                        if(!AddFieldsHelper::addField(object, JSONInterfaceFields::getType(), static_cast<int>(uiData.getType())))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONInterfaceFields::getType());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONInterfaceBuilder::addTitle(const IInterfaceData& uiData, Json::Value &object)
            {
                try
                {
                    if (!uiData.getTitle().empty())
                    {
                        if(!AddFieldsHelper::addField(object, JSONInterfaceFields::getTitle(), uiData.getTitle()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONInterfaceFields::getTitle());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONInterfaceBuilder::addValue(const IInterfaceData& uiData, Json::Value &object)
            {
                try
                {
                    if (!uiData.getValue().empty())
                    {
                        if(!AddFieldsHelper::addField(object, JSONInterfaceFields::getValue(), uiData.getValue()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONInterfaceFields::getValue());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONInterfaceBuilder::addInfoText(const IInterfaceData& uiData, Json::Value& object)
            {
                try
                {
                    if (!uiData.getInfoText().empty())
                    {
                        if (!AddFieldsHelper::addField(object, JSONInterfaceFields::getInfoText(), uiData.getInfoText()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONInterfaceFields::getInfoText());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONInterfaceBuilder::addMinLen(const IInterfaceData& uiData, Json::Value& object)
            {
                try
                {
                    if (!uiData.getMinLen().empty())
                    {
                        if (!AddFieldsHelper::addField(object, JSONInterfaceFields::getMinLen(), uiData.getMinLen()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONInterfaceFields::getMinLen());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONInterfaceBuilder::addMaxLen(const IInterfaceData& uiData, Json::Value& object)
            {
                try
                {
                    if (!uiData.getMaxLen().empty())
                    {
                        if (!AddFieldsHelper::addField(object, JSONInterfaceFields::getMaxLen(), uiData.getMaxLen()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONInterfaceFields::getMaxLen());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONInterfaceBuilder::addResult(const IInterfaceData& uiData, Json::Value& object)
            {
                try
                {
                    if (!uiData.getResult().empty())
                    {
                        if (!AddFieldsHelper::addField(object, JSONInterfaceFields::getResult(), uiData.getResult()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONInterfaceFields::getResult());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }
        }
    }
}