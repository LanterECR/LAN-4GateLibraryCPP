#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Lanter/Utils/Constants.h"

#include "Lanter/Manager/Lan4Gate.h"

using namespace Lanter;
using namespace Lanter::Manager;

using namespace Lanter::Communication;

using namespace Lanter::Message;
using namespace Lanter::Message::Request;
using namespace Lanter::Message::Response;
using namespace Lanter::Message::Notification;

using testing::Return;

TEST(Lan4Gate, TestAddRemoveRequestCallback) {
    int iterationCount = 50;
    std::vector<size_t> callbackIDs;

    Lan4Gate gate;

    std::function<void(std::shared_ptr<IRequestData>)> emptyFunc;

    auto realFunc = [](std::shared_ptr<IRequestData>) -> void {};

    EXPECT_EQ(gate.requestCallbacksCount(), 0);
    EXPECT_EQ(gate.addRequestCallback(emptyFunc), 0);
    EXPECT_EQ(gate.requestCallbacksCount(), 0);

    EXPECT_FALSE(gate.removeRequestCallback(1234));

    for(int i = 0; i < iterationCount; i++) {
        size_t id = gate.addRequestCallback(realFunc);
        EXPECT_NE(id, 0);

        callbackIDs.push_back(id);
    }

    ASSERT_EQ(gate.requestCallbacksCount(), callbackIDs.size());

    for(auto i : callbackIDs) {
        EXPECT_TRUE(gate.removeRequestCallback(i));
    }

    EXPECT_EQ(gate.requestCallbacksCount(), 0);
}

TEST(Lan4Gate, TestAddRemoveResponseCallback) {
    int iterationCount = 50;
    std::vector<size_t> callbackIDs;
    Lan4Gate gate;

    std::function<void(std::shared_ptr<IResponseData>)> emptyFunc;

    auto realFunc = [](std::shared_ptr<IResponseData>) -> void {};

    EXPECT_EQ(gate.responseCallbacksCount(), 0);
    EXPECT_EQ(gate.addResponseCallback(emptyFunc), 0);
    EXPECT_EQ(gate.responseCallbacksCount(), 0);

    EXPECT_FALSE(gate.removeResponseCallback(1234));

    for(int i = 0; i < iterationCount; i++) {
        size_t id = gate.addResponseCallback(realFunc);
        EXPECT_NE(id, 0);

        callbackIDs.push_back(id);
    }

    ASSERT_EQ(gate.responseCallbacksCount(), callbackIDs.size());

    for(auto i : callbackIDs) {
        EXPECT_TRUE(gate.removeResponseCallback(i));
    }

    EXPECT_EQ(gate.responseCallbacksCount(), 0);

}

TEST(Lan4Gate, TestAddRemoveNotificationCallback) {
    int iterationCount = 50;
    std::vector<size_t> callbackIDs;
    Lan4Gate gate;

    std::function<void(std::shared_ptr<INotificationData>)> emptyFunc;

    auto realFunc = [](std::shared_ptr<INotificationData>) -> void {};

    EXPECT_EQ(gate.notificationCallbacksCount(), 0);
    EXPECT_EQ(gate.addNotificationCallback(emptyFunc), 0);
    EXPECT_EQ(gate.notificationCallbacksCount(), 0);

    EXPECT_FALSE(gate.removeNotificationCallback(1234));

    for(int i = 0; i < iterationCount; i++) {
        size_t id = gate.addNotificationCallback(realFunc);
        EXPECT_NE(id, 0);

        callbackIDs.push_back(id);
    }

    ASSERT_EQ(gate.notificationCallbacksCount(), callbackIDs.size());

    for(auto i : callbackIDs) {
        EXPECT_TRUE(gate.removeNotificationCallback(i));
    }

    EXPECT_EQ(gate.notificationCallbacksCount(), 0);

}

class MOCKComms : public ICommunication {
public:
    MOCK_METHOD(bool, open, (), (override));
    MOCK_METHOD(bool, close, (), (override));
    MOCK_METHOD(bool, isOpen, (), (override));

    MOCK_METHOD(size_t, send, (const std::vector<uint8_t> &), (override));
    MOCK_METHOD(size_t, receive, (std::vector<uint8_t> &), (override));
};

TEST(Lan4Gate, TestAddResetGetCommunication) {
    //закроется с первой попытки
    auto closedComms = std::make_shared<MOCKComms>();
    EXPECT_CALL(*closedComms, isOpen).
            WillRepeatedly(Return(false));

    auto simpleOpen = std::make_shared<MOCKComms>();

    EXPECT_CALL(*simpleOpen, isOpen).
            WillOnce(Return(true)).
            WillRepeatedly(Return(false)); //последующие закроют

    EXPECT_CALL(*simpleOpen, close).
            WillRepeatedly(Return(true)); //вызов close сразу вернет true


    auto lockedComms = std::make_shared<MOCKComms>();

    EXPECT_CALL(*lockedComms, isOpen).
            WillOnce(Return(true)).
            WillOnce(Return(true)).
            WillRepeatedly(Return(false));

    EXPECT_CALL(*lockedComms, close).
            WillOnce(Return(false)).
            WillOnce(Return(false)).
            WillRepeatedly(Return(true));

    Lan4Gate gate;

    EXPECT_TRUE(gate.setCommunication(closedComms));
    EXPECT_EQ(gate.getCommunication(), closedComms);
    EXPECT_TRUE(gate.resetCommunication());
    EXPECT_EQ(gate.getCommunication(), nullptr);


    EXPECT_TRUE(gate.setCommunication(simpleOpen));
    EXPECT_EQ(gate.getCommunication(), simpleOpen);
    EXPECT_TRUE(gate.resetCommunication());
    EXPECT_EQ(gate.getCommunication(), nullptr);


    EXPECT_TRUE(gate.setCommunication(lockedComms));
    EXPECT_FALSE(gate.resetCommunication());
    EXPECT_FALSE(gate.resetCommunication());
    EXPECT_TRUE(gate.resetCommunication());
    EXPECT_EQ(gate.getCommunication(), nullptr);
}

TEST(Lan4Gate, TestStartStop) {
    auto stubComms = std::make_shared<MOCKComms>();

    Lan4Gate gate;
    gate.setCommunication(stubComms);

    EXPECT_FALSE(gate.isStarted());
    EXPECT_TRUE(gate.start());
    EXPECT_TRUE(gate.isStarted());
    EXPECT_TRUE(gate.stop());
    EXPECT_FALSE(gate.isStarted());
}

TEST(Lan4Gate, TestEcrNumber) {
    auto stubComms = std::make_shared<MOCKComms>();

    int validEcrNumber = Utils::Constants::MINIMUM_ECR_NUMBER;
    int invalidEcrNumber = Utils::Constants::MAXIMUM_ECR_NUMBER + 1;

    Lan4Gate gate;

    EXPECT_EQ(gate.getEcrNumber(), 1);

    EXPECT_TRUE(gate.setEcrNumber(validEcrNumber));
    EXPECT_FALSE(gate.setEcrNumber(invalidEcrNumber));
    EXPECT_EQ(gate.getEcrNumber(), 1);


    gate.setCommunication(stubComms);

    EXPECT_TRUE(gate.start());

    EXPECT_FALSE(gate.setEcrNumber(validEcrNumber));
    EXPECT_FALSE(gate.setEcrNumber(invalidEcrNumber));

    EXPECT_TRUE(gate.stop());

    EXPECT_TRUE(gate.setEcrNumber(validEcrNumber));
    EXPECT_FALSE(gate.setEcrNumber(invalidEcrNumber));
    EXPECT_EQ(gate.getEcrNumber(), 1);
}

TEST(Lan4Gate, TestPreparedRequest) {
    int validEcrNumber = Utils::Constants::MINIMUM_ECR_NUMBER;

    Lan4Gate gate;
    gate.setEcrNumber(validEcrNumber);

    auto lessNoOperation = (OperationCode)((int)OperationCode::NoOperation - 1);

    auto invalidRequest = gate.getPreparedRequest(lessNoOperation);

    auto validRequest = gate.getPreparedRequest(OperationCode::Sale);

    EXPECT_EQ(invalidRequest, nullptr);

    ASSERT_NE(validRequest, nullptr);

    EXPECT_EQ(validRequest->getEcrNumber(), validEcrNumber);

    EXPECT_EQ(validRequest->getOperationCode(), OperationCode::Sale);


}

TEST(Lan4Gate, TestPreparedResponse) {
    int validEcrNumber = Utils::Constants::MINIMUM_ECR_NUMBER;

    Lan4Gate gate;
    gate.setEcrNumber(validEcrNumber);

    auto lessNoOperation = (OperationCode)((int)OperationCode::NoOperation - 1);

    auto invalidResponse = gate.getPreparedResponse(lessNoOperation);

    auto validResponse = gate.getPreparedResponse(OperationCode::Sale);

    EXPECT_EQ(invalidResponse, nullptr);

    ASSERT_NE(validResponse, nullptr);

    EXPECT_EQ(validResponse->getEcrNumber(), validEcrNumber);

    EXPECT_EQ(validResponse->getOperationCode(), OperationCode::Sale);
}

TEST(Lan4Gate, TestPreparedNotification) {
    std::shared_ptr<ILan4Gate> gate = std::make_shared<Lan4Gate>();

    ASSERT_NE(gate, nullptr);

    auto firstValue = gate->getPreparedNotification(NotificationCode::FirstValue);

    auto lastValue = gate->getPreparedNotification(NotificationCode::LastValue);

    auto noCode = gate->getPreparedNotification(NotificationCode::NoNotification);

    auto withoutParam = gate->getPreparedNotification();


    ASSERT_NE(firstValue, nullptr);
    EXPECT_EQ(firstValue->getCode(), NotificationCode::FirstValue);

    ASSERT_NE(lastValue, nullptr);
    EXPECT_EQ(lastValue->getCode(), NotificationCode::LastValue);

    ASSERT_NE(noCode, nullptr);
    EXPECT_EQ(noCode->getCode(), NotificationCode::NoNotification);

    ASSERT_NE(withoutParam, nullptr);
    EXPECT_EQ(withoutParam->getCode(), NotificationCode::NoNotification);
}