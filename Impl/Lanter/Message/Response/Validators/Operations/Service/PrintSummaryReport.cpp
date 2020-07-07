#include "PrintSummaryReport.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void PrintSummaryReport::addSpecificFields() {
                appendOptionalField(ResponseFields::TotalAmount);
                appendOptionalField(ResponseFields::CurrencyCode);
                appendOptionalField(ResponseFields::TerminalID);
                appendOptionalField(ResponseFields::MerchantID);
                appendOptionalField(ResponseFields::TerminalDateTime);
                appendOptionalField(ResponseFields::SalesCount);
                appendOptionalField(ResponseFields::VoidCount);
                appendOptionalField(ResponseFields::RefundCount);
            }
        }
    }
}
