#include "gtest/gtest.h"

#include "Lanter/Message/Interaction/InteractionDataFactory.h"

#include "Lanter/MessageProcessor/Builder/JSONInteractionBuilder.h"

#include "Lanter/Message/Interaction/InteractionData.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"

using namespace Lanter;
using namespace Lanter::Interaction;
using namespace Lanter::Message;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Builder;

TEST(TestJSONInteractionBuilder, CheckAddCode) {
    InteractionData data;

    Json::Value object;

    EXPECT_FALSE(JSONInteractionBuilder::addCode(data, object));

    data.setCode(getFirstInteractionCode());

    EXPECT_TRUE(JSONInteractionBuilder::addCode(data, object));
    EXPECT_TRUE(fieldExists(object, JSONInteractionFields::getCode()));
    EXPECT_EQ((int) data.getCode(), object[JSONInteractionFields::getCode()].asInt());
}

TEST(TestJSONInteractionBuilder, CheckCreateObject) {
    auto data = InteractionDataFactory::getInteractionData();
    Json::Value object;
    JSONInteractionBuilder builder;

    EXPECT_FALSE(builder.createObject(*data, object));

    data->setCode(getFirstInteractionCode());

    EXPECT_TRUE(builder.createObject(*data, object));
    EXPECT_TRUE(fieldExists(object, JSONInteractionFields::getCode()));

    EXPECT_EQ((int) data->getCode(), object[JSONInteractionFields::getCode()].asInt());
}