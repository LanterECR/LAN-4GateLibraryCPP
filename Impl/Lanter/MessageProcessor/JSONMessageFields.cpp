#include "JSONMessageFields.h"

namespace Lanter {
    namespace MessageProcessor {
        //Для статических членов требуется "реализация". Обман для компилятора

        std::string JSONRootFields::classField;
        std::string JSONRootFields::objectField;

        std::string JSONClassFieldValues::requestValue;
        std::string JSONClassFieldValues::responseValue;
        std::string JSONClassFieldValues::communicationValue;
        std::string JSONClassFieldValues::notificationValue;

        std::string JSONRequestFields::EcrNumber;
        std::string JSONRequestFields::EcrMerchantNumber;
        std::string JSONRequestFields::OperationCode;
        std::string JSONRequestFields::Amount;
        std::string JSONRequestFields::PartialAmount;
        std::string JSONRequestFields::TipsAmount;
        std::string JSONRequestFields::CashbackAmount;
        std::string JSONRequestFields::CurrencyCode;
        std::string JSONRequestFields::RRN;
        std::string JSONRequestFields::AuthCode;
        std::string JSONRequestFields::ReceiptReference;
        std::string JSONRequestFields::TransactionID;
        std::string JSONRequestFields::CardDataEnc;
        std::string JSONRequestFields::OpenTags;
        std::string JSONRequestFields::EncTags;
        std::string JSONRequestFields::ProviderCode;
        std::string JSONRequestFields::AdditionalInfo;
        std::string JSONRequestFields::CfgTerminalID;
        std::string JSONRequestFields::Status;

        std::string JSONResponseFields::EcrNumber;
        std::string JSONResponseFields::EcrMerchantNumber;
        std::string JSONResponseFields::OperationCode;
        std::string JSONResponseFields::OriginalOperationCode;
        std::string JSONResponseFields::PartialAmount;
        std::string JSONResponseFields::TotalAmount;
        std::string JSONResponseFields::AcquirerFeeAmount;
        std::string JSONResponseFields::TerminalFeeAmount;
        std::string JSONResponseFields::TipsAmount;
        std::string JSONResponseFields::CurrencyCode;
        std::string JSONResponseFields::ReceiptReference;
        std::string JSONResponseFields::RRN;
        std::string JSONResponseFields::Status;
        std::string JSONResponseFields::OriginalOperationStatus;
        std::string JSONResponseFields::TransDateTime;
        std::string JSONResponseFields::TerminalDateTime;
        std::string JSONResponseFields::CardPAN;
        std::string JSONResponseFields::ExpireDate;
        std::string JSONResponseFields::CardholderName;
        std::string JSONResponseFields::CardholderAuthMethod;
        std::string JSONResponseFields::AuthCode;
        std::string JSONResponseFields::ResponseCode;
        std::string JSONResponseFields::ResponseText;
        std::string JSONResponseFields::STAN;
        std::string JSONResponseFields::TransactionID;
        std::string JSONResponseFields::TerminalID;
        std::string JSONResponseFields::CfgTerminalID;
        std::string JSONResponseFields::CardEmvAid;
        std::string JSONResponseFields::CardAppName;
        std::string JSONResponseFields::CardInputMethod;
        std::string JSONResponseFields::IssuerName;
        std::string JSONResponseFields::AdditionalInfo;
        std::string JSONResponseFields::CardData;
        std::string JSONResponseFields::CardDataEnc;
        std::string JSONResponseFields::MerchantId;
        std::string JSONResponseFields::TVR;
        std::string JSONResponseFields::TSI;
        std::string JSONResponseFields::TC;
        std::string JSONResponseFields::CID;
        std::string JSONResponseFields::KVR;
        std::string JSONResponseFields::CDAResult;
        std::string JSONResponseFields::SalesCount;
        std::string JSONResponseFields::VoidCount;
        std::string JSONResponseFields::RefundCount;
        std::string JSONResponseFields::SalesArray;
        std::string JSONResponseFields::VoidArray;
        std::string JSONResponseFields::RefundArray;
        std::string JSONResponseFields::SalesAmount;
        std::string JSONResponseFields::VoidAmount;
        std::string JSONResponseFields::RefundAmount;
        std::string JSONResponseFields::CardPANHash;
        std::string JSONResponseFields::receiptLine1;
        std::string JSONResponseFields::receiptLine2;
        std::string JSONResponseFields::receiptLine3;
        std::string JSONResponseFields::receiptLine4;
        std::string JSONResponseFields::receiptLine5;

        std::string JSONCommunicationFields::Command;
        std::string JSONCommunicationFields::Link;
        std::string JSONCommunicationFields::Data;
        std::string JSONCommunicationFields::IP;
        std::string JSONCommunicationFields::Port;

        std::string JSONNotificationFields::Code;
        std::string JSONNotificationFields::Message;
        std::string JSONNotificationFields::Additional;

        //реализация геттеров
        const std::string &JSONRootFields::getObjectField() {

            if(JSONRootFields::objectField.empty()) {
                JSONRootFields::objectField = "__object";
            }
            return JSONRootFields::objectField;
        }

//root fields init
        const std::string &JSONRootFields::getClassField() {
            if(JSONRootFields::classField.empty()) {
                JSONRootFields::classField = "__class";
            }
            return JSONRootFields::classField;
        }

//class field values
        const std::string &JSONClassFieldValues::getRequestValue() {
            if(JSONClassFieldValues::requestValue.empty()) {
                JSONClassFieldValues::requestValue = "LANTER::Request";
            }
            return JSONClassFieldValues::requestValue;
        }

        const std::string &JSONClassFieldValues::getResponseValue() {
            if(JSONClassFieldValues::responseValue.empty()) {
                JSONClassFieldValues::responseValue = "LANTER::Response";
            }
            return JSONClassFieldValues::responseValue;
        }

        const std::string &JSONClassFieldValues::getCommunicationValue() {
            if(JSONClassFieldValues::communicationValue.empty()) {
                JSONClassFieldValues::communicationValue = "Com";
            }
            return JSONClassFieldValues::communicationValue;
        }

        const std::string &JSONClassFieldValues::getNotificationValue() {
            if(JSONClassFieldValues::notificationValue.empty()) {
                JSONClassFieldValues::notificationValue = "LANTER::Notification";
            }
            return JSONClassFieldValues::notificationValue;
        }

//request object fields
        const std::string &JSONRequestFields::getEcrNumber() {
            if(JSONRequestFields::EcrNumber.empty()) {
                JSONRequestFields::EcrNumber = "EcrNumber";
            }
            return JSONRequestFields::EcrNumber;
        }

        const std::string &JSONRequestFields::getEcrMerchantNumber() {
            if(JSONRequestFields::EcrMerchantNumber.empty()) {
                JSONRequestFields::EcrMerchantNumber = "EcrMerchantNumber";
            }
            return JSONRequestFields::EcrMerchantNumber;
        }

        const std::string &JSONRequestFields::getOperationCode() {
            if(JSONRequestFields::OperationCode.empty()) {
                JSONRequestFields::OperationCode = "OperationCode";
            }
            return JSONRequestFields::OperationCode;
        }

        const std::string &JSONRequestFields::getAmount() {
            if(JSONRequestFields::Amount.empty()) {
                JSONRequestFields::Amount = "Amount";
            }
            return JSONRequestFields::Amount;
        }

        const std::string &JSONRequestFields::getPartialAmount() {
            if(JSONRequestFields::PartialAmount.empty()) {
                JSONRequestFields::PartialAmount = "PartialAmount";
            }
            return JSONRequestFields::PartialAmount;
        }

        const std::string &JSONRequestFields::getTipsAmount() {
            if(JSONRequestFields::TipsAmount.empty()) {
                JSONRequestFields::TipsAmount = "TipsAmount";
            }
            return JSONRequestFields::TipsAmount;
        }

        const std::string &JSONRequestFields::getCashbackAmount() {
            if(JSONRequestFields::CashbackAmount.empty()) {
                JSONRequestFields::CashbackAmount = "CashbackAmount";
            }
            return JSONRequestFields::CashbackAmount;
        }

        const std::string &JSONRequestFields::getCurrencyCode() {
            if(JSONRequestFields::CurrencyCode.empty()) {
                JSONRequestFields::CurrencyCode = "CurrencyCode";
            }
            return JSONRequestFields::CurrencyCode;
        }

        const std::string &JSONRequestFields::getRRN() {
            if(JSONRequestFields::RRN.empty()) {
                JSONRequestFields::RRN = "RRN";
            }
            return JSONRequestFields::RRN;
        }

        const std::string &JSONRequestFields::getAuthCode() {
            if(JSONRequestFields::AuthCode.empty()) {
                JSONRequestFields::AuthCode = "AuthCode";
            }
            return JSONRequestFields::AuthCode;
        }

        const std::string &JSONRequestFields::getReceiptReference() {
            if(JSONRequestFields::ReceiptReference.empty()) {
                JSONRequestFields::ReceiptReference = "ReceiptReference";
            }
            return JSONRequestFields::ReceiptReference;
        }

        const std::string &JSONRequestFields::getTransactionID() {
            if(JSONRequestFields::TransactionID.empty()) {
                JSONRequestFields::TransactionID = "TransactionID";
            }
            return JSONRequestFields::TransactionID;
        }

        const std::string &JSONRequestFields::getCardDataEnc() {
            if(JSONRequestFields::CardDataEnc.empty()) {
                JSONRequestFields::CardDataEnc = "CardDataEnc";
            }
            return JSONRequestFields::CardDataEnc;
        }

        const std::string &JSONRequestFields::getOpenTags() {
            if(JSONRequestFields::OpenTags.empty()) {
                JSONRequestFields::OpenTags = "OpenTags";
            }
            return JSONRequestFields::OpenTags;
        }

        const std::string &JSONRequestFields::getEncTags() {
            if(JSONRequestFields::EncTags.empty()) {
                JSONRequestFields::EncTags = "EncTags";}
            return JSONRequestFields::EncTags;
        }

        const std::string &JSONRequestFields::getProviderCode() {
            if(JSONRequestFields::ProviderCode.empty()) {
                JSONRequestFields::ProviderCode = "ProviderCode";
            }
            return JSONRequestFields::ProviderCode;
        }

        const std::string &JSONRequestFields::getAdditionalInfo() {
            if(JSONRequestFields::AdditionalInfo.empty()) {
                JSONRequestFields::AdditionalInfo = "AdditionalInfo";}
            return JSONRequestFields::AdditionalInfo;
        }

        const std::string &JSONRequestFields::getCfgTerminalId() {
            if(JSONRequestFields::CfgTerminalID.empty()) {
                JSONRequestFields::CfgTerminalID = "CfgTerminalID";}
            return JSONRequestFields::CfgTerminalID;
        }

        const std::string &JSONRequestFields::getStatus() {
            if(JSONRequestFields::Status.empty()) {
                JSONRequestFields::Status = "Status";
            }
            return JSONRequestFields::Status;
        }

//response object fields

        const std::string &JSONResponseFields::getEcrNumber() {
            if(JSONResponseFields::EcrNumber.empty()) {
                JSONResponseFields::EcrNumber = "EcrNumber";
            }
            return JSONResponseFields::EcrNumber;
        }

        const std::string &JSONResponseFields::getEcrMerchantNumber() {
            if(JSONResponseFields::EcrMerchantNumber.empty()) {
                JSONResponseFields::EcrMerchantNumber = "EcrMerchantNumber";
            }
            return JSONResponseFields::EcrMerchantNumber;
        }

        const std::string &JSONResponseFields::getOperationCode() {
            if(JSONResponseFields::OperationCode.empty()) {
                JSONResponseFields::OperationCode = "OperationCode";
            }
            return JSONResponseFields::OperationCode;
        }

        const std::string &JSONResponseFields::getOriginalOperationCode() {
            if(JSONResponseFields::OriginalOperationCode.empty()) {
                JSONResponseFields::OriginalOperationCode = "OriginalOperationCode";
            }
            return JSONResponseFields::OriginalOperationCode;
        }

        const std::string &JSONResponseFields::getPartialAmount() {
            if(JSONResponseFields::PartialAmount.empty()) {
                JSONResponseFields::PartialAmount = "PartialAmount";
            }
            return JSONResponseFields::PartialAmount;
        }

        const std::string &JSONResponseFields::getTotalAmount() {
            if(JSONResponseFields::TotalAmount.empty()) {
                JSONResponseFields::TotalAmount = "TotalAmount";
            }
            return JSONResponseFields::TotalAmount;
        }

        const std::string &JSONResponseFields::getAcquirerFeeAmount() {
            if(JSONResponseFields::AcquirerFeeAmount.empty()) {
                JSONResponseFields::AcquirerFeeAmount = "AmountAquirerFee";
            }
            return JSONResponseFields::AcquirerFeeAmount;
        }

        const std::string &JSONResponseFields::getTerminalFeeAmount() {
            if(JSONResponseFields::TerminalFeeAmount.empty()) {
                JSONResponseFields::TerminalFeeAmount = "AmountTerminalFee";
            }
            return JSONResponseFields::TerminalFeeAmount;
        }

        const std::string &JSONResponseFields::getTipsAmount() {
            if(JSONResponseFields::TipsAmount.empty()) {
                JSONResponseFields::TipsAmount = "TipsAmount";
            }
            return JSONResponseFields::TipsAmount;
        }

        const std::string &JSONResponseFields::getCurrencyCode() {
            if(JSONResponseFields::CurrencyCode.empty()) {
                JSONResponseFields::CurrencyCode = "CurrencyCode";
            }
            return JSONResponseFields::CurrencyCode;
        }

        const std::string &JSONResponseFields::getReceiptReference() {
            if(JSONResponseFields::ReceiptReference.empty()) {
                JSONResponseFields::ReceiptReference = "ReceiptReference";
            }
            return JSONResponseFields::ReceiptReference;
        }

        const std::string &JSONResponseFields::getRRN() {
            if(JSONResponseFields::RRN.empty()) {
                JSONResponseFields::RRN = "RRN";
            }
            return JSONResponseFields::RRN;
        }

        const std::string &JSONResponseFields::getStatus() {
            if(JSONResponseFields::Status.empty()) {
                JSONResponseFields::Status = "Status";
            }
            return JSONResponseFields::Status;
        }

        const std::string &JSONResponseFields::getOriginalOperationStatus() {
            if(JSONResponseFields::OriginalOperationStatus.empty()) {
                JSONResponseFields::OriginalOperationStatus = "OriginalOperationStatus";
            }
            return JSONResponseFields::OriginalOperationStatus;
        }

        const std::string &JSONResponseFields::getTransDateTime() {
            if(JSONResponseFields::TransDateTime.empty()) {
                JSONResponseFields::TransDateTime = "TransDateTime";
            }
            return JSONResponseFields::TransDateTime;
        }

        const std::string &JSONResponseFields::getTerminalDateTime() {
            if(JSONResponseFields::TerminalDateTime.empty()) {
                JSONResponseFields::TerminalDateTime = "TerminalDateTime";
            }
            return JSONResponseFields::TerminalDateTime;
        }

        const std::string &JSONResponseFields::getCardPAN() {
            if(JSONResponseFields::CardPAN.empty()) {
                JSONResponseFields::CardPAN = "CardPAN";
            }
            return JSONResponseFields::CardPAN;
        }

        const std::string &JSONResponseFields::getExpireDate() {
            if(JSONResponseFields::ExpireDate.empty()) {
                JSONResponseFields::ExpireDate = "ExpireDate";
            }
            return JSONResponseFields::ExpireDate;
        }

        const std::string &JSONResponseFields::getCardholderName() {
            if(JSONResponseFields::CardholderName.empty()) {
                JSONResponseFields::CardholderName = "CardholderName";
            }
            return JSONResponseFields::CardholderName;
        }

        const std::string &JSONResponseFields::getCardholderAuthMethod() {
            if(JSONResponseFields::CardholderAuthMethod.empty()) {
                JSONResponseFields::CardholderAuthMethod = "CardholderAuthMethod";
            }
            return JSONResponseFields::CardholderAuthMethod;
        }

        const std::string &JSONResponseFields::getAuthCode() {
            if(JSONResponseFields::AuthCode.empty()) {
                JSONResponseFields::AuthCode = "AuthCode";
            }
            return JSONResponseFields::AuthCode;
        }

        const std::string &JSONResponseFields::getResponseCode() {
            if(JSONResponseFields::ResponseCode.empty()) {
                JSONResponseFields::ResponseCode = "ResponseCode";
            }
            return JSONResponseFields::ResponseCode;
        }

        const std::string &JSONResponseFields::getResponseText() {
            if(JSONResponseFields::ResponseText.empty()) {
                JSONResponseFields::ResponseText = "ResponseText";
            }
            return JSONResponseFields::ResponseText;
        }

        const std::string &JSONResponseFields::getSTAN() {
            if(JSONResponseFields::STAN.empty()) {
                JSONResponseFields::STAN = "STAN";
            }
            return JSONResponseFields::STAN;
        }

        const std::string &JSONResponseFields::getTransactionID() {
            if(JSONResponseFields::TransactionID.empty()) {
                JSONResponseFields::TransactionID = "TransactionID";
            }
            return JSONResponseFields::TransactionID;
        }

        const std::string &JSONResponseFields::getTerminalID() {
            if(JSONResponseFields::TerminalID.empty()) {
                JSONResponseFields::TerminalID = "TerminalID";
            }
            return JSONResponseFields::TerminalID;
        }

        const std::string &JSONResponseFields::getCfgTerminalId() {
            if(JSONResponseFields::CfgTerminalID.empty()) {
                JSONResponseFields::CfgTerminalID = "CfgTerminalID";
            }
            return JSONResponseFields::CfgTerminalID;
        }

        const std::string &JSONResponseFields::getCardEmvAid() {
            if(JSONResponseFields::CardEmvAid.empty()) {
                JSONResponseFields::CardEmvAid = "CardEmvAid";
            }
            return JSONResponseFields::CardEmvAid;
        }

        const std::string &JSONResponseFields::getCardAppName() {
            if(JSONResponseFields::CardAppName.empty()) {
                JSONResponseFields::CardAppName = "CardAppName";
            }
            return JSONResponseFields::CardAppName;
        }

        const std::string &JSONResponseFields::getCardInputMethod() {
            if(JSONResponseFields::CardInputMethod.empty()) {
                JSONResponseFields::CardInputMethod = "CardInputMethod";
            }
            return JSONResponseFields::CardInputMethod;
        }

        const std::string &JSONResponseFields::getIssuerName() {
            if(JSONResponseFields::IssuerName.empty()) {
                JSONResponseFields::IssuerName = "IssuerName";
            }
            return JSONResponseFields::IssuerName;
        }

        const std::string &JSONResponseFields::getAdditionalInfo() {
            if(JSONResponseFields::AdditionalInfo.empty()) {
                JSONResponseFields::AdditionalInfo = "AdditionalInfo";
            }
            return JSONResponseFields::AdditionalInfo;
        }

        const std::string &JSONResponseFields::getCardData() {
            if(JSONResponseFields::CardData.empty()) {
                JSONResponseFields::CardData = "CardData";
            }
            return JSONResponseFields::CardData;
        }

        const std::string &JSONResponseFields::getCardDataEnc() {
            if(JSONResponseFields::CardDataEnc.empty()) {
                JSONResponseFields::CardDataEnc = "CardDataEnc";
            }
            return JSONResponseFields::CardDataEnc;
        }

        const std::string &JSONResponseFields::getMerchantID() {
            if(JSONResponseFields::MerchantId.empty()) {
                JSONResponseFields::MerchantId = "MerchantId";
            }
            return JSONResponseFields::MerchantId;
        }

        const std::string &JSONResponseFields::getTVR() {
            if(JSONResponseFields::TVR.empty()) {
                JSONResponseFields::TVR = "TVR";
            }
            return JSONResponseFields::TVR;
        }

        const std::string &JSONResponseFields::getTSI() {
            if(JSONResponseFields::TSI.empty()) {
                JSONResponseFields::TSI = "TSI";
            }
            return JSONResponseFields::TSI;
        }

        const std::string &JSONResponseFields::getTC() {
            if(JSONResponseFields::TC.empty()) {
                JSONResponseFields::TC = "TC";
            }
            return JSONResponseFields::TC;
        }

        const std::string &JSONResponseFields::getCID() {
            if(JSONResponseFields::CID.empty()) {
                JSONResponseFields::CID = "CID";
            }
            return JSONResponseFields::CID;
        }

        const std::string &JSONResponseFields::getKVR() {
            if(JSONResponseFields::KVR.empty()) {
                JSONResponseFields::KVR = "KVR";
            }
            return JSONResponseFields::KVR;
        }

        const std::string &JSONResponseFields::getCDAResult() {
            if(JSONResponseFields::CDAResult.empty()) {
                JSONResponseFields::CDAResult = "CDAResult";
            }
            return JSONResponseFields::CDAResult;
        }

        const std::string &JSONResponseFields::getSaleCount() {
            if(JSONResponseFields::SalesCount.empty()) {
                JSONResponseFields::SalesCount = "SalesCount";
            }
            return JSONResponseFields::SalesCount;
        }

        const std::string &JSONResponseFields::getVoidCount() {
            if(JSONResponseFields::VoidCount.empty()) {
                JSONResponseFields::VoidCount = "VoidCount";
            }
            return JSONResponseFields::VoidCount;
        }

        const std::string &JSONResponseFields::getRefundCount() {
            if(JSONResponseFields::RefundCount.empty()) {
                JSONResponseFields::RefundCount = "RefundCount";
            }
            return JSONResponseFields::RefundCount;
        }

        const std::string &JSONResponseFields::getSaleArray() {
            if(JSONResponseFields::SalesArray.empty()) {
                JSONResponseFields::SalesArray = "SalesArray";
            }
            return JSONResponseFields::SalesArray;
        }

        const std::string &JSONResponseFields::getVoidArray() {
            if(JSONResponseFields::VoidArray.empty()) {
                JSONResponseFields::VoidArray = "VoidArray";
            }
            return JSONResponseFields::VoidArray;
        }

        const std::string &JSONResponseFields::getRefundArray() {
            if(JSONResponseFields::RefundArray.empty()) {
                JSONResponseFields::RefundArray = "RefundArray";
            }
            return JSONResponseFields::RefundArray;
        }

        const std::string &JSONResponseFields::getSalesAmount() {
            if(JSONResponseFields::SalesAmount.empty()) {
                JSONResponseFields::SalesAmount = "SalesAmount";
            }
            return JSONResponseFields::SalesAmount;
        }

        const std::string &JSONResponseFields::getVoidAmount() {
            if(JSONResponseFields::VoidAmount.empty()) {
                JSONResponseFields::VoidAmount = "VoidAmount";
            }
            return JSONResponseFields::VoidAmount;
        }

        const std::string &JSONResponseFields::getRefundAmount() {
            if(JSONResponseFields::RefundAmount.empty()) {
                JSONResponseFields::RefundAmount = "RefundAmount";
            }
            return JSONResponseFields::RefundAmount;
        }

        const std::string &JSONResponseFields::getCardPanHash() {
            if(JSONResponseFields::CardPANHash.empty()) {
                JSONResponseFields::CardPANHash = "CardPANHash";
            }
            return JSONResponseFields::CardPANHash;
        }

        const std::string &JSONResponseFields::getReceiptLine1() {
            if(JSONResponseFields::receiptLine1.empty()) {
                JSONResponseFields::receiptLine1 = "ReceiptLine1";
            }
            return JSONResponseFields::receiptLine1;
        }

        const std::string &JSONResponseFields::getReceiptLine2() {
            if(JSONResponseFields::receiptLine2.empty()) {
                JSONResponseFields::receiptLine2 = "ReceiptLine2";
            }
            return JSONResponseFields::receiptLine2;
        }

        const std::string &JSONResponseFields::getReceiptLine3() {
            if(JSONResponseFields::receiptLine3.empty()) {
                JSONResponseFields::receiptLine3 = "ReceiptLine3";
            }
            return JSONResponseFields::receiptLine3;
        }

        const std::string &JSONResponseFields::getReceiptLine4() {
            if(JSONResponseFields::receiptLine4.empty()) {
                JSONResponseFields::receiptLine4 = "ReceiptLine4";
            }
            return JSONResponseFields::receiptLine4;
        }

        const std::string &JSONResponseFields::getReceiptLine5() {
            if(JSONResponseFields::receiptLine5.empty()) {
                JSONResponseFields::receiptLine5 = "ReceiptLine5";
            }
            return JSONResponseFields::receiptLine5;
        }

        const std::string &JSONCommunicationFields::getCommand() {
            if(JSONCommunicationFields::Command.empty()) {
                JSONCommunicationFields::Command = "Cmd";
            }
            return JSONCommunicationFields::Command;
        }

        const std::string &JSONCommunicationFields::getLink() {
            if(JSONCommunicationFields::Link.empty()) {
                JSONCommunicationFields::Link = "Lnk";
            }
            return JSONCommunicationFields::Link;
        }

        const std::string &JSONCommunicationFields::getData() {
            if(JSONCommunicationFields::Data.empty()) {
                JSONCommunicationFields::Data = "Dt";
            }
            return JSONCommunicationFields::Data;
        }

        const std::string &JSONCommunicationFields::getIp() {
            if(JSONCommunicationFields::IP.empty()) {
                JSONCommunicationFields::IP = "IP";
            }
            return JSONCommunicationFields::IP;
        }

        const std::string &JSONCommunicationFields::getPort() {
            if(JSONCommunicationFields::Port.empty()) {
                JSONCommunicationFields::Port = "Port";
            }
            return JSONCommunicationFields::Port;
        }

        const std::string &JSONNotificationFields::getCode() {
            if(JSONNotificationFields::Code.empty()) {
                JSONNotificationFields::Code = "Code";
            }
            return JSONNotificationFields::Code;
        }

        const std::string &JSONNotificationFields::getMessage() {
            if(JSONNotificationFields::Message.empty()) {
                JSONNotificationFields::Message = "Message";
            }
            return JSONNotificationFields::Message;
        }

        const std::string &JSONNotificationFields::getAdditional() {
            if(JSONNotificationFields::Additional.empty()) {
                JSONNotificationFields::Additional = "Additional";
            }
            return JSONNotificationFields::Additional;
        }
    }
}