#include "Lanter/MessageProcessor/Parser/MessageParserFactory.h"
#include "Lanter/MessageProcessor/Parser/JSONMessageParser.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            std::shared_ptr<IMessageParser> MessageParserFactory::getMessageParser()
            {
                return std::make_shared<JSONMessageParser>();
            }//getMessageParser()
        }//namespace Parser
    }//namespace MessageProcessor
}//namespace Lanter