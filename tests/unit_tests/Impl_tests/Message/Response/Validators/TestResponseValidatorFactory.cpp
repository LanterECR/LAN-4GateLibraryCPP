#include "gtest/gtest.h"

#include "Lanter/Message/Response/Validators/ValidatorFactory.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;

TEST(TestResponseValidatorFactory, CheckValidatorCreation) {
    auto start = (int)OperationCode::FirstValue;
    auto end = (int)OperationCode::LastValue;

    for(int i = start; i <= end; i++) {
        EXPECT_TRUE(ValidatorFactory::getValidator((OperationCode)i) != nullptr);
    }
}