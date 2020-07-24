#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"
#include "Lanter/MessageProcessor/JSONMessageFields.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;

TEST(JSONFIeldExists, CheckFieldNotExists) {
    Json::Value object;
    EXPECT_FALSE(fieldExists(object, JSONRootFields::getClassField()));
}

TEST(JSONFIeldExists, CheckFieldExists) {
    Json::Value object;
    object[JSONRootFields::getClassField()] = JSONRootFields::getClassField();
    EXPECT_TRUE(fieldExists(object, JSONRootFields::getClassField()));
}

TEST(JSONFIeldExists, CheckFieldNotExistsNotEmpty) {
    Json::Value object;
    object[JSONRootFields::getClassField()] = JSONRootFields::getClassField();
    EXPECT_FALSE(fieldExists(object, JSONRootFields::getObjectField()));
}

TEST(JSONFIeldExists, CheckEmptyName) {
    Json::Value object;
    object[JSONRootFields::getClassField()] = JSONRootFields::getClassField();
    std::string empty;
    EXPECT_FALSE(fieldExists(object, empty));
}