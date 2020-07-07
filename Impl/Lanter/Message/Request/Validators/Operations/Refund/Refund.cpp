#include "Refund.h"

namespace Lanter {
    namespace Message {
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
}
