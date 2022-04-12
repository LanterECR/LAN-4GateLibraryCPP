#ifndef LAN_4GATELIBRARYCPP_ISCARDPRESENT_H
#define LAN_4GATELIBRARYCPP_ISCARDPRESENT_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class IsCardPresent : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_ISCARDPRESENT_H
