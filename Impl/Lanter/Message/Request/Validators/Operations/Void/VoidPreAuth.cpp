#include "VoidPreAuth.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void VoidPreAuth::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::TransactionID);

                appendOptionalField(RequestFields::CardDataEnc);
            }
        }
    }
}
