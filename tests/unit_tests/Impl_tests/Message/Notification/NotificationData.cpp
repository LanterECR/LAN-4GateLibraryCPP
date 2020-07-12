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
    EXPECT_THROW(data.setCode(lessMinimum), std::invalid_argument);
    EXPECT_THROW(data.setCode(greatMaximum), std::invalid_argument);

    EXPECT_TRUE(data.getCode() == NotificationCodes::NoNotification);

    EXPECT_NO_THROW(data.setCode(NotificationCodes::FirstValue));
    EXPECT_TRUE(data.getCode() == NotificationCodes::FirstValue);
    EXPECT_NO_THROW(data.setCode(NotificationCodes::LastValue));
    EXPECT_TRUE(data.getCode() == NotificationCodes::LastValue);
}