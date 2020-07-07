#include "GetOperationCopy.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void GetOperationCopy::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::ReceiptReference);
            }
        }
    }
}
