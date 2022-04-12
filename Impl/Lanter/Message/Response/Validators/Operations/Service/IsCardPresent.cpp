#include "IsCardPresent.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void IsCardPresent::addSpecificFields() {
                appendOptionalField(ResponseField::AdditionalInfo);
                appendOptionalField(ResponseField::CardPAN);
                appendOptionalField(ResponseField::ExpireDate);
            }
        }
    }
}
