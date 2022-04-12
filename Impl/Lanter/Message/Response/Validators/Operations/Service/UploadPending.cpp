#include "UploadPending.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void UploadPending::addSpecificFields() {

                appendOptionalField(ResponseField::ReceiptReference);
                appendOptionalField(ResponseField::EcrMerchantNumber);
                appendOptionalField(ResponseField::OriginalOperationCode);
                appendOptionalField(ResponseField::TotalAmount);
                appendOptionalField(ResponseField::CurrencyCode);
                appendOptionalField(ResponseField::MerchantID);
                appendOptionalField(ResponseField::IssuerName);
                appendOptionalField(ResponseField::CardPAN);
                appendOptionalField(ResponseField::CardholderAuthMethod);
                appendOptionalField(ResponseField::ReceiptReference);
                appendOptionalField(ResponseField::ResponseCode);
                appendOptionalField(ResponseField::RRN);
                appendOptionalField(ResponseField::AcquirerFeeAmount);
                appendOptionalField(ResponseField::TerminalFeeAmount);
                appendOptionalField(ResponseField::ResponseText);
                appendOptionalField(ResponseField::AuthCode);
                appendOptionalField(ResponseField::TransDateTime);
                appendOptionalField(ResponseField::TerminalDateTime);
                appendOptionalField(ResponseField::CardInputMethod);
                appendOptionalField(ResponseField::ExpireDate);
                appendOptionalField(ResponseField::CardAppName);
                appendOptionalField(ResponseField::CardEmvAid);
                appendOptionalField(ResponseField::CardDataEnc);
                appendOptionalField(ResponseField::TVR);
                appendOptionalField(ResponseField::TSI);
                appendOptionalField(ResponseField::TC);
                appendOptionalField(ResponseField::CID);
                appendOptionalField(ResponseField::KVR);
                appendOptionalField(ResponseField::CDAResult);
                appendOptionalField(ResponseField::TransactionID);
                appendOptionalField(ResponseField::CardholderName);
                appendOptionalField(ResponseField::ApplicationLabel);
                appendOptionalField(ResponseField::EcrMerchantNumber);
            }
        }
    }
}
