#include "RepeatLastN.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void Request::RepeatLastN::addSpecificFields()
            {
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}