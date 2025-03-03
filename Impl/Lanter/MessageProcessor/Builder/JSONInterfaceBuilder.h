#ifndef LAN_4GATELIBRARYCPP_JSONInterfaceBUILDER_H
#define LAN_4GATELIBRARYCPP_JSONInterfaceBUILDER_H

#include "Lanter/Message/Interface/IInterfaceData.h"
#include "json/json.h"

namespace Lanter
{
    using namespace Message;
    using namespace Message::Interface;

    namespace MessageProcessor
    {
        namespace Builder
        {
            class JSONInterfaceBuilder
            {
            public:
                bool createObject(const IInterfaceData &uiData, Json::Value &object);
                static bool addCode(const IInterfaceData& uiData, Json::Value &object);
                static bool addTitle(const IInterfaceData& uiData, Json::Value& object);
                static bool addValue(const IInterfaceData& uiData, Json::Value& object);
                static bool addInfoText(const IInterfaceData& uiData, Json::Value& object);
                static bool addMinLen(const IInterfaceData& uiData, Json::Value& object);
                static bool addMaxLen(const IInterfaceData& uiData, Json::Value& object);
                static bool addResult(const IInterfaceData& uiData, Json::Value& object);
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_JSONInterfaceBUILDER_H