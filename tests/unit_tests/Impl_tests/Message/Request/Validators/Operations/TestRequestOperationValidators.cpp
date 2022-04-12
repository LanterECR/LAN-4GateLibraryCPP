#include "gtest/gtest.h"

#include "Lanter/Message/Request/Validators/ValidatorFactory.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;

//Refund
TEST(TestRequestOperationValidators, CheckRefund) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);
    fields.insert(RequestField::RRN);
    fields.insert(RequestField::TransactionID);

    auto validator = ValidatorFactory::getValidator(OperationCode::Refund);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckRefundWithoutRRN) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCode::RefundWithoutRRN);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Sales
TEST(TestRequestOperationValidators, CheckAliPay) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCode::AliPay);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(TestRequestOperationValidators, CheckFastTrack) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);
    fields.insert(RequestField::EncTags);
    fields.insert(RequestField::OpenTags);

    auto validator = ValidatorFactory::getValidator(OperationCode::FastTrack);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckMOTO) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCode::MOTO);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(TestRequestOperationValidators, CheckPreAuth) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);
    fields.insert(RequestField::TransactionID);
    fields.insert(RequestField::CardDataEnc);

    auto validator = ValidatorFactory::getValidator(OperationCode::PreAuth);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckQuickPayment) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCode::QuickPayment);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(TestRequestOperationValidators, CheckQuickPaymentStatus) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::RRN);
    fields.insert(RequestField::AuthCode);
    fields.insert(RequestField::TransactionID);
    fields.insert(RequestField::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCode::QuickPaymentStatus);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckSale) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCode::Sale);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(TestRequestOperationValidators, CheckSalesCompletion) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);
    fields.insert(RequestField::RRN);
    fields.insert(RequestField::AuthCode);
    fields.insert(RequestField::TransactionID);

    auto validator = ValidatorFactory::getValidator(OperationCode::SalesCompletion);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Void
TEST(TestRequestOperationValidators, CheckVoid) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCode::Void);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckVoidPartialSale) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::PartialAmount);
    fields.insert(RequestField::CurrencyCode);
    fields.insert(RequestField::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCode::VoidPartialSale);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckVoidPreAuth) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::CardDataEnc);
    fields.insert(RequestField::TransactionID);

    auto validator = ValidatorFactory::getValidator(OperationCode::VoidPreAuth);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Service

TEST(TestRequestOperationValidators, CheckDisplayQR) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::AdditionalInfo);

    auto validator = ValidatorFactory::getValidator(OperationCode::DisplayQR);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckFinalizeTransaction) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::FinalizeTransaction);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckGetCurrentPrinter) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::GetCurrentPrinter);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckGetLastOperation) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::GetLastOperation);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckGetOperationCopy) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCode::GetOperationCopy);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckInitialization) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::Initialization);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckKeyDownload) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::KeyDownload);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckPrintCommsInfo) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintCommsInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckPrintDetailReport) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintDetailReport);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckPrintLastReceipt) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintLastReceipt);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckPrintReceiptCopy) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintReceiptCopy);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckPrintSoftInfo) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintSoftInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckPrintSummaryReport) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintSummaryReport);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckRegistration) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::Registration);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckSelfTest) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::SelfTest);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckSetCurrentPrinter) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::AdditionalInfo);

    auto validator = ValidatorFactory::getValidator(OperationCode::SetCurrentPrinter);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckSettlement) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::Settlement);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckTest) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::Test);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckTestCommunication) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::TestCommunication);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckUpdateSW) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::UpdateSW);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckSendLogs) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::SendLogs);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckSetLogLevel) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::SetLogLevel);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckLicenseActivationFile) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::LicenseActivationFile);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckLicenseActivationServer) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::LicenseActivationServer);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckClearReversal) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::ClearReversal);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckClearAllJournals) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::ClearAllJournals);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}
TEST(TestRequestOperationValidators, CheckTakeLockCard) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::TakeLockCard);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckEjectCard) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::EjectCard);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckEjectWaitCard) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::EjectWaitCard);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(TestRequestOperationValidators, CheckIsCardPresent) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::IsCardPresent);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}
