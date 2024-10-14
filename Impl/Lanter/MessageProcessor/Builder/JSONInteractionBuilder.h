#ifndef LAN_4GATELIB_JSONINTERACTIONBUILDER_H
#define LAN_4GATELIB_JSONINTERACTIONBUILDER_H

#include "Lanter/Message/Interaction/IInteractionData.h"
#include "json/json.h"

namespace Lanter
{
    using namespace Message;
    using namespace Message::Interaction;

    namespace MessageProcessor
    {
        namespace Builder
        {
            class JSONInteractionBuilder
            {
            public:
                bool createObject(const IInteractionData& interactionData, Json::Value& object);
                static bool addCode(const IInteractionData& interactionData, Json::Value& object);
            };
        }
    }
}
#endif //LAN_4GATELIB_JSONINTERACTIONBUILDER_H