#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/JSONFields/JSONClassFieldsValues.h"
#include "Lanter/MessageProcessor/JSONFields/JSONRootFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONRequestFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONResponseFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONNotificationFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONInteractionFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONCommunicationFields.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;

TEST(TestJSONFields, CheckRootFields) {
    EXPECT_FALSE(JSONRootFields::getClassField().empty());
    EXPECT_FALSE(JSONRootFields::getObjectField().empty());
}

TEST(TestJSONFields, CheckClassFieldsValues) {
    EXPECT_FALSE(JSONClassFieldValues::getRequestValue().empty());
    EXPECT_FALSE(JSONClassFieldValues::getResponseValue().empty());
    EXPECT_FALSE(JSONClassFieldValues::getCommunicationValue().empty());
    EXPECT_FALSE(JSONClassFieldValues::getNotificationValue().empty());
    EXPECT_FALSE(JSONClassFieldValues::getInteractionValue().empty());
}

TEST(TestJSONFields, CheckRequestFields) {
    EXPECT_FALSE(JSONRequestFields::getEcrNumber().empty());
    EXPECT_FALSE(JSONRequestFields::getEcrMerchantNumber().empty());
    EXPECT_FALSE(JSONRequestFields::getOperationCode().empty());
    EXPECT_FALSE(JSONRequestFields::getAmount().empty());
    EXPECT_FALSE(JSONRequestFields::getPartialAmount().empty());
    EXPECT_FALSE(JSONRequestFields::getTipsAmount().empty());
    EXPECT_FALSE(JSONRequestFields::getCashbackAmount().empty());
    EXPECT_FALSE(JSONRequestFields::getCurrencyCode().empty());
    EXPECT_FALSE(JSONRequestFields::getRRN().empty());
    EXPECT_FALSE(JSONRequestFields::getAuthCode().empty());
    EXPECT_FALSE(JSONRequestFields::getReceiptReference().empty());
    EXPECT_FALSE(JSONRequestFields::getTransactionID().empty());
    EXPECT_FALSE(JSONRequestFields::getCardDataEnc().empty());
    EXPECT_FALSE(JSONRequestFields::getOpenTags().empty());
    EXPECT_FALSE(JSONRequestFields::getEncTags().empty());
    EXPECT_FALSE(JSONRequestFields::getProviderCode().empty());
    EXPECT_FALSE(JSONRequestFields::getAdditionalInfo().empty());
    EXPECT_FALSE(JSONRequestFields::getCfgTerminalId().empty());
}

TEST(TestJSONFields, CheckResponseFields) {
    EXPECT_FALSE(JSONResponseFields::getEcrNumber().empty());
    EXPECT_FALSE(JSONResponseFields::getEcrMerchantNumber().empty());
    EXPECT_FALSE(JSONResponseFields::getOperationCode().empty());
    EXPECT_FALSE(JSONResponseFields::getOriginalOperationCode().empty());
    EXPECT_FALSE(JSONResponseFields::getPartialAmount().empty());
    EXPECT_FALSE(JSONResponseFields::getTotalAmount().empty());
    EXPECT_FALSE(JSONResponseFields::getAcquirerFeeAmount().empty());
    EXPECT_FALSE(JSONResponseFields::getTerminalFeeAmount().empty());
    EXPECT_FALSE(JSONResponseFields::getTipsAmount().empty());
    EXPECT_FALSE(JSONResponseFields::getCurrencyCode().empty());
    EXPECT_FALSE(JSONResponseFields::getReceiptReference().empty());
    EXPECT_FALSE(JSONResponseFields::getRRN().empty());
    EXPECT_FALSE(JSONResponseFields::getStatus().empty());
    EXPECT_FALSE(JSONResponseFields::getOriginalOperationStatus().empty());
    EXPECT_FALSE(JSONResponseFields::getTransDateTime().empty());
    EXPECT_FALSE(JSONResponseFields::getTerminalDateTime().empty());
    EXPECT_FALSE(JSONResponseFields::getCardPAN().empty());
    EXPECT_FALSE(JSONResponseFields::getExpireDate().empty());
    EXPECT_FALSE(JSONResponseFields::getCardholderName().empty());
    EXPECT_FALSE(JSONResponseFields::getCardholderAuthMethod().empty());
    EXPECT_FALSE(JSONResponseFields::getAuthCode().empty());
    EXPECT_FALSE(JSONResponseFields::getResponseCode().empty());
    EXPECT_FALSE(JSONResponseFields::getResponseText().empty());
    EXPECT_FALSE(JSONResponseFields::getSTAN().empty());
    EXPECT_FALSE(JSONResponseFields::getTransactionID().empty());
    EXPECT_FALSE(JSONResponseFields::getTerminalID().empty());
    EXPECT_FALSE(JSONResponseFields::getCfgTerminalId().empty());
    EXPECT_FALSE(JSONResponseFields::getCardEmvAid().empty());
    EXPECT_FALSE(JSONResponseFields::getCardAppName().empty());
    EXPECT_FALSE(JSONResponseFields::getCardInputMethod().empty());
    EXPECT_FALSE(JSONResponseFields::getIssuerName().empty());
    EXPECT_FALSE(JSONResponseFields::getAdditionalInfo().empty());
    EXPECT_FALSE(JSONResponseFields::getCardData().empty());
    EXPECT_FALSE(JSONResponseFields::getCardDataEnc().empty());
    EXPECT_FALSE(JSONResponseFields::getMerchantID().empty());
    EXPECT_FALSE(JSONResponseFields::getTVR().empty());
    EXPECT_FALSE(JSONResponseFields::getTSI().empty());
    EXPECT_FALSE(JSONResponseFields::getTC().empty());
    EXPECT_FALSE(JSONResponseFields::getCID().empty());
    EXPECT_FALSE(JSONResponseFields::getKVR().empty());
    EXPECT_FALSE(JSONResponseFields::getCDAResult().empty());
    EXPECT_FALSE(JSONResponseFields::getSaleCount().empty());
    EXPECT_FALSE(JSONResponseFields::getVoidCount().empty());
    EXPECT_FALSE(JSONResponseFields::getRefundCount().empty());
    EXPECT_FALSE(JSONResponseFields::getSaleArray().empty());
    EXPECT_FALSE(JSONResponseFields::getVoidArray().empty());
    EXPECT_FALSE(JSONResponseFields::getRefundArray().empty());
    EXPECT_FALSE(JSONResponseFields::getSalesAmount().empty());
    EXPECT_FALSE(JSONResponseFields::getVoidAmount().empty());
    EXPECT_FALSE(JSONResponseFields::getRefundAmount().empty());
    EXPECT_FALSE(JSONResponseFields::getCardPanHash().empty());
    EXPECT_FALSE(JSONResponseFields::getReceiptLine1().empty());
    EXPECT_FALSE(JSONResponseFields::getReceiptLine2().empty());
    EXPECT_FALSE(JSONResponseFields::getReceiptLine3().empty());
    EXPECT_FALSE(JSONResponseFields::getReceiptLine4().empty());
    EXPECT_FALSE(JSONResponseFields::getReceiptLine5().empty());
    EXPECT_FALSE(JSONResponseFields::getStatus().empty());
}

TEST(TestJSONFields, CheckCommunicationFields) {
    EXPECT_FALSE(JSONCommunicationFields::getCommand().empty());
    EXPECT_FALSE(JSONCommunicationFields::getLink().empty());
    EXPECT_FALSE(JSONCommunicationFields::getData().empty());
    EXPECT_FALSE(JSONCommunicationFields::getIp().empty());
    EXPECT_FALSE(JSONCommunicationFields::getPort().empty());
}

TEST(TestJSONFields, CheckNotificationFields) {
    EXPECT_FALSE(JSONNotificationFields::getCode().empty());
    EXPECT_FALSE(JSONNotificationFields::getMessage().empty());
    EXPECT_FALSE(JSONNotificationFields::getAdditional().empty());

}

TEST(TestJSONFields, CheckInteractionFields) {
    EXPECT_FALSE(JSONInteractionFields::getCode().empty());

}