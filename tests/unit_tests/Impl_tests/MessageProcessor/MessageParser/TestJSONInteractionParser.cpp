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

    object[JSONInteractionFields::getCode()] = (int)getLastInteractionCode() + 1;

    EXPECT_FALSE(parser.getCode(object, data));

    object[JSONInteractionFields::getCode()] = (int)getFirstInteractionCode() - 1;

    EXPECT_FALSE(parser.getCode(object, data));

    object[JSONInteractionFields::getCode()] = (int)getFirstInteractionCode();

    EXPECT_TRUE(parser.getCode(object, data));

    EXPECT_EQ(data.getCode(), getFirstInteractionCode());
}


TEST(TestJSONInteractionParser, CheckGetInteractionData) {
    std::shared_ptr<IInteractionData> data;

    JSONInteractionParser parser;

    Json::Value object;

    data = parser.parseData(object);
    EXPECT_EQ(data, nullptr);

    object[JSONInteractionFields::getCode()] = (int)getFirstInteractionCode();

    data = parser.parseData(object);
    EXPECT_NE(data, nullptr);

    EXPECT_EQ(data->getCode(), getFirstInteractionCode());
}