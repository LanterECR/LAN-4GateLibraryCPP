#include "Settlement.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void Response::Settlement::addSpecificFields() {
                appendOptionalField(ResponseFields::EcrMerchantNumber);
                appendOptionalField(ResponseFields::TotalAmount);
                appendOptionalField(ResponseFields::CurrencyCode);
                appendOptionalField(ResponseFields::TerminalID);
                appendOptionalField(ResponseFields::MerchantID);
                appendOptionalField(ResponseFields::TerminalDateTime);
                appendOptionalField(ResponseFields::SalesCount);
                appendOptionalField(ResponseFields::VoidCount);
                appendOptionalField(ResponseFields::RefundCount);
                appendOptionalField(ResponseFields::SalesArray);
                appendOptionalField(ResponseFields::VoidArray);
                appendOptionalField(ResponseFields::RefundArray);
            }
        }
    }
}
