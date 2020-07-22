//
// Created by Владимир Лысенков on 10.07.2020.
//

#include "JSONNotificationBuilder.h"

#include "JSONAddFieldHelper.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"
#include "Lanter/MessageProcessor/JSONMessageFields.h"

namespace Lanter {
    namespace MessageProcessor {

        bool JSONNotificationBuilder::createObject(const INotificationData &notificationData, Json::Value &object) {
            bool result = addCode(notificationData, object);
            addAdditional(notificationData, object);
            addMessage(notificationData, object);
            return result;
        }

        bool
        JSONNotificationBuilder::addCode(const INotificationData &notificationData, Json::Value &object) {
            if(notificationData.getCode() != NotificationCode::NoNotification) {
                AddFieldsHelper::addField(object, JSONNotificationFields::getCode(),
                                          static_cast<int>(notificationData.getCode()));
            }
            return fieldExists(object, JSONNotificationFields::getCode());
        }

        bool JSONNotificationBuilder::addAdditional(const INotificationData &notificationData, Json::Value &object) {
            if(!notificationData.getAdditional().empty()) {
                AddFieldsHelper::addField(object, JSONNotificationFields::getAdditional(), notificationData.getAdditional());
            }
            return fieldExists(object, JSONNotificationFields::getAdditional());
        }

        bool JSONNotificationBuilder::addMessage(const INotificationData &notificationData, Json::Value &object) {
            if(!notificationData.getMessage().empty()) {
                AddFieldsHelper::addField(object, JSONNotificationFields::getMessage(), notificationData.getMessage());
            }
            return fieldExists(object, JSONNotificationFields::getMessage());
        }
    }
}