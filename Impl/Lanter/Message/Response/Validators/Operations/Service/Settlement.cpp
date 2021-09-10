#include "Settlement.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void Response::Settlement::addSpecificFields() {
                appendOptionalField(ResponseField::EcrMerchantNumber);
                appendOptionalField(ResponseField::TotalAmount);
                appendOptionalField(ResponseField::CurrencyCode);
                appendOptionalField(ResponseField::TerminalID);
                appendOptionalField(ResponseField::MerchantID);
                appendOptionalField(ResponseField::TerminalDateTime);
                appendOptionalField(ResponseField::SaleCount);
                appendOptionalField(ResponseField::VoidCount);
                appendOptionalField(ResponseField::RefundCount);
                appendOptionalField(ResponseField::SaleArray);
                appendOptionalField(ResponseField::VoidArray);
                appendOptionalField(ResponseField::RefundArray);
            }
        }
    }
}
