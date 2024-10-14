#include "UploadDelayed.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void UploadDelayed::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::OperationCode);
            }
        }
    }
}