#include "ECertRefund.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::ECertRefund::addSpecificFields() {
                appendMandatoryField(RequestField::EcrMerchantNumber);

				appendOptionalField(RequestField::CurrencyCode);
				appendOptionalField(RequestField::Amount);
				appendOptionalField(RequestField::ECertAmount);
				appendOptionalField(RequestField::BasketID);
				appendOptionalField(RequestField::TransactionID);
				appendOptionalField(RequestField::RRN);
				appendOptionalField(RequestField::AdditionalInfo);
			}
        }
    }
}
