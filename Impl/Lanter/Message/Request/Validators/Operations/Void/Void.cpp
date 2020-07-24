#include "Void.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::Void::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::ReceiptReference);
            }
        }
    }
}
