#include "RepeatLastN.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void Response::RepeatLastN::addSpecificFields()
            {
                appendMandatoryField(ResponseField::Status);

                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}