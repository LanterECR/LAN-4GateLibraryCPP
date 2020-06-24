#include "AliPay.h"

namespace Lanter {
    namespace Request {

        AliPay::AliPay() {
            AliPay::addSpecificFields();
        }

        void AliPay::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::Amount);
            appendMandatoryField(RequestFields::CurrencyCode);
        }
    }
}
