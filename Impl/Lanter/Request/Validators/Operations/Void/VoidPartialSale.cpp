#include "VoidPartialSale.h"

namespace Lanter {
    namespace Request {
        void VoidPartialSale::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::ReceiptReference);
            appendMandatoryField(RequestFields::PartialAmount);
            appendMandatoryField(RequestFields::CurrencyCode);
        }
    }
}
