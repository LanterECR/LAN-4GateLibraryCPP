#include "QuickPayment.h"


namespace Lanter {
    namespace Request {

        QuickPayment::QuickPayment() {
            QuickPayment::addSpecificFields();
        }

        void Request::QuickPayment::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::Amount);
            appendMandatoryField(RequestFields::CurrencyCode);
        }
    }
}
