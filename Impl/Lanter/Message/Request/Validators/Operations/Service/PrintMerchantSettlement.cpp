#include "PrintMerchantSettlement.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void PrintMerchantSettlement::addSpecificFields()
            {
                appendMandatoryField(RequestField::EcrNumber);
                appendMandatoryField(RequestField::EcrMerchantNumber);

                appendOptionalField(RequestField::CurrencyCode);
            }
        }
    }
}