#include "ECertPayment.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::ECertPayment::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);

				appendMandatoryField(RequestField::CardPANHash);
				appendMandatoryField(RequestField::Amount);
				appendMandatoryField(RequestField::ECertAmount);
				appendMandatoryField(RequestField::CurrencyCode);
				appendMandatoryField(RequestField::BasketID);
			}
        }
    }
}
