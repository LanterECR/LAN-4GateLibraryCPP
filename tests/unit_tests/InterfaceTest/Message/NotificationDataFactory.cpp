#include "gtest/gtest.h"
#include "Lanter/Message/Notification/NotificationDataFactory.h"

#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Notification;
using namespace Lanter::Utils::Constants;

TEST(NotificationDataFactory, CheckFactory) {
    auto lessFirstOperation = (NotificationCode)((int)NotificationCode::FirstValue - 1);

    auto greatLastOperation = (NotificationCode)((int)NotificationCode::LastValue + 1);

    auto lessNotification = NotificationDataFactory::getNotificationData(lessFirstOperation);
    auto greatNotification = NotificationDataFactory::getNotificationData(greatLastOperation);

    auto firstNotification = NotificationDataFactory::getNotificationData(NotificationCode::FirstValue);
    auto lastNotification = NotificationDataFactory::getNotificationData(NotificationCode::LastValue);

    EXPECT_NE(NotificationDataFactory::getNotificationData(), nullptr);


    ASSERT_NE(lessNotification, nullptr);
    EXPECT_EQ(lessNotification->getCode(), NotificationCode::NoNotification);

    ASSERT_NE(greatNotification, nullptr);
    EXPECT_EQ(greatNotification->getCode(), NotificationCode::NoNotification);


    ASSERT_NE(firstNotification, nullptr);
    EXPECT_EQ(firstNotification->getCode(), NotificationCode::FirstValue);

    ASSERT_NE(lastNotification, nullptr);
    EXPECT_EQ(lastNotification->getCode(), NotificationCode::LastValue);

}
