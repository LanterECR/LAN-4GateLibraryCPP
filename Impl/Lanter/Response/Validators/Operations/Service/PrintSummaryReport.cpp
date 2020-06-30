#include "PrintSummaryReport.h"

namespace Lanter {
    namespace Response {
        void PrintSummaryReport::addSpecificFields() {
            appendMandatoryField(ResponseFields::EcrMerchantNumber);
        }
    }
}
