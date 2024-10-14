#include "Lanter/MessageProcessor/Builder/MessageBuilderFactory.h"
#include "Lanter/MessageProcessor/Builder/JSONMessageBuilder.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Builder
        {
            std::shared_ptr<IMessageBuilder> MessageBuilderFactory::getMessageBuilder()
            {
                return std::make_shared<JSONMessageBuilder>();
            }//getMessageBuilder
        }//namespace Builder
    }//namespace MessageProcessor
}//namespace Lanter