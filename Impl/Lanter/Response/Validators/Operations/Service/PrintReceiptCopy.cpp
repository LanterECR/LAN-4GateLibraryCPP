//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "PrintReceiptCopy.h"

namespace Lanter {
    namespace Response {

        void PrintReceiptCopy::addSpecificFields() {
            appendMandatoryField(ResponseFields::EcrMerchantNumber);
            appendMandatoryField(ResponseFields::ReceiptReference);
        }
    }
}