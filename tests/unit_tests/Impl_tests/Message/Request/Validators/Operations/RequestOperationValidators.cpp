//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "gtest/gtest.h"

#include "Lanter/Message/Request/Validators/ValidatorFactory.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;

//Refund
TEST(RequestOperationValidators, CheckRefund) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::Amount);
    fields.insert(RequestFields::CurrencyCode);
    fields.insert(RequestFields::RRN);
    fields.insert(RequestFields::TransactionID);

    auto validator = ValidatorFactory::getValidator(OperationCodes::Refund);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckRefundWithoutRRN) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::Amount);
    fields.insert(RequestFields::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCodes::RefundWithoutRRN);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Sales
TEST(RequestOperationValidators, CheckAliPay) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::Amount);
    fields.insert(RequestFields::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCodes::AliPay);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(RequestOperationValidators, CheckFastTrack) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::Amount);
    fields.insert(RequestFields::CurrencyCode);
    fields.insert(RequestFields::EncTags);
    fields.insert(RequestFields::OpenTags);

    auto validator = ValidatorFactory::getValidator(OperationCodes::FastTrack);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckMOTO) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::Amount);
    fields.insert(RequestFields::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCodes::MOTO);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(RequestOperationValidators, CheckPreAuth) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::Amount);
    fields.insert(RequestFields::CurrencyCode);
    fields.insert(RequestFields::TransactionID);
    fields.insert(RequestFields::CardDataEnc);

    auto validator = ValidatorFactory::getValidator(OperationCodes::PreAuth);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckQuickPayment) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::Amount);
    fields.insert(RequestFields::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCodes::QuickPayment);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(RequestOperationValidators, CheckQuickPaymentStatus) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::RRN);
    fields.insert(RequestFields::AuthCode);
    fields.insert(RequestFields::TransactionID);
    fields.insert(RequestFields::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCodes::QuickPaymentStatus);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckSale) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::Amount);
    fields.insert(RequestFields::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCodes::Sale);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(RequestOperationValidators, CheckSalesCompletion) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::Amount);
    fields.insert(RequestFields::CurrencyCode);
    fields.insert(RequestFields::RRN);
    fields.insert(RequestFields::AuthCode);
    fields.insert(RequestFields::TransactionID);

    auto validator = ValidatorFactory::getValidator(OperationCodes::SalesCompletion);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Void
TEST(RequestOperationValidators, CheckVoid) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCodes::Void);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckVoidPartialSale) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::PartialAmount);
    fields.insert(RequestFields::CurrencyCode);
    fields.insert(RequestFields::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCodes::VoidPartialSale);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckVoidPreAuth) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::CardDataEnc);
    fields.insert(RequestFields::TransactionID);

    auto validator = ValidatorFactory::getValidator(OperationCodes::VoidPreAuth);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Service

TEST(RequestOperationValidators, CheckDisplayQR) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::AdditionalInfo);

    auto validator = ValidatorFactory::getValidator(OperationCodes::DisplayQR);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckFinalizeTransaction) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::FinalizeTransaction);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckGetCurrentPrinter) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::GetCurrentPrinter);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckGetLastOperation) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::GetLastOperation);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckGetOperationCopy) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCodes::GetOperationCopy);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckInitialization) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::Initialization);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckKeyDownload) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::KeyDownload);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintCommsInfo) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::PrintCommsInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintDetailReport) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::PrintDetailReport);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintLastReceipt) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::PrintLastReceipt);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintReceiptCopy) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);
    fields.insert(RequestFields::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCodes::PrintReceiptCopy);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintSoftInfo) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::PrintSoftInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintSummaryReport) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::PrintSummaryReport);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckRegistration) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::Registration);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckSelfTest) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::SelfTest);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckSetCurrentPrinter) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::AdditionalInfo);

    auto validator = ValidatorFactory::getValidator(OperationCodes::SetCurrentPrinter);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckSettlement) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);
    fields.insert(RequestFields::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::Settlement);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckTest) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::Test);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckTestCommunication) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::TestCommunication);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckUpdateSW) {
    std::set<RequestFields> fields;

    fields.insert(RequestFields::OperationCode);
    fields.insert(RequestFields::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCodes::UpdateSW);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestFields> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}