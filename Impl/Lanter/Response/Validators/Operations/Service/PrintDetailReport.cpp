#include "PrintDetailReport.h"

namespace Lanter {
    namespace Response {
        void PrintDetailReport::addSpecificFields() {
            appendMandatoryField(ResponseFields::EcrMerchantNumber);
        }
    }
}
