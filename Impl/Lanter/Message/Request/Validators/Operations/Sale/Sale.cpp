#include "Sale.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void Request::Sale::addSpecificFields()
            {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);

                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}