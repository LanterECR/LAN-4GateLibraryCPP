#include "gtest/gtest.h"

#include "Lanter/Message/Response/Validators/ValidatorFactory.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;

//Refund
TEST(TestResponseOperationValidators, CheckRefund) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);
    fields.insert(ResponseField::CardDataEnc);
    fields.insert(ResponseField::TVR);
    fields.insert(ResponseField::TSI);
    fields.insert(ResponseField::TC);
    fields.insert(ResponseField::CID);
    fields.insert(ResponseField::KVR);
    fields.insert(ResponseField::CDAResult);
    fields.insert(ResponseField::CardholderName);
    fields.insert(ResponseField::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(OperationCode::Refund);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckRefundWithoutRRN) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);
    fields.insert(ResponseField::CardDataEnc);
    fields.insert(ResponseField::TVR);
    fields.insert(ResponseField::TSI);
    fields.insert(ResponseField::TC);
    fields.insert(ResponseField::CID);
    fields.insert(ResponseField::KVR);
    fields.insert(ResponseField::CDAResult);
    fields.insert(ResponseField::CardholderName);
    fields.insert(ResponseField::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(OperationCode::RefundWithoutRRN);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Sales
TEST(TestResponseOperationValidators, CheckAliPay) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::AcquirerFeeAmount);
    fields.insert(ResponseField::TerminalFeeAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);

    auto validator = ValidatorFactory::getValidator(OperationCode::AliPay);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckFastTrack) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::TerminalFeeAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);
    fields.insert(ResponseField::CardData);
    fields.insert(ResponseField::CardDataEnc);
    fields.insert(ResponseField::CardholderName);
    fields.insert(ResponseField::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(OperationCode::FastTrack);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckMOTO) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);
    fields.insert(ResponseField::CardDataEnc);
    fields.insert(ResponseField::CardholderName);
    fields.insert(ResponseField::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(OperationCode::MOTO);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckPreAuth) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);
    fields.insert(ResponseField::CardDataEnc);
    fields.insert(ResponseField::TVR);
    fields.insert(ResponseField::TSI);
    fields.insert(ResponseField::TC);
    fields.insert(ResponseField::CID);
    fields.insert(ResponseField::KVR);
    fields.insert(ResponseField::CDAResult);
    fields.insert(ResponseField::CardholderName);
    fields.insert(ResponseField::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(OperationCode::PreAuth);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckQuickPayment) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::AcquirerFeeAmount);
    fields.insert(ResponseField::TerminalFeeAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);

    auto validator = ValidatorFactory::getValidator(OperationCode::QuickPayment);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckQuickPaymentStatus) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::QuickPaymentStatus);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    //EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckSale) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);
    fields.insert(ResponseField::CardDataEnc);
    fields.insert(ResponseField::TVR);
    fields.insert(ResponseField::TSI);
    fields.insert(ResponseField::TC);
    fields.insert(ResponseField::CID);
    fields.insert(ResponseField::KVR);
    fields.insert(ResponseField::CDAResult);
    fields.insert(ResponseField::CardholderName);
    fields.insert(ResponseField::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(OperationCode::Sale);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckSalesCompletion) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);
    fields.insert(ResponseField::CardDataEnc);
    fields.insert(ResponseField::TVR);
    fields.insert(ResponseField::TSI);
    fields.insert(ResponseField::TC);
    fields.insert(ResponseField::CID);
    fields.insert(ResponseField::KVR);
    fields.insert(ResponseField::CDAResult);
    fields.insert(ResponseField::CardholderName);
    fields.insert(ResponseField::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(OperationCode::SalesCompletion);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Void
TEST(TestResponseOperationValidators, CheckVoid) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);
    fields.insert(ResponseField::CardDataEnc);
    fields.insert(ResponseField::TVR);
    fields.insert(ResponseField::TSI);
    fields.insert(ResponseField::TC);
    fields.insert(ResponseField::CID);
    fields.insert(ResponseField::KVR);
    fields.insert(ResponseField::CDAResult);
    fields.insert(ResponseField::CardholderName);
    fields.insert(ResponseField::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(OperationCode::Void);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckVoidPartialSale) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::PartialAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);
    fields.insert(ResponseField::CardDataEnc);
    fields.insert(ResponseField::TVR);
    fields.insert(ResponseField::TSI);
    fields.insert(ResponseField::TC);
    fields.insert(ResponseField::CID);
    fields.insert(ResponseField::KVR);
    fields.insert(ResponseField::CDAResult);
    fields.insert(ResponseField::CardholderName);
    fields.insert(ResponseField::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(OperationCode::VoidPartialSale);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckVoidPreAuth) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::PartialAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::TransactionID);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);
    fields.insert(ResponseField::CardDataEnc);
    fields.insert(ResponseField::TVR);
    fields.insert(ResponseField::TSI);
    fields.insert(ResponseField::TC);
    fields.insert(ResponseField::CID);
    fields.insert(ResponseField::KVR);
    fields.insert(ResponseField::CDAResult);
    fields.insert(ResponseField::CardholderName);
    fields.insert(ResponseField::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(OperationCode::VoidPreAuth);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Service

TEST(TestResponseOperationValidators, CheckDisplayQR) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::DisplayQR);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckFinalizeTransaction) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::FinalizeTransaction);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckGetCurrentPrinter) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::AdditionalInfo);

    auto validator = ValidatorFactory::getValidator(OperationCode::GetCurrentPrinter);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckGetLastOperation) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::GetLastOperation);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckGetOperationCopy) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::ReceiptReference);
    auto validator = ValidatorFactory::getValidator(OperationCode::GetOperationCopy);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckInitialization) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::Initialization);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckKeyDownload) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::KeyDownload);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckPrintCommsInfo) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::AdditionalInfo);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintCommsInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckPrintDetailReport) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::TerminalID);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::SaleCount);
    fields.insert(ResponseField::VoidCount);
    fields.insert(ResponseField::RefundCount);
    fields.insert(ResponseField::SaleArray);
    fields.insert(ResponseField::VoidArray);
    fields.insert(ResponseField::RefundArray);
    auto validator = ValidatorFactory::getValidator(OperationCode::PrintDetailReport);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckPrintLastReceipt) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintLastReceipt);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckPrintReceiptCopy) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintReceiptCopy);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckPrintSoftInfo) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintSoftInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckPrintSummaryReport) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintSummaryReport);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckRegistration) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::Registration);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckSelfTest) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::SelfTest);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckSetCurrentPrinter) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::SetCurrentPrinter);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckSettlement) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::Settlement);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckTest) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::Test);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckTestCommunication) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::TestCommunication);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckUpdateSW) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::UpdateSW);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckSendLogs) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::SendLogs);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckSetLogLevel) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::SetLogLevel);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckLicenseActivationFile) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::LicenseActivationFile);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckLicenseActivationServer) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::LicenseActivationServer);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckClearReversal) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::ClearReversal);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckClearAllJournals) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::ClearAllJournals);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckTakeLockCard) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::TakeLockCard);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckEjectCard) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::EjectCard);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckEjectWaitCard) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::EjectWaitCard);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckIsCardPresent) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    fields.insert(ResponseField::AdditionalInfo);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::ExpireDate);

    auto validator = ValidatorFactory::getValidator(OperationCode::IsCardPresent);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckUploadPending) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::EcrMerchantNumber);
    fields.insert(ResponseField::OriginalOperationCode);
    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::CardholderAuthMethod);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::RRN);

    auto validator = ValidatorFactory::getValidator(OperationCode::UploadPending);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckBonusBalance) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    fields.insert(ResponseField::TotalAmount);
    fields.insert(ResponseField::CurrencyCode);
    fields.insert(ResponseField::MerchantID);
    fields.insert(ResponseField::IssuerName);
    fields.insert(ResponseField::CardPAN);
    fields.insert(ResponseField::CardholderAuthMethod);
    fields.insert(ResponseField::ReceiptReference);
    fields.insert(ResponseField::ResponseCode);
    fields.insert(ResponseField::RRN);
    fields.insert(ResponseField::AcquirerFeeAmount);
    fields.insert(ResponseField::TerminalFeeAmount);
    fields.insert(ResponseField::ResponseText);
    fields.insert(ResponseField::AuthCode);
    fields.insert(ResponseField::TransDateTime);
    fields.insert(ResponseField::TerminalDateTime);
    fields.insert(ResponseField::CardInputMethod);
    fields.insert(ResponseField::ExpireDate);
    fields.insert(ResponseField::CardAppName);
    fields.insert(ResponseField::CardEmvAid);

    auto validator = ValidatorFactory::getValidator(OperationCode::BonusBalance);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestResponseOperationValidators, CheckGrabEjectCard) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::GrabEjectCard);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}