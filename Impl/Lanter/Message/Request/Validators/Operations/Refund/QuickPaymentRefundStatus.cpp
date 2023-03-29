#include "QuickPaymentRefundStatus.h"

namespace Lanter {
    namespace Message {
        namespace Request {

            void QuickPaymentRefundStatus::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);

                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::RRN);
                appendOptionalField(RequestField::AuthCode);
                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::ReceiptReference);
            }
        }
    }
}