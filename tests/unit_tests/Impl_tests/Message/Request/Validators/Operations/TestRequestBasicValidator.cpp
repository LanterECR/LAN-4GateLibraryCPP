#include "gtest/gtest.h"
#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

using namespace Lanter::Message;
using namespace Lanter::Message::Request;

TEST(TestRequestBasicValidator, CheckAppendMandatory) {
    BasicValidator validator;

    EXPECT_FALSE(validator.getMandatoryFields().empty());
    EXPECT_NE(validator.getMandatoryFields().find(RequestField::EcrNumber), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(RequestField::OperationCode), validator.getMandatoryFields().end());

    auto lessMinimum = (RequestField)((int)RequestField::FirstValue - 1);
    auto greatMaximum = (RequestField)((int)RequestField::LastValue + 1);
    EXPECT_THROW(validator.appendMandatoryField(lessMinimum), std::invalid_argument);
    EXPECT_THROW(validator.appendMandatoryField(greatMaximum), std::invalid_argument);

    EXPECT_NO_THROW(validator.appendMandatoryField(RequestField::EcrMerchantNumber));
    EXPECT_NO_THROW(validator.appendMandatoryField(RequestField::CurrencyCode));

    EXPECT_FALSE(validator.getMandatoryFields().empty());
    EXPECT_EQ(validator.getMandatoryFields().size(), 4);

    EXPECT_NE(validator.getMandatoryFields().find(RequestField::EcrMerchantNumber), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(RequestField::CurrencyCode), validator.getMandatoryFields().end());
}

TEST(TestRequestBasicValidator, CheckAppendOptional) {
    BasicValidator validator;

    EXPECT_TRUE(validator.getOptionalFields().empty());

    auto lessMinimum = (RequestField)((int)RequestField::FirstValue - 1);
    auto greatMaximum = (RequestField)((int)RequestField::LastValue + 1);
    EXPECT_THROW(validator.appendOptionalField(lessMinimum), std::invalid_argument);
    EXPECT_THROW(validator.appendOptionalField(greatMaximum), std::invalid_argument);

    EXPECT_NO_THROW(validator.appendOptionalField(RequestField::FirstValue));
    EXPECT_NO_THROW(validator.appendOptionalField(RequestField::LastValue));

    EXPECT_FALSE(validator.getOptionalFields().empty());
    EXPECT_EQ(validator.getOptionalFields().size(), 2);

    EXPECT_NE(validator.getOptionalFields().find(RequestField::FirstValue), validator.getOptionalFields().end());
    EXPECT_NE(validator.getOptionalFields().find(RequestField::LastValue), validator.getOptionalFields().end());
}

TEST(TestRequestBasicValidator, CheckValidateEmptyMandatory) {
    BasicValidator validator;

    std::set<RequestField> fields;
    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    EXPECT_TRUE(validator.validate(fields));
}

TEST(TestRequestBasicValidator, CheckValidateOneMandatory) {
    BasicValidator validator;
    validator.appendMandatoryField(RequestField::FirstValue);

    std::set<RequestField> fields;
    fields.insert(RequestField::FirstValue);
    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    EXPECT_TRUE(validator.validate(fields));
}

TEST(TestRequestBasicValidator, CheckValidateAllFields) {
    BasicValidator validator;
    auto first = (int)RequestField::FirstValue;
    auto last = (int)RequestField::LastValue;

    for(auto i = first; i <= last; i++){
        EXPECT_NO_THROW(validator.appendMandatoryField((RequestField)i));
    }

    validator.appendMandatoryField(RequestField::FirstValue);

    std::set<RequestField> twoFields;
    twoFields.insert(RequestField::FirstValue);
    twoFields.insert(RequestField::LastValue);
    twoFields.insert(RequestField::OperationCode);
    twoFields.insert(RequestField::EcrNumber);

    EXPECT_FALSE(validator.validate(twoFields));

    std::set<RequestField> allFields;
    for(auto i = first; i <= last; i++){
        allFields.insert((RequestField)i);
    }

    EXPECT_TRUE(validator.validate(allFields));
}

TEST(TestRequestBasicValidator, CheckOptional) {
    BasicValidator validator;
    validator.appendOptionalField(RequestField::FirstValue);

    std::set<RequestField> fields;
    fields.insert(RequestField::FirstValue);
    fields.insert(RequestField::LastValue);
    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    EXPECT_TRUE(validator.validate(fields));
}