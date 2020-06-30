#include "PrintDetailReport.h"

namespace Lanter {
    namespace Request {
        void PrintDetailReport::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
        }
    }
}
