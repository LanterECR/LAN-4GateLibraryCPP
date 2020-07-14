//
// Created by Владимир Лысенков on 14.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/Message/Notification/NotificationDataFactory.h"
#include "Lanter/MessageProcessor/MessageBuilder/MessageBuilderFactory.h"
#include "Lanter/MessageProcessor/MessageParser/MessageParserFactory.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Notification;
using namespace Lanter::MessageProcessor;

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

}