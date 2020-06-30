#include "GetOperationCopy.h"

namespace Lanter {
    namespace Request {
        void GetOperationCopy::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::ReceiptReference);
        }
    }
}
