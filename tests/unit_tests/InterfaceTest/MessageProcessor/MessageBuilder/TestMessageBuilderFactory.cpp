#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Builder/MessageBuilderFactory.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Builder;

TEST(TestMessageBuilderFactory, TestFactory) {
    EXPECT_NE(MessageBuilderFactory::getMessageBuilder(), nullptr);
}