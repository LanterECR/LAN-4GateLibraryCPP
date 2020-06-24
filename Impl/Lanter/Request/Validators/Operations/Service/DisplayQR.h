//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_DISPLAYQR_H
#define LAN_4GATELIBRARYCPP_DISPLAYQR_H

#include "Lanter/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Request {
        class DisplayQR : public BasicValidator{
        public:
            DisplayQR();
        protected:
            void addSpecificFields() override;
        };
    }//Request
}//Lanter

#endif //LAN_4GATELIBRARYCPP_DISPLAYQR_H
