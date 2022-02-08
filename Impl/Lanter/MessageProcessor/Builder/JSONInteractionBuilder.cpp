#include "JSONInteractionBuilder.h"

#include "JSONAddFieldHelper.h"

#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"
#include "Lanter/MessageProcessor/JSONFields/JSONInteractionFields.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Builder {

            bool JSONInteractionBuilder::createObject(const IInteractionData &notificationData, Json::Value &object) {
                return addCode(notificationData, object);
            }

            bool JSONInteractionBuilder::addCode(const IInteractionData &interactionData, Json::Value &object) {
                if (interactionData.getCode() != InteractionCode::NoInteraction) {
                    AddFieldsHelper::addField(object, JSONInteractionFields::getCode(),
                                              static_cast<int>(interactionData.getCode()));
                }
                return fieldExists(object, JSONInteractionFields::getCode());
            }
        }
    }
}