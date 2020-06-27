//
// Created by Владимир Лысенков on 25.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_CONSTANTS_H
#define LAN_4GATELIBRARYCPP_CONSTANTS_H

#include <cstdint>

namespace Lanter {
    namespace Utils {
        namespace Constants {
            static const uint64_t MINIMUM_AMOUNT = 0;
            static const uint64_t MAXIMUM_AMOUNT = 999999999999;

            static const uint16_t MINIMUM_ECR_NUMBER = 1;
            static const uint16_t MAXIMUM_ECR_NUMBER = 999;

            static const uint16_t MINIMUM_ECR_MERCHANT_NUMBER = 1;
            static const uint16_t MAXIMUM_ECR_MERCHANT_NUMBER = 999;

            static const uint16_t MINIMUM_CURRENCY_CODE = 1;
            static const uint16_t MAXIMUM_CURRENCY_CODE = 999;

            static const uint16_t MINIMUM_RRN_LENGTH = 1;
            static const uint16_t MAXIMUM_RRN_LENGTH = 8192;

            static const uint16_t MINIMUM_AUTH_CODE_LENGTH = 1;
            static const uint16_t MAXIMUM_AUTH_CODE_LENGTH = 8192;

            static const uint16_t MINIMUM_RECEIPT_REFERENCE_LENGTH = 1;
            static const uint16_t MAXIMUM_RECEIPT_REFERENCE_LENGTH = 8192;

            static const uint16_t MINIMUM_TRANSACTION_ID_LENGTH = 1;
            static const uint16_t MAXIMUM_TRANSACTION_ID_LENGTH = 8192;

            static const uint16_t MINIMUM_PROVIDER_CODE_LENGTH = 1;
            static const uint16_t MAXIMUM_PROVIDER_CODE_LENGTH = 8192;

            static const uint16_t MINIMUM_TRANSACTION_DATETIME_LENGTH = 1;
            static const uint16_t MAXIMUM_TRANSACTION_DATETIME_LENGTH = 8192;

            static const uint16_t MINIMUM_TERMINAL_DATETIME_LENGTH = 1;
            static const uint16_t MAXIMUM_TERMINAL_DATETIME_LENGTH = 8192;

            static const uint16_t MINIMUM_CARD_PAN_LENGTH = 1;
            static const uint16_t MAXIMUM_CARD_PAN_LENGTH = 8192;

            static const uint16_t MINIMUM_EXPIRE_DATE_LENGTH = 1;
            static const uint16_t MAXIMUM_EXPIRE_DATE_LENGTH = 8192;

            static const uint16_t MINIMUM_CARDHOLDER_NAME_LENGTH = 1;
            static const uint16_t MAXIMUM_CARDHOLDER_NAME_LENGTH = 8192;

            static const uint16_t MINIMUM_RESPONSE_CODE_LENGTH = 1;
            static const uint16_t MAXIMUM_RESPONSE_CODE_LENGTH = 8192;

            static const uint16_t MINIMUM_RESPONSE_TEXT_LENGTH = 1;
            static const uint16_t MAXIMUM_RESPONSE_TEXT_LENGTH = 8192;

            static const uint16_t MINIMUM_STAN_LENGTH = 1;
            static const uint16_t MAXIMUM_STAN_LENGTH = 8192;

            static const uint16_t MINIMUM_TERMINAL_ID_LENGTH = 1;
            static const uint16_t MAXIMUM_TERMINAL_ID_LENGTH = 8192;

            static const uint16_t MINIMUM_EMV_AID_LENGTH = 1;
            static const uint16_t MAXIMUM_EMV_AID_LENGTH = 8192;

            static const uint16_t MINIMUM_CARD_APP_NAME_LENGTH = 1;
            static const uint16_t MAXIMUM_CARD_APP_NAME_LENGTH = 8192;

            static const uint16_t MINIMUM_ISSUER_NAME_LENGTH = 1;
            static const uint16_t MAXIMUM_ISSUER_NAME_LENGTH = 8192;

            static const uint16_t MINIMUM_MERCHANT_ID_LENGTH = 1;
            static const uint16_t MAXIMUM_MERCHANT_ID_LENGTH = 8192;

            static const uint16_t MINIMUM_TVR_LENGTH = 1;
            static const uint16_t MAXIMUM_TVR_LENGTH = 8192;

            static const uint16_t MINIMUM_TSI_LENGTH = 1;
            static const uint16_t MAXIMUM_TSI_LENGTH = 8192;

            static const uint16_t MINIMUM_TC_LENGTH = 1;
            static const uint16_t MAXIMUM_TC_LENGTH = 8192;

            static const uint16_t MINIMUM_CID_LENGTH = 1;
            static const uint16_t MAXIMUM_CID_LENGTH = 8192;

            static const uint16_t MINIMUM_KVR_LENGTH = 1;
            static const uint16_t MAXIMUM_KVR_LENGTH = 8192;

            static const uint16_t MINIMUM_CDARESULT_LENGTH = 1;
            static const uint16_t MAXIMUM_CDARESULT_LENGTH = 8192;

            static const uint16_t MINIMUM_ARRAY_SIZE = 0;
            static const uint16_t MAXIMUM_ARRAY_SIZE = 999;
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_CONSTANTS_H
