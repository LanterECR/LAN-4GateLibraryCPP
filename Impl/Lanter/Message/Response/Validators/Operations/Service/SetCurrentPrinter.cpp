#include "SetCurrentPrinter.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void SetCurrentPrinter::addSpecificFields() {
                appendOptionalField(ResponseFields::AdditionalInfo);
            }
        }
    }
}
