#include "gtest/gtest.h"
#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

using namespace Lanter::Message;
using namespace Lanter::Message::Response;
TEST(TestResponseBasicValidator, CheckAppendMandatory) {
    BasicValidator validator;

    EXPECT_FALSE(validator.getMandatoryFields().empty());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseField::EcrNumber), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseField::OperationCode), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseField::Status), validator.getMandatoryFields().end());

    auto lessMinimum = (ResponseField)((int)getFirstResponseField() - 1);
    auto greatMaximum = (ResponseField)((int)getLastResponseField() + 1);
    EXPECT_THROW(validator.appendMandatoryField(lessMinimum), std::invalid_argument);
    EXPECT_THROW(validator.appendMandatoryField(greatMaximum), std::invalid_argument);

    EXPECT_NO_THROW(validator.appendMandatoryField(ResponseField::EcrMerchantNumber));
    EXPECT_NO_THROW(validator.appendMandatoryField(ResponseField::CurrencyCode));

    EXPECT_FALSE(validator.getMandatoryFields().empty());
    EXPECT_EQ(validator.getMandatoryFields().size(), 5);

    EXPECT_NE(validator.getMandatoryFields().find(ResponseField::EcrMerchantNumber), validator.getMandatoryFields().end());
    EXPECT_NE(validator.getMandatoryFields().find(ResponseField::CurrencyCode), validator.getMandatoryFields().end());
}

TEST(TestResponseBasicValidator, CheckAppendOptional) {
    BasicValidator validator;

    auto size = validator.getOptionalFields().size();
    EXPECT_FALSE(validator.getOptionalFields().empty());

    auto lessMinimum = (ResponseField)((int)getFirstResponseField() - 1);
    auto greatMaximum = (ResponseField)((int)getLastResponseField() + 1);
    EXPECT_THROW(validator.appendOptionalField(lessMinimum), std::invalid_argument);
    EXPECT_THROW(validator.appendOptionalField(greatMaximum), std::invalid_argument);

    EXPECT_NO_THROW(validator.appendOptionalField(getFirstResponseField()));
    EXPECT_NO_THROW(validator.appendOptionalField(getLastResponseField()));

    EXPECT_FALSE(validator.getOptionalFields().empty());
    EXPECT_GE(validator.getOptionalFields().size(), size);

    EXPECT_NE(validator.getOptionalFields().find(getFirstResponseField()), validator.getOptionalFields().end());
    EXPECT_NE(validator.getOptionalFields().find(getLastResponseField()), validator.getOptionalFields().end());
}

TEST(TestResponseBasicValidator, CheckValidateEmptyMandatory) {
    BasicValidator validator;

    std::set<ResponseField> fields;
    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    EXPECT_TRUE(validator.validate(fields));
}

TEST(TestResponseBasicValidator, CheckValidateOneMandatory) {
    BasicValidator validator;
    validator.appendMandatoryField(getFirstResponseField());

    std::set<ResponseField> fields;
    fields.insert(getFirstResponseField());
    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    EXPECT_TRUE(validator.validate(fields));
}

TEST(TestResponseBasicValidator, CheckValidateAllFields) {
    BasicValidator validator;
    auto first = (int)getFirstResponseField();
    auto last = (int)getLastResponseField();

    for(auto i = first; i <= last; i++){
        EXPECT_NO_THROW(validator.appendMandatoryField((ResponseField)i));
    }

    validator.appendMandatoryField(getFirstResponseField());

    std::set<ResponseField> twoFields;
    twoFields.insert(getFirstResponseField());
    twoFields.insert(getLastResponseField());

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

TEST(TestResponseBasicValidator, CheckOptional) {
    BasicValidator validator;
    validator.appendOptionalField(getFirstResponseField());

    std::set<ResponseField> fields;
    fields.insert(getFirstResponseField());
    fields.insert(getLastResponseField());
    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    EXPECT_TRUE(validator.validate(fields));
}