#include "CommunicationSettings.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void CommunicationSettings::addSpecificFields()
            {
                appendOptionalField(ResponseField::EcrNumber);
                appendOptionalField(ResponseField::OperationCode);
                appendOptionalField(ResponseField::Status);
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}