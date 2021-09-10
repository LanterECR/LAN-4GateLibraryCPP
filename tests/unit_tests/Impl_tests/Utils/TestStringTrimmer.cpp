#include "gtest/gtest.h"

#include "Lanter/Utils/StringTrimmer.h"

using namespace Lanter;
using namespace Lanter::Utils;

TEST(TestStringTrimmer, CheckLeftTrim) {
    size_t spaceCount = 5;
    std::string value(spaceCount, ' ');
    std::string endValue = "Test";
    value.append(endValue);

    EXPECT_EQ(value.size(), endValue.size() + spaceCount);

    ltrim(value);

    EXPECT_EQ(value.size(), endValue.size());
    EXPECT_STREQ(value.c_str(), endValue.c_str());
}

TEST(TestStringTrimmer, CheckRightTrim) {
    size_t spaceCount = 5;
    std::string value = "Test";
    std::string endValue(spaceCount, ' ');

    std::string testValue = value + endValue;

    EXPECT_EQ(testValue.size(), value.size() + endValue.size());

    rtrim(testValue);

    EXPECT_EQ(testValue.size(), value.size());
    EXPECT_STREQ(testValue.c_str(), value.c_str());
}

TEST(TestStringTrimmer, CheckTrim) {
    size_t spaceCount = 5;
    std::string value = "Test";
    std::string spaceValue(spaceCount, ' ');

    std::string testValue = spaceValue + value + spaceValue;

    EXPECT_EQ(testValue.size(), value.size() + 2 * spaceValue.size());

    trim(testValue);

    EXPECT_EQ(testValue.size(), value.size());
    EXPECT_STREQ(testValue.c_str(), value.c_str());
}