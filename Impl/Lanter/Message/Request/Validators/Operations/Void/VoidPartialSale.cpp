#include "VoidPartialSale.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void VoidPartialSale::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::ReceiptReference);
                appendMandatoryField(RequestFields::PartialAmount);
                appendMandatoryField(RequestFields::CurrencyCode);
            }
        }
    }
}
