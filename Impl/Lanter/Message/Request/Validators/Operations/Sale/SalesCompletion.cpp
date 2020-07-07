#include "SalesCompletion.h"


namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::SalesCompletion::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::Amount);
                appendMandatoryField(RequestFields::CurrencyCode);

                appendOptionalField(RequestFields::TransactionID);
                appendOptionalField(RequestFields::AuthCode);
                appendOptionalField(RequestFields::RRN);
                appendOptionalField(RequestFields::CardDataEnc);
            }
        }
    }
}
