#ifndef LAN_4GATELIBRARYCPP_UPLOADDELAYED_H
#define LAN_4GATELIBRARYCPP_UPLOADDELAYED_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            class UploadDelayed : public BasicValidator
            {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_UPLOADDELAYED_H