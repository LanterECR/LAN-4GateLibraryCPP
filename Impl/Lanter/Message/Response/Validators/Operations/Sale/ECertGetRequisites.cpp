#include "ECertGetRequisites.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void Response::ECertGetRequisites::addSpecificFields() {
                appendOptionalField(ResponseField::EcrMerchantNumber);

				appendOptionalField(ResponseField::AdditionalInfo);
				appendOptionalField(ResponseField::CardEmvAid);
				appendOptionalField(ResponseField::CardInputMethod);
				appendOptionalField(ResponseField::CardPANHash);
				appendOptionalField(ResponseField::CardholderAuthMethod);
				appendOptionalField(ResponseField::CardholderName);
				appendOptionalField(ResponseField::CurrencyCode);
				appendOptionalField(ResponseField::ExpireDate);
				appendOptionalField(ResponseField::IssuerName);
				appendOptionalField(ResponseField::TerminalID);
				appendOptionalField(ResponseField::MerchantID);
				appendOptionalField(ResponseField::Status);
				appendOptionalField(ResponseField::ReceiptLine1);
				appendOptionalField(ResponseField::ReceiptLine2);
				appendOptionalField(ResponseField::ReceiptLine3);
				appendOptionalField(ResponseField::ReceiptLine4);
				appendOptionalField(ResponseField::ReceiptLine5);
				appendOptionalField(ResponseField::TerminalDateTime);
            }
        }
    }
}
