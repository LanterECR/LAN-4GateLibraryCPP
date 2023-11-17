#include "QRScannerResult.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            void QRScannerResult::addSpecificFields()
            {
                appendOptionalField(ResponseField::AdditionalInfo);
                appendOptionalField(ResponseField::EcrNumber);
                appendOptionalField(ResponseField::OperationCode);
                appendOptionalField(ResponseField::ReceiptLine1);
                appendOptionalField(ResponseField::ReceiptLine2);
                appendOptionalField(ResponseField::ReceiptLine3);
                appendOptionalField(ResponseField::ReceiptLine4);
                appendOptionalField(ResponseField::ResponseCode);
                appendOptionalField(ResponseField::ResponseText);
                appendOptionalField(ResponseField::Status);
                appendOptionalField(ResponseField::TerminalID);
                appendOptionalField(ResponseField::TransportControlDateTime);
            }
        }
    }
}
