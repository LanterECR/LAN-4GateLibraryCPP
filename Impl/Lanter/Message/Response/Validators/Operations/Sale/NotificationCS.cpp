#include "NotificationCS.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void Response::NotificationCS::addSpecificFields()
            {
                appendMandatoryField(ResponseField::AdditionalInfo);
            }
        }
    }
}