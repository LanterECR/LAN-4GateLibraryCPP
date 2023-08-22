#include "NotificationCS.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void Request::NotificationCS::addSpecificFields()
            {
                appendMandatoryField(RequestField::AdditionalInfo);
                appendMandatoryField(RequestField::Amount);

                appendOptionalField(RequestField::RRN);
                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::AuthCode);
                //appendOptionalField(RequestField::CardPan);
                //appendOptionalField(RequestField::CfgIssuerName);
                //appendOptionalField(RequestField::TerminalID);
                appendOptionalField(RequestField::CardPANHash);
                //appendOptionalField(RequestField::ResponseCode);
                //appendOptionalField(RequestField::TerminalReference);
            }
        }
    }
}