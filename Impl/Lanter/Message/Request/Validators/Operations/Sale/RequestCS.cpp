#include "RequestCS.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void Request::RequestCS::addSpecificFields()
            {
                appendMandatoryField(RequestField::AdditionalInfo);
            }
        }
    }
}