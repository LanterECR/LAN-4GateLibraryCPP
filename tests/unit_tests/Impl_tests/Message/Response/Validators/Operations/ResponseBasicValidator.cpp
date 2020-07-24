#include "gtest/gtest.h"
#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

using namespace Lanter::Message;
using namespace Lanter::Message::Response;
TEST(ResponseBasicValidator, CheckAppendMandatory) {
    BasicValidator validator;

    EXPECT_FALSE(validator.getMandatoryFields().empty());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseField::EcrNumber), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseField::OperationCode), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseField::Status), validator.getMandatoryFields().end());

    auto lessMinimum = (ResponseField)((int)ResponseField::FirstValue - 1);
    auto greatMaximum = (ResponseField)((int)ResponseField::LastValue + 1);
    EXPECT_THROW(validator.appendMandatoryField(lessMinimum), std::invalid_argument);
    EXPECT_THROW(validator.appendMandatoryField(greatMaximum), std::invalid_argument);

    EXPECT_NO_THROW(validator.appendMandatoryField(ResponseField::EcrMerchantNumber));
    EXPECT_NO_THROW(validator.appendMandatoryField(ResponseField::CurrencyCode));

    EXPECT_FALSE(validator.getMandatoryFields().empty());
    EXPECT_EQ(validator.getMandatoryFields().size(), 5);

    EXPECT_NE(validator.getMandatoryFields().find(ResponseField::EcrMerchantNumber), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseField::CurrencyCode), validator.getMandatoryFields().end());
}

TEST(ResponseBasicValidator, CheckAppendOptional) {
    BasicValidator validator;

    EXPECT_TRUE(validator.getOptionalFields().empty());

    auto lessMinimum = (ResponseField)((int)ResponseField::FirstValue - 1);
    auto greatMaximum = (ResponseField)((int)ResponseField::LastValue + 1);
    EXPECT_THROW(validator.appendOptionalField(lessMinimum), std::invalid_argument);
    EXPECT_THROW(validator.appendOptionalField(greatMaximum), std::invalid_argument);

    EXPECT_NO_THROW(validator.appendOptionalField(ResponseField::FirstValue));
    EXPECT_NO_THROW(validator.appendOptionalField(ResponseField::LastValue));

    EXPECT_FALSE(validator.getOptionalFields().empty());
    EXPECT_EQ(validator.getOptionalFields().size(), 2);

    EXPECT_NE(validator.getOptionalFields().find(ResponseField::FirstValue), validator.getOptionalFields().end());
    EXPECT_NE(validator.getOptionalFields().find(ResponseField::LastValue), validator.getOptionalFields().end());
}

TEST(ResponseBasicValidator, CheckValidateEmptyMandatory) {
    BasicValidator validator;

    std::set<ResponseField> fields;
    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    EXPECT_TRUE(validator.validate(fields));
}

TEST(ResponseBasicValidator, CheckValidateOneMandatory) {
    BasicValidator validator;
    validator.appendMandatoryField(ResponseField::FirstValue);

    std::set<ResponseField> fields;
    fields.insert(ResponseField::FirstValue);
    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    EXPECT_TRUE(validator.validate(fields));
}

TEST(ResponseBasicValidator, CheckValidateAllFields) {
    BasicValidator validator;
    auto first = (int)ResponseField::FirstValue;
    auto last = (int)ResponseField::LastValue;

    for(auto i = first; i <= last; i++){
        EXPECT_NO_THROW(validator.appendMandatoryField((ResponseField)i));
    }

    validator.appendMandatoryField(ResponseField::FirstValue);

    std::set<ResponseField> twoFields;
    twoFields.insert(ResponseField::FirstValue);
    twoFields.insert(ResponseField::LastValue);

    twoFields.insert(ResponseField::OperationCode);
    twoFields.insert(ResponseField::EcrNumber);
    twoFields.insert(ResponseField::Status);


    EXPECT_FALSE(validator.validate(twoFields));

    std::set<ResponseField> allFields;
    for(auto i = first; i <= last; i++){
        allFields.insert((ResponseField)i);
    }

    EXPECT_TRUE(validator.validate(allFields));
}

TEST(ResponseBasicValidator, CheckOptional) {
    BasicValidator validator;
    validator.appendOptionalField(ResponseField::FirstValue);

    std::set<ResponseField> fields;
    fields.insert(ResponseField::FirstValue);
    fields.insert(ResponseField::LastValue);
    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    EXPECT_TRUE(validator.validate(fields));
}