#include "GetOperationCopy.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void GetOperationCopy::addSpecificFields() {
                appendOptionalField(ResponseFields::EcrMerchantNumber);
                appendOptionalField(ResponseFields::OriginalOperationCode);
                appendOptionalField(ResponseFields::TotalAmount);
                appendOptionalField(ResponseFields::PartialAmount);
                appendOptionalField(ResponseFields::AcquirerFeeAmount);
                appendOptionalField(ResponseFields::TerminalFeeAmount);
                appendOptionalField(ResponseFields::TipsAmount);
                appendOptionalField(ResponseFields::CurrencyCode);
                appendOptionalField(ResponseFields::ReceiptReference);
                appendOptionalField(ResponseFields::RRN);
                appendOptionalField(ResponseFields::OriginalOperationStatus);
                appendOptionalField(ResponseFields::TransDateTime);
                appendOptionalField(ResponseFields::TerminalDateTime);
                appendOptionalField(ResponseFields::CardPAN);
                appendOptionalField(ResponseFields::ExpireDate);
                appendOptionalField(ResponseFields::CardholderName);
                appendOptionalField(ResponseFields::CardholderAuthMethod);
                appendOptionalField(ResponseFields::AuthCode);
                appendOptionalField(ResponseFields::ResponseCode);
                appendOptionalField(ResponseFields::ResponseText);
                appendOptionalField(ResponseFields::STAN);
                appendOptionalField(ResponseFields::TransactionID);
                appendOptionalField(ResponseFields::TerminalID);
                appendOptionalField(ResponseFields::CardEmvAid);
                appendOptionalField(ResponseFields::CardAppName);
                appendOptionalField(ResponseFields::CardInputMethod);
                appendOptionalField(ResponseFields::IssuerName);
                appendOptionalField(ResponseFields::AdditionalInfo);
                appendOptionalField(ResponseFields::CardData);
                appendOptionalField(ResponseFields::CardDataEnc);
                appendOptionalField(ResponseFields::MerchantID);
                appendOptionalField(ResponseFields::TVR);
                appendOptionalField(ResponseFields::TSI);
                appendOptionalField(ResponseFields::TC);
                appendOptionalField(ResponseFields::CID);
                appendOptionalField(ResponseFields::KVR);
                appendOptionalField(ResponseFields::CDAResult);
            }
        }
    }
}
