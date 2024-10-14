#include "PrintLastSettlement.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void Request::PrintLastSettlement::addSpecificFields()
            {
                appendMandatoryField(RequestField::EcrMerchantNumber);

                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
