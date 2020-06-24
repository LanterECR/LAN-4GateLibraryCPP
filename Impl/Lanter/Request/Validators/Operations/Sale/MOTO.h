//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_MOTO_H
#define LAN_4GATELIBRARYCPP_MOTO_H

#include "Lanter/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Request {
        class MOTO : public BasicValidator{
        public:
            MOTO();
        protected:
            void addSpecificFields() override;
        };
    }//Request
}//Lanter
#endif //LAN_4GATELIBRARYCPP_MOTO_H
