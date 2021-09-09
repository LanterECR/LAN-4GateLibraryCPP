#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Lanter/Utils/Constants.h"
#include "Lanter/Utils/StringConverter.h"

#include "Lanter/Manager/Lan4Gate.h"


#include "MOCKComm.h"
#include "MOCKCallback.h"

using namespace Lanter;
using namespace Lanter::Manager;

using namespace Lanter::Communication;

using namespace Lanter::Message;
using namespace Lanter::Message::Request;
using namespace Lanter::Message::Response;
using namespace Lanter::Message::Notification;

//using ::testing::Return;
using namespace ::testing;

TEST(TestLan4Gate, TestAddRemoveRequestCallback) {
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

TEST(TestLan4Gate, TestAddRemoveResponseCallback) {
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

TEST(TestLan4Gate, TestAddRemoveNotificationCallback) {
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



TEST(TestLan4Gate, TestAddResetGetCommunication) {
    //закроется с первой попытки
    auto closedComms = std::make_shared<MOCKComms>();
    EXPECT_CALL(*closedComms, isOpen).
            WillRepeatedly(Return(false));

    EXPECT_CALL(*closedComms, close).
            WillRepeatedly(Return(true));

    EXPECT_CALL(*closedComms, open).Times(0);
    EXPECT_CALL(*closedComms, send).Times(0);
    EXPECT_CALL(*closedComms, receive).Times(0);
    EXPECT_CALL(*closedComms, connect).Times(0);
    EXPECT_CALL(*closedComms, isConnected).Times(0);

    auto simpleOpen = std::make_shared<MOCKComms>();

    EXPECT_CALL(*simpleOpen, isOpen).
            WillOnce(Return(true)).
            WillRepeatedly(Return(false)); //последующие закроют

    EXPECT_CALL(*simpleOpen, close).
            WillRepeatedly(Return(true)); //вызов close сразу вернет true

    EXPECT_CALL(*simpleOpen, open).Times(0);
    EXPECT_CALL(*simpleOpen, send).Times(0);
    EXPECT_CALL(*simpleOpen, receive).Times(0);
    EXPECT_CALL(*simpleOpen, connect).Times(0);
    EXPECT_CALL(*simpleOpen, isConnected).Times(0);

    auto lockedComms = std::make_shared<MOCKComms>();

    EXPECT_CALL(*lockedComms, isOpen).
            WillOnce(Return(true)).
            WillOnce(Return(true)).
            WillRepeatedly(Return(false));

    EXPECT_CALL(*lockedComms, close).
            WillOnce(Return(false)).
            WillOnce(Return(false)).
            WillRepeatedly(Return(true));

    EXPECT_CALL(*lockedComms, open).Times(0);
    EXPECT_CALL(*lockedComms, send).Times(0);
    EXPECT_CALL(*lockedComms, receive).Times(0);
    EXPECT_CALL(*lockedComms, connect).Times(0);
    EXPECT_CALL(*lockedComms, isConnected).Times(0);

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

TEST(TestLan4Gate, TestStartStop) {
    auto stubComms = std::make_shared<MOCKComms>();

    EXPECT_CALL(*stubComms, open).Times(0);
    EXPECT_CALL(*stubComms, close).Times(2).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, isOpen).Times(3).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, send).Times(0);
    EXPECT_CALL(*stubComms, receive).Times(0);
    EXPECT_CALL(*stubComms, connect).Times(0);
    EXPECT_CALL(*stubComms, isConnected).Times(0);

    Lan4Gate gate;
    EXPECT_EQ(gate.start(), ILan4Gate::Status::Error);


    gate.setCommunication(stubComms);

    EXPECT_FALSE(gate.isStarted());
    EXPECT_EQ(gate.start(), ILan4Gate::Status::Success);
    EXPECT_TRUE(gate.isStarted());
    EXPECT_EQ(gate.stop(), ILan4Gate::Status::Success);
    EXPECT_FALSE(gate.isStarted());
}

TEST(TestLan4Gate, TestEcrNumber) {
    auto stubComms = std::make_shared<MOCKComms>();
    EXPECT_CALL(*stubComms, open).Times(0);
    EXPECT_CALL(*stubComms, close).Times(2).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, isOpen).Times(3).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, send).Times(0);
    EXPECT_CALL(*stubComms, receive).Times(0);
    EXPECT_CALL(*stubComms, connect).Times(0);
    EXPECT_CALL(*stubComms, isConnected).Times(0);

    int validEcrNumber = Utils::Constants::MINIMUM_ECR_NUMBER;
    int invalidEcrNumber = Utils::Constants::MAXIMUM_ECR_NUMBER + 1;

    Lan4Gate gate;

    EXPECT_EQ(gate.getEcrNumber(), 1);

    EXPECT_TRUE(gate.setEcrNumber(validEcrNumber));
    EXPECT_FALSE(gate.setEcrNumber(invalidEcrNumber));
    EXPECT_EQ(gate.getEcrNumber(), 1);


    gate.setCommunication(stubComms);

    EXPECT_EQ(gate.start(), ILan4Gate::Status::Success);

    EXPECT_FALSE(gate.setEcrNumber(validEcrNumber));
    EXPECT_FALSE(gate.setEcrNumber(invalidEcrNumber));

    EXPECT_EQ(gate.stop(), ILan4Gate::Status::Success);

    EXPECT_TRUE(gate.setEcrNumber(validEcrNumber));
    EXPECT_FALSE(gate.setEcrNumber(invalidEcrNumber));
    EXPECT_EQ(gate.getEcrNumber(), 1);
}

TEST(TestLan4Gate, TestPreparedRequest) {
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

TEST(TestLan4Gate, TestPreparedResponse) {
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

TEST(TestLan4Gate, TestPreparedNotification) {
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

TEST(TestLan4Gate, TestSendRequest) {
    auto stubComms = std::make_shared<MOCKComms>();

    EXPECT_CALL(*stubComms, open).Times(0);
    EXPECT_CALL(*stubComms, close).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, isOpen).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, send).Times(0);
    EXPECT_CALL(*stubComms, receive).Times(0);
    EXPECT_CALL(*stubComms, connect).Times(0);
    EXPECT_CALL(*stubComms, isConnected).Times(0);

    Lan4Gate gate;

    gate.setCommunication(stubComms);

    auto request = gate.getPreparedRequest(OperationCode::FinalizeTransaction);

    std::shared_ptr<IRequestData> nullRequest = nullptr;

    ASSERT_NE(request, nullptr);

    EXPECT_FALSE(gate.sendMessage(request));

    EXPECT_EQ(gate.start(), ILan4Gate::Status::Success);

    EXPECT_FALSE(gate.sendMessage(nullRequest));

    EXPECT_TRUE(gate.sendMessage(request));
}

TEST(TestLan4Gate, TestSendResponse) {
    auto stubComms = std::make_shared<MOCKComms>();

    EXPECT_CALL(*stubComms, open).Times(0);
    EXPECT_CALL(*stubComms, close).Times(1).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, isOpen).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, send).Times(0);
    EXPECT_CALL(*stubComms, receive).Times(0);
    EXPECT_CALL(*stubComms, connect).Times(0);
    EXPECT_CALL(*stubComms, isConnected).Times(0);

    Lan4Gate gate;

    gate.setCommunication(stubComms);

    auto response = gate.getPreparedResponse(OperationCode::FinalizeTransaction);

    std::shared_ptr<IResponseData> nullResponse = nullptr;

    ASSERT_NE(response, nullptr);

    EXPECT_FALSE(gate.sendMessage(response));

    EXPECT_EQ(gate.start(), ILan4Gate::Status::Success);

    EXPECT_FALSE(gate.sendMessage(nullResponse));

    EXPECT_FALSE(gate.sendMessage(response));

    response->setStatus(Lanter::Message::Response::Status::Success);

    EXPECT_TRUE(gate.sendMessage(response));
}

TEST(TestLan4Gate, TestSendNotification) {
    auto stubComms = std::make_shared<MOCKComms>();

    EXPECT_CALL(*stubComms, open).Times(0);
    EXPECT_CALL(*stubComms, close).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, isOpen).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, send).Times(0);
    EXPECT_CALL(*stubComms, receive).Times(0);
    EXPECT_CALL(*stubComms, connect).Times(0);
    EXPECT_CALL(*stubComms, isConnected).Times(0);

    Lan4Gate gate;

    gate.setCommunication(stubComms);

    auto notification = gate.getPreparedNotification(NotificationCode::AccountBlocked);

    std::shared_ptr<INotificationData> nullNotification = nullptr;

    ASSERT_NE(notification, nullptr);

    EXPECT_FALSE(gate.sendMessage(notification));

    EXPECT_EQ(gate.start(), ILan4Gate::Status::Success);

    EXPECT_FALSE(gate.sendMessage(nullNotification));

    EXPECT_TRUE(gate.sendMessage(notification));
}

TEST(TestLan4Gate, TestChangeCallbackNotificationType) {
    auto stubComms = std::make_shared<MOCKComms>();

    EXPECT_CALL(*stubComms, open).Times(0);
    EXPECT_CALL(*stubComms, close).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, isOpen).WillRepeatedly(Return(true));
    EXPECT_CALL(*stubComms, send).Times(0);
    EXPECT_CALL(*stubComms, receive).Times(0);
    EXPECT_CALL(*stubComms, connect).Times(0);
    EXPECT_CALL(*stubComms, isConnected).Times(0);

    //Объединение двух типов
    auto callType = static_cast<ILan4Gate::CallbackNotificationType>(static_cast<int>(ILan4Gate::CallbackNotificationType::Sync) | static_cast<int>(ILan4Gate::CallbackNotificationType::Async));

    Lan4Gate gate;

    gate.setCommunication(stubComms);

    EXPECT_EQ(gate.getCallbackNotificationType(), ILan4Gate::CallbackNotificationType::Async);


    EXPECT_TRUE(gate.setCallbackNotificationType(callType));
    EXPECT_EQ(gate.getCallbackNotificationType(), ILan4Gate::CallbackNotificationType::Sync);

    EXPECT_TRUE(gate.setCallbackNotificationType(ILan4Gate::CallbackNotificationType::Sync));

    EXPECT_EQ(gate.getCallbackNotificationType(), ILan4Gate::CallbackNotificationType::Sync);

    EXPECT_EQ(gate.start(), ILan4Gate::Status::Success);

    EXPECT_FALSE(gate.setCallbackNotificationType(ILan4Gate::CallbackNotificationType::Async));
    EXPECT_EQ(gate.getCallbackNotificationType(), ILan4Gate::CallbackNotificationType::Sync);

    EXPECT_EQ(gate.stop(), ILan4Gate::Status::Success);

    EXPECT_TRUE(gate.setCallbackNotificationType(ILan4Gate::CallbackNotificationType::Async));
    EXPECT_EQ(gate.getCallbackNotificationType(), ILan4Gate::CallbackNotificationType::Async);
}

TEST(TestLan4Gate, TestSendMessageDoL4G) {
    bool commsOpen = false;
    bool commsConnected = false;

    auto openFunc = [&commsOpen](){
        commsOpen = true;
        return commsOpen;
    };

    auto isOpenFunc = [&commsOpen](){
        return commsOpen;
    };

    auto closeFunc = [&commsOpen, &commsConnected](){
        commsOpen = false;
        commsConnected = false;
        return commsOpen;
    };

    auto connectFunc = [&commsConnected] () {
        commsConnected = true;
        return commsConnected;
    };

    auto isConnectedFunc = [&commsConnected] () {
        return commsConnected;
    };

    auto sendRequestFunc = [](const std::vector<uint8_t> & data){
        std::string request(R"({"__class":"LANTER::Request","__object":{"EcrNumber":1,"OperationCode":814}})");

        std::string str(data.begin(), data.end());

        EXPECT_TRUE(request == str);
        return data.size();
    };

    auto sendResponseFunc = [](const std::vector<uint8_t> & data){
        std::string response(R"({"__class":"LANTER::Response","__object":{"EcrNumber":1,"OperationCode":814,"Status":1}})");

        std::string str(data.begin(), data.end());

        EXPECT_TRUE(response == str);
        return data.size();
    };

    auto sendNotificationFunc = [](const std::vector<uint8_t> & data){
        std::string notification(R"({"__class":"LANTER::Notification","__object":{"Code":27}})");

        std::string str(data.begin(), data.end());

        EXPECT_TRUE(notification == str);
        return data.size();
    };

    auto comms = std::make_shared<MOCKComms>();

    EXPECT_CALL(*comms, isOpen).
        WillRepeatedly(Invoke(isOpenFunc));

    EXPECT_CALL(*comms, open).
        WillOnce(Invoke(openFunc));

    EXPECT_CALL(*comms, close).
            WillOnce(Invoke(closeFunc));

    EXPECT_CALL(*comms, connect).
            WillRepeatedly(Invoke(connectFunc));

    EXPECT_CALL(*comms, isConnected).
            WillRepeatedly(Invoke(isConnectedFunc));

    EXPECT_CALL(*comms, send(_)).
            WillOnce(Invoke(sendRequestFunc)).
            WillOnce(Invoke(sendResponseFunc)).
            WillOnce(Invoke(sendNotificationFunc)).
            WillOnce(Invoke(sendNotificationFunc)).
            WillOnce(Invoke(sendResponseFunc)).
            WillOnce(Invoke(sendRequestFunc));

    Lan4Gate gate;

    gate.setCommunication(comms);

    auto request = gate.getPreparedRequest(OperationCode::FinalizeTransaction);

    auto response = gate.getPreparedResponse(OperationCode::FinalizeTransaction);
    response->setStatus(Lanter::Message::Response::Status::Success);

    auto notification = gate.getPreparedNotification(NotificationCode::AccountBlocked);


    ASSERT_NE(notification, nullptr);

    EXPECT_EQ(gate.start(), ILan4Gate::Status::Success);

    //6 отправок данных
    EXPECT_TRUE(gate.sendMessage(request));
    EXPECT_TRUE(gate.sendMessage(response));
    EXPECT_TRUE(gate.sendMessage(notification));
    EXPECT_TRUE(gate.sendMessage(notification));
    EXPECT_TRUE(gate.sendMessage(response));
    EXPECT_TRUE(gate.sendMessage(request));

    //10 циклов библиотеки
    for(int i = 0; i < 10; i++) {
        EXPECT_NO_THROW(gate.doLan4Gate());
    }

    EXPECT_EQ(gate.stop(), ILan4Gate::Status::Success);
}

TEST(TestLan4Gate, TestReceiveMessageDoL4G) {
    bool commsOpen = false;
    bool commsConnected = false;

    auto openFunc = [&commsOpen](){
        commsOpen = true;
        return commsOpen;
    };

    auto isOpenFunc = [&commsOpen](){
        return commsOpen;
    };

    auto closeFunc = [&commsOpen, &commsConnected](){
        commsOpen = false;
        commsConnected = false;
        return commsOpen;
    };

    auto connectFunc = [&commsConnected] () {
        commsConnected = true;
        return commsConnected;
    };

    auto isConnectedFunc = [&commsConnected] () {
        return commsConnected;
    };

    auto receiveRequestFunc = [](std::vector<uint8_t> & data){
        std::string request(R"({"__class":"LANTER::Request","__object":{"EcrNumber":1,"OperationCode":814}})");

        Utils::StringConverter::convertToVector(request, data);
        return data.size();
    };

    auto receiveResponseFunc = [](std::vector<uint8_t> & data){
        std::string response(R"({"__class":"LANTER::Response","__object":{"EcrNumber":1,"OperationCode":814,"Status":1}})");

        Utils::StringConverter::convertToVector(response, data);
        return data.size();
    };

    auto receiveNotificationFunc = [](std::vector<uint8_t> & data){
        std::string notification(R"({"__class":"LANTER::Notification","__object":{"Code":27}})");

        Utils::StringConverter::convertToVector(notification, data);
        return data.size();
    };

    auto receiveConnectionStatusTrueFunc = [](bool connected) {
        EXPECT_TRUE(connected);
    };

    auto comms = std::make_shared<MOCKComms>();

    EXPECT_CALL(*comms, isOpen).
            WillRepeatedly(Invoke(isOpenFunc));

    EXPECT_CALL(*comms, open).
            WillOnce(Invoke(openFunc));

    EXPECT_CALL(*comms, close).
            WillOnce(Invoke(closeFunc));


    EXPECT_CALL(*comms, receive(_)).
            WillOnce(Invoke(receiveRequestFunc)).
            WillOnce(Invoke(receiveResponseFunc)).
            WillOnce(Invoke(receiveNotificationFunc)).
            WillOnce(Invoke(receiveNotificationFunc)).
            WillOnce(Invoke(receiveResponseFunc)).
            WillOnce(Invoke(receiveRequestFunc)).
            WillRepeatedly(Return(0));

    EXPECT_CALL(*comms, connect).
            WillRepeatedly(Invoke(connectFunc));

    EXPECT_CALL(*comms, isConnected).
            WillRepeatedly(Invoke(isConnectedFunc));

    auto checkRequest = [](std::shared_ptr<IRequestData> request) {
        ASSERT_NE(request, nullptr);

        EXPECT_EQ(request->getEcrNumber(), 1);
        EXPECT_EQ(request->getOperationCode(), OperationCode::FinalizeTransaction);
    };

    auto checkResponse = [](std::shared_ptr<IResponseData> response) {
        ASSERT_NE(response, nullptr);

        EXPECT_EQ(response->getEcrNumber(), 1);
        EXPECT_EQ(response->getOperationCode(), OperationCode::FinalizeTransaction);
        EXPECT_EQ(response->getStatus(), Status::Success);
    };

    auto checkNotification = [](std::shared_ptr<INotificationData> notification) {
        ASSERT_NE(notification, nullptr);

        EXPECT_EQ(notification->getCode(), NotificationCode::AccountBlocked);
    };
    MOCKCallback callback;

    EXPECT_CALL(callback, requestCallback(_)).
        WillOnce(checkRequest).
        WillOnce(checkRequest);

    EXPECT_CALL(callback, responseCallback(_)).
            WillOnce(checkResponse).
            WillOnce(checkResponse);

    EXPECT_CALL(callback, notificationCallback(_)).
            WillOnce(checkNotification).
            WillOnce(checkNotification);

    EXPECT_CALL(callback, connectedCallback(_)).
            WillOnce(Invoke(receiveConnectionStatusTrueFunc));

    std::function<void(std::shared_ptr<IRequestData>)> callbackRequest = [&callback](std::shared_ptr<IRequestData> data) {
        callback.requestCallback(data);
    };

    std::function<void(std::shared_ptr<IResponseData>)> callbackResponse = [&callback](std::shared_ptr<IResponseData> data) {
        callback.responseCallback(data);
    };

    std::function<void(std::shared_ptr<INotificationData>)> callbackNotification = [&callback](std::shared_ptr<INotificationData> data) {
        callback.notificationCallback(data);
    };

    std::function<void(bool)> callbackConnection = [&callback](bool connected) {
        callback.connectedCallback(connected);
    };

    Lan4Gate gate;

    gate.setCommunication(comms);
    gate.setCallbackNotificationType(Lanter::Manager::ILan4Gate::CallbackNotificationType::Sync);

    gate.addRequestCallback(callbackRequest);
    gate.addResponseCallback(callbackResponse);
    gate.addNotificationCallback(callbackNotification);
    gate.addConnectionCallback(callbackConnection);
    EXPECT_EQ(gate.start(), ILan4Gate::Status::Success);

    //100 циклов библиотеки
    for(int i = 0; i < 100; i++) {
        EXPECT_NO_THROW(gate.doLan4Gate());
    }

    EXPECT_EQ(gate.stop(), ILan4Gate::Status::Success);
}
