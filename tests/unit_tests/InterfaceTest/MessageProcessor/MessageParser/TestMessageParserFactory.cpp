#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Parser/MessageParserFactory.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Parser;

TEST(TestMessageParserFactory, TestFactory) {
    EXPECT_NE(MessageParserFactory::getMessageParser(), nullptr);
}