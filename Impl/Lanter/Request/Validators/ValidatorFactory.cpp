//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "ValidatorFactory.h"

#include "Operations/BasicValidator.h"

#include "Operations/Refund/QuickPaymentRefund.h"
#include "Operations/Refund/QuickPaymentRefundStatus.h"
#include "Operations/Refund/Refund.h"
#include "Operations/Refund/RefundWithoutRRN.h"

#include "Operations/Sale/AliPay.h"
#include "Operations/Sale/FastTrack.h"
#include "Operations/Sale/MOTO.h"
#include "Operations/Sale/PreAuth.h"
#include "Operations/Sale/QuickPayment.h"
#include "Operations/Sale/QuickPaymentStatus.h"
#include "Operations/Sale/Sale.h"
#include "Operations/Sale/SalesCompletion.h"

#include "Operations/Service/DisplayQR.h"
#include "Operations/Service/FinalizeTransaction.h"
#include "Operations/Service/GetCurrentPrinter.h"
#include "Operations/Service/GetLastOperation.h"
#include "Operations/Service/GetOperationCopy.h"
#include "Operations/Service/Initialization.h"
#include "Operations/Service/KeyDowload.h"
#include "Operations/Service/PrintCommsInfo.h"
#include "Operations/Service/PrintDetailReport.h"
#include "Operations/Service/PrintLastReceipt.h"
#include "Operations/Service/PrintReceiptCopy.h"
#include "Operations/Service/PrintSoftInfo.h"
#include "Operations/Service/PrintSummaryReport.h"
#include "Operations/Service/Registration.h"
#include "Operations/Service/SelfTest.h"
#include "Operations/Service/SetCurrentPrinter.h"
#include "Operations/Service/Settlement.h"
#include "Operations/Service/Test.h"
#include "Operations/Service/TestCommunication.h"
#include "Operations/Service/UpdateSW.h"

#include "Operations/Void/Void.h"
#include "Operations/Void/VoidPartialSale.h"
#include "Operations/Void/VoidPreAuth.h"

// TODO Добавить QuickPaymentRefund
namespace Lanter {
    namespace Request {

        std::shared_ptr<IValidator> ValidatorFactory::getValidator(OperationCodes operationCode) {
            std::shared_ptr<BasicValidator> validator;
            switch (operationCode) {
                case OperationCodes::Sale:
                    validator = std::make_shared<Sale>();
                    break;
                case OperationCodes::MOTO:
                    validator = std::make_shared<MOTO>();
                    break;
                case OperationCodes::QuickPayment:
                    validator = std::make_shared<QuickPayment>();
                    break;
                case OperationCodes::AliPay:
                    validator = std::make_shared<AliPay>();
                    break;
                case OperationCodes::PreAuth:
                    validator = std::make_shared<PreAuth>();
                    break;
                case OperationCodes::SalesCompletion:
                    validator = std::make_shared<SalesCompletion>();
                    break;
                case OperationCodes::QuickPaymentStatus:
                    validator = std::make_shared<QuickPaymentStatus>();
                    break;
                case OperationCodes::FastTrack:
                    validator = std::make_shared<FastTrack>();
                    break;
                case OperationCodes::Void:
                    validator = std::make_shared<Void>();
                    break;
                case OperationCodes::VoidPartialSale:
                    validator = std::make_shared<VoidPartialSale>();
                    break;
                case OperationCodes::VoidPreAuth:
                    validator = std::make_shared<VoidPreAuth>();
                    break;
                case OperationCodes::Refund:
                    validator = std::make_shared<Refund>();
                    break;
                case OperationCodes::RefundWithoutRRN:
                    validator = std::make_shared<RefundWithoutRRN>();
                    break;
                case OperationCodes::QuickPaymentRefund:
                    validator = std::make_shared<QuickPaymentRefund>();
                    break;
                case OperationCodes::QuickPaymentRefundStatus:
                    validator = std::make_shared<QuickPaymentRefundStatus>();
                    break;
                case OperationCodes::Registration:
                    validator = std::make_shared<Registration>();
                    break;
                case OperationCodes::TestCommunication:
                    validator = std::make_shared<TestCommunication>();
                    break;
                case OperationCodes::Test:
                    validator = std::make_shared<Test>();
                    break;
                case OperationCodes::PrintLastReceipt:
                    validator = std::make_shared<PrintLastReceipt>();
                    break;
                case OperationCodes::GetLastOperation:
                    validator = std::make_shared<GetLastOperation>();
                    break;
                case OperationCodes::PrintReceiptCopy:
                    validator = std::make_shared<PrintReceiptCopy>();
                    break;
                case OperationCodes::PrintDetailReport:
                    validator = std::make_shared<PrintDetailReport>();
                    break;
                case OperationCodes::PrintSummaryReport:
                    validator = std::make_shared<PrintSummaryReport>();
                    break;
                case OperationCodes::Settlement:
                    validator = std::make_shared<Settlement>();
                    break;
                case OperationCodes::KeyDownload:
                    validator = std::make_shared<KeyDownload>();
                    break;
                case OperationCodes::Initialization:
                    validator = std::make_shared<Initialization>();
                    break;
                case OperationCodes::UpdateSW:
                    validator = std::make_shared<UpdateSW>();
                    break;
                case OperationCodes::PrintCommsInfo:
                    validator = std::make_shared<PrintCommsInfo>();
                    break;
                case OperationCodes::PrintSoftInfo:
                    validator = std::make_shared<PrintSoftInfo>();
                    break;
                case OperationCodes::FinalizeTransaction:
                    validator = std::make_shared<FinalizeTransaction>();
                    break;
                case OperationCodes::GetCurrentPrinter:
                    validator = std::make_shared<GetCurrentPrinter>();
                    break;
                case OperationCodes::SetCurrentPrinter:
                    validator = std::make_shared<SetCurrentPrinter>();
                    break;
                case OperationCodes::SelfTest:
                    validator = std::make_shared<SelfTest>();
                    break;
                case OperationCodes::GetOperationCopy:
                    validator = std::make_shared<GetOperationCopy>();
                    break;
                case OperationCodes::DisplayQR:
                    validator = std::make_shared<DisplayQR>();
                    break;
                default:
                    validator = std::make_shared<BasicValidator>();
                    break;
            }
            if(validator) {
                validator->addSpecificFields();
            }
            return validator;
        }
    }//Request
}//Lanter