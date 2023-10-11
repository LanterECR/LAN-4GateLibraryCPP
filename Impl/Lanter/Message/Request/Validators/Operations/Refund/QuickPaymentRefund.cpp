#include "QuickPaymentRefund.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void QuickPaymentRefund::addSpecificFields()
            {
                appendOptionalField(RequestField::RRN);
                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::SBP_RN);
                appendOptionalField(RequestField::SBP_ReqID);
            }
        }
    }
}