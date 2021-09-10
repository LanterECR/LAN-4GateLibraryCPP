#ifndef LAN_4GATELIBRARYCPP_GETLASTOPERATION_H
#define LAN_4GATELIBRARYCPP_GETLASTOPERATION_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            class GetLastOperation : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_GETLASTOPERATION_H
