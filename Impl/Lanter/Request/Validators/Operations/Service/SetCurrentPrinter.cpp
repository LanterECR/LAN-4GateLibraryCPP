#include "SetCurrentPrinter.h"

namespace Lanter {
    namespace Request {
        void SetCurrentPrinter::addSpecificFields() {
            appendMandatoryField(RequestFields::AdditionalInfo);
        }
    }
}
