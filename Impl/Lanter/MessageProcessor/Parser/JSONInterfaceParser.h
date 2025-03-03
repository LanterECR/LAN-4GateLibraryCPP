#ifndef LAN_4GATELIBRARYCPP_JSONINTERFACEPARSER_H
#define LAN_4GATELIBRARYCPP_JSONINTERFACEPARSER_H

#include <memory>
#include "json/json.h"
#include "Lanter/Message/Interface/IInterfaceData.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            using namespace Message;
            using namespace Message::Interface;

            class JSONInterfaceParser
            {
            public:
                std::shared_ptr<IInterfaceData> parseData(const Json::Value &object);
                bool getType(const Json::Value &object, IInterfaceData &data);
                bool getTitle(const Json::Value &object, IInterfaceData &data);
                bool getValue(const Json::Value &object, IInterfaceData &data);
                bool getInfoText(const Json::Value& object, IInterfaceData& data);
                bool getMinLen(const Json::Value& object, IInterfaceData& data);
                bool getMaxLen(const Json::Value& object, IInterfaceData& data);
                bool getResult(const Json::Value& object, IInterfaceData& data);
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_JSONINTERFACEPARSER_H