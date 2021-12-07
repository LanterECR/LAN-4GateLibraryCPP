#ifndef LAN_4GATELIB_JSONINTERACTIONPARSER_H
#define LAN_4GATELIB_JSONINTERACTIONPARSER_H

#include <memory>

#include "json/json.h"

#include "Lanter/Message/Interaction/IInteractionData.h"

namespace Lanter {
    namespace MessageProcessor {
        using namespace Message;
        using namespace Message::Interaction;

        namespace Parser {
            class JSONInteractionParser {
            public:
                std::shared_ptr<IInteractionData> parseData(const Json::Value &object);
            private:
                bool getCode(const Json::Value &object, IInteractionData &data);
            };
        }
    }
}

#endif //LAN_4GATELIB_JSONINTERACTIONPARSER_H
