#ifndef LAN_4GATELIB_JSONNOTIFICATIONFIELDS_H
#define LAN_4GATELIB_JSONNOTIFICATIONFIELDS_H

#include <string>

namespace Lanter
{
    namespace MessageProcessor
    {
        class JSONNotificationFields
        {
        public:
            static inline std::string getCode() { return "Code"; }
            static inline std::string getMessage() { return "Message"; }
            static inline std::string getAdditional() { return "Additional"; }
        };
    }
}
#endif //LAN_4GATELIB_JSONNOTIFICATIONFIELDS_H