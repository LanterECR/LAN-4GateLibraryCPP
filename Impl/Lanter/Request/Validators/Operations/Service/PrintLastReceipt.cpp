#include "PrintLastReceipt.h"

namespace Lanter {
    namespace Request {
        void PrintLastReceipt::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
        }
    }
}
