#include "Refund.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Refund::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);
                appendMandatoryField(RequestField::RRN);

                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
