#include "QuickPayment.h"


namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::QuickPayment::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::Amount);
                appendMandatoryField(RequestFields::CurrencyCode);
            }
        }
    }
}
