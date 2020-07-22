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

    auto lessNoOperation = (OperationCode)((int)OperationCode::NoOperation - 1);
    EXPECT_NE(RequestDataFactory::getRequestData(OperationCode::NoOperation, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_NE(RequestDataFactory::getRequestData(OperationCode::NoOperation, MAXIMUM_ECR_NUMBER), nullptr);

    EXPECT_EQ(RequestDataFactory::getRequestData(lessNoOperation, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(lessNoOperation, MAXIMUM_ECR_NUMBER), nullptr);

    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCode::NoOperation, ecrNumberLessMinimum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCode::NoOperation, ecrNumberGreatMaximum), nullptr);

    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCode::FirstValue, ecrNumberGreatMaximum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCode::LastValue, ecrNumberGreatMaximum), nullptr);

    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCode::FirstValue, ecrNumberLessMinimum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCode::LastValue, ecrNumberLessMinimum), nullptr);

    EXPECT_NE(RequestDataFactory::getRequestData(OperationCode::Sale, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_FALSE(RequestDataFactory::getRequestData(OperationCode::Sale, MINIMUM_ECR_NUMBER)->validateMandatoryFields());

    EXPECT_NE(RequestDataFactory::getRequestData(OperationCode::Registration, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_TRUE(RequestDataFactory::getRequestData(OperationCode::Registration, MINIMUM_ECR_NUMBER)->validateMandatoryFields());
}