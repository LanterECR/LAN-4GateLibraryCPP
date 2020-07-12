//
// Created by Владимир Лысенков on 26.06.2020.
//

#include <stdexcept>

#include "FieldRangeChecker.h"

#include "RangeChecker.h"

#include "Lanter/Message/Response/CardholderAuthMethod.h"
#include "Lanter/Message/Response/CardInputMethod.h"
#include "Lanter/Message/Response/Status.h"
#include "Lanter/Message/Notification/NotificationCodes.h"
#include "Constants.h"

using namespace Lanter::Message;
using namespace Lanter::Utils::Constants;
namespace Lanter {
    namespace Utils {

        bool checkEcrNumberRange(int16_t ecrNumber) {
            if (!checkValueRange(ecrNumber, MINIMUM_ECR_NUMBER, MAXIMUM_ECR_NUMBER)) {
                throw std::invalid_argument("Invalid ecr number");
            }
            return true;
        }

        bool checkEcrMerchantNumberRange(int16_t ecrMerchantNumber) {
            if (!checkValueRange(ecrMerchantNumber, MINIMUM_ECR_MERCHANT_NUMBER, MAXIMUM_ECR_MERCHANT_NUMBER)) {
                throw std::invalid_argument("Invalid ecr merchant number");
            }
            return true;
        }

        bool checkOperationCodeRange(int32_t operationCode) {
            if (!checkValueRange(operationCode,
                                static_cast<int64_t>(OperationCodes::FirstValue),
                                static_cast<int64_t>(OperationCodes::LastValue)))
            {
                throw std::invalid_argument("Invalid operation code");
            }
            return true;
        }

        bool checkAmountRange(int64_t amount) {
            if (!checkValueRange(amount, MINIMUM_AMOUNT, MAXIMUM_AMOUNT)) {
                throw std::invalid_argument("Invalid amount");
            }
            return true;
        }

        bool checkCurrencyCodeRange(int64_t currencyCode) {
            if (!checkValueRange(currencyCode, MINIMUM_CURRENCY_CODE, MAXIMUM_CURRENCY_CODE)) {
                throw std::invalid_argument("Invalid currency code");
            }
            return true;
        }

        bool checkRRNRange(const std::string &RRN) {
            if (!checkValueRange(RRN.size(), MINIMUM_RRN_LENGTH, MAXIMUM_RRN_LENGTH)) {
                throw std::invalid_argument("Invalid RRN length");
            }
            return true;
        }

        bool checkAuthCodeRange(const std::string &authCode) {
            if (!checkValueRange(authCode.size(), MINIMUM_AUTH_CODE_LENGTH, MAXIMUM_AUTH_CODE_LENGTH)) {
                throw std::invalid_argument("Invalid auth code length");
            }
            return true;
        }

        bool checkReceiptReferenceRange(const std::string &receiptReference) {
            if (!checkValueRange(receiptReference.size(), MINIMUM_RECEIPT_REFERENCE_LENGTH, MAXIMUM_RECEIPT_REFERENCE_LENGTH)) {
                throw std::invalid_argument("Invalid receipt reference length");
            }
            return true;
        }

        bool checkTransactionIDRange(const std::string &transactionID) {
            if (!checkValueRange(transactionID.size(), MINIMUM_TRANSACTION_ID_LENGTH, MAXIMUM_TRANSACTION_ID_LENGTH)) {
                throw std::invalid_argument("Invalid TransactionID length");
            }
            return true;
        }

        bool checkCardDataEncRange(const std::string &cardDataEnc) {
            if (cardDataEnc.empty()) {
                throw std::invalid_argument("Invalid CardDataEnc length");
            }
            return true;
        }

        bool checkOpenTagsRange(const std::string &openTags) {
            if (openTags.empty()) {
                throw std::invalid_argument("Invalid OpenTags length");
            }
            return true;
        }

        bool checkEncTagsRange(const std::string &encTags) {
            if (encTags.empty()) {
                throw std::invalid_argument("Invalid EncTags length");
            }
            return true;
        }

        bool checkProviderCodeRange(const std::string &providerCode) {
            if (!checkValueRange(providerCode.size(), MINIMUM_PROVIDER_CODE_LENGTH, MAXIMUM_PROVIDER_CODE_LENGTH)) {
                throw std::invalid_argument("Invalid ProviderCode length");
            }
            return true;
        }

        bool checkAdditionalInfoRange(const std::string & additionalInfo) {
            if (additionalInfo.empty()) {
                throw std::invalid_argument("Invalid AdditionalInfo length");
            }
            return true;
        }

        bool checkStatusRange(int32_t status) {
            if (!checkValueRange(status,
                                 static_cast<int64_t>(Response::Status::FirstValue),
                                 static_cast<int64_t>(Response::Status::LastValue))){
                throw std::invalid_argument("Invalid status");
            }
            return true;
        }

        bool checkTransDateTimeRange(const std::string &dateTime) {
            if(!checkValueRange(dateTime.size(),
                                MINIMUM_TRANSACTION_DATETIME_LENGTH,
                                MAXIMUM_TRANSACTION_DATETIME_LENGTH))
            {
                throw std::invalid_argument("Invalid transaction date time length");
            }
            return true;
        }
        bool checkTerminalDateTimeRange(const std::string &dateTime) {
            if(!checkValueRange(dateTime.size(),
                                MINIMUM_TERMINAL_DATETIME_LENGTH,
                                MAXIMUM_TERMINAL_DATETIME_LENGTH))
            {
                throw std::invalid_argument("Invalid terminal date time length");
            }
            return true;
        }

        bool checkCardPANRange(const std::string &cardPAN) {
            if(!checkValueRange(cardPAN.size(),
                                MINIMUM_CARD_PAN_LENGTH,
                                MAXIMUM_CARD_PAN_LENGTH))
            {
                throw std::invalid_argument("Invalid card pan length");
            }
            return true;
        }

        bool checkExpireDateRange(const std::string &expireDate) {
            if(!checkValueRange(expireDate.size(),
                                MINIMUM_EXPIRE_DATE_LENGTH,
                                MAXIMUM_EXPIRE_DATE_LENGTH))
            {
                throw std::invalid_argument("Invalid expire date length");
            }
            return true;
        }

        bool checkCardholderNameRange(const std::string &cardholderName) {
            if(!checkValueRange(cardholderName.size(),
                                MINIMUM_CARDHOLDER_NAME_LENGTH,
                                MAXIMUM_CARDHOLDER_NAME_LENGTH))
            {
                throw std::invalid_argument("Invalid cardholder name length");
            }
            return true;
        }

        bool checkCardholderAuthMethodRange(int32_t cardholderAuthMethod) {
            if(!checkValueRange(cardholderAuthMethod,
                                static_cast<int64_t>(Response::CardholderAuthMethod::FirstValue),
                                static_cast<int64_t>(Response::CardholderAuthMethod::LastValue)))
            {
                throw std::invalid_argument("Invalid cardholder auth method");
            }
            return true;
        }

        bool checkResponseCodeRange(const std::string &responseCode) {
            if(!checkValueRange(responseCode.size(),
                                MINIMUM_RESPONSE_CODE_LENGTH,
                                MAXIMUM_RESPONSE_CODE_LENGTH))
            {
                throw std::invalid_argument("Invalid response code length");
            }
            return true;
        }

        bool checkResponseTextRange(const std::string &responseText) {
            if(!checkValueRange(responseText.size(),
                                MINIMUM_RESPONSE_TEXT_LENGTH,
                                MAXIMUM_RESPONSE_TEXT_LENGTH))
            {
                throw std::invalid_argument("Invalid response text length");
            }
            return true;
        }

        bool checkSTANRange(const std::string &STAN) {
            if(!checkValueRange(STAN.size(),
                                MINIMUM_STAN_LENGTH,
                                MAXIMUM_STAN_LENGTH))
            {
                throw std::invalid_argument("Invalid STAN length");
            }
            return true;
        }

        bool checkTerminalIDRange(const std::string &terminalID) {
            if(!checkValueRange(terminalID.size(),
                                MINIMUM_TERMINAL_ID_LENGTH,
                                MAXIMUM_TERMINAL_ID_LENGTH))
            {
                throw std::invalid_argument("Invalid terminal ID length");
            }
            return true;
        }

        bool checkCardEmvAidRange(const std::string &emvAID) {
            if(!checkValueRange(emvAID.size(),
                                MINIMUM_EMV_AID_LENGTH,
                                MAXIMUM_EMV_AID_LENGTH))
            {
                throw std::invalid_argument("Invalid emv AID length");
            }
            return true;
        }

        bool checkCardAppNameRange(const std::string &cardAppName) {
            if(!checkValueRange(cardAppName.size(),
                                MINIMUM_CARD_APP_NAME_LENGTH,
                                MAXIMUM_CARD_APP_NAME_LENGTH))
            {
                throw std::invalid_argument("Invalid card app name length");
            }
            return true;
        }

        bool checkCardInputMethodRange(int32_t cardInputMethod) {
            if(!checkValueRange(cardInputMethod,
                                static_cast<int64_t>(Response::CardInputMethod::FirstValue),
                                static_cast<int64_t>(Response::CardInputMethod::LastValue)))
            {
                throw std::invalid_argument("Invalid card input method");
            }
            return true;
        }

        bool checkIssuerNameRange(const std::string &issuerName) {
            if(!checkValueRange(issuerName.size(),
                                MINIMUM_ISSUER_NAME_LENGTH,
                                MAXIMUM_ISSUER_NAME_LENGTH))
            {
                throw std::invalid_argument("Invalid issuer name length");
            }
            return true;
        }

        bool checkCardDataRange(const std::string &cardData) {
            if(cardData.empty())
            {
                throw std::invalid_argument("Invalid card data length");
            }
            return true;
        }

        bool checkMerchantIDRange(const std::string &merchantID) {
            if(!checkValueRange(merchantID.size(),
                                MINIMUM_MERCHANT_ID_LENGTH,
                                MAXIMUM_MERCHANT_ID_LENGTH))
            {
                throw std::invalid_argument("Invalid merchant ID length");
            }
            return true;
        }

        bool checkTVRRange(const std::string &TVR) {
            if(!checkValueRange(TVR.size(),
                                MINIMUM_TVR_LENGTH,
                                MAXIMUM_TVR_LENGTH))
            {
                throw std::invalid_argument("Invalid TVR length");
            }
            return true;
        }

        bool checkTSIRange(const std::string &TSI) {
            if(!checkValueRange(TSI.size(),
                                MINIMUM_TSI_LENGTH,
                                MAXIMUM_TSI_LENGTH))
            {
                throw std::invalid_argument("Invalid TSI length");
            }
            return true;
        }

        bool checkTCRange(const std::string &TC) {
            if(!checkValueRange(TC.size(),
                                MINIMUM_TC_LENGTH,
                                MAXIMUM_TC_LENGTH))
            {
                throw std::invalid_argument("Invalid TC length");
            }
            return true;
        }

        bool checkCIDRange(const std::string &CID) {
            if(!checkValueRange(CID.size(),
                                MINIMUM_CID_LENGTH,
                                MAXIMUM_CID_LENGTH))
            {
                throw std::invalid_argument("Invalid CID length");
            }
            return true;
        }

        bool checkKVRRange(const std::string &KVR) {
            if(!checkValueRange(KVR.size(),
                                MINIMUM_KVR_LENGTH,
                                MAXIMUM_KVR_LENGTH))
            {
                throw std::invalid_argument("Invalid KVR length");
            }
            return true;
        }

        bool checkCDAResultRange(const std::string &CDAResult) {
            if(!checkValueRange(CDAResult.size(),
                                MINIMUM_CDARESULT_LENGTH,
                                MAXIMUM_CDARESULT_LENGTH))
            {
                throw std::invalid_argument("Invalid CDAResult length");
            }
            return true;
        }

        bool checkSalesCountRange(int32_t salesCount) {
            if(!checkValueRange(salesCount,
                                MINIMUM_ARRAY_SIZE,
                                MAXIMUM_ARRAY_SIZE))
            {
                throw std::invalid_argument("Invalid sales count size");
            }
            return true;
        }

        bool checkVoidCountRange(int32_t voidCount) {
            if(!checkValueRange(voidCount,
                                MINIMUM_ARRAY_SIZE,
                                MAXIMUM_ARRAY_SIZE))
            {
                throw std::invalid_argument("Invalid void count size");
            }
            return true;
        }

        bool checkRefundCountRange(int32_t refundCount) {
            if(!checkValueRange(refundCount,
                                MINIMUM_ARRAY_SIZE,
                                MAXIMUM_ARRAY_SIZE))
            {
                throw std::invalid_argument("Invalid refund count size");
            }
            return true;
        }

        bool checkNotificationsRange(int32_t notification) {
            if(!checkValueRange(notification,
                                static_cast<int64_t>(Notification::NotificationCodes::FirstValue),
                                static_cast<int64_t>(Notification::NotificationCodes::LastValue)))
            {
                throw std::invalid_argument("Invalid notification code");
            }
            return true;
        }


    }//Utils
}//Lanter