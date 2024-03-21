#ifndef LAN_4GATELIB_JSONROOTFIELDS_H
#define LAN_4GATELIB_JSONROOTFIELDS_H

#include <string>

namespace Lanter
{
    namespace MessageProcessor
    {
        class JSONRootFields
        {
        public:
            static inline std::string getClassField() { return "__class"; }
            static inline std::string getObjectField() { return "__object"; }
        };
    }
}
#endif //LAN_4GATELIB_JSONROOTFIELDS_H