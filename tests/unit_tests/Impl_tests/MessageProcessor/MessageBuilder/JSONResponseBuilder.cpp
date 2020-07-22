//
// Created by Владимир Лысенков on 12.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/MessageBuilder/JSONResponseBuilder.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"

#include "Lanter/Message/Response/ResponseDataFactory.h"

#include "Lanter/Message/Response/ResponseData.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;

TEST(JSONRequestBuilder, CheckFunctionInit) {
    JSONResponseBuilder builder;

    EXPECT_FALSE(builder.getFunctions().empty());

    int fieldsCount = (int)ResponseFields::LastValue - (int)ResponseFields::FirstValue + 1;

    EXPECT_EQ(builder.getFunctions().size(), fieldsCount);
}

TEST(JSONResponseBuilder, CheckAddFieldEcrNumber) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setEcrNumber(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldEcrNumber(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getEcrNumber()));
    EXPECT_EQ(data.getEcrNumber(), directObject[JSONResponseFields::getEcrNumber()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::EcrNumber);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getEcrNumber()));
    EXPECT_EQ(data.getEcrNumber(), listObject[JSONResponseFields::getEcrNumber()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldEcrMerchantNumber) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setEcrMerchantNumber(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldEcrMerchantNumber(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getEcrMerchantNumber()));
    EXPECT_EQ(data.getEcrMerchantNumber(), directObject[JSONResponseFields::getEcrMerchantNumber()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::EcrMerchantNumber);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getEcrMerchantNumber()));
    EXPECT_EQ(data.getEcrMerchantNumber(), listObject[JSONResponseFields::getEcrMerchantNumber()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldOperationCode) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setOperationCode(OperationCode::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldOperationCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOperationCode()));
    EXPECT_EQ((int)data.getOperationCode(), directObject[JSONResponseFields::getOperationCode()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::OperationCode);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOperationCode()));
    EXPECT_EQ((int)data.getOperationCode(), listObject[JSONResponseFields::getOperationCode()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldOriginalOperationCode) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setOriginalOperationCode(OperationCode::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldOriginalOperationCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOriginalOperationCode()));
    EXPECT_EQ((int)data.getOriginalOperationCode(), directObject[JSONResponseFields::getOriginalOperationCode()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::OriginalOperationCode);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOriginalOperationCode()));
    EXPECT_EQ((int)data.getOriginalOperationCode(), listObject[JSONResponseFields::getOriginalOperationCode()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldTotalAmount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTotalAmount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTotalAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTotalAmount()));
    EXPECT_EQ(data.getTotalAmount(), directObject[JSONResponseFields::getTotalAmount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::TotalAmount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTotalAmount()));
    EXPECT_EQ(data.getTotalAmount(), listObject[JSONResponseFields::getTotalAmount()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldPartialAmount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setPartialAmount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldPartialAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getPartialAmount()));
    EXPECT_EQ(data.getPartialAmount(), directObject[JSONResponseFields::getPartialAmount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::PartialAmount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getPartialAmount()));
    EXPECT_EQ(data.getPartialAmount(), listObject[JSONResponseFields::getPartialAmount()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldAcquirerFeeAmount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setAcquirerFeeAmount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldAcquirerFeeAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getAcquirerFeeAmount()));
    EXPECT_EQ(data.getAcquirerFeeAmount(), directObject[JSONResponseFields::getAcquirerFeeAmount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::AcquirerFeeAmount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getAcquirerFeeAmount()));
    EXPECT_EQ(data.getAcquirerFeeAmount(), listObject[JSONResponseFields::getAcquirerFeeAmount()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldTerminalFeeAmount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTerminalFeeAmount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTerminalFeeAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTerminalFeeAmount()));
    EXPECT_EQ(data.getTerminalFeeAmount(), directObject[JSONResponseFields::getTerminalFeeAmount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::TerminalFeeAmount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTerminalFeeAmount()));
    EXPECT_EQ(data.getTerminalFeeAmount(), listObject[JSONResponseFields::getTerminalFeeAmount()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldTipsAmount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTipsAmount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTipsAmount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTipsAmount()));
    EXPECT_EQ(data.getTipsAmount(), directObject[JSONResponseFields::getTipsAmount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::TipsAmount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTipsAmount()));
    EXPECT_EQ(data.getTipsAmount(), listObject[JSONResponseFields::getTipsAmount()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldCurrencyCode) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCurrencyCode(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCurrencyCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCurrencyCode()));
    EXPECT_EQ(data.getCurrencyCode(), directObject[JSONResponseFields::getCurrencyCode()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CurrencyCode);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCurrencyCode()));
    EXPECT_EQ(data.getCurrencyCode(), listObject[JSONResponseFields::getCurrencyCode()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldReceiptReference) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setReceiptReference("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldReceiptReference(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getReceiptReference()));
    EXPECT_STREQ(data.getReceiptReference().c_str(), directObject[JSONResponseFields::getReceiptReference()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::ReceiptReference);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getReceiptReference()));
    EXPECT_STREQ(data.getReceiptReference().c_str(), listObject[JSONResponseFields::getReceiptReference()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldRRN) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setRRN("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldRRN(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getRRN()));
    EXPECT_STREQ(data.getRRN().c_str(), directObject[JSONResponseFields::getRRN()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::RRN);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getRRN()));
    EXPECT_STREQ(data.getRRN().c_str(), listObject[JSONResponseFields::getRRN()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldStatus) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setStatus(Status::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldStatus(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getStatus()));
    EXPECT_EQ((int)data.getStatus(), directObject[JSONResponseFields::getStatus()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::Status);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getStatus()));
    EXPECT_EQ((int)data.getStatus(), listObject[JSONResponseFields::getStatus()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldOriginalOperationStatus) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setOriginalOperationStatus(Status::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldOriginalOperationStatus(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOriginalOperationStatus()));
    EXPECT_EQ((int)data.getOriginalOperationStatus(), directObject[JSONResponseFields::getOriginalOperationStatus()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::OriginalOperationStatus);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getOriginalOperationStatus()));
    EXPECT_EQ((int)data.getOriginalOperationStatus(), listObject[JSONResponseFields::getOriginalOperationStatus()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldTransDateTime) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTransDateTime("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTransDateTime(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTransDateTime()));
    EXPECT_STREQ(data.getTransDateTime().c_str(), directObject[JSONResponseFields::getTransDateTime()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::TransDateTime);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTransDateTime()));
    EXPECT_STREQ(data.getTransDateTime().c_str(), listObject[JSONResponseFields::getTransDateTime()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldTerminalDateTime) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTerminalDateTime("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTerminalDateTime(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTerminalDateTime()));
    EXPECT_STREQ(data.getTerminalDateTime().c_str(), directObject[JSONResponseFields::getTerminalDateTime()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::TerminalDateTime);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTerminalDateTime()));
    EXPECT_STREQ(data.getTerminalDateTime().c_str(), listObject[JSONResponseFields::getTerminalDateTime()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldCardPAN) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardPAN("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardPAN(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardPAN()));
    EXPECT_STREQ(data.getCardPAN().c_str(), directObject[JSONResponseFields::getCardPAN()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CardPAN);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardPAN()));
    EXPECT_STREQ(data.getCardPAN().c_str(), listObject[JSONResponseFields::getCardPAN()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldExpireDate) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setExpireDate("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldExpireDate(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getExpireDate()));
    EXPECT_STREQ(data.getExpireDate().c_str(), directObject[JSONResponseFields::getExpireDate()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::ExpireDate);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getExpireDate()));
    EXPECT_STREQ(data.getExpireDate().c_str(), listObject[JSONResponseFields::getExpireDate()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldCardholderName) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardholderName("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardholderName(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardholderName()));
    EXPECT_STREQ(data.getCardholderName().c_str(), directObject[JSONResponseFields::getCardholderName()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CardholderName);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardholderName()));
    EXPECT_STREQ(data.getCardholderName().c_str(), listObject[JSONResponseFields::getCardholderName()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldCardholderAuthMethod) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardholderAuthMethod(CardholderAuthMethod::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardholderAuthMethod(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardholderAuthMethod()));
    EXPECT_EQ((int)data.getCardholderAuthMethod(), directObject[JSONResponseFields::getCardholderAuthMethod()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CardholderAuthMethod);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardholderAuthMethod()));
    EXPECT_EQ((int)data.getCardholderAuthMethod(), listObject[JSONResponseFields::getCardholderAuthMethod()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldAuthCode) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setAuthCode("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldAuthCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getAuthCode()));
    EXPECT_STREQ(data.getAuthCode().c_str(), directObject[JSONResponseFields::getAuthCode()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::AuthCode);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getAuthCode()));
    EXPECT_STREQ(data.getAuthCode().c_str(), listObject[JSONResponseFields::getAuthCode()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldResponseCode) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setResponseCode("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldResponseCode(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getResponseCode()));
    EXPECT_STREQ(data.getResponseCode().c_str(), directObject[JSONResponseFields::getResponseCode()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::ResponseCode);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getResponseCode()));
    EXPECT_STREQ(data.getResponseCode().c_str(), listObject[JSONResponseFields::getResponseCode()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldResponseText) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setResponseText("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldResponseText(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getResponseText()));
    EXPECT_STREQ(data.getResponseText().c_str(), directObject[JSONResponseFields::getResponseText()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::ResponseText);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getResponseText()));
    EXPECT_STREQ(data.getResponseText().c_str(), listObject[JSONResponseFields::getResponseText()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldSTAN) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setSTAN("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldSTAN(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getSTAN()));
    EXPECT_STREQ(data.getSTAN().c_str(), directObject[JSONResponseFields::getSTAN()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::STAN);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getSTAN()));
    EXPECT_STREQ(data.getSTAN().c_str(), listObject[JSONResponseFields::getSTAN()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldTransactionID) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTransactionID("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTransactionID(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTransactionID()));
    EXPECT_STREQ(data.getTransactionID().c_str(), directObject[JSONResponseFields::getTransactionID()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::TransactionID);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTransactionID()));
    EXPECT_STREQ(data.getTransactionID().c_str(), listObject[JSONResponseFields::getTransactionID()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldTerminalID) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTerminalID("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTerminalID(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTerminalID()));
    EXPECT_STREQ(data.getTerminalID().c_str(), directObject[JSONResponseFields::getTerminalID()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::TerminalID);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTerminalID()));
    EXPECT_STREQ(data.getTerminalID().c_str(), listObject[JSONResponseFields::getTerminalID()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldCardEmvAid) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardEmvAid("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardEmvAid(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardEmvAid()));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), directObject[JSONResponseFields::getCardEmvAid()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CardEmvAid);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardEmvAid()));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), listObject[JSONResponseFields::getCardEmvAid()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldCardAppName) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardAppName("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardAppName(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardAppName()));
    EXPECT_STREQ(data.getCardAppName().c_str(), directObject[JSONResponseFields::getCardAppName()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CardAppName);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardAppName()));
    EXPECT_STREQ(data.getCardAppName().c_str(), listObject[JSONResponseFields::getCardAppName()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldCardInputMethod) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardInputMethod(CardInputMethod::FirstValue);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardInputMethod(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardInputMethod()));
    EXPECT_EQ((int)data.getCardInputMethod(), directObject[JSONResponseFields::getCardInputMethod()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CardInputMethod);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardInputMethod()));
    EXPECT_EQ((int)data.getCardInputMethod(), listObject[JSONResponseFields::getCardInputMethod()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldIssuerName) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setIssuerName("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldIssuerName(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getIssuerName()));
    EXPECT_STREQ(data.getIssuerName().c_str(), directObject[JSONResponseFields::getIssuerName()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::IssuerName);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getIssuerName()));
    EXPECT_STREQ(data.getIssuerName().c_str(), listObject[JSONResponseFields::getIssuerName()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldAdditionalInfo) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setAdditionalInfo("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldAdditionalInfo(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getAdditionalInfo()));
    EXPECT_STREQ(data.getAdditionalInfo().c_str(), directObject[JSONResponseFields::getAdditionalInfo()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::AdditionalInfo);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getAdditionalInfo()));
    EXPECT_STREQ(data.getAdditionalInfo().c_str(), listObject[JSONResponseFields::getAdditionalInfo()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldCardData) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardData("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardData(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardData()));
    EXPECT_STREQ(data.getCardData().c_str(), directObject[JSONResponseFields::getCardData()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CardData);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardData()));
    EXPECT_STREQ(data.getCardData().c_str(), listObject[JSONResponseFields::getCardData()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldCardDataEnc) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCardDataEnc("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCardDataEnc(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCardDataEnc()));
    EXPECT_STREQ(data.getCardDataEnc().c_str(), directObject[JSONResponseFields::getCardDataEnc()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CardDataEnc);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCardDataEnc()));
    EXPECT_STREQ(data.getCardDataEnc().c_str(), listObject[JSONResponseFields::getCardDataEnc()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldMerchantID) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setMerchantID("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldMerchantID(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getMerchantID()));
    EXPECT_STREQ(data.getMerchantID().c_str(), directObject[JSONResponseFields::getMerchantID()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::MerchantID);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getMerchantID()));
    EXPECT_STREQ(data.getMerchantID().c_str(), listObject[JSONResponseFields::getMerchantID()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldTVR) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTVR("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTVR(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTVR()));
    EXPECT_STREQ(data.getTVR().c_str(), directObject[JSONResponseFields::getTVR()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::TVR);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTVR()));
    EXPECT_STREQ(data.getTVR().c_str(), listObject[JSONResponseFields::getTVR()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldTSI) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTSI("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTSI(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTSI()));
    EXPECT_STREQ(data.getTSI().c_str(), directObject[JSONResponseFields::getTSI()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::TSI);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTSI()));
    EXPECT_STREQ(data.getTSI().c_str(), listObject[JSONResponseFields::getTSI()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldTC) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setTC("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldTC(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getTC()));
    EXPECT_STREQ(data.getTC().c_str(), directObject[JSONResponseFields::getTC()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::TC);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getTC()));
    EXPECT_STREQ(data.getTC().c_str(), listObject[JSONResponseFields::getTC()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldCID) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCID("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCID(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCID()));
    EXPECT_STREQ(data.getCID().c_str(), directObject[JSONResponseFields::getCID()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CID);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCID()));
    EXPECT_STREQ(data.getCID().c_str(), listObject[JSONResponseFields::getCID()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldKVR) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setKVR("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldKVR(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getKVR()));
    EXPECT_STREQ(data.getKVR().c_str(), directObject[JSONResponseFields::getKVR()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::KVR);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getKVR()));
    EXPECT_STREQ(data.getKVR().c_str(), listObject[JSONResponseFields::getKVR()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldCDAResult) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setCDAResult("123");

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldCDAResult(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getCDAResult()));
    EXPECT_STREQ(data.getCDAResult().c_str(), directObject[JSONResponseFields::getCDAResult()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::CDAResult);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getCDAResult()));
    EXPECT_STREQ(data.getCDAResult().c_str(), listObject[JSONResponseFields::getCDAResult()].asString().c_str());
}

TEST(JSONResponseBuilder, CheckAddFieldSalesCount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setSalesCount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldSalesCount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getSalesCount()));
    EXPECT_EQ(data.getSalesCount(), directObject[JSONResponseFields::getSalesCount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::SalesCount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getSalesCount()));
    EXPECT_EQ(data.getSalesCount(), listObject[JSONResponseFields::getSalesCount()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldVoidCount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setVoidCount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldVoidCount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getVoidCount()));
    EXPECT_EQ(data.getVoidCount(), directObject[JSONResponseFields::getVoidCount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::VoidCount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getVoidCount()));
    EXPECT_EQ(data.getVoidCount(), listObject[JSONResponseFields::getVoidCount()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldRefundCount) {
    JSONResponseBuilder builder;

    ResponseData data;

    data.setRefundCount(1);

    Json::Value directObject;

    EXPECT_TRUE(builder.addFieldRefundCount(data, directObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getRefundCount()));
    EXPECT_EQ(data.getRefundCount(), directObject[JSONResponseFields::getRefundCount()].asInt());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::RefundCount);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getRefundCount()));
    EXPECT_EQ(data.getRefundCount(), listObject[JSONResponseFields::getRefundCount()].asInt());
}

TEST(JSONResponseBuilder, CheckAddFieldSalesArray) {
    JSONResponseBuilder builder;

    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto arrayElement = ResponseDataFactory::getResponseData(Lanter::Message::OperationCode::ArrayElement);

    arrayElement->setTotalAmount(100);
    arrayElement->setCurrencyCode(643);
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
    EXPECT_TRUE(fieldExists(directObject, JSONResponseFields::getSalesArray()));

    EXPECT_EQ(arrayElement->getTotalAmount(),
              directObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              directObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getCurrencyCode()].asInt());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getCardPAN()].asString().c_str());

    EXPECT_EQ(arrayElement->getTotalAmount(),
              directObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              directObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getCurrencyCode()].asInt());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 directObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getCardPAN()].asString().c_str());

    Json::Value listObject;

    auto function = builder.getFunctions().at(ResponseFields::SalesArray);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getSalesArray()));

    EXPECT_EQ(arrayElement->getTotalAmount(),
              listObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              listObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getCurrencyCode()].asInt());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][0][JSONResponseFields::getCardPAN()].asString().c_str());

    EXPECT_EQ(arrayElement->getTotalAmount(),
              listObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              listObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getCurrencyCode()].asInt());
    EXPECT_STREQ(arrayElement->getRRN().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getRRN()].asString().c_str());
    EXPECT_STREQ(arrayElement->getReceiptReference().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getReceiptReference()].asString().c_str());
    EXPECT_STREQ(arrayElement->getResponseCode().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getResponseCode()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransactionID().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getTransactionID()].asString().c_str());
    EXPECT_STREQ(arrayElement->getTransDateTime().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getTransDateTime()].asString().c_str());
    EXPECT_STREQ(arrayElement->getIssuerName().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getIssuerName()].asString().c_str());
    EXPECT_STREQ(arrayElement->getCardPAN().c_str(),
                 listObject[JSONResponseFields::getSalesArray()][1][JSONResponseFields::getCardPAN()].asString().c_str());
}


TEST(JSONResponseBuilder, CheckAddFieldVoidArray) {
    JSONResponseBuilder builder;

    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto arrayElement = ResponseDataFactory::getResponseData(Lanter::Message::OperationCode::ArrayElement);

    arrayElement->setTotalAmount(100);
    arrayElement->setCurrencyCode(643);
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
              directObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getCurrencyCode()].asInt());
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
              directObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getCurrencyCode()].asInt());
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

    auto function = builder.getFunctions().at(ResponseFields::VoidArray);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getVoidArray()));

    EXPECT_EQ(arrayElement->getTotalAmount(),
              listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              listObject[JSONResponseFields::getVoidArray()][0][JSONResponseFields::getCurrencyCode()].asInt());
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
              listObject[JSONResponseFields::getVoidArray()][1][JSONResponseFields::getCurrencyCode()].asInt());
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

TEST(JSONResponseBuilder, CheckAddFieldRefundArray) {
    JSONResponseBuilder builder;

    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto arrayElement = ResponseDataFactory::getResponseData(Lanter::Message::OperationCode::ArrayElement);

    arrayElement->setTotalAmount(100);
    arrayElement->setCurrencyCode(643);
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
              directObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getCurrencyCode()].asInt());
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
              directObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getCurrencyCode()].asInt());
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

    auto function = builder.getFunctions().at(ResponseFields::RefundArray);

    EXPECT_TRUE(function(data, listObject));
    EXPECT_TRUE(fieldExists(listObject, JSONResponseFields::getRefundArray()));

    EXPECT_EQ(arrayElement->getTotalAmount(),
              listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getTotalAmount()].asInt64());
    EXPECT_EQ(arrayElement->getCurrencyCode(),
              listObject[JSONResponseFields::getRefundArray()][0][JSONResponseFields::getCurrencyCode()].asInt());
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
              listObject[JSONResponseFields::getRefundArray()][1][JSONResponseFields::getCurrencyCode()].asInt());
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

TEST(JSONResponseBuilder, CheckCreateObject) {
    JSONResponseBuilder builder;

    auto data = ResponseDataFactory::getResponseData(OperationCode::PrintDetailReport, 1);

    data->setTotalAmount(100);
    data->setCurrencyCode(643);
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
    arrayElement->setCurrencyCode(643);
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