//
// Created by Владимир Лысенков on 12.07.2020.//

#include "gtest/gtest.h"

#include "Lanter/Message/Request/RequestDataFactory.h"
#include <Lanter/Message/Response/ResponseDataFactory.h>
#include <Lanter/Message/Notification/NotificationDataFactory.h>

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/MessageProcessor/MessageBuilder/JSONMessageBuilder.h"
#include "Lanter/Utils/StringConverter.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;
using namespace Lanter::Message::Response;
using namespace Lanter::Message::Notification;
using namespace Lanter::MessageProcessor;

TEST(JSONMessageBuilder, CheckCreateRequestMessage) {
    std::vector<unsigned char> message;

    JSONMessageBuilder builder;

    auto data = RequestDataFactory::getRequestData(OperationCode::Sale, 1);
    data->setEcrMerchantNumber(1);
    data->setAmount(100);
    data->setCurrencyCode(643);

    EXPECT_TRUE(builder.createMessage(data, message));

    EXPECT_FALSE(message.empty());

    std::string stringMsg;

    Utils::StringConverter::convertToString(message, stringMsg);

    EXPECT_NE(stringMsg.find(JSONClassFieldValues::getRequestValue()), std::string::npos);
}

TEST(JSONMessageBuilder, CheckCreateResponseMessage) {
    std::vector<unsigned char> message;

    JSONMessageBuilder builder;

    auto data = ResponseDataFactory::getResponseData(OperationCode::Sale, 1);

    data->setStatus(Lanter::Message::Response::Status::Success);
    data->setEcrMerchantNumber(1);
    data->setTotalAmount(100);
    data->setCurrencyCode(643);
    data->setRRN("123");
    data->setReceiptReference("123");
    data->setTransactionID("123");
    data->setAuthCode("123");
    data->setResponseCode("123");
    data->setResponseText("123");
    data->setTerminalID("123");
    data->setMerchantID("123");
    data->setTransDateTime("123");
    data->setTerminalDateTime("123");
    data->setIssuerName("123");
    data->setCardInputMethod(Lanter::Message::Response::CardInputMethod::ChipFullGrade);
    data->setCardPAN("123");
    data->setExpireDate("123");
    data->setCardAppName("123");
    data->setCardEmvAid("123");
    data->setCardDataEnc("123");
    data->setTVR("123");
    data->setTSI("123");
    data->setTC("123");
    data->setCID("123");
    data->setKVR("123");
    data->setCDAResult("123");
    data->setCardholderName("123");
    data->setCardholderAuthMethod(Lanter::Message::Response::CardholderAuthMethod::PaperSignatureVerification);

    EXPECT_TRUE(builder.createMessage(data, message));

    EXPECT_FALSE(message.empty());

    std::string stringMsg;

    Utils::StringConverter::convertToString(message, stringMsg);

    EXPECT_NE(stringMsg.find(JSONClassFieldValues::getResponseValue()), std::string::npos);
}

TEST(JSONMessageBuilder, CheckCreateNotificationMessage) {
    std::vector<unsigned char> message;

    JSONMessageBuilder builder;

    auto data = NotificationDataFactory::getNotificationData();
    data->setCode(Lanter::Message::Notification::NotificationCode::InsertCard);
    data->setAdditional("123");
    data->setMessage("123");

    EXPECT_TRUE(builder.createMessage(data, message));

    EXPECT_FALSE(message.empty());

    std::string stringMsg;

    Utils::StringConverter::convertToString(message, stringMsg);

    EXPECT_NE(stringMsg.find(JSONClassFieldValues::getNotificationValue()), std::string::npos);
}