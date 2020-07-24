#include "VoidPreAuth.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void VoidPreAuth::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::TransactionID);

                appendOptionalField(RequestField::CardDataEnc);
            }
        }
    }
}
