#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Builder/JSONResponseBuilder.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"

#include "Lanter/Message/Response/ResponseDataFactory.h"

#include "Lanter/Message/Response/ResponseData.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Builder;

TEST(TestJSONResponseBuilder, CheckFunctionInit) {
    JSONResponseBuilder builder;

    EXPECT_FALSE(builder.getFunctions().empty());

    int fieldsCount = (int)ResponseField::LastValue - (int)ResponseField::FirstValue + 1;

    EXPECT_EQ(builder.getFunctions().size(), fieldsCount);
}

TEST(TestJSONResponseBuilder, CheckAddFieldEcrNumber) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setEcrNumber(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldEcrNumber(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getEcrNumber()));
    EXPECT_EQ(data.getEcrNumber(), directObject[JSONResponseFields::getEcrNumber()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::EcrNumber);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getEcrNumber()));
    EXPECT_EQ(data.getEcrNumber(), listObject[JSONResponseFields::getEcrNumber()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldEcrMerchantNumber) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setEcrMerchantNumber(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldEcrMerchantNumber(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getEcrMerchantNumber()));
    EXPECT_EQ(data.getEcrMerchantNumber(), directObject[JSONResponseFields::getEcrMerchantNumber()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::EcrMerchantNumber);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getEcrMerchantNumber()));
    EXPECT_EQ(data.getEcrMerchantNumber(), listObject[JSONResponseFields::getEcrMerchantNumber()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldOperationCode) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setOperationCode(OperationCode::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldOperationCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOperationCode()));
    EXPECT_EQ((int)data.getOperationCode(), directObject[JSONResponseFields::getOperationCode()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::OperationCode);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOperationCode()));
    EXPECT_EQ((int)data.getOperationCode(), listObject[JSONResponseFields::getOperationCode()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldOriginalOperationCode) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setOriginalOperationCode(OperationCode::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldOriginalOperationCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOriginalOperationCode()));
    EXPECT_EQ((int)data.getOriginalOperationCode(), directObject[JSONResponseFields::getOriginalOperationCode()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::OriginalOperationCode);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOriginalOperationCode()));
    EXPECT_EQ((int)data.getOriginalOperationCode(), listObject[JSONResponseFields::getOriginalOperationCode()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldTotalAmount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTotalAmount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTotalAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTotalAmount()));
    EXPECT_EQ(data.getTotalAmount(), directObject[JSONResponseFields::getTotalAmount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::TotalAmount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTotalAmount()));
    EXPECT_EQ(data.getTotalAmount(), listObject[JSONResponseFields::getTotalAmount()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldPartialAmount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setPartialAmount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldPartialAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getPartialAmount()));
    EXPECT_EQ(data.getPartialAmount(), directObject[JSONResponseFields::getPartialAmount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::PartialAmount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getPartialAmount()));
    EXPECT_EQ(data.getPartialAmount(), listObject[JSONResponseFields::getPartialAmount()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldAcquirerFeeAmount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setAcquirerFeeAmount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldAcquirerFeeAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getAcquirerFeeAmount()));
    EXPECT_EQ(data.getAcquirerFeeAmount(), directObject[JSONResponseFields::getAcquirerFeeAmount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::AcquirerFeeAmount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getAcquirerFeeAmount()));
    EXPECT_EQ(data.getAcquirerFeeAmount(), listObject[JSONResponseFields::getAcquirerFeeAmount()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldTerminalFeeAmount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTerminalFeeAmount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTerminalFeeAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTerminalFeeAmount()));
    EXPECT_EQ(data.getTerminalFeeAmount(), directObject[JSONResponseFields::getTerminalFeeAmount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::TerminalFeeAmount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTerminalFeeAmount()));
    EXPECT_EQ(data.getTerminalFeeAmount(), listObject[JSONResponseFields::getTerminalFeeAmount()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldTipsAmount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTipsAmount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTipsAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTipsAmount()));
    EXPECT_EQ(data.getTipsAmount(), directObject[JSONResponseFields::getTipsAmount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::TipsAmount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTipsAmount()));
    EXPECT_EQ(data.getTipsAmount(), listObject[JSONResponseFields::getTipsAmount()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCurrencyCode) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCurrencyCode("1");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCurrencyCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCurrencyCode()));
    EXPECT_EQ(data.getCurrencyCode(), directObject[JSONResponseFields::getCurrencyCode()].asString());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CurrencyCode);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCurrencyCode()));
    EXPECT_EQ(data.getCurrencyCode(), listObject[JSONResponseFields::getCurrencyCode()].asString());
}

TEST(TestJSONResponseBuilder, CheckAddFieldReceiptReference) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setReceiptReference("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldReceiptReference(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getReceiptReference()));
    EXPECT_STREQ(data.getReceiptReference().c_str(), directObject[JSONResponseFields::getReceiptReference()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::ReceiptReference);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getReceiptReference()));
    EXPECT_STREQ(data.getReceiptReference().c_str(), listObject[JSONResponseFields::getReceiptReference()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldRRN) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setRRN("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldRRN(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getRRN()));
    EXPECT_STREQ(data.getRRN().c_str(), directObject[JSONResponseFields::getRRN()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::RRN);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getRRN()));
    EXPECT_STREQ(data.getRRN().c_str(), listObject[JSONResponseFields::getRRN()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldStatus) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setStatus(Status::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldStatus(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getStatus()));
    EXPECT_EQ((int)data.getStatus(), directObject[JSONResponseFields::getStatus()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::Status);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getStatus()));
    EXPECT_EQ((int)data.getStatus(), listObject[JSONResponseFields::getStatus()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldOriginalOperationStatus) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setOriginalOperationStatus(Status::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldOriginalOperationStatus(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOriginalOperationStatus()));
    EXPECT_EQ((int)data.getOriginalOperationStatus(), directObject[JSONResponseFields::getOriginalOperationStatus()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::OriginalOperationStatus);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOriginalOperationStatus()));
    EXPECT_EQ((int)data.getOriginalOperationStatus(), listObject[JSONResponseFields::getOriginalOperationStatus()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldTransDateTime) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTransDateTime("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTransDateTime(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTransDateTime()));
    EXPECT_STREQ(data.getTransDateTime().c_str(), directObject[JSONResponseFields::getTransDateTime()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::TransDateTime);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTransDateTime()));
    EXPECT_STREQ(data.getTransDateTime().c_str(), listObject[JSONResponseFields::getTransDateTime()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldTerminalDateTime) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTerminalDateTime("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTerminalDateTime(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTerminalDateTime()));
    EXPECT_STREQ(data.getTerminalDateTime().c_str(), directObject[JSONResponseFields::getTerminalDateTime()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::TerminalDateTime);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTerminalDateTime()));
    EXPECT_STREQ(data.getTerminalDateTime().c_str(), listObject[JSONResponseFields::getTerminalDateTime()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCardPAN) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardPAN("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardPAN(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardPAN()));
    EXPECT_STREQ(data.getCardPAN().c_str(), directObject[JSONResponseFields::getCardPAN()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CardPAN);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardPAN()));
    EXPECT_STREQ(data.getCardPAN().c_str(), listObject[JSONResponseFields::getCardPAN()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldExpireDate) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setExpireDate("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldExpireDate(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getExpireDate()));
    EXPECT_STREQ(data.getExpireDate().c_str(), directObject[JSONResponseFields::getExpireDate()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::ExpireDate);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getExpireDate()));
    EXPECT_STREQ(data.getExpireDate().c_str(), listObject[JSONResponseFields::getExpireDate()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCardholderName) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardholderName("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardholderName(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardholderName()));
    EXPECT_STREQ(data.getCardholderName().c_str(), directObject[JSONResponseFields::getCardholderName()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CardholderName);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardholderName()));
    EXPECT_STREQ(data.getCardholderName().c_str(), listObject[JSONResponseFields::getCardholderName()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCardholderAuthMethod) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardholderAuthMethod(CardholderAuthMethod::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardholderAuthMethod(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardholderAuthMethod()));
    EXPECT_EQ((int)data.getCardholderAuthMethod(), directObject[JSONResponseFields::getCardholderAuthMethod()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CardholderAuthMethod);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardholderAuthMethod()));
    EXPECT_EQ((int)data.getCardholderAuthMethod(), listObject[JSONResponseFields::getCardholderAuthMethod()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldAuthCode) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setAuthCode("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldAuthCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getAuthCode()));
    EXPECT_STREQ(data.getAuthCode().c_str(), directObject[JSONResponseFields::getAuthCode()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::AuthCode);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getAuthCode()));
    EXPECT_STREQ(data.getAuthCode().c_str(), listObject[JSONResponseFields::getAuthCode()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldResponseCode) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setResponseCode("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldResponseCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getResponseCode()));
    EXPECT_STREQ(data.getResponseCode().c_str(), directObject[JSONResponseFields::getResponseCode()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::ResponseCode);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getResponseCode()));
    EXPECT_STREQ(data.getResponseCode().c_str(), listObject[JSONResponseFields::getResponseCode()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldResponseText) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setResponseText("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldResponseText(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getResponseText()));
    EXPECT_STREQ(data.getResponseText().c_str(), directObject[JSONResponseFields::getResponseText()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::ResponseText);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getResponseText()));
    EXPECT_STREQ(data.getResponseText().c_str(), listObject[JSONResponseFields::getResponseText()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldSTAN) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setSTAN("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldSTAN(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getSTAN()));
    EXPECT_STREQ(data.getSTAN().c_str(), directObject[JSONResponseFields::getSTAN()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::STAN);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getSTAN()));
    EXPECT_STREQ(data.getSTAN().c_str(), listObject[JSONResponseFields::getSTAN()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldTransactionID) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTransactionID("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTransactionID(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTransactionID()));
    EXPECT_STREQ(data.getTransactionID().c_str(), directObject[JSONResponseFields::getTransactionID()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::TransactionID);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTransactionID()));
    EXPECT_STREQ(data.getTransactionID().c_str(), listObject[JSONResponseFields::getTransactionID()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldTerminalID) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTerminalID("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTerminalID(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTerminalID()));
    EXPECT_STREQ(data.getTerminalID().c_str(), directObject[JSONResponseFields::getTerminalID()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::TerminalID);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTerminalID()));
    EXPECT_STREQ(data.getTerminalID().c_str(), listObject[JSONResponseFields::getTerminalID()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCardEmvAid) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardEmvAid("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardEmvAid(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardEmvAid()));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), directObject[JSONResponseFields::getCardEmvAid()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CardEmvAid);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardEmvAid()));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), listObject[JSONResponseFields::getCardEmvAid()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCardAppName) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardAppName("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardAppName(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardAppName()));
    EXPECT_STREQ(data.getCardAppName().c_str(), directObject[JSONResponseFields::getCardAppName()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CardAppName);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardAppName()));
    EXPECT_STREQ(data.getCardAppName().c_str(), listObject[JSONResponseFields::getCardAppName()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCardInputMethod) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardInputMethod(CardInputMethod::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardInputMethod(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardInputMethod()));
    EXPECT_EQ((int)data.getCardInputMethod(), directObject[JSONResponseFields::getCardInputMethod()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CardInputMethod);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardInputMethod()));
    EXPECT_EQ((int)data.getCardInputMethod(), listObject[JSONResponseFields::getCardInputMethod()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldIssuerName) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setIssuerName("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldIssuerName(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getIssuerName()));
    EXPECT_STREQ(data.getIssuerName().c_str(), directObject[JSONResponseFields::getIssuerName()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::IssuerName);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getIssuerName()));
    EXPECT_STREQ(data.getIssuerName().c_str(), listObject[JSONResponseFields::getIssuerName()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldAdditionalInfo) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setAdditionalInfo("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldAdditionalInfo(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getAdditionalInfo()));
    EXPECT_STREQ(data.getAdditionalInfo().c_str(), directObject[JSONResponseFields::getAdditionalInfo()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::AdditionalInfo);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getAdditionalInfo()));
    EXPECT_STREQ(data.getAdditionalInfo().c_str(), listObject[JSONResponseFields::getAdditionalInfo()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCardData) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardData("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardData(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardData()));
    EXPECT_STREQ(data.getCardData().c_str(), directObject[JSONResponseFields::getCardData()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CardData);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardData()));
    EXPECT_STREQ(data.getCardData().c_str(), listObject[JSONResponseFields::getCardData()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCardDataEnc) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardDataEnc("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardDataEnc(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardDataEnc()));
    EXPECT_STREQ(data.getCardDataEnc().c_str(), directObject[JSONResponseFields::getCardDataEnc()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CardDataEnc);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardDataEnc()));
    EXPECT_STREQ(data.getCardDataEnc().c_str(), listObject[JSONResponseFields::getCardDataEnc()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldMerchantID) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setMerchantID("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldMerchantID(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getMerchantID()));
    EXPECT_STREQ(data.getMerchantID().c_str(), directObject[JSONResponseFields::getMerchantID()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::MerchantID);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getMerchantID()));
    EXPECT_STREQ(data.getMerchantID().c_str(), listObject[JSONResponseFields::getMerchantID()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldTVR) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTVR("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTVR(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTVR()));
    EXPECT_STREQ(data.getTVR().c_str(), directObject[JSONResponseFields::getTVR()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::TVR);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTVR()));
    EXPECT_STREQ(data.getTVR().c_str(), listObject[JSONResponseFields::getTVR()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldTSI) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTSI("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTSI(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTSI()));
    EXPECT_STREQ(data.getTSI().c_str(), directObject[JSONResponseFields::getTSI()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::TSI);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTSI()));
    EXPECT_STREQ(data.getTSI().c_str(), listObject[JSONResponseFields::getTSI()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldTC) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTC("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTC(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTC()));
    EXPECT_STREQ(data.getTC().c_str(), directObject[JSONResponseFields::getTC()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::TC);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTC()));
    EXPECT_STREQ(data.getTC().c_str(), listObject[JSONResponseFields::getTC()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCID) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCID("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCID(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCID()));
    EXPECT_STREQ(data.getCID().c_str(), directObject[JSONResponseFields::getCID()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CID);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCID()));
    EXPECT_STREQ(data.getCID().c_str(), listObject[JSONResponseFields::getCID()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldKVR) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setKVR("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldKVR(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getKVR()));
    EXPECT_STREQ(data.getKVR().c_str(), directObject[JSONResponseFields::getKVR()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::KVR);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getKVR()));
    EXPECT_STREQ(data.getKVR().c_str(), listObject[JSONResponseFields::getKVR()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldCDAResult) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCDAResult("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCDAResult(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCDAResult()));
    EXPECT_STREQ(data.getCDAResult().c_str(), directObject[JSONResponseFields::getCDAResult()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::CDAResult);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCDAResult()));
    EXPECT_STREQ(data.getCDAResult().c_str(), listObject[JSONResponseFields::getCDAResult()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldSalesCount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setSalesCount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldSalesCount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getSaleCount()));
    EXPECT_EQ(data.getSaleCount(), directObject[JSONResponseFields::getSaleCount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::SaleCount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getSaleCount()));
    EXPECT_EQ(data.getSaleCount(), listObject[JSONResponseFields::getSaleCount()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldVoidCount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setVoidCount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldVoidCount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getVoidCount()));
    EXPECT_EQ(data.getVoidCount(), directObject[JSONResponseFields::getVoidCount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::VoidCount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getVoidCount()));
    EXPECT_EQ(data.getVoidCount(), listObject[JSONResponseFields::getVoidCount()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldRefundCount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setRefundCount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldRefundCount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getRefundCount()));
    EXPECT_EQ(data.getRefundCount(), directObject[JSONResponseFields::getRefundCount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::RefundCount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getRefundCount()));
    EXPECT_EQ(data.getRefundCount(), listObject[JSONResponseFields::getRefundCount()].asInt());
}

TEST(TestJSONResponseBuilder, CheckAddFieldSalesArray) {
    JSONResponseBuilder builder;

    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto arrayElement = ResponseDataFactory::getResponseData(Lanter::Message::OperationCode::ArrayElement);

    arrayElement->setTotalAmount(100);
    arrayElement->setCurrencyCode("643");
    arrayElement->setRRN("1234");
    arrayElement->setReceiptReference("1234");
    arrayElement->setResponseCode("1234");
    arrayElement->setTransactionID("1234");
    arrayElement->setTransDateTime("1234");
    arrayElement->setIssuerName("1234");
    arrayElement->setCardPAN("1234");

    array.push_back(arrayElement);
    array.push_back(arrayElement);

    EXPECT_EQ(array.size(), 2);

    data.setSalesArray(array);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldSalesArray(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getSaleArray()));

    EXPECT_EQ(arrayElement->getTotalAmount(),
              directObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              directObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getCardPAN()].asString().c_str());

    EXPECT_EQ(arrayElement->getTotalAmount(),
              directObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              directObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 directObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getCardPAN()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::SaleArray);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getSaleArray()));

    EXPECT_EQ(arrayElement->getTotalAmount(),
              listObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              listObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][0][JSONResponseFields::getCardPAN()].asString().c_str());

    EXPECT_EQ(arrayElement->getTotalAmount(),
              listObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              listObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 listObject[JSONResponseFields::getSaleArray()][1][JSONResponseFields::getCardPAN()].asString().c_str());
}


TEST(TestJSONResponseBuilder, CheckAddFieldVoidArray) {
    JSONResponseBuilder builder;

    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto arrayElement = ResponseDataFactory::getResponseData(Lanter::Message::OperationCode::ArrayElement);

    arrayElement->setTotalAmount(100);
    arrayElement->setCurrencyCode("643");
    arrayElement->setRRN("1234");
    arrayElement->setReceiptReference("1234");
    arrayElement->setResponseCode("1234");
    arrayElement->setTransactionID("1234");
    arrayElement->setTransDateTime("1234");
    arrayElement->setIssuerName("1234");
    arrayElement->setCardPAN("1234");

    array.push_back(arrayElement);
    array.push_back(arrayElement);

    EXPECT_EQ(array.size(), 2);

    data.setVoidArray(array);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldVoidArray(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getVoidArray()));

    EXPECT_EQ(arrayElement->getTotalAmount(),
              directObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              directObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getCardPAN()].asString().c_str());

    EXPECT_EQ(arrayElement->getTotalAmount(),
              directObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              directObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 directObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getCardPAN()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::VoidArray);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getVoidArray()));

    EXPECT_EQ(arrayElement->getTotalAmount(),
              listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getCardPAN()].asString().c_str());

    EXPECT_EQ(arrayElement->getTotalAmount(),
              listObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              listObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 listObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getCardPAN()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckAddFieldRefundArray) {
    JSONResponseBuilder builder;

    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto arrayElement = ResponseDataFactory::getResponseData(Lanter::Message::OperationCode::ArrayElement);

    arrayElement->setTotalAmount(100);
    arrayElement->setCurrencyCode("643");
    arrayElement->setRRN("1234");
    arrayElement->setReceiptReference("1234");
    arrayElement->setResponseCode("1234");
    arrayElement->setTransactionID("1234");
    arrayElement->setTransDateTime("1234");
    arrayElement->setIssuerName("1234");
    arrayElement->setCardPAN("1234");

    array.push_back(arrayElement);
    array.push_back(arrayElement);

    EXPECT_EQ(array.size(), 2);

    data.setRefundArray(array);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldRefundArray(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getRefundArray()));

    EXPECT_EQ(arrayElement->getTotalAmount(),
              directObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              directObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getCardPAN()].asString().c_str());

    EXPECT_EQ(arrayElement->getTotalAmount(),
              directObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              directObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 directObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getCardPAN()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseField::RefundArray);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getRefundArray()));

    EXPECT_EQ(arrayElement->getTotalAmount(),
              listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getCardPAN()].asString().c_str());

    EXPECT_EQ(arrayElement->getTotalAmount(),
              listObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              listObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getCurrencyCode()].asString());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 listObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getCardPAN()].asString().c_str());
}

TEST(TestJSONResponseBuilder, CheckCreateObject) {
    JSONResponseBuilder builder;

    auto data = ResponseDataFactory::getResponseData(OperationCode::PrintDetailReport, 1);

    data->setTotalAmount(100);
    data->setCurrencyCode("643");
    data->setTerminalID("1234");
    data->setMerchantID("1234");
    data->setTerminalDateTime("1234");
    data->setSalesCount(2);
    data->setVoidCount(2);
    data->setRefundCount(2);
    data->setStatus(Status::Success);

    std::vector<std::shared_ptr<IResponseData> > array;
    auto arrayElement = ResponseDataFactory::getResponseData(Lanter::Message::OperationCode::ArrayElement);

    arrayElement->setTotalAmount(100);
    arrayElement->setCurrencyCode("643");
    arrayElement->setRRN("1234");
    arrayElement->setReceiptReference("1234");
    arrayElement->setResponseCode("1234");
    arrayElement->setTransactionID("1234");
    arrayElement->setTransDateTime("1234");
    arrayElement->setIssuerName("1234");
    arrayElement->setCardPAN("1234");

    array.push_back(arrayElement);
    array.push_back(arrayElement);

    data->setSalesArray(array);
    data->setVoidArray(array);
    data->setRefundArray(array);

    Json::Value object;
    EXPECT_TRUE(builder.createObject(*data, object));
}