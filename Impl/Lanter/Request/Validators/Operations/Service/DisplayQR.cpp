#include "DisplayQR.h"

namespace Lanter {
    namespace Request {
        void DisplayQR::addSpecificFields() {
            appendOptionalField(RequestFields::AdditionalInfo);
        }
    }
}
