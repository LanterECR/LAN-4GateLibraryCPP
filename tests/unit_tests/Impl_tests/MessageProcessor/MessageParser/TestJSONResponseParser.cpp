#include "gtest/gtest.h"

#include "Lanter/Utils/Constants.h"

#include "Lanter/Message/Response/ResponseData.h"
#include "Lanter/MessageProcessor/Parser/JSONResponseParser.h"

#include "Lanter/MessageProcessor/Builder/JSONAddFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFields/JSONResponseFields.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Parser;
using namespace Lanter::MessageProcessor::Builder;
using namespace Lanter::Utils;
using namespace Lanter::Utils::Constants;

TEST(TestJSONResponseParser, CheckInitMap) {
    JSONResponseParser parser;

    EXPECT_FALSE(parser.getFunctions().empty());

    auto count = (size_t)getLastResponseField() - (size_t)getFirstResponseField() +1;

    EXPECT_EQ(count, parser.getFunctions().size());
}

TEST(TestJSONResponseParser, CheckBasicResponse) {
    JSONResponseParser parser;

    std::string text = "{\"ApplicationLabel\":\"MIR Classic DBT\",\"CID\":\"00\",\"CardEmvAid\":\"A0000006581010\",\"CardInputMethod\":5,\"CardPAN\":\"************3968\",\"CardholderAuthMethod\":1,\"CardholderName\":\"MK TKK  DVL/TEST\",\"CurrencyCode\":643,\"EcrMerchantNumber\":1,\"EcrNumber\":1,\"ExpireDate\":\"2303\",\"IssuerName\":\"qwe\",\"MerchantId\":\"01000154\",\"OperationCode\":1,\"RRN\":\"209811337140\",\"ReceiptLine1\":\"11\",\"ReceiptLine2\":\"11\",\"ReceiptLine3\":\"ww\",\"ReceiptLine4\":\"qq\",\"ReceiptReference\":\"000046\",\"ResponseCode\":\"908\",\"ResponseText\":\"908\",\"Status\":2,\"TSI\":\"E800\",\"TVR\":\"0000048000\",\"TerminalDateTime\":\"20220408111205\",\"TerminalID\":\"01000154\",\"TotalAmount\":100,\"TransDateTime\":\"20220408111205\"}";
    Json::Value object;
    Json::Reader reader;
    EXPECT_TRUE(reader.parse( text, object ));

    ResponseData data;

    EXPECT_TRUE(parser.getFieldCurrencyCode(object, data));
    EXPECT_EQ(data.getCurrencyCode(),"643");
}

TEST(TestJSONResponseParser, CheckGetEcrNumber) {
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

TEST(TestJSONResponseParser, CheckGetEcrMerchantNumber) {
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

TEST(TestJSONResponseParser, CheckGetOperationCode) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldOperationCode(object, data));

    auto lessMinimum = (int)getFirstOperationCode() - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), lessMinimum);
    EXPECT_FALSE(parser.getFieldOperationCode(object, data));

    auto greatMaximum = (int)getLastOperationCode() + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), greatMaximum);
    EXPECT_FALSE(parser.getFieldOperationCode(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), (int)getFirstOperationCode());
    EXPECT_TRUE(parser.getFieldOperationCode(object, data));
    EXPECT_EQ((int)data.getOperationCode(), (int)getFirstOperationCode());

    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), (int)getLastOperationCode());
    EXPECT_TRUE(parser.getFieldOperationCode(object, data));
    EXPECT_EQ((int)data.getOperationCode(), (int)getLastOperationCode());
}

TEST(TestJSONResponseParser, CheckGetOriginalOperationCode) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldOriginalOperationCode(object, data));

    auto lessMinimum = (int)getFirstOperationCode() - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(), lessMinimum);
    EXPECT_FALSE(parser.getFieldOriginalOperationCode(object, data));

    auto greatMaximum = (int)getLastOperationCode() + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(), greatMaximum);
    EXPECT_FALSE(parser.getFieldOriginalOperationCode(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(), (int)getFirstOperationCode());
    EXPECT_TRUE(parser.getFieldOriginalOperationCode(object, data));
    EXPECT_EQ((int)data.getOriginalOperationCode(), (int)getFirstOperationCode());

    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(), (int)getLastOperationCode());
    EXPECT_TRUE(parser.getFieldOriginalOperationCode(object, data));
    EXPECT_EQ((int)data.getOriginalOperationCode(), (int)getLastOperationCode());
}

TEST(TestJSONResponseParser, CheckGetTotalAmount) {
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
TEST(TestJSONResponseParser, CheckGetPartialAmount) {
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
TEST(TestJSONResponseParser, CheckGetAcquirerFeeAmount) {
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
TEST(TestJSONResponseParser, CheckGetTerminalFeeAmount) {
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
TEST(TestJSONResponseParser, CheckGetTipsAmount) {
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

TEST(TestJSONResponseParser, CheckGetCurrencyCode) {
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

    AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(), std::to_string(MINIMUM_CURRENCY_CODE));
    EXPECT_TRUE(parser.getFieldCurrencyCode(object, data));
    EXPECT_EQ(data.getCurrencyCode(), std::to_string(MINIMUM_CURRENCY_CODE));

    AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(), std::to_string(MAXIMUM_CURRENCY_CODE));
    EXPECT_TRUE(parser.getFieldCurrencyCode(object, data));
    EXPECT_EQ(data.getCurrencyCode(), std::to_string(MAXIMUM_CURRENCY_CODE));
}

TEST(TestJSONResponseParser, CheckGetReceiptReference) {
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
TEST(TestJSONResponseParser, CheckGetRRN) {
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

TEST(TestJSONResponseParser, CheckGetStatus) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldStatus(object, data));

    auto lessMinimum = (int)getFirstStatus() - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), lessMinimum);
    EXPECT_FALSE(parser.getFieldStatus(object, data));

    auto greatMaximum = (int)getLastStatus() + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), greatMaximum);
    EXPECT_FALSE(parser.getFieldStatus(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), (int)getFirstStatus());
    EXPECT_TRUE(parser.getFieldStatus(object, data));
    EXPECT_EQ((int)data.getStatus(), (int)getFirstStatus());

    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), (int)getLastStatus());
    EXPECT_TRUE(parser.getFieldStatus(object, data));
    EXPECT_EQ((int)data.getStatus(), (int)getLastStatus());
}
TEST(TestJSONResponseParser, CheckGetOriginalOperationStatus) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldOriginalOperationStatus(object, data));

    auto lessMinimum = (int)getFirstStatus() - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationStatus(), lessMinimum);
    EXPECT_FALSE(parser.getFieldOriginalOperationStatus(object, data));

    auto greatMaximum = (int)getLastStatus() + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationStatus(), greatMaximum);
    EXPECT_FALSE(parser.getFieldOriginalOperationStatus(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationStatus(), (int)getFirstStatus());
    EXPECT_TRUE(parser.getFieldOriginalOperationStatus(object, data));
    EXPECT_EQ((int)data.getOriginalOperationStatus(), (int)getFirstStatus());

    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationStatus(), (int)getLastStatus());
    EXPECT_TRUE(parser.getFieldOriginalOperationStatus(object, data));
    EXPECT_EQ((int)data.getOriginalOperationStatus(), (int)getLastStatus());
}

TEST(TestJSONResponseParser, CheckGetTransDateTime) {
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
TEST(TestJSONResponseParser, CheckGetTerminalDateTime) {
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
TEST(TestJSONResponseParser, CheckGetCardPAN) {
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
TEST(TestJSONResponseParser, CheckGetExpireDate) {
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
TEST(TestJSONResponseParser, CheckGetCardholderName) {
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

TEST(TestJSONResponseParser, CheckGetCardholderAuthMethod) {
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

TEST(TestJSONResponseParser, CheckGetAuthCode) {
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
TEST(TestJSONResponseParser, CheckGetResponseCode) {
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
TEST(TestJSONResponseParser, CheckGetResponseText) {
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
TEST(TestJSONResponseParser, CheckGetSTAN) {
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
TEST(TestJSONResponseParser, CheckGetTransactionID) {
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
TEST(TestJSONResponseParser, CheckGetTerminalID) {
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
TEST(TestJSONResponseParser, CheckGetCardEmvAid) {
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
TEST(TestJSONResponseParser, CheckGetCardAppName) {
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

TEST(TestJSONResponseParser, CheckGetCardInputMethod) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCardInputMethod(object, data));

    auto lessMinimum = (int)getFirstCardInputMethod() - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(), lessMinimum);
    EXPECT_FALSE(parser.getFieldCardInputMethod(object, data));

    auto greatMaximum = (int)getLastCardInputMethod() + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(), greatMaximum);
    EXPECT_FALSE(parser.getFieldCardInputMethod(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(), (int)getFirstCardInputMethod());
    EXPECT_TRUE(parser.getFieldCardInputMethod(object, data));
    EXPECT_EQ((int)data.getCardInputMethod(), (int)getFirstCardInputMethod());

    AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(), (int)getLastCardInputMethod());
    EXPECT_TRUE(parser.getFieldCardInputMethod(object, data));
    EXPECT_EQ((int)data.getCardInputMethod(), (int)getLastCardInputMethod());
}

TEST(TestJSONResponseParser, CheckGetIssuerName) {
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
TEST(TestJSONResponseParser, CheckGetAdditionalInfo) {
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
TEST(TestJSONResponseParser, CheckGetCardData) {
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
TEST(TestJSONResponseParser, CheckGetCardDataEnc) {
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
TEST(TestJSONResponseParser, CheckGetMerchantID) {
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
TEST(TestJSONResponseParser, CheckGetTVR) {
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
TEST(TestJSONResponseParser, CheckGetTSI) {
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
TEST(TestJSONResponseParser, CheckGetTC) {
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
TEST(TestJSONResponseParser, CheckGetCID) {
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
TEST(TestJSONResponseParser, CheckGetKVR) {
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
TEST(TestJSONResponseParser, CheckGetCDAResult) {
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

TEST(TestJSONResponseParser, CheckgetSalesCount) {
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
TEST(TestJSONResponseParser, CheckGetVoidCount) {
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
TEST(TestJSONResponseParser, CheckGetRefundCount) {
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

TEST(TestJSONResponseParser, CheckGetSalesArray) {
    JSONResponseParser parser;

    Json::Value object;
    ResponseData data;

    EXPECT_FALSE(parser.getFieldSalesArray(object, data));

    Json::Value array;

    Json::Value element;
    AddFieldsHelper::addField(element, JSONResponseFields::getTotalAmount(), MAXIMUM_AMOUNT);
    AddFieldsHelper::addField(element, JSONResponseFields::getCurrencyCode(),MAXIMUM_CURRENCY_CODE);
    AddFieldsHelper::addField(element, JSONResponseFields::getRRN(), std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getReceiptReference(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getResponseCode(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getTransactionID(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getTransDateTime(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getIssuerName(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getCardPAN(),std::string("Значение"));

    AddFieldsHelper::addArrayElement(array, element);
    AddFieldsHelper::addArrayElement(array, element);

    AddFieldsHelper::addField(object, JSONResponseFields::getSalesArray(), array);

    EXPECT_TRUE(parser.getFieldSalesArray(object, data));

    EXPECT_EQ(array.size(), data.getSalesArray().size());

    for(auto i : data.getSalesArray())
    {
        EXPECT_FALSE(i->isFieldSet(Lanter::Message::Response::ResponseField::OperationCode));
    }
}

TEST(TestJSONResponseParser, CheckGetVoidArray)
{
    JSONResponseParser parser;

    Json::Value object;
    ResponseData data;

    EXPECT_FALSE(parser.getFieldVoidArray(object, data));

    Json::Value array;

    Json::Value element;
    AddFieldsHelper::addField(element, JSONResponseFields::getTotalAmount(), MAXIMUM_AMOUNT);
    AddFieldsHelper::addField(element, JSONResponseFields::getCurrencyCode(),MAXIMUM_CURRENCY_CODE);
    AddFieldsHelper::addField(element, JSONResponseFields::getRRN(), std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getReceiptReference(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getResponseCode(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getTransactionID(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getTransDateTime(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getIssuerName(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getCardPAN(),std::string("Значение"));

    AddFieldsHelper::addArrayElement(array, element);
    AddFieldsHelper::addArrayElement(array, element);

    AddFieldsHelper::addField(object, JSONResponseFields::getVoidArray(), array);

    EXPECT_TRUE(parser.getFieldVoidArray(object, data));

    EXPECT_EQ(array.size(), data.getVoidArray().size());

    for(auto i : data.getVoidArray()) {
        EXPECT_FALSE(i->isFieldSet(Lanter::Message::Response::ResponseField::OperationCode));
    }
}
TEST(TestJSONResponseParser, CheckGetRefundArray) {
    JSONResponseParser parser;

    Json::Value object;
    ResponseData data;

    EXPECT_FALSE(parser.getFieldRefundArray(object, data));

    Json::Value array;

    Json::Value element;
    AddFieldsHelper::addField(element, JSONResponseFields::getTotalAmount(), MAXIMUM_AMOUNT);
    AddFieldsHelper::addField(element, JSONResponseFields::getCurrencyCode(),MAXIMUM_CURRENCY_CODE);
    AddFieldsHelper::addField(element, JSONResponseFields::getRRN(), std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getReceiptReference(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getResponseCode(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getTransactionID(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getTransDateTime(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getIssuerName(),std::string("Значение"));
    AddFieldsHelper::addField(element, JSONResponseFields::getCardPAN(),std::string("Значение"));

    AddFieldsHelper::addArrayElement(array, element);
    AddFieldsHelper::addArrayElement(array, element);

    AddFieldsHelper::addField(object, JSONResponseFields::getRefundArray(), array);

    EXPECT_TRUE(parser.getFieldRefundArray(object, data));

    EXPECT_EQ(array.size(), data.getRefundArray().size());

    for(auto i : data.getRefundArray()) {
        EXPECT_FALSE(i->isFieldSet(Lanter::Message::Response::ResponseField::OperationCode));
    }
}

TEST(TestJSONResponseParser, CheckParseData) {
    JSONResponseParser parser;

    Json::Value object;

    EXPECT_EQ(parser.parseData(object), nullptr);

    auto operationCode = OperationCode::PrintDetailReport;
    auto ecrNumber = MAXIMUM_ECR_NUMBER;
    auto status = Status::Success;
    int64_t totalAmount = MAXIMUM_AMOUNT;
    auto currencyCode = MAXIMUM_CURRENCY_CODE;

    std::string terminalID = "Значение";
    std::string merchantID = "Значение";
    std::string terminalDateTime = "Значение";
    std::string rrn = "Значение";
    std::string receiptReference = "Значение";
    std::string responseCode = "Значение";
    std::string transactionID = "Значение";
    std::string issuerName = "Значение";
    std::string transactionDateTime = "Значение";
    std::string cardPan = "Значение";
    int salesCount = 2;
    int voidCount = 2;
    int refundCount = 2;

    Json::Value array;

    Json::Value element;
    AddFieldsHelper::addField(element, JSONResponseFields::getTotalAmount(), MAXIMUM_AMOUNT);
    AddFieldsHelper::addField(element, JSONResponseFields::getCurrencyCode(),MAXIMUM_CURRENCY_CODE);
    AddFieldsHelper::addField(element, JSONResponseFields::getRRN(), rrn);
    AddFieldsHelper::addField(element, JSONResponseFields::getReceiptReference(), rrn);
    AddFieldsHelper::addField(element, JSONResponseFields::getResponseCode(), responseCode);
    AddFieldsHelper::addField(element, JSONResponseFields::getTransactionID(), transactionID);
    AddFieldsHelper::addField(element, JSONResponseFields::getTransDateTime(), transactionDateTime);
    AddFieldsHelper::addField(element, JSONResponseFields::getIssuerName(), issuerName);
    AddFieldsHelper::addField(element, JSONResponseFields::getCardPAN(), cardPan);

    AddFieldsHelper::addArrayElement(array, element);
    AddFieldsHelper::addArrayElement(array, element);

    AddFieldsHelper::addField(object, JSONResponseFields::getSalesArray(), array);
    AddFieldsHelper::addField(object, JSONResponseFields::getVoidArray(), array);
    AddFieldsHelper::addField(object, JSONResponseFields::getRefundArray(), array);

    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), (int)operationCode);
    AddFieldsHelper::addField(object, JSONResponseFields::getEcrNumber(), ecrNumber);
    AddFieldsHelper::addField(object, JSONResponseFields::getTotalAmount(), totalAmount);
    AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(), currencyCode);
    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalID(), terminalID);
    AddFieldsHelper::addField(object, JSONResponseFields::getMerchantID(), merchantID);
    AddFieldsHelper::addField(object, JSONResponseFields::getSalesCount(), salesCount);
    AddFieldsHelper::addField(object, JSONResponseFields::getVoidCount(), voidCount);
    AddFieldsHelper::addField(object, JSONResponseFields::getRefundCount(), refundCount);
    AddFieldsHelper::addField(object, JSONResponseFields::getSalesArray(), array);
    AddFieldsHelper::addField(object, JSONResponseFields::getVoidArray(), array);
    AddFieldsHelper::addField(object, JSONResponseFields::getRefundArray(), array);

    EXPECT_EQ(parser.parseData(object), nullptr);

    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), (int)status);
    auto data = parser.parseData(object);


    EXPECT_NE(data, nullptr);

    /*EXPECT_EQ(data->getOperationCode(), operationCode);
    EXPECT_EQ(data->getEcrNumber(), ecrNumber);
    EXPECT_EQ(data->getCurrencyCode(), currencyCode);
    EXPECT_EQ(data->getEcrMerchantNumber(), ecrMerchantNumber);
    EXPECT_EQ(data->getAmount(), amount);

    EXPECT_EQ(data->getFieldsSet().find(ResponseField::OpenTags), data->getFieldsSet().end());*/
}

TEST(TestJSONResponseParser, CheckGetBonusBalance) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldBonusBalance(object, data));

    auto lessMinimum = MINIMUM_AMOUNT - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getBonusBalance(), lessMinimum);
    EXPECT_FALSE(parser.getFieldBonusBalance(object, data));

    auto greatMaximum = MAXIMUM_AMOUNT + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getBonusBalance(), greatMaximum);
    EXPECT_FALSE(parser.getFieldBonusBalance(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getBonusBalance(), MINIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldBonusBalance(object, data));
    EXPECT_EQ(data.getBonusBalance(), MINIMUM_AMOUNT);

    AddFieldsHelper::addField(object, JSONResponseFields::getBonusBalance(), MAXIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldBonusBalance(object, data));
    EXPECT_EQ(data.getBonusBalance(), MAXIMUM_AMOUNT);
}

TEST(TestJSONResponseParser, CheckGetBonusAmount) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldBonusAmount(object, data));

    auto lessMinimum = MINIMUM_AMOUNT - 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getBonusAmount(), lessMinimum);
    EXPECT_FALSE(parser.getFieldBonusAmount(object, data));

    auto greatMaximum = MAXIMUM_AMOUNT + 1;
    AddFieldsHelper::addField(object, JSONResponseFields::getBonusAmount(), greatMaximum);
    EXPECT_FALSE(parser.getFieldBonusAmount(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getBonusAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldBonusAmount(object, data));
    EXPECT_EQ(data.getBonusAmount(), MINIMUM_AMOUNT);

    AddFieldsHelper::addField(object, JSONResponseFields::getBonusAmount(), MAXIMUM_AMOUNT);
    EXPECT_TRUE(parser.getFieldBonusAmount(object, data));
    EXPECT_EQ(data.getBonusAmount(), MAXIMUM_AMOUNT);
}

TEST(TestJSONResponseParser, CheckGetCardPANHash) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldCardPANHash(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getCardPANHash(), empty);
    EXPECT_FALSE(parser.getFieldCardPANHash(object, data));

    std::string maxSize(16+1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getCardPANHash(), maxSize);
    EXPECT_TRUE(parser.getFieldCardPANHash(object, data));
    EXPECT_STREQ(data.getCardPANHash().c_str(), maxSize.c_str());
}

TEST(TestJSONResponseParser, CheckGetReceiptLine1) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldReceiptLine1(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine1(), empty);
    EXPECT_FALSE(parser.getFieldReceiptLine1(object, data));

    std::string maxSize(16+1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine1(), maxSize);
    EXPECT_TRUE(parser.getFieldReceiptLine1(object, data));
    EXPECT_STREQ(data.getReceiptLine1().c_str(), maxSize.c_str());
}

TEST(TestJSONResponseParser, CheckGetReceiptLine2) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldReceiptLine2(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine2(), empty);
    EXPECT_FALSE(parser.getFieldReceiptLine2(object, data));

    std::string maxSize(16+1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine2(), maxSize);
    EXPECT_TRUE(parser.getFieldReceiptLine2(object, data));
    EXPECT_STREQ(data.getReceiptLine2().c_str(), maxSize.c_str());
}

TEST(TestJSONResponseParser, CheckGetReceiptLine3) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldReceiptLine3(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine3(), empty);
    EXPECT_FALSE(parser.getFieldReceiptLine3(object, data));

    std::string maxSize(16+1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine3(), maxSize);
    EXPECT_TRUE(parser.getFieldReceiptLine3(object, data));
    EXPECT_STREQ(data.getReceiptLine3().c_str(), maxSize.c_str());
}

TEST(TestJSONResponseParser, CheckGetReceiptLine4) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldReceiptLine4(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine4(), empty);
    EXPECT_FALSE(parser.getFieldReceiptLine4(object, data));

    std::string maxSize(16+1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine4(), maxSize);
    EXPECT_TRUE(parser.getFieldReceiptLine4(object, data));
    EXPECT_STREQ(data.getReceiptLine4().c_str(), maxSize.c_str());
}

TEST(TestJSONResponseParser, CheckGetReceiptLine5) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldReceiptLine5(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine5(), empty);
    EXPECT_FALSE(parser.getFieldReceiptLine5(object, data));

    std::string maxSize(16+1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine5(), maxSize);
    EXPECT_TRUE(parser.getFieldReceiptLine5(object, data));
    EXPECT_STREQ(data.getReceiptLine5().c_str(), maxSize.c_str());
}

TEST(TestJSONResponseParser, CheckGetApplicationLabel) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldApplicationLabel(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getApplicationLabel(), empty);
    EXPECT_FALSE(parser.getFieldApplicationLabel(object, data));

    std::string maxSize(16+1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getApplicationLabel(), maxSize);
    EXPECT_TRUE(parser.getFieldApplicationLabel(object, data));
    EXPECT_STREQ(data.getApplicationLabel().c_str(), maxSize.c_str());
}

TEST(TestJSONResponseParser, CheckGetHashCardTrack2) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldHashCardTrack2(object, data));

    std::string empty;

    AddFieldsHelper::addField(object, JSONResponseFields::getHashCardTrack2(), empty);
    EXPECT_FALSE(parser.getFieldHashCardTrack2(object, data));

    std::string maxSize(16+1024, 'a');
    AddFieldsHelper::addField(object, JSONResponseFields::getHashCardTrack2(), maxSize);
    EXPECT_TRUE(parser.getFieldHashCardTrack2(object, data));
    EXPECT_STREQ(data.getHashCardTrack2().c_str(), maxSize.c_str());
}

TEST(TestJSONResponseParser, CheckGetFinalizationRequired) {
    JSONResponseParser parser;

    Json::Value object;

    ResponseData data;

    EXPECT_FALSE(parser.getFieldFinalizationRequired(object, data));

    AddFieldsHelper::addField(object, JSONResponseFields::getFinalizationRequired(), true);
    EXPECT_TRUE(parser.getFieldFinalizationRequired(object, data));
    EXPECT_TRUE(data.getFinalizationRequired());

    AddFieldsHelper::addField(object, JSONResponseFields::getFinalizationRequired(), 1);
    EXPECT_TRUE(parser.getFieldFinalizationRequired(object, data));
    EXPECT_TRUE(data.getFinalizationRequired());

    AddFieldsHelper::addField(object, JSONResponseFields::getFinalizationRequired(), false);
    EXPECT_TRUE(parser.getFieldFinalizationRequired(object, data));
    EXPECT_FALSE(data.getFinalizationRequired());

    AddFieldsHelper::addField(object, JSONResponseFields::getFinalizationRequired(), 0);
    EXPECT_TRUE(parser.getFieldFinalizationRequired(object, data));
    EXPECT_FALSE(data.getFinalizationRequired());
}

/*
FinalizationRequired*/