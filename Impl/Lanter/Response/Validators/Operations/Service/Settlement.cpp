#include "Settlement.h"

namespace Lanter {
    namespace Response {

        void Response::Settlement::addSpecificFields() {
            appendMandatoryField(ResponseFields::EcrMerchantNumber);
        }
    }
}
