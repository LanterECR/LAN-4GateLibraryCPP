//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "gtest/gtest.h"
#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

using namespace Lanter::Message;
using namespace Lanter::Message::Response;
TEST(ResponseBasicValidator, CheckAppendMandatory) {
    BasicValidator validator;

    EXPECT_FALSE(validator.getMandatoryFields().empty());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseFields::EcrNumber), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseFields::OperationCode), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseFields::Status), validator.getMandatoryFields().end());

    auto lessMinimum = (ResponseFields)((int)ResponseFields::FirstValue - 1);
    auto greatMaximum = (ResponseFields)((int)ResponseFields::LastValue + 1);
    EXPECT_THROW(validator.appendMandatoryField(lessMinimum), std::invalid_argument);
    EXPECT_THROW(validator.appendMandatoryField(greatMaximum), std::invalid_argument);

    EXPECT_NO_THROW(validator.appendMandatoryField(ResponseFields::EcrMerchantNumber));
    EXPECT_NO_THROW(validator.appendMandatoryField(ResponseFields::CurrencyCode));

    EXPECT_FALSE(validator.getMandatoryFields().empty());
    EXPECT_EQ(validator.getMandatoryFields().size(), 5);

    EXPECT_NE(validator.getMandatoryFields().find(ResponseFields::EcrMerchantNumber), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseFields::CurrencyCode), validator.getMandatoryFields().end());
}

TEST(ResponseBasicValidator, CheckAppendOptional) {
    BasicValidator validator;

    EXPECT_TRUE(validator.getOptionalFields().empty());

    auto lessMinimum = (ResponseFields)((int)ResponseFields::FirstValue - 1);
    auto greatMaximum = (ResponseFields)((int)ResponseFields::LastValue + 1);
    EXPECT_THROW(validator.appendOptionalField(lessMinimum), std::invalid_argument);
    EXPECT_THROW(validator.appendOptionalField(greatMaximum), std::invalid_argument);

    EXPECT_NO_THROW(validator.appendOptionalField(ResponseFields::FirstValue));
    EXPECT_NO_THROW(validator.appendOptionalField(ResponseFields::LastValue));

    EXPECT_FALSE(validator.getOptionalFields().empty());
    EXPECT_EQ(validator.getOptionalFields().size(), 2);

    EXPECT_NE(validator.getOptionalFields().find(ResponseFields::FirstValue), validator.getOptionalFields().end());
    EXPECT_NE(validator.getOptionalFields().find(ResponseFields::LastValue), validator.getOptionalFields().end());
}

TEST(ResponseBasicValidator, CheckValidateEmptyMandatory) {
    BasicValidator validator;

    std::set<ResponseFields> fields;
    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    EXPECT_TRUE(validator.validate(fields));
}

TEST(ResponseBasicValidator, CheckValidateOneMandatory) {
    BasicValidator validator;
    validator.appendMandatoryField(ResponseFields::FirstValue);

    std::set<ResponseFields> fields;
    fields.insert(ResponseFields::FirstValue);
    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    EXPECT_TRUE(validator.validate(fields));
}

TEST(ResponseBasicValidator, CheckValidateAllFields) {
    BasicValidator validator;
    auto first = (int)ResponseFields::FirstValue;
    auto last = (int)ResponseFields::LastValue;

    for(auto i = first; i <= last; i++){
        EXPECT_NO_THROW(validator.appendMandatoryField((ResponseFields)i));
    }

    validator.appendMandatoryField(ResponseFields::FirstValue);

    std::set<ResponseFields> twoFields;
    twoFields.insert(ResponseFields::FirstValue);
    twoFields.insert(ResponseFields::LastValue);

    twoFields.insert(ResponseFields::OperationCode);
    twoFields.insert(ResponseFields::EcrNumber);
    twoFields.insert(ResponseFields::Status);


    EXPECT_FALSE(validator.validate(twoFields));

    std::set<ResponseFields> allFields;
    for(auto i = first; i <= last; i++){
        allFields.insert((ResponseFields)i);
    }

    EXPECT_TRUE(validator.validate(allFields));
}

TEST(ResponseBasicValidator, CheckOptional) {
    BasicValidator validator;
    validator.appendOptionalField(ResponseFields::FirstValue);

    std::set<ResponseFields> fields;
    fields.insert(ResponseFields::FirstValue);
    fields.insert(ResponseFields::LastValue);
    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    EXPECT_TRUE(validator.validate(fields));
}