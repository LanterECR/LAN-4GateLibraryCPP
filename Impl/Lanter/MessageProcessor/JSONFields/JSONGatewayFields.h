#ifndef LAN_4GATELIB_JSONGATEWAYFIELDS_H
#define LAN_4GATELIB_JSONGATEWAYFIELDS_H

#include <string>

namespace Lanter
{
    namespace MessageProcessor
    {
        class JSONGatewayFields
        {
        public:
            static inline std::string getCode() { return "Cmd"; }
            static inline std::string getIP() { return "IP"; }
            static inline std::string getPort() { return "Port"; }
            static inline std::string getLink() { return "Link"; }
            static inline std::string getStatus() { return "Status"; }
            static inline std::string getData() { return "Dt"; }
        };
    }
}
#endif //LAN_4GATELIB_JSONGATEWAYFIELDS_H