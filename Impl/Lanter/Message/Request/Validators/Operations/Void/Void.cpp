#include "Void.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void Request::Void::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::OperationCode);
                appendOptionalField(RequestField::ReceiptReference);
                appendOptionalField(RequestField::RRN);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}