#include "Sale.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::Sale::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);

                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::AdditionalChoice);
                appendOptionalField(RequestField::BonusBalance);
                appendOptionalField(RequestField::BonusAmount);
                appendOptionalField(RequestField::HashCardTrack2);
                //appendOptionalField(RequestField::QRCodeScan);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
