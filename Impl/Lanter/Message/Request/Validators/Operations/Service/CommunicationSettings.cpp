#include "CommunicationSettings.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void CommunicationSettings::addSpecificFields()
            {
                appendMandatoryField(RequestField::AdditionalInfo);
            }
        }
    }
}