#ifndef LAN_4GATELIBRARYCPP_FASTTRACK_H
#define LAN_4GATELIBRARYCPP_FASTTRACK_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            class FastTrack : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_FASTTRACK_H
