#include "UploadDelayed.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void UploadDelayed::addSpecificFields()
            {
                appendOptionalField(ResponseField::EcrMerchantNumber);
                appendOptionalField(ResponseField::EcrNumber);
                appendOptionalField(ResponseField::Status);
            }
        }
    }
}
