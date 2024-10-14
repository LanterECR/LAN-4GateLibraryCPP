#include "VoidPreAuth.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void VoidPreAuth::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::OperationCode);
                appendOptionalField(RequestField::TransactionID);
                appendOptionalField(RequestField::AdditionalInfo);
                appendOptionalField(RequestField::CardDataEnc);
            }
        }
    }
}