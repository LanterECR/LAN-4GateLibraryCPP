#include "UploadPending.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void UploadPending::addSpecificFields() {
                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::ReceiptReference);
            }
        }
    }
}
