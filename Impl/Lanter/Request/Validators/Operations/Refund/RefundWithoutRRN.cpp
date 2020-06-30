#include "RefundWithoutRRN.h"

namespace Lanter {
    namespace Request {
        void RefundWithoutRRN::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::Amount);
            appendMandatoryField(RequestFields::CurrencyCode);
        }
    }
}
