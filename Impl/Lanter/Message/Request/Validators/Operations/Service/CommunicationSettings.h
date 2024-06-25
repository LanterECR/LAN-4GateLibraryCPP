#ifndef LAN_4GATELIBRARYCPP_COMMUNICATIONSETTINGS_H
#define LAN_4GATELIBRARYCPP_COMMUNICATIONSETTINGS_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            class CommunicationSettings : public BasicValidator
            {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_COMMUNICATIONSETTINGS_H