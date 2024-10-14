#include "ClearAllJournals.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void ClearAllJournals::addSpecificFields()
            {
                appendOptionalField(ResponseField::EcrNumber);
                appendOptionalField(ResponseField::OperationCode);
                appendOptionalField(ResponseField::Status);
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}