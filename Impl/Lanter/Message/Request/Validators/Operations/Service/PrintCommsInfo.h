#ifndef LAN_4GATELIBRARYCPP_PRINTCOMMSINFO_H
#define LAN_4GATELIBRARYCPP_PRINTCOMMSINFO_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            class PrintCommsInfo : public BasicValidator
            {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_PRINTCOMMSINFO_H