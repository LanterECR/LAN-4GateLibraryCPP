#include "QRScannerResult.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            void QRScannerResult::addSpecificFields()
            {
                appendOptionalField(RequestField::EcrMerchantNumber);
                appendOptionalField(RequestField::EcrNumber);
                appendOptionalField(RequestField::OperationCode);
                appendOptionalField(RequestField::CurrencyCode);
                appendOptionalField(RequestField::TransportControlStation);
                appendOptionalField(RequestField::TransportControlArea);
                appendOptionalField(RequestField::TransportControlID);
            }
        }
    }
}