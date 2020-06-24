//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "QuickPaymentStatus.h"

namespace Lanter {
    namespace Request {

        void QuickPaymentStatus::addSpecificFields() {
            appendMandatoryField(RequestFields::EcrMerchantNumber);

            appendOptionalField(RequestFields::RRN);
            appendOptionalField(RequestFields::AuthCode);
            appendOptionalField(RequestFields::TransactionID);
            appendOptionalField(RequestFields::ReceiptReference);
        }
    }
}