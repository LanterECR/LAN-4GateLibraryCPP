#ifndef LAN_4GATELIB_JSONCLASSFIELDSVALUES_H
#define LAN_4GATELIB_JSONCLASSFIELDSVALUES_H

#include <string>

namespace Lanter
{
    namespace MessageProcessor
    {
        class JSONClassFieldValues
        {
        public:
            static inline std::string getRequestValue() { return "LANTER::Request"; }
            static inline std::string getResponseValue() { return "LANTER::Response";}
            static inline std::string getCommunicationValue() { return "Com"; }
            static inline std::string getNotificationValue() { return "LANTER::Notification";}
            static inline std::string getInteractionValue() { return "LANTER::Interaction";}
            static inline std::string getReceiptValue() { return "LANTER::Receipt"; }
        };
    }
}
#endif //LAN_4GATELIB_JSONCLASSFIELDSVALUES_H