#include "Settlement.h"

namespace Lanter {
    namespace Request {

        void Request::Settlement::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
        }
    }
}
