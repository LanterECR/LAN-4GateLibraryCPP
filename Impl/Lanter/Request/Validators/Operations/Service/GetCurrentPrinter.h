//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_GETCURRENTPRINTER_H
#define LAN_4GATELIBRARYCPP_GETCURRENTPRINTER_H

#include "Lanter/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Request {
        class GetCurrentPrinter : public BasicValidator{
        public:
            GetCurrentPrinter();
        protected:
            void addSpecificFields() override;
        };
    }//Request
}//Lanter
#endif //LAN_4GATELIBRARYCPP_GETCURRENTPRINTER_H
