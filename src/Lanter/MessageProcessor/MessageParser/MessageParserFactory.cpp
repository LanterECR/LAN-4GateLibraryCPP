//
// Created by Владимир Лысенков on 12.07.2020.
//

#include "Lanter/MessageProcessor/MessageParser/MessageParserFactory.h"


namespace Lanter {
    namespace MessageProcessor {

        std::shared_ptr<IMessageParser> MessageParserFactory::getMessageParser() {
            return nullptr;
        }
    }
}