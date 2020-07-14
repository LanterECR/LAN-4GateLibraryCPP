//
// Created by Владимир Лысенков on 14.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/MessageParser/MessageParserFactory.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;

TEST(MessageParserFactory, TestFactory) {
    EXPECT_NE(MessageParserFactory::getMessageParser(), nullptr);
}