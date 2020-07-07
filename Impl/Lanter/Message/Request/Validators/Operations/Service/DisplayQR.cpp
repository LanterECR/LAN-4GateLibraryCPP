#include "DisplayQR.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void DisplayQR::addSpecificFields() {
                appendOptionalField(RequestFields::AdditionalInfo);
            }
        }
    }
}
