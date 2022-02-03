#include "gtest/gtest.h"
#include "Lanter/Message/Notification/NotificationDataFactory.h"

#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Notification;
using namespace Lanter::Utils::Constants;

TEST(TestNotificationDataFactory, CheckFactory) {
    auto lessFirstOperation = (NotificationCode)((int)getFirstNotificationCode() - 1);

    auto greatLastOperation = (NotificationCode)((int)getLastNotificationCode() + 1);

    auto lessNotification = NotificationDataFactory::getNotificationData(lessFirstOperation);
    auto greatNotification = NotificationDataFactory::getNotificationData(greatLastOperation);

    auto firstNotification = NotificationDataFactory::getNotificationData(getFirstNotificationCode());
    auto lastNotification = NotificationDataFactory::getNotificationData(getLastNotificationCode());

    EXPECT_NE(NotificationDataFactory::getNotificationData(), nullptr);


    ASSERT_NE(lessNotification, nullptr);
    EXPECT_EQ(lessNotification->getCode(), NotificationCode::NoNotification);

    ASSERT_NE(greatNotification, nullptr);
    EXPECT_EQ(greatNotification->getCode(), NotificationCode::NoNotification);


    ASSERT_NE(firstNotification, nullptr);
    EXPECT_EQ(firstNotification->getCode(), getFirstNotificationCode());

    ASSERT_NE(lastNotification, nullptr);
    EXPECT_EQ(lastNotification->getCode(), getLastNotificationCode());

}
