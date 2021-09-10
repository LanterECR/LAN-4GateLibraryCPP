#ifndef LAN_4GATELIBRARYCPP_REFUNDWITHOUTRRN_H
#define LAN_4GATELIBRARYCPP_REFUNDWITHOUTRRN_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class RefundWithoutRRN : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_REFUNDWITHOUTRRN_H
