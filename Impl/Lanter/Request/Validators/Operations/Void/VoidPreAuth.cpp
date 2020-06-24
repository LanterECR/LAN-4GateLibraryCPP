#include "VoidPreAuth.h"

namespace Lanter {
    namespace Request {

        VoidPreAuth::VoidPreAuth() {
            VoidPreAuth::addSpecificFields();
        }

        void VoidPreAuth::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::TransactionID);

            appendOptionalField(RequestFields::CardDataEnc);
        }
    }
}
