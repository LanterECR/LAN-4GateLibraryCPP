#include "RepeatLastN.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void Response::RepeatLastN::addSpecificFields()
            {
                appendOptionalField(ResponseField::Status);
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}