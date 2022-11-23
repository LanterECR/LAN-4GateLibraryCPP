#include "ECertRefund.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::ECertRefund::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);

				appendMandatoryField(RequestField::CurrencyCode);
				appendMandatoryField(RequestField::Amount);
				appendMandatoryField(RequestField::ECertAmount);
				appendMandatoryField(RequestField::BasketID);

				appendOptionalField(RequestField::TransactionID);
				appendOptionalField(RequestField::RRN);
			}
        }
    }
}
