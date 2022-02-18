#include "gtest/gtest.h"
#include "Lanter/Message/Request/RequestData.h"
#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;
using namespace Lanter::Utils::Constants;

TEST(TestRequestData, CheckIsFieldSet) {
    RequestData data;

    EXPECT_FALSE(data.isFieldSet(RequestField::EcrNumber));
    EXPECT_FALSE(data.isFieldSet(RequestField::OperationCode));

    EXPECT_TRUE(data.setEcrNumber(10));
    EXPECT_TRUE(data.setOperationCode(OperationCode::GetLastOperation));

    EXPECT_TRUE(data.isFieldSet(RequestField::EcrNumber));
    EXPECT_TRUE(data.isFieldSet(RequestField::OperationCode));

    for(int i = 0; i < 3; i++) {
        EXPECT_TRUE(data.resetField(RequestField::EcrNumber));
        EXPECT_TRUE(data.resetField(RequestField::OperationCode));
    }

    EXPECT_TRUE(data.getFieldsSet().empty());
}
TEST(TestRequestData, CheckEcrNumber) {
    RequestData data;
    int16_t lessMinimum = MINIMUM_ECR_NUMBER - 1;
    int16_t greatMaximum = MAXIMUM_ECR_NUMBER + 1;

    EXPECT_FALSE(data.setEcrNumber(lessMinimum));
    EXPECT_FALSE(data.setEcrNumber(greatMaximum));

    EXPECT_EQ(data.getEcrNumber(), -1);

    EXPECT_TRUE(data.setEcrNumber(MINIMUM_ECR_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), MINIMUM_ECR_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(RequestField::EcrNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.setEcrNumber(MAXIMUM_ECR_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), MAXIMUM_ECR_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(RequestField::EcrNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetEcrNumber());
    EXPECT_EQ(data.getEcrNumber(), -1);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, ChechEcrMerchantNumber) {
    RequestData data;

    int16_t lessMinimum = MINIMUM_ECR_MERCHANT_NUMBER - 1;
    int16_t greatMaximum = MAXIMUM_ECR_MERCHANT_NUMBER + 1;

    EXPECT_FALSE(data.setEcrMerchantNumber(lessMinimum));
    EXPECT_FALSE(data.setEcrMerchantNumber(greatMaximum));

    EXPECT_EQ(data.getEcrMerchantNumber(), -1);

    EXPECT_TRUE(data.setEcrMerchantNumber(MINIMUM_ECR_MERCHANT_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), MINIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(RequestField::EcrMerchantNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.setEcrMerchantNumber(MAXIMUM_ECR_MERCHANT_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), MAXIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(RequestField::EcrMerchantNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetEcrMerchantNumber());
    EXPECT_EQ(data.getEcrMerchantNumber(), -1);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckOperationCode) {
    RequestData data;

    auto greatMaximum = (OperationCode)((int)(getLastOperationCode()) + 1);
    EXPECT_FALSE(data.setOperationCode(OperationCode::NoOperation));
    EXPECT_EQ(data.getFieldsSet().size(), 0);
    EXPECT_FALSE(data.setOperationCode(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOperationCode(), OperationCode::NoOperation);

    EXPECT_TRUE(data.setOperationCode(getFirstOperationCode()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOperationCode(), getFirstOperationCode());

    EXPECT_TRUE(data.setOperationCode(getLastOperationCode()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOperationCode(), getLastOperationCode());

    EXPECT_NE(data.getFieldsSet().find(RequestField::OperationCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetOperationCode());
    EXPECT_EQ(data.getOperationCode(), OperationCode::NoOperation);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckAllAmounts) {
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
    EXPECT_NE(data.getFieldsSet().find(RequestField::Amount), data.getFieldsSet().end());

    //ParialAmount
    EXPECT_EQ(data.getPartialAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setPartialAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setPartialAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(RequestField::PartialAmount), data.getFieldsSet().end());

    //TipsAmount
    EXPECT_EQ(data.getTipsAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setTipsAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setTipsAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(RequestField::TipsAmount), data.getFieldsSet().end());

    //CashbackAmount
    EXPECT_EQ(data.getCashbackAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setCashbackAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getCashbackAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setCashbackAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getCashbackAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(RequestField::CashbackAmount), data.getFieldsSet().end());

    //BonusBalance
    EXPECT_EQ(data.getBonusBalance(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setBonusBalance(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getBonusBalance(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setBonusBalance(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getBonusBalance(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(RequestField::BonusBalance), data.getFieldsSet().end());

    //BonusAmount
    EXPECT_EQ(data.getBonusAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setBonusAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getBonusAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setBonusAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getBonusAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(RequestField::BonusAmount), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetAmount());
    EXPECT_EQ(data.getAmount(), -1);

    EXPECT_TRUE(data.resetPartialAmount());
    EXPECT_EQ(data.getPartialAmount(), -1);

    EXPECT_TRUE(data.resetTipsAmount());
    EXPECT_EQ(data.getTipsAmount(), -1);

    EXPECT_TRUE(data.resetCashbackAmount());
    EXPECT_EQ(data.getCashbackAmount(), -1);

    EXPECT_TRUE(data.resetBonusBalance());
    EXPECT_EQ(data.getBonusBalance(), -1);

    EXPECT_TRUE(data.resetBonusAmount());
    EXPECT_EQ(data.getBonusAmount(), -1);

    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckCurrencyCode) {
    RequestData data;

    int16_t lessMinimum = MINIMUM_CURRENCY_CODE - 1;
    int16_t greatMaximum = MAXIMUM_CURRENCY_CODE + 1;

    EXPECT_FALSE(data.setCurrencyCode(std::to_string(lessMinimum)));
    EXPECT_FALSE(data.setCurrencyCode(std::to_string(greatMaximum)));

    EXPECT_TRUE(data.getCurrencyCode().empty());

    EXPECT_TRUE(data.setCurrencyCode(std::to_string((MINIMUM_CURRENCY_CODE))));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), std::to_string(MINIMUM_CURRENCY_CODE));
    EXPECT_NE(data.getFieldsSet().find(RequestField::CurrencyCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.setCurrencyCode(std::to_string((MAXIMUM_CURRENCY_CODE))));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), std::to_string(MAXIMUM_CURRENCY_CODE));
    EXPECT_NE(data.getFieldsSet().find(RequestField::CurrencyCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCurrencyCode());
    EXPECT_TRUE(data.getCurrencyCode().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckRRN) {
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
    EXPECT_NE(data.getFieldsSet().find(RequestField::RRN), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetRRN());
    EXPECT_TRUE(data.getRRN().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckAuthCode) {
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
    EXPECT_NE(data.getFieldsSet().find(RequestField::AuthCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetAuthCode());
    EXPECT_TRUE(data.getAuthCode().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckReceiptReference) {
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
    EXPECT_NE(data.getFieldsSet().find(RequestField::ReceiptReference), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetReceiptReference());
    EXPECT_TRUE(data.getReceiptReference().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckTransactionID) {
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
    EXPECT_NE(data.getFieldsSet().find(RequestField::TransactionID), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetTransactionID());
    EXPECT_TRUE(data.getTransactionID().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckCardDataEnc) {
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
    EXPECT_NE(data.getFieldsSet().find(RequestField::CardDataEnc), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCardDataEnc());
    EXPECT_TRUE(data.getCardDataEnc().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckOpenTags) {
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
    EXPECT_NE(data.getFieldsSet().find(RequestField::OpenTags), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetOpenTags());
    EXPECT_TRUE(data.getOpenTags().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckEncTags) {
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
    EXPECT_NE(data.getFieldsSet().find(RequestField::EncTags), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetEncTags());
    EXPECT_TRUE(data.getEncTags().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckProviderCode) {
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
    EXPECT_NE(data.getFieldsSet().find(RequestField::ProviderCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetProviderCode());
    EXPECT_TRUE(data.getProviderCode().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckAdditionalInfo) {
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
    EXPECT_NE(data.getFieldsSet().find(RequestField::AdditionalInfo), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetAdditionalInfo());
    EXPECT_TRUE(data.getAdditionalInfo().empty());

    EXPECT_TRUE(data.resetAdditionalInfo());
    EXPECT_TRUE(data.getAdditionalInfo().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckHashCardTrack2) {
    RequestData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setHashCardTrack2(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getHashCardTrack2().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setHashCardTrack2(value));
    EXPECT_STRCASEEQ(data.getHashCardTrack2().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestField::HashCardTrack2), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetHashCardTrack2());
    EXPECT_TRUE(data.getHashCardTrack2().empty());

    EXPECT_TRUE(data.resetHashCardTrack2());
    EXPECT_TRUE(data.getHashCardTrack2().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckPaymentProviderCode) {
    RequestData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setPaymentProviderCode(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getPaymentProviderCode().empty());

    std::string oversize(MAXIMUM_PROVIDER_CODE_LENGTH + 1, '0');
    EXPECT_FALSE(data.setPaymentProviderCode(oversize));

    std::string minimumSize(MINIMUM_PROVIDER_CODE_LENGTH, '0');
    EXPECT_TRUE(data.setPaymentProviderCode(minimumSize));
    EXPECT_STREQ(data.getPaymentProviderCode().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_PROVIDER_CODE_LENGTH, '0');
    EXPECT_TRUE(data.setPaymentProviderCode(maximumSize));
    EXPECT_STREQ(data.getPaymentProviderCode().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestField::PaymentProviderCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetPaymentProviderCode());
    EXPECT_TRUE(data.getPaymentProviderCode().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckPaymentParam1) {
    RequestData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setPaymentParam1(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getPaymentParam1().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setPaymentParam1(value));
    EXPECT_STRCASEEQ(data.getPaymentParam1().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestField::PaymentParam1), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetPaymentParam1());
    EXPECT_TRUE(data.getPaymentParam1().empty());

    EXPECT_TRUE(data.resetPaymentParam1());
    EXPECT_TRUE(data.getPaymentParam1().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckPaymentParam2) {
    RequestData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setPaymentParam2(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getPaymentParam2().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setPaymentParam2(value));
    EXPECT_STRCASEEQ(data.getPaymentParam2().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestField::PaymentParam2), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetPaymentParam2());
    EXPECT_TRUE(data.getPaymentParam2().empty());

    EXPECT_TRUE(data.resetPaymentParam2());
    EXPECT_TRUE(data.getPaymentParam2().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestRequestData, CheckPaymentParam3) {
    RequestData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setPaymentParam3(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getPaymentParam3().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setPaymentParam3(value));
    EXPECT_STRCASEEQ(data.getPaymentParam3().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(RequestField::PaymentParam3), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetPaymentParam3());
    EXPECT_TRUE(data.getPaymentParam3().empty());

    EXPECT_TRUE(data.resetPaymentParam3());
    EXPECT_TRUE(data.getPaymentParam3().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}
