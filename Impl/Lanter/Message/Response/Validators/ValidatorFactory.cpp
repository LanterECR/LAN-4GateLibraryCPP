//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "ValidatorFactory.h"

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

#include "Lanter/Message/Response/Validators/Operations/Refund/QuickPaymentRefund.h"
#include "Lanter/Message/Response/Validators/Operations/Refund/QuickPaymentRefundStatus.h"
#include "Lanter/Message/Response/Validators/Operations/Refund/Refund.h"
#include "Lanter/Message/Response/Validators/Operations/Refund/RefundWithoutRRN.h"

#include "Lanter/Message/Response/Validators/Operations/Sale/AliPay.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/FastTrack.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/MOTO.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/PreAuth.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/QuickPayment.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/QuickPaymentStatus.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/Sale.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/SalesCompletion.h"

#include "Lanter/Message/Response/Validators/Operations/Service/DisplayQR.h"
#include "Lanter/Message/Response/Validators/Operations/Service/FinalizeTransaction.h"
#include "Lanter/Message/Response/Validators/Operations/Service/GetCurrentPrinter.h"
#include "Lanter/Message/Response/Validators/Operations/Service/GetLastOperation.h"
#include "Lanter/Message/Response/Validators/Operations/Service/GetOperationCopy.h"
#include "Lanter/Message/Response/Validators/Operations/Service/Initialization.h"
#include "Lanter/Message/Response/Validators/Operations/Service/KeyDowload.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintCommsInfo.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintDetailReport.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintLastReceipt.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintReceiptCopy.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintSoftInfo.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintSummaryReport.h"
#include "Lanter/Message/Response/Validators/Operations/Service/Registration.h"
#include "Lanter/Message/Response/Validators/Operations/Service/SelfTest.h"
#include "Lanter/Message/Response/Validators/Operations/Service/SetCurrentPrinter.h"
#include "Lanter/Message/Response/Validators/Operations/Service/Settlement.h"
#include "Lanter/Message/Response/Validators/Operations/Service/Test.h"
#include "Lanter/Message/Response/Validators/Operations/Service/TestCommunication.h"
#include "Lanter/Message/Response/Validators/Operations/Service/UpdateSW.h"

#include "Lanter/Message/Response/Validators/Operations/Void/Void.h"
#include "Lanter/Message/Response/Validators/Operations/Void/VoidPartialSale.h"
#include "Lanter/Message/Response/Validators/Operations/Void/VoidPreAuth.h"

// TODO Добавить QuickPaymentRefund
namespace Lanter {
    namespace Message {
        namespace Response {

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
                if (validator) {
                    validator->addSpecificFields();
                }
                return validator;
            }
        }//Response
    }
}//Lanter