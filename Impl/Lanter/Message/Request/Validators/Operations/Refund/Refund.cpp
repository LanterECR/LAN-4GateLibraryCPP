#include "Refund.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Refund::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);

                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::RRN);
                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::AdditionalInfo);
                //appendOptionalField(RequestField::QRCodeScan);
            }
        }
    }
}
