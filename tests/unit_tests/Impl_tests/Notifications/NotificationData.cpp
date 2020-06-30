//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "gtest/gtest.h"

#include "Lanter/Notifications/NotificationData.h"

using namespace Lanter;
using namespace Lanter::Notifications;

TEST(NotificationData, CheckNotiticationData) {
    NotificationData data;
    auto lessMinimum = (NotificationCodes)((int)NotificationCodes::FirstValue - 1);
    auto greatMaximum = (NotificationCodes)((int)NotificationCodes::LastValue + 1);
    EXPECT_THROW(data.setNotificationCode(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setNotificationCode(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(data.getNotificationCode() == NotificationCodes::NoNotification);

    EXPECT_NO_THROW(data.setNotificationCode(NotificationCodes::FirstValue));
    EXPECT_TRUE(data.getNotificationCode() == NotificationCodes::FirstValue);
    EXPECT_NO_THROW(data.setNotificationCode(NotificationCodes::LastValue));
    EXPECT_TRUE(data.getNotificationCode() == NotificationCodes::LastValue);
}