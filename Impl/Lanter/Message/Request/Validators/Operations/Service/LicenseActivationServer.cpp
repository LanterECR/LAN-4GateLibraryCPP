#include "LicenseActivationServer.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void LicenseActivationServer::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::OperationCode);
                appendOptionalField(RequestField::AdditionalInfo);
            }
        }
    }
}