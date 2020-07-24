#include "gtest/gtest.h"

#include "Lanter/Message/Notification/NotificationDataFactory.h"

#include "Lanter/MessageProcessor/Builder/JSONNotificationBuilder.h"

#include "Lanter/Message/Notification/NotificationData.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"

using namespace Lanter;
using namespace Lanter::Notification;
using namespace Lanter::Message;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Builder;

TEST(JSONNOtificationBuilder, CheckAddCode) {
    NotificationData data;

    Json::Value object;

    EXPECT_FALSE(JSONNotificationBuilder::addCode(data, object));

    data.setCode(NotificationCode::FirstValue);

    EXPECT_TRUE(JSONNotificationBuilder::addCode(data, object));
    EXPECT_TRUE(fieldExists(object, JSONNotificationFields::getCode()));
    EXPECT_EQ((int) data.getCode(), object[JSONNotificationFields::getCode()].asInt());
}

TEST(JSONNOtificationBuilder, CheckAddAdditional) {
    NotificationData data;

    Json::Value object;

    EXPECT_FALSE(JSONNotificationBuilder::addAdditional(data, object));

    data.setAdditional("123");

    EXPECT_TRUE(JSONNotificationBuilder::addAdditional(data, object));
    EXPECT_TRUE(fieldExists(object, JSONNotificationFields::getAdditional()));
    EXPECT_STREQ(data.getAdditional().c_str(), object[JSONNotificationFields::getAdditional()].asString().c_str());
}

TEST(JSONNOtificationBuilder, CheckAddMessagel) {
    NotificationData data;

    Json::Value object;

    EXPECT_FALSE(JSONNotificationBuilder::addMessage(data, object));

    data.setMessage("123");

    EXPECT_TRUE(JSONNotificationBuilder::addMessage(data, object));
    EXPECT_TRUE(fieldExists(object, JSONNotificationFields::getMessage()));
    EXPECT_STREQ(data.getMessage().c_str(), object[JSONNotificationFields::getMessage()].asString().c_str());
}

TEST(JSONNOtificationBuilder, CheckCreateObject) {
    auto data = NotificationDataFactory::getNotificationData();
    Json::Value object;
    JSONNotificationBuilder builder;

    EXPECT_FALSE(builder.createObject(*data, object));

    data->setCode(NotificationCode::FirstValue);
    data->setAdditional("123");
    data->setMessage("123");

    EXPECT_TRUE(builder.createObject(*data, object));
    EXPECT_TRUE(fieldExists(object, JSONNotificationFields::getCode()));
    EXPECT_TRUE(fieldExists(object, JSONNotificationFields::getAdditional()));
    EXPECT_TRUE(fieldExists(object, JSONNotificationFields::getMessage()));

    EXPECT_EQ((int) data->getCode(), object[JSONNotificationFields::getCode()].asInt());
    EXPECT_STREQ(data->getAdditional().c_str(), object[JSONNotificationFields::getAdditional()].asString().c_str());
    EXPECT_STREQ(data->getMessage().c_str(), object[JSONNotificationFields::getMessage()].asString().c_str());
}