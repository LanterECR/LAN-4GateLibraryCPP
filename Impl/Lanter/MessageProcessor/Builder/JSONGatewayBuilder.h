#ifndef LAN_4GATELIBRARYCPP_JSONGATEWAYBUILDER_H
#define LAN_4GATELIBRARYCPP_JSONGATEWAYBUILDER_H

#include "Lanter/Message/Gateway/IGatewayData.h"
#include "json/json.h"

namespace Lanter
{
    using namespace Message;
    using namespace Message::Gateway;

    namespace MessageProcessor
    {
        namespace Builder
        {
            class JSONGatewayBuilder
            {
            public:
                bool createObject(const IGatewayData &gatewaynData, Json::Value &object);
                static bool addCode(const IGatewayData& gatewaynData, Json::Value &object);
                static bool addIP(const IGatewayData& gatewaynData, Json::Value &object);
                static bool addPort(const IGatewayData& gatewaynData, Json::Value &object);
                static bool addLink(const IGatewayData& gatewaynData, Json::Value& object);
                static bool addStatus(const IGatewayData& gatewaynData, Json::Value& object);
                static bool addData(const IGatewayData& gatewaynData, Json::Value& object);
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_JSONGATEWAYBUILDER_H