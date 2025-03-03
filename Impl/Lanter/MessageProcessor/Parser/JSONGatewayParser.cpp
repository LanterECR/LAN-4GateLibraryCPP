#include "JSONGatewayParser.h"
#include "Lanter/MessageProcessor/JSONFields/JSONGatewayFields.h"
#include "Lanter/Message/Gateway/GatewayDataFactory.h"
#include "JSONGetFieldHelper.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            std::shared_ptr<IGatewayData> JSONGatewayParser::parseData(const Json::Value &object)
            {
                std::shared_ptr<IGatewayData> result = GatewayDataFactory::getGatewayData();
                if (result)
                {
                    try
                    {
                        if (getCode(object, *result))
                        {
                            getIP(object, *result);
                            getPort(object, *result);
                            getLink(object, *result);
                            getStatus(object, *result);
                            getData(object, *result);
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

            bool JSONGatewayParser::getCode(const Json::Value &object, IGatewayData &data)
            {
                int code;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONGatewayFields::getCode(), code))
                    {
                        return data.setCode(static_cast<GatewayCode>(code));
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONGatewayParser::getIP(const Json::Value &object, IGatewayData &data)
            {
                std::string ip;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONGatewayFields::getIP(), ip))
                    {
                        return data.setIP(ip);
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONGatewayParser::getPort(const Json::Value& object, IGatewayData& data)
            {
                int port;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONGatewayFields::getPort(), port))
                    {
                        return data.setPort(port);
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONGatewayParser::getLink(const Json::Value& object, IGatewayData& data)
            {
                int link;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONGatewayFields::getLink(), link))
                    {
                        return data.setLink(link);
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONGatewayParser::getStatus(const Json::Value& object, IGatewayData& data)
            {
                int status;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONGatewayFields::getStatus(), status))
                    {
                        return data.setLink(status);
                    }
                }
                catch (const std::exception&)
                {
                    throw;
                }
                return false;
            }

            bool JSONGatewayParser::getData(const Json::Value& object, IGatewayData& data)
            {
                std::vector<int8_t> dt;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONGatewayFields::getData(), dt))
                    {
                        return data.setData(dt);
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