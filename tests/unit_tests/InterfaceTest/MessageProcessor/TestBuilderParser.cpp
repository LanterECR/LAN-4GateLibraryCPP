//
// Created by Владимир Лысенков on 14.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/Message/Request/RequestDataFactory.h"
#include "Lanter/Message/Notification/NotificationDataFactory.h"
#include "Lanter/MessageProcessor/MessageBuilder/MessageBuilderFactory.h"
#include "Lanter/MessageProcessor/MessageParser/MessageParserFactory.h"
#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Utils;
using namespace Lanter::Utils::Constants;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;
using namespace Lanter::Message::Notification;
using namespace Lanter::MessageProcessor;

TEST(TestBuilderParser, CheckRequest) {
    auto inputObject = RequestDataFactory::getRequestData();
    inputObject->setOperationCode(Lanter::Message::OperationCodes::Sale);
    inputObject->setAmount(MAXIMUM_AMOUNT);
    inputObject->setCurrencyCode(MAXIMUM_CURRENCY_CODE);
    inputObject->setEcrNumber(MAXIMUM_ECR_NUMBER);
    inputObject->setEcrMerchantNumber(MAXIMUM_ECR_MERCHANT_NUMBER);

    std::vector<unsigned char> serializedData;

    auto builder = MessageBuilderFactory::getMessageBuilder();
    auto parser = MessageParserFactory::getMessageParser();

    EXPECT_TRUE(builder->createMessage(inputObject, serializedData));
    EXPECT_FALSE(serializedData.empty());

    EXPECT_EQ(parser->parseMessage(serializedData), MessageType::Request);
    EXPECT_EQ(parser->requestCount(), 1);

    auto outputObject = parser->getNextRequestData();
    EXPECT_NE(outputObject, nullptr);

    EXPECT_EQ((int)inputObject->getOperationCode(), (int)outputObject->getOperationCode());
    EXPECT_EQ(inputObject->getAmount(), outputObject->getAmount());
    EXPECT_EQ(inputObject->getCurrencyCode(), outputObject->getCurrencyCode());
    EXPECT_EQ(inputObject->getEcrNumber(), outputObject->getEcrNumber());
    EXPECT_EQ(inputObject->getEcrMerchantNumber(), outputObject->getEcrMerchantNumber());
}

TEST(TestBuilderParser, CheckNotification) {
    auto inputObject = NotificationDataFactory::getNotificationData();
    inputObject->setCode(Lanter::Message::Notification::NotificationCodes::FirstValue);
    inputObject->setMessage("Сообщение");
    inputObject->setAdditional("Дополнительно");

    std::vector<unsigned char> serializedData;

    auto builder = MessageBuilderFactory::getMessageBuilder();
    auto parser = MessageParserFactory::getMessageParser();

    EXPECT_TRUE(builder->createMessage(inputObject, serializedData));
    EXPECT_FALSE(serializedData.empty());

    EXPECT_EQ(parser->parseMessage(serializedData), MessageType::Notification);
    EXPECT_EQ(parser->notificationCount(), 1);

    auto outputObject = parser->getNextNotificationData();
    EXPECT_NE(outputObject, nullptr);

    EXPECT_EQ((int)outputObject->getCode(), (int)inputObject->getCode());
    EXPECT_STREQ(outputObject->getMessage().c_str(), inputObject->getMessage().c_str());
    EXPECT_STREQ(outputObject->getAdditional().c_str(), inputObject->getAdditional().c_str());
}