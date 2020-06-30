//
// Created by Владимир Лысенков on 28.06.2020.
//

#include "gtest/gtest.h"
#include "Lanter/Utils/Constants.h"
#include "Lanter/Utils/FieldRangeChecker.h"
#include "Lanter/OperationCodes.h"
#include "Lanter/Response/Status.h"
#include "Lanter/Response/CardInputMethod.h"
#include "Lanter/Response/CardholderAuthMethod.h"
#include "Lanter/Notifications/NotificationCodes.h"

using namespace Lanter;
using namespace Lanter::Response;
using namespace Lanter::Notifications;
using namespace Lanter::Utils;
using namespace Lanter::Utils::Constants;

TEST(FieldsRangeChecker, CheckEcrNumberRange){
    int64_t lessMinimum = MINIMUM_ECR_NUMBER - 1;
    int64_t greatMaximum = MAXIMUM_ECR_NUMBER + 1;

    EXPECT_THROW(checkEcrNumberRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkEcrNumberRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkEcrNumberRange(MINIMUM_ECR_NUMBER));
    EXPECT_TRUE(checkEcrNumberRange(MAXIMUM_ECR_NUMBER));

    EXPECT_TRUE(checkEcrNumberRange(MINIMUM_ECR_NUMBER + 1));
    EXPECT_TRUE(checkEcrNumberRange(MAXIMUM_ECR_NUMBER - 1));
}
TEST(FieldsRangeChecker, CheckEcrMerchantNumberRange){
    int64_t lessMinimum = MINIMUM_ECR_MERCHANT_NUMBER - 1;
    int64_t greatMaximum = MAXIMUM_ECR_MERCHANT_NUMBER + 1;

    EXPECT_THROW(checkEcrMerchantNumberRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkEcrMerchantNumberRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkEcrMerchantNumberRange(MINIMUM_ECR_NUMBER));
    EXPECT_TRUE(checkEcrMerchantNumberRange(MAXIMUM_ECR_NUMBER));

    EXPECT_TRUE(checkEcrMerchantNumberRange(MINIMUM_ECR_NUMBER + 1));
    EXPECT_TRUE(checkEcrMerchantNumberRange(MAXIMUM_ECR_NUMBER - 1));
}
TEST(FieldsRangeChecker, CheckOperationCodeRange){
    auto lessMinimum =  (int32_t)OperationCodes::FirstValue - 1;
    auto greatMaximum = (int32_t)OperationCodes::LastValue + 1;

    auto greatMinimum = (int32_t)OperationCodes::FirstValue + 1;
    auto lessMaximum = (int32_t)OperationCodes::LastValue - 1;

    EXPECT_THROW(checkOperationCodeRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkOperationCodeRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkOperationCodeRange((int32_t)OperationCodes::FirstValue));
    EXPECT_TRUE(checkOperationCodeRange((int32_t)OperationCodes::LastValue));

    EXPECT_TRUE(checkOperationCodeRange(greatMinimum));
    EXPECT_TRUE(checkOperationCodeRange(lessMaximum));
}
TEST(FieldsRangeChecker, CheckAmountRange){
    int64_t lessMinimum = MINIMUM_AMOUNT - 1;
    int64_t greatMaximum = MAXIMUM_AMOUNT + 1;

    EXPECT_THROW(checkAmountRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkAmountRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkAmountRange(MINIMUM_AMOUNT));
    EXPECT_TRUE(checkAmountRange(MAXIMUM_AMOUNT));

    EXPECT_TRUE(checkAmountRange(MINIMUM_AMOUNT + 1));
    EXPECT_TRUE(checkAmountRange(MAXIMUM_AMOUNT - 1));
}
TEST(FieldsRangeChecker, CheckCurrencyCodeRange){
    int64_t lessMinimum = MINIMUM_CURRENCY_CODE - 1;
    int64_t greatMaximum = MAXIMUM_CURRENCY_CODE + 1;

    EXPECT_THROW(checkCurrencyCodeRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkCurrencyCodeRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkCurrencyCodeRange(MINIMUM_CURRENCY_CODE));
    EXPECT_TRUE(checkCurrencyCodeRange(MAXIMUM_CURRENCY_CODE));

    EXPECT_TRUE(checkAmountRange(MINIMUM_CURRENCY_CODE + 1));
    EXPECT_TRUE(checkAmountRange(MAXIMUM_CURRENCY_CODE - 1));
}
TEST(FieldsRangeChecker, CheckRRNRange){
    std::string empty;

    EXPECT_THROW(checkRRNRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_RRN_LENGTH + 1, 'R');

    EXPECT_THROW(checkRRNRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_RRN_LENGTH, 'R');

    EXPECT_TRUE(checkRRNRange(minimumSize));

    std::string maximumSize(MAXIMUM_RRN_LENGTH, 'R');

    EXPECT_TRUE(checkRRNRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckAuthCodeRange){
    std::string empty;

    EXPECT_THROW(checkAuthCodeRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_AUTH_CODE_LENGTH + 1, 'R');

    EXPECT_THROW(checkAuthCodeRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_AUTH_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkAuthCodeRange(minimumSize));

    std::string maximumSize(MAXIMUM_AUTH_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkAuthCodeRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckReceiptReferenceRange){
    std::string empty;

    EXPECT_THROW(checkReceiptReferenceRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_RECEIPT_REFERENCE_LENGTH + 1, 'R');

    EXPECT_THROW(checkReceiptReferenceRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_RECEIPT_REFERENCE_LENGTH, 'R');

    EXPECT_TRUE(checkReceiptReferenceRange(minimumSize));

    std::string maximumSize(MAXIMUM_RECEIPT_REFERENCE_LENGTH, 'R');

    EXPECT_TRUE(checkReceiptReferenceRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckTransactionIDRange){
    std::string empty;

    EXPECT_THROW(checkTransactionIDRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH + 1, 'R');

    EXPECT_THROW(checkTransactionIDRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TRANSACTION_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTransactionIDRange(minimumSize));

    std::string maximumSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTransactionIDRange(maximumSize));
}

TEST(FieldsRangeChecker, CheckCardDataEncRange){
    std::string empty;

    EXPECT_THROW(checkCardDataRange(empty), std::invalid_argument);

    size_t len = 512;
    std::string notEmpty(len, 'R');

    EXPECT_TRUE(checkCardDataRange(notEmpty));
}

TEST(FieldsRangeChecker, CheckOpenTagsRange){
    std::string empty;

    EXPECT_THROW(checkOpenTagsRange(empty), std::invalid_argument);

    size_t len = 512;
    std::string notEmpty(len, 'R');

    EXPECT_TRUE(checkOpenTagsRange(notEmpty));
}
TEST(FieldsRangeChecker, CheckEncTagsRange){
    std::string empty;

    EXPECT_THROW(checkEncTagsRange(empty), std::invalid_argument);

    size_t len = 512;
    std::string notEmpty(len, 'R');

    EXPECT_TRUE(checkEncTagsRange(notEmpty));
}
TEST(FieldsRangeChecker, CheckProviderCodeRange){
    std::string empty;

    EXPECT_THROW(checkProviderCodeRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_PROVIDER_CODE_LENGTH + 1, 'R');

    EXPECT_THROW(checkProviderCodeRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_PROVIDER_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkProviderCodeRange(minimumSize));

    std::string maximumSize(MAXIMUM_PROVIDER_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkProviderCodeRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckAdditionalInfoRange){
    std::string empty;

    EXPECT_THROW(checkAdditionalInfoRange(empty), std::invalid_argument);

    size_t len = 512;
    std::string notEmpty(len, 'R');

    EXPECT_TRUE(checkAdditionalInfoRange(notEmpty));
}
TEST(FieldsRangeChecker, CheckStatusRange){
    auto lessMinimum =  (int32_t)Status::FirstValue - 1;
    auto greatMaximum = (int32_t)Status::LastValue + 1;

    auto greatMinimum = (int32_t)Status::FirstValue + 1;
    auto lessMaximum = (int32_t)Status::LastValue - 1;

    EXPECT_THROW(checkStatusRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkStatusRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkStatusRange((int32_t)Status::FirstValue));
    EXPECT_TRUE(checkStatusRange((int32_t)Status::LastValue));

    EXPECT_TRUE(checkStatusRange(greatMinimum));
    EXPECT_TRUE(checkStatusRange(lessMaximum));
}
TEST(FieldsRangeChecker, CheckTransDateTimeRange){
    std::string empty;

    EXPECT_THROW(checkTransDateTimeRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH + 1, 'R');

    EXPECT_THROW(checkTransDateTimeRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TRANSACTION_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTransDateTimeRange(minimumSize));

    std::string maximumSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTransDateTimeRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckTerminalDateTimeRange){
    std::string empty;

    EXPECT_THROW(checkTerminalDateTimeRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_TERMINAL_DATETIME_LENGTH + 1, 'R');

    EXPECT_THROW(checkTerminalDateTimeRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TERMINAL_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTerminalDateTimeRange(minimumSize));

    std::string maximumSize(MAXIMUM_TERMINAL_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTerminalDateTimeRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckCardPANRange){
    std::string empty;

    EXPECT_THROW(checkCardPANRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_CARD_PAN_LENGTH + 1, 'R');

    EXPECT_THROW(checkCardPANRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_CARD_PAN_LENGTH, 'R');

    EXPECT_TRUE(checkCardPANRange(minimumSize));

    std::string maximumSize(MAXIMUM_CARD_PAN_LENGTH, 'R');

    EXPECT_TRUE(checkCardPANRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckExpireDateRange){
    std::string empty;

    EXPECT_THROW(checkExpireDateRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_EXPIRE_DATE_LENGTH + 1, 'R');

    EXPECT_THROW(checkExpireDateRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_EXPIRE_DATE_LENGTH, 'R');

    EXPECT_TRUE(checkExpireDateRange(minimumSize));

    std::string maximumSize(MAXIMUM_EXPIRE_DATE_LENGTH, 'R');

    EXPECT_TRUE(checkExpireDateRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckCardholderNameRange){
    std::string empty;

    EXPECT_THROW(checkCardholderNameRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_CARDHOLDER_NAME_LENGTH + 1, 'R');

    EXPECT_THROW(checkCardholderNameRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_CARDHOLDER_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkCardholderNameRange(minimumSize));

    std::string maximumSize(MINIMUM_CARDHOLDER_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkCardholderNameRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckCardholderAuthMethodRange){
    auto lessMinimum =  (int32_t)CardholderAuthMethod::FirstValue - 1;
    auto greatMaximum = (int32_t)CardholderAuthMethod::LastValue + 1;

    auto greatMinimum = (int32_t)CardholderAuthMethod::FirstValue + 1;
    auto lessMaximum = (int32_t)CardholderAuthMethod::LastValue - 1;

    EXPECT_THROW(checkCardholderAuthMethodRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkCardholderAuthMethodRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkCardholderAuthMethodRange((int32_t)CardholderAuthMethod::FirstValue));
    EXPECT_TRUE(checkCardholderAuthMethodRange((int32_t)CardholderAuthMethod::LastValue));

    EXPECT_TRUE(checkCardholderAuthMethodRange(greatMinimum));
    EXPECT_TRUE(checkCardholderAuthMethodRange(lessMaximum));
}
TEST(FieldsRangeChecker, CheckResponseCodeRange){
    std::string empty;

    EXPECT_THROW(checkResponseCodeRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_RESPONSE_CODE_LENGTH + 1, 'R');

    EXPECT_THROW(checkResponseCodeRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_RESPONSE_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkResponseCodeRange(minimumSize));

    std::string maximumSize(MAXIMUM_RESPONSE_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkResponseCodeRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckResponseTextRange){
    std::string empty;

    EXPECT_THROW(checkResponseTextRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_RESPONSE_TEXT_LENGTH + 1, 'R');

    EXPECT_THROW(checkResponseTextRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_RESPONSE_TEXT_LENGTH, 'R');

    EXPECT_TRUE(checkResponseTextRange(minimumSize));

    std::string maximumSize(MAXIMUM_RESPONSE_TEXT_LENGTH, 'R');

    EXPECT_TRUE(checkResponseTextRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckSTANRange){
    std::string empty;

    EXPECT_THROW(checkSTANRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_STAN_LENGTH + 1, 'R');

    EXPECT_THROW(checkSTANRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_STAN_LENGTH, 'R');

    EXPECT_TRUE(checkSTANRange(minimumSize));

    std::string maximumSize(MAXIMUM_STAN_LENGTH, 'R');

    EXPECT_TRUE(checkSTANRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckTerminalIDRange){
    std::string empty;

    EXPECT_THROW(checkTerminalIDRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_TERMINAL_ID_LENGTH + 1, 'R');

    EXPECT_THROW(checkTerminalIDRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TERMINAL_ID_LENGTH, 'R');

    EXPECT_TRUE(checkTerminalIDRange(minimumSize));

    std::string maximumSize(MAXIMUM_TERMINAL_ID_LENGTH, 'R');

    EXPECT_TRUE(checkTerminalIDRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckCardEmvAidRange){
    std::string empty;

    EXPECT_THROW(checkCardEmvAidRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_EMV_AID_LENGTH + 1, 'R');

    EXPECT_THROW(checkCardEmvAidRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_EMV_AID_LENGTH, 'R');

    EXPECT_TRUE(checkCardEmvAidRange(minimumSize));

    std::string maximumSize(MAXIMUM_EMV_AID_LENGTH, 'R');

    EXPECT_TRUE(checkCardEmvAidRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckCardAppNameRange){
    std::string empty;

    EXPECT_THROW(checkCardAppNameRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_CARD_APP_NAME_LENGTH + 1, 'R');

    EXPECT_THROW(checkCardAppNameRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_CARD_APP_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkCardAppNameRange(minimumSize));

    std::string maximumSize(MAXIMUM_CARD_APP_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkCardAppNameRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckCardInputMethodRange){
    auto lessMinimum =  (int32_t)CardInputMethod::FirstValue - 1;
    auto greatMaximum = (int32_t)CardInputMethod::LastValue + 1;

    auto greatMinimum = (int32_t)CardInputMethod::FirstValue + 1;
    auto lessMaximum = (int32_t)CardInputMethod::LastValue - 1;

    EXPECT_THROW(checkCardInputMethodRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkCardInputMethodRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkCardInputMethodRange((int32_t)CardInputMethod::FirstValue));
    EXPECT_TRUE(checkCardInputMethodRange((int32_t)CardInputMethod::LastValue));

    EXPECT_TRUE(checkCardInputMethodRange(greatMinimum));
    EXPECT_TRUE(checkCardInputMethodRange(lessMaximum));
}
TEST(FieldsRangeChecker, CheckIssuerNameRange){
    std::string empty;

    EXPECT_THROW(checkIssuerNameRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_ISSUER_NAME_LENGTH + 1, 'R');

    EXPECT_THROW(checkIssuerNameRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_ISSUER_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkIssuerNameRange(minimumSize));

    std::string maximumSize(MAXIMUM_ISSUER_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkIssuerNameRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckCardDataRange){
    std::string empty;

    EXPECT_THROW(checkCardDataRange(empty), std::invalid_argument);

    std::string notEmpty( 512, 'R');

    EXPECT_TRUE(checkResponseCodeRange(notEmpty));
}
TEST(FieldsRangeChecker, CheckMerchantIDRange){
    std::string empty;

    EXPECT_THROW(checkMerchantIDRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_MERCHANT_ID_LENGTH + 1, 'R');

    EXPECT_THROW(checkMerchantIDRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_MERCHANT_ID_LENGTH, 'R');

    EXPECT_TRUE(checkMerchantIDRange(minimumSize));

    std::string maximumSize(MAXIMUM_MERCHANT_ID_LENGTH, 'R');

    EXPECT_TRUE(checkMerchantIDRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckTVRRange){
    std::string empty;

    EXPECT_THROW(checkTVRRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_TVR_LENGTH + 1, 'R');

    EXPECT_THROW(checkTVRRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TVR_LENGTH, 'R');

    EXPECT_TRUE(checkTVRRange(minimumSize));

    std::string maximumSize(MAXIMUM_TVR_LENGTH, 'R');

    EXPECT_TRUE(checkTVRRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckTSIRange){
    std::string empty;

    EXPECT_THROW(checkTSIRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_TSI_LENGTH + 1, 'R');

    EXPECT_THROW(checkTSIRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TSI_LENGTH, 'R');

    EXPECT_TRUE(checkTSIRange(minimumSize));

    std::string maximumSize(MAXIMUM_TSI_LENGTH, 'R');

    EXPECT_TRUE(checkTSIRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckTCRange){
    std::string empty;

    EXPECT_THROW(checkTCRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_TC_LENGTH + 1, 'R');

    EXPECT_THROW(checkTCRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TC_LENGTH, 'R');

    EXPECT_TRUE(checkTCRange(minimumSize));

    std::string maximumSize(MAXIMUM_TC_LENGTH, 'R');

    EXPECT_TRUE(checkTCRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckCIDRange){
    std::string empty;

    EXPECT_THROW(checkTCRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_TC_LENGTH + 1, 'R');

    EXPECT_THROW(checkTCRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TC_LENGTH, 'R');

    EXPECT_TRUE(checkTCRange(minimumSize));

    std::string maximumSize(MAXIMUM_TC_LENGTH, 'R');

    EXPECT_TRUE(checkTCRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckKVRRange){
    std::string empty;

    EXPECT_THROW(checkKVRRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_KVR_LENGTH + 1, 'R');

    EXPECT_THROW(checkKVRRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_KVR_LENGTH, 'R');

    EXPECT_TRUE(checkKVRRange(minimumSize));

    std::string maximumSize(MAXIMUM_KVR_LENGTH, 'R');

    EXPECT_TRUE(checkKVRRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckCDAResultRange){
    std::string empty;

    EXPECT_THROW(checkCDAResultRange(empty), std::invalid_argument);

    std::string overSize(MAXIMUM_CDARESULT_LENGTH + 1, 'R');

    EXPECT_THROW(checkCDAResultRange(overSize), std::invalid_argument);

    std::string minimumSize(MINIMUM_CDARESULT_LENGTH, 'R');

    EXPECT_TRUE(checkCDAResultRange(minimumSize));

    std::string maximumSize(MAXIMUM_CDARESULT_LENGTH, 'R');

    EXPECT_TRUE(checkCDAResultRange(maximumSize));
}
TEST(FieldsRangeChecker, CheckSalesCountRange){
    int64_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int64_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_THROW(checkSalesCountRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkSalesCountRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkSalesCountRange(MINIMUM_ARRAY_SIZE));
    EXPECT_TRUE(checkSalesCountRange(MAXIMUM_ARRAY_SIZE));

    EXPECT_TRUE(checkSalesCountRange(MINIMUM_ARRAY_SIZE + 1));
    EXPECT_TRUE(checkSalesCountRange(MAXIMUM_ARRAY_SIZE - 1));
}
TEST(FieldsRangeChecker, CheckVoidCountRange){
    int64_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int64_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_THROW(checkVoidCountRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkVoidCountRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkVoidCountRange(MINIMUM_ARRAY_SIZE));
    EXPECT_TRUE(checkVoidCountRange(MAXIMUM_ARRAY_SIZE));

    EXPECT_TRUE(checkVoidCountRange(MINIMUM_ARRAY_SIZE + 1));
    EXPECT_TRUE(checkVoidCountRange(MAXIMUM_ARRAY_SIZE - 1));
}
TEST(FieldsRangeChecker, CheckRefundCountRange){
    int64_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int64_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_THROW(checkRefundCountRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkRefundCountRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkRefundCountRange(MINIMUM_ARRAY_SIZE));
    EXPECT_TRUE(checkRefundCountRange(MAXIMUM_ARRAY_SIZE));

    EXPECT_TRUE(checkRefundCountRange(MINIMUM_ARRAY_SIZE + 1));
    EXPECT_TRUE(checkRefundCountRange(MAXIMUM_ARRAY_SIZE - 1));
}
TEST(FieldsRangeChecker, CheckNotiticationCodes){
    auto lessMinimum =  (int32_t)NotificationCodes::FirstValue - 1;
    auto greatMaximum = (int32_t)NotificationCodes::LastValue + 1;

    auto greatMinimum = (int32_t)NotificationCodes::FirstValue + 1;
    auto lessMaximum = (int32_t)NotificationCodes::LastValue - 1;

    EXPECT_THROW(checkNotificationsRange(lessMinimum), std::invalid_argument);
    EXPECT_THROW(checkNotificationsRange(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(checkNotificationsRange((int32_t)NotificationCodes::FirstValue));
    EXPECT_TRUE(checkNotificationsRange((int32_t)NotificationCodes::LastValue));

    EXPECT_TRUE(checkNotificationsRange(greatMinimum));
    EXPECT_TRUE(checkNotificationsRange(lessMaximum));
}