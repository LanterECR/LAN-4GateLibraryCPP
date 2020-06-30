#include "GetCurrentPrinter.h"

namespace Lanter {
    namespace Response {
        void GetCurrentPrinter::addSpecificFields() {
            appendOptionalField(ResponseFields::AdditionalInfo);
        }
    }
}
