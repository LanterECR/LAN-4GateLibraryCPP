#ifndef LAN_4GATELIBRARYCPP_LICENSEACTIVATIONFILE_H
#define LAN_4GATELIBRARYCPP_LICENSEACTIVATIONFILE_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class LicenseActivationFile : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_LICENSEACTIVATIONFILE_H
