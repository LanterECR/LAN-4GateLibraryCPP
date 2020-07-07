//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "PrintReceiptCopy.h"

namespace Lanter {
    namespace Message {
        namespace Request {

            void PrintReceiptCopy::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
                appendMandatoryField(RequestFields::ReceiptReference);
            }
        }
    }
}