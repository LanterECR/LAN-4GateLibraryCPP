#include "Sale.h"

namespace Lanter {
    namespace Request {

        Sale::Sale() {
            Sale::addSpecificFields();

        }

        void Request::Sale::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::Amount);
            appendMandatoryField(RequestFields::CurrencyCode);
        }
    }
}
