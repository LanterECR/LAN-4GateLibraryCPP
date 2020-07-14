//
// Created by Владимир Лысенков on 13.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/MessageParser/JSONMessageParser.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/Utils/StringConverter.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;
using namespace Lanter::Utils;

TEST(JSONMessageParser, CheckReadMessage) {
    std::string junkValue = "JUNK";

    std::string jsonValue = "{\"field\":\"value\"}";

    Json::Value root;

    EXPECT_FALSE(JSONMessageParser::readMessage(junkValue, root));
    EXPECT_TRUE(JSONMessageParser::readMessage(jsonValue, root));

    EXPECT_NE(std::find(root.getMemberNames().begin(), root.getMemberNames().end(), "field"), root.getMemberNames().end());

    EXPECT_TRUE(root["field"].isString());

    EXPECT_STREQ(root["field"].asString().c_str(), "value");
}

TEST(JSONMessageParser, CheckNotification) {
    Json::Value root;

    std::vector<unsigned char> data = {'J', 'U', 'N', 'N', 'K'};
    JSONMessageParser parser;


    EXPECT_EQ(parser.parseMessage(data), MessageType::Error);


    root[JSONRootFields::getClassField()] = JSONClassFieldValues::getNotificationValue();

    std::string value = "Значение";

    Json::Value object;
    object[JSONNotificationFields::getCode()] = (int)NotificationCodes::FirstValue;
    object[JSONNotificationFields::getAdditional()] = value;
    object[JSONNotificationFields::getMessage()] = value;

    root[JSONRootFields::getObjectField()] = object;

    Json::FastWriter writer;

    StringConverter::convertToVector(writer.write(root), data);

    EXPECT_EQ(parser.parseMessage(data), MessageType::Notification);
    EXPECT_EQ(parser.notificationCount(), 1);

    EXPECT_EQ(parser.parseMessage(data), MessageType::Notification);
    EXPECT_EQ(parser.notificationCount(), 2);



    EXPECT_NE(parser.getNextNotificationData(), nullptr);
    EXPECT_EQ(parser.notificationCount(), 1);

    EXPECT_NE(parser.getNextNotificationData(), nullptr);
    EXPECT_EQ(parser.notificationCount(), 0);

    EXPECT_EQ(parser.getNextNotificationData(), nullptr);
    EXPECT_EQ(parser.notificationCount(), 0);
}