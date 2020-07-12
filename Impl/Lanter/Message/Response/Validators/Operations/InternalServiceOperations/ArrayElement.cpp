//
// Created by Владимир Лысенков on 12.07.2020.
//

#include "ArrayElement.h"

namespace Lanter {
    namespace Message {
        namespace Response {

            void ArrayElement::addSpecificFields() {
                clearMandatoryFields();
                clearOptionalFields();

                appendOptionalField(ResponseFields::TotalAmount);
                appendOptionalField(ResponseFields::CurrencyCode);
                appendOptionalField(ResponseFields::RRN);
                appendOptionalField(ResponseFields::ReceiptReference);
                appendOptionalField(ResponseFields::ResponseCode);
                appendOptionalField(ResponseFields::TransactionID);
                appendOptionalField(ResponseFields::TransDateTime);
                appendOptionalField(ResponseFields::IssuerName);
                appendOptionalField(ResponseFields::CardPAN);
            }
        }
    }
}