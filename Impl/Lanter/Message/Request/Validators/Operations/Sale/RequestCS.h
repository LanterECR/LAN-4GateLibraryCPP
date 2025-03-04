#ifndef LAN_4GATELIBRARYCPP_REQUESTCS_H
#define LAN_4GATELIBRARYCPP_REQUESTCS_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            class RequestCS : public BasicValidator
            {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_REQUESTCS_H