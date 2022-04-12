#ifndef LAN_4GATELIBRARYCPP_SENDLOGS_H
#define LAN_4GATELIBRARYCPP_SENDLOGS_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            class SendLogs : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_SENDLOGS_H
