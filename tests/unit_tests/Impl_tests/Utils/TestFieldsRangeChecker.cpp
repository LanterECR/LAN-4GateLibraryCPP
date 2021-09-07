#include "gtest/gtest.h"
#include "Lanter/Utils/Constants.h"
#include "Lanter/Utils/FieldRangeChecker.h"
#include "Lanter/Message/OperationCode.h"
#include "Lanter/Message/Response/Status.h"
#include "Lanter/Message/Response/CardInputMethod.h"
#include "Lanter/Message/Response/CardholderAuthMethod.h"
#include "Lanter/Message/Notification/NotificationCode.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;
using namespace Lanter::Message::Notification;
using namespace Lanter::Utils;
using namespace Lanter::Utils::Constants;

TEST(TestFieldsRangeChecker, CheckEcrNumberRange){
    int64_t lessMinimum = MINIMUM_ECR_NUMBER - 1;
    int64_t greatMaximum = MAXIMUM_ECR_NUMBER + 1;

    EXPECT_FALSE(checkEcrNumberRange(lessMinimum));
    EXPECT_FALSE(checkEcrNumberRange(greatMaximum));

    EXPECT_TRUE(checkEcrNumberRange(MINIMUM_ECR_NUMBER));
    EXPECT_TRUE(checkEcrNumberRange(MAXIMUM_ECR_NUMBER));

    EXPECT_TRUE(checkEcrNumberRange(MINIMUM_ECR_NUMBER + 1));
    EXPECT_TRUE(checkEcrNumberRange(MAXIMUM_ECR_NUMBER - 1));
}
TEST(TestFieldsRangeChecker, CheckEcrMerchantNumberRange){
    int64_t lessMinimum = MINIMUM_ECR_MERCHANT_NUMBER - 1;
    int64_t greatMaximum = MAXIMUM_ECR_MERCHANT_NUMBER + 1;

    EXPECT_FALSE(checkEcrMerchantNumberRange(lessMinimum));
    EXPECT_FALSE(checkEcrMerchantNumberRange(greatMaximum));

    EXPECT_TRUE(checkEcrMerchantNumberRange(MINIMUM_ECR_NUMBER));
    EXPECT_TRUE(checkEcrMerchantNumberRange(MAXIMUM_ECR_NUMBER));

    EXPECT_TRUE(checkEcrMerchantNumberRange(MINIMUM_ECR_NUMBER + 1));
    EXPECT_TRUE(checkEcrMerchantNumberRange(MAXIMUM_ECR_NUMBER - 1));
}
TEST(TestFieldsRangeChecker, CheckOperationCodeRange){
    auto lessMinimum =  (int32_t)OperationCode::FirstValue - 1;
    auto greatMaximum = (int32_t)OperationCode::LastValue + 1;

    auto greatMinimum = (int32_t)OperationCode::FirstValue + 1;
    auto lessMaximum = (int32_t)OperationCode::LastValue - 1;

    EXPECT_FALSE(checkOperationCodeRange(lessMinimum));
    EXPECT_FALSE(checkOperationCodeRange(greatMaximum));

    EXPECT_TRUE(checkOperationCodeRange((int32_t)OperationCode::FirstValue));
    EXPECT_TRUE(checkOperationCodeRange((int32_t)OperationCode::LastValue));

    EXPECT_TRUE(checkOperationCodeRange(greatMinimum));
    EXPECT_TRUE(checkOperationCodeRange(lessMaximum));
}
TEST(TestFieldsRangeChecker, CheckAmountRange){
    int64_t lessMinimum = MINIMUM_AMOUNT - 1;
    int64_t greatMaximum = MAXIMUM_AMOUNT + 1;

    EXPECT_FALSE(checkAmountRange(lessMinimum));
    EXPECT_FALSE(checkAmountRange(greatMaximum));

    EXPECT_TRUE(checkAmountRange(MINIMUM_AMOUNT));
    EXPECT_TRUE(checkAmountRange(MAXIMUM_AMOUNT));

    EXPECT_TRUE(checkAmountRange(MINIMUM_AMOUNT + 1));
    EXPECT_TRUE(checkAmountRange(MAXIMUM_AMOUNT - 1));
}
TEST(TestFieldsRangeChecker, CheckCurrencyCodeRange){
    int64_t lessMinimum = MINIMUM_CURRENCY_CODE - 1;
    int64_t greatMaximum = MAXIMUM_CURRENCY_CODE + 1;

    EXPECT_FALSE(checkCurrencyCodeRange(lessMinimum));
    EXPECT_FALSE(checkCurrencyCodeRange(greatMaximum));

    EXPECT_TRUE(checkCurrencyCodeRange(MINIMUM_CURRENCY_CODE));
    EXPECT_TRUE(checkCurrencyCodeRange(MAXIMUM_CURRENCY_CODE));

    EXPECT_TRUE(checkAmountRange(MINIMUM_CURRENCY_CODE + 1));
    EXPECT_TRUE(checkAmountRange(MAXIMUM_CURRENCY_CODE - 1));
}
TEST(TestFieldsRangeChecker, CheckRRNRange){
    std::string empty;

    EXPECT_FALSE(checkRRNRange(empty));

    std::string overSize(MAXIMUM_RRN_LENGTH + 1, 'R');

    EXPECT_FALSE(checkRRNRange(overSize));

    std::string minimumSize(MINIMUM_RRN_LENGTH, 'R');

    EXPECT_TRUE(checkRRNRange(minimumSize));

    std::string maximumSize(MAXIMUM_RRN_LENGTH, 'R');

    EXPECT_TRUE(checkRRNRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckAuthCodeRange){
    std::string empty;

    EXPECT_FALSE(checkAuthCodeRange(empty));

    std::string overSize(MAXIMUM_AUTH_CODE_LENGTH + 1, 'R');

    EXPECT_FALSE(checkAuthCodeRange(overSize));

    std::string minimumSize(MINIMUM_AUTH_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkAuthCodeRange(minimumSize));

    std::string maximumSize(MAXIMUM_AUTH_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkAuthCodeRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckReceiptReferenceRange){
    std::string empty;

    EXPECT_FALSE(checkReceiptReferenceRange(empty));

    std::string overSize(MAXIMUM_RECEIPT_REFERENCE_LENGTH + 1, 'R');

    EXPECT_FALSE(checkReceiptReferenceRange(overSize));

    std::string minimumSize(MINIMUM_RECEIPT_REFERENCE_LENGTH, 'R');

    EXPECT_TRUE(checkReceiptReferenceRange(minimumSize));

    std::string maximumSize(MAXIMUM_RECEIPT_REFERENCE_LENGTH, 'R');

    EXPECT_TRUE(checkReceiptReferenceRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckTransactionIDRange){
    std::string empty;

    EXPECT_FALSE(checkTransactionIDRange(empty));

    std::string overSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH + 1, 'R');

    EXPECT_FALSE(checkTransactionIDRange(overSize));

    std::string minimumSize(MINIMUM_TRANSACTION_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTransactionIDRange(minimumSize));

    std::string maximumSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTransactionIDRange(maximumSize));
}

TEST(TestFieldsRangeChecker, CheckCardDataEncRange){
    std::string empty;

    EXPECT_FALSE(checkCardDataRange(empty));

    size_t len = 512;
    std::string notEmpty(len, 'R');

    EXPECT_TRUE(checkCardDataRange(notEmpty));
}

TEST(TestFieldsRangeChecker, CheckOpenTagsRange){
    std::string empty;

    EXPECT_FALSE(checkOpenTagsRange(empty));

    size_t len = 512;
    std::string notEmpty(len, 'R');

    EXPECT_TRUE(checkOpenTagsRange(notEmpty));
}
TEST(TestFieldsRangeChecker, CheckEncTagsRange){
    std::string empty;

    EXPECT_FALSE(checkEncTagsRange(empty));

    size_t len = 512;
    std::string notEmpty(len, 'R');

    EXPECT_TRUE(checkEncTagsRange(notEmpty));
}
TEST(TestFieldsRangeChecker, CheckProviderCodeRange){
    std::string empty;

    EXPECT_FALSE(checkProviderCodeRange(empty));

    std::string overSize(MAXIMUM_PROVIDER_CODE_LENGTH + 1, 'R');

    EXPECT_FALSE(checkProviderCodeRange(overSize));

    std::string minimumSize(MINIMUM_PROVIDER_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkProviderCodeRange(minimumSize));

    std::string maximumSize(MAXIMUM_PROVIDER_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkProviderCodeRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckAdditionalInfoRange){
    std::string empty;

    EXPECT_FALSE(checkAdditionalInfoRange(empty));

    size_t len = 512;
    std::string notEmpty(len, 'R');

    EXPECT_TRUE(checkAdditionalInfoRange(notEmpty));
}
TEST(TestFieldsRangeChecker, CheckStatusRange){
    auto lessMinimum =  (int32_t)Status::FirstValue - 1;
    auto greatMaximum = (int32_t)Status::LastValue + 1;

    auto greatMinimum = (int32_t)Status::FirstValue + 1;
    auto lessMaximum = (int32_t)Status::LastValue - 1;

    EXPECT_FALSE(checkStatusRange(lessMinimum));
    EXPECT_FALSE(checkStatusRange(greatMaximum));

    EXPECT_TRUE(checkStatusRange((int32_t)Status::FirstValue));
    EXPECT_TRUE(checkStatusRange((int32_t)Status::LastValue));

    EXPECT_TRUE(checkStatusRange(greatMinimum));
    EXPECT_TRUE(checkStatusRange(lessMaximum));
}
TEST(TestFieldsRangeChecker, CheckTransDateTimeRange){
    std::string empty;

    EXPECT_FALSE(checkTransDateTimeRange(empty));

    std::string overSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH + 1, 'R');

    EXPECT_FALSE(checkTransDateTimeRange(overSize));

    std::string minimumSize(MINIMUM_TRANSACTION_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTransDateTimeRange(minimumSize));

    std::string maximumSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTransDateTimeRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckTerminalDateTimeRange){
    std::string empty;

    EXPECT_FALSE(checkTerminalDateTimeRange(empty));

    std::string overSize(MAXIMUM_TERMINAL_DATETIME_LENGTH + 1, 'R');

    EXPECT_FALSE(checkTerminalDateTimeRange(overSize));

    std::string minimumSize(MINIMUM_TERMINAL_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTerminalDateTimeRange(minimumSize));

    std::string maximumSize(MAXIMUM_TERMINAL_DATETIME_LENGTH, 'R');

    EXPECT_TRUE(checkTerminalDateTimeRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckCardPANRange){
    std::string empty;

    EXPECT_FALSE(checkCardPANRange(empty));

    std::string overSize(MAXIMUM_CARD_PAN_LENGTH + 1, 'R');

    EXPECT_FALSE(checkCardPANRange(overSize));

    std::string minimumSize(MINIMUM_CARD_PAN_LENGTH, 'R');

    EXPECT_TRUE(checkCardPANRange(minimumSize));

    std::string maximumSize(MAXIMUM_CARD_PAN_LENGTH, 'R');

    EXPECT_TRUE(checkCardPANRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckExpireDateRange){
    std::string empty;

    EXPECT_FALSE(checkExpireDateRange(empty));

    std::string overSize(MAXIMUM_EXPIRE_DATE_LENGTH + 1, 'R');

    EXPECT_FALSE(checkExpireDateRange(overSize));

    std::string minimumSize(MINIMUM_EXPIRE_DATE_LENGTH, 'R');

    EXPECT_TRUE(checkExpireDateRange(minimumSize));

    std::string maximumSize(MAXIMUM_EXPIRE_DATE_LENGTH, 'R');

    EXPECT_TRUE(checkExpireDateRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckCardholderNameRange){
    std::string empty;

    EXPECT_FALSE(checkCardholderNameRange(empty));

    std::string overSize(MAXIMUM_CARDHOLDER_NAME_LENGTH + 1, 'R');

    EXPECT_FALSE(checkCardholderNameRange(overSize));

    std::string minimumSize(MINIMUM_CARDHOLDER_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkCardholderNameRange(minimumSize));

    std::string maximumSize(MINIMUM_CARDHOLDER_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkCardholderNameRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckCardholderAuthMethodRange){
    auto lessMinimum =  (int32_t)CardholderAuthMethod::FirstValue - 1;
    auto greatMaximum = (int32_t)CardholderAuthMethod::LastValue + 1;

    auto greatMinimum = (int32_t)CardholderAuthMethod::FirstValue + 1;
    auto lessMaximum = (int32_t)CardholderAuthMethod::LastValue - 1;

    EXPECT_FALSE(checkCardholderAuthMethodRange(lessMinimum));
    EXPECT_FALSE(checkCardholderAuthMethodRange(greatMaximum));

    EXPECT_TRUE(checkCardholderAuthMethodRange((int32_t)CardholderAuthMethod::FirstValue));
    EXPECT_TRUE(checkCardholderAuthMethodRange((int32_t)CardholderAuthMethod::LastValue));

    EXPECT_TRUE(checkCardholderAuthMethodRange(greatMinimum));
    EXPECT_TRUE(checkCardholderAuthMethodRange(lessMaximum));
}
TEST(TestFieldsRangeChecker, CheckResponseCodeRange){
    std::string empty;

    EXPECT_FALSE(checkResponseCodeRange(empty));

    std::string overSize(MAXIMUM_RESPONSE_CODE_LENGTH + 1, 'R');

    EXPECT_FALSE(checkResponseCodeRange(overSize));

    std::string minimumSize(MINIMUM_RESPONSE_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkResponseCodeRange(minimumSize));

    std::string maximumSize(MAXIMUM_RESPONSE_CODE_LENGTH, 'R');

    EXPECT_TRUE(checkResponseCodeRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckResponseTextRange){
    std::string empty;

    EXPECT_FALSE(checkResponseTextRange(empty));

    std::string overSize(MAXIMUM_RESPONSE_TEXT_LENGTH + 1, 'R');

    EXPECT_FALSE(checkResponseTextRange(overSize));

    std::string minimumSize(MINIMUM_RESPONSE_TEXT_LENGTH, 'R');

    EXPECT_TRUE(checkResponseTextRange(minimumSize));

    std::string maximumSize(MAXIMUM_RESPONSE_TEXT_LENGTH, 'R');

    EXPECT_TRUE(checkResponseTextRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckSTANRange){
    std::string empty;

    EXPECT_FALSE(checkSTANRange(empty));

    std::string overSize(MAXIMUM_STAN_LENGTH + 1, 'R');

    EXPECT_FALSE(checkSTANRange(overSize));

    std::string minimumSize(MINIMUM_STAN_LENGTH, 'R');

    EXPECT_TRUE(checkSTANRange(minimumSize));

    std::string maximumSize(MAXIMUM_STAN_LENGTH, 'R');

    EXPECT_TRUE(checkSTANRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckTerminalIDRange){
    std::string empty;

    EXPECT_FALSE(checkTerminalIDRange(empty));

    std::string overSize(MAXIMUM_TERMINAL_ID_LENGTH + 1, 'R');

    EXPECT_FALSE(checkTerminalIDRange(overSize));

    std::string minimumSize(MINIMUM_TERMINAL_ID_LENGTH, 'R');

    EXPECT_TRUE(checkTerminalIDRange(minimumSize));

    std::string maximumSize(MAXIMUM_TERMINAL_ID_LENGTH, 'R');

    EXPECT_TRUE(checkTerminalIDRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckCardEmvAidRange){
    std::string empty;

    EXPECT_FALSE(checkCardEmvAidRange(empty));

    std::string overSize(MAXIMUM_CARD_EMV_AID_LENGTH + 1, 'R');

    EXPECT_FALSE(checkCardEmvAidRange(overSize));

    std::string minimumSize(MINIMUM_CARD_EMV_AID_LENGTH, 'R');

    EXPECT_TRUE(checkCardEmvAidRange(minimumSize));

    std::string maximumSize(MAXIMUM_CARD_EMV_AID_LENGTH, 'R');

    EXPECT_TRUE(checkCardEmvAidRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckCardAppNameRange){
    std::string empty;

    EXPECT_FALSE(checkCardAppNameRange(empty));

    std::string overSize(MAXIMUM_CARD_APP_NAME_LENGTH + 1, 'R');

    EXPECT_FALSE(checkCardAppNameRange(overSize));

    std::string minimumSize(MINIMUM_CARD_APP_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkCardAppNameRange(minimumSize));

    std::string maximumSize(MAXIMUM_CARD_APP_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkCardAppNameRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckCardInputMethodRange){
    auto lessMinimum =  (int32_t)CardInputMethod::FirstValue - 1;
    auto greatMaximum = (int32_t)CardInputMethod::LastValue + 1;

    auto greatMinimum = (int32_t)CardInputMethod::FirstValue + 1;
    auto lessMaximum = (int32_t)CardInputMethod::LastValue - 1;

    EXPECT_FALSE(checkCardInputMethodRange(lessMinimum));
    EXPECT_FALSE(checkCardInputMethodRange(greatMaximum));

    EXPECT_TRUE(checkCardInputMethodRange((int32_t)CardInputMethod::FirstValue));
    EXPECT_TRUE(checkCardInputMethodRange((int32_t)CardInputMethod::LastValue));

    EXPECT_TRUE(checkCardInputMethodRange(greatMinimum));
    EXPECT_TRUE(checkCardInputMethodRange(lessMaximum));
}
TEST(TestFieldsRangeChecker, CheckIssuerNameRange){
    std::string empty;

    EXPECT_FALSE(checkIssuerNameRange(empty));

    std::string overSize(MAXIMUM_ISSUER_NAME_LENGTH + 1, 'R');

    EXPECT_FALSE(checkIssuerNameRange(overSize));

    std::string minimumSize(MINIMUM_ISSUER_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkIssuerNameRange(minimumSize));

    std::string maximumSize(MAXIMUM_ISSUER_NAME_LENGTH, 'R');

    EXPECT_TRUE(checkIssuerNameRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckCardDataRange){
    std::string empty;

    EXPECT_FALSE(checkCardDataRange(empty));

    std::string notEmpty( 512, 'R');

    EXPECT_TRUE(checkResponseCodeRange(notEmpty));
}
TEST(TestFieldsRangeChecker, CheckMerchantIDRange){
    std::string empty;

    EXPECT_FALSE(checkMerchantIDRange(empty));

    std::string overSize(MAXIMUM_MERCHANT_ID_LENGTH + 1, 'R');

    EXPECT_FALSE(checkMerchantIDRange(overSize));

    std::string minimumSize(MINIMUM_MERCHANT_ID_LENGTH, 'R');

    EXPECT_TRUE(checkMerchantIDRange(minimumSize));

    std::string maximumSize(MAXIMUM_MERCHANT_ID_LENGTH, 'R');

    EXPECT_TRUE(checkMerchantIDRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckTVRRange){
    std::string empty;

    EXPECT_FALSE(checkTVRRange(empty));

    std::string overSize(MAXIMUM_TVR_LENGTH + 1, 'R');

    EXPECT_FALSE(checkTVRRange(overSize));

    std::string minimumSize(MINIMUM_TVR_LENGTH, 'R');

    EXPECT_TRUE(checkTVRRange(minimumSize));

    std::string maximumSize(MAXIMUM_TVR_LENGTH, 'R');

    EXPECT_TRUE(checkTVRRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckTSIRange){
    std::string empty;

    EXPECT_FALSE(checkTSIRange(empty));

    std::string overSize(MAXIMUM_TSI_LENGTH + 1, 'R');

    EXPECT_FALSE(checkTSIRange(overSize));

    std::string minimumSize(MINIMUM_TSI_LENGTH, 'R');

    EXPECT_TRUE(checkTSIRange(minimumSize));

    std::string maximumSize(MAXIMUM_TSI_LENGTH, 'R');

    EXPECT_TRUE(checkTSIRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckTCRange){
    std::string empty;

    EXPECT_FALSE(checkTCRange(empty));

    std::string overSize(MAXIMUM_TC_LENGTH + 1, 'R');

    EXPECT_FALSE(checkTCRange(overSize));

    std::string minimumSize(MINIMUM_TC_LENGTH, 'R');

    EXPECT_TRUE(checkTCRange(minimumSize));

    std::string maximumSize(MAXIMUM_TC_LENGTH, 'R');

    EXPECT_TRUE(checkTCRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckCIDRange){
    std::string empty;

    EXPECT_FALSE(checkTCRange(empty));

    std::string overSize(MAXIMUM_TC_LENGTH + 1, 'R');

    EXPECT_FALSE(checkTCRange(overSize));

    std::string minimumSize(MINIMUM_TC_LENGTH, 'R');

    EXPECT_TRUE(checkTCRange(minimumSize));

    std::string maximumSize(MAXIMUM_TC_LENGTH, 'R');

    EXPECT_TRUE(checkTCRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckKVRRange){
    std::string empty;

    EXPECT_FALSE(checkKVRRange(empty));

    std::string overSize(MAXIMUM_KVR_LENGTH + 1, 'R');

    EXPECT_FALSE(checkKVRRange(overSize));

    std::string minimumSize(MINIMUM_KVR_LENGTH, 'R');

    EXPECT_TRUE(checkKVRRange(minimumSize));

    std::string maximumSize(MAXIMUM_KVR_LENGTH, 'R');

    EXPECT_TRUE(checkKVRRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckCDAResultRange){
    std::string empty;

    EXPECT_FALSE(checkCDAResultRange(empty));

    std::string overSize(MAXIMUM_CDARESULT_LENGTH + 1, 'R');

    EXPECT_FALSE(checkCDAResultRange(overSize));

    std::string minimumSize(MINIMUM_CDARESULT_LENGTH, 'R');

    EXPECT_TRUE(checkCDAResultRange(minimumSize));

    std::string maximumSize(MAXIMUM_CDARESULT_LENGTH, 'R');

    EXPECT_TRUE(checkCDAResultRange(maximumSize));
}
TEST(TestFieldsRangeChecker, CheckSalesCountRange){
    int64_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int64_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_FALSE(checkSalesCountRange(lessMinimum));
    EXPECT_FALSE(checkSalesCountRange(greatMaximum));

    EXPECT_TRUE(checkSalesCountRange(MINIMUM_ARRAY_SIZE));
    EXPECT_TRUE(checkSalesCountRange(MAXIMUM_ARRAY_SIZE));

    EXPECT_TRUE(checkSalesCountRange(MINIMUM_ARRAY_SIZE + 1));
    EXPECT_TRUE(checkSalesCountRange(MAXIMUM_ARRAY_SIZE - 1));
}
TEST(TestFieldsRangeChecker, CheckVoidCountRange){
    int64_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int64_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_FALSE(checkVoidCountRange(lessMinimum));
    EXPECT_FALSE(checkVoidCountRange(greatMaximum));

    EXPECT_TRUE(checkVoidCountRange(MINIMUM_ARRAY_SIZE));
    EXPECT_TRUE(checkVoidCountRange(MAXIMUM_ARRAY_SIZE));

    EXPECT_TRUE(checkVoidCountRange(MINIMUM_ARRAY_SIZE + 1));
    EXPECT_TRUE(checkVoidCountRange(MAXIMUM_ARRAY_SIZE - 1));
}
TEST(TestFieldsRangeChecker, CheckRefundCountRange){
    int64_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int64_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_FALSE(checkRefundCountRange(lessMinimum));
    EXPECT_FALSE(checkRefundCountRange(greatMaximum));

    EXPECT_TRUE(checkRefundCountRange(MINIMUM_ARRAY_SIZE));
    EXPECT_TRUE(checkRefundCountRange(MAXIMUM_ARRAY_SIZE));

    EXPECT_TRUE(checkRefundCountRange(MINIMUM_ARRAY_SIZE + 1));
    EXPECT_TRUE(checkRefundCountRange(MAXIMUM_ARRAY_SIZE - 1));
}
TEST(TestFieldsRangeChecker, CheckNotiticationCodes){
    auto lessMinimum =  (int32_t)NotificationCode::FirstValue - 1;
    auto greatMaximum = (int32_t)NotificationCode::LastValue + 1;

    auto greatMinimum = (int32_t)NotificationCode::FirstValue + 1;
    auto lessMaximum = (int32_t)NotificationCode::LastValue - 1;

    EXPECT_FALSE(checkNotificationsRange(lessMinimum));
    EXPECT_FALSE(checkNotificationsRange(greatMaximum));

    EXPECT_TRUE(checkNotificationsRange((int32_t)NotificationCode::FirstValue));
    EXPECT_TRUE(checkNotificationsRange((int32_t)NotificationCode::LastValue));

    EXPECT_TRUE(checkNotificationsRange(greatMinimum));
    EXPECT_TRUE(checkNotificationsRange(lessMaximum));
}