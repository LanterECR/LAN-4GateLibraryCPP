#include "KeyDowload.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void KeyDownload::addSpecificFields()
            {
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}