#include "JSONNotificationParser.h"
#include "Lanter/MessageProcessor/JSONFields/JSONNotificationFields.h"
#include "Lanter/Message/Notification/NotificationDataFactory.h"
#include "JSONGetFieldHelper.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            std::shared_ptr<INotificationData> JSONNotificationParser::parseData(const Json::Value &object)
            {
                std::shared_ptr<INotificationData> result = NotificationDataFactory::getNotificationData();
                if (result)
                {
                    try
                    {
                        if (getCode(object, *result))
                        {
                            getAdditional(object, *result);
                            getMessage(object, *result);
                        }
                        else
                        {
                            result.reset();
                        }
                    }
                    catch (const std::exception& e)
                    {
                        throw;
                    }
                }
                return result;
            }

            bool JSONNotificationParser::getCode(const Json::Value &object, INotificationData &data)
            {
                int code;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONNotificationFields::getCode(), code))
                    {
                        return data.setCode(static_cast<NotificationCode>(code));
                    }
                }
                catch (const std::exception& e)
                {
                    throw;
                }
                return false;
            }

            bool JSONNotificationParser::getAdditional(const Json::Value &object, INotificationData &data)
            {
                std::string additional;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONNotificationFields::getAdditional(), additional))
                    {
                        return data.setAdditional(additional);
                    }
                }
                catch (const std::exception& e)
                {
                    throw;
                }
                return false;
            }

            bool JSONNotificationParser::getMessage(const Json::Value &object, INotificationData &data)
            {
                std::string message;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONNotificationFields::getMessage(), message))
                    {
                        return data.setMessage(message);
                    }
                }
                catch (const std::exception& e)
                {
                    throw;
                }
                return false;
            }
        }
    }
}