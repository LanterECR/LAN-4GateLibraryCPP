#include "PrintDetailReport.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void PrintDetailReport::addSpecificFields() {
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
