#include "VoidPartialSale.h"

namespace Lanter {
    namespace Request {

        VoidPartialSale::VoidPartialSale() {
            VoidPartialSale::addSpecificFields();
        }

        void VoidPartialSale::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);
            appendMandatoryField(RequestFields::ReceiptReference);
            appendMandatoryField(RequestFields::PartialAmount);
            appendMandatoryField(RequestFields::CurrencyCode);
        }
    }
}
