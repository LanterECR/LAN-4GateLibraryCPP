#ifndef LAN_4GATELIB_JSONRESPONSEFIELDS_H
#define LAN_4GATELIB_JSONRESPONSEFIELDS_H

#include <string>

namespace Lanter {
    namespace MessageProcessor {
        class JSONResponseFields {
        public:
            static inline std::string getEcrNumber() { return "EcrNumber"; }
            static inline std::string getEcrMerchantNumber() { return "EcrMerchantNumber"; }
            static inline std::string getOperationCode() { return "OperationCode"; }
            static inline std::string getOriginalOperationCode() { return "OriginalOperationCode"; }
            static inline std::string getPartialAmount() { return "PartialAmount"; }
            static inline std::string getTotalAmount() { return "TotalAmount"; }
            static inline std::string getAcquirerFeeAmount() { return "AmountAquirerFee"; }
            static inline std::string getTerminalFeeAmount() { return "AmountTerminalFee"; }
            static inline std::string getTipsAmount() { return "TipsAmount"; }
            static inline std::string getCurrencyCode() { return "CurrencyCode"; }
            static inline std::string getReceiptReference() { return "ReceiptReference"; }
            static inline std::string getRRN() { return "RRN"; }
            static inline std::string getStatus() { return "Status"; }
            static inline std::string getOriginalOperationStatus() { return "OriginalOperationStatus"; }
            static inline std::string getTransDateTime() { return "TransDateTime"; }
            static inline std::string getTerminalDateTime() { return "TerminalDateTime"; }
            static inline std::string getCardPAN() { return "CardPAN"; }
            static inline std::string getExpireDate() { return "ExpireDate"; }
            static inline std::string getCardholderName() { return "CardholderName"; }
            static inline std::string getCardholderAuthMethod() { return "CardholderAuthMethod"; }
            static inline std::string getAuthCode() { return "AuthCode"; }
            static inline std::string getResponseCode() { return "ResponseCode"; }
            static inline std::string getResponseText() { return "ResponseText"; }
            static inline std::string getSTAN() { return "STAN"; }
            static inline std::string getTransactionID() { return "TransactionID"; }
            static inline std::string getTerminalID() { return "TerminalID"; }
            static inline std::string getCfgTerminalID() { return "CfgTerminalID"; }
            static inline std::string getCardEmvAid() { return "CardEmvAid"; }
            static inline std::string getCardAppName() { return "CardAppName"; }
            static inline std::string getCardInputMethod() { return "CardInputMethod"; }
            static inline std::string getIssuerName() { return "IssuerName"; }
            static inline std::string getAdditionalInfo() { return "AdditionalInfo"; }
            static inline std::string getCardData() { return "CardData"; }
            static inline std::string getCardDataEnc() { return "CardDataEnc"; }
            static inline std::string getMerchantID() { return "MerchantId"; }
            static inline std::string getTVR() { return "TVR"; }
            static inline std::string getTSI() { return "TSI"; }
            static inline std::string getTC() { return "TC"; }
            static inline std::string getCID() { return "CID"; }
            static inline std::string getKVR() { return "KVR"; }
            static inline std::string getCDAResult() { return "CDAResult"; }
            static inline std::string getSaleCount() { return "SalesCount"; }
            static inline std::string getVoidCount() { return "VoidCount"; }
            static inline std::string getRefundCount() { return "RefundCount"; }
            static inline std::string getSaleArray() { return "SalesArray"; }
            static inline std::string getVoidArray() { return "VoidArray"; }
            static inline std::string getRefundArray() { return "RefundArray"; }
            static inline std::string getSalesAmount() { return "SalesAmount"; }
            static inline std::string getVoidAmount() { return "VoidAmount"; }
            static inline std::string getRefundAmount() { return "RefundAmount"; }
            static inline std::string getCardPANHash() { return "CardPANHash"; }
            static inline std::string getReceiptLine1() { return "ReceiptLine1"; }
            static inline std::string getReceiptLine2() { return "ReceiptLine2"; }
            static inline std::string getReceiptLine3() { return "ReceiptLine3"; }
            static inline std::string getReceiptLine4() { return "ReceiptLine4"; }
            static inline std::string getReceiptLine5() { return "ReceiptLine5"; }
            static inline std::string getApplicationLabel() { return "ApplicationLabel"; }
            static inline std::string getBonusBalance() { return "BonusBalance"; }
            static inline std::string getBonusAmount() { return "BonusAmount"; }
            static inline std::string getHashCardTrack2() { return "HashCardTrack2"; }
            static inline std::string getFinalizationRequired() { return "FinalizationRequired"; }
            static inline std::string getAdditionalChoiceResult() { return "AdditionalChoiceResult"; }
			static inline std::string getECertAmount() { return "ECertAmount"; }
			static inline std::string getBasketID() { return "BasketID"; }

        };
    }
}
#endif //LAN_4GATELIB_JSONRESPONSEFIELDS_H
