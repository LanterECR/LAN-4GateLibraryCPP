#include "RefundWithoutRRN.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void RefundWithoutRRN::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);

                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
