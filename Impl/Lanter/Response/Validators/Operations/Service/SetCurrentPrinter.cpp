#include "SetCurrentPrinter.h"

namespace Lanter {
    namespace Response {
        void SetCurrentPrinter::addSpecificFields() {
            appendMandatoryField(ResponseFields::AdditionalInfo);
        }
    }
}
