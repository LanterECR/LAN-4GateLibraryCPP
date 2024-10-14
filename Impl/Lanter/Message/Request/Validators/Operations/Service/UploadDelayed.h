#ifndef LAN_4GATELIBRARYCPP_UPLOADDELAYED_H
#define LAN_4GATELIBRARYCPP_UPLOADDELAYED_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            class UploadDelayed : public BasicValidator
            {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_UPLOADDELAYED_H