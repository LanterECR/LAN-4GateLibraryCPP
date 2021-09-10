#ifndef LAN_4GATELIBRARYCPP_SETCURRENTPRINTER_H
#define LAN_4GATELIBRARYCPP_SETCURRENTPRINTER_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            class SetCurrentPrinter : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_SETCURRENTPRINTER_H
