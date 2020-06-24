//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_VOIDPREAUTH_H
#define LAN_4GATELIBRARYCPP_VOIDPREAUTH_H

#include "Lanter/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Request {
        class VoidPreAuth : public BasicValidator{
        public:
            VoidPreAuth();
        protected:
            void addSpecificFields() override;
        };
    }//Request
}//Lanter

#endif //LAN_4GATELIBRARYCPP_VOIDPREAUTH_H
