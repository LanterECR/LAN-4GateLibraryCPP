#include "GetLastOperation.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void GetLastOperation::addSpecificFields() {
                appendOptionalField(ResponseField::EcrMerchantNumber);
                appendOptionalField(ResponseField::OriginalOperationCode);
                appendOptionalField(ResponseField::TotalAmount);
                appendOptionalField(ResponseField::PartialAmount);
                appendOptionalField(ResponseField::AcquirerFeeAmount);
                appendOptionalField(ResponseField::TerminalFeeAmount);
                appendOptionalField(ResponseField::TipsAmount);
                appendOptionalField(ResponseField::CurrencyCode);
                appendOptionalField(ResponseField::ReceiptReference);
                appendOptionalField(ResponseField::RRN);
                appendOptionalField(ResponseField::OriginalOperationStatus);
                appendOptionalField(ResponseField::TransDateTime);
                appendOptionalField(ResponseField::TerminalDateTime);
                appendOptionalField(ResponseField::CardPAN);
                appendOptionalField(ResponseField::ExpireDate);
                appendOptionalField(ResponseField::CardholderName);
                appendOptionalField(ResponseField::CardholderAuthMethod);
                appendOptionalField(ResponseField::AuthCode);
                appendOptionalField(ResponseField::ResponseCode);
                appendOptionalField(ResponseField::ResponseText);
                appendOptionalField(ResponseField::STAN);
                appendOptionalField(ResponseField::TransactionID);
                appendOptionalField(ResponseField::TerminalID);
                appendOptionalField(ResponseField::CardEmvAid);
                appendOptionalField(ResponseField::CardAppName);
                appendOptionalField(ResponseField::CardInputMethod);
                appendOptionalField(ResponseField::IssuerName);
                appendOptionalField(ResponseField::AdditionalInfo);
                appendOptionalField(ResponseField::CardData);
                appendOptionalField(ResponseField::CardDataEnc);
                appendOptionalField(ResponseField::MerchantID);
                appendOptionalField(ResponseField::TVR);
                appendOptionalField(ResponseField::TSI);
                appendOptionalField(ResponseField::TC);
                appendOptionalField(ResponseField::CID);
                appendOptionalField(ResponseField::KVR);
                appendOptionalField(ResponseField::CDAResult);
            }
        }
    }
}
