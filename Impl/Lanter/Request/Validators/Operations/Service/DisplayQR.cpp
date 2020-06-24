#include "DisplayQR.h"

namespace Lanter {
    namespace Request {

        DisplayQR::DisplayQR() {
            DisplayQR::addSpecificFields();
        }

        void DisplayQR::addSpecificFields() {
            appendOptionalField(RequestFields::AdditionalInfo);
        }
    }
}
