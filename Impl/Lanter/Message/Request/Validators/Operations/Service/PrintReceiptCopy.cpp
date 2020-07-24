#include "PrintReceiptCopy.h"

namespace Lanter {
    namespace Message {
        namespace Request {

            void PrintReceiptCopy::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::ReceiptReference);
            }
        }
    }
}