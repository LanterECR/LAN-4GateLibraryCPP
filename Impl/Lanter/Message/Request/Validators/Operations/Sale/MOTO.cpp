#include "MOTO.h"


namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::MOTO::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::Amount);
                appendMandatoryField(RequestFields::CurrencyCode);
            }
        }
    }
}
