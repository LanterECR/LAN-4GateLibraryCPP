#include "gtest/gtest.h"

#include "Lanter/Message/Request/Validators/ValidatorFactory.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;

TEST(TestRequestValidatorFactory, CheckValidatorCreation) {
    auto start = (int)getFirstOperationCode();
    auto end = (int)getLastOperationCode();

    for(int i = start; i <= end; i++) {
        EXPECT_TRUE(ValidatorFactory::getValidator((OperationCode)i) != nullptr);
    }
}