//
// Created by Владимир Лысенков on 13.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/MessageParser/JSONMessageTypeChecker.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;

TEST(JSONMessageTypeChecker, CheckEmpty) {
    Json::Value object;

    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Error);
}

TEST(JSONMessageTypeChecker, CheckRequest) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = JSONClassFieldValues::getRequestValue();
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Request);
}

TEST(JSONMessageTypeChecker, CheckResponse) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = JSONClassFieldValues::getResponseValue();
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Response);
}

TEST(JSONMessageTypeChecker, CheckNotification) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = JSONClassFieldValues::getNotificationValue();
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Notification);
}

TEST(JSONMessageTypeChecker, CheckCommunication) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = JSONClassFieldValues::getCommunicationValue();
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Communication);
}

TEST(JSONMessageTypeChecker, CheckUnknown) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = "Unknown";
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Unknown);
}
