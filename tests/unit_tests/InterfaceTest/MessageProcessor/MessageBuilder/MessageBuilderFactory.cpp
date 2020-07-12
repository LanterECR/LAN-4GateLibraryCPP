//
// Created by Владимир Лысенков on 07.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/MessageBuilder/MessageBuilderFactory.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;

TEST(MessageBuilderFactory, TestFactory) {
    EXPECT_TRUE(MessageBuilderFactory::getMessageBuilder() != nullptr);
}