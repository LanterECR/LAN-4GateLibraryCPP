#include "Settlement.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void Response::Settlement::addSpecificFields()
            {
                appendOptionalField(ResponseField::OperationCode);
                appendOptionalField(ResponseField::EcrNumber);
                appendOptionalField(ResponseField::EcrMerchantNumber);
                appendOptionalField(ResponseField::TotalAmount);
                appendOptionalField(ResponseField::CurrencyCode);
                appendOptionalField(ResponseField::TerminalID);
                appendOptionalField(ResponseField::MerchantID);
                appendOptionalField(ResponseField::TerminalDateTime);
                appendOptionalField(ResponseField::SalesCount);
                appendOptionalField(ResponseField::VoidCount);
                appendOptionalField(ResponseField::RefundCount);
                appendOptionalField(ResponseField::SalesArray);
                appendOptionalField(ResponseField::VoidArray);
                appendOptionalField(ResponseField::RefundArray);
                appendOptionalField(ResponseField::SalesAmount);
                appendOptionalField(ResponseField::VoidAmount);
                appendOptionalField(ResponseField::RefundAmount);
                appendOptionalField(ResponseField::TransDateTime);
                appendOptionalField(ResponseField::ResponseCode);
                appendOptionalField(ResponseField::ResponseText);
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}