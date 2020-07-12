//
// Created by Владимир Лысенков on 09.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/MessageBuilder/JSONAddFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFieldExists.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;

TEST(JSONAddFieldHelper, CheckNumberField) {
    Json::Value object;

    //8bit
    std::string value8bit_name = "value8bit";
    int8_t value8bit = 0;
    EXPECT_TRUE(AddFieldsHelper::addField(object, value8bit_name, value8bit));
    EXPECT_TRUE(fieldExists(object, value8bit_name));
    EXPECT_TRUE(object[value8bit_name].asInt() == value8bit);

    value8bit = 0xFF;//min

    EXPECT_TRUE(AddFieldsHelper::addField(object, value8bit_name, value8bit));
    EXPECT_TRUE(fieldExists(object, value8bit_name));
    EXPECT_TRUE(object[value8bit_name].asInt() == value8bit);

    value8bit = 0x7F;//max

    EXPECT_TRUE(AddFieldsHelper::addField(object, value8bit_name, value8bit));
    EXPECT_TRUE(fieldExists(object, value8bit_name));
    EXPECT_TRUE(object[value8bit_name].asInt() == value8bit);

    //16bit
    std::string value16bit_name = "value16bit";
    int16_t value16bit = 0;
    EXPECT_TRUE(AddFieldsHelper::addField(object, value16bit_name, value16bit));
    EXPECT_TRUE(fieldExists(object, value16bit_name));
    EXPECT_TRUE(object[value16bit_name].asInt() == value16bit);

    value16bit = 0xFFFF;//min

    EXPECT_TRUE(AddFieldsHelper::addField(object, value16bit_name, value16bit));
    EXPECT_TRUE(fieldExists(object, value16bit_name));
    EXPECT_TRUE(object[value16bit_name].asInt() == value16bit);

    value16bit = 0x7FFF;//max

    EXPECT_TRUE(AddFieldsHelper::addField(object, value16bit_name, value16bit));
    EXPECT_TRUE(fieldExists(object, value16bit_name));
    EXPECT_TRUE(object[value16bit_name].asInt() == value16bit);

    //32bit
    std::string value32bit_name = "value32bit";
    int32_t value32bit = 0;
    EXPECT_TRUE(AddFieldsHelper::addField(object, value32bit_name, value32bit));
    EXPECT_TRUE(fieldExists(object, value32bit_name));
    EXPECT_TRUE(object[value32bit_name].asInt() == value32bit);

    value32bit = 0xFFFFFFFF;//min

    EXPECT_TRUE(AddFieldsHelper::addField(object, value32bit_name, value32bit));
    EXPECT_TRUE(fieldExists(object, value32bit_name));
    EXPECT_TRUE(object[value32bit_name].asInt() == value32bit);

    value32bit = 0x7FFFFFFF;//max

    EXPECT_TRUE(AddFieldsHelper::addField(object, value32bit_name, value32bit));
    EXPECT_TRUE(fieldExists(object, value32bit_name));
    EXPECT_TRUE(object[value32bit_name].asInt() == value32bit);

    //64bit
    std::string value64bit_name = "value64";
    int64_t value64bit = 0;
    EXPECT_TRUE(AddFieldsHelper::addField(object, value64bit_name, value64bit));
    EXPECT_TRUE(fieldExists(object, value64bit_name));
    EXPECT_TRUE(object[value64bit_name].asInt64() == value64bit);

    value64bit = 0xFFFFFFFFFFFFFFFF;//min

    EXPECT_TRUE(AddFieldsHelper::addField(object, value64bit_name, value64bit));
    EXPECT_TRUE(fieldExists(object, value64bit_name));
    EXPECT_TRUE(object[value64bit_name].asInt64() == value64bit);

    value64bit = 0x7FFFFFFFFFFFFFFF;//max

    EXPECT_TRUE(AddFieldsHelper::addField(object, value64bit_name, value64bit));
    EXPECT_TRUE(fieldExists(object, value64bit_name));
    EXPECT_TRUE(object[value64bit_name].asInt64() == value64bit);
}

TEST(JSONAddFieldHelper, CheckStringField) {
    Json::Value object;

    //empty
    std::string fieldEmptyName = "fieldEmpty";
    std::string empty;

    EXPECT_TRUE(AddFieldsHelper::addField(object, fieldEmptyName, empty));
    EXPECT_TRUE(fieldExists(object, fieldEmptyName));
    EXPECT_TRUE(object[fieldEmptyName].asString().empty());

    //1m
    std::string field1mName = "field1m";
    std::string value1m(1*1024*1024, 'A');

    EXPECT_TRUE(AddFieldsHelper::addField(object, field1mName, value1m));
    EXPECT_TRUE(fieldExists(object, field1mName));
    EXPECT_STRCASEEQ(object[field1mName].asString().c_str(), value1m.c_str());
}

TEST(JSONAddFieldHelper, CheckObjectField) {
    Json::Value object;

    std::string innerObjectFieldName = "InnerObject";
    Json::Value innerObject;

    std::string stringFieldName = "stringField";
    std::string stringFieldValue = "value";

    std::string int32FieldName = "int32Field";
    int32_t intField = 0xFFFFFFFF;

    EXPECT_TRUE(AddFieldsHelper::addField(innerObject, stringFieldName, stringFieldValue));
    EXPECT_TRUE(AddFieldsHelper::addField(innerObject, int32FieldName, intField));
    EXPECT_TRUE(AddFieldsHelper::addField(object, innerObjectFieldName, innerObject));

    EXPECT_TRUE(fieldExists(object, innerObjectFieldName));
    EXPECT_TRUE(object[innerObjectFieldName] == innerObject);
}

TEST(JSONAddFieldHelper, CheckArray) {
    Json::Value array;

    Json::Value element;

    std::string fieldName = "stringField";
    std::string fieldValue = "Value";

    EXPECT_TRUE(AddFieldsHelper::addField(element, fieldName, fieldValue));
    EXPECT_TRUE(AddFieldsHelper::addArrayElement(array, element));
    EXPECT_TRUE(AddFieldsHelper::addArrayElement(array, element));

    EXPECT_TRUE(array.isArray());

    EXPECT_EQ(array.size(), 2);

    EXPECT_EQ(array[0], element);
    EXPECT_EQ(array[1], element);
}