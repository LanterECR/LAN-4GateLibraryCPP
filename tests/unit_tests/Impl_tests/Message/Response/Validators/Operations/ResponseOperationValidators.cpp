//
// Created by Владимир Лысенков on 30.06.2020.
//

#include "gtest/gtest.h"

#include "Lanter/Message/Response/Validators/ValidatorFactory.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Response;

//Refund
TEST(ResponseOperationValidators, CheckRefund) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::IssuerName);
    fields.insert(ResponseFields::CardInputMethod);
    fields.insert(ResponseFields::CardPAN);
    fields.insert(ResponseFields::ExpireDate);
    fields.insert(ResponseFields::CardAppName);
    fields.insert(ResponseFields::CardEmvAid);
    fields.insert(ResponseFields::CardDataEnc);
    fields.insert(ResponseFields::TVR);
    fields.insert(ResponseFields::TSI);
    fields.insert(ResponseFields::TC);
    fields.insert(ResponseFields::CID);
    fields.insert(ResponseFields::KVR);
    fields.insert(ResponseFields::CDAResult);
    fields.insert(ResponseFields::CardholderName);
    fields.insert(ResponseFields::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::Refund);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckRefundWithoutRRN) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::IssuerName);
    fields.insert(ResponseFields::CardInputMethod);
    fields.insert(ResponseFields::CardPAN);
    fields.insert(ResponseFields::ExpireDate);
    fields.insert(ResponseFields::CardAppName);
    fields.insert(ResponseFields::CardEmvAid);
    fields.insert(ResponseFields::CardDataEnc);
    fields.insert(ResponseFields::TVR);
    fields.insert(ResponseFields::TSI);
    fields.insert(ResponseFields::TC);
    fields.insert(ResponseFields::CID);
    fields.insert(ResponseFields::KVR);
    fields.insert(ResponseFields::CDAResult);
    fields.insert(ResponseFields::CardholderName);
    fields.insert(ResponseFields::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::RefundWithoutRRN);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Sales
TEST(ResponseOperationValidators, CheckAliPay) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::AcquirerFeeAmount);
    fields.insert(ResponseFields::TerminalFeeAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::AliPay);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckFastTrack) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::TerminalFeeAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::IssuerName);
    fields.insert(ResponseFields::CardInputMethod);
    fields.insert(ResponseFields::CardPAN);
    fields.insert(ResponseFields::ExpireDate);
    fields.insert(ResponseFields::CardAppName);
    fields.insert(ResponseFields::CardEmvAid);
    fields.insert(ResponseFields::CardData);
    fields.insert(ResponseFields::CardDataEnc);
    fields.insert(ResponseFields::CardholderName);
    fields.insert(ResponseFields::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::FastTrack);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckMOTO) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::IssuerName);
    fields.insert(ResponseFields::CardInputMethod);
    fields.insert(ResponseFields::CardPAN);
    fields.insert(ResponseFields::ExpireDate);
    fields.insert(ResponseFields::CardAppName);
    fields.insert(ResponseFields::CardEmvAid);
    fields.insert(ResponseFields::CardDataEnc);
    fields.insert(ResponseFields::CardholderName);
    fields.insert(ResponseFields::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::MOTO);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckPreAuth) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::IssuerName);
    fields.insert(ResponseFields::CardInputMethod);
    fields.insert(ResponseFields::CardPAN);
    fields.insert(ResponseFields::ExpireDate);
    fields.insert(ResponseFields::CardAppName);
    fields.insert(ResponseFields::CardEmvAid);
    fields.insert(ResponseFields::CardDataEnc);
    fields.insert(ResponseFields::TVR);
    fields.insert(ResponseFields::TSI);
    fields.insert(ResponseFields::TC);
    fields.insert(ResponseFields::CID);
    fields.insert(ResponseFields::KVR);
    fields.insert(ResponseFields::CDAResult);
    fields.insert(ResponseFields::CardholderName);
    fields.insert(ResponseFields::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::PreAuth);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckQuickPayment) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::AcquirerFeeAmount);
    fields.insert(ResponseFields::TerminalFeeAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::QuickPayment);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckQuickPaymentStatus) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::QuickPaymentStatus);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    //EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckSale) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::IssuerName);
    fields.insert(ResponseFields::CardInputMethod);
    fields.insert(ResponseFields::CardPAN);
    fields.insert(ResponseFields::ExpireDate);
    fields.insert(ResponseFields::CardAppName);
    fields.insert(ResponseFields::CardEmvAid);
    fields.insert(ResponseFields::CardDataEnc);
    fields.insert(ResponseFields::TVR);
    fields.insert(ResponseFields::TSI);
    fields.insert(ResponseFields::TC);
    fields.insert(ResponseFields::CID);
    fields.insert(ResponseFields::KVR);
    fields.insert(ResponseFields::CDAResult);
    fields.insert(ResponseFields::CardholderName);
    fields.insert(ResponseFields::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::Sale);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckSalesCompletion) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::IssuerName);
    fields.insert(ResponseFields::CardInputMethod);
    fields.insert(ResponseFields::CardPAN);
    fields.insert(ResponseFields::ExpireDate);
    fields.insert(ResponseFields::CardAppName);
    fields.insert(ResponseFields::CardEmvAid);
    fields.insert(ResponseFields::CardDataEnc);
    fields.insert(ResponseFields::TVR);
    fields.insert(ResponseFields::TSI);
    fields.insert(ResponseFields::TC);
    fields.insert(ResponseFields::CID);
    fields.insert(ResponseFields::KVR);
    fields.insert(ResponseFields::CDAResult);
    fields.insert(ResponseFields::CardholderName);
    fields.insert(ResponseFields::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::SalesCompletion);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Void
TEST(ResponseOperationValidators, CheckVoid) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::IssuerName);
    fields.insert(ResponseFields::CardInputMethod);
    fields.insert(ResponseFields::CardPAN);
    fields.insert(ResponseFields::ExpireDate);
    fields.insert(ResponseFields::CardAppName);
    fields.insert(ResponseFields::CardEmvAid);
    fields.insert(ResponseFields::CardDataEnc);
    fields.insert(ResponseFields::TVR);
    fields.insert(ResponseFields::TSI);
    fields.insert(ResponseFields::TC);
    fields.insert(ResponseFields::CID);
    fields.insert(ResponseFields::KVR);
    fields.insert(ResponseFields::CDAResult);
    fields.insert(ResponseFields::CardholderName);
    fields.insert(ResponseFields::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::Void);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckVoidPartialSale) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::PartialAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::IssuerName);
    fields.insert(ResponseFields::CardInputMethod);
    fields.insert(ResponseFields::CardPAN);
    fields.insert(ResponseFields::ExpireDate);
    fields.insert(ResponseFields::CardAppName);
    fields.insert(ResponseFields::CardEmvAid);
    fields.insert(ResponseFields::CardDataEnc);
    fields.insert(ResponseFields::TVR);
    fields.insert(ResponseFields::TSI);
    fields.insert(ResponseFields::TC);
    fields.insert(ResponseFields::CID);
    fields.insert(ResponseFields::KVR);
    fields.insert(ResponseFields::CDAResult);
    fields.insert(ResponseFields::CardholderName);
    fields.insert(ResponseFields::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::VoidPartialSale);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckVoidPreAuth) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::PartialAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::RRN);
    fields.insert(ResponseFields::ReceiptReference);
    fields.insert(ResponseFields::TransactionID);
    fields.insert(ResponseFields::AuthCode);
    fields.insert(ResponseFields::ResponseCode);
    fields.insert(ResponseFields::ResponseText);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TransDateTime);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::IssuerName);
    fields.insert(ResponseFields::CardInputMethod);
    fields.insert(ResponseFields::CardPAN);
    fields.insert(ResponseFields::ExpireDate);
    fields.insert(ResponseFields::CardAppName);
    fields.insert(ResponseFields::CardEmvAid);
    fields.insert(ResponseFields::CardDataEnc);
    fields.insert(ResponseFields::TVR);
    fields.insert(ResponseFields::TSI);
    fields.insert(ResponseFields::TC);
    fields.insert(ResponseFields::CID);
    fields.insert(ResponseFields::KVR);
    fields.insert(ResponseFields::CDAResult);
    fields.insert(ResponseFields::CardholderName);
    fields.insert(ResponseFields::CardholderAuthMethod);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::VoidPreAuth);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Service

TEST(ResponseOperationValidators, CheckDisplayQR) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::DisplayQR);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckFinalizeTransaction) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::FinalizeTransaction);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckGetCurrentPrinter) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::AdditionalInfo);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::GetCurrentPrinter);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckGetLastOperation) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::GetLastOperation);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckGetOperationCopy) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::ReceiptReference);
    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::GetOperationCopy);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckInitialization) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::Initialization);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckKeyDownload) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::KeyDownload);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckPrintCommsInfo) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::AdditionalInfo);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::PrintCommsInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckPrintDetailReport) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);
    fields.insert(ResponseFields::TotalAmount);
    fields.insert(ResponseFields::CurrencyCode);
    fields.insert(ResponseFields::TerminalID);
    fields.insert(ResponseFields::MerchantID);
    fields.insert(ResponseFields::TerminalDateTime);
    fields.insert(ResponseFields::SalesCount);
    fields.insert(ResponseFields::VoidCount);
    fields.insert(ResponseFields::RefundCount);
    fields.insert(ResponseFields::SalesArray);
    fields.insert(ResponseFields::VoidArray);
    fields.insert(ResponseFields::RefundArray);
    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::PrintDetailReport);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckPrintLastReceipt) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::PrintLastReceipt);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckPrintReceiptCopy) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::PrintReceiptCopy);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckPrintSoftInfo) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::PrintSoftInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckPrintSummaryReport) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::PrintSummaryReport);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckRegistration) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::Registration);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckSelfTest) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::SelfTest);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckSetCurrentPrinter) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::SetCurrentPrinter);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckSettlement) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::EcrMerchantNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::Settlement);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckTest) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::Test);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckTestCommunication) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::TestCommunication);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(ResponseOperationValidators, CheckUpdateSW) {
    std::set<ResponseFields> fields;

    fields.insert(ResponseFields::OperationCode);
    fields.insert(ResponseFields::EcrNumber);
    fields.insert(ResponseFields::Status);

    auto validator = ValidatorFactory::getValidator(Lanter::OperationCodes::UpdateSW);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<ResponseFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}