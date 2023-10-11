#include "NotificationCS.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void Request::NotificationCS::addSpecificFields()
            {
                appendOptionalField(RequestField::AdditionalInfo);
                appendOptionalField(RequestField::Amount);
                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::RRN);
                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::AuthCode);
                appendOptionalField(RequestField::CardPANHash);
            }
        }
    }
}