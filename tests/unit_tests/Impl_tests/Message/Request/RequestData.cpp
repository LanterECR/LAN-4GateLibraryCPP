//
// Created by Владимир Лысенков on 20.06.2020.
//

#include "gtest/gtest.h"
#include "Lanter/Message/Request/RequestData.h"
#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;
using namespace Lanter::Utils::Constants;

TEST(RequestData, CheckIsFieldSet) {
    RequestData data;

    EXPECT_FALSE(data.isFieldSet(RequestFields::EcrNumber));
    EXPECT_FALSE(data.isFieldSet(RequestFields::OperationCode));

    data.setEcrNumber(10);
    data.setOperationCode(OperationCodes::GetLastOperation);

    EXPECT_TRUE(data.isFieldSet(RequestFields::EcrNumber));
    EXPECT_TRUE(data.isFieldSet(RequestFields::OperationCode));
}
TEST(RequestData, CheckEcrNumber) {
    RequestData data;
    int16_t lessMinimum = MINIMUM_ECR_NUMBER - 1;
    int16_t greatMaximum = MAXIMUM_ECR_NUMBER + 1;

    EXPECT_FALSE(data.setEcrNumber(lessMinimum));
    EXPECT_FALSE(data.setEcrNumber(greatMaximum));

    EXPECT_EQ(data.getEcrNumber(), -1);

    EXPECT_TRUE(data.setEcrNumber(MINIMUM_ECR_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), MINIMUM_ECR_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EcrNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.setEcrNumber(MAXIMUM_ECR_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), MAXIMUM_ECR_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EcrNumber), data.getFieldsSet().end());
}

TEST(RequestData, ChechEcrMerchantNumber) {
    RequestData data;

    int16_t lessMinimum = MINIMUM_ECR_MERCHANT_NUMBER - 1;
    int16_t greatMaximum = MAXIMUM_ECR_MERCHANT_NUMBER + 1;

    EXPECT_FALSE(data.setEcrMerchantNumber(lessMinimum));
    EXPECT_FALSE(data.setEcrMerchantNumber(greatMaximum));

    EXPECT_EQ(data.getEcrMerchantNumber(), -1);

    EXPECT_TRUE(data.setEcrMerchantNumber(MINIMUM_ECR_MERCHANT_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), MINIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EcrMerchantNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.setEcrMerchantNumber(MAXIMUM_ECR_MERCHANT_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), MAXIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EcrMerchantNumber), data.getFieldsSet().end());
}

TEST(RequestData, CheckOperationCode) {
    RequestData data;

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

    EXPECT_NE(data.getFieldsSet().find(RequestFields::OperationCode), data.getFieldsSet().end());
}

TEST(RequestData, CheckAllAmounts) {
    RequestData data;

    int64_t lessMinimum = MINIMUM_AMOUNT - 1;
    int64_t greatMaximum = MAXIMUM_AMOUNT + 1;

    int fieldsCount = 0;
    //Amount
    EXPECT_FALSE(data.setAmount(lessMinimum));
    EXPECT_FALSE(data.setAmount(greatMaximum));

    EXPECT_EQ(data.getAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::Amount), data.getFieldsSet().end());

    //ParialAmount
    EXPECT_EQ(data.getPartialAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setPartialAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setPartialAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::PartialAmount), data.getFieldsSet().end());

    //TipsAmount
    EXPECT_EQ(data.getTipsAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setTipsAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setTipsAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::TipsAmount), data.getFieldsSet().end());

    //CashbackAmount
    EXPECT_EQ(data.getCashbackAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setCashbackAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getCashbackAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setCashbackAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getCashbackAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::CashbackAmount), data.getFieldsSet().end());

}

TEST(RequestData, CheckCurrencyCode) {
    RequestData data;

    int16_t lessMinimum = MINIMUM_CURRENCY_CODE - 1;
    int16_t greatMaximum = MAXIMUM_CURRENCY_CODE + 1;

    EXPECT_FALSE(data.setCurrencyCode(lessMinimum));
    EXPECT_FALSE(data.setCurrencyCode(greatMaximum));

    EXPECT_EQ(data.getCurrencyCode(), -1);

    EXPECT_TRUE(data.setCurrencyCode(MINIMUM_CURRENCY_CODE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), MINIMUM_CURRENCY_CODE);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::CurrencyCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.setCurrencyCode(MAXIMUM_CURRENCY_CODE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), MAXIMUM_CURRENCY_CODE);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::CurrencyCode), data.getFieldsSet().end());
}

TEST(RequestData, CheckRRN) {
    RequestData data;

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
    EXPECT_NE(data.getFieldsSet().find(RequestFields::RRN), data.getFieldsSet().end());
}

TEST(RequestData, CheckAuthCode) {
    RequestData data;

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

    std::string maximumSize(MAXIMUM_RRN_LENGTH, '0');
    EXPECT_TRUE(data.setAuthCode(maximumSize));
    EXPECT_STREQ(data.getAuthCode().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::AuthCode), data.getFieldsSet().end());
}

TEST(RequestData, CheckReceiptReference) {
    RequestData data;

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
    EXPECT_NE(data.getFieldsSet().find(RequestFields::ReceiptReference), data.getFieldsSet().end());
}

TEST(RequestData, CheckTransactionID) {
    RequestData data;

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
    EXPECT_NE(data.getFieldsSet().find(RequestFields::TransactionID), data.getFieldsSet().end());
}

TEST(RequestData, CheckCardDataEnc) {
    RequestData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCardDataEnc(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardDataEnc().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setCardDataEnc(value));
    EXPECT_STRCASEEQ(data.getCardDataEnc().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::CardDataEnc), data.getFieldsSet().end());
}

TEST(RequestData, CheckOpenTags) {
    RequestData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setOpenTags(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getOpenTags().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setOpenTags(value));
    EXPECT_STRCASEEQ(data.getOpenTags().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::OpenTags), data.getFieldsSet().end());
}

TEST(RequestData, CheckEncTags) {
    RequestData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setEncTags(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getEncTags().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setEncTags(value));
    EXPECT_STRCASEEQ(data.getEncTags().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::EncTags), data.getFieldsSet().end());
}

TEST(RequestData, CheckProviderCode) {
    RequestData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setProviderCode(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getProviderCode().empty());

    std::string oversize(MAXIMUM_PROVIDER_CODE_LENGTH + 1, '0');
    EXPECT_FALSE(data.setProviderCode(oversize));

    std::string minimumSize(MINIMUM_PROVIDER_CODE_LENGTH, '0');
    EXPECT_TRUE(data.setProviderCode(minimumSize));
    EXPECT_STREQ(data.getProviderCode().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_PROVIDER_CODE_LENGTH, '0');
    EXPECT_TRUE(data.setProviderCode(maximumSize));
    EXPECT_STREQ(data.getProviderCode().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::ProviderCode), data.getFieldsSet().end());
}

TEST(RequestData, CheckAdditionalInfo) {
    RequestData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setAdditionalInfo(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getAdditionalInfo().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setAdditionalInfo(value));
    EXPECT_STRCASEEQ(data.getAdditionalInfo().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestFields::AdditionalInfo), data.getFieldsSet().end());
}