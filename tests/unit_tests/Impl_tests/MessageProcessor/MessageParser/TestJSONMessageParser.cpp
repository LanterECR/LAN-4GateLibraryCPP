#include <algorithm>

#include "gtest/gtest.h"

#include "Lanter/MessageProcessor/Builder/JSONAddFieldHelper.h"
#include "Lanter/MessageProcessor/Parser/JSONMessageParser.h"
#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/Utils/Constants.h"

#include "Lanter/Utils/StringConverter.h"

using namespace Lanter;
using namespace Lanter::MessageProcessor;
using namespace Lanter::Utils;
using namespace Lanter::Utils::Constants;
using namespace Lanter::MessageProcessor::Parser;
using namespace Lanter::MessageProcessor::Builder;

TEST(TestJSONMessageParser, CheckReadMessage) {
    std::string junkValue = "JUNK";

    std::string jsonValue = R"({"field":"value"})";

    Json::Value root;

    EXPECT_FALSE(JSONMessageParser::readMessage(junkValue, root));
    EXPECT_TRUE(JSONMessageParser::readMessage(jsonValue, root));

    auto members = root.getMemberNames();
    EXPECT_NE(std::find(members.begin(), members.end(), "field"), members.end());

    EXPECT_TRUE(root["field"].isString());

    EXPECT_STREQ(root["field"].asString().c_str(), "value");
}

TEST(TestJSONMessageParser, CheckError) {
    Json::Value root;

    std::vector<uint8_t> data = {'J', 'U', 'N', 'N', 'K'};
    JSONMessageParser parser;


    EXPECT_EQ(parser.parseMessage(data), MessageType::Error);
}
TEST(TestJSONMessageParser, CheckRequest) {
    Json::Value root;
    std::vector<uint8_t> data;
    JSONMessageParser parser;

    auto ecrNumber = MAXIMUM_ECR_NUMBER;
    auto operationCode = OperationCode::Sale;
    auto ecrMerchantNumber = MAXIMUM_ECR_MERCHANT_NUMBER;
    auto amount = MAXIMUM_AMOUNT;
    auto currencyCode = MAXIMUM_CURRENCY_CODE;

    AddFieldsHelper::addField(root, JSONRootFields::getClassField(), JSONClassFieldValues::getRequestValue());

    Json::Value object;

    AddFieldsHelper::addField(object, JSONRequestFields::getEcrNumber(), ecrNumber);
    AddFieldsHelper::addField(object, JSONRequestFields::getOperationCode(), (int)operationCode);
    AddFieldsHelper::addField(object, JSONRequestFields::getEcrMerchantNumber(), ecrMerchantNumber);
    AddFieldsHelper::addField(object, JSONRequestFields::getAmount(), amount);
    AddFieldsHelper::addField(object, JSONRequestFields::getCurrencyCode(), std::to_string(currencyCode));

    AddFieldsHelper::addField(root, JSONRootFields::getObjectField(), object);

    //TODO заменить на актуальный writer
    Json::FastWriter writer;

    StringConverter::convertToVector(writer.write(root), data);

    EXPECT_EQ(parser.parseMessage(data), MessageType::Request);
    EXPECT_EQ(parser.requestCount(), 1);

    EXPECT_EQ(parser.parseMessage(data), MessageType::Request);
    EXPECT_EQ(parser.requestCount(), 2);

    EXPECT_NE(parser.nextRequestData(), nullptr);
    EXPECT_EQ(parser.requestCount(), 1);

    EXPECT_NE(parser.nextRequestData(), nullptr);
    EXPECT_EQ(parser.requestCount(), 0);

    EXPECT_EQ(parser.nextRequestData(), nullptr);
    EXPECT_EQ(parser.requestCount(), 0);
}

TEST(TestJSONMessageParser, CheckResponse) {
    Json::Value root;
    std::vector<uint8_t> data;
    JSONMessageParser parser;

    auto ecrNumber = MAXIMUM_ECR_NUMBER;
    auto operationCode = OperationCode::Sale;
    auto ecrMerchantNumber = MAXIMUM_ECR_MERCHANT_NUMBER;
    auto status = Status::Success;
    auto totalAmount = MAXIMUM_AMOUNT;
    auto currencyCode = MAXIMUM_CURRENCY_CODE;
    std::string stringValue = "Значение";
    auto cardInputMethod = CardInputMethod::ChipFullGrade;
    auto cardholderAuthMethod = CardholderAuthMethod::PaperSignatureVerification;

    AddFieldsHelper::addField(root, JSONRootFields::getClassField(), JSONClassFieldValues::getResponseValue());

    Json::Value object;

    AddFieldsHelper::addField(object, JSONResponseFields::getEcrNumber(), ecrNumber);
    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), (int)operationCode);
    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), (int)status);
    AddFieldsHelper::addField(object, JSONResponseFields::getEcrMerchantNumber(), ecrMerchantNumber);
    AddFieldsHelper::addField(object, JSONResponseFields::getTotalAmount(), totalAmount);
    AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(), std::to_string(currencyCode));
    AddFieldsHelper::addField(object, JSONResponseFields::getRRN(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptReference(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getTransactionID(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getAuthCode(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getResponseCode(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getResponseText(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalID(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getMerchantID(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getTransDateTime(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalDateTime(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getIssuerName(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(), (int)cardInputMethod);
    AddFieldsHelper::addField(object, JSONResponseFields::getCardPAN(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getExpireDate(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getCardAppName(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getCardEmvAid(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getCardDataEnc(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getTVR(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getTSI(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getTC(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getCID(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getKVR(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getCDAResult(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderName(), stringValue);
    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderAuthMethod(), (int)cardholderAuthMethod);

    AddFieldsHelper::addField(root, JSONRootFields::getObjectField(), object);

    //TODO заменить на актуальный writer
    Json::FastWriter writer;

    StringConverter::convertToVector(writer.write(root), data);

    EXPECT_EQ(parser.parseMessage(data), MessageType::Response);
    EXPECT_EQ(parser.responseCount(), 1);

    EXPECT_EQ(parser.parseMessage(data), MessageType::Response);
    EXPECT_EQ(parser.responseCount(), 2);

    EXPECT_NE(parser.nextResponseData(), nullptr);
    EXPECT_EQ(parser.responseCount(), 1);

    EXPECT_NE(parser.nextResponseData(), nullptr);
    EXPECT_EQ(parser.responseCount(), 0);

    EXPECT_EQ(parser.nextResponseData(), nullptr);
    EXPECT_EQ(parser.responseCount(), 0);
}

TEST(TestJSONMessageParser, CheckNotification) {
    Json::Value root;

    std::vector<uint8_t> data;
    JSONMessageParser parser;

    AddFieldsHelper::addField(root, JSONRootFields::getClassField(), JSONClassFieldValues::getNotificationValue());

    std::string value = "Значение";

    Json::Value object;
    AddFieldsHelper::addField(object, JSONNotificationFields::getCode(), (int)NotificationCode::FirstValue);
    AddFieldsHelper::addField(object, JSONNotificationFields::getAdditional(),  value);
    AddFieldsHelper::addField(object, JSONNotificationFields::getMessage(),  value);

    AddFieldsHelper::addField(root, JSONRootFields::getObjectField(), object);

    //TODO заменить на актуальный writer
    Json::FastWriter writer;

    StringConverter::convertToVector(writer.write(root), data);

    EXPECT_EQ(parser.parseMessage(data), MessageType::Notification);
    EXPECT_EQ(parser.notificationCount(), 1);

    EXPECT_EQ(parser.parseMessage(data), MessageType::Notification);
    EXPECT_EQ(parser.notificationCount(), 2);



    EXPECT_NE(parser.nextNotificationData(), nullptr);
    EXPECT_EQ(parser.notificationCount(), 1);

    EXPECT_NE(parser.nextNotificationData(), nullptr);
    EXPECT_EQ(parser.notificationCount(), 0);

    EXPECT_EQ(parser.nextNotificationData(), nullptr);
    EXPECT_EQ(parser.notificationCount(), 0);
}

TEST(TestJSONMessageParser, CheckInteraction) {
    Json::Value root;

    std::vector<uint8_t> data;
    JSONMessageParser parser;

    AddFieldsHelper::addField(root, JSONRootFields::getClassField(), JSONClassFieldValues::getInteractionValue());

    Json::Value object;
    AddFieldsHelper::addField(object, JSONInteractionFields::getCode(), (int)InteractionCode::FirstValue);

    AddFieldsHelper::addField(root, JSONRootFields::getObjectField(), object);

    //TODO заменить на актуальный writer
    Json::FastWriter writer;

    StringConverter::convertToVector(writer.write(root), data);

    EXPECT_EQ(parser.parseMessage(data), MessageType::Interaction);
    EXPECT_EQ(parser.interactionCount(), 1);

    EXPECT_EQ(parser.parseMessage(data), MessageType::Interaction);
    EXPECT_EQ(parser.interactionCount(), 2);



    EXPECT_NE(parser.nextInteractionData(), nullptr);
    EXPECT_EQ(parser.interactionCount(), 1);

    EXPECT_NE(parser.nextInteractionData(), nullptr);
    EXPECT_EQ(parser.interactionCount(), 0);

    EXPECT_EQ(parser.nextInteractionData(), nullptr);
    EXPECT_EQ(parser.interactionCount(), 0);
}