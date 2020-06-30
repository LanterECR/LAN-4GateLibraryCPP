#include "PrintCommsInfo.h"

namespace Lanter {
    namespace Response {
        void PrintCommsInfo::addSpecificFields() {
            appendOptionalField(ResponseFields::AdditionalInfo);
        }
    }
}
