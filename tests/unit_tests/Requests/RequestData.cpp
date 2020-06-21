//
// Created by Владимир Лысенков on 20.06.2020.
//

#include "gtest/gtest.h"
#include "Lanter/Requests/RequestData.h"

using namespace Lanter;
using namespace Lanter::Requests;

TEST(RequestData, CheckEcrNumber) {
    RequestData data;
    int16_t minimumValue = 1;
    int16_t maximumValue = 999;
    int16_t lessMinimum = minimumValue - 1;
    int16_t greatMaximum = maximumValue + 1;

    EXPECT_THROW(data.setEcrNumber(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setEcrNumber(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getEcrNumber(), -1);

    EXPECT_NO_THROW(data.setEcrNumber(minimumValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), minimumValue);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EcrNumber), data.getFieldsSet().end());

    EXPECT_NO_THROW(data.setEcrNumber(maximumValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), maximumValue);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EcrNumber), data.getFieldsSet().end());
}

TEST(RequestData, ChechEcrMerchantNumber) {
    RequestData data;
    int16_t minimumValue = 1;
    int16_t maximumValue = 999;
    int16_t lessMinimum = minimumValue - 1;
    int16_t greatMaximum = maximumValue + 1;

    EXPECT_THROW(data.setEcrMerchantNumber(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setEcrMerchantNumber(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getEcrMerchantNumber(), -1);

    EXPECT_NO_THROW(data.setEcrMerchantNumber(minimumValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), minimumValue);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EcrMerchantNumber), data.getFieldsSet().end());

    EXPECT_NO_THROW(data.setEcrMerchantNumber(maximumValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), maximumValue);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EcrMerchantNumber), data.getFieldsSet().end());
}

TEST(RequestData, CheckOperationCode) {
    RequestData data;
    EXPECT_THROW(data.setOperationCode(OperationCodes::NoOperation), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);
    EXPECT_THROW(data.setOperationCode((OperationCodes)((int)(OperationCodes::LastValue) + 1)), std::invalid_argument);
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOperationCode(), OperationCodes::NoOperation);

    EXPECT_NO_THROW(data.setOperationCode(OperationCodes::FirstValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOperationCode(), OperationCodes::FirstValue);

    EXPECT_NO_THROW(data.setOperationCode(OperationCodes::LastValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOperationCode(), OperationCodes::LastValue);
}

TEST(RequestData, CheckAllAmounts) {
    RequestData data;

    int64_t minimumValue = 0;
    int64_t maximumValue = 999999999999;
    int64_t lessMinimum = minimumValue - 1;
    int64_t greatMaximum = maximumValue + 1;

    int fieldsCount = 0;
    //Amount
    EXPECT_THROW(data.setAmount(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setAmount(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getAmount(), -1);
    ++fieldsCount;
    EXPECT_NO_THROW(data.setAmount(minimumValue));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getAmount(), minimumValue);
    EXPECT_NO_THROW(data.setAmount(maximumValue));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getAmount(), maximumValue);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::Amount), data.getFieldsSet().end());

    //ParialAmount
    EXPECT_EQ(data.getPartialAmount(), -1);
    ++fieldsCount;
    EXPECT_NO_THROW(data.setPartialAmount(minimumValue));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), minimumValue);
    EXPECT_NO_THROW(data.setPartialAmount(maximumValue));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), maximumValue);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::PartialAmount), data.getFieldsSet().end());

    //TipsAmount
    EXPECT_EQ(data.getTipsAmount(), -1);
    ++fieldsCount;
    EXPECT_NO_THROW(data.setTipsAmount(minimumValue));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), minimumValue);
    EXPECT_NO_THROW(data.setTipsAmount(maximumValue));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), maximumValue);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::TipsAmount), data.getFieldsSet().end());

    //CashbackAmount
    EXPECT_EQ(data.getCashbackAmount(), -1);
    ++fieldsCount;
    EXPECT_NO_THROW(data.setCashbackAmount(minimumValue));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getCashbackAmount(), minimumValue);
    EXPECT_NO_THROW(data.setCashbackAmount(maximumValue));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getCashbackAmount(), maximumValue);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::CashbackAmount), data.getFieldsSet().end());

}

TEST(RequestData, CheckCurrencyCode) {
    RequestData data;
    int16_t minimumValue = 1;
    int16_t maximumValue = 999;
    int16_t lessMinimum = minimumValue - 1;
    int16_t greatMaximum = maximumValue + 1;

    EXPECT_THROW(data.setCurrencyCode(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setCurrencyCode(greatMaximum), std::invalid_argument);

    EXPECT_EQ(data.getCurrencyCode(), -1);

    EXPECT_NO_THROW(data.setCurrencyCode(minimumValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), minimumValue);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::CurrencyCode), data.getFieldsSet().end());

    EXPECT_NO_THROW(data.setCurrencyCode(maximumValue));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), maximumValue);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::CurrencyCode), data.getFieldsSet().end());
}

TEST(RequestData, CheckRRN) {
    RequestData data;

    //empty value
    std::string value;
    EXPECT_THROW(data.setRRN(value), std::invalid_argument);

    //great len
    value = "0123456789ABC";
    EXPECT_THROW(data.setRRN(value), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getRRN().empty());

    value = "0";
    EXPECT_NO_THROW(data.setRRN(value));
    EXPECT_STREQ(data.getRRN().c_str(), value.c_str());

    value = "0123456789AB";
    EXPECT_NO_THROW(data.setRRN(value));
    EXPECT_STREQ(data.getRRN().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::RRN), data.getFieldsSet().end());
}

TEST(RequestData, CheckAuthCode) {
    RequestData data;

    //empty value
    std::string value;
    EXPECT_THROW(data.setAuthCode(value), std::invalid_argument);

    //great len
    value = "0123456";
    EXPECT_THROW(data.setAuthCode(value), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getAuthCode().empty());

    value = "0";
    EXPECT_NO_THROW(data.setAuthCode(value));
    EXPECT_STREQ(data.getAuthCode().c_str(), value.c_str());

    value = "012345";
    EXPECT_NO_THROW(data.setAuthCode(value));
    EXPECT_STREQ(data.getAuthCode().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::AuthCode), data.getFieldsSet().end());
}

TEST(RequestData, CheckReceiptReference) {
    RequestData data;

    //empty value
    std::string value;
    EXPECT_THROW(data.setReceiptReference(value), std::invalid_argument);

    //great len
    value = "0123456";
    EXPECT_THROW(data.setReceiptReference(value), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getReceiptReference().empty());

    value = "0";
    EXPECT_NO_THROW(data.setReceiptReference(value));
    EXPECT_STREQ(data.getReceiptReference().c_str(), value.c_str());

    value = "012345";
    EXPECT_NO_THROW(data.setReceiptReference(value));
    EXPECT_STREQ(data.getReceiptReference().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::ReceiptReference), data.getFieldsSet().end());
}

TEST(RequestData, CheckTransactionID) {
    RequestData data;

    //empty value
    std::string value;
    EXPECT_THROW(data.setTransactionId(value), std::invalid_argument);

    //gt max len. 41 chars
    value = "0123456789ABCDEF0123456789ABCDEF012345678";
    EXPECT_THROW(data.setTransactionId(value), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getTransactionId().empty());

    value = "0";
    EXPECT_NO_THROW(data.setTransactionId(value));
    EXPECT_STREQ(data.getTransactionId().c_str(), value.c_str());

    value = "0123456789ABCDEF0123456789ABCDEF01234567";
    EXPECT_NO_THROW(data.setTransactionId(value));
    EXPECT_STREQ(data.getTransactionId().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::TransactionID), data.getFieldsSet().end());
}

TEST(RequestData, CheckCardDataEnc) {
    RequestData data;

    //empty value
    std::string value;
    EXPECT_THROW(data.setCardDataEnc(value), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardDataEnc().empty());

    value = "0";
    EXPECT_NO_THROW(data.setCardDataEnc(value));
    EXPECT_STREQ(data.getCardDataEnc().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::CardDataEnc), data.getFieldsSet().end());
}

TEST(RequestData, CheckOpenTags) {
    RequestData data;

    //empty value
    std::string value;
    EXPECT_THROW(data.setOpenTags(value), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getOpenTags().empty());

    value = "0";
    EXPECT_NO_THROW(data.setOpenTags(value));
    EXPECT_STREQ(data.getOpenTags().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::OpenTags), data.getFieldsSet().end());
}

TEST(RequestData, CheckEncTags) {
    RequestData data;

    //empty value
    std::string value;
    EXPECT_THROW(data.setEncTags(value), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getEncTags().empty());

    value = "0";
    EXPECT_NO_THROW(data.setEncTags(value));
    EXPECT_STREQ(data.getEncTags().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EncTags), data.getFieldsSet().end());
}

TEST(RequestData, CheckProviderCode) {
    RequestData data;

    //empty value
    std::string value;
    EXPECT_THROW(data.setProviderCode(value), std::invalid_argument);

    //gt max len. 5
    value = "01234";
    EXPECT_THROW(data.setProviderCode(value), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getProviderCode().empty());

    value = "0";
    EXPECT_NO_THROW(data.setProviderCode(value));
    EXPECT_STREQ(data.getProviderCode().c_str(), value.c_str());

    value = "0123";
    EXPECT_NO_THROW(data.setProviderCode(value));
    EXPECT_STREQ(data.getProviderCode().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::ProviderCode), data.getFieldsSet().end());
}

TEST(RequestData, CheckAdditionalInfo) {
    RequestData data;

    //empty value
    std::string value;
    EXPECT_THROW(data.setEncTags(value), std::invalid_argument);

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getEncTags().empty());

    value = "0";
    EXPECT_NO_THROW(data.setEncTags(value));
    EXPECT_STREQ(data.getEncTags().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EncTags), data.getFieldsSet().end());
}