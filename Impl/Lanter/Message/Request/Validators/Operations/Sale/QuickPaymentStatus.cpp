#include "QuickPaymentStatus.h"

namespace Lanter {
    namespace Message {
        namespace Request {

            void QuickPaymentStatus::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);

                appendOptionalField(RequestField::RRN);
                appendOptionalField(RequestField::AuthCode);
                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::ReceiptReference);
            }
        }
    }
}