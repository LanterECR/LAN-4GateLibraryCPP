//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "gtest/gtest.h"
#include "Lanter/Message/Notifications/NotificationDataFactory.h"

#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Notification;
using namespace Lanter::Utils::Constants;

TEST(NotificationDataFactory, CheckFactory) {
    EXPECT_TRUE(NotificationDataFactory::getNotificationData() != nullptr);
}
