#include <sstream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../MOCK/MOCKComm.h"

#include "Lanter/Communication/Decorators/SizeControlDecorator.h"

TEST(TestSizeControlDecorator, TestCheckHex) {
    auto mock = std::make_shared<Lanter::MOCKComms>();

    auto decorator = std::make_shared<Lanter::Communication::SizeControlDecorator>(mock);

    std::string noHex = "ikmnjp---";

    std::string hex = "abcdef11234FEDCBA536547";

    ASSERT_FALSE(decorator->checkHex(noHex));
    ASSERT_TRUE(decorator->checkHex(hex));
}

TEST(TestSizeControlDecorator, TestGetReceiveSize) {
    auto mock = std::make_shared<Lanter::MOCKComms>();

    auto decorator = std::make_shared<Lanter::Communication::SizeControlDecorator>(mock);

    std::string hexSize;
    std::string originalMessage = "Some text message";

    std::stringstream ss;
    ss << std::hex << originalMessage.size();
    ss >> hexSize;

    std::string message = hexSize + originalMessage;

    std::vector<uint8_t> errorVector(message.begin(), message.end());

    ASSERT_EQ(decorator->getReceiveSize(errorVector), 0);

    message = "00" + message;

    std::vector<uint8_t> correctVector(message.begin(), message.end());

    ASSERT_EQ(decorator->getReceiveSize(correctVector), originalMessage.size());
}