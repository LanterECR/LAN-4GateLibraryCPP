#include "FastTrack.h"


namespace Lanter {
    namespace Message {
        namespace Response {
            void Response::FastTrack::addSpecificFields() {
                appendOptionalField(ResponseField::EcrMerchantNumber);
                appendOptionalField(ResponseField::TotalAmount);
                appendOptionalField(ResponseField::TerminalFeeAmount);
                appendOptionalField(ResponseField::CurrencyCode);
                appendOptionalField(ResponseField::ReceiptReference);
                appendOptionalField(ResponseField::TerminalID);
                appendOptionalField(ResponseField::MerchantID);
                appendOptionalField(ResponseField::TerminalDateTime);
                appendOptionalField(ResponseField::IssuerName);
                appendOptionalField(ResponseField::CardInputMethod);
                appendOptionalField(ResponseField::CardPAN);
                appendOptionalField(ResponseField::ExpireDate);
                appendOptionalField(ResponseField::CardAppName);
                appendOptionalField(ResponseField::CardEmvAid);
                appendOptionalField(ResponseField::CardData);
                appendOptionalField(ResponseField::CardDataEnc);
                appendOptionalField(ResponseField::CardholderName);
                appendOptionalField(ResponseField::CardholderAuthMethod);
                appendOptionalField(ResponseField::CardPANHash);
            }
        }
    }
}
