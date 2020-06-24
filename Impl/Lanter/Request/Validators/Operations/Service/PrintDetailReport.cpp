#include "PrintDetailReport.h"

namespace Lanter {
    namespace Request {

        PrintDetailReport::PrintDetailReport() {
            PrintDetailReport::addSpecificFields();
        }

        void PrintDetailReport::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
        }
    }
}
