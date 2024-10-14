#include "Payment.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::Payment::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);
                
                appendOptionalField(RequestField::BonusBalance);
                appendOptionalField(RequestField::BonusAmount);
                appendOptionalField(RequestField::HashCardTrack2);
                appendOptionalField(RequestField::AdditionalInfo);
                appendOptionalField(RequestField::PaymentProviderCode);
                appendOptionalField(RequestField::PaymentParam1);
                appendOptionalField(RequestField::PaymentParam2);
                appendOptionalField(RequestField::PaymentParam3);

            }
        }
    }
}
