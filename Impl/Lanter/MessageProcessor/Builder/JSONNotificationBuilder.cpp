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
                    bool result = addCode(notificationData, object);
                    addAdditional(notificationData, object);
                    addMessage(notificationData, object);

                    return result;
                }
                catch (const std::exception& e)
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
                        AddFieldsHelper::addField(object, JSONNotificationFields::getCode(),
                                                  static_cast<int>(notificationData.getCode()));
                    }

                    return fieldExists(object, JSONNotificationFields::getCode());
                }
                catch (const std::exception& e)
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
                        AddFieldsHelper::addField(object, JSONNotificationFields::getAdditional(),
                                                  notificationData.getAdditional());
                    }

                    return fieldExists(object, JSONNotificationFields::getAdditional());
                }
                catch (const std::exception& e)
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
                        AddFieldsHelper::addField(object, JSONNotificationFields::getMessage(),
                                                  notificationData.getMessage());
                    }

                    return fieldExists(object, JSONNotificationFields::getMessage());
                }
                catch (const std::exception& e)
                {
                    throw;
                }
            }
        }
    }
}