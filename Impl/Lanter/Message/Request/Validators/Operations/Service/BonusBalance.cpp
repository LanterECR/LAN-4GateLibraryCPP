#include "BonusBalance.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void BonusBalance::addSpecificFields()
            {

                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::AdditionalChoice);

                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}