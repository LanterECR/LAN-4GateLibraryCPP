#ifndef LAN_4GATELIBRARYCPP_JSONRECEIPTPARSER_H
#define LAN_4GATELIBRARYCPP_JSONRECEIPTPARSER_H

#include <memory>
#include "json/json.h"
#include "Lanter/Message/Receipt/IReceiptData.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            using namespace Message;
            using namespace Message::Receipt;

            class JSONReceiptParser
            {
            public:
                std::shared_ptr<IReceiptData> parseData(const Json::Value& object);
                bool getCode(const Json::Value& object, IReceiptData& data);
                bool getMessage(const Json::Value& object, IReceiptData& data);
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_JSONRECEIPTPARSER_H