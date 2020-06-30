//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "gtest/gtest.h"
#include "Lanter/Response/ResponseDataFactory.h"

#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Response;
using namespace Lanter::Utils::Constants;

TEST(ResponseDataFactory, CheckFactory) {
    int32_t ecrNumberLessMinimum = MINIMUM_ECR_NUMBER - 1;
    int32_t ecrNumberGreatMaximum = MAXIMUM_ECR_NUMBER + 1;
    EXPECT_THROW(ResponseDataFactory::getResponseData(OperationCodes::NoOperation, MINIMUM_ECR_NUMBER), std::invalid_argument);
    EXPECT_THROW(ResponseDataFactory::getResponseData(OperationCodes::NoOperation, MAXIMUM_ECR_NUMBER), std::invalid_argument);
    EXPECT_THROW(ResponseDataFactory::getResponseData(OperationCodes::NoOperation, ecrNumberLessMinimum), std::invalid_argument);
    EXPECT_THROW(ResponseDataFactory::getResponseData(OperationCodes::NoOperation, ecrNumberGreatMaximum), std::invalid_argument);
    EXPECT_THROW(ResponseDataFactory::getResponseData(OperationCodes::FirstValue, ecrNumberGreatMaximum), std::invalid_argument);
    EXPECT_THROW(ResponseDataFactory::getResponseData(OperationCodes::LastValue, ecrNumberGreatMaximum), std::invalid_argument);
    EXPECT_THROW(ResponseDataFactory::getResponseData(OperationCodes::FirstValue, ecrNumberLessMinimum), std::invalid_argument);
    EXPECT_THROW(ResponseDataFactory::getResponseData(OperationCodes::LastValue, ecrNumberLessMinimum), std::invalid_argument);

    EXPECT_NO_THROW(ResponseDataFactory::getResponseData(OperationCodes::Sale, MINIMUM_ECR_NUMBER));
    EXPECT_FALSE(ResponseDataFactory::getResponseData(OperationCodes::Sale, MINIMUM_ECR_NUMBER)->validateMandatoryFields());

    EXPECT_NO_THROW(ResponseDataFactory::getResponseData(OperationCodes::Registration, MINIMUM_ECR_NUMBER));
    EXPECT_FALSE(ResponseDataFactory::getResponseData(OperationCodes::Registration, MINIMUM_ECR_NUMBER)->validateMandatoryFields());

    auto response = ResponseDataFactory::getResponseData(OperationCodes::Registration, MINIMUM_ECR_NUMBER);
    response->setStatus(Lanter::Response::Status::Success);

    EXPECT_TRUE(response->validateMandatoryFields());
}