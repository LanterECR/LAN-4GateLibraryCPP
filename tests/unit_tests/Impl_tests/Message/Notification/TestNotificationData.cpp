#include "gtest/gtest.h"

#include "Lanter/Message/Notification/NotificationData.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Notification;

TEST(TestNotificationData, CheckNotiticationData) {
    NotificationData data;
    auto lessMinimum = (NotificationCode)((int)getFirstNotificationCode() - 1);
    auto greatMaximum = (NotificationCode)((int)getLastNotificationCode() + 1);
    EXPECT_FALSE(data.setCode(lessMinimum));
    EXPECT_FALSE(data.setCode(greatMaximum));

    EXPECT_EQ(data.getCode(), NotificationCode::NoNotification);

    EXPECT_TRUE(data.setCode(getFirstNotificationCode()));
    EXPECT_EQ(data.getCode(), getFirstNotificationCode());
    EXPECT_TRUE(data.setCode(getLastNotificationCode()));
    EXPECT_EQ(data.getCode(), getLastNotificationCode());
}

TEST(TestNotificationData, CheckUnsetCode) {
    NotificationData data;
    EXPECT_EQ((int)data.getCode(), (int)NotificationCode::NoNotification);

    EXPECT_TRUE(data.setCode(Lanter::Message::Notification::getFirstNotificationCode()));
    EXPECT_EQ((int)data.getCode(), (int)getFirstNotificationCode());

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