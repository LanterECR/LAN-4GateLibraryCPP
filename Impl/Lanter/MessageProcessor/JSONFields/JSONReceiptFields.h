#ifndef LAN_4GATELIB_JSONRECEIPTFIELDS_H
#define LAN_4GATELIB_JSONRECEIPTFIELDS_H

#include <string>

namespace Lanter
{
    namespace MessageProcessor
    {
        class JSONReceiptFields
        {
        public:
            static inline std::string getCode() { return "Code"; }
            static inline std::string getMessage() { return "Lines"; }
        };
    }
}
#endif //LAN_4GATELIB_JSONRECEIPTFIELDS_H