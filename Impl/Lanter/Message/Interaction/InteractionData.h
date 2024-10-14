#ifndef LAN_4GATELIB_INTERACTIONDATA_H
#define LAN_4GATELIB_INTERACTIONDATA_H

#include "Lanter/Message/Interaction/IInteractionData.h"

namespace Lanter
{
    namespace Message
    {
        namespace Interaction
        {
            class InteractionData : public IInteractionData
            {
            public:
                InteractionCode getCode() const override;
                bool setCode(InteractionCode code) override;
                bool resetCode() override;

            private:
                InteractionCode m_Code = InteractionCode::NoInteraction;
            };
        }
    }
}
#endif //LAN_4GATELIB_INTERACTIONDATA_H