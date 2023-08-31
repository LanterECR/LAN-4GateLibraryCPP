#include "PrintMerchantSettlement.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void PrintMerchantSettlement::addSpecificFields()
            {
                appendOptionalField(ResponseField::EcrNumber);
                appendOptionalField(ResponseField::EcrMerchantNumber);
                appendOptionalField(ResponseField::CurrencyCode);
            }
        }
    }
}