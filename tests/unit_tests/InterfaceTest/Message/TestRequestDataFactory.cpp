#include "gtest/gtest.h"
#include "Lanter/Message/Request/RequestDataFactory.h"

#include "Lanter/Utils/Constants.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;
using namespace Lanter::Utils::Constants;

TEST(TestRequestDataFactory, CheckFactory) {
    int32_t ecrNumberLessMinimum = MINIMUM_ECR_NUMBER - 1;
    int32_t ecrNumberGreatMaximum = MAXIMUM_ECR_NUMBER + 1;

    auto lessNoOperation = (OperationCode)((int)OperationCode::NoOperation - 1);
    EXPECT_NE(RequestDataFactory::getRequestData(OperationCode::NoOperation, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_NE(RequestDataFactory::getRequestData(OperationCode::NoOperation, MAXIMUM_ECR_NUMBER), nullptr);

    EXPECT_EQ(RequestDataFactory::getRequestData(lessNoOperation, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(lessNoOperation, MAXIMUM_ECR_NUMBER), nullptr);

    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCode::NoOperation, ecrNumberLessMinimum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(OperationCode::NoOperation, ecrNumberGreatMaximum), nullptr);

    EXPECT_EQ(RequestDataFactory::getRequestData(getFirstOperationCode(), ecrNumberGreatMaximum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(getLastOperationCode(), ecrNumberGreatMaximum), nullptr);

    EXPECT_EQ(RequestDataFactory::getRequestData(getFirstOperationCode(), ecrNumberLessMinimum), nullptr);
    EXPECT_EQ(RequestDataFactory::getRequestData(getLastOperationCode(), ecrNumberLessMinimum), nullptr);

    EXPECT_NE(RequestDataFactory::getRequestData(OperationCode::Sale, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_FALSE(RequestDataFactory::getRequestData(OperationCode::Sale, MINIMUM_ECR_NUMBER)->validateMandatoryFields());

    EXPECT_NE(RequestDataFactory::getRequestData(OperationCode::Registration, MINIMUM_ECR_NUMBER), nullptr);
    EXPECT_TRUE(RequestDataFactory::getRequestData(OperationCode::Registration, MINIMUM_ECR_NUMBER)->validateMandatoryFields());
}