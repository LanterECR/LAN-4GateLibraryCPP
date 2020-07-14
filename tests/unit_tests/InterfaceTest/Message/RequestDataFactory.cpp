//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "gtest/gtest.h"
#include "Lanter/Message/Request/RequestDataFactory.h"

#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;
using namespace Lanter::Utils::Constants;

TEST(RequestDataFactory, CheckFactory) {
    int32_t ecrNumberLessMinimum = MINIMUM_ECR_NUMBER - 1;
    int32_t ecrNumberGreatMaximum = MAXIMUM_ECR_NUMBER + 1;
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCodes::NoOperation, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCodes::NoOperation, MAXIMUM_ECR_NUMBER), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCodes::NoOperation, ecrNumberLessMinimum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCodes::NoOperation, ecrNumberGreatMaximum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCodes::FirstValue, ecrNumberGreatMaximum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCodes::LastValue, ecrNumberGreatMaximum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCodes::FirstValue, ecrNumberLessMinimum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCodes::LastValue, ecrNumberLessMinimum), nullptr);

    EXPECT_NE(RequestDataFactory::getRequestData(OperationCodes::Sale, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_FALSE(RequestDataFactory::getRequestData(OperationCodes::Sale, MINIMUM_ECR_NUMBER)->validateMandatoryFields());

    EXPECT_NE(RequestDataFactory::getRequestData(OperationCodes::Registration, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_TRUE(RequestDataFactory::getRequestData(OperationCodes::Registration, MINIMUM_ECR_NUMBER)->validateMandatoryFields());
}