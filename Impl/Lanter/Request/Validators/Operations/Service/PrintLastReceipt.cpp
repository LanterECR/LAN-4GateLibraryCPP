#include "PrintLastReceipt.h"

namespace Lanter {
    namespace Request {

        PrintLastReceipt::PrintLastReceipt() {
            PrintLastReceipt::addSpecificFields();
        }

        void PrintLastReceipt::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
        }
    }
}
