//
// Created by Владимир Лысенков on 21.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/Utils/Constants.h"

#include "Lanter/Message/Response/ResponseData.h"
#include "Lanter/MessageProcessor/MessageParser/JSONResponseParser.h"

#include "Lanter/MessageProcessor/MessageBuilder/JSONAddFieldHelper.h"
#include "Lanter/MessageProcessor/JSONMessageFields.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;
using namespace Lanter::MessageProcessor;
using namespace Lanter::Utils;
using namespace Lanter::Utils::Constants;

TEST(JSONResponseParser, CheckInitMap) {
    JSONResponseParser parser;

    EXPECT_FALSE(parser.getFunctions().empty());

    auto count = (size_t)ResponseFields::LastValue - (size_t)ResponseFields::FirstValue +1;

    EXPECT_EQ(count, parser.getFunctions().size());
}

TEST(JSONResponseParser, CheckGetEcrNumber) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldEcrNumber(object, data));

    auto lessMinimum = MINIMUM_ECR_NUMBER - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getEcrNumber(), lessMinimum);
    EXPECT_FALSE(parser.getFieldEcrNumber(object, data));

    auto greatMaximum = MAXIMUM_ECR_NUMBER + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getEcrNumber(), greatMaximum);
    EXPECT_FALSE(parser.getFieldEcrNumber(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getEcrNumber(), MINIMUM_ECR_NUMBER);
    EXPECT_TRUE(parser.getFieldEcrNumber(object, data));
    EXPECT_EQ(data.getEcrNumber(), MINIMUM_ECR_NUMBER);

    AddFieldsHelper::addField(object, JSONResponseFields::getEcrNumber(), MAXIMUM_ECR_NUMBER);
    EXPECT_TRUE(parser.getFieldEcrNumber(object, data));
    EXPECT_EQ(data.getEcrNumber(), MAXIMUM_ECR_NUMBER);
}

TEST(JSONResponseParser, CheckGetEcrMerchantNumber) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldEcrMerchantNumber(object, data));

    auto lessMinimum = MINIMUM_ECR_MERCHANT_NUMBER - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getEcrMerchantNumber(), lessMinimum);
    EXPECT_FALSE(parser.getFieldEcrMerchantNumber(object, data));

    auto greatMaximum = MAXIMUM_ECR_MERCHANT_NUMBER + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getEcrMerchantNumber(), greatMaximum);
    EXPECT_FALSE(parser.getFieldEcrMerchantNumber(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getEcrMerchantNumber(), MINIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_TRUE(parser.getFieldEcrMerchantNumber(object, data));
    EXPECT_EQ(data.getEcrMerchantNumber(), MINIMUM_ECR_MERCHANT_NUMBER);

    AddFieldsHelper::addField(object, JSONResponseFields::getEcrMerchantNumber(), MAXIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_TRUE(parser.getFieldEcrMerchantNumber(object, data));
    EXPECT_EQ(data.getEcrMerchantNumber(), MAXIMUM_ECR_MERCHANT_NUMBER);
}

TEST(JSONResponseParser, CheckGetOperationCode) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldOperationCode(object, data));

    auto lessMinimum = (int)OperationCode::FirstValue - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), lessMinimum);
    EXPECT_FALSE(parser.getFieldOperationCode(object, data));

    auto greatMaximum = (int)OperationCode::LastValue + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), greatMaximum);
    EXPECT_FALSE(parser.getFieldOperationCode(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), (int)OperationCode::FirstValue);
    EXPECT_TRUE(parser.getFieldOperationCode(object, data));
    EXPECT_EQ((int)data.getOperationCode(), (int)OperationCode::FirstValue);

    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), (int)OperationCode::LastValue);
    EXPECT_TRUE(parser.getFieldOperationCode(object, data));
    EXPECT_EQ((int)data.getOperationCode(), (int)OperationCode::LastValue);
}

TEST(JSONResponseParser, CheckGetOriginalOperationCode) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldOriginalOperationCode(object, data));

    auto lessMinimum = (int)OperationCode::FirstValue - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(), lessMinimum);
    EXPECT_FALSE(parser.getFieldOriginalOperationCode(object, data));

    auto greatMaximum = (int)OperationCode::LastValue + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(), greatMaximum);
    EXPECT_FALSE(parser.getFieldOriginalOperationCode(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(), (int)OperationCode::FirstValue);
    EXPECT_TRUE(parser.getFieldOriginalOperationCode(object, data));
    EXPECT_EQ((int)data.getOriginalOperationCode(), (int)OperationCode::FirstValue);

    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(), (int)OperationCode::LastValue);
    EXPECT_TRUE(parser.getFieldOriginalOperationCode(object, data));
    EXPECT_EQ((int)data.getOriginalOperationCode(), (int)OperationCode::LastValue);
}

TEST(JSONResponseParser, CheckGetTotalAmount) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldTotalAmount(object, data));

    auto lessMinimum = MINIMUM_AMOUNT - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getTotalAmount(), lessMinimum);
    EXPECT_FALSE(parser.getFieldTotalAmount(object, data));

    auto greatMaximum = MAXIMUM_AMOUNT + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getTotalAmount(), greatMaximum);
    EXPECT_FALSE(parser.getFieldTotalAmount(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getTotalAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldTotalAmount(object, data));
    EXPECT_EQ(data.getTotalAmount(), MINIMUM_AMOUNT);

    AddFieldsHelper::addField(object, JSONResponseFields::getTotalAmount(), MAXIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldTotalAmount(object, data));
    EXPECT_EQ(data.getTotalAmount(), MAXIMUM_AMOUNT);
}
TEST(JSONResponseParser, CheckGetPartialAmount) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldPartialAmount(object, data));

    auto lessMinimum = MINIMUM_AMOUNT - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getPartialAmount(), lessMinimum);
    EXPECT_FALSE(parser.getFieldPartialAmount(object, data));

    auto greatMaximum = MAXIMUM_AMOUNT + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getPartialAmount(), greatMaximum);
    EXPECT_FALSE(parser.getFieldPartialAmount(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getPartialAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldPartialAmount(object, data));
    EXPECT_EQ(data.getPartialAmount(), MINIMUM_AMOUNT);

    AddFieldsHelper::addField(object, JSONResponseFields::getPartialAmount(), MAXIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldPartialAmount(object, data));
    EXPECT_EQ(data.getPartialAmount(), MAXIMUM_AMOUNT);
}
TEST(JSONResponseParser, CheckGetAcquirerFeeAmount) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldAcquirerFeeAmount(object, data));

    auto lessMinimum = MINIMUM_AMOUNT - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getAcquirerFeeAmount(), lessMinimum);
    EXPECT_FALSE(parser.getFieldAcquirerFeeAmount(object, data));

    auto greatMaximum = MAXIMUM_AMOUNT + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getAcquirerFeeAmount(), greatMaximum);
    EXPECT_FALSE(parser.getFieldAcquirerFeeAmount(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getAcquirerFeeAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldAcquirerFeeAmount(object, data));
    EXPECT_EQ(data.getAcquirerFeeAmount(), MINIMUM_AMOUNT);

    AddFieldsHelper::addField(object, JSONResponseFields::getAcquirerFeeAmount(), MAXIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldAcquirerFeeAmount(object, data));
    EXPECT_EQ(data.getAcquirerFeeAmount(), MAXIMUM_AMOUNT);
}
TEST(JSONResponseParser, CheckGetTerminalFeeAmount) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldTerminalFeeAmount(object, data));

    auto lessMinimum = MINIMUM_AMOUNT - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalFeeAmount(), lessMinimum);
    EXPECT_FALSE(parser.getFieldTerminalFeeAmount(object, data));

    auto greatMaximum = MAXIMUM_AMOUNT + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalFeeAmount(), greatMaximum);
    EXPECT_FALSE(parser.getFieldTerminalFeeAmount(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalFeeAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldTerminalFeeAmount(object, data));
    EXPECT_EQ(data.getTerminalFeeAmount(), MINIMUM_AMOUNT);

    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalFeeAmount(), MAXIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldTerminalFeeAmount(object, data));
    EXPECT_EQ(data.getTerminalFeeAmount(), MAXIMUM_AMOUNT);
}
TEST(JSONResponseParser, CheckGetTipsAmount) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldTipsAmount(object, data));

    auto lessMinimum = MINIMUM_AMOUNT - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getTipsAmount(), lessMinimum);
    EXPECT_FALSE(parser.getFieldTipsAmount(object, data));

    auto greatMaximum = MAXIMUM_AMOUNT + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getTipsAmount(), greatMaximum);
    EXPECT_FALSE(parser.getFieldTipsAmount(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getTipsAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldTipsAmount(object, data));
    EXPECT_EQ(data.getTipsAmount(), MINIMUM_AMOUNT);

    AddFieldsHelper::addField(object, JSONResponseFields::getTipsAmount(), MAXIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldTipsAmount(object, data));
    EXPECT_EQ(data.getTipsAmount(), MAXIMUM_AMOUNT);
}

TEST(JSONResponseParser, CheckGetCurrencyCode) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCurrencyCode(object, data));

    auto lessMinimum = MINIMUM_CURRENCY_CODE - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(), lessMinimum);
    EXPECT_FALSE(parser.getFieldCurrencyCode(object, data));

    auto greatMaximum = MAXIMUM_CURRENCY_CODE + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(), greatMaximum);
    EXPECT_FALSE(parser.getFieldCurrencyCode(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(), MINIMUM_CURRENCY_CODE);
    EXPECT_TRUE(parser.getFieldCurrencyCode(object, data));
    EXPECT_EQ(data.getCurrencyCode(), MINIMUM_CURRENCY_CODE);

    AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(), MAXIMUM_CURRENCY_CODE);
    EXPECT_TRUE(parser.getFieldCurrencyCode(object, data));
    EXPECT_EQ(data.getCurrencyCode(), MAXIMUM_CURRENCY_CODE);
}

TEST(JSONResponseParser, CheckGetReceiptReference) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldReceiptReference(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptReference(), empty);
    EXPECT_FALSE(parser.getFieldReceiptReference(object, data));

    std::string overSize(MAXIMUM_RECEIPT_REFERENCE_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptReference(), overSize);
    EXPECT_FALSE(parser.getFieldReceiptReference(object, data));

    std::string maxSize(MAXIMUM_RECEIPT_REFERENCE_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptReference(), maxSize);
    EXPECT_TRUE(parser.getFieldReceiptReference(object, data));
    EXPECT_STREQ(data.getReceiptReference().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetRRN) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldRRN(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getRRN(), empty);
    EXPECT_FALSE(parser.getFieldRRN(object, data));

    std::string overSize(MAXIMUM_RRN_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getRRN(), overSize);
    EXPECT_FALSE(parser.getFieldRRN(object, data));

    std::string maxSize(MAXIMUM_RRN_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getRRN(), maxSize);
    EXPECT_TRUE(parser.getFieldRRN(object, data));
    EXPECT_STREQ(data.getRRN().c_str(), maxSize.c_str());
}

TEST(JSONResponseParser, CheckGetStatus) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldStatus(object, data));

    auto lessMinimum = (int)Status::FirstValue - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), lessMinimum);
    EXPECT_FALSE(parser.getFieldStatus(object, data));

    auto greatMaximum = (int)Status::LastValue + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), greatMaximum);
    EXPECT_FALSE(parser.getFieldStatus(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), (int)Status::FirstValue);
    EXPECT_TRUE(parser.getFieldStatus(object, data));
    EXPECT_EQ((int)data.getStatus(), (int)Status::FirstValue);

    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), (int)Status::LastValue);
    EXPECT_TRUE(parser.getFieldStatus(object, data));
    EXPECT_EQ((int)data.getStatus(), (int)Status::LastValue);
}
TEST(JSONResponseParser, CheckGetOriginalOperationStatus) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldOriginalOperationStatus(object, data));

    auto lessMinimum = (int)Status::FirstValue - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationStatus(), lessMinimum);
    EXPECT_FALSE(parser.getFieldOriginalOperationStatus(object, data));

    auto greatMaximum = (int)Status::LastValue + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationStatus(), greatMaximum);
    EXPECT_FALSE(parser.getFieldOriginalOperationStatus(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationStatus(), (int)Status::FirstValue);
    EXPECT_TRUE(parser.getFieldOriginalOperationStatus(object, data));
    EXPECT_EQ((int)data.getOriginalOperationStatus(), (int)Status::FirstValue);

    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationStatus(), (int)Status::LastValue);
    EXPECT_TRUE(parser.getFieldOriginalOperationStatus(object, data));
    EXPECT_EQ((int)data.getOriginalOperationStatus(), (int)Status::LastValue);
}

TEST(JSONResponseParser, CheckGetTransDateTime) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldTransDateTime(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getTransDateTime(), empty);
    EXPECT_FALSE(parser.getFieldTransDateTime(object, data));

    std::string overSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTransDateTime(), overSize);
    EXPECT_FALSE(parser.getFieldTransDateTime(object, data));

    std::string maxSize(MAXIMUM_TRANSACTION_DATETIME_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTransDateTime(), maxSize);
    EXPECT_TRUE(parser.getFieldTransDateTime(object, data));
    EXPECT_STREQ(data.getTransDateTime().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetTerminalDateTime) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldTerminalDateTime(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalDateTime(), empty);
    EXPECT_FALSE(parser.getFieldTerminalDateTime(object, data));

    std::string overSize(MAXIMUM_TERMINAL_DATETIME_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalDateTime(), overSize);
    EXPECT_FALSE(parser.getFieldTerminalDateTime(object, data));

    std::string maxSize(MAXIMUM_TERMINAL_DATETIME_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalDateTime(), maxSize);
    EXPECT_TRUE(parser.getFieldTerminalDateTime(object, data));
    EXPECT_STREQ(data.getTerminalDateTime().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetCardPAN) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCardPAN(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getCardPAN(), empty);
    EXPECT_FALSE(parser.getFieldCardPAN(object, data));

    std::string overSize(MAXIMUM_CARD_PAN_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardPAN(), overSize);
    EXPECT_FALSE(parser.getFieldCardPAN(object, data));

    std::string maxSize(MAXIMUM_CARD_PAN_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardPAN(), maxSize);
    EXPECT_TRUE(parser.getFieldCardPAN(object, data));
    EXPECT_STREQ(data.getCardPAN().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetExpireDate) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldExpireDate(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getExpireDate(), empty);
    EXPECT_FALSE(parser.getFieldExpireDate(object, data));

    std::string overSize(MAXIMUM_EXPIRE_DATE_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getExpireDate(), overSize);
    EXPECT_FALSE(parser.getFieldExpireDate(object, data));

    std::string maxSize(MAXIMUM_EXPIRE_DATE_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getExpireDate(), maxSize);
    EXPECT_TRUE(parser.getFieldExpireDate(object, data));
    EXPECT_STREQ(data.getExpireDate().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetCardholderName) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCardholderName(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderName(), empty);
    EXPECT_FALSE(parser.getFieldCardholderName(object, data));

    std::string overSize(MAXIMUM_CARDHOLDER_NAME_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderName(), overSize);
    EXPECT_FALSE(parser.getFieldCardholderName(object, data));

    std::string maxSize(MAXIMUM_CARDHOLDER_NAME_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderName(), maxSize);
    EXPECT_TRUE(parser.getFieldCardholderName(object, data));
    EXPECT_STREQ(data.getCardholderName().c_str(), maxSize.c_str());
}

TEST(JSONResponseParser, CheckGetCardholderAuthMethod) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCardholderAuthMethod(object, data));

    auto lessMinimum = (int)CardholderAuthMethod::FirstValue - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderAuthMethod(), lessMinimum);
    EXPECT_FALSE(parser.getFieldCardholderAuthMethod(object, data));

    auto greatMaximum = (int)CardholderAuthMethod::LastValue + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderAuthMethod(), greatMaximum);
    EXPECT_FALSE(parser.getFieldCardholderAuthMethod(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderAuthMethod(), (int)CardholderAuthMethod::FirstValue);
    EXPECT_TRUE(parser.getFieldCardholderAuthMethod(object, data));
    EXPECT_EQ((int)data.getCardholderAuthMethod(), (int)CardholderAuthMethod::FirstValue);

    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderAuthMethod(), (int)CardholderAuthMethod::LastValue);
    EXPECT_TRUE(parser.getFieldCardholderAuthMethod(object, data));
    EXPECT_EQ((int)data.getCardholderAuthMethod(), (int)CardholderAuthMethod::LastValue);
}

TEST(JSONResponseParser, CheckGetAuthCode) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldAuthCode(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getAuthCode(), empty);
    EXPECT_FALSE(parser.getFieldAuthCode(object, data));

    std::string overSize(MAXIMUM_AUTH_CODE_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getAuthCode(), overSize);
    EXPECT_FALSE(parser.getFieldAuthCode(object, data));

    std::string maxSize(MAXIMUM_AUTH_CODE_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getAuthCode(), maxSize);
    EXPECT_TRUE(parser.getFieldAuthCode(object, data));
    EXPECT_STREQ(data.getAuthCode().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetResponseCode) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldResponseCode(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getResponseCode(), empty);
    EXPECT_FALSE(parser.getFieldResponseCode(object, data));

    std::string overSize(MAXIMUM_RESPONSE_CODE_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getResponseCode(), overSize);
    EXPECT_FALSE(parser.getFieldResponseCode(object, data));

    std::string maxSize(MAXIMUM_RESPONSE_CODE_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getResponseCode(), maxSize);
    EXPECT_TRUE(parser.getFieldResponseCode(object, data));
    EXPECT_STREQ(data.getResponseCode().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetResponseText) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldResponseText(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getResponseText(), empty);
    EXPECT_FALSE(parser.getFieldResponseText(object, data));

    std::string overSize(MAXIMUM_RESPONSE_TEXT_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getResponseText(), overSize);
    EXPECT_FALSE(parser.getFieldResponseText(object, data));

    std::string maxSize(MAXIMUM_RESPONSE_TEXT_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getResponseText(), maxSize);
    EXPECT_TRUE(parser.getFieldResponseText(object, data));
    EXPECT_STREQ(data.getResponseText().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetSTAN) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldSTAN(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getSTAN(), empty);
    EXPECT_FALSE(parser.getFieldSTAN(object, data));

    std::string overSize(MAXIMUM_STAN_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getSTAN(), overSize);
    EXPECT_FALSE(parser.getFieldSTAN(object, data));

    std::string maxSize(MAXIMUM_STAN_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getSTAN(), maxSize);
    EXPECT_TRUE(parser.getFieldSTAN(object, data));
    EXPECT_STREQ(data.getSTAN().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetTransactionID) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldTransactionID(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getTransactionID(), empty);
    EXPECT_FALSE(parser.getFieldTransactionID(object, data));

    std::string overSize(MAXIMUM_TRANSACTION_ID_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTransactionID(), overSize);
    EXPECT_FALSE(parser.getFieldTransactionID(object, data));

    std::string maxSize(MAXIMUM_TRANSACTION_ID_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTransactionID(), maxSize);
    EXPECT_TRUE(parser.getFieldTransactionID(object, data));
    EXPECT_STREQ(data.getTransactionID().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetTerminalID) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldTerminalID(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalID(), empty);
    EXPECT_FALSE(parser.getFieldTerminalID(object, data));

    std::string overSize(MAXIMUM_TERMINAL_ID_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalID(), overSize);
    EXPECT_FALSE(parser.getFieldTerminalID(object, data));

    std::string maxSize(MAXIMUM_TERMINAL_ID_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalID(), maxSize);
    EXPECT_TRUE(parser.getFieldTerminalID(object, data));
    EXPECT_STREQ(data.getTerminalID().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetCardEmvAid) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCardEmvAid(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getCardEmvAid(), empty);
    EXPECT_FALSE(parser.getFieldCardEmvAid(object, data));

    std::string overSize(MAXIMUM_CARD_EMV_AID_LENGTH + 1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardEmvAid(), overSize);
    EXPECT_FALSE(parser.getFieldCardEmvAid(object, data));

    std::string maxSize(MAXIMUM_CARD_EMV_AID_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardEmvAid(), maxSize);
    EXPECT_TRUE(parser.getFieldCardEmvAid(object, data));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetCardAppName) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCardAppName(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getCardAppName(), empty);
    EXPECT_FALSE(parser.getFieldCardAppName(object, data));

    std::string overSize(MAXIMUM_CARD_APP_NAME_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardAppName(), overSize);
    EXPECT_FALSE(parser.getFieldCardAppName(object, data));

    std::string maxSize(MAXIMUM_CARD_APP_NAME_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardAppName(), maxSize);
    EXPECT_TRUE(parser.getFieldCardAppName(object, data));
    EXPECT_STREQ(data.getCardAppName().c_str(), maxSize.c_str());
}

TEST(JSONResponseParser, CheckGetCardInputMethod) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCardInputMethod(object, data));

    auto lessMinimum = (int)CardInputMethod::FirstValue - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(), lessMinimum);
    EXPECT_FALSE(parser.getFieldCardInputMethod(object, data));

    auto greatMaximum = (int)CardInputMethod::LastValue + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(), greatMaximum);
    EXPECT_FALSE(parser.getFieldCardInputMethod(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(), (int)CardInputMethod::FirstValue);
    EXPECT_TRUE(parser.getFieldCardInputMethod(object, data));
    EXPECT_EQ((int)data.getCardInputMethod(), (int)CardInputMethod::FirstValue);

    AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(), (int)CardInputMethod::LastValue);
    EXPECT_TRUE(parser.getFieldCardInputMethod(object, data));
    EXPECT_EQ((int)data.getCardInputMethod(), (int)CardInputMethod::LastValue);
}

TEST(JSONResponseParser, CheckGetIssuerName) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldIssuerName(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getIssuerName(), empty);
    EXPECT_FALSE(parser.getFieldIssuerName(object, data));

    std::string overSize(MAXIMUM_ISSUER_NAME_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getIssuerName(), overSize);
    EXPECT_FALSE(parser.getFieldIssuerName(object, data));

    std::string maxSize(MAXIMUM_ISSUER_NAME_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getIssuerName(), maxSize);
    EXPECT_TRUE(parser.getFieldIssuerName(object, data));
    EXPECT_STREQ(data.getIssuerName().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetAdditionalInfo) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldAdditionalInfo(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getAdditionalInfo(), empty);
    EXPECT_FALSE(parser.getFieldAdditionalInfo(object, data));

    std::string maxSize(16+1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getAdditionalInfo(), maxSize);
    EXPECT_TRUE(parser.getFieldAdditionalInfo(object, data));
    EXPECT_STREQ(data.getAdditionalInfo().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetCardData) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCardData(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getCardData(), empty);
    EXPECT_FALSE(parser.getFieldCardData(object, data));


    std::string maxSize(16*1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardData(), maxSize);
    EXPECT_TRUE(parser.getFieldCardData(object, data));
    EXPECT_STREQ(data.getCardData().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetCardDataEnc) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCardDataEnc(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getCardDataEnc(), empty);
    EXPECT_FALSE(parser.getFieldCardDataEnc(object, data));

    std::string maxSize(16*1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardDataEnc(), maxSize);
    EXPECT_TRUE(parser.getFieldCardDataEnc(object, data));
    EXPECT_STREQ(data.getCardDataEnc().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetMerchantID) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldMerchantID(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getMerchantID(), empty);
    EXPECT_FALSE(parser.getFieldMerchantID(object, data));

    std::string overSize(MAXIMUM_MERCHANT_ID_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getMerchantID(), overSize);
    EXPECT_FALSE(parser.getFieldMerchantID(object, data));

    std::string maxSize(MAXIMUM_MERCHANT_ID_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getMerchantID(), maxSize);
    EXPECT_TRUE(parser.getFieldMerchantID(object, data));
    EXPECT_STREQ(data.getMerchantID().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetTVR) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldTVR(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getTVR(), empty);
    EXPECT_FALSE(parser.getFieldTVR(object, data));

    std::string overSize(MAXIMUM_TVR_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTVR(), overSize);
    EXPECT_FALSE(parser.getFieldTVR(object, data));

    std::string maxSize(MAXIMUM_TVR_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTVR(), maxSize);
    EXPECT_TRUE(parser.getFieldTVR(object, data));
    EXPECT_STREQ(data.getTVR().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetTSI) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldTSI(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getTSI(), empty);
    EXPECT_FALSE(parser.getFieldTSI(object, data));

    std::string overSize(MAXIMUM_TSI_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTSI(), overSize);
    EXPECT_FALSE(parser.getFieldTSI(object, data));

    std::string maxSize(MAXIMUM_TSI_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTSI(), maxSize);
    EXPECT_TRUE(parser.getFieldTSI(object, data));
    EXPECT_STREQ(data.getTSI().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetTC) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldTC(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getTC(), empty);
    EXPECT_FALSE(parser.getFieldTC(object, data));

    std::string overSize(MAXIMUM_TC_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTC(), overSize);
    EXPECT_FALSE(parser.getFieldTC(object, data));

    std::string maxSize(MAXIMUM_TC_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getTC(), maxSize);
    EXPECT_TRUE(parser.getFieldTC(object, data));
    EXPECT_STREQ(data.getTC().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetCID) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCID(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getCID(), empty);
    EXPECT_FALSE(parser.getFieldCID(object, data));

    std::string overSize(MAXIMUM_CID_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCID(), overSize);
    EXPECT_FALSE(parser.getFieldCID(object, data));

    std::string maxSize(MAXIMUM_CID_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCID(), maxSize);
    EXPECT_TRUE(parser.getFieldCID(object, data));
    EXPECT_STREQ(data.getCID().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetKVR) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldKVR(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getKVR(), empty);
    EXPECT_FALSE(parser.getFieldKVR(object, data));

    std::string overSize(MAXIMUM_KVR_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getKVR(), overSize);
    EXPECT_FALSE(parser.getFieldKVR(object, data));

    std::string maxSize(MAXIMUM_KVR_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getKVR(), maxSize);
    EXPECT_TRUE(parser.getFieldKVR(object, data));
    EXPECT_STREQ(data.getKVR().c_str(), maxSize.c_str());
}
TEST(JSONResponseParser, CheckGetCDAResult) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCDAResult(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getCDAResult(), empty);
    EXPECT_FALSE(parser.getFieldCDAResult(object, data));

    std::string overSize(MAXIMUM_CDARESULT_LENGTH+1, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCDAResult(), overSize);
    EXPECT_FALSE(parser.getFieldCDAResult(object, data));

    std::string maxSize(MAXIMUM_CDARESULT_LENGTH, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCDAResult(), maxSize);
    EXPECT_TRUE(parser.getFieldCDAResult(object, data));
    EXPECT_STREQ(data.getCDAResult().c_str(), maxSize.c_str());
}

TEST(JSONResponseParser, CheckGetSalesCount) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldSalesCount(object, data));

    auto lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getSalesCount(), lessMinimum);
    EXPECT_FALSE(parser.getFieldSalesCount(object, data));

    auto greatMaximum = MAXIMUM_ARRAY_SIZE + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getSalesCount(), greatMaximum);
    EXPECT_FALSE(parser.getFieldSalesCount(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getSalesCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_TRUE(parser.getFieldSalesCount(object, data));
    EXPECT_EQ(data.getSalesCount(), MINIMUM_ARRAY_SIZE);

    AddFieldsHelper::addField(object, JSONResponseFields::getSalesCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_TRUE(parser.getFieldSalesCount(object, data));
    EXPECT_EQ(data.getSalesCount(), MAXIMUM_ARRAY_SIZE);
}
TEST(JSONResponseParser, CheckGetVoidCount) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldVoidCount(object, data));

    auto lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getVoidCount(), lessMinimum);
    EXPECT_FALSE(parser.getFieldVoidCount(object, data));

    auto greatMaximum = MAXIMUM_ARRAY_SIZE + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getVoidCount(), greatMaximum);
    EXPECT_FALSE(parser.getFieldVoidCount(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getVoidCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_TRUE(parser.getFieldVoidCount(object, data));
    EXPECT_EQ(data.getVoidCount(), MINIMUM_ARRAY_SIZE);

    AddFieldsHelper::addField(object, JSONResponseFields::getVoidCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_TRUE(parser.getFieldVoidCount(object, data));
    EXPECT_EQ(data.getVoidCount(), MAXIMUM_ARRAY_SIZE);
}
TEST(JSONResponseParser, CheckGetRefundCount) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldRefundCount(object, data));

    auto lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getRefundCount(), lessMinimum);
    EXPECT_FALSE(parser.getFieldRefundCount(object, data));

    auto greatMaximum = MAXIMUM_ARRAY_SIZE + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getRefundCount(), greatMaximum);
    EXPECT_FALSE(parser.getFieldRefundCount(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getRefundCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_TRUE(parser.getFieldRefundCount(object, data));
    EXPECT_EQ(data.getRefundCount(), MINIMUM_ARRAY_SIZE);

    AddFieldsHelper::addField(object, JSONResponseFields::getRefundCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_TRUE(parser.getFieldRefundCount(object, data));
    EXPECT_EQ(data.getRefundCount(), MAXIMUM_ARRAY_SIZE);
}
/*
TEST(JSONResponseParser, CheckGetSalesArray) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldSalesArray(object, data));

    auto value;

    AddFieldsHelper::addField(object, JSONResponseFields::getSalesArray(), value);
    EXPECT_TRUE(parser.getFieldSalesArray(object, data));
    EXPECT_EQ(data.getSalesArray(), value);
}
TEST(JSONResponseParser, CheckGetVoidArray) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldVoidArray(object, data));

    auto value;

    AddFieldsHelper::addField(object, JSONResponseFields::getVoidArray(), value);
    EXPECT_TRUE(parser.getFieldVoidArray(object, data));
    EXPECT_EQ(data.getVoidArray(), value);
}
TEST(JSONResponseParser, CheckGetRefundArray) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldRefundArray(object, data));

    auto value;

    AddFieldsHelper::addField(object, JSONResponseFields::getRefundArray(), value);
    EXPECT_TRUE(parser.getFieldRefundArray(object, data));
    EXPECT_EQ(data.getRefundArray(), value);
}*/