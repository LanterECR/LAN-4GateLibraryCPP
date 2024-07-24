#include "CommunicationSettings.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void CommunicationSettings::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::OperationCode);
                appendMandatoryField(RequestField::AdditionalInfo);
            }
        }
    }
}