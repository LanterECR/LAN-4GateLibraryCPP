#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Builder/JSONRequestBuilder.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"

#include "Lanter/Message/Request/RequestDataFactory.h"

#include "Lanter/Message/Request/RequestData.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Builder;

TEST(TestJSONRequestBuilder, CheckFunctionInit) {
    JSONRequestBuilder builder;

    EXPECT_FALSE(builder.getFunctions().empty());

    int fieldsCount = (int)getLastRequestField() - (int)getFirstRequestField() + 1;

    EXPECT_EQ(builder.getFunctions().size(), fieldsCount);
}

TEST(TestJSONRequestBuilder, CheckAddFieldEcrNumber) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setEcrNumber(1);

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldEcrNumber(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getEcrNumber()));
    EXPECT_EQ(data.getEcrNumber(), directObject[JSONRequestFields::getEcrNumber()].asInt());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::EcrNumber);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getEcrNumber()));
    EXPECT_EQ(data.getEcrNumber(), listObject[JSONRequestFields::getEcrNumber()].asInt());
}

TEST(TestJSONRequestBuilder, CheckAddFieldEcrMerchantNumber) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setEcrMerchantNumber(1);

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldEcrMerchantNumber(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getEcrMerchantNumber()));
    EXPECT_EQ(data.getEcrMerchantNumber(), directObject[JSONRequestFields::getEcrMerchantNumber()].asInt());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::EcrMerchantNumber);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getEcrMerchantNumber()));
    EXPECT_EQ(data.getEcrMerchantNumber(), listObject[JSONRequestFields::getEcrMerchantNumber()].asInt());
}

TEST(TestJSONRequestBuilder, CheckAddFieldOperationCode) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setOperationCode(getFirstOperationCode());

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldOperationCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getOperationCode()));
    EXPECT_EQ((int)data.getOperationCode(), directObject[JSONRequestFields::getOperationCode()].asInt());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::OperationCode);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getOperationCode()));
    EXPECT_EQ((int)data.getOperationCode(), listObject[JSONRequestFields::getOperationCode()].asInt());
}

TEST(TestJSONRequestBuilder, CheckAddFieldAmount) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setAmount(999999999999);

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getAmount()));
    EXPECT_EQ(data.getAmount(), directObject[JSONRequestFields::getAmount()].asInt64());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::Amount);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getAmount()));
    EXPECT_EQ(data.getAmount(), listObject[JSONRequestFields::getAmount()].asInt64());
}

TEST(TestJSONRequestBuilder, CheckAddFieldPartialAmount) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setPartialAmount(999999999999);

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldPartialAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getPartialAmount()));
    EXPECT_EQ(data.getPartialAmount(), directObject[JSONRequestFields::getPartialAmount()].asInt64());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::PartialAmount);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getPartialAmount()));
    EXPECT_EQ(data.getPartialAmount(), listObject[JSONRequestFields::getPartialAmount()].asInt64());
}

TEST(TestJSONRequestBuilder, CheckAddFieldTipsAmount) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setTipsAmount(999999999999);

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldTipsAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getTipsAmount()));
    EXPECT_EQ(data.getTipsAmount(), directObject[JSONRequestFields::getTipsAmount()].asInt64());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::TipsAmount);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getTipsAmount()));
    EXPECT_EQ(data.getTipsAmount(), listObject[JSONRequestFields::getTipsAmount()].asInt64());
}

TEST(TestJSONRequestBuilder, CheckAddFieldCashbackAmount) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setCashbackAmount(999999999999);

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldCashbackAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getCashbackAmount()));
    EXPECT_EQ(data.getCashbackAmount(), directObject[JSONRequestFields::getCashbackAmount()].asInt64());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::CashbackAmount);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getCashbackAmount()));
    EXPECT_EQ(data.getCashbackAmount(), listObject[JSONRequestFields::getCashbackAmount()].asInt64());
}

TEST(TestJSONRequestBuilder, CheckAddFieldCurrencyCode) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setCurrencyCode("1");

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldCurrencyCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getCurrencyCode()));
    EXPECT_EQ(data.getCurrencyCode(), directObject[JSONRequestFields::getCurrencyCode()].asString());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::CurrencyCode);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getCurrencyCode()));
    EXPECT_EQ(data.getCurrencyCode(), listObject[JSONRequestFields::getCurrencyCode()].asString());
}

TEST(TestJSONRequestBuilder, CheckAddFieldRRN) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setRRN("1234");

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldRRN(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getRRN()));
    EXPECT_STREQ(data.getRRN().c_str(), directObject[JSONRequestFields::getRRN()].asString().c_str());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::RRN);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getRRN()));
    EXPECT_STREQ(data.getRRN().c_str(), listObject[JSONRequestFields::getRRN()].asString().c_str());
}

TEST(TestJSONRequestBuilder, CheckAddFieldAuthCode) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setAuthCode("1234");

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldAuthCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getAuthCode()));
    EXPECT_STREQ(data.getAuthCode().c_str(), directObject[JSONRequestFields::getAuthCode()].asString().c_str());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::AuthCode);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getAuthCode()));
    EXPECT_STREQ(data.getAuthCode().c_str(), listObject[JSONRequestFields::getAuthCode()].asString().c_str());
}

TEST(TestJSONRequestBuilder, CheckAddFieldReceiptReference) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setReceiptReference("1234");

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldReceiptReference(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getReceiptReference()));
    EXPECT_STREQ(data.getReceiptReference().c_str(), directObject[JSONRequestFields::getReceiptReference()].asString().c_str());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::ReceiptReference);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getReceiptReference()));
    EXPECT_STREQ(data.getReceiptReference().c_str(), listObject[JSONRequestFields::getReceiptReference()].asString().c_str());
}
TEST(TestJSONRequestBuilder, CheckAddFieldTransactionID) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setTransactionID("1234");

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldTransactionID(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getTransactionID()));
    EXPECT_STREQ(data.getTransactionID().c_str(), directObject[JSONRequestFields::getTransactionID()].asString().c_str());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::TransactionID);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getTransactionID()));
    EXPECT_STREQ(data.getTransactionID().c_str(), listObject[JSONRequestFields::getTransactionID()].asString().c_str());
}
TEST(TestJSONRequestBuilder, CheckAddFieldCardDataEnc) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setCardDataEnc("1234");

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldCardDataEnc(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getCardDataEnc()));
    EXPECT_STREQ(data.getCardDataEnc().c_str(), directObject[JSONRequestFields::getCardDataEnc()].asString().c_str());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::CardDataEnc);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getCardDataEnc()));
    EXPECT_STREQ(data.getCardDataEnc().c_str(), listObject[JSONRequestFields::getCardDataEnc()].asString().c_str());
}
TEST(TestJSONRequestBuilder, CheckAddFieldOpenTags) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setOpenTags("1234");

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldOpenTags(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getOpenTags()));
    EXPECT_STREQ(data.getOpenTags().c_str(), directObject[JSONRequestFields::getOpenTags()].asString().c_str());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::OpenTags);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getOpenTags()));
    EXPECT_STREQ(data.getOpenTags().c_str(), listObject[JSONRequestFields::getOpenTags()].asString().c_str());
}
TEST(TestJSONRequestBuilder, CheckAddFieldEncTags) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setOpenTags("1234");

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldOpenTags(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getOpenTags()));
    EXPECT_STREQ(data.getOpenTags().c_str(), directObject[JSONRequestFields::getOpenTags()].asString().c_str());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::OpenTags);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getOpenTags()));
    EXPECT_STREQ(data.getOpenTags().c_str(), listObject[JSONRequestFields::getOpenTags()].asString().c_str());
}
TEST(TestJSONRequestBuilder, CheckAddFieldProviderCode) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setProviderCode("1234");

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldProviderCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getProviderCode()));
    EXPECT_STREQ(data.getProviderCode().c_str(), directObject[JSONRequestFields::getProviderCode()].asString().c_str());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::ProviderCode);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getProviderCode()));
    EXPECT_STREQ(data.getProviderCode().c_str(), listObject[JSONRequestFields::getProviderCode()].asString().c_str());
}
TEST(TestJSONRequestBuilder, CheckAddFieldAdditionalInfo) {
    JSONRequestBuilder builder;

    RequestData data;
    data.setAdditionalInfo("1234");

    Json::Value directObject;
    EXPECT_TRUE(builder.addFieldAdditionalInfo(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONRequestFields::getAdditionalInfo()));
    EXPECT_STREQ(data.getAdditionalInfo().c_str(), directObject[JSONRequestFields::getAdditionalInfo()].asString().c_str());

    Json::Value listObject;
    auto function = builder.getFunctions().at(RequestField::AdditionalInfo);
    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONRequestFields::getAdditionalInfo()));
    EXPECT_STREQ(data.getAdditionalInfo().c_str(), listObject[JSONRequestFields::getAdditionalInfo()].asString().c_str());
}

TEST(TestJSONRequestBuilder, CheckCreateObject) {
    JSONRequestBuilder builder;
    Json::Value object;

    auto data = RequestDataFactory::getRequestData(Lanter::Message::OperationCode::Sale, 1);

    EXPECT_FALSE(builder.createObject(*data, object));

    data->setEcrMerchantNumber(1);
    data->setAmount(100);
    data->setCurrencyCode("643");

    EXPECT_TRUE(builder.createObject(*data, object));

    EXPECT_TRUE(fieldExists(object, JSONRequestFields::getOperationCode()));
    EXPECT_EQ((int)data->getOperationCode(), object[JSONRequestFields::getOperationCode()].asInt());

    EXPECT_TRUE(fieldExists(object, JSONRequestFields::getEcrNumber()));
    EXPECT_EQ(data->getEcrNumber(), object[JSONRequestFields::getEcrNumber()].asInt());

    EXPECT_TRUE(fieldExists(object, JSONRequestFields::getAmount()));
    EXPECT_EQ(data->getAmount(), object[JSONRequestFields::getAmount()].asInt64());

    EXPECT_TRUE(fieldExists(object, JSONRequestFields::getCurrencyCode()));
    EXPECT_EQ(data->getCurrencyCode(), object[JSONRequestFields::getCurrencyCode()].asString());
}