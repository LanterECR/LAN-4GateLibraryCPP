//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "gtest/gtest.h"
#include "Lanter/Message/Response/ResponseDataFactory.h"

#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;
using namespace Lanter::Utils::Constants;

TEST(ResponseDataFactory, CheckFactory) {
    int32_t ecrNumberLessMinimum = MINIMUM_ECR_NUMBER - 1;
    int32_t ecrNumberGreatMaximum = MAXIMUM_ECR_NUMBER + 1;
    EXPECT_EQ(ResponseDataFactory::getResponseData(OperationCodes::NoOperation, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(OperationCodes::NoOperation, MAXIMUM_ECR_NUMBER), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(OperationCodes::NoOperation, ecrNumberLessMinimum), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(OperationCodes::NoOperation, ecrNumberGreatMaximum), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(OperationCodes::FirstValue, ecrNumberGreatMaximum), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(OperationCodes::LastValue, ecrNumberGreatMaximum), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(OperationCodes::FirstValue, ecrNumberLessMinimum), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(OperationCodes::LastValue, ecrNumberLessMinimum), nullptr);

    EXPECT_NE(ResponseDataFactory::getResponseData(OperationCodes::Sale, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_FALSE(ResponseDataFactory::getResponseData(OperationCodes::Sale, MINIMUM_ECR_NUMBER)->validateMandatoryFields());

    EXPECT_NE(ResponseDataFactory::getResponseData(OperationCodes::Registration, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_FALSE(ResponseDataFactory::getResponseData(OperationCodes::Registration, MINIMUM_ECR_NUMBER)->validateMandatoryFields());

    auto response = ResponseDataFactory::getResponseData(OperationCodes::Registration, MINIMUM_ECR_NUMBER);
    response->setStatus(Status::Success);

    EXPECT_TRUE(response->validateMandatoryFields());
}