#include "PrintSummaryReport.h"

namespace Lanter {
    namespace Request {

        PrintSummaryReport::PrintSummaryReport() {
            PrintSummaryReport::addSpecificFields();
        }

        void PrintSummaryReport::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
        }
    }
}
