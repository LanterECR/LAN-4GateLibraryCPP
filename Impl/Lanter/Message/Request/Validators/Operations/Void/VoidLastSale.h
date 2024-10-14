#ifndef LAN_4GATELIBRARYCPP_VOIDLASTSALE_H
#define LAN_4GATELIBRARYCPP_VOIDLASTSALE_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            class VoidLastSale : public BasicValidator
            {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }//Message
}//Lanter
#endif //LAN_4GATELIBRARYCPP_VOIDLASTSALE_H