#include "Refund.h"

namespace Lanter {
    namespace Request {
        void Refund::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::Amount);
            appendMandatoryField(RequestFields::CurrencyCode);
            appendMandatoryField(RequestFields::RRN);

            appendOptionalField(RequestFields::TransactionID);
        }
    }
}
