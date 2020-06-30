#include "VoidPreAuth.h"

namespace Lanter {
    namespace Request {
        void VoidPreAuth::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::TransactionID);

            appendOptionalField(RequestFields::CardDataEnc);
        }
    }
}
