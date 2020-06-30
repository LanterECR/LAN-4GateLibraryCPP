#include "AliPay.h"

namespace Lanter {
    namespace Response {
        void AliPay::addSpecificFields() {
            appendOptionalField(ResponseFields::EcrMerchantNumber);
            appendOptionalField(ResponseFields::TotalAmount);
            appendOptionalField(ResponseFields::AmountAcquirerFee);
            appendOptionalField(ResponseFields::AmountTerminalFee);
            appendOptionalField(ResponseFields::CurrencyCode);
            appendOptionalField(ResponseFields::RRN);
            appendOptionalField(ResponseFields::ReceiptReference);
            appendOptionalField(ResponseFields::TransactionID);
            appendOptionalField(ResponseFields::AuthCode);
            appendOptionalField(ResponseFields::ResponseCode);
            appendOptionalField(ResponseFields::ResponseText);
            appendOptionalField(ResponseFields::TerminalID);
            appendOptionalField(ResponseFields::MerchantID);
            appendOptionalField(ResponseFields::TransDateTime);
            appendOptionalField(ResponseFields::TerminalDateTime);
        }
    }
}
