#include "VoidPartialSale.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void VoidPartialSale::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);
                appendMandatoryField(RequestField::ReceiptReference);
                appendMandatoryField(RequestField::PartialAmount);
                appendMandatoryField(RequestField::CurrencyCode);

                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}
