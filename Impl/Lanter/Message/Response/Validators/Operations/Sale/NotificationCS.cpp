#include "NotificationCS.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void Response::NotificationCS::addSpecificFields()
            {
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}