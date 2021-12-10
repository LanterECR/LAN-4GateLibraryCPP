#include <sstream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../MOCK/MOCKComm.h"

#include "Lanter/Communication/Decorators/SizeControlDecorator.h"

using namespace ::testing;

TEST(TestSizeControlDecorator, TestCheckHex) {
    auto mock = std::make_shared<Lanter::MOCKComms>();

    auto decorator = std::make_shared<Lanter::Communication::SizeControlDecorator>(mock);

    std::string noHex = "ikmnjp---";

    std::string hex = "abcdef11234FEDCBA536547";

    EXPECT_FALSE(decorator->checkHex(noHex));
    EXPECT_TRUE(decorator->checkHex(hex));
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

    EXPECT_EQ(decorator->getReceiveSize(errorVector), 0);

    message = "00" + message;

    std::vector<uint8_t> correctVector(message.begin(), message.end());

    EXPECT_EQ(decorator->getReceiveSize(correctVector), originalMessage.size());
}

TEST(TestSizeControlDecorator, TestSend) {

    std::string hexSize;
    std::string originalMessage = "Some text message";

    std::stringstream ss;
    ss << std::hex << originalMessage.size();
    ss >> hexSize;

    std::string message = hexSize + originalMessage;

    message = "00" + message;

    auto sendLambda = [message](const std::vector<uint8_t> & data) {
        std::string result (data.begin(), data.end());

        EXPECT_TRUE(result == message);

        return data.size();
    };

    auto mockConnection = std::make_shared<Lanter::MOCKComms>();

    EXPECT_CALL(*mockConnection, send).WillOnce(Invoke(sendLambda));


    auto decorator = std::make_shared<Lanter::Communication::SizeControlDecorator>(mockConnection);

    std::vector<uint8_t> messageVector(originalMessage.begin(), originalMessage.end());

    EXPECT_EQ(message.size(), decorator->send(messageVector));
}

TEST(TestSizeControlDecorator, TestReceive) {

    std::string hexSize;
    std::string originalMessage = "Some text message";

    std::stringstream ss;
    ss << std::hex << originalMessage.size();
    ss >> hexSize;

    std::string message = hexSize + originalMessage;

    message = "00" + message;

    auto receiveFirstPartOfLengthLambda = [message](std::vector<uint8_t> & data) {

        data.clear();
        data.push_back('0');
        data.push_back('0');
        return data.size();
    };

    auto receiveSecondPartOfLengthLambda = [hexSize](std::vector<uint8_t> & data) {

        data.clear();
        data.insert(data.end(), hexSize.begin(), hexSize.end());
        return data.size();
    };

    auto receiveMessageLambda = [originalMessage](std::vector<uint8_t> & data) {

        data.clear();
        data.insert(data.end(), originalMessage.begin(), originalMessage.end());
        return data.size();
    };

    auto mockConnection = std::make_shared<Lanter::MOCKComms>();

    EXPECT_CALL(*mockConnection, receive).
            WillOnce(Invoke(receiveFirstPartOfLengthLambda)).
            WillOnce(Invoke(receiveSecondPartOfLengthLambda)).
            WillOnce(Invoke(receiveMessageLambda));


    auto decorator = std::make_shared<Lanter::Communication::SizeControlDecorator>(mockConnection);

    std::vector<uint8_t> receivedMessageBuffer;

    for(int i = 0; i < 3; i++) {
        decorator->doCommunication();
        decorator->receive(receivedMessageBuffer);
    }

    std::string receivedMessage(receivedMessageBuffer.begin(), receivedMessageBuffer.end());

    EXPECT_TRUE(receivedMessage == originalMessage);
}