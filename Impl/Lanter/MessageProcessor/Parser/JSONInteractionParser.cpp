#include "JSONInteractionParser.h"

#include "Lanter/Message/Interaction/InteractionDataFactory.h"

#include "Lanter/MessageProcessor/JSONFields/JSONNotificationFields.h"

#include "JSONGetFieldHelper.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            std::shared_ptr<IInteractionData> JSONInteractionParser::parseData(const Json::Value &object) {
                std::shared_ptr<IInteractionData> result = InteractionDataFactory::getInteractionData();
                if (result) {
                    if (!getCode(object, *result)) {
                        result.reset();
                    }
                }
                return result;
            }

            bool JSONInteractionParser::getCode(const Json::Value &object, IInteractionData &data) {
                bool result = false;
                int code;
                if (JSONGetFieldHelper::getField(object, JSONNotificationFields::getCode(), code)) {
                    result = data.setCode(static_cast<InteractionCode>(code));
                }
                return result;
            }
        }
    }
}