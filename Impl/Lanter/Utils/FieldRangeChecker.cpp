#include <stdexcept>
#include <sstream>

#include "FieldRangeChecker.h"

#include "RangeChecker.h"

#include "Lanter/Message/Response/CardholderAuthMethod.h"
#include "Lanter/Message/Response/CardInputMethod.h"
#include "Lanter/Message/Response/Status.h"
#include "Lanter/Message/Notification/NotificationCode.h"
#include "Lanter/Message/Interaction/InteractionCode.h"

#include "Constants.h"

using namespace Lanter::Message;
using namespace Lanter::Utils::Constants;
namespace Lanter {
    namespace Utils {

        bool checkEcrNumberRange(int16_t ecrNumber) {
            return checkValueRange(ecrNumber, MINIMUM_ECR_NUMBER, MAXIMUM_ECR_NUMBER);
        }

        bool checkEcrMerchantNumberRange(int16_t ecrMerchantNumber) {
            return checkValueRange(ecrMerchantNumber, MINIMUM_ECR_MERCHANT_NUMBER, MAXIMUM_ECR_MERCHANT_NUMBER);
        }

        bool checkOperationCodeRange(int32_t operationCode) {
            return checkValueRange(operationCode,
                                static_cast<int64_t>(OperationCode::FirstValue),
                                static_cast<int64_t>(OperationCode::LastValue));
        }

        bool checkAmountRange(int64_t amount) {
            return checkValueRange(amount, MINIMUM_AMOUNT, MAXIMUM_AMOUNT);
        }

        bool checkCurrencyCodeRange(const std::string &currencyCode) {
            int currencyCodeInt;
            std::stringstream ss(currencyCode);

            ss >> currencyCodeInt;
            return checkValueRange(currencyCodeInt, MINIMUM_CURRENCY_CODE, MAXIMUM_CURRENCY_CODE);
        }

        bool checkRRNRange(const std::string &RRN) {
            return checkValueRange(RRN.size(), MINIMUM_RRN_LENGTH, MAXIMUM_RRN_LENGTH);
        }

        bool checkAuthCodeRange(const std::string &authCode) {
            return checkValueRange(authCode.size(), MINIMUM_AUTH_CODE_LENGTH, MAXIMUM_AUTH_CODE_LENGTH);
        }

        bool checkReceiptReferenceRange(const std::string &receiptReference) {
            return checkValueRange(receiptReference.size(), MINIMUM_RECEIPT_REFERENCE_LENGTH, MAXIMUM_RECEIPT_REFERENCE_LENGTH);
        }

        bool checkTransactionIDRange(const std::string &transactionID) {
            return checkValueRange(transactionID.size(), MINIMUM_TRANSACTION_ID_LENGTH, MAXIMUM_TRANSACTION_ID_LENGTH);
        }

        bool checkCardDataEncRange(const std::string &cardDataEnc) {
            return !cardDataEnc.empty();
        }

        bool checkOpenTagsRange(const std::string &openTags) {
            return !openTags.empty();
        }

        bool checkEncTagsRange(const std::string &encTags) {
            return !encTags.empty();
        }

        bool checkProviderCodeRange(const std::string &providerCode) {
            return checkValueRange(providerCode.size(), MINIMUM_PROVIDER_CODE_LENGTH, MAXIMUM_PROVIDER_CODE_LENGTH);
        }

        bool checkAdditionalInfoRange(const std::string & additionalInfo) {
            return !additionalInfo.empty();
        }

        bool checkStatusRange(int32_t status) {
            return checkValueRange(status,
                                 static_cast<int64_t>(Response::Status::FirstValue),
                                 static_cast<int64_t>(Response::Status::LastValue));
        }

        bool checkTransDateTimeRange(const std::string &dateTime) {
            return checkValueRange(dateTime.size(), MINIMUM_TRANSACTION_DATETIME_LENGTH, MAXIMUM_TRANSACTION_DATETIME_LENGTH);
        }
        bool checkTerminalDateTimeRange(const std::string &dateTime) {
            return checkValueRange(dateTime.size(), MINIMUM_TERMINAL_DATETIME_LENGTH, MAXIMUM_TERMINAL_DATETIME_LENGTH);
        }

        bool checkCardPANRange(const std::string &cardPAN) {
            return checkValueRange(cardPAN.size(), MINIMUM_CARD_PAN_LENGTH, MAXIMUM_CARD_PAN_LENGTH);
        }

        bool checkExpireDateRange(const std::string &expireDate) {
            return checkValueRange(expireDate.size(), MINIMUM_EXPIRE_DATE_LENGTH, MAXIMUM_EXPIRE_DATE_LENGTH);
        }

        bool checkCardholderNameRange(const std::string &cardholderName) {
            return checkValueRange(cardholderName.size(), MINIMUM_CARDHOLDER_NAME_LENGTH, MAXIMUM_CARDHOLDER_NAME_LENGTH);
        }

        bool checkCardholderAuthMethodRange(int32_t cardholderAuthMethod) {
            return checkValueRange(cardholderAuthMethod,
                                static_cast<int64_t>(Response::CardholderAuthMethod::FirstValue),
                                static_cast<int64_t>(Response::CardholderAuthMethod::LastValue));
        }

        bool checkResponseCodeRange(const std::string &responseCode) {
            return checkValueRange(responseCode.size(), MINIMUM_RESPONSE_CODE_LENGTH, MAXIMUM_RESPONSE_CODE_LENGTH);
        }

        bool checkResponseTextRange(const std::string &responseText) {
            return checkValueRange(responseText.size(), MINIMUM_RESPONSE_TEXT_LENGTH, MAXIMUM_RESPONSE_TEXT_LENGTH);
        }

        bool checkSTANRange(const std::string &STAN) {
            return checkValueRange(STAN.size(), MINIMUM_STAN_LENGTH, MAXIMUM_STAN_LENGTH);
        }

        bool checkTerminalIDRange(const std::string &terminalID) {
            return checkValueRange(terminalID.size(), MINIMUM_TERMINAL_ID_LENGTH, MAXIMUM_TERMINAL_ID_LENGTH);
        }

        bool checkCardEmvAidRange(const std::string &emvAID) {
            return checkValueRange(emvAID.size(), MINIMUM_CARD_EMV_AID_LENGTH, MAXIMUM_CARD_EMV_AID_LENGTH);
        }

        bool checkCardAppNameRange(const std::string &cardAppName) {
            return checkValueRange(cardAppName.size(), MINIMUM_CARD_APP_NAME_LENGTH, MAXIMUM_CARD_APP_NAME_LENGTH);
        }

        bool checkCardInputMethodRange(int32_t cardInputMethod) {
            return checkValueRange(cardInputMethod,
                                static_cast<int64_t>(Response::CardInputMethod::FirstValue),
                                static_cast<int64_t>(Response::CardInputMethod::LastValue));
        }

        bool checkIssuerNameRange(const std::string &issuerName) {
            return checkValueRange(issuerName.size(), MINIMUM_ISSUER_NAME_LENGTH, MAXIMUM_ISSUER_NAME_LENGTH);
        }

        bool checkCardDataRange(const std::string &cardData) {
            return !cardData.empty();
        }

        bool checkMerchantIDRange(const std::string &merchantID) {
            return checkValueRange(merchantID.size(), MINIMUM_MERCHANT_ID_LENGTH, MAXIMUM_MERCHANT_ID_LENGTH);
        }

        bool checkTVRRange(const std::string &TVR) {
            return checkValueRange(TVR.size(), MINIMUM_TVR_LENGTH, MAXIMUM_TVR_LENGTH);
        }

        bool checkTSIRange(const std::string &TSI) {
            return checkValueRange(TSI.size(), MINIMUM_TSI_LENGTH, MAXIMUM_TSI_LENGTH);
        }

        bool checkTCRange(const std::string &TC) {
            return checkValueRange(TC.size(), MINIMUM_TC_LENGTH, MAXIMUM_TC_LENGTH);
        }

        bool checkCIDRange(const std::string &CID) {
            return checkValueRange(CID.size(), MINIMUM_CID_LENGTH, MAXIMUM_CID_LENGTH);
        }

        bool checkKVRRange(const std::string &KVR) {
            return checkValueRange(KVR.size(), MINIMUM_KVR_LENGTH, MAXIMUM_KVR_LENGTH);
        }

        bool checkCDAResultRange(const std::string &CDAResult) {
            return checkValueRange(CDAResult.size(), MINIMUM_CDARESULT_LENGTH, MAXIMUM_CDARESULT_LENGTH);
        }

        bool checkSalesCountRange(int32_t salesCount) {
            return checkValueRange(salesCount, MINIMUM_ARRAY_SIZE, MAXIMUM_ARRAY_SIZE);
        }

        bool checkVoidCountRange(int32_t voidCount) {
            return checkValueRange(voidCount, MINIMUM_ARRAY_SIZE, MAXIMUM_ARRAY_SIZE);
        }

        bool checkRefundCountRange(int32_t refundCount) {
            return checkValueRange(refundCount, MINIMUM_ARRAY_SIZE, MAXIMUM_ARRAY_SIZE);
        }

        bool checkNotificationsRange(int32_t notification) {
            return checkValueRange(notification,
                                static_cast<int64_t>(Notification::NotificationCode::FirstValue),
                                static_cast<int64_t>(Notification::NotificationCode::LastValue));

        }

        bool checkInteractionsRange(int32_t notification) {
            return checkValueRange(notification,
                                   static_cast<int64_t>(Interaction::InteractionCode::FirstValue),
                                   static_cast<int64_t>(Interaction::InteractionCode::LastValue));

        }
    }//Utils
}//Lanter