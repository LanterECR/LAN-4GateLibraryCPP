#include "JSONMessageTypeChecker.h"

#include "Lanter/MessageProcessor/JSONFields/JSONClassFieldsValues.h"
#include "Lanter/MessageProcessor/JSONFields/JSONRootFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            MessageType JSONMessageTypeChecker::checkType(const Json::Value &root) {
                MessageType result = MessageType::Error;

                if (fieldExists(root, JSONRootFields::getClassField())) {
                    std::string classType = root[JSONRootFields::getClassField()].asString();

                    if (JSONClassFieldValues::getRequestValue() == classType) {
                        result = MessageType::Request;
                    } else if (JSONClassFieldValues::getResponseValue() == classType) {
                        result = MessageType::Response;
                    } else if (JSONClassFieldValues::getNotificationValue() == classType) {
                        result = MessageType::Notification;
                    } else if (JSONClassFieldValues::getCommunicationValue() == classType) {
                        result = MessageType::Communication;
                    } else if (JSONClassFieldValues::getInteractionValue() == classType) {
                        result = MessageType::Interaction;
                    } else {
                        result = MessageType::Unknown;
                    }
                }
                return result;
            }
        }
    }
}