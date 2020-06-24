//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_SALESCOMPLETION_H
#define LAN_4GATELIBRARYCPP_SALESCOMPLETION_H

#include "Lanter/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Request {
        class SalesCompletion : public BasicValidator{
        public:
            SalesCompletion();
        protected:
            void addSpecificFields() override;
        };
    }//Request
}//Lanter
#endif //LAN_4GATELIBRARYCPP_SALESCOMPLETION_H
