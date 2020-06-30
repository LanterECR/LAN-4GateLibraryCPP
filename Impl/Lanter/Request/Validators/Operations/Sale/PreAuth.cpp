#include "PreAuth.h"


namespace Lanter {
    namespace Request {
        void Request::PreAuth::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::Amount);
            appendMandatoryField(RequestFields::CurrencyCode);
            appendMandatoryField(RequestFields::TransactionID);

            appendOptionalField(RequestFields::CardDataEnc);
        }
    }
}
