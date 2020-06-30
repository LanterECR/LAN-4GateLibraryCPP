//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_SETCURRENTPRINTER_H
#define LAN_4GATELIBRARYCPP_SETCURRENTPRINTER_H

#include "Lanter/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Response {
        class SetCurrentPrinter : public BasicValidator{
        public:
            void addSpecificFields() override;
        };
    }//Response
}//Lanter

#endif //LAN_4GATELIBRARYCPP_SETCURRENTPRINTER_H
