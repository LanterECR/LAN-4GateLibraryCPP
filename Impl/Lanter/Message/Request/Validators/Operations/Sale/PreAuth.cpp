#include "PreAuth.h"


namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::PreAuth::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);
                appendMandatoryField(RequestField::TransactionID);

                appendOptionalField(RequestField::CardDataEnc);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
