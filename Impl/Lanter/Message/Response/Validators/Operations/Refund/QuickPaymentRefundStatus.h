//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_QUICKPAYMENTREFUNDSTATUS_H
#define LAN_4GATELIBRARYCPP_QUICKPAYMENTREFUNDSTATUS_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class QuickPaymentRefundStatus : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }//Message
}//Lanter

#endif //LAN_4GATELIBRARYCPP_QUICKPAYMENTREFUNDSTATUS_H
