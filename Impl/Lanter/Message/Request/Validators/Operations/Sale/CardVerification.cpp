#include "CardVerification.h"

namespace Lanter
{
    namespace Message
	{
        namespace Request
		{
            void Request::CardVerification::addSpecificFields()
			{
				appendOptionalField(RequestField::EcrMerchantNumber);
				appendOptionalField(RequestField::EcrNumber);
				appendOptionalField(RequestField::OperationCode);
				appendOptionalField(RequestField::CurrencyCode);
			}
        }
    }
}