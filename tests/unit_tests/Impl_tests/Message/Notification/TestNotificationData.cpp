#include "gtest/gtest.h"

#include "Lanter/Message/Notification/NotificationData.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Notification;

TEST(TestNotificationData, CheckNotiticationData) {
    NotificationData data;
    auto lessMinimum = (NotificationCode)((int)NotificationCode::FirstValue - 1);
    auto greatMaximum = (NotificationCode)((int)NotificationCode::LastValue + 1);
    EXPECT_FALSE(data.setCode(lessMinimum));
    EXPECT_FALSE(data.setCode(greatMaximum));

    EXPECT_EQ(data.getCode(), NotificationCode::NoNotification);

    EXPECT_TRUE(data.setCode(NotificationCode::FirstValue));
    EXPECT_EQ(data.getCode(), NotificationCode::FirstValue);
    EXPECT_TRUE(data.setCode(NotificationCode::LastValue));
    EXPECT_EQ(data.getCode(), NotificationCode::LastValue);
}

TEST(TestNotificationData, CheckUnsetCode) {
    NotificationData data;
    EXPECT_EQ((int)data.getCode(), (int)NotificationCode::NoNotification);

    EXPECT_TRUE(data.setCode(Lanter::Message::Notification::NotificationCode::FirstValue));
    EXPECT_EQ((int)data.getCode(), (int)NotificationCode::FirstValue);

    EXPECT_TRUE(data.resetCode());
    EXPECT_EQ((int)data.getCode(), (int)NotificationCode::NoNotification);
}

TEST(TestNotificationData, CheckUnsetMessage) {
    NotificationData data;
    std::string message = "Сообщение";

    EXPECT_TRUE(data.getMessage().empty());

    EXPECT_TRUE(data.setMessage(message));
    EXPECT_STREQ(data.getMessage().c_str(), message.c_str());

    EXPECT_TRUE(data.resetMessage());
    EXPECT_TRUE(data.getMessage().empty());
}

TEST(TestNotificationData, CheckUnsetAdditional) {
    NotificationData data;
    std::string additional = "Дополнительно";

    EXPECT_TRUE(data.getAdditional().empty());

    EXPECT_TRUE(data.setAdditional(additional));
    EXPECT_STREQ(data.getAdditional().c_str(), additional.c_str());

    EXPECT_TRUE(data.resetAdditional());
    EXPECT_TRUE(data.getAdditional().empty());
}