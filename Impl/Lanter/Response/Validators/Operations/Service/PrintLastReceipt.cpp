#include "PrintLastReceipt.h"

namespace Lanter {
    namespace Response {
        void PrintLastReceipt::addSpecificFields() {
            appendMandatoryField(ResponseFields::EcrMerchantNumber);
        }
    }
}
