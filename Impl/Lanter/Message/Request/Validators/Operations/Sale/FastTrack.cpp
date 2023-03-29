#include "FastTrack.h"


namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::FastTrack::addSpecificFields() {
                appendMandatoryField(RequestField::OpenTags);

                appendOptionalField(RequestField::EncTags);
                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
