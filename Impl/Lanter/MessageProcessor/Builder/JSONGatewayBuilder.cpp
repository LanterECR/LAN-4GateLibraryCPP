#include "JSONGatewayBuilder.h"
#include "JSONAddFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"
#include "Lanter/MessageProcessor/JSONFields/JSONGatewayFields.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Builder
        {
            bool JSONGatewayBuilder::createObject(const IGatewayData &gatewayData, Json::Value &object)
            {
                try
                {
                    if (!addCode(gatewayData, object))
                    {
                        return false;
                    }

                    addIP(gatewayData, object);
                    addPort(gatewayData, object);
                    addLink(gatewayData, object);
                    addStatus(gatewayData, object);
                    addData(gatewayData, object);

                    return true;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONGatewayBuilder::addCode(const IGatewayData &gatewayData, Json::Value &object)
            {
                try
                {
                    if (gatewayData.getCode() != GatewayCode::NoCode)
                    {
                        if(!AddFieldsHelper::addField(object, JSONGatewayFields::getCode(), static_cast<int>(gatewayData.getCode())))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONGatewayFields::getCode());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONGatewayBuilder::addIP(const IGatewayData &gatewayData, Json::Value &object)
            {
                try
                {
                    if (!gatewayData.getIP().empty())
                    {
                        if(!AddFieldsHelper::addField(object, JSONGatewayFields::getIP(), gatewayData.getIP()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONGatewayFields::getIP());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONGatewayBuilder::addPort(const IGatewayData & gatewayData, Json::Value &object)
            {
                try
                {
                    if (gatewayData.getPort() != 0)
                    {
                        if(!AddFieldsHelper::addField(object, JSONGatewayFields::getPort(), gatewayData.getPort()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONGatewayFields::getPort());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONGatewayBuilder::addLink(const IGatewayData& gatewayData, Json::Value& object)
            {
                try
                {
                    if (gatewayData.getLink() != 0)
                    {
                        if (!AddFieldsHelper::addField(object, JSONGatewayFields::getLink(), gatewayData.getLink()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONGatewayFields::getLink());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONGatewayBuilder::addStatus(const IGatewayData& gatewayData, Json::Value& object)
            {
                try
                {
                    if (gatewayData.getStatus() != -1)
                    {
                        if (!AddFieldsHelper::addField(object, JSONGatewayFields::getStatus(), gatewayData.getStatus()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONGatewayFields::getStatus());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONGatewayBuilder::addData(const IGatewayData& gatewayData, Json::Value& object)
            {
                try
                {
                    if (gatewayData.getData().size() > 0)
                    {
                        if (!AddFieldsHelper::addField(object, JSONGatewayFields::getData(), gatewayData.getData()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONGatewayFields::getData());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }
        }
    }
}