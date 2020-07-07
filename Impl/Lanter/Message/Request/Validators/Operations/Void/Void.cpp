#include "Void.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::Void::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::ReceiptReference);
            }
        }
    }
}
