//
// Created by Владимир Лысенков on 29.06.2020.
//
#include "gtest/gtest.h"
#include "Lanter/Message/Response/ResponseData.h"
#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;
using namespace Lanter::Utils::Constants;

TEST(ResponseData, CheckEcrNumber) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ECR_NUMBER - 1;
    int16_t greatMaximum = MAXIMUM_ECR_NUMBER + 1;

    EXPECT_FALSE(data.setEcrNumber(lessMinimum));
    EXPECT_FALSE(data.setEcrNumber(greatMaximum));

    EXPECT_EQ(data.getEcrNumber(), -1);

    EXPECT_TRUE(data.setEcrNumber(MINIMUM_ECR_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), MINIMUM_ECR_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::EcrNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.setEcrNumber(MAXIMUM_ECR_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), MAXIMUM_ECR_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::EcrNumber), data.getFieldsSet().end());
}

TEST(ResponseData, CheckEcrMerchantNumber) {
    ResponseData data;

    int16_t lessMinimum = MINIMUM_ECR_MERCHANT_NUMBER - 1;
    int16_t greatMaximum = MAXIMUM_ECR_MERCHANT_NUMBER + 1;

    EXPECT_FALSE(data.setEcrMerchantNumber(lessMinimum));
    EXPECT_FALSE(data.setEcrMerchantNumber(greatMaximum));

    EXPECT_EQ(data.getEcrMerchantNumber(), -1);

    EXPECT_TRUE(data.setEcrMerchantNumber(MINIMUM_ECR_MERCHANT_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), MINIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::EcrMerchantNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.setEcrMerchantNumber(MAXIMUM_ECR_MERCHANT_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), MAXIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::EcrMerchantNumber), data.getFieldsSet().end());
}

TEST(ResponseData, CheckOperationCode) {
    ResponseData data;

    auto greatMaximum = (OperationCodes)((int)(OperationCodes::LastValue) + 1);
    EXPECT_FALSE(data.setOperationCode(OperationCodes::NoOperation));
    EXPECT_EQ(data.getFieldsSet().size(), 0);
    EXPECT_FALSE(data.setOperationCode(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOperationCode(), OperationCodes::NoOperation);

    EXPECT_TRUE(data.setOperationCode(OperationCodes::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOperationCode(), OperationCodes::FirstValue);

    EXPECT_TRUE(data.setOperationCode(OperationCodes::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOperationCode(), OperationCodes::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::OperationCode), data.getFieldsSet().end());
}

TEST(ResponseData, CheckOriginalOperationCode) {
    ResponseData data;

    auto greatMaximum = (OperationCodes)((int)(OperationCodes::LastValue) + 1);
    EXPECT_FALSE(data.setOriginalOperationCode(OperationCodes::NoOperation));
    EXPECT_EQ(data.getFieldsSet().size(), 0);
    EXPECT_FALSE(data.setOriginalOperationCode(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOriginalOperationCode(), OperationCodes::NoOperation);

    EXPECT_TRUE(data.setOriginalOperationCode(OperationCodes::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationCode(), OperationCodes::FirstValue);

    EXPECT_TRUE(data.setOriginalOperationCode(OperationCodes::LastValue));
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
    EXPECT_FALSE(data.setTotalAmount(lessMinimum));
    EXPECT_FALSE(data.setTotalAmount(greatMaximum));

    EXPECT_EQ(data.getTotalAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setTotalAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTotalAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setTotalAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTotalAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TotalAmount), data.getFieldsSet().end());

    //ParialAmount
    EXPECT_EQ(data.getPartialAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setPartialAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setPartialAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::PartialAmount), data.getFieldsSet().end());

    //TipsAmount
    EXPECT_EQ(data.getTipsAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setTipsAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setTipsAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TipsAmount), data.getFieldsSet().end());

    //AcquirerFeeAmount
    EXPECT_EQ(data.getAcquirerFeeAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setAcquirerFeeAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getAcquirerFeeAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setAcquirerFeeAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getAcquirerFeeAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::AcquirerFeeAmount), data.getFieldsSet().end());

    //TerminalFeeAmount
    EXPECT_EQ(data.getTerminalFeeAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setTerminalFeeAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTerminalFeeAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setTerminalFeeAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTerminalFeeAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TerminalFeeAmount), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCurrencyCode) {
    ResponseData data;

    int16_t lessMinimum = MINIMUM_CURRENCY_CODE - 1;
    int16_t greatMaximum = MAXIMUM_CURRENCY_CODE + 1;

    EXPECT_FALSE(data.setCurrencyCode(lessMinimum));
    EXPECT_FALSE(data.setCurrencyCode(greatMaximum));

    EXPECT_EQ(data.getCurrencyCode(), -1);

    EXPECT_TRUE(data.setCurrencyCode(MINIMUM_CURRENCY_CODE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), MINIMUM_CURRENCY_CODE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CurrencyCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.setCurrencyCode(MAXIMUM_CURRENCY_CODE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), MAXIMUM_CURRENCY_CODE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CurrencyCode), data.getFieldsSet().end());
}

TEST(ResponseData, CheckReceiptReference) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setReceiptReference(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getReceiptReference().empty());

    std::string oversize(MAXIMUM_RECEIPT_REFERENCE_LENGTH + 1, '0');
    EXPECT_FALSE(data.setReceiptReference(oversize));

    std::string minimumSize(MINIMUM_RECEIPT_REFERENCE_LENGTH, '0');
    EXPECT_TRUE(data.setReceiptReference(minimumSize));
    EXPECT_STREQ(data.getReceiptReference().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_RECEIPT_REFERENCE_LENGTH, '0');
    EXPECT_TRUE(data.setReceiptReference(maximumSize));
    EXPECT_STREQ(data.getReceiptReference().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::ReceiptReference), data.getFieldsSet().end());
}

TEST(ResponseData, CheckRRN) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setRRN(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getRRN().empty());

    std::string oversize(MAXIMUM_RRN_LENGTH + 1, '0');
    EXPECT_FALSE(data.setRRN(oversize));

    std::string minimumSize(MINIMUM_RRN_LENGTH, '0');
    EXPECT_TRUE(data.setRRN(minimumSize));
    EXPECT_STREQ(data.getRRN().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_RRN_LENGTH, '0');
    EXPECT_TRUE(data.setRRN(maximumSize));
    EXPECT_STREQ(data.getRRN().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::RRN), data.getFieldsSet().end());
}

TEST(ResponseData, CheckStatus) {
    ResponseData data;

    auto greatMaximum = (Status)((int)(Status::LastValue) + 1);
    EXPECT_FALSE(data.setStatus(Status::NoStatus));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_FALSE(data.setStatus(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getStatus(), Status::NoStatus);

    EXPECT_TRUE(data.setStatus(Status::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getStatus(), Status::FirstValue);

    EXPECT_TRUE(data.setStatus(Status::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getStatus(), Status::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::Status), data.getFieldsSet().end());
}

TEST(ResponseData, CheckOriginalOperationStatus) {
    ResponseData data;

    auto greatMaximum = (Status)((int)(Status::LastValue) + 1);
    EXPECT_FALSE(data.setOriginalOperationStatus(Status::NoStatus));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_FALSE(data.setOriginalOperationStatus(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOriginalOperationStatus(), Status::NoStatus);

    EXPECT_TRUE(data.setOriginalOperationStatus(Status::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationStatus(), Status::FirstValue);

    EXPECT_TRUE(data.setOriginalOperationStatus(Status::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationStatus(), Status::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::OriginalOperationStatus), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTransDateTime) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setTransDateTime(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTransDateTime().empty());

    std::string oversize(MAXIMUM_TRANSACTION_DATETIME_LENGTH + 1, '0');
    EXPECT_FALSE(data.setTransDateTime(oversize));

    std::string minimumSize(MINIMUM_TRANSACTION_DATETIME_LENGTH, '0');
    EXPECT_TRUE(data.setTransDateTime(minimumSize));
    EXPECT_STREQ(data.getTransDateTime().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH, '0');
    EXPECT_TRUE(data.setTransDateTime(maximumSize));
    EXPECT_STREQ(data.getTransDateTime().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TransDateTime), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTerminalDateTime) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setTerminalDateTime(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTerminalDateTime().empty());

    std::string oversize(MAXIMUM_TERMINAL_DATETIME_LENGTH + 1, '0');
    EXPECT_FALSE(data.setTerminalDateTime(oversize));

    std::string minimumSize(MINIMUM_TERMINAL_DATETIME_LENGTH, '0');
    EXPECT_TRUE(data.setTerminalDateTime(minimumSize));
    EXPECT_STREQ(data.getTerminalDateTime().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TERMINAL_DATETIME_LENGTH, '0');
    EXPECT_TRUE(data.setTerminalDateTime(maximumSize));
    EXPECT_STREQ(data.getTerminalDateTime().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TerminalDateTime), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardPan) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCardPAN(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardPAN().empty());

    std::string oversize(MAXIMUM_CARD_PAN_LENGTH + 1, '0');
    EXPECT_FALSE(data.setCardPAN(oversize));

    std::string minimumSize(MINIMUM_CARD_PAN_LENGTH, '0');
    EXPECT_TRUE(data.setCardPAN(minimumSize));
    EXPECT_STREQ(data.getCardPAN().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CARD_PAN_LENGTH, '0');
    EXPECT_TRUE(data.setCardPAN(maximumSize));
    EXPECT_STREQ(data.getCardPAN().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardPAN), data.getFieldsSet().end());
}

TEST(ResponseData, CheckExpireDate) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setExpireDate(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getExpireDate().empty());

    std::string oversize(MAXIMUM_EXPIRE_DATE_LENGTH + 1, '0');
    EXPECT_FALSE(data.setExpireDate(oversize));

    std::string minimumSize(MINIMUM_EXPIRE_DATE_LENGTH, '0');
    EXPECT_TRUE(data.setExpireDate(minimumSize));
    EXPECT_STREQ(data.getExpireDate().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_EXPIRE_DATE_LENGTH, '0');
    EXPECT_TRUE(data.setExpireDate(maximumSize));
    EXPECT_STREQ(data.getExpireDate().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::ExpireDate), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardholderName) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCardholderName(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardholderName().empty());

    std::string oversize(MAXIMUM_CARDHOLDER_NAME_LENGTH + 1, '0');
    EXPECT_FALSE(data.setCardholderName(oversize));

    std::string minimumSize(MINIMUM_CARDHOLDER_NAME_LENGTH, '0');
    EXPECT_TRUE(data.setCardholderName(minimumSize));
    EXPECT_STREQ(data.getCardholderName().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CARDHOLDER_NAME_LENGTH, '0');
    EXPECT_TRUE(data.setCardholderName(maximumSize));
    EXPECT_STREQ(data.getCardholderName().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardholderName), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardholderAuthMethod) {
    ResponseData data;

    auto greatMaximum = (CardholderAuthMethod)((int)(CardholderAuthMethod::LastValue) + 1);
    EXPECT_FALSE(data.setCardholderAuthMethod(CardholderAuthMethod::NoMethod));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_FALSE(data.setCardholderAuthMethod(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getCardholderAuthMethod(), CardholderAuthMethod::NoMethod);

    EXPECT_TRUE(data.setCardholderAuthMethod(CardholderAuthMethod::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCardholderAuthMethod(), CardholderAuthMethod::FirstValue);

    EXPECT_TRUE(data.setCardholderAuthMethod(CardholderAuthMethod::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCardholderAuthMethod(), CardholderAuthMethod::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardholderAuthMethod), data.getFieldsSet().end());
}

TEST(ResponseData, CheckAuthCode) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setAuthCode(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getAuthCode().empty());

    std::string oversize(MAXIMUM_AUTH_CODE_LENGTH + 1, '0');
    EXPECT_FALSE(data.setAuthCode(oversize));

    std::string minimumSize(MINIMUM_AUTH_CODE_LENGTH, '0');
    EXPECT_TRUE(data.setAuthCode(minimumSize));
    EXPECT_STREQ(data.getAuthCode().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_AUTH_CODE_LENGTH, '0');
    EXPECT_TRUE(data.setAuthCode(maximumSize));
    EXPECT_STREQ(data.getAuthCode().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::AuthCode), data.getFieldsSet().end());
}

TEST(ResponseData, CheckResponseCode) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setResponseCode(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getResponseCode().empty());

    std::string oversize(MAXIMUM_RESPONSE_CODE_LENGTH + 1, '0');
    EXPECT_FALSE(data.setResponseCode(oversize));

    std::string minimumSize(MINIMUM_RESPONSE_CODE_LENGTH, '0');
    EXPECT_TRUE(data.setResponseCode(minimumSize));
    EXPECT_STREQ(data.getResponseCode().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_RESPONSE_CODE_LENGTH, '0');
    EXPECT_TRUE(data.setResponseCode(maximumSize));
    EXPECT_STREQ(data.getResponseCode().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::ResponseCode), data.getFieldsSet().end());
}

TEST(ResponseData, CheckResponseText) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setResponseText(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getResponseText().empty());

    std::string oversize(MAXIMUM_RESPONSE_TEXT_LENGTH + 1, '0');
    EXPECT_FALSE(data.setResponseText(oversize));

    std::string minimumSize(MINIMUM_RESPONSE_TEXT_LENGTH, '0');
    EXPECT_TRUE(data.setResponseText(minimumSize));
    EXPECT_STREQ(data.getResponseText().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_RESPONSE_TEXT_LENGTH, '0');
    EXPECT_TRUE(data.setResponseText(maximumSize));
    EXPECT_STREQ(data.getResponseText().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::ResponseText), data.getFieldsSet().end());
}

TEST(ResponseData, CheckSTAN) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setSTAN(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getSTAN().empty());

    std::string oversize(MAXIMUM_STAN_LENGTH + 1, '0');
    EXPECT_FALSE(data.setSTAN(oversize));

    std::string minimumSize(MINIMUM_STAN_LENGTH, '0');
    EXPECT_TRUE(data.setSTAN(minimumSize));
    EXPECT_STREQ(data.getSTAN().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_STAN_LENGTH, '0');
    EXPECT_TRUE(data.setSTAN(maximumSize));
    EXPECT_STREQ(data.getSTAN().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::STAN), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTransactionID) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setTransactionID(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTransactionID().empty());

    std::string oversize(MAXIMUM_TRANSACTION_ID_LENGTH + 1, '0');
    EXPECT_FALSE(data.setTransactionID(oversize));

    std::string minimumSize(MINIMUM_TRANSACTION_ID_LENGTH, '0');
    EXPECT_TRUE(data.setTransactionID(minimumSize));
    EXPECT_STREQ(data.getTransactionID().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TRANSACTION_ID_LENGTH, '0');
    EXPECT_TRUE(data.setTransactionID(maximumSize));
    EXPECT_STREQ(data.getTransactionID().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TransactionID), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTerminalId) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setTerminalID(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTerminalID().empty());

    std::string oversize(MAXIMUM_TERMINAL_ID_LENGTH + 1, '0');
    EXPECT_FALSE(data.setTerminalID(oversize));

    std::string minimumSize(MINIMUM_TERMINAL_ID_LENGTH, '0');
    EXPECT_TRUE(data.setTerminalID(minimumSize));
    EXPECT_STREQ(data.getTerminalID().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TERMINAL_ID_LENGTH, '0');
    EXPECT_TRUE(data.setTerminalID(maximumSize));
    EXPECT_STREQ(data.getTerminalID().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TerminalID), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardEmvAid) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCardEmvAid(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardEmvAid().empty());

    std::string oversize(MAXIMUM_EMV_AID_LENGTH + 1, '0');
    EXPECT_FALSE(data.setCardEmvAid(oversize));

    std::string minimumSize(MINIMUM_EMV_AID_LENGTH, '0');
    EXPECT_TRUE(data.setCardEmvAid(minimumSize));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_EMV_AID_LENGTH, '0');
    EXPECT_TRUE(data.setCardEmvAid(maximumSize));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardEmvAid), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardAppName) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCardAppName(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardAppName().empty());

    std::string oversize(MAXIMUM_CARD_APP_NAME_LENGTH + 1, '0');
    EXPECT_FALSE(data.setCardAppName(oversize));

    std::string minimumSize(MINIMUM_CARD_APP_NAME_LENGTH, '0');
    EXPECT_TRUE(data.setCardAppName(minimumSize));
    EXPECT_STREQ(data.getCardAppName().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CARD_APP_NAME_LENGTH, '0');
    EXPECT_TRUE(data.setCardAppName(maximumSize));
    EXPECT_STREQ(data.getCardAppName().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardAppName), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardInputMethod) {
    ResponseData data;

    auto greatMaximum = (CardInputMethod)((int)(CardInputMethod::LastValue) + 1);
    EXPECT_FALSE(data.setCardInputMethod(CardInputMethod::NoMethod));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_FALSE(data.setCardInputMethod(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getCardInputMethod(), CardInputMethod::NoMethod);

    EXPECT_TRUE(data.setCardInputMethod(CardInputMethod::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCardInputMethod(), CardInputMethod::FirstValue);

    EXPECT_TRUE(data.setCardInputMethod(CardInputMethod::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCardInputMethod(), CardInputMethod::LastValue);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardInputMethod), data.getFieldsSet().end());
}

TEST(ResponseData, CheckIssuerName) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setIssuerName(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getIssuerName().empty());

    std::string oversize(MAXIMUM_ISSUER_NAME_LENGTH + 1, '0');
    EXPECT_FALSE(data.setIssuerName(oversize));

    std::string minimumSize(MINIMUM_ISSUER_NAME_LENGTH, '0');
    EXPECT_TRUE(data.setIssuerName(minimumSize));
    EXPECT_STREQ(data.getIssuerName().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_ISSUER_NAME_LENGTH, '0');
    EXPECT_TRUE(data.setIssuerName(maximumSize));
    EXPECT_STREQ(data.getIssuerName().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::IssuerName), data.getFieldsSet().end());
}

TEST(ResponseData, CheckAdditionalInfo) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setAdditionalInfo(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getAdditionalInfo().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setAdditionalInfo(value));
    EXPECT_STRCASEEQ(data.getAdditionalInfo().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::AdditionalInfo), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardData) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCardData(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardData().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setCardData(value));
    EXPECT_STRCASEEQ(data.getCardData().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardData), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCardDataEnc) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCardDataEnc(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardDataEnc().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setCardDataEnc(value));
    EXPECT_STRCASEEQ(data.getCardDataEnc().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CardDataEnc), data.getFieldsSet().end());
}

TEST(ResponseData, CheckMerchantID) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setMerchantID(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getMerchantID().empty());

    std::string oversize(MAXIMUM_MERCHANT_ID_LENGTH + 1, '0');
    EXPECT_FALSE(data.setMerchantID(oversize));

    std::string minimumSize(MINIMUM_MERCHANT_ID_LENGTH, '0');
    EXPECT_TRUE(data.setMerchantID(minimumSize));
    EXPECT_STREQ(data.getMerchantID().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_MERCHANT_ID_LENGTH, '0');
    EXPECT_TRUE(data.setMerchantID(maximumSize));
    EXPECT_STREQ(data.getMerchantID().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::MerchantID), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTVR) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setTVR(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTVR().empty());

    std::string oversize(MAXIMUM_TVR_LENGTH + 1, '0');
    EXPECT_FALSE(data.setTVR(oversize));

    std::string minimumSize(MINIMUM_TVR_LENGTH, '0');
    EXPECT_TRUE(data.setTVR(minimumSize));
    EXPECT_STREQ(data.getTVR().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TVR_LENGTH, '0');
    EXPECT_TRUE(data.setTVR(maximumSize));
    EXPECT_STREQ(data.getTVR().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TVR), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTSI) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setTSI(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTSI().empty());

    std::string oversize(MAXIMUM_TSI_LENGTH + 1, '0');
    EXPECT_FALSE(data.setTSI(oversize));

    std::string minimumSize(MINIMUM_TSI_LENGTH, '0');
    EXPECT_TRUE(data.setTSI(minimumSize));
    EXPECT_STREQ(data.getTSI().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TSI_LENGTH, '0');
    EXPECT_TRUE(data.setTSI(maximumSize));
    EXPECT_STREQ(data.getTSI().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TSI), data.getFieldsSet().end());
}

TEST(ResponseData, CheckTC) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setTC(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTC().empty());

    std::string oversize(MAXIMUM_TC_LENGTH + 1, '0');
    EXPECT_FALSE(data.setTC(oversize));

    std::string minimumSize(MINIMUM_TC_LENGTH, '0');
    EXPECT_TRUE(data.setTC(minimumSize));
    EXPECT_STREQ(data.getTC().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_TC_LENGTH, '0');
    EXPECT_TRUE(data.setTC(maximumSize));
    EXPECT_STREQ(data.getTC().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::TC), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCID) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCID(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCID().empty());

    std::string oversize(MAXIMUM_CID_LENGTH + 1, '0');
    EXPECT_FALSE(data.setCID(oversize));

    std::string minimumSize(MINIMUM_CID_LENGTH, '0');
    EXPECT_TRUE(data.setCID(minimumSize));
    EXPECT_STREQ(data.getCID().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CID_LENGTH, '0');
    EXPECT_TRUE(data.setCID(maximumSize));
    EXPECT_STREQ(data.getCID().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CID), data.getFieldsSet().end());
}

TEST(ResponseData, CheckKVR) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setKVR(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getKVR().empty());

    std::string oversize(MAXIMUM_KVR_LENGTH + 1, '0');
    EXPECT_FALSE(data.setKVR(oversize));

    std::string minimumSize(MINIMUM_KVR_LENGTH, '0');
    EXPECT_TRUE(data.setKVR(minimumSize));
    EXPECT_STREQ(data.getKVR().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_KVR_LENGTH, '0');
    EXPECT_TRUE(data.setKVR(maximumSize));
    EXPECT_STREQ(data.getKVR().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::KVR), data.getFieldsSet().end());
}

TEST(ResponseData, CheckCDAResult) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCDAResult(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCDAResult().empty());

    std::string oversize(MAXIMUM_CDARESULT_LENGTH + 1, '0');
    EXPECT_FALSE(data.setCDAResult(oversize));

    std::string minimumSize(MINIMUM_CDARESULT_LENGTH, '0');
    EXPECT_TRUE(data.setCDAResult(minimumSize));
    EXPECT_STREQ(data.getCDAResult().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CDARESULT_LENGTH, '0');
    EXPECT_TRUE(data.setCDAResult(maximumSize));
    EXPECT_STREQ(data.getCDAResult().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::CDAResult), data.getFieldsSet().end());
}

TEST(ResponseData, CheckSalesCount) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int16_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_FALSE(data.setSalesCount(lessMinimum));
    EXPECT_FALSE(data.setSalesCount(greatMaximum));

    EXPECT_EQ(data.getSalesCount(), -1);

    EXPECT_TRUE(data.setSalesCount(MINIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getSalesCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::SalesCount), data.getFieldsSet().end());

    EXPECT_TRUE(data.setSalesCount(MAXIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getSalesCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::SalesCount), data.getFieldsSet().end());
}

TEST(ResponseData, CheckVoidCount) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int16_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_FALSE(data.setVoidCount(lessMinimum));
    EXPECT_FALSE(data.setVoidCount(greatMaximum));

    EXPECT_EQ(data.getVoidCount(), -1);

    EXPECT_TRUE(data.setVoidCount(MINIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getVoidCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::VoidCount), data.getFieldsSet().end());

    EXPECT_TRUE(data.setVoidCount(MAXIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getVoidCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::VoidCount), data.getFieldsSet().end());
}

TEST(ResponseData, CheckRefundCount) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int16_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_FALSE(data.setRefundCount(lessMinimum));
    EXPECT_FALSE(data.setRefundCount(greatMaximum));

    EXPECT_EQ(data.getRefundCount(), -1);

    EXPECT_TRUE(data.setRefundCount(MINIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getRefundCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::RefundCount), data.getFieldsSet().end());

    EXPECT_TRUE(data.setRefundCount(MAXIMUM_ARRAY_SIZE));
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

    EXPECT_TRUE(data.setSalesArray(array));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::SalesArray), data.getFieldsSet().end());
}

TEST(ResponseData, CheckVoidArray) {
    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto element = std::make_shared<ResponseData>();
    element->setTotalAmount(MAXIMUM_AMOUNT);
    array.push_back(element);

    EXPECT_TRUE(data.setVoidArray(array));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::VoidArray), data.getFieldsSet().end());
}

TEST(ResponseData, CheckRefundArray) {
    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto element = std::make_shared<ResponseData>();
    element->setTotalAmount(MAXIMUM_AMOUNT);
    array.push_back(element);

    EXPECT_TRUE(data.setRefundArray(array));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseFields::RefundArray), data.getFieldsSet().end());
}

