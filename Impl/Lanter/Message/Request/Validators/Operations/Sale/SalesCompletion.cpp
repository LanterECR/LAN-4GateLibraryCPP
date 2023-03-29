#include "SalesCompletion.h"


namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::SalesCompletion::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);

                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::AuthCode);
                appendOptionalField(RequestField::RRN);
                appendOptionalField(RequestField::CardDataEnc);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
