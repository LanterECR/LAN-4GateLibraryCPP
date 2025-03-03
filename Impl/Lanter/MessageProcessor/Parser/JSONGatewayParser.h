#ifndef LAN_4GATELIBRARYCPP_JSONGATEWAYPARSER_H
#define LAN_4GATELIBRARYCPP_JSONGATEWAYPARSER_H

#include <memory>
#include "json/json.h"
#include "Lanter/Message/Gateway/IGatewayData.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            using namespace Message;
            using namespace Message::Gateway;

            class JSONGatewayParser
            {
            public:
                std::shared_ptr<IGatewayData> parseData(const Json::Value &object);
                bool getCode(const Json::Value &object, IGatewayData &data);
                bool getIP(const Json::Value& object, IGatewayData& data);
                bool getPort(const Json::Value& object, IGatewayData& data);
                bool getLink(const Json::Value& object, IGatewayData& data);
                bool getStatus(const Json::Value& object, IGatewayData& data);
                bool getData(const Json::Value& object, IGatewayData& data);
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_JSONGATEWAYPARSER_H