#include "CheckDeviceStatus.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void CheckDeviceStatus::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::OperationCode);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}