#include "gtest/gtest.h"

#include "Lanter/Message/Response/ResponseDataFactory.h"
#include "Lanter/Message/Request/RequestDataFactory.h"
#include "Lanter/Message/Notification/NotificationDataFactory.h"
#include "Lanter/MessageProcessor/Builder/MessageBuilderFactory.h"
#include "Lanter/MessageProcessor/Parser/MessageParserFactory.h"
#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Utils;
using namespace Lanter::Utils::Constants;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;
using namespace Lanter::Message::Response;
using namespace Lanter::Message::Notification;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Builder;
using namespace Lanter::MessageProcessor::Parser;

TEST(TestBuilderParser, CheckRequest) {
    auto inputObject = RequestDataFactory::getRequestData();
    inputObject->setOperationCode(Lanter::Message::OperationCode::Sale);
    inputObject->setAmount(MAXIMUM_AMOUNT);
    inputObject->setCurrencyCode(MAXIMUM_CURRENCY_CODE);
    inputObject->setEcrNumber(MAXIMUM_ECR_NUMBER);
    inputObject->setEcrMerchantNumber(MAXIMUM_ECR_MERCHANT_NUMBER);

    std::vector<uint8_t> serializedData;

    auto builder = MessageBuilderFactory::getMessageBuilder();
    auto parser = MessageParserFactory::getMessageParser();

    EXPECT_TRUE(builder->createMessage(inputObject, serializedData));
    EXPECT_FALSE(serializedData.empty());

    EXPECT_EQ(parser->parseMessage(serializedData), MessageType::Request);
    EXPECT_EQ(parser->requestCount(), 1);

    auto outputObject = parser->nextRequestData();
    EXPECT_NE(outputObject, nullptr);

    EXPECT_EQ((int)inputObject->getOperationCode(), (int)outputObject->getOperationCode());
    EXPECT_EQ(inputObject->getAmount(), outputObject->getAmount());
    EXPECT_EQ(inputObject->getCurrencyCode(), outputObject->getCurrencyCode());
    EXPECT_EQ(inputObject->getEcrNumber(), outputObject->getEcrNumber());
    EXPECT_EQ(inputObject->getEcrMerchantNumber(), outputObject->getEcrMerchantNumber());
}

TEST(TestBuilderParser, CheckResponse) {
    auto inputObject = ResponseDataFactory::getResponseData();
    inputObject->setOperationCode(Lanter::Message::OperationCode::Sale);
    inputObject->setEcrNumber(MAXIMUM_ECR_NUMBER);
    inputObject->setStatus(Lanter::Message::Response::Status::Success);
    inputObject->setEcrMerchantNumber(MAXIMUM_ECR_MERCHANT_NUMBER);
    inputObject->setTotalAmount(MAXIMUM_AMOUNT);
    inputObject->setCurrencyCode(MAXIMUM_CURRENCY_CODE);
    inputObject->setRRN("Значение");
    inputObject->setReceiptReference("Значение");
    inputObject->setTransactionID("Значение");
    inputObject->setAuthCode("Значение");
    inputObject->setResponseCode("Значение");
    inputObject->setResponseText("Значение");
    inputObject->setTerminalID("Значение");
    inputObject->setMerchantID("Значение");
    inputObject->setTransDateTime("Значение");
    inputObject->setTerminalDateTime("Значение");
    inputObject->setIssuerName("Значение");
    inputObject->setCardInputMethod(Lanter::Message::Response::CardInputMethod::TerminalManualEntry);
    inputObject->setCardPAN("Значение");
    inputObject->setExpireDate("Значение");
    inputObject->setCardAppName("Значение");
    inputObject->setCardEmvAid("Значение");
    inputObject->setCardDataEnc("Значение");
    inputObject->setTVR("Значение");
    inputObject->setTSI("Значение");
    inputObject->setTC("Значение");
    inputObject->setCID("Значение");
    inputObject->setKVR("Значение");
    inputObject->setCDAResult("Значение");
    inputObject->setCardholderName("Значение");
    inputObject->setCardholderAuthMethod(Lanter::Message::Response::CardholderAuthMethod::PaperSignatureVerification);

    std::vector<uint8_t> serializedData;

    auto builder = MessageBuilderFactory::getMessageBuilder();
    auto parser = MessageParserFactory::getMessageParser();

    EXPECT_TRUE(builder->createMessage(inputObject, serializedData));
    EXPECT_FALSE(serializedData.empty());

    EXPECT_EQ(parser->parseMessage(serializedData), MessageType::Response);
    EXPECT_EQ(parser->responseCount(), 1);

    auto outputObject = parser->nextResponseData();
    EXPECT_NE(outputObject, nullptr);

    EXPECT_EQ(inputObject->getEcrNumber(), outputObject->getEcrNumber());
    EXPECT_EQ(inputObject->getOperationCode(), outputObject->getOperationCode());
    EXPECT_EQ(inputObject->getStatus(), outputObject->getStatus());
    EXPECT_EQ(inputObject->getEcrMerchantNumber(), outputObject->getEcrMerchantNumber());
    EXPECT_EQ(inputObject->getTotalAmount(), outputObject->getTotalAmount());
    EXPECT_EQ(inputObject->getCurrencyCode(), outputObject->getCurrencyCode());
    EXPECT_STREQ(inputObject->getRRN().c_str(), outputObject->getRRN().c_str());
    EXPECT_STREQ(inputObject->getReceiptReference().c_str(), outputObject->getReceiptReference().c_str());
    EXPECT_STREQ(inputObject->getTransactionID().c_str(), outputObject->getTransactionID().c_str());
    EXPECT_STREQ(inputObject->getAuthCode().c_str(), outputObject->getAuthCode().c_str());
    EXPECT_STREQ(inputObject->getResponseCode().c_str(), outputObject->getResponseCode().c_str());
    EXPECT_STREQ(inputObject->getResponseText().c_str(), outputObject->getResponseText().c_str());
    EXPECT_STREQ(inputObject->getTerminalID().c_str(), outputObject->getTerminalID().c_str());
    EXPECT_STREQ(inputObject->getMerchantID().c_str(), outputObject->getMerchantID().c_str());
    EXPECT_STREQ(inputObject->getTransDateTime().c_str(), outputObject->getTransDateTime().c_str());
    EXPECT_STREQ(inputObject->getTerminalDateTime().c_str(), outputObject->getTerminalDateTime().c_str());
    EXPECT_STREQ(inputObject->getIssuerName().c_str(), outputObject->getIssuerName().c_str());
    EXPECT_EQ(inputObject->getCardInputMethod(), outputObject->getCardInputMethod());
    EXPECT_STREQ(inputObject->getCardPAN().c_str(), outputObject->getCardPAN().c_str());
    EXPECT_STREQ(inputObject->getExpireDate().c_str(), outputObject->getExpireDate().c_str());
    EXPECT_STREQ(inputObject->getCardAppName().c_str(), outputObject->getCardAppName().c_str());
    EXPECT_STREQ(inputObject->getCardEmvAid().c_str(), outputObject->getCardEmvAid().c_str());
    EXPECT_STREQ(inputObject->getCardDataEnc().c_str(), outputObject->getCardDataEnc().c_str());
    EXPECT_STREQ(inputObject->getTVR().c_str(), outputObject->getTVR().c_str());
    EXPECT_STREQ(inputObject->getTSI().c_str(), outputObject->getTSI().c_str());
    EXPECT_STREQ(inputObject->getTC().c_str(), outputObject->getTC().c_str());
    EXPECT_STREQ(inputObject->getCID().c_str(), outputObject->getCID().c_str());
    EXPECT_STREQ(inputObject->getKVR().c_str(), outputObject->getKVR().c_str());
    EXPECT_STREQ(inputObject->getCDAResult().c_str(), outputObject->getCDAResult().c_str());
    EXPECT_STREQ(inputObject->getCardholderName().c_str(), outputObject->getCardholderName().c_str());
    EXPECT_EQ(inputObject->getCardholderAuthMethod(), outputObject->getCardholderAuthMethod());
}
TEST(TestBuilderParser, CheckNotification) {
    auto inputObject = NotificationDataFactory::getNotificationData();
    inputObject->setCode(Lanter::Message::Notification::NotificationCode::FirstValue);
    inputObject->setMessage("Сообщение");
    inputObject->setAdditional("Дополнительно");

    std::vector<uint8_t> serializedData;

    auto builder = MessageBuilderFactory::getMessageBuilder();
    auto parser = MessageParserFactory::getMessageParser();

    EXPECT_TRUE(builder->createMessage(inputObject, serializedData));
    EXPECT_FALSE(serializedData.empty());

    EXPECT_EQ(parser->parseMessage(serializedData), MessageType::Notification);
    EXPECT_EQ(parser->notificationCount(), 1);

    auto outputObject = parser->nextNotificationData();
    EXPECT_NE(outputObject, nullptr);

    EXPECT_EQ((int)outputObject->getCode(), (int)inputObject->getCode());
    EXPECT_STREQ(outputObject->getMessage().c_str(), inputObject->getMessage().c_str());
    EXPECT_STREQ(outputObject->getAdditional().c_str(), inputObject->getAdditional().c_str());
}