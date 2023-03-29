#include "ECertPayment.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::ECertPayment::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);

				appendOptionalField(RequestField::CardPANHash);
				appendOptionalField(RequestField::CurrencyCode);
				appendOptionalField(RequestField::Amount);
				appendOptionalField(RequestField::ECertAmount);
				appendOptionalField(RequestField::BasketID);
				appendOptionalField(RequestField::AdditionalInfo);
			}
        }
    }
}
