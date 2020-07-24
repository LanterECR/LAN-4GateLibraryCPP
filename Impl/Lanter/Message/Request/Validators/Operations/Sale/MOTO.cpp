#include "MOTO.h"


namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::MOTO::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);
            }
        }
    }
}
