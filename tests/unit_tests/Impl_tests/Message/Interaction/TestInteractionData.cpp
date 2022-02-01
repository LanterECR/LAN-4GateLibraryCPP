#include "gtest/gtest.h"

#include "Lanter/Message/Interaction/InteractionData.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Interaction;

TEST(TestInteractionData, CheckNotiticationData) {
    InteractionData data;
    auto lessMinimum = (InteractionCode)((int)getFirstInteractionCode() - 1);
    auto greatMaximum = (InteractionCode)((int)getLastInteractionCode() + 1);
    EXPECT_FALSE(data.setCode(lessMinimum));
    EXPECT_FALSE(data.setCode(greatMaximum));

    EXPECT_EQ(data.getCode(), InteractionCode::NoInteraction);

    EXPECT_TRUE(data.setCode(getFirstInteractionCode()));
    EXPECT_EQ(data.getCode(), getFirstInteractionCode());
    EXPECT_TRUE(data.setCode(getLastInteractionCode()));
    EXPECT_EQ(data.getCode(), getLastInteractionCode());
}

TEST(TestInteractionData, CheckUnsetCode) {
    InteractionData data;
    EXPECT_EQ((int)data.getCode(), (int)InteractionCode::NoInteraction);

    EXPECT_TRUE(data.setCode(Lanter::Message::Interaction::getFirstInteractionCode()));
    EXPECT_EQ((int)data.getCode(), (int)getFirstInteractionCode());

    EXPECT_TRUE(data.resetCode());
    EXPECT_EQ((int)data.getCode(), (int)InteractionCode::NoInteraction);
}
