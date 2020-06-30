#include "GetOperationCopy.h"

namespace Lanter {
    namespace Response {
        void GetOperationCopy::addSpecificFields() {
            appendMandatoryField(ResponseFields::EcrMerchantNumber);
            appendMandatoryField(ResponseFields::ReceiptReference);
        }
    }
}
