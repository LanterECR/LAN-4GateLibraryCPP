#include "AliPay.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void AliPay::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);
            }
        }
    }
}
