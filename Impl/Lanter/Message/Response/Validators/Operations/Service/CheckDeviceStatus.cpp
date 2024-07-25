#include "CheckDeviceStatus.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void CheckDeviceStatus::addSpecificFields()
            {
                appendOptionalField(ResponseField::EcrNumber);
                appendOptionalField(ResponseField::OperationCode);
                appendOptionalField(ResponseField::Status);
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}