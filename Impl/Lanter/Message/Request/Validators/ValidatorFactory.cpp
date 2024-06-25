#include "ValidatorFactory.h"

//Sale operations
#include "Lanter/Message/Request/Validators/Operations/Sale/AliPay.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/Payment.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/FastTrack.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/MOTO.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/PreAuth.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/QuickPayment.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/QuickPaymentStatus.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/Sale.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/SalesCompletion.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/ECertGetRequisites.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/ECertPayment.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/ECertRefund.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/RequestCS.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/NotificationCS.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/RepeatLastN.h"
#include "Lanter/Message/Request/Validators/Operations/Sale/CardVerification.h"

//Devices operations
#include "Lanter/Message/Request/Validators/Operations/Devices/QRScannerResult.h"

//Void operations
#include "Lanter/Message/Request/Validators/Operations/Void/Void.h"
#include "Lanter/Message/Request/Validators/Operations/Void/VoidPartialSale.h"
#include "Lanter/Message/Request/Validators/Operations/Void/VoidPreAuth.h"

//Refund operations
#include "Lanter/Message/Request/Validators/Operations/Refund/QuickPaymentRefund.h"
#include "Lanter/Message/Request/Validators/Operations/Refund/QuickPaymentRefundStatus.h"
#include "Lanter/Message/Request/Validators/Operations/Refund/Refund.h"
#include "Lanter/Message/Request/Validators/Operations/Refund/RefundWithoutRRN.h"

//Service operations
#include "Lanter/Message/Request/Validators/Operations/Service/DisplayQR.h"
#include "Lanter/Message/Request/Validators/Operations/Service/FinalizeTransaction.h"
#include "Lanter/Message/Request/Validators/Operations/Service/GetCurrentPrinter.h"
#include "Lanter/Message/Request/Validators/Operations/Service/GetLastOperation.h"
#include "Lanter/Message/Request/Validators/Operations/Service/GetOperationCopy.h"
#include "Lanter/Message/Request/Validators/Operations/Service/GetMerchantList.h"
#include "Lanter/Message/Request/Validators/Operations/Service/Initialization.h"
#include "Lanter/Message/Request/Validators/Operations/Service/KeyDowload.h"
#include "Lanter/Message/Request/Validators/Operations/Service/PrintCommsInfo.h"
#include "Lanter/Message/Request/Validators/Operations/Service/PrintDetailReport.h"
#include "Lanter/Message/Request/Validators/Operations/Service/PrintMerchantSettlement.h"
#include "Lanter/Message/Request/Validators/Operations/Service/PrintLastReceipt.h"
#include "Lanter/Message/Request/Validators/Operations/Service/PrintReceiptCopy.h"
#include "Lanter/Message/Request/Validators/Operations/Service/PrintSoftInfo.h"
#include "Lanter/Message/Request/Validators/Operations/Service/PrintSummaryReport.h"
#include "Lanter/Message/Request/Validators/Operations/Service/Registration.h"
#include "Lanter/Message/Request/Validators/Operations/Service/SelfTest.h"
#include "Lanter/Message/Request/Validators/Operations/Service/SetCurrentPrinter.h"
#include "Lanter/Message/Request/Validators/Operations/Service/Settlement.h"
#include "Lanter/Message/Request/Validators/Operations/Service/Test.h"
#include "Lanter/Message/Request/Validators/Operations/Service/TestCommunication.h"
#include "Lanter/Message/Request/Validators/Operations/Service/UpdateSW.h"
#include "Lanter/Message/Request/Validators/Operations/Service/SendLogs.h"
#include "Lanter/Message/Request/Validators/Operations/Service/SetLogLevel.h"
#include "Lanter/Message/Request/Validators/Operations/Service/LicenseActivationFile.h"
#include "Lanter/Message/Request/Validators/Operations/Service/LicenseActivationServer.h"
#include "Lanter/Message/Request/Validators/Operations/Service/ClearReversal.h"
#include "Lanter/Message/Request/Validators/Operations/Service/ClearAllJournals.h"
#include "Lanter/Message/Request/Validators/Operations/Service/TakeLockCard.h"
#include "Lanter/Message/Request/Validators/Operations/Service/EjectCard.h"
#include "Lanter/Message/Request/Validators/Operations/Service/EjectWaitCard.h"
#include "Lanter/Message/Request/Validators/Operations/Service/IsCardPresent.h"
#include "Lanter/Message/Request/Validators/Operations/Service/UploadPending.h"
#include "Lanter/Message/Request/Validators/Operations/Service/UploadDelayed.h"
#include "Lanter/Message/Request/Validators/Operations/Service/BonusBalance.h"
#include "Lanter/Message/Request/Validators/Operations/Service/GrabEjectCard.h"
#include "Lanter/Message/Request/Validators/Operations/Service/SZKLoadKeys.h"
#include "Lanter/Message/Request/Validators/Operations/Service/CommunicationSettings.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            std::shared_ptr<IValidator> ValidatorFactory::getValidator(OperationCode operationCode)
            {
                std::shared_ptr<BasicValidator> validator;
                switch (operationCode)
                {
                    //Sale operations
                    case OperationCode::Sale:
                        validator = std::make_shared<Sale>();
                        break;
                    case OperationCode::MOTO:
                        validator = std::make_shared<MOTO>();
                        break;
                    case OperationCode::QuickPayment:
                        validator = std::make_shared<QuickPayment>();
                        break;
                    case OperationCode::AliPay:
                        validator = std::make_shared<AliPay>();
                        break;
                    case OperationCode::Payment:
                        validator = std::make_shared<Payment>();
                        break;
                    case OperationCode::PreAuth:
                        validator = std::make_shared<PreAuth>();
                        break;
                    case OperationCode::SalesCompletion:
                        validator = std::make_shared<SalesCompletion>();
                        break;
                    case OperationCode::QuickPaymentStatus:
                        validator = std::make_shared<QuickPaymentStatus>();
                        break;
                    case OperationCode::FastTrack:
                        validator = std::make_shared<FastTrack>();
                        break;
					case OperationCode::ECertGetRequisites:
						validator = std::make_shared<ECertGetRequisites>();
						break;
					case OperationCode::ECertPayment:
						validator = std::make_shared<ECertPayment>();
						break;
					case OperationCode::ECertRefund:
						validator = std::make_shared<ECertRefund>();
						break;
                    case OperationCode::CardVerification:
                        validator = std::make_shared<CardVerification>();
                        break;
                    case OperationCode::RequestCS:
                        validator = std::make_shared<RequestCS>();
                        break;
                    case OperationCode::NotificationCS:
                        validator = std::make_shared<NotificationCS>();
                        break;
                    case OperationCode::RepeatLastN:
                        validator = std::make_shared<RepeatLastN>();
                        break;

                    //Devices operations
                    case OperationCode::QRScannerResult:
                        validator = std::make_shared<QRScannerResult>();
                        break;

                    //Void operations
                    case OperationCode::Void:
                        validator = std::make_shared<Void>();
                        break;
                    case OperationCode::VoidPartialSale:
                        validator = std::make_shared<VoidPartialSale>();
                        break;
                    case OperationCode::VoidPreAuth:
                        validator = std::make_shared<VoidPreAuth>();
                        break;

                    //Refund operations
                    case OperationCode::Refund:
                        validator = std::make_shared<Refund>();
                        break;
                    case OperationCode::RefundWithoutRRN:
                        validator = std::make_shared<RefundWithoutRRN>();
                        break;
                    case OperationCode::QuickPaymentRefund:
                        validator = std::make_shared<QuickPaymentRefund>();
                        break;
                    case OperationCode::QuickPaymentRefundStatus:
                        validator = std::make_shared<QuickPaymentRefundStatus>();
                        break;

                    //Service operations
                    case OperationCode::Registration:
                        validator = std::make_shared<Registration>();
                        break;
                    case OperationCode::TestCommunication:
                        validator = std::make_shared<TestCommunication>();
                        break;
                    case OperationCode::Test:
                        validator = std::make_shared<Test>();
                        break;
                    case OperationCode::PrintLastReceipt:
                        validator = std::make_shared<PrintLastReceipt>();
                        break;
                    case OperationCode::GetLastOperation:
                        validator = std::make_shared<GetLastOperation>();
                        break;
                    case OperationCode::PrintReceiptCopy:
                        validator = std::make_shared<PrintReceiptCopy>();
                        break;
                    case OperationCode::PrintDetailReport:
                        validator = std::make_shared<PrintDetailReport>();
                        break;
                    case OperationCode::PrintSummaryReport:
                        validator = std::make_shared<PrintSummaryReport>();
                        break;
                    case OperationCode::Settlement:
                        validator = std::make_shared<Settlement>();
                        break;
                    case OperationCode::KeyDownload:
                        validator = std::make_shared<KeyDownload>();
                        break;
                    case OperationCode::Initialization:
                        validator = std::make_shared<Initialization>();
                        break;
                    case OperationCode::UpdateSW:
                        validator = std::make_shared<UpdateSW>();
                        break;
                    case OperationCode::PrintCommsInfo:
                        validator = std::make_shared<PrintCommsInfo>();
                        break;
                    case OperationCode::PrintMerchantSettlement:
                        validator = std::make_shared<PrintMerchantSettlement>();
                        break;
                    case OperationCode::PrintSoftInfo:
                        validator = std::make_shared<PrintSoftInfo>();
                        break;
                    case OperationCode::FinalizeTransaction:
                        validator = std::make_shared<FinalizeTransaction>();
                        break;
                    case OperationCode::GetCurrentPrinter:
                        validator = std::make_shared<GetCurrentPrinter>();
                        break;
                    case OperationCode::SetCurrentPrinter:
                        validator = std::make_shared<SetCurrentPrinter>();
                        break;
                    case OperationCode::SelfTest:
                        validator = std::make_shared<SelfTest>();
                        break;
                    case OperationCode::GetOperationCopy:
                        validator = std::make_shared<GetOperationCopy>();
                        break;
                    case OperationCode::GetMerchantList:
                        validator = std::make_shared<GetMerchantList>();
                        break;
                    case OperationCode::DisplayQR:
                        validator = std::make_shared<DisplayQR>();
                        break;
                    case OperationCode::SendLogs:
                        validator = std::make_shared<SendLogs>();
                        break;
                    case OperationCode::SetLogLevel:
                        validator = std::make_shared<SetLogLevel>();
                        break;
                    case OperationCode::LicenseActivationFile:
                        validator = std::make_shared<LicenseActivationFile>();
                        break;
                    case OperationCode::LicenseActivationServer:
                        validator = std::make_shared<LicenseActivationServer>();
                        break;
                    case OperationCode::ClearReversal:
                        validator = std::make_shared<ClearReversal>();
                        break;
                    case OperationCode::ClearAllJournals:
                        validator = std::make_shared<ClearAllJournals>();
                        break;
                    case OperationCode::TakeLockCard:
                        validator = std::make_shared<TakeLockCard>();
                        break;
                    case OperationCode::EjectCard:
                        validator = std::make_shared<EjectCard>();
                        break;
                    case OperationCode::EjectWaitCard:
                        validator = std::make_shared<EjectWaitCard>();
                        break;
                    case OperationCode::IsCardPresent:
                        validator = std::make_shared<IsCardPresent>();
                        break;
                    case OperationCode::UploadPending:
                        validator = std::make_shared<UploadPending>();
                        break;
                    case OperationCode::UploadDelayed:
                        validator = std::make_shared<UploadDelayed>();
                        break;
                    case OperationCode::BonusBalance:
                        validator = std::make_shared<BonusBalance>();
                        break;
                    case OperationCode::GrabEjectCard:
                        validator = std::make_shared<GrabEjectCard>();
                        break;
                    case OperationCode::SZKLoadKeys:
                        validator = std::make_shared<SZKLoadKeys>();
                        break;
                    case OperationCode::CommunicationSettings:
                        validator = std::make_shared<CommunicationSettings>();
                        break;
                    default:
                        validator = std::make_shared<BasicValidator>();
                        break;
                }//switch

                if (validator)
                {
                    //Из конструкторов не рекомендуется вызывать виртуальные методы. Необходима инициализация валидатора
                    validator->addSpecificFields();
                }//if validator

                return validator;
            }//getValidator()
        }//namespace Request
    }//namespace Message
}//namespace Lanter