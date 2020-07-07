//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_VOIDPARTIALSALE_H
#define LAN_4GATELIBRARYCPP_VOIDPARTIALSALE_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            class VoidPartialSale : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }//Message
}//Lanter

#endif //LAN_4GATELIBRARYCPP_VOIDPARTIALSALE_H
