//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_SETCURRENTPRINTER_H
#define LAN_4GATELIBRARYCPP_SETCURRENTPRINTER_H

#include "Lanter/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Request {
        class SetCurrentPrinter : public BasicValidator{
        public:
            void addSpecificFields() override;
        };
    }//Request
}//Lanter

#endif //LAN_4GATELIBRARYCPP_SETCURRENTPRINTER_H
