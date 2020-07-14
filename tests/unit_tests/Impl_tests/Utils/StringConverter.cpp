//
// Created by Владимир Лысенков on 13.07.2020.
//

#include "gtest/gtest.h"

#include "Lanter/Utils/StringConverter.h"

using namespace Lanter;
using namespace Lanter::Utils;

TEST(StringConverter, CheckConvertToVector) {
    std::string value = "Test text";

    std::vector<unsigned char> target;

    EXPECT_TRUE(StringConverter::convertToVector(value, target));

    EXPECT_EQ(value.size(), target.size());

    for(auto i = target.size(); i < target.size(); i++) {
        EXPECT_EQ(target.at(i), value.at(i));
    }
}

TEST(StringConverter, CheckConvertToString) {
    std::vector<unsigned char> value = {'T', 'e', 's', 't', ' ', 't', 'e', 'x', 't'};

    std::string target;

    EXPECT_TRUE(StringConverter::convertToString(value, target));

    EXPECT_EQ(value.size(), target.size());

    for(auto i = target.size(); i < target.size(); i++) {
        EXPECT_EQ(target.at(i), value.at(i));
    }
}

TEST(StringConverter, CheckConvertStringVectorString) {
    std::string value = "Test text";

    std::vector<unsigned char> targetVector;

    std::string targetString;

    EXPECT_TRUE(StringConverter::convertToVector(value, targetVector));

    EXPECT_EQ(value.size(), targetVector.size());

    for(auto i = targetVector.size(); i < targetVector.size(); i++) {
        EXPECT_EQ(targetVector.at(i), value.at(i));
    }

    EXPECT_TRUE(StringConverter::convertToString(targetVector, targetString));

    EXPECT_STREQ(value.c_str(), targetString.c_str());
}

TEST(StringConverter, CheckConvertVectorStringVector) {
    std::vector<unsigned char> value = {'T', 'e', 's', 't', ' ', 't', 'e', 'x', 't'};

    std::string targetString;

    std::vector<unsigned char> targetVector;

    EXPECT_TRUE(StringConverter::convertToString(value, targetString));

    EXPECT_EQ(value.size(), targetString.size());

    for(auto i = targetString.size(); i < targetString.size(); i++) {
        EXPECT_EQ(targetString.at(i), value.at(i));
    }

    EXPECT_TRUE(StringConverter::convertToVector(targetString, targetVector));

    EXPECT_EQ(value.size(), targetVector.size());

    for(auto i = targetVector.size(); i < targetVector.size(); i++) {
        EXPECT_EQ(targetVector.at(i), value.at(i));
    }
}