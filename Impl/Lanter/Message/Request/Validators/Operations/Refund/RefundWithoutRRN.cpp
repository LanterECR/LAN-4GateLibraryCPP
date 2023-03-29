#include "RefundWithoutRRN.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void RefundWithoutRRN::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::CurrencyCode);

                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
