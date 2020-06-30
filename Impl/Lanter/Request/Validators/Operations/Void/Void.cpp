#include "Void.h"

namespace Lanter {
    namespace Request {
        void Request::Void::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::ReceiptReference);
        }
    }
}
