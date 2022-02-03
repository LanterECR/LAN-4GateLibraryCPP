#include "gtest/gtest.h"
#include "Lanter/Message/Response/ResponseDataFactory.h"

#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;
using namespace Lanter::Utils::Constants;

TEST(TestResponseDataFactory, CheckFactory) {
    int32_t ecrNumberLessMinimum = MINIMUM_ECR_NUMBER - 1;
    int32_t ecrNumberGreatMaximum = MAXIMUM_ECR_NUMBER + 1;

    auto lessNoOperation = (OperationCode)((int)OperationCode::NoOperation - 1);
    EXPECT_NE(ResponseDataFactory::getResponseData(OperationCode::NoOperation, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_NE(ResponseDataFactory::getResponseData(OperationCode::NoOperation, MAXIMUM_ECR_NUMBER), nullptr);

    EXPECT_EQ(ResponseDataFactory::getResponseData(lessNoOperation, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(lessNoOperation, MAXIMUM_ECR_NUMBER), nullptr);

    EXPECT_EQ(ResponseDataFactory::getResponseData(OperationCode::NoOperation, ecrNumberLessMinimum), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(OperationCode::NoOperation, ecrNumberGreatMaximum), nullptr);

    EXPECT_EQ(ResponseDataFactory::getResponseData(getFirstOperationCode(), ecrNumberGreatMaximum), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(getLastOperationCode(), ecrNumberGreatMaximum), nullptr);

    EXPECT_EQ(ResponseDataFactory::getResponseData(getFirstOperationCode(), ecrNumberLessMinimum), nullptr);
    EXPECT_EQ(ResponseDataFactory::getResponseData(getLastOperationCode(), ecrNumberLessMinimum), nullptr);

    EXPECT_NE(ResponseDataFactory::getResponseData(OperationCode::Sale, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_FALSE(ResponseDataFactory::getResponseData(OperationCode::Sale, MINIMUM_ECR_NUMBER)->validateMandatoryFields());

    EXPECT_NE(ResponseDataFactory::getResponseData(OperationCode::Registration, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_FALSE(ResponseDataFactory::getResponseData(OperationCode::Registration, MINIMUM_ECR_NUMBER)->validateMandatoryFields());
    
    auto response = ResponseDataFactory::getResponseData(OperationCode::Registration, MINIMUM_ECR_NUMBER);
    response->setStatus(Status::Success);

    EXPECT_TRUE(response->validateMandatoryFields());
}