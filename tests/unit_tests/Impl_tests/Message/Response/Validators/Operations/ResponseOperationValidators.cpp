#include "gtest/gtest.h"

#include "Lanter/Message/Response/Validators/ValidatorFactory.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;

//Refund
TEST(ResponseOperationValidators, CheckRefund) {
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

TEST(ResponseOperationValidators, CheckRefundWithoutRRN) {
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
TEST(ResponseOperationValidators, CheckAliPay) {
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

TEST(ResponseOperationValidators, CheckFastTrack) {
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

TEST(ResponseOperationValidators, CheckMOTO) {
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

TEST(ResponseOperationValidators, CheckPreAuth) {
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

TEST(ResponseOperationValidators, CheckQuickPayment) {
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

TEST(ResponseOperationValidators, CheckQuickPaymentStatus) {
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

TEST(ResponseOperationValidators, CheckSale) {
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

TEST(ResponseOperationValidators, CheckSalesCompletion) {
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
TEST(ResponseOperationValidators, CheckVoid) {
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

TEST(ResponseOperationValidators, CheckVoidPartialSale) {
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

TEST(ResponseOperationValidators, CheckVoidPreAuth) {
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

TEST(ResponseOperationValidators, CheckDisplayQR) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::DisplayQR);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckFinalizeTransaction) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::FinalizeTransaction);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckGetCurrentPrinter) {
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

TEST(ResponseOperationValidators, CheckGetLastOperation) {
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

TEST(ResponseOperationValidators, CheckGetOperationCopy) {
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

TEST(ResponseOperationValidators, CheckInitialization) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::Initialization);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckKeyDownload) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::KeyDownload);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckPrintCommsInfo) {
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

TEST(ResponseOperationValidators, CheckPrintDetailReport) {
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

TEST(ResponseOperationValidators, CheckPrintLastReceipt) {
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

TEST(ResponseOperationValidators, CheckPrintReceiptCopy) {
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

TEST(ResponseOperationValidators, CheckPrintSoftInfo) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintSoftInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckPrintSummaryReport) {
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

TEST(ResponseOperationValidators, CheckRegistration) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::Registration);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckSelfTest) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::SelfTest);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckSetCurrentPrinter) {
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

TEST(ResponseOperationValidators, CheckSettlement) {
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

TEST(ResponseOperationValidators, CheckTest) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::Test);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckTestCommunication) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::TestCommunication);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckUpdateSW) {
    std::set<ResponseField> fields;

    fields.insert(ResponseField::OperationCode);
    fields.insert(ResponseField::EcrNumber);
    fields.insert(ResponseField::Status);

    auto validator = ValidatorFactory::getValidator(OperationCode::UpdateSW);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}