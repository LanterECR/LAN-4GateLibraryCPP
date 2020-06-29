//
// Created by Владимир Лысенков on 29.06.2020.
//
#include "gtest/gtest.h"
#include "Lanter/Response/ResponseData.h"
#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Response;
using namespace Lanter::Utils::Constants;

TEST(ResponseData, CheckEcrNumber) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ECR_NUMBER - 1;
    int16_t greatMaximum = MAXIMUM_ECR_NUMBER + 1;

    EXPECT_THROW(data.setEcrNumber(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setEcrNumber(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getEcrNumber(), -1);

    EXPECT_NO_THROW(data.setEcrNumber(MINIMUM_ECR_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), MINIMUM_ECR_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::EcrNumber), data.getFieldsSet().end());

    EXPECT_NO_THROW(data.setEcrNumber(MAXIMUM_ECR_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), MAXIMUM_ECR_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::EcrNumber), data.getFieldsSet().end());
}

TEST(ResponseData, CheckEcrMerchantNumber) {
    ResponseData data;

    int16_t lessMinimum = MINIMUM_ECR_MERCHANT_NUMBER - 1;
    int16_t greatMaximum = MAXIMUM_ECR_MERCHANT_NUMBER + 1;

    EXPECT_THROW(data.setEcrMerchantNumber(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setEcrMerchantNumber(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getEcrMerchantNumber(), -1);

    EXPECT_NO_THROW(data.setEcrMerchantNumber(MINIMUM_ECR_MERCHANT_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), MINIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::EcrMerchantNumber), data.getFieldsSet().end());

    EXPECT_NO_THROW(data.setEcrMerchantNumber(MAXIMUM_ECR_MERCHANT_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), MAXIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::EcrMerchantNumber), data.getFieldsSet().end());
}

TEST(ResponseData, CheckOperationCode) {
    ResponseData data;

    auto greatMaximum = (OperationCodes)((int)(OperationCodes::LastValue) + 1);
    EXPECT_THROW(data.setOperationCode(OperationCodes::NoOperation), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);
    EXPECT_THROW(data.setOperationCode(greatMaximum), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOperationCode(), OperationCodes::NoOperation);

    EXPECT_NO_THROW(data.setOperationCode(OperationCodes::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOperationCode(), OperationCodes::FirstValue);

    EXPECT_NO_THROW(data.setOperationCode(OperationCodes::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOperationCode(), OperationCodes::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::OperationCode), data.getFieldsSet().end());
}

TEST(ResponseData, CheckOriginalOperationCode) {
    ResponseData data;

    auto greatMaximum = (OperationCodes)((int)(OperationCodes::LastValue) + 1);
    EXPECT_THROW(data.setOriginalOperationCode(OperationCodes::NoOperation), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);
    EXPECT_THROW(data.setOriginalOperationCode(greatMaximum), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOriginalOperationCode(), OperationCodes::NoOperation);

    EXPECT_NO_THROW(data.setOriginalOperationCode(OperationCodes::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationCode(), OperationCodes::FirstValue);

    EXPECT_NO_THROW(data.setOriginalOperationCode(OperationCodes::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationCode(), OperationCodes::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::OriginalOperationCode), data.getFieldsSet().end());
}

TEST(ResponseData, CheckAllAmount) {
    ResponseData data;

    int64_t lessMinimum = MINIMUM_AMOUNT - 1;
    int64_t greatMaximum = MAXIMUM_AMOUNT + 1;

    int fieldsCount = 0;
    //TotalAmount
    EXPECT_THROW(data.setTotalAmount(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setTotalAmount(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getTotalAmount(), -1);
    ++fieldsCount;
    EXPECT_NO_THROW(data.setTotalAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTotalAmount(), MINIMUM_AMOUNT);
    EXPECT_NO_THROW(data.setTotalAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTotalAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TotalAmount), data.getFieldsSet().end());

    //ParialAmount
    EXPECT_EQ(data.getPartialAmount(), -1);
    ++fieldsCount;
    EXPECT_NO_THROW(data.setPartialAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), MINIMUM_AMOUNT);
    EXPECT_NO_THROW(data.setPartialAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::PartialAmount), data.getFieldsSet().end());

    //TipsAmount
    EXPECT_EQ(data.getTipsAmount(), -1);
    ++fieldsCount;
    EXPECT_NO_THROW(data.setTipsAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), MINIMUM_AMOUNT);
    EXPECT_NO_THROW(data.setTipsAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TipsAmount), data.getFieldsSet().end());

    //AcquirerFeeAmount
    EXPECT_EQ(data.getAcquirerFeeAmount(), -1);
    ++fieldsCount;
    EXPECT_NO_THROW(data.setAcquirerFeeAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getAcquirerFeeAmount(), MINIMUM_AMOUNT);
    EXPECT_NO_THROW(data.setAcquirerFeeAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getAcquirerFeeAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::AmountAcquirerFee), data.getFieldsSet().end());

    //TerminalFeeAmount
    EXPECT_EQ(data.getTerminalFeeAmount(), -1);
    ++fieldsCount;
    EXPECT_NO_THROW(data.setTerminalFeeAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTerminalFeeAmount(), MINIMUM_AMOUNT);
    EXPECT_NO_THROW(data.setTerminalFeeAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTerminalFeeAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::AmountTerminalFee), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCurrencyCode) {
    ResponseData data;

    int16_t lessMinimum = MINIMUM_CURRENCY_CODE - 1;
    int16_t greatMaximum = MAXIMUM_CURRENCY_CODE + 1;

    EXPECT_THROW(data.setCurrencyCode(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setCurrencyCode(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getCurrencyCode(), -1);

    EXPECT_NO_THROW(data.setCurrencyCode(MINIMUM_CURRENCY_CODE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), MINIMUM_CURRENCY_CODE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CurrencyCode), data.getFieldsSet().end());

    EXPECT_NO_THROW(data.setCurrencyCode(MAXIMUM_CURRENCY_CODE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), MAXIMUM_CURRENCY_CODE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CurrencyCode), data.getFieldsSet().end());
}

TEST(ResponseData, CheckReceiptReference) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setReceiptReference(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getReceiptReference().empty());

    std::string oversize(MAXIMUM_RECEIPT_REFERENCE_LENGTH + 1, '0');
    EXPECT_THROW(data.setReceiptReference(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_RECEIPT_REFERENCE_LENGTH, '0');
    EXPECT_NO_THROW(data.setReceiptReference(minimumSize));
    EXPECT_STREQ(data.getReceiptReference().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_RECEIPT_REFERENCE_LENGTH, '0');
    EXPECT_NO_THROW(data.setReceiptReference(maximumSize));
    EXPECT_STREQ(data.getReceiptReference().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::ReceiptReference), data.getFieldsSet().end());
}

TEST(ResponseData, CheckRRN) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setRRN(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getRRN().empty());

    std::string oversize(MAXIMUM_RRN_LENGTH + 1, '0');
    EXPECT_THROW(data.setRRN(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_RRN_LENGTH, '0');
    EXPECT_NO_THROW(data.setRRN(minimumSize));
    EXPECT_STREQ(data.getRRN().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_RRN_LENGTH, '0');
    EXPECT_NO_THROW(data.setRRN(maximumSize));
    EXPECT_STREQ(data.getRRN().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::RRN), data.getFieldsSet().end());
}

TEST(ResponseData, CheckStatus) {
    ResponseData data;

    auto greatMaximum = (Status)((int)(Status::LastValue) + 1);
    EXPECT_THROW(data.setStatus(Status::NoStatus), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_THROW(data.setStatus(greatMaximum), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getStatus(), Status::NoStatus);

    EXPECT_NO_THROW(data.setStatus(Status::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getStatus(), Status::FirstValue);

    EXPECT_NO_THROW(data.setStatus(Status::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getStatus(), Status::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::Status), data.getFieldsSet().end());
}

TEST(ResponseData, CheckOriginalOperationStatus) {
    ResponseData data;

    auto greatMaximum = (Status)((int)(Status::LastValue) + 1);
    EXPECT_THROW(data.setOriginalOperationStatus(Status::NoStatus), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_THROW(data.setOriginalOperationStatus(greatMaximum), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOriginalOperationStatus(), Status::NoStatus);

    EXPECT_NO_THROW(data.setOriginalOperationStatus(Status::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationStatus(), Status::FirstValue);

    EXPECT_NO_THROW(data.setOriginalOperationStatus(Status::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationStatus(), Status::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::OriginalOperationStatus), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTransDateTime) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setTransDateTime(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTransDateTime().empty());

    std::string oversize(MAXIMUM_TRANSACTION_DATETIME_LENGTH + 1, '0');
    EXPECT_THROW(data.setTransDateTime(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TRANSACTION_DATETIME_LENGTH, '0');
    EXPECT_NO_THROW(data.setTransDateTime(minimumSize));
    EXPECT_STREQ(data.getTransDateTime().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH, '0');
    EXPECT_NO_THROW(data.setTransDateTime(maximumSize));
    EXPECT_STREQ(data.getTransDateTime().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TransDateTime), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTerminalDateTime) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setTerminalDateTime(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTerminalDateTime().empty());

    std::string oversize(MAXIMUM_TERMINAL_DATETIME_LENGTH + 1, '0');
    EXPECT_THROW(data.setTerminalDateTime(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TERMINAL_DATETIME_LENGTH, '0');
    EXPECT_NO_THROW(data.setTerminalDateTime(minimumSize));
    EXPECT_STREQ(data.getTerminalDateTime().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TERMINAL_DATETIME_LENGTH, '0');
    EXPECT_NO_THROW(data.setTerminalDateTime(maximumSize));
    EXPECT_STREQ(data.getTerminalDateTime().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TerminalDateTime), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardPan) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setCardPan(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardPan().empty());

    std::string oversize(MAXIMUM_CARD_PAN_LENGTH + 1, '0');
    EXPECT_THROW(data.setCardPan(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_CARD_PAN_LENGTH, '0');
    EXPECT_NO_THROW(data.setCardPan(minimumSize));
    EXPECT_STREQ(data.getCardPan().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CARD_PAN_LENGTH, '0');
    EXPECT_NO_THROW(data.setCardPan(maximumSize));
    EXPECT_STREQ(data.getCardPan().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardPAN), data.getFieldsSet().end());
}

TEST(ResponseData, CheckExpireDate) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setExpireDate(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getExpireDate().empty());

    std::string oversize(MAXIMUM_EXPIRE_DATE_LENGTH + 1, '0');
    EXPECT_THROW(data.setExpireDate(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_EXPIRE_DATE_LENGTH, '0');
    EXPECT_NO_THROW(data.setExpireDate(minimumSize));
    EXPECT_STREQ(data.getExpireDate().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_EXPIRE_DATE_LENGTH, '0');
    EXPECT_NO_THROW(data.setExpireDate(maximumSize));
    EXPECT_STREQ(data.getExpireDate().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::ExpireDate), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardholderName) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setCardholderName(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardholderName().empty());

    std::string oversize(MAXIMUM_CARDHOLDER_NAME_LENGTH + 1, '0');
    EXPECT_THROW(data.setCardholderName(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_CARDHOLDER_NAME_LENGTH, '0');
    EXPECT_NO_THROW(data.setCardholderName(minimumSize));
    EXPECT_STREQ(data.getCardholderName().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CARDHOLDER_NAME_LENGTH, '0');
    EXPECT_NO_THROW(data.setCardholderName(maximumSize));
    EXPECT_STREQ(data.getCardholderName().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardholderName), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardholderAuthMethod) {
    ResponseData data;

    auto greatMaximum = (CardholderAuthMethod)((int)(CardholderAuthMethod::LastValue) + 1);
    EXPECT_THROW(data.setCardholderAuthMethod(CardholderAuthMethod::NoMethod), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_THROW(data.setCardholderAuthMethod(greatMaximum), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getCardholderAuthMethod(), CardholderAuthMethod::NoMethod);

    EXPECT_NO_THROW(data.setCardholderAuthMethod(CardholderAuthMethod::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCardholderAuthMethod(), CardholderAuthMethod::FirstValue);

    EXPECT_NO_THROW(data.setCardholderAuthMethod(CardholderAuthMethod::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCardholderAuthMethod(), CardholderAuthMethod::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardholderAuthMethod), data.getFieldsSet().end());
}

TEST(ResponseData, CheckAuthCode) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setAuthCode(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getAuthCode().empty());

    std::string oversize(MAXIMUM_AUTH_CODE_LENGTH + 1, '0');
    EXPECT_THROW(data.setAuthCode(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_AUTH_CODE_LENGTH, '0');
    EXPECT_NO_THROW(data.setAuthCode(minimumSize));
    EXPECT_STREQ(data.getAuthCode().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_AUTH_CODE_LENGTH, '0');
    EXPECT_NO_THROW(data.setAuthCode(maximumSize));
    EXPECT_STREQ(data.getAuthCode().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::AuthCode), data.getFieldsSet().end());
}

TEST(ResponseData, CheckResponseCode) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setResponseCode(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getResponseCode().empty());

    std::string oversize(MAXIMUM_RESPONSE_CODE_LENGTH + 1, '0');
    EXPECT_THROW(data.setResponseCode(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_RESPONSE_CODE_LENGTH, '0');
    EXPECT_NO_THROW(data.setResponseCode(minimumSize));
    EXPECT_STREQ(data.getResponseCode().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_RESPONSE_CODE_LENGTH, '0');
    EXPECT_NO_THROW(data.setResponseCode(maximumSize));
    EXPECT_STREQ(data.getResponseCode().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::ResponseCode), data.getFieldsSet().end());
}

TEST(ResponseData, CheckResponseText) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setResponseText(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getResponseText().empty());

    std::string oversize(MAXIMUM_RESPONSE_TEXT_LENGTH + 1, '0');
    EXPECT_THROW(data.setResponseText(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_RESPONSE_TEXT_LENGTH, '0');
    EXPECT_NO_THROW(data.setResponseText(minimumSize));
    EXPECT_STREQ(data.getResponseText().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_RESPONSE_TEXT_LENGTH, '0');
    EXPECT_NO_THROW(data.setResponseText(maximumSize));
    EXPECT_STREQ(data.getResponseText().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::ResponseText), data.getFieldsSet().end());
}

TEST(ResponseData, CheckSTAN) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setSTAN(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getSTAN().empty());

    std::string oversize(MAXIMUM_STAN_LENGTH + 1, '0');
    EXPECT_THROW(data.setSTAN(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_STAN_LENGTH, '0');
    EXPECT_NO_THROW(data.setSTAN(minimumSize));
    EXPECT_STREQ(data.getSTAN().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_STAN_LENGTH, '0');
    EXPECT_NO_THROW(data.setSTAN(maximumSize));
    EXPECT_STREQ(data.getSTAN().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::STAN), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTransactionID) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setTransactionID(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTransactionID().empty());

    std::string oversize(MAXIMUM_TRANSACTION_ID_LENGTH + 1, '0');
    EXPECT_THROW(data.setTransactionID(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TRANSACTION_ID_LENGTH, '0');
    EXPECT_NO_THROW(data.setTransactionID(minimumSize));
    EXPECT_STREQ(data.getTransactionID().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TRANSACTION_ID_LENGTH, '0');
    EXPECT_NO_THROW(data.setTransactionID(maximumSize));
    EXPECT_STREQ(data.getTransactionID().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TransactionID), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTerminalId) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setTerminalID(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTerminalID().empty());

    std::string oversize(MAXIMUM_TERMINAL_ID_LENGTH + 1, '0');
    EXPECT_THROW(data.setTerminalID(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TERMINAL_ID_LENGTH, '0');
    EXPECT_NO_THROW(data.setTerminalID(minimumSize));
    EXPECT_STREQ(data.getTerminalID().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TERMINAL_ID_LENGTH, '0');
    EXPECT_NO_THROW(data.setTerminalID(maximumSize));
    EXPECT_STREQ(data.getTerminalID().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TerminalID), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardEmvAid) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setCardEmvAid(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardEmvAid().empty());

    std::string oversize(MAXIMUM_EMV_AID_LENGTH + 1, '0');
    EXPECT_THROW(data.setCardEmvAid(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_EMV_AID_LENGTH, '0');
    EXPECT_NO_THROW(data.setCardEmvAid(minimumSize));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_EMV_AID_LENGTH, '0');
    EXPECT_NO_THROW(data.setCardEmvAid(maximumSize));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardEmvAid), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardAppName) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setCardAppName(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardAppName().empty());

    std::string oversize(MAXIMUM_CARD_APP_NAME_LENGTH + 1, '0');
    EXPECT_THROW(data.setCardAppName(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_CARD_APP_NAME_LENGTH, '0');
    EXPECT_NO_THROW(data.setCardAppName(minimumSize));
    EXPECT_STREQ(data.getCardAppName().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CARD_APP_NAME_LENGTH, '0');
    EXPECT_NO_THROW(data.setCardAppName(maximumSize));
    EXPECT_STREQ(data.getCardAppName().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardAppName), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardInputMethod) {
    ResponseData data;

    auto greatMaximum = (CardInputMethod)((int)(CardInputMethod::LastValue) + 1);
    EXPECT_THROW(data.setCardInputMethod(CardInputMethod::NoMethod), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_THROW(data.setCardInputMethod(greatMaximum), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getCardInputMethod(), CardInputMethod::NoMethod);

    EXPECT_NO_THROW(data.setCardInputMethod(CardInputMethod::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCardInputMethod(), CardInputMethod::FirstValue);

    EXPECT_NO_THROW(data.setCardInputMethod(CardInputMethod::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCardInputMethod(), CardInputMethod::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardInputMethod), data.getFieldsSet().end());
}

TEST(ResponseData, CheckIssuerName) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setIssuerName(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getIssuerName().empty());

    std::string oversize(MAXIMUM_ISSUER_NAME_LENGTH + 1, '0');
    EXPECT_THROW(data.setIssuerName(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_ISSUER_NAME_LENGTH, '0');
    EXPECT_NO_THROW(data.setIssuerName(minimumSize));
    EXPECT_STREQ(data.getIssuerName().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_ISSUER_NAME_LENGTH, '0');
    EXPECT_NO_THROW(data.setIssuerName(maximumSize));
    EXPECT_STREQ(data.getIssuerName().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::IssuerName), data.getFieldsSet().end());
}

TEST(ResponseData, CheckAdditionalInfo) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setAdditionalInfo(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getAdditionalInfo().empty());

    std::string value(512, '0');
    EXPECT_NO_THROW(data.setAdditionalInfo(value));
    EXPECT_STRCASEEQ(data.getAdditionalInfo().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::AdditionalInfo), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardData) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setCardData(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardData().empty());

    std::string value(512, '0');
    EXPECT_NO_THROW(data.setCardData(value));
    EXPECT_STRCASEEQ(data.getCardData().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardData), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardDataEnc) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setCardDataEnc(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardDataEnc().empty());

    std::string value(512, '0');
    EXPECT_NO_THROW(data.setCardDataEnc(value));
    EXPECT_STRCASEEQ(data.getCardDataEnc().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardDataEnc), data.getFieldsSet().end());
}

TEST(ResponseData, CheckMerchantID) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setMerchantID(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getMerchantID().empty());

    std::string oversize(MAXIMUM_MERCHANT_ID_LENGTH + 1, '0');
    EXPECT_THROW(data.setMerchantID(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_MERCHANT_ID_LENGTH, '0');
    EXPECT_NO_THROW(data.setMerchantID(minimumSize));
    EXPECT_STREQ(data.getMerchantID().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_MERCHANT_ID_LENGTH, '0');
    EXPECT_NO_THROW(data.setMerchantID(maximumSize));
    EXPECT_STREQ(data.getMerchantID().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::MerchantID), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTVR) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setTVR(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTVR().empty());

    std::string oversize(MAXIMUM_TVR_LENGTH + 1, '0');
    EXPECT_THROW(data.setTVR(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TVR_LENGTH, '0');
    EXPECT_NO_THROW(data.setTVR(minimumSize));
    EXPECT_STREQ(data.getTVR().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TVR_LENGTH, '0');
    EXPECT_NO_THROW(data.setTVR(maximumSize));
    EXPECT_STREQ(data.getTVR().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TVR), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTSI) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setTSI(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTSI().empty());

    std::string oversize(MAXIMUM_TSI_LENGTH + 1, '0');
    EXPECT_THROW(data.setTSI(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TSI_LENGTH, '0');
    EXPECT_NO_THROW(data.setTSI(minimumSize));
    EXPECT_STREQ(data.getTSI().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TSI_LENGTH, '0');
    EXPECT_NO_THROW(data.setTSI(maximumSize));
    EXPECT_STREQ(data.getTSI().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TSI), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTC) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setTC(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTC().empty());

    std::string oversize(MAXIMUM_TC_LENGTH + 1, '0');
    EXPECT_THROW(data.setTC(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_TC_LENGTH, '0');
    EXPECT_NO_THROW(data.setTC(minimumSize));
    EXPECT_STREQ(data.getTC().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TC_LENGTH, '0');
    EXPECT_NO_THROW(data.setTC(maximumSize));
    EXPECT_STREQ(data.getTC().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TC), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCID) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setCID(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCID().empty());

    std::string oversize(MAXIMUM_CID_LENGTH + 1, '0');
    EXPECT_THROW(data.setCID(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_CID_LENGTH, '0');
    EXPECT_NO_THROW(data.setCID(minimumSize));
    EXPECT_STREQ(data.getCID().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CID_LENGTH, '0');
    EXPECT_NO_THROW(data.setCID(maximumSize));
    EXPECT_STREQ(data.getCID().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CID), data.getFieldsSet().end());
}

TEST(ResponseData, CheckKVR) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setKVR(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getKVR().empty());

    std::string oversize(MAXIMUM_KVR_LENGTH + 1, '0');
    EXPECT_THROW(data.setKVR(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_KVR_LENGTH, '0');
    EXPECT_NO_THROW(data.setKVR(minimumSize));
    EXPECT_STREQ(data.getKVR().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_KVR_LENGTH, '0');
    EXPECT_NO_THROW(data.setKVR(maximumSize));
    EXPECT_STREQ(data.getKVR().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::KVR), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCDAResult) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_THROW(data.setCDAResult(emptyValue), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCDAResult().empty());

    std::string oversize(MAXIMUM_CDARESULT_LENGTH + 1, '0');
    EXPECT_THROW(data.setCDAResult(oversize), std::invalid_argument);

    std::string minimumSize(MINIMUM_CDARESULT_LENGTH, '0');
    EXPECT_NO_THROW(data.setCDAResult(minimumSize));
    EXPECT_STREQ(data.getCDAResult().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CDARESULT_LENGTH, '0');
    EXPECT_NO_THROW(data.setCDAResult(maximumSize));
    EXPECT_STREQ(data.getCDAResult().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CDAResult), data.getFieldsSet().end());
}

TEST(ResponseData, CheckSalesCount) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int16_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_THROW(data.setSalesCount(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setSalesCount(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getSalesCount(), -1);

    EXPECT_NO_THROW(data.setSalesCount(MINIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getSalesCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::SalesCount), data.getFieldsSet().end());

    EXPECT_NO_THROW(data.setSalesCount(MAXIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getSalesCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::SalesCount), data.getFieldsSet().end());
}

TEST(ResponseData, CheckVoidCount) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int16_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_THROW(data.setVoidCount(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setVoidCount(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getVoidCount(), -1);

    EXPECT_NO_THROW(data.setVoidCount(MINIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getVoidCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::VoidCount), data.getFieldsSet().end());

    EXPECT_NO_THROW(data.setVoidCount(MAXIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getVoidCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::VoidCount), data.getFieldsSet().end());
}

TEST(ResponseData, CheckRefundCount) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int16_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_THROW(data.setRefundCount(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setRefundCount(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getRefundCount(), -1);

    EXPECT_NO_THROW(data.setRefundCount(MINIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getRefundCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::RefundCount), data.getFieldsSet().end());

    EXPECT_NO_THROW(data.setRefundCount(MAXIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getRefundCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::RefundCount), data.getFieldsSet().end());
}

TEST(ResponseData, CheckSalesArray) {
    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto element = std::make_shared<ResponseData>();
    element->setTotalAmount(MAXIMUM_AMOUNT);
    array.push_back(element);

    EXPECT_NO_THROW(data.setSalesArray(array));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::SalesArray), data.getFieldsSet().end());
}

TEST(ResponseData, CheckVoidArray) {
    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto element = std::make_shared<ResponseData>();
    element->setTotalAmount(MAXIMUM_AMOUNT);
    array.push_back(element);

    EXPECT_NO_THROW(data.setVoidArray(array));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::VoidArray), data.getFieldsSet().end());
}

TEST(ResponseData, CheckRefundArray) {
    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto element = std::make_shared<ResponseData>();
    element->setTotalAmount(MAXIMUM_AMOUNT);
    array.push_back(element);

    EXPECT_NO_THROW(data.setRefundArray(array));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::RefundArray), data.getFieldsSet().end());
}

