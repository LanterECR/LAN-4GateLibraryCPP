#ifndef LAN_4GATELIBRARYCPP_GETOPERATIONCOPY_H
#define LAN_4GATELIBRARYCPP_GETOPERATIONCOPY_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class GetOperationCopy : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_GETOPERATIONCOPY_H
