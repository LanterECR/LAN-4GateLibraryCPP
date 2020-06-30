#include "FastTrack.h"


namespace Lanter {
    namespace Response {
        void Response::FastTrack::addSpecificFields() {
            appendOptionalField(ResponseFields::EcrMerchantNumber);
            appendOptionalField(ResponseFields::TotalAmount);
            appendOptionalField(ResponseFields::AmountTerminalFee);
            appendOptionalField(ResponseFields::CurrencyCode);
            appendOptionalField(ResponseFields::ReceiptReference);
            appendOptionalField(ResponseFields::TerminalID);
            appendOptionalField(ResponseFields::MerchantID);
            appendOptionalField(ResponseFields::TerminalDateTime);
            appendOptionalField(ResponseFields::IssuerName);
            appendOptionalField(ResponseFields::CardInputMethod);
            appendOptionalField(ResponseFields::CardPAN);
            appendOptionalField(ResponseFields::ExpireDate);
            appendOptionalField(ResponseFields::CardAppName);
            appendOptionalField(ResponseFields::CardEmvAid);
            appendOptionalField(ResponseFields::CardData);
            appendOptionalField(ResponseFields::CardDataEnc);
            appendOptionalField(ResponseFields::CardholderName);
            appendOptionalField(ResponseFields::CardholderAuthMethod);
        }
    }
}
