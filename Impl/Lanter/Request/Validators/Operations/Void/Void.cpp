#include "Void.h"

namespace Lanter {
    namespace Request {
        Void::Void() {
            Void::addSpecificFields();
        }

        void Request::Void::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::ReceiptReference);
        }
    }
}
