#include "PrintSummaryReport.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void PrintSummaryReport::addSpecificFields() {
                appendOptionalField(ResponseField::TotalAmount);
                appendOptionalField(ResponseField::CurrencyCode);
                appendOptionalField(ResponseField::TerminalID);
                appendOptionalField(ResponseField::MerchantID);
                appendOptionalField(ResponseField::TerminalDateTime);
                appendOptionalField(ResponseField::SaleCount);
                appendOptionalField(ResponseField::VoidCount);
                appendOptionalField(ResponseField::RefundCount);
            }
        }
    }
}
