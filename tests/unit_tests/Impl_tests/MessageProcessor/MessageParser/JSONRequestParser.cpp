//
// Created by Lysenkov on 17.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Parser/JSONRequestParser.h"
#include "Lanter/MessageProcessor/JSONMessageFields.h"
#include "Lanter/Message/Request/RequestData.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Parser;

TEST(JSONRequestParser, CheckInitMap) {
    JSONRequestParser parser;

    EXPECT_FALSE(parser.getFunctions().empty());

    auto count = (size_t)RequestField::LastValue - (size_t)RequestField::FirstValue +1;

    EXPECT_EQ(count, parser.getFunctions().size());
}
TEST(JSONRequestParser, CheckGetFieldEcrNumber) {
    JSONRequestParser parser;

    auto badValueLess = -1;
    auto badValueGreat = 1000;
    auto goodValue = 1;

    RequestData data;
    Json::Value object;

    object[JSONRequestFields::getEcrNumber()] = badValueLess;

    EXPECT_FALSE(parser.getFieldEcrNumber(object, data));

    object[JSONRequestFields::getEcrNumber()] = badValueGreat;

    EXPECT_FALSE(parser.getFieldEcrNumber(object, data));

    object[JSONRequestFields::getEcrNumber()] = goodValue;

    EXPECT_TRUE(parser.getFieldEcrNumber(object, data));

    EXPECT_EQ(data.getEcrNumber(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldEcrMerchantNumber) {
    JSONRequestParser parser;

    auto badValueLess = -1;
    auto badValueGreat = 1000;
    auto goodValue = 1;

    RequestData data;

    Json::Value object;

    object[JSONRequestFields::getEcrMerchantNumber()] = badValueLess;

    EXPECT_FALSE(parser.getFieldEcrMerchantNumber(object, data));

    object[JSONRequestFields::getEcrMerchantNumber()] = badValueGreat;

    EXPECT_FALSE(parser.getFieldEcrMerchantNumber(object, data));

    object[JSONRequestFields::getEcrMerchantNumber()] = goodValue;

    EXPECT_TRUE(parser.getFieldEcrMerchantNumber(object, data));

    EXPECT_EQ(data.getEcrMerchantNumber(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldOperationCode) {
    JSONRequestParser parser;

    auto badValueLess = (int) OperationCode::FirstValue - 1;
    auto badValueGreat = (int) OperationCode::LastValue + 1;
    auto goodValue = (int)OperationCode::FirstValue;

    RequestData data;

    Json::Value object;

    object[JSONRequestFields::getOperationCode()] = badValueLess;

    EXPECT_FALSE(parser.getFieldOperationCode(object, data));

    object[JSONRequestFields::getOperationCode()] = badValueGreat;

    EXPECT_FALSE(parser.getFieldOperationCode(object, data));

    object[JSONRequestFields::getOperationCode()] = goodValue;

    EXPECT_TRUE(parser.getFieldOperationCode(object, data));

    EXPECT_EQ((int)data.getOperationCode(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldAmount) {
    JSONRequestParser parser;

    int64_t badValueLess = -1;
    int64_t badValueGreat = 1000000000000;
    int64_t goodValue = 999999999999;

    RequestData data;

    Json::Value object;

    object[JSONRequestFields::getAmount()] = badValueLess;

    EXPECT_FALSE(parser.getFieldAmount(object, data));

    object[JSONRequestFields::getAmount()] = badValueGreat;

    EXPECT_FALSE(parser.getFieldAmount(object, data));

    object[JSONRequestFields::getAmount()] = goodValue;

    EXPECT_TRUE(parser.getFieldAmount(object, data));

    EXPECT_EQ(data.getAmount(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldPartialAmount) {
    JSONRequestParser parser;

    int64_t badValueLess = -1;
    int64_t badValueGreat = 1000000000000;
    int64_t goodValue = 999999999999;

    RequestData data;

    Json::Value object;

    object[JSONRequestFields::getPartialAmount()] = badValueLess;

    EXPECT_FALSE(parser.getFieldPartialAmount(object, data));

    object[JSONRequestFields::getPartialAmount()] = badValueGreat;

    EXPECT_FALSE(parser.getFieldPartialAmount(object, data));

    object[JSONRequestFields::getPartialAmount()] = goodValue;

    EXPECT_TRUE(parser.getFieldPartialAmount(object, data));

    EXPECT_EQ(data.getPartialAmount(), goodValue);
}
TEST(JSONRequestParser, CheckGetFieldTipsAmount) {
    JSONRequestParser parser;

    int64_t badValueLess = -1;
    int64_t badValueGreat = 1000000000000;
    int64_t goodValue = 999999999999;

    RequestData data;

    Json::Value object;

    object[JSONRequestFields::getTipsAmount()] = badValueLess;

    EXPECT_FALSE(parser.getFieldTipsAmount(object, data));

    object[JSONRequestFields::getTipsAmount()] = badValueGreat;

    EXPECT_FALSE(parser.getFieldTipsAmount(object, data));

    object[JSONRequestFields::getTipsAmount()] = goodValue;

    EXPECT_TRUE(parser.getFieldTipsAmount(object, data));

    EXPECT_EQ(data.getTipsAmount(), goodValue);
}
TEST(JSONRequestParser, CheckGetFieldCashbackAmount) {
    JSONRequestParser parser;

    int64_t badValueLess = -1;
    int64_t badValueGreat = 1000000000000;
    int64_t goodValue = 999999999999;

    RequestData data;

    Json::Value object;

    object[JSONRequestFields::getCashbackAmount()] = badValueLess;

    EXPECT_FALSE(parser.getFieldCashbackAmount(object, data));

    object[JSONRequestFields::getCashbackAmount()] = badValueGreat;

    EXPECT_FALSE(parser.getFieldCashbackAmount(object, data));

    object[JSONRequestFields::getCashbackAmount()] = goodValue;

    EXPECT_TRUE(parser.getFieldCashbackAmount(object, data));

    EXPECT_EQ(data.getCashbackAmount(), goodValue);
}
TEST(JSONRequestParser, CheckGetFieldCurrencyCode) {
    JSONRequestParser parser;

    auto badValueLess = -1;
    auto badValueGreat = 1000;
    auto goodValue = 1;

    RequestData data;

    Json::Value object;

    object[JSONRequestFields::getCurrencyCode()] = badValueLess;

    EXPECT_FALSE(parser.getFieldCurrencyCode(object, data));

    object[JSONRequestFields::getCurrencyCode()] = badValueGreat;

    EXPECT_FALSE(parser.getFieldCurrencyCode(object, data));

    object[JSONRequestFields::getCurrencyCode()] = goodValue;

    EXPECT_TRUE(parser.getFieldCurrencyCode(object, data));

    EXPECT_EQ(data.getCurrencyCode(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldRRN) {
    JSONRequestParser parser;

    auto badValue = "";
    auto goodValue = "Тестовое значение";

    RequestData data;

    Json::Value object;
    object[JSONRequestFields::getRRN()] = badValue;

    EXPECT_FALSE(parser.getFieldRRN(object, data));

    object[JSONRequestFields::getRRN()] = goodValue;

    EXPECT_TRUE(parser.getFieldRRN(object, data));

    EXPECT_STREQ(data.getRRN().c_str(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldAuthCode) {
    JSONRequestParser parser;

    auto badValue = "";
    auto goodValue = "Тестовое значение";

    RequestData data;

    Json::Value object;
    object[JSONRequestFields::getAuthCode()] = badValue;

    EXPECT_FALSE(parser.getFieldAuthCode(object, data));

    object[JSONRequestFields::getAuthCode()] = goodValue;

    EXPECT_TRUE(parser.getFieldAuthCode(object, data));

    EXPECT_STREQ(data.getAuthCode().c_str(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldReceiptReference) {
    JSONRequestParser parser;

    auto badValue = "";
    auto goodValue = "Тестовое значение";

    RequestData data;

    Json::Value object;
    object[JSONRequestFields::getReceiptReference()] = badValue;

    EXPECT_FALSE(parser.getFieldReceiptReference(object, data));

    object[JSONRequestFields::getReceiptReference()] = goodValue;

    EXPECT_TRUE(parser.getFieldReceiptReference(object, data));

    EXPECT_STREQ(data.getReceiptReference().c_str(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldTransactionID) {
    JSONRequestParser parser;

    auto badValue = "";
    auto goodValue = "Тестовое значение";

    RequestData data;

    Json::Value object;
    object[JSONRequestFields::getTransactionID()] = badValue;

    EXPECT_FALSE(parser.getFieldTransactionID(object, data));

    object[JSONRequestFields::getTransactionID()] = goodValue;

    EXPECT_TRUE(parser.getFieldTransactionID(object, data));

    EXPECT_STREQ(data.getTransactionID().c_str(), goodValue);
}
TEST(JSONRequestParser, CheckGetFieldCardDataEnc) {
    JSONRequestParser parser;

    auto badValue = "";
    auto goodValue = "Тестовое значение";

    RequestData data;

    Json::Value object;
    object[JSONRequestFields::getCardDataEnc()] = badValue;

    EXPECT_FALSE(parser.getFieldCardDataEnc(object, data));

    object[JSONRequestFields::getCardDataEnc()] = goodValue;

    EXPECT_TRUE(parser.getFieldCardDataEnc(object, data));

    EXPECT_STREQ(data.getCardDataEnc().c_str(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldOpenTags) {
    JSONRequestParser parser;

    auto badValue = "";
    auto goodValue = "Тестовое значение";

    RequestData data;

    Json::Value object;
    object[JSONRequestFields::getOpenTags()] = badValue;

    EXPECT_FALSE(parser.getFieldOpenTags(object, data));

    object[JSONRequestFields::getOpenTags()] = goodValue;

    EXPECT_TRUE(parser.getFieldOpenTags(object, data));

    EXPECT_STREQ(data.getOpenTags().c_str(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldEncTags) {
    JSONRequestParser parser;

    auto badValue = "";
    auto goodValue = "Тестовое значение";

    RequestData data;

    Json::Value object;
    object[JSONRequestFields::getEncTags()] = badValue;

    EXPECT_FALSE(parser.getFieldEncTags(object, data));

    object[JSONRequestFields::getEncTags()] = goodValue;

    EXPECT_TRUE(parser.getFieldEncTags(object, data));

    EXPECT_STREQ(data.getEncTags().c_str(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldProviderCode) {
    JSONRequestParser parser;

    auto badValue = "";
    auto goodValue = "Тестовое значение";

    RequestData data;

    Json::Value object;
    object[JSONRequestFields::getProviderCode()] = badValue;

    EXPECT_FALSE(parser.getFieldProviderCode(object, data));

    object[JSONRequestFields::getProviderCode()] = goodValue;

    EXPECT_TRUE(parser.getFieldProviderCode(object, data));

    EXPECT_STREQ(data.getProviderCode().c_str(), goodValue);

}
TEST(JSONRequestParser, CheckGetFieldAdditionalInfo) {
    JSONRequestParser parser;

    auto badValue = "";
    auto goodValue = "Тестовое значение";

    RequestData data;

    Json::Value object;
    object[JSONRequestFields::getAdditionalInfo()] = badValue;

    EXPECT_FALSE(parser.getFieldAdditionalInfo(object, data));

    object[JSONRequestFields::getAdditionalInfo()] = goodValue;

    EXPECT_TRUE(parser.getFieldAdditionalInfo(object, data));

    EXPECT_STREQ(data.getAdditionalInfo().c_str(), goodValue);

}

TEST(JSONRequestParser, CheckParseData) {
    JSONRequestParser parser;

    Json::Value object;

    auto operationCode = OperationCode::Sale;
    auto ecrNumber = 1;
    auto ecrMerchantNumber = 2;
    int64_t amount = 999999999999;
    auto currencyCode = 643;

    auto openTags = "Значение";

    EXPECT_EQ(parser.parseData(object), nullptr);

    object[JSONRequestFields::getOpenTags()] = openTags;

    EXPECT_EQ(parser.parseData(object), nullptr);

    object[JSONRequestFields::getOperationCode()] = (int)operationCode;

    EXPECT_EQ(parser.parseData(object), nullptr);

    object[JSONRequestFields::getEcrNumber()] = ecrNumber;

    EXPECT_EQ(parser.parseData(object), nullptr);

    object[JSONRequestFields::getEcrMerchantNumber()] = ecrMerchantNumber;

    EXPECT_EQ(parser.parseData(object), nullptr);

    object[JSONRequestFields::getAmount()] = amount;

    EXPECT_EQ(parser.parseData(object), nullptr);

    object[JSONRequestFields::getCurrencyCode()] = currencyCode;

    auto data = parser.parseData(object);

    EXPECT_NE(data, nullptr);

    EXPECT_EQ(data->getOperationCode(), operationCode);
    EXPECT_EQ(data->getEcrNumber(), ecrNumber);
    EXPECT_EQ(data->getEcrMerchantNumber(), ecrMerchantNumber);
    EXPECT_EQ(data->getAmount(), amount);
    EXPECT_EQ(data->getCurrencyCode(), currencyCode);

    EXPECT_EQ(data->getFieldsSet().find(RequestField::OpenTags), data->getFieldsSet().end());
}