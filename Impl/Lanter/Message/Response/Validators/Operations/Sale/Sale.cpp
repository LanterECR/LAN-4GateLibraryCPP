#include "Sale.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void Response::Sale::addSpecificFields() {
                appendOptionalField(ResponseFields::EcrMerchantNumber);
                appendOptionalField(ResponseFields::TotalAmount);
                appendOptionalField(ResponseFields::CurrencyCode);
                appendOptionalField(ResponseFields::RRN);
                appendOptionalField(ResponseFields::ReceiptReference);
                appendOptionalField(ResponseFields::TransactionID);
                appendOptionalField(ResponseFields::AuthCode);
                appendOptionalField(ResponseFields::ResponseCode);
                appendOptionalField(ResponseFields::ResponseText);
                appendOptionalField(ResponseFields::TerminalID);
                appendOptionalField(ResponseFields::MerchantID);
                appendOptionalField(ResponseFields::TransDateTime);
                appendOptionalField(ResponseFields::TerminalDateTime);
                appendOptionalField(ResponseFields::IssuerName);
                appendOptionalField(ResponseFields::CardInputMethod);
                appendOptionalField(ResponseFields::CardPAN);
                appendOptionalField(ResponseFields::ExpireDate);
                appendOptionalField(ResponseFields::CardAppName);
                appendOptionalField(ResponseFields::CardEmvAid);
                appendOptionalField(ResponseFields::CardDataEnc);
                appendOptionalField(ResponseFields::TVR);
                appendOptionalField(ResponseFields::TSI);
                appendOptionalField(ResponseFields::TC);
                appendOptionalField(ResponseFields::CID);
                appendOptionalField(ResponseFields::KVR);
                appendOptionalField(ResponseFields::CDAResult);
                appendOptionalField(ResponseFields::CardholderName);
                appendOptionalField(ResponseFields::CardholderAuthMethod);
            }
        }
    }
}
