//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "gtest/gtest.h"
#include "Lanter/Request/RequestDataFactory.h"

using namespace Lanter;
using namespace Lanter::Request;

TEST(RequestDataFactory, CheckFactory) {
    EXPECT_THROW(RequestDataFactory::getRequestData(OperationCodes::NoOperation, 1), std::invalid_argument);
    EXPECT_THROW(RequestDataFactory::getRequestData(OperationCodes::NoOperation, 999), std::invalid_argument);
    EXPECT_THROW(RequestDataFactory::getRequestData(OperationCodes::NoOperation, 0), std::invalid_argument);
    EXPECT_THROW(RequestDataFactory::getRequestData(OperationCodes::NoOperation, 1000), std::invalid_argument);
    EXPECT_THROW(RequestDataFactory::getRequestData(OperationCodes::FirstValue, 1000), std::invalid_argument);
    EXPECT_THROW(RequestDataFactory::getRequestData(OperationCodes::LastValue, 1000), std::invalid_argument);
    EXPECT_THROW(RequestDataFactory::getRequestData(OperationCodes::FirstValue, 0), std::invalid_argument);
    EXPECT_THROW(RequestDataFactory::getRequestData(OperationCodes::LastValue, 0), std::invalid_argument);

    EXPECT_NO_THROW(RequestDataFactory::getRequestData(OperationCodes::Sale, 1));
    EXPECT_FALSE(RequestDataFactory::getRequestData(OperationCodes::Sale, 1)->validateMandatoryFields());

    EXPECT_NO_THROW(RequestDataFactory::getRequestData(OperationCodes::Registration, 1));
    EXPECT_TRUE(RequestDataFactory::getRequestData(OperationCodes::Registration, 1)->validateMandatoryFields());
}