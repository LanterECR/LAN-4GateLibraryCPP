#include "MOTO.h"


namespace Lanter {
    namespace Request {

        MOTO::MOTO() {
            MOTO::addSpecificFields();
        }

        void Request::MOTO::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::Amount);
            appendMandatoryField(RequestFields::CurrencyCode);
        }
    }
}
