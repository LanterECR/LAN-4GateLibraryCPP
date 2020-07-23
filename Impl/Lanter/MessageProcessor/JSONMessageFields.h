//
// Created by Владимир Лысенков on 08.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_MESSAGEFIELDS_H
#define LAN_4GATELIBRARYCPP_MESSAGEFIELDS_H

#include <string>

namespace Lanter {
    namespace MessageProcessor {
        class JSONRootFields
        {
        public:
            static const std::string &getClassField();
            static const std::string &getObjectField();
        private:
            JSONRootFields() = default;
            static std::string classField;
            static std::string objectField;
        };

        class JSONClassFieldValues
        {
        public:
            static const std::string &getRequestValue();
            static const std::string &getResponseValue();
            static const std::string &getCommunicationValue();
            static const std::string &getNotificationValue();
        private:
            JSONClassFieldValues() = default;
            static std::string requestValue;
            static std::string responseValue;
            static std::string communicationValue;
            static std::string notificationValue;
        };

        class JSONRequestFields
        {
        public:
            static const std::string &getEcrNumber();

            static const std::string &getEcrMerchantNumber();

            static const std::string &getOperationCode();

            static const std::string &getAmount();

            static const std::string &getPartialAmount();

            static const std::string &getTipsAmount();

            static const std::string &getCashbackAmount();

            static const std::string &getCurrencyCode();

            static const std::string &getRRN();

            static const std::string &getAuthCode();

            static const std::string &getReceiptReference();

            static const std::string &getTransactionID();

            static const std::string &getCardDataEnc();

            static const std::string &getOpenTags();

            static const std::string &getEncTags();

            static const std::string &getProviderCode();

            static const std::string &getAdditionalInfo();

            static const std::string &getCfgTerminalId();

            static const std::string &getStatus();

        private:
            JSONRequestFields() = default;
            static std::string EcrNumber;
            static std::string EcrMerchantNumber;
            static std::string OperationCode;
            static std::string Amount;
            static std::string PartialAmount;
            static std::string TipsAmount;
            static std::string CashbackAmount;
            static std::string CurrencyCode;
            static std::string RRN;
            static std::string AuthCode;
            static std::string ReceiptReference;
            static std::string TransactionID;
            static std::string CardDataEnc;
            static std::string OpenTags;
            static std::string EncTags;
            static std::string ProviderCode;
            static std::string AdditionalInfo;
            static std::string CfgTerminalID;
            static std::string Status;
        };

        class JSONResponseFields
        {
        public:
            static const std::string &getEcrNumber();

            static const std::string &getEcrMerchantNumber();

            static const std::string &getOperationCode();

            static const std::string &getOriginalOperationCode();

            static const std::string &getPartialAmount();

            static const std::string &getTotalAmount();

            static const std::string &getAcquirerFeeAmount();

            static const std::string &getTerminalFeeAmount();

            static const std::string &getTipsAmount();

            static const std::string &getCurrencyCode();

            static const std::string &getReceiptReference();

            static const std::string &getRRN();

            static const std::string &getStatus();

            static const std::string &getOriginalOperationStatus();

            static const std::string &getTransDateTime();

            static const std::string &getTerminalDateTime();

            static const std::string &getCardPAN();

            static const std::string &getExpireDate();

            static const std::string &getCardholderName();

            static const std::string &getCardholderAuthMethod();

            static const std::string &getAuthCode();

            static const std::string &getResponseCode();

            static const std::string &getResponseText();

            static const std::string &getSTAN();

            static const std::string &getTransactionID();

            static const std::string &getTerminalID();

            static const std::string &getCfgTerminalId();

            static const std::string &getCardEmvAid();

            static const std::string &getCardAppName();

            static const std::string &getCardInputMethod();

            static const std::string &getIssuerName();

            static const std::string &getAdditionalInfo();

            static const std::string &getCardData();

            static const std::string &getCardDataEnc();

            static const std::string &getMerchantID();

            static const std::string &getTVR();

            static const std::string &getTSI();

            static const std::string &getTC();

            static const std::string &getCID();

            static const std::string &getKVR();

            static const std::string &getCDAResult();

            static const std::string &getSaleCount();

            static const std::string &getVoidCount();

            static const std::string &getRefundCount();

            static const std::string &getSaleArray();

            static const std::string &getVoidArray();

            static const std::string &getRefundArray();

            static const std::string &getSalesAmount();

            static const std::string &getVoidAmount();

            static const std::string &getRefundAmount();

            static const std::string &getCardPanHash();

            static const std::string &getReceiptLine1();

            static const std::string &getReceiptLine2();

            static const std::string &getReceiptLine3();

            static const std::string &getReceiptLine4();

            static const std::string &getReceiptLine5();

        private:
            JSONResponseFields() = default;
            static std::string EcrNumber;
            static std::string EcrMerchantNumber;
            static std::string OperationCode;
            static std::string OriginalOperationCode;
            static std::string PartialAmount;
            static std::string TotalAmount;
            static std::string AcquirerFeeAmount;
            static std::string TerminalFeeAmount;
            static std::string TipsAmount;
            static std::string CurrencyCode;
            static std::string ReceiptReference;
            static std::string RRN;
            static std::string Status;
            static std::string OriginalOperationStatus;
            static std::string TransDateTime;
            static std::string TerminalDateTime;
            static std::string CardPAN;
            static std::string ExpireDate;
            static std::string CardholderName;
            static std::string CardholderAuthMethod;
            static std::string AuthCode;
            static std::string ResponseCode;
            static std::string ResponseText;
            static std::string STAN;
            static std::string TransactionID;
            static std::string TerminalID;
            static std::string CfgTerminalID;
            static std::string CardEmvAid;
            static std::string CardAppName;
            static std::string CardInputMethod;
            static std::string IssuerName;
            static std::string AdditionalInfo;
            static std::string CardData;
            static std::string CardDataEnc;
            static std::string MerchantId;
            static std::string TVR;
            static std::string TSI;
            static std::string TC;
            static std::string CID;
            static std::string KVR;
            static std::string CDAResult;
            static std::string SalesCount;
            static std::string VoidCount;
            static std::string RefundCount;
            static std::string SalesArray;
            static std::string VoidArray;
            static std::string RefundArray;
            static std::string SalesAmount;
            static std::string VoidAmount;
            static std::string RefundAmount;
            static std::string CardPANHash;
            static std::string receiptLine1;
            static std::string receiptLine2;
            static std::string receiptLine3;
            static std::string receiptLine4;
            static std::string receiptLine5;
        };

        class JSONCommunicationFields
        {
        public:
            static const std::string &getCommand();

            static const std::string &getLink();

            static const std::string &getData();

            static const std::string &getIp();

            static const std::string &getPort();

        private:
            JSONCommunicationFields() = default;
            static std::string Command;
            static std::string Link;
            static std::string Data;
            static std::string IP;
            static std::string Port;
        };

        class JSONNotificationFields
        {
        public:
            static const std::string &getCode();

            static const std::string &getMessage();

            static const std::string &getAdditional();

        private:
            JSONNotificationFields() = default;
            static std::string Code;
            static std::string Message;
            static std::string Additional;
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_MESSAGEFIELDS_H
