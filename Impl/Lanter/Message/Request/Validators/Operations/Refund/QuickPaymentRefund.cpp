#include "QuickPaymentRefund.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void QuickPaymentRefund::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);

                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::RRN);
                appendOptionalField(RequestField::AuthCode);
                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::ReceiptReference);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
