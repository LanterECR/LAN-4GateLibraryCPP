#ifndef LAN_4GATELIBRARYCPP_RESPONSE_ECertRefund_H
#define LAN_4GATELIBRARYCPP_RESPONSE_ECertRefund_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class ECertRefund : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_RESPONSE_ECertRefund_H
