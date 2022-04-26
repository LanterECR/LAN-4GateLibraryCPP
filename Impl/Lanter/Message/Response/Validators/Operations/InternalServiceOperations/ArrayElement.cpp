#include "ArrayElement.h"

namespace Lanter {
    namespace Message {
        namespace Response {

            void ArrayElement::addSpecificFields() {
                clearMandatoryFields();
                clearOptionalFields();

                appendOptionalField(ResponseField::ApplicationLabel);
                appendOptionalField(ResponseField::TotalAmount);
                appendOptionalField(ResponseField::CurrencyCode);
                appendOptionalField(ResponseField::RRN);
                appendOptionalField(ResponseField::ReceiptReference);
                appendOptionalField(ResponseField::ResponseCode);
                appendOptionalField(ResponseField::TransactionID);
                appendOptionalField(ResponseField::TransDateTime);
                appendOptionalField(ResponseField::IssuerName);
                appendOptionalField(ResponseField::CardPAN);
            }
        }
    }
}