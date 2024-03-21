#include "Lanter/Message/Interaction/InteractionDataFactory.h"
#include "Lanter/Message/Interaction/InteractionData.h"

namespace Lanter
{
    namespace Message
    {
        namespace Interaction
        {
            std::shared_ptr<IInteractionData> InteractionDataFactory::getInteractionData(InteractionCode code)
            {
                auto interaction = getInteractionData();
                if(interaction != nullptr)
                {
                    interaction->setCode(code);
                }
                return interaction;
            }

            std::shared_ptr<IInteractionData> InteractionDataFactory::getInteractionData()
            {
                return std::make_shared<InteractionData>();
            }
        }
    }
}