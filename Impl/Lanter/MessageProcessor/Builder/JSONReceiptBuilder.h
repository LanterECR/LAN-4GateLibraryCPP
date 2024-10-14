#ifndef LAN_4GATELIB_JSONRECEIPTBUILDER_H
#define LAN_4GATELIB_JSONRECEIPTBUILDER_H

#include "Lanter/Message/Receipt/IReceiptData.h"
#include "json/json.h"

namespace Lanter
{
    using namespace Message;
    using namespace Message::Receipt;

    namespace MessageProcessor
    {
        namespace Builder
        {
            class JSONReceiptBuilder
            {
            public:
                bool createObject(const IReceiptData& receiptData, Json::Value& object);
                static bool addCode(const IReceiptData& receiptData, Json::Value& object);
                static bool addMessage(const IReceiptData& receiptData, Json::Value& object);
            };
        }
    }
}
#endif //LAN_4GATELIB_JSONRECEIPTBUILDER_H