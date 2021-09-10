#include "FastTrack.h"


namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::FastTrack::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::Amount);
                appendMandatoryField(RequestField::CurrencyCode);

                appendOptionalField(RequestField::EncTags);
                appendOptionalField(RequestField::OpenTags);
            }
        }
    }
}
