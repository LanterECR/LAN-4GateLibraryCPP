#include "Sale.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::Sale::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::Amount);
                appendMandatoryField(RequestFields::CurrencyCode);
            }
        }
    }
}
