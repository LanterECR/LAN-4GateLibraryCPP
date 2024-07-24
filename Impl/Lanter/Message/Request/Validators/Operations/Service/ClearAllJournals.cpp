#include "ClearAllJournals.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void ClearAllJournals::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::OperationCode);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}