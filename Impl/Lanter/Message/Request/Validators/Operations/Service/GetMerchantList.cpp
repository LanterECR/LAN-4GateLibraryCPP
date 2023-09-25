#include "GetMerchantList.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void GetMerchantList::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrNumber);
            }
        }
    }
}