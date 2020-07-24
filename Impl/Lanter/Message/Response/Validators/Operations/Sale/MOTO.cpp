#include "MOTO.h"


namespace Lanter {
    namespace Message {
        namespace Response {
            void Response::MOTO::addSpecificFields() {
                appendOptionalField(ResponseField::EcrMerchantNumber);
                appendOptionalField(ResponseField::TotalAmount);
                appendOptionalField(ResponseField::CurrencyCode);
                appendOptionalField(ResponseField::RRN);
                appendOptionalField(ResponseField::ReceiptReference);
                appendOptionalField(ResponseField::TransactionID);
                appendOptionalField(ResponseField::AuthCode);
                appendOptionalField(ResponseField::ResponseCode);
                appendOptionalField(ResponseField::ResponseText);
                appendOptionalField(ResponseField::TerminalID);
                appendOptionalField(ResponseField::MerchantID);
                appendOptionalField(ResponseField::TransDateTime);
                appendOptionalField(ResponseField::TerminalDateTime);
                appendOptionalField(ResponseField::IssuerName);
                appendOptionalField(ResponseField::CardInputMethod);
                appendOptionalField(ResponseField::CardPAN);
                appendOptionalField(ResponseField::ExpireDate);
                appendOptionalField(ResponseField::CardAppName);
                appendOptionalField(ResponseField::CardEmvAid);
                appendOptionalField(ResponseField::CardDataEnc);
                appendOptionalField(ResponseField::CardholderName);
                appendOptionalField(ResponseField::CardholderAuthMethod);
            }
        }
    }
}
