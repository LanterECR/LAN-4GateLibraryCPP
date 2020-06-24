#include "RefundWithoutRRN.h"

namespace Lanter {
    namespace Request {

        RefundWithoutRRN::RefundWithoutRRN() {
            RefundWithoutRRN::addSpecificFields();
        }

        void RefundWithoutRRN::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::Amount);
            appendMandatoryField(RequestFields::CurrencyCode);
        }
    }
}
