#include "VoidLastSale.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void Request::VoidLastSale::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::OperationCode);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}