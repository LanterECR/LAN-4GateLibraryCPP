#include "FastTrack.h"


namespace Lanter {
    namespace Request {

        FastTrack::FastTrack() {
            FastTrack::addSpecificFields();
        }

        void Request::FastTrack::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::Amount);
            appendMandatoryField(RequestFields::CurrencyCode);

            appendOptionalField(RequestFields::EncTags);
            appendOptionalField(RequestFields::OpenTags);
        }
    }
}
