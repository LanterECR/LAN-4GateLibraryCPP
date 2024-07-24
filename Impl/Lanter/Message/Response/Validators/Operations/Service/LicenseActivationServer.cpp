#include "LicenseActivationServer.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void LicenseActivationServer::addSpecificFields()
            {
                appendOptionalField(ResponseField::EcrNumber);
                appendOptionalField(ResponseField::OperationCode);
                appendOptionalField(ResponseField::Status);
                appendOptionalField(ResponseField::AdditionalInfo);
            }
        }
    }
}