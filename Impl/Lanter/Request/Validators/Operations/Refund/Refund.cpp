#include "Refund.h"

namespace Lanter {
    namespace Request {
        Refund::Refund() {
            Refund::addSpecificFields();
        }

        void Refund::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::Amount);
            appendMandatoryField(RequestFields::CurrencyCode);
            appendMandatoryField(RequestFields::RRN);

            appendOptionalField(RequestFields::TransactionID);
        }
    }
}
