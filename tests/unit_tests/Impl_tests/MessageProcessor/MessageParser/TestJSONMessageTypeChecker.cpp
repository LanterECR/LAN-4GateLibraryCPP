#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Parser/JSONMessageTypeChecker.h"

#include "Lanter/MessageProcessor/JSONFields/JSONRootFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONClassFieldsValues.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Parser;

TEST(TestJSONMessageTypeChecker, CheckEmpty) {
    Json::Value object;

    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Error);
}

TEST(TestJSONMessageTypeChecker, CheckRequest) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = JSONClassFieldValues::getRequestValue();
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Request);
}

TEST(TestJSONMessageTypeChecker, CheckResponse) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = JSONClassFieldValues::getResponseValue();
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Response);
}

TEST(TestJSONMessageTypeChecker, CheckNotification) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = JSONClassFieldValues::getNotificationValue();
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Notification);
}

TEST(TestJSONMessageTypeChecker, CheckInteraction) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = JSONClassFieldValues::getInteractionValue();
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Interaction);
}

TEST(TestJSONMessageTypeChecker, CheckCommunication) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = JSONClassFieldValues::getCommunicationValue();
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Communication);
}

TEST(TestJSONMessageTypeChecker, CheckUnknown) {
    Json::Value object;

    object[JSONRootFields::getClassField()] = "Unknown";
    EXPECT_EQ(JSONMessageTypeChecker::checkType(object), MessageType::Unknown);
}
