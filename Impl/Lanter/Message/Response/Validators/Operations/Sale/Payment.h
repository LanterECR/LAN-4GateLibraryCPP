#ifndef LAN_4GATELIBRARYCPP_PAYMENT_H
#define LAN_4GATELIBRARYCPP_PAYMENT_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class Payment : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_PAYMENT_H
