#ifndef LAN_4GATELIBRARYCPP_NotificationCS_H
#define LAN_4GATELIBRARYCPP_NotificationCS_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            class NotificationCS : public BasicValidator
            {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_NotificationCS_H