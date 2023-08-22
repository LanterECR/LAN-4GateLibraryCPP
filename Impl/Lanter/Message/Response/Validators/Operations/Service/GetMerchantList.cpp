#include "GetMerchantList.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void GetMerchantList::addSpecificFields()
            {
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}