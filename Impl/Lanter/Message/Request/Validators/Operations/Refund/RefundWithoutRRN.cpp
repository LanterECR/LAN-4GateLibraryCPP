#include "RefundWithoutRRN.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void RefundWithoutRRN::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::Amount);
                appendMandatoryField(RequestFields::CurrencyCode);
            }
        }
    }
}
