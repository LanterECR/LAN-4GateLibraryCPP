#ifndef LAN_4GATELIBRARYCPP_QUICKPAYMENT_H
#define LAN_4GATELIBRARYCPP_QUICKPAYMENT_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class QuickPayment : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_QUICKPAYMENT_H
