#include "QuickPayment.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void Request::QuickPayment::addSpecificFields()
            {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);
                appendMandatoryField(RequestField::AdditionalInfo);
                appendMandatoryField(RequestField::PaymentPurpose);
            }
        }
    }
}