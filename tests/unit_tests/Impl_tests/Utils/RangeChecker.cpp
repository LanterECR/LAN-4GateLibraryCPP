//
// Created by Владимир Лысенков on 28.06.2020.
//

#include "gtest/gtest.h"

#include "Lanter/Utils/RangeChecker.h"

using namespace Lanter::Utils;
TEST(RangeChecker, TestZeroRange) {
    int64_t minRange = 0;
    int64_t maxRange = 0;

    EXPECT_TRUE(checkValueRange(0, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(1, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(-1, minRange, maxRange));
}

TEST(RangeChecker, NegativeRange) {
    int64_t minRange = -10;
    int64_t maxRange = -1;

    EXPECT_FALSE(checkValueRange(-11, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(0, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(5, minRange, maxRange));

    EXPECT_TRUE(checkValueRange(-10, minRange, maxRange));

    EXPECT_TRUE(checkValueRange(-1, minRange, maxRange));

    EXPECT_TRUE(checkValueRange(-5, minRange, maxRange));
}

TEST(RangeChecker, RevertNegativeRange) {
    int64_t minRange = -1;
    int64_t maxRange = -10;

    EXPECT_FALSE(checkValueRange(-11, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(0, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(-10, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(-1, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(-5, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(5, minRange, maxRange));
}

TEST(RangeChecker, PositiveRange) {
    int64_t minRange = 1;
    int64_t maxRange = 10;

    EXPECT_FALSE(checkValueRange(11, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(0, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(-5, minRange, maxRange));

    EXPECT_TRUE(checkValueRange(10, minRange, maxRange));

    EXPECT_TRUE(checkValueRange(1, minRange, maxRange));

    EXPECT_TRUE(checkValueRange(5, minRange, maxRange));
}

TEST(RangeChecker, RevertPositiveRange) {
    int64_t minRange = 10;
    int64_t maxRange = 1;

    EXPECT_FALSE(checkValueRange(11, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(0, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(10, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(1, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(5, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(-5, minRange, maxRange));
}

TEST(RangeChecker, NegativePositiveRange) {
    int64_t minRange = -10;
    int64_t maxRange = 10;

    EXPECT_FALSE(checkValueRange(11, minRange, maxRange));
    EXPECT_FALSE(checkValueRange(-11, minRange, maxRange));


    EXPECT_TRUE(checkValueRange(0, minRange, maxRange));

    EXPECT_TRUE(checkValueRange(-5, minRange, maxRange));

    EXPECT_TRUE(checkValueRange(10, minRange, maxRange));

    EXPECT_TRUE(checkValueRange(1, minRange, maxRange));

    EXPECT_TRUE(checkValueRange(5, minRange, maxRange));
}

TEST(RangeChecker, RevertNegativePositiveRange) {
    int64_t minRange = 10;
    int64_t maxRange = -10;

    EXPECT_FALSE(checkValueRange(11, minRange, maxRange));
    EXPECT_FALSE(checkValueRange(-11, minRange, maxRange));


    EXPECT_FALSE(checkValueRange(0, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(-5, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(10, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(1, minRange, maxRange));

    EXPECT_FALSE(checkValueRange(5, minRange, maxRange));
}