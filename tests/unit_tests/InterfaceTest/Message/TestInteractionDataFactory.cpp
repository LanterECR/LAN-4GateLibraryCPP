#include "gtest/gtest.h"
#include "Lanter/Message/Interaction/InteractionDataFactory.h"

#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Interaction;
using namespace Lanter::Utils::Constants;

TEST(TestInteractionDataFactory, CheckFactory) {
    auto lessFirstOperation = (InteractionCode)((int)getFirstInteractionCode() - 1);

    auto greatLastOperation = (InteractionCode)((int)getLastInteractionCode() + 1);

    auto lessNotification = InteractionDataFactory::getInteractionData(lessFirstOperation);
    auto greatNotification = InteractionDataFactory::getInteractionData(greatLastOperation);

    auto firstNotification = InteractionDataFactory::getInteractionData(getFirstInteractionCode());
    auto lastNotification = InteractionDataFactory::getInteractionData(getLastInteractionCode());

    EXPECT_NE(InteractionDataFactory::getInteractionData(), nullptr);


    ASSERT_NE(lessNotification, nullptr);
    EXPECT_EQ(lessNotification->getCode(), InteractionCode::NoInteraction);

    ASSERT_NE(greatNotification, nullptr);
    EXPECT_EQ(greatNotification->getCode(), InteractionCode::NoInteraction);


    ASSERT_NE(firstNotification, nullptr);
    EXPECT_EQ(firstNotification->getCode(), getFirstInteractionCode());

    ASSERT_NE(lastNotification, nullptr);
    EXPECT_EQ(lastNotification->getCode(), getLastInteractionCode());

}
