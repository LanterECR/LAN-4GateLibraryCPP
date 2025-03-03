#ifndef LAN_4GATELIB_JSONInterfaceFIELDS_H
#define LAN_4GATELIB_JSONInterfaceFIELDS_H

#include <string>

namespace Lanter
{
    namespace MessageProcessor
    {
        class JSONInterfaceFields
        {
        public:
            static inline std::string getType()     { return "TypeUI"; }
            static inline std::string getTitle()    { return "Title"; }
            static inline std::string getValue()    { return "Value"; }
            static inline std::string getInfoText() { return "InfoText"; }
            static inline std::string getMinLen()   { return "MinLen"; }
            static inline std::string getMaxLen()   { return "MaxLen"; }
            static inline std::string getResult()   { return "Result"; }
        };
    }
}
#endif //LAN_4GATELIB_JSONInterfaceFIELDS_H