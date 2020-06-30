#include "PrintSummaryReport.h"

namespace Lanter {
    namespace Request {
        void PrintSummaryReport::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
        }
    }
}
