#include "PrintLastReceipt.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void PrintLastReceipt::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
            }
        }
    }
}
