#include "RequestCS.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void Request::RequestCS::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}