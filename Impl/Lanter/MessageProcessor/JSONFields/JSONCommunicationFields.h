#ifndef LAN_4GATELIB_JSONCOMMUNICATIONFIELDS_H
#define LAN_4GATELIB_JSONCOMMUNICATIONFIELDS_H

#include <string>

namespace Lanter
{
    namespace MessageProcessor
    {
        class JSONCommunicationFields
        {
        public:
            static inline std::string getCommand() { return "Cmd"; }
            static inline std::string getLink() { return "Lnk"; }
            static inline std::string getData() { return "Dt"; }
            static inline std::string getIp() { return "IP"; }
            static inline std::string getPort() { return "Port"; }
        };
    }
}
#endif //LAN_4GATELIB_JSONCOMMUNICATIONFIELDS_H