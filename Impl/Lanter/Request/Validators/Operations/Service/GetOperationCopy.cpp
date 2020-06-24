#include "GetOperationCopy.h"

namespace Lanter {
    namespace Request {

        GetOperationCopy::GetOperationCopy() {
            GetOperationCopy::addSpecificFields();
        }

        void GetOperationCopy::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::ReceiptReference);
        }
    }
}
