#ifndef LAN_4GATELIB_JSONINTERACTIONFIELDS_H
#define LAN_4GATELIB_JSONINTERACTIONFIELDS_H

#include <string>

namespace Lanter
{
    namespace MessageProcessor
    {
        class JSONInteractionFields
        {
        public:
            static inline std::string getCode() { return "Code"; }
        };
    }
}
#endif //LAN_4GATELIB_JSONINTERACTIONFIELDS_H