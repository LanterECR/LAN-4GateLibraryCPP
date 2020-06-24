//
// Created by Владимир Лысенков on 21.06.2020.
//

#include "gtest/gtest.h"
#include "Lanter/Request/Validators/Operations/BasicValidator.h"

using namespace Lanter::Request;
TEST(FieldsValidator, CheckAppendMandatory) {
    BasicValidator validator;

    EXPECT_FALSE(validator.getMandatoryFields().empty());
    EXPECT_NE(validator.getMandatoryFields().find(RequestFields::EcrNumber), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(RequestFields::OperationCode), validator.getMandatoryFields().end());

    auto lessMinimum = (RequestFields)((int)RequestFields::FirstValue - 1);
    auto greatMaximum = (RequestFields)((int)RequestFields::LastValue + 1);
    EXPECT_THROW(validator.appendMandatoryField(lessMinimum), std::invalid_argument);
    EXPECT_THROW(validator.appendMandatoryField(greatMaximum), std::invalid_argument);

    EXPECT_NO_THROW(validator.appendMandatoryField(RequestFields::EcrMerchantNumber));
    EXPECT_NO_THROW(validator.appendMandatoryField(RequestFields::CurrencyCode));

    EXPECT_FALSE(validator.getMandatoryFields().empty());
    EXPECT_EQ(validator.getMandatoryFields().size(), 4);

    EXPECT_NE(validator.getMandatoryFields().find(RequestFields::EcrMerchantNumber), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(RequestFields::CurrencyCode), validator.getMandatoryFields().end());
}

TEST(FieldsValidator, CheckAppendOptional) {
    BasicValidator validator;

    EXPECT_TRUE(validator.getOptionalFields().empty());

    auto lessMinimum = (RequestFields)((int)RequestFields::FirstValue - 1);
    auto greatMaximum = (RequestFields)((int)RequestFields::LastValue + 1);
    EXPECT_THROW(validator.appendOptionalField(lessMinimum), std::invalid_argument);
    EXPECT_THROW(validator.appendOptionalField(greatMaximum), std::invalid_argument);

    EXPECT_NO_THROW(validator.appendOptionalField(RequestFields::FirstValue));
    EXPECT_NO_THROW(validator.appendOptionalField(RequestFields::LastValue));

    EXPECT_FALSE(validator.getOptionalFields().empty());
    EXPECT_EQ(validator.getOptionalFields().size(), 2);

    EXPECT_NE(validator.getOptionalFields().find(RequestFields::FirstValue), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getOptionalFields().find(RequestFields::LastValue), validator.getMandatoryFields().end());
}

TEST(FieldsValidator, CheckValidateEmptyMandatory) {
    BasicValidator validator;

    std::set<RequestFields> fields;
    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    EXPECT_TRUE(validator.validate(fields));
}

TEST(FieldsValidator, CheckValidateOneMandatory) {
    BasicValidator validator;
    validator.appendMandatoryField(RequestFields::FirstValue);

    std::set<RequestFields> fields;
    fields.insert(RequestFields::FirstValue);
    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    EXPECT_TRUE(validator.validate(fields));
}

TEST(FieldsValidator, CheckValidateAllFields) {
    BasicValidator validator;
    auto first = (int)RequestFields::FirstValue;
    auto last = (int)RequestFields::LastValue;

    for(auto i = first; i <= last; i++){
        EXPECT_NO_THROW(validator.appendMandatoryField((RequestFields)i));
    }

    validator.appendMandatoryField(RequestFields::FirstValue);

    std::set<RequestFields> twoFields;
    twoFields.insert(RequestFields::FirstValue);
    twoFields.insert(RequestFields::LastValue);
    twoFields.insert(RequestFields::OperationCode);
    twoFields.insert(RequestFields::EcrNumber);

    EXPECT_FALSE(validator.validate(twoFields));

    std::set<RequestFields> allFields;
    for(auto i = first; i <= last; i++){
        allFields.insert((RequestFields)i);
    }

    EXPECT_TRUE(validator.validate(allFields));
}

TEST(FieldsValidator, CheckOptional) {
    BasicValidator validator;
    validator.appendOptionalField(RequestFields::FirstValue);

    std::set<RequestFields> fields;
    fields.insert(RequestFields::FirstValue);
    fields.insert(RequestFields::LastValue);
    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    EXPECT_TRUE(validator.validate(fields));
}