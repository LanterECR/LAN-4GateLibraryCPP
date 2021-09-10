#include "GetCurrentPrinter.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void GetCurrentPrinter::addSpecificFields() {
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}
