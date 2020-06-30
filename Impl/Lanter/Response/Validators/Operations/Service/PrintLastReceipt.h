//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_PRINTLASTRECEIPT_H
#define LAN_4GATELIBRARYCPP_PRINTLASTRECEIPT_H

#include "Lanter/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Response {
        class PrintLastReceipt : public BasicValidator{
        public:
            void addSpecificFields() override;
        };
    }//Response
}//Lanter
#endif //LAN_4GATELIBRARYCPP_PRINTLASTRECEIPT_H
