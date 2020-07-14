//
// Created by Владимир Лысенков on 07.07.2020.
//
#include "Lanter/MessageProcessor/MessageBuilder/MessageBuilderFactory.h"

#include "Lanter/MessageProcessor/MessageBuilder/JSONMessageBuilder.h"

namespace Lanter {
    namespace MessageProcessor {

        std::shared_ptr<IMessageBuilder> MessageBuilderFactory::getMessageBuilder() {
            return std::make_shared<JSONMessageBuilder>();
        }
    }
}
