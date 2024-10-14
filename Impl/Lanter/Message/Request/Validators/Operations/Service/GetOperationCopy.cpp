#include "GetOperationCopy.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void GetOperationCopy::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::ReceiptReference);
            }
        }
    }
}
