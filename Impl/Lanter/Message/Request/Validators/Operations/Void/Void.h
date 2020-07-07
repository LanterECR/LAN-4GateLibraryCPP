//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_VOID_H
#define LAN_4GATELIBRARYCPP_VOID_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            class Void : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }//Message
}//Lanter
#endif //LAN_4GATELIBRARYCPP_VOID_H
