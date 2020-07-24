#include "PrintCommsInfo.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void PrintCommsInfo::addSpecificFields() {
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}
