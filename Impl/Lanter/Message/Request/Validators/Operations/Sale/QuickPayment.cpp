#include "QuickPayment.h"


namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::QuickPayment::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);

                appendOptionalField(RequestField::PaymentPurpose);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
