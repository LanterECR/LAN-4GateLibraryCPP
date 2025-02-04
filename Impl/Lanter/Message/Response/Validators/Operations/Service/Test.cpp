#include "Test.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void Test::addSpecificFields()
            {
                appendOptionalField(ResponseField::OperationCode);
                appendOptionalField(ResponseField::EcrNumber);
                appendOptionalField(ResponseField::EcrMerchantNumber);
                appendOptionalField(ResponseField::ResponseCode);
                appendOptionalField(ResponseField::ResponseText);
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}