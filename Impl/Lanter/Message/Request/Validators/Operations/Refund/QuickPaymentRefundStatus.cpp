#include "QuickPaymentRefundStatus.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void QuickPaymentRefundStatus::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::RRN);
                appendOptionalField(RequestField::AuthCode);
                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::ReceiptReference);
                appendOptionalField(RequestField::PaymentPurpose);
                appendOptionalField(RequestField::SBP_RN);
                appendOptionalField(RequestField::SBP_ReqID);
            }
        }
    }
}