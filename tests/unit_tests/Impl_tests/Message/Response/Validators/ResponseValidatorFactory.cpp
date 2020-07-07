//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "gtest/gtest.h"

#include "Lanter/Message/Response/Validators/ValidatorFactory.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;

TEST(ResponseValidatorFactory, CheckValidatorCreation) {
    auto start = (int)OperationCodes::FirstValue;
    auto end = (int)OperationCodes::LastValue;

    for(int i = start; i <= end; i++) {
        EXPECT_TRUE(ValidatorFactory::getValidator((OperationCodes)i) != nullptr);
    }
}