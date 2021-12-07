#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Parser/JSONInteractionParser.h"

#include "Lanter/Message/Interaction/InteractionData.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Interaction;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Parser;

TEST(TestJSONInteractionParser, CheckGetCode) {
    InteractionData data;

    JSONInteractionParser parser;

    Json::Value object;

    EXPECT_FALSE(parser.getCode(object, data));

    object[JSONInteractionFields::getCode()] = (int)InteractionCode::LastValue + 1;

    EXPECT_FALSE(parser.getCode(object, data));

    object[JSONInteractionFields::getCode()] = (int)InteractionCode::FirstValue - 1;

    EXPECT_FALSE(parser.getCode(object, data));

    object[JSONInteractionFields::getCode()] = (int)InteractionCode::FirstValue;

    EXPECT_TRUE(parser.getCode(object, data));

    EXPECT_EQ(data.getCode(), InteractionCode::FirstValue);
}


TEST(TestJSONInteractionParser, CheckGetInteractionData) {
    std::shared_ptr<IInteractionData> data;

    JSONInteractionParser parser;

    Json::Value object;

    data = parser.parseData(object);
    EXPECT_EQ(data, nullptr);

    object[JSONInteractionFields::getCode()] = (int)InteractionCode::FirstValue;

    data = parser.parseData(object);
    EXPECT_NE(data, nullptr);

    EXPECT_EQ(data->getCode(), InteractionCode::FirstValue);
}