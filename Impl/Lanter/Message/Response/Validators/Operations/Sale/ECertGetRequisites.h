#ifndef LAN_4GATELIBRARYCPP_RESPONSE_ECertGetRequisites_H
#define LAN_4GATELIBRARYCPP_RESPONSE_ECertGetRequisites_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class ECertGetRequisites : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_RESPONSE_ECertGetRequisites_H
