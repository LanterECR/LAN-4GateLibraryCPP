#ifndef LAN_4GATELIBRARYCPP_ARRAYELEMENT_H
#define LAN_4GATELIBRARYCPP_ARRAYELEMENT_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class ArrayElement : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_ARRAYELEMENT_H
