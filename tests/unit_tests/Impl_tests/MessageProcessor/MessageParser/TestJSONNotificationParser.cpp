#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Parser/JSONNotificationParser.h"

#include "Lanter/Message/Notification/NotificationData.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Notification;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Parser;

TEST(TestJSONNotificationParser, CheckGetCode) {
    NotificationData data;

    JSONNotificationParser parser;

    Json::Value object;

    EXPECT_FALSE(parser.getCode(object, data));

    object[JSONNotificationFields::getCode()] = (int)getLastNotificationCode() + 1;

    EXPECT_FALSE(parser.getCode(object, data));

    object[JSONNotificationFields::getCode()] = (int)getFirstNotificationCode() - 1;

    EXPECT_FALSE(parser.getCode(object, data));

    object[JSONNotificationFields::getCode()] = (int)getFirstNotificationCode();

    EXPECT_TRUE(parser.getCode(object, data));

    EXPECT_EQ(data.getCode(), getFirstNotificationCode());
}

TEST(TestJSONNotificationParser, CheckGetMessage) {
    NotificationData data;

    JSONNotificationParser parser;

    Json::Value object;

    std::string value = "Значение";

    EXPECT_FALSE(parser.getMessage(object, data));

    object[JSONNotificationFields::getMessage()] = value;

    EXPECT_TRUE(parser.getMessage(object, data));

    EXPECT_STREQ(data.getMessage().c_str(), value.c_str());

}

TEST(TestJSONNotificationParser, CheckGetAdditional) {
    NotificationData data;

    JSONNotificationParser parser;

    Json::Value object;

    std::string value = "Значение";

    EXPECT_FALSE(parser.getAdditional(object, data));

    object[JSONNotificationFields::getAdditional()] = value;

    EXPECT_TRUE(parser.getAdditional(object, data));

    EXPECT_STREQ(data.getAdditional().c_str(), value.c_str());

}

TEST(TestJSONNotificationParser, CheckGetNotificationData) {
    std::shared_ptr<INotificationData> data;

    JSONNotificationParser parser;

    Json::Value object;

    data = parser.parseData(object);
    EXPECT_EQ(data, nullptr);

    std::string value = "Значение";

    object[JSONNotificationFields::getCode()] = (int)getFirstNotificationCode();
    object[JSONNotificationFields::getMessage()] = value;
    object[JSONNotificationFields::getAdditional()] = value;

    data = parser.parseData(object);
    EXPECT_NE(data, nullptr);

    EXPECT_EQ(data->getCode(), getFirstNotificationCode());
    EXPECT_STREQ(data->getMessage().c_str(), value.c_str());
    EXPECT_STREQ(data->getAdditional().c_str(), value.c_str());
}