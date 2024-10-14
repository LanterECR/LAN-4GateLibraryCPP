#ifndef LAN_4GATELIBRARYCPP_VOID_H
#define LAN_4GATELIBRARYCPP_VOID_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            class Void : public BasicValidator
            {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }//Message
}//Lanter
#endif //LAN_4GATELIBRARYCPP_VOID_H