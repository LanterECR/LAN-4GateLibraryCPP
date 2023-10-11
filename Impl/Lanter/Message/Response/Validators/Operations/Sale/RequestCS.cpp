#include "RequestCS.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void Response::RequestCS::addSpecificFields()
            {
                appendOptionalField(ResponseField::Status);
                appendOptionalField(ResponseField::AdditionalInfo);
                appendOptionalField(ResponseField::TotalAmount);
                appendOptionalField(ResponseField::TransDateTime);
            }
        }
    }
}