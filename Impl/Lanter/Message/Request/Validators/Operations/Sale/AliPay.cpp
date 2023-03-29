#include "AliPay.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void AliPay::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);

                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
