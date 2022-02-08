#ifndef LAN_4GATELIB_JSONREQUESTFIELDS_H
#define LAN_4GATELIB_JSONREQUESTFIELDS_H
#include <string>

namespace Lanter {
    namespace MessageProcessor {
        class JSONRequestFields
        {
        public:
            static inline std::string getEcrNumber() { return "EcrNumber";}
            static inline std::string getEcrMerchantNumber() { return "EcrMerchantNumber";}
            static inline std::string getOperationCode() { return "OperationCode"; }
            static inline std::string getAmount() { return "Amount";}
            static inline std::string getPartialAmount() { return "PartialAmount";}
            static inline std::string getTipsAmount() { return "TipsAmount";}
            static inline std::string getCashbackAmount() { return "CashbackAmount";}
            static inline std::string getCurrencyCode() { return "CurrencyCode";}
            static inline std::string getRRN() { return "RRN";}
            static inline std::string getAuthCode() { return "AuthCode";}
            static inline std::string getReceiptReference() { return "ReceiptReference";}
            static inline std::string getTransactionID() { return "TransactionID";}
            static inline std::string getCardDataEnc() { return "CardDataEnc";}
            static inline std::string getOpenTags() { return "OpenTags";}
            static inline std::string getEncTags() { return "EncTags";}
            static inline std::string getProviderCode() { return "ProviderCode";}
            static inline std::string getAdditionalInfo() { return "AdditionalInfo";}
            static inline std::string getCfgTerminalId() { return "CfgTerminalID";}
        };
    }
}
#endif //LAN_4GATELIB_JSONREQUESTFIELDS_H
