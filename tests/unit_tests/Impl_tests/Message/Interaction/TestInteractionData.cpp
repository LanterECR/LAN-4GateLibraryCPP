#include "gtest/gtest.h"

#include "Lanter/Message/Interaction/InteractionData.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Interaction;

TEST(TestInteractionData, CheckNotiticationData) {
    InteractionData data;
    auto lessMinimum = (InteractionCode)((int)InteractionCode::FirstValue - 1);
    auto greatMaximum = (InteractionCode)((int)InteractionCode::LastValue + 1);
    EXPECT_FALSE(data.setCode(lessMinimum));
    EXPECT_FALSE(data.setCode(greatMaximum));

    EXPECT_EQ(data.getCode(), InteractionCode::NoInteraction);

    EXPECT_TRUE(data.setCode(InteractionCode::FirstValue));
    EXPECT_EQ(data.getCode(), InteractionCode::FirstValue);
    EXPECT_TRUE(data.setCode(InteractionCode::LastValue));
    EXPECT_EQ(data.getCode(), InteractionCode::LastValue);
}

TEST(TestInteractionData, CheckUnsetCode) {
    InteractionData data;
    EXPECT_EQ((int)data.getCode(), (int)InteractionCode::NoInteraction);

    EXPECT_TRUE(data.setCode(Lanter::Message::Interaction::InteractionCode::FirstValue));
    EXPECT_EQ((int)data.getCode(), (int)InteractionCode::FirstValue);

    EXPECT_TRUE(data.resetCode());
    EXPECT_EQ((int)data.getCode(), (int)InteractionCode::NoInteraction);
}
