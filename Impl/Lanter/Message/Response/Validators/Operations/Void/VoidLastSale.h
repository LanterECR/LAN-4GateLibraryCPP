#ifndef LAN_4GATELIBRARYCPP_VOIDLASTSALE_H
#define LAN_4GATELIBRARYCPP_VOIDLASTSALE_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            class VoidLastSale : public BasicValidator
            {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }//Message
}//Lanter
#endif //LAN_4GATELIBRARYCPP_VOIDLASTSALE_H