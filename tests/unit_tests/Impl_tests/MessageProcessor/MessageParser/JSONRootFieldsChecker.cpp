//
// Created by Владимир Лысенков on 13.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/MessageParser/JSONRootFieldsChecker.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;

TEST(JSONRootFieldsChecker, CheckEmpty) {
    Json::Value root;

    EXPECT_FALSE(JSONRootFieldsChecker::checkFields(root));
}

TEST(JSONRootFieldsChecker, CheckClass) {
    Json::Value root;

    root[JSONRootFields::getClassField()] = JSONClassFieldValues::getRequestValue();
    EXPECT_FALSE(JSONRootFieldsChecker::checkFields(root));
}

TEST(JSONRootFieldsChecker, CheckObject) {
    Json::Value root;

    Json::Value object;
    object[JSONRequestFields::getOperationCode()] = 1;

    root[JSONRootFields::getObjectField()] = object;

    EXPECT_FALSE(JSONRootFieldsChecker::checkFields(root));
}

TEST(JSONRootFieldsChecker, CheckFullClassIncorrect) {
    Json::Value root;

    Json::Value object;
    object[JSONRequestFields::getOperationCode()] = 1;

    root[JSONRootFields::getClassField()] = 1;
    root[JSONRootFields::getObjectField()] = object;

    EXPECT_FALSE(JSONRootFieldsChecker::checkFields(root));
}

TEST(JSONRootFieldsChecker, CheckFullObjectIncorrect) {
    Json::Value root;

    root[JSONRootFields::getClassField()] = JSONClassFieldValues::getRequestValue();
    root[JSONRootFields::getObjectField()] = 1;

    EXPECT_FALSE(JSONRootFieldsChecker::checkFields(root));
}

TEST(JSONRootFieldsChecker, CheckFull) {
    Json::Value root;

    Json::Value object;
    object[JSONRequestFields::getOperationCode()] = 1;

    root[JSONRootFields::getClassField()] = JSONClassFieldValues::getRequestValue();
    root[JSONRootFields::getObjectField()] = object;

    EXPECT_TRUE(JSONRootFieldsChecker::checkFields(root));
}