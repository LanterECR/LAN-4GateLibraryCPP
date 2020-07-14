//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "gtest/gtest.h"

#include "Lanter/Message/Notification/NotificationData.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Notification;

TEST(NotificationData, CheckNotiticationData) {
    NotificationData data;
    auto lessMinimum = (NotificationCodes)((int)NotificationCodes::FirstValue - 1);
    auto greatMaximum = (NotificationCodes)((int)NotificationCodes::LastValue + 1);
    EXPECT_FALSE(data.setCode(lessMinimum));
    EXPECT_FALSE(data.setCode(greatMaximum));

    EXPECT_EQ(data.getCode(), NotificationCodes::NoNotification);

    EXPECT_TRUE(data.setCode(NotificationCodes::FirstValue));
    EXPECT_EQ(data.getCode(), NotificationCodes::FirstValue);
    EXPECT_TRUE(data.setCode(NotificationCodes::LastValue));
    EXPECT_EQ(data.getCode(), NotificationCodes::LastValue);
}