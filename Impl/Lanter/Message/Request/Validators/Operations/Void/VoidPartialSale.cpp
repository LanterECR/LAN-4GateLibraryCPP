#include "VoidPartialSale.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void VoidPartialSale::addSpecificFields()
            {
                appendMandatoryField(RequestField::EcrMerchantNumber);

                appendOptionalField(RequestField::ReceiptReference);
                appendOptionalField(RequestField::PartialAmount);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}