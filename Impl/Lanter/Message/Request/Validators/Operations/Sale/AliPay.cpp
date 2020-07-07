#include "AliPay.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void AliPay::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::Amount);
                appendMandatoryField(RequestFields::CurrencyCode);
            }
        }
    }
}
