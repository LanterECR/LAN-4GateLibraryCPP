#include "gtest/gtest.h"
#include "Lanter/Message/Response/ResponseData.h"
#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;
using namespace Lanter::Utils::Constants;

TEST(TestResponseData, CheckIsFieldSet) {
    ResponseData data;

    EXPECT_FALSE(data.isFieldSet(ResponseField::EcrNumber));
    EXPECT_FALSE(data.isFieldSet(ResponseField::OperationCode));

    EXPECT_TRUE(data.setEcrNumber(10));
    EXPECT_TRUE(data.setOperationCode(OperationCode::GetLastOperation));

    EXPECT_TRUE(data.isFieldSet(ResponseField::EcrNumber));
    EXPECT_TRUE(data.isFieldSet(ResponseField::OperationCode));

    for(int i = 0; i < 3; i++) {
        EXPECT_TRUE(data.resetField(ResponseField::EcrNumber));
        EXPECT_TRUE(data.resetField(ResponseField::OperationCode));
    }

    EXPECT_TRUE(data.getFieldsSet().empty());
}
TEST(TestResponseData, CheckEcrNumber) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ECR_NUMBER - 1;
    int16_t greatMaximum = MAXIMUM_ECR_NUMBER + 1;

    EXPECT_FALSE(data.setEcrNumber(lessMinimum));
    EXPECT_FALSE(data.setEcrNumber(greatMaximum));

    EXPECT_EQ(data.getEcrNumber(), -1);

    EXPECT_TRUE(data.setEcrNumber(MINIMUM_ECR_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), MINIMUM_ECR_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::EcrNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.setEcrNumber(MAXIMUM_ECR_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrNumber(), MAXIMUM_ECR_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::EcrNumber), data.getFieldsSet().end());
    
    EXPECT_TRUE(data.resetEcrNumber());
    EXPECT_EQ(data.getEcrNumber(), -1);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckEcrMerchantNumber) {
    ResponseData data;

    int16_t lessMinimum = MINIMUM_ECR_MERCHANT_NUMBER - 1;
    int16_t greatMaximum = MAXIMUM_ECR_MERCHANT_NUMBER + 1;

    EXPECT_FALSE(data.setEcrMerchantNumber(lessMinimum));
    EXPECT_FALSE(data.setEcrMerchantNumber(greatMaximum));

    EXPECT_EQ(data.getEcrMerchantNumber(), -1);

    EXPECT_TRUE(data.setEcrMerchantNumber(MINIMUM_ECR_MERCHANT_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), MINIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::EcrMerchantNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.setEcrMerchantNumber(MAXIMUM_ECR_MERCHANT_NUMBER));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getEcrMerchantNumber(), MAXIMUM_ECR_MERCHANT_NUMBER);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::EcrMerchantNumber), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetEcrMerchantNumber());
    EXPECT_EQ(data.getEcrMerchantNumber(), -1);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckOperationCode) {
    ResponseData data;

    auto greatMaximum = (OperationCode)((int)(getLastOperationCode()) + 1);
    EXPECT_FALSE(data.setOperationCode(OperationCode::NoOperation));
    EXPECT_EQ(data.getFieldsSet().size(), 0);
    EXPECT_FALSE(data.setOperationCode(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOperationCode(), OperationCode::NoOperation);

    EXPECT_TRUE(data.setOperationCode(getFirstOperationCode()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOperationCode(), getFirstOperationCode());
    EXPECT_FALSE(data.getMandatoryFields().empty());

    EXPECT_TRUE(data.setOperationCode(getLastOperationCode()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOperationCode(), getLastOperationCode());
    EXPECT_NE(data.getFieldsSet().find(ResponseField::OperationCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetOperationCode());
    EXPECT_EQ(data.getOperationCode(), OperationCode::NoOperation);
    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getMandatoryFields().empty());
}

TEST(TestResponseData, CheckOriginalOperationCode) {
    ResponseData data;

    auto greatMaximum = (OperationCode)((int)(getLastOperationCode()) + 1);
    EXPECT_FALSE(data.setOriginalOperationCode(OperationCode::NoOperation));
    EXPECT_EQ(data.getFieldsSet().size(), 0);
    EXPECT_FALSE(data.setOriginalOperationCode(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOriginalOperationCode(), OperationCode::NoOperation);

    EXPECT_TRUE(data.setOriginalOperationCode(getFirstOperationCode()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationCode(), getFirstOperationCode());

    EXPECT_TRUE(data.setOriginalOperationCode(getLastOperationCode()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationCode(), getLastOperationCode());
    EXPECT_NE(data.getFieldsSet().find(ResponseField::OriginalOperationCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetOriginalOperationCode());
    EXPECT_EQ(data.getOriginalOperationCode(), OperationCode::NoOperation);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckAllAmount) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::TotalAmount), data.getFieldsSet().end());

    //ParialAmount
    EXPECT_EQ(data.getPartialAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setPartialAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setPartialAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getPartialAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::PartialAmount), data.getFieldsSet().end());

    //TipsAmount
    EXPECT_EQ(data.getTipsAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setTipsAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setTipsAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTipsAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::TipsAmount), data.getFieldsSet().end());

    //AcquirerFeeAmount
    EXPECT_EQ(data.getAcquirerFeeAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setAcquirerFeeAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getAcquirerFeeAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setAcquirerFeeAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getAcquirerFeeAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::AcquirerFeeAmount), data.getFieldsSet().end());

    //TerminalFeeAmount
    EXPECT_EQ(data.getTerminalFeeAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setTerminalFeeAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTerminalFeeAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setTerminalFeeAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getTerminalFeeAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::TerminalFeeAmount), data.getFieldsSet().end());

    //BonusBalance
    EXPECT_EQ(data.getBonusBalance(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setBonusBalance(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getBonusBalance(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setBonusBalance(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getBonusBalance(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::BonusBalance), data.getFieldsSet().end());

    //BonusAmount
    EXPECT_EQ(data.getBonusAmount(), -1);
    ++fieldsCount;
    EXPECT_TRUE(data.setBonusAmount(MINIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getBonusAmount(), MINIMUM_AMOUNT);
    EXPECT_TRUE(data.setBonusAmount(MAXIMUM_AMOUNT));
    EXPECT_EQ(data.getFieldsSet().size(), fieldsCount);
    EXPECT_EQ(data.getBonusAmount(), MAXIMUM_AMOUNT);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::BonusAmount), data.getFieldsSet().end());
    
    EXPECT_TRUE(data.resetTotalAmount());
    EXPECT_EQ(data.getTotalAmount(), -1);

    EXPECT_TRUE(data.resetPartialAmount());
    EXPECT_EQ(data.getPartialAmount(), -1);

    EXPECT_TRUE(data.resetTipsAmount());
    EXPECT_EQ(data.getTipsAmount(), -1);

    EXPECT_TRUE(data.resetAcquirerFeeAmount());
    EXPECT_EQ(data.getAcquirerFeeAmount(), -1);

    EXPECT_TRUE(data.resetTerminalFeeAmount());
    EXPECT_EQ(data.getTerminalFeeAmount(), -1);

    EXPECT_TRUE(data.resetBonusBalance());
    EXPECT_EQ(data.getBonusBalance(), -1);

    EXPECT_TRUE(data.resetBonusAmount());
    EXPECT_EQ(data.getBonusAmount(), -1);

    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCurrencyCode) {
    ResponseData data;

    int16_t lessMinimum = MINIMUM_CURRENCY_CODE - 1;
    int16_t greatMaximum = MAXIMUM_CURRENCY_CODE + 1;

    EXPECT_FALSE(data.setCurrencyCode(std::to_string(lessMinimum)));
    EXPECT_FALSE(data.setCurrencyCode(std::to_string(greatMaximum)));

    EXPECT_TRUE(data.getCurrencyCode().empty());

    EXPECT_TRUE(data.setCurrencyCode(std::to_string((MINIMUM_CURRENCY_CODE))));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), std::to_string(MINIMUM_CURRENCY_CODE));
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CurrencyCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.setCurrencyCode(std::to_string((MAXIMUM_CURRENCY_CODE))));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCurrencyCode(), std::to_string(MAXIMUM_CURRENCY_CODE));
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CurrencyCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCurrencyCode());
    EXPECT_TRUE(data.getCurrencyCode().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckReceiptReference) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::ReceiptReference), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetReceiptReference());
    EXPECT_TRUE(data.getReceiptReference().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckRRN) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::RRN), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetRRN());
    EXPECT_TRUE(data.getRRN().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckStatus) {
    ResponseData data;

    auto greatMaximum = (Status)((int)(getLastStatus()) + 1);
    EXPECT_FALSE(data.setStatus(Status::NoStatus));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_FALSE(data.setStatus(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getStatus(), Status::NoStatus);

    EXPECT_TRUE(data.setStatus(getFirstStatus()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getStatus(), getFirstStatus());

    EXPECT_TRUE(data.setStatus(getLastStatus()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getStatus(), getLastStatus());
    EXPECT_NE(data.getFieldsSet().find(ResponseField::Status), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetStatus());
    EXPECT_EQ(data.getStatus(), Status::NoStatus);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckOriginalOperationStatus) {
    ResponseData data;

    auto greatMaximum = (Status)((int)(getLastStatus()) + 1);
    EXPECT_FALSE(data.setOriginalOperationStatus(Status::NoStatus));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_FALSE(data.setOriginalOperationStatus(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getOriginalOperationStatus(), Status::NoStatus);

    EXPECT_TRUE(data.setOriginalOperationStatus(getFirstStatus()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationStatus(), getFirstStatus());

    EXPECT_TRUE(data.setOriginalOperationStatus(getLastStatus()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getOriginalOperationStatus(), getLastStatus());
    EXPECT_NE(data.getFieldsSet().find(ResponseField::OriginalOperationStatus), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetOriginalOperationStatus());
    EXPECT_EQ(data.getOriginalOperationStatus(), Status::NoStatus);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckTransDateTime) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::TransDateTime), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetTransDateTime());
    EXPECT_TRUE(data.getTransDateTime().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckTerminalDateTime) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::TerminalDateTime), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetTerminalDateTime());
    EXPECT_TRUE(data.getTerminalDateTime().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCardPan) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CardPAN), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCardPAN());
    EXPECT_TRUE(data.getCardPAN().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckExpireDate) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::ExpireDate), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetExpireDate());
    EXPECT_TRUE(data.getExpireDate().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCardholderName) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CardholderName), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCardholderName());
    EXPECT_TRUE(data.getCardholderName().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCardholderAuthMethod) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CardholderAuthMethod), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCardholderAuthMethod());
    EXPECT_EQ(data.getCardholderAuthMethod(), CardholderAuthMethod::NoMethod);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckAuthCode) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::AuthCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetAuthCode());
    EXPECT_TRUE(data.getAuthCode().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckResponseCode) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::ResponseCode), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetResponseCode());
    EXPECT_TRUE(data.getResponseCode().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckResponseText) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::ResponseText), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetResponseText());
    EXPECT_TRUE(data.getResponseText().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckSTAN) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::STAN), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetSTAN());
    EXPECT_TRUE(data.getSTAN().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckTransactionID) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::TransactionID), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetTransactionID());
    EXPECT_TRUE(data.getTransactionID().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckTerminalId) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::TerminalID), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetTerminalID());
    EXPECT_TRUE(data.getTerminalID().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCardEmvAid) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCardEmvAid(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardEmvAid().empty());

    std::string oversize(MAXIMUM_CARD_EMV_AID_LENGTH + 1, '0');
    EXPECT_FALSE(data.setCardEmvAid(oversize));

    std::string minimumSize(MINIMUM_CARD_EMV_AID_LENGTH, '0');
    EXPECT_TRUE(data.setCardEmvAid(minimumSize));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), minimumSize.c_str());

    std::string maximumSize(MAXIMUM_CARD_EMV_AID_LENGTH, '0');
    EXPECT_TRUE(data.setCardEmvAid(maximumSize));
    EXPECT_STREQ(data.getCardEmvAid().c_str(), maximumSize.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CardEmvAid), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCardEmvAid());
    EXPECT_TRUE(data.getCardEmvAid().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCardAppName) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CardAppName), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCardAppName());
    EXPECT_TRUE(data.getCardAppName().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCardInputMethod) {
    ResponseData data;

    auto greatMaximum = (CardInputMethod)((int)(getLastCardInputMethod()) + 1);
    EXPECT_FALSE(data.setCardInputMethod(CardInputMethod::NoMethod));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_FALSE(data.setCardInputMethod(greatMaximum));
    EXPECT_EQ(data.getFieldsSet().size(), 0);

    EXPECT_EQ(data.getCardInputMethod(), CardInputMethod::NoMethod);

    EXPECT_TRUE(data.setCardInputMethod(getFirstCardInputMethod()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCardInputMethod(), getFirstCardInputMethod());

    EXPECT_TRUE(data.setCardInputMethod(getLastCardInputMethod()));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getCardInputMethod(), getLastCardInputMethod());
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CardInputMethod), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCardInputMethod());
    EXPECT_EQ(data.getCardInputMethod(), CardInputMethod::NoMethod);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckIssuerName) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::IssuerName), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetIssuerName());
    EXPECT_TRUE(data.getIssuerName().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckAdditionalInfo) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::AdditionalInfo), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetAdditionalInfo());
    EXPECT_TRUE(data.getAdditionalInfo().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCardData) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CardData), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCardData());
    EXPECT_TRUE(data.getCardData().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCardDataEnc) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CardDataEnc), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCardDataEnc());
    EXPECT_TRUE(data.getCardDataEnc().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckMerchantID) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::MerchantID), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetMerchantID());
    EXPECT_TRUE(data.getMerchantID().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckTVR) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::TVR), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetTVR());
    EXPECT_TRUE(data.getTVR().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckTSI) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::TSI), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetTSI());
    EXPECT_TRUE(data.getTSI().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckTC) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::TC), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetTC());
    EXPECT_TRUE(data.getTC().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCID) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CID), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCID());
    EXPECT_TRUE(data.getCID().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckKVR) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::KVR), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetKVR());
    EXPECT_TRUE(data.getKVR().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCDAResult) {
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
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CDAResult), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCDAResult());
    EXPECT_TRUE(data.getCDAResult().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckSalesCount) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int16_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_FALSE(data.setSalesCount(lessMinimum));
    EXPECT_FALSE(data.setSalesCount(greatMaximum));

    EXPECT_EQ(data.getSalesCount(), -1);

    EXPECT_TRUE(data.setSalesCount(MINIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getSalesCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::SalesCount), data.getFieldsSet().end());

    EXPECT_TRUE(data.setSalesCount(MAXIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getSalesCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::SalesCount), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetSalesCount());
    EXPECT_EQ(data.getSalesCount(), -1);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckVoidCount) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int16_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_FALSE(data.setVoidCount(lessMinimum));
    EXPECT_FALSE(data.setVoidCount(greatMaximum));

    EXPECT_EQ(data.getVoidCount(), -1);

    EXPECT_TRUE(data.setVoidCount(MINIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getVoidCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::VoidCount), data.getFieldsSet().end());

    EXPECT_TRUE(data.setVoidCount(MAXIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getVoidCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::VoidCount), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetVoidCount());
    EXPECT_EQ(data.getVoidCount(), -1);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckRefundCount) {
    ResponseData data;
    int16_t lessMinimum = MINIMUM_ARRAY_SIZE - 1;
    int16_t greatMaximum = MAXIMUM_ARRAY_SIZE + 1;

    EXPECT_FALSE(data.setRefundCount(lessMinimum));
    EXPECT_FALSE(data.setRefundCount(greatMaximum));

    EXPECT_EQ(data.getRefundCount(), -1);

    EXPECT_TRUE(data.setRefundCount(MINIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getRefundCount(), MINIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::RefundCount), data.getFieldsSet().end());

    EXPECT_TRUE(data.setRefundCount(MAXIMUM_ARRAY_SIZE));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_EQ(data.getRefundCount(), MAXIMUM_ARRAY_SIZE);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::RefundCount), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetRefundCount());
    EXPECT_EQ(data.getRefundCount(), -1);
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckSalesArray) {
    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto element = std::make_shared<ResponseData>();
    element->setTotalAmount(MAXIMUM_AMOUNT);
    array.push_back(element);

    EXPECT_TRUE(data.setSalesArray(array));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::SalesArray), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetSalesArray());
    EXPECT_TRUE(data.getSalesArray().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckVoidArray) {
    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto element = std::make_shared<ResponseData>();
    element->setTotalAmount(MAXIMUM_AMOUNT);
    array.push_back(element);

    EXPECT_TRUE(data.setVoidArray(array));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::VoidArray), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetVoidArray());
    EXPECT_TRUE(data.getVoidArray().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckRefundArray) {
    ResponseData data;

    std::vector<std::shared_ptr<IResponseData> > array;
    auto element = std::make_shared<ResponseData>();
    element->setTotalAmount(MAXIMUM_AMOUNT);
    array.push_back(element);

    EXPECT_TRUE(data.setRefundArray(array));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::RefundArray), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetRefundArray());
    EXPECT_TRUE(data.getRefundArray().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckCardPANHash) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setCardPANHash(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getCardPANHash().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setCardPANHash(value));
    EXPECT_STRCASEEQ(data.getCardPANHash().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::CardPANHash), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetCardPANHash());
    EXPECT_TRUE(data.getCardPANHash().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckReceiptLine1) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setReceiptLine1(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getReceiptLine1().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setReceiptLine1(value));
    EXPECT_STRCASEEQ(data.getReceiptLine1().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::ReceiptLine1), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetReceiptLine1());
    EXPECT_TRUE(data.getReceiptLine1().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckReceiptLine2) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setReceiptLine2(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getReceiptLine2().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setReceiptLine2(value));
    EXPECT_STRCASEEQ(data.getReceiptLine2().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::ReceiptLine2), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetReceiptLine2());
    EXPECT_TRUE(data.getReceiptLine2().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckReceiptLine3) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setReceiptLine3(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getReceiptLine3().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setReceiptLine3(value));
    EXPECT_STRCASEEQ(data.getReceiptLine3().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::ReceiptLine3), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetReceiptLine3());
    EXPECT_TRUE(data.getReceiptLine3().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckReceiptLine4) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setReceiptLine4(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getReceiptLine4().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setReceiptLine4(value));
    EXPECT_STRCASEEQ(data.getReceiptLine4().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::ReceiptLine4), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetReceiptLine4());
    EXPECT_TRUE(data.getReceiptLine4().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckReceiptLine5) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setReceiptLine5(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getReceiptLine5().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setReceiptLine5(value));
    EXPECT_STRCASEEQ(data.getReceiptLine5().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::ReceiptLine5), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetReceiptLine5());
    EXPECT_TRUE(data.getReceiptLine5().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckApplicationLabel) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setApplicationLabel(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getApplicationLabel().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setApplicationLabel(value));
    EXPECT_STRCASEEQ(data.getApplicationLabel().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::ApplicationLabel), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetApplicationLabel());
    EXPECT_TRUE(data.getApplicationLabel().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckHashCardTrack2) {
    ResponseData data;

    //empty value
    std::string emptyValue;
    EXPECT_FALSE(data.setHashCardTrack2(emptyValue));

    EXPECT_TRUE(data.getFieldsSet().empty());
    EXPECT_TRUE(data.getHashCardTrack2().empty());

    std::string value(512, '0');
    EXPECT_TRUE(data.setHashCardTrack2(value));
    EXPECT_STRCASEEQ(data.getHashCardTrack2().c_str(), value.c_str());

    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_NE(data.getFieldsSet().find(ResponseField::HashCardTrack2), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetHashCardTrack2());
    EXPECT_TRUE(data.getHashCardTrack2().empty());
    EXPECT_TRUE(data.getFieldsSet().empty());
}

TEST(TestResponseData, CheckFinalizationRequired) {
    ResponseData data;

    EXPECT_TRUE(data.setFinalizationRequired(false));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_FALSE(data.getFinalizationRequired());

    EXPECT_TRUE(data.setFinalizationRequired(true));
    EXPECT_EQ(data.getFieldsSet().size(), 1);
    EXPECT_TRUE(data.getFinalizationRequired());

    EXPECT_NE(data.getFieldsSet().find(ResponseField::FinalizationRequired), data.getFieldsSet().end());

    EXPECT_TRUE(data.resetFinalizationRequired());
    EXPECT_FALSE(data.getFinalizationRequired());
    EXPECT_TRUE(data.getFieldsSet().empty());
}
/*
FinalizationRequired
 */