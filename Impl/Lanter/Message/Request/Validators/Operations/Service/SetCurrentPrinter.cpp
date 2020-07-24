#include "SetCurrentPrinter.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void SetCurrentPrinter::addSpecificFields() {
                appendMandatoryField(RequestField::AdditionalInfo);
            }
        }
    }
}
