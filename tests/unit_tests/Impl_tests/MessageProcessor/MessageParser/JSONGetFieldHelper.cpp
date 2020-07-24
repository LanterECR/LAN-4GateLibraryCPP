#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Parser/JSONGetFieldHelper.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;
using namespace Lanter::MessageProcessor::Parser;

TEST(JSONGetFieldHelper, CheckGetInt) {
    Json::Value object;

    std::string fieldName = "field";
    int fieldValue = 0x7FFFFFFF;
    int getField;
    EXPECT_FALSE(JSONGetFieldHelper::getField(object, fieldName, getField));

    object[fieldName] = fieldValue;

    EXPECT_TRUE(JSONGetFieldHelper::getField(object, fieldName, getField));
    EXPECT_EQ(fieldValue, getField);
}

TEST(JSONGetFieldHelper, CheckGetInt64) {
    Json::Value object;

    std::string fieldName = "field";
    int64_t fieldValue = 0x7FFFFFFFFFFFFFFF;
    int64_t getField;
    EXPECT_FALSE(JSONGetFieldHelper::getField(object, fieldName, getField));

    object[fieldName] = fieldValue;

    EXPECT_TRUE(JSONGetFieldHelper::getField(object, fieldName, getField));
    EXPECT_EQ(fieldValue, getField);
}

TEST(JSONGetFieldHelper, CheckGetString) {
    Json::Value object;

    std::string fieldName = "field";
    std::string fieldValue = "value";
    std::string getField;

    EXPECT_FALSE(JSONGetFieldHelper::getField(object, fieldName, getField));

    object[fieldName] = fieldValue;

    EXPECT_TRUE(JSONGetFieldHelper::getField(object, fieldName, getField));
    EXPECT_STREQ(fieldValue.c_str(), getField.c_str());
}