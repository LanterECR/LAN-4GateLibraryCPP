#include "JSONNotificationBuilder.h"
#include "JSONAddFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"
#include "Lanter/MessageProcessor/JSONFields/JSONNotificationFields.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Builder
        {
            bool JSONNotificationBuilder::createObject(const INotificationData &notificationData, Json::Value &object)
            {
                try
                {
                    if (!addCode(notificationData, object))
                    {
                        return false;
                    }

                    addAdditional(notificationData, object);
                    addMessage(notificationData, object);

                    return true;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONNotificationBuilder::addCode(const INotificationData &notificationData, Json::Value &object)
            {
                try
                {
                    if (notificationData.getCode() != NotificationCode::NoNotification)
                    {
                        if(!AddFieldsHelper::addField(object, JSONNotificationFields::getCode(), static_cast<int>(notificationData.getCode())))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONNotificationFields::getCode());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONNotificationBuilder::addAdditional(const INotificationData &notificationData, Json::Value &object)
            {
                try
                {
                    if (!notificationData.getAdditional().empty())
                    {
                        if(!AddFieldsHelper::addField(object, JSONNotificationFields::getAdditional(), notificationData.getAdditional()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONNotificationFields::getAdditional());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONNotificationBuilder::addMessage(const INotificationData &notificationData, Json::Value &object)
            {
                try
                {
                    if (!notificationData.getMessage().empty())
                    {
                        if(!AddFieldsHelper::addField(object, JSONNotificationFields::getMessage(), notificationData.getMessage()))
                        {
                            return false;
                        }
                    }

                    return fieldExists(object, JSONNotificationFields::getMessage());
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }
        }
    }
}