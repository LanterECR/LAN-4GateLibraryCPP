#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Parser/JSONRootFieldsChecker.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Parser;

TEST(TestJSONRootFieldsChecker, CheckEmpty) {
    Json::Value root;

    EXPECT_FALSE(JSONRootFieldsChecker::checkFields(root));
}

TEST(TestJSONRootFieldsChecker, CheckClass) {
    Json::Value root;

    root[JSONRootFields::getClassField()] = JSONClassFieldValues::getRequestValue();
    EXPECT_FALSE(JSONRootFieldsChecker::checkFields(root));
}

TEST(TestJSONRootFieldsChecker, CheckObject) {
    Json::Value root;

    Json::Value object;
    object[JSONRequestFields::getOperationCode()] = 1;

    root[JSONRootFields::getObjectField()] = object;

    EXPECT_FALSE(JSONRootFieldsChecker::checkFields(root));
}

TEST(TestJSONRootFieldsChecker, CheckFullClassIncorrect) {
    Json::Value root;

    Json::Value object;
    object[JSONRequestFields::getOperationCode()] = 1;

    root[JSONRootFields::getClassField()] = 1;
    root[JSONRootFields::getObjectField()] = object;

    EXPECT_FALSE(JSONRootFieldsChecker::checkFields(root));
}

TEST(TestJSONRootFieldsChecker, CheckFullObjectIncorrect) {
    Json::Value root;

    root[JSONRootFields::getClassField()] = JSONClassFieldValues::getRequestValue();
    root[JSONRootFields::getObjectField()] = 1;

    EXPECT_FALSE(JSONRootFieldsChecker::checkFields(root));
}

TEST(TestJSONRootFieldsChecker, CheckFull) {
    Json::Value root;

    Json::Value object;
    object[JSONRequestFields::getOperationCode()] = 1;

    root[JSONRootFields::getClassField()] = JSONClassFieldValues::getRequestValue();
    root[JSONRootFields::getObjectField()] = object;

    EXPECT_TRUE(JSONRootFieldsChecker::checkFields(root));
}