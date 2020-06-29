//
// Created by Владимир Лысенков on 25.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_RESPONSEDATA_H
#define LAN_4GATELIBRARYCPP_RESPONSEDATA_H

#include "Lanter/Response/IResponseData.h"

#include "Validators/IValidator.h"

namespace Lanter {
    namespace Response {
        class ResponseData : public IResponseData {
        public:
            ResponseData();
            ~ResponseData() override = default;

            const std::set<ResponseFields> &getFieldsSet() const override;

            const std::set<ResponseFields> &getMandatoryFields() const override;

            const std::set<ResponseFields> &getOptionalFields() const override;

            bool validateMandatoryFields() override;

            int16_t getEcrNumber() const override;

            void setEcrNumber(int16_t ecrNumber) override;

            int16_t getEcrMerchantNumber() const override;

            void setEcrMerchantNumber(int16_t ecrMerchantNumber) override;

            OperationCodes getOperationCode() const override;

            void setOperationCode(OperationCodes operationCode) override;

            OperationCodes getOriginalOperationCode() const override;

            void setOriginalOperationCode(OperationCodes originalOperationCode) override;

            int64_t getTotalAmount() const override;

            void setTotalAmount(int64_t totalAmount) override;

            int64_t getPartialAmount() const override;

            void setPartialAmount(int64_t partialAmount) override;

            int64_t getAcquirerFeeAmount() const override;

            void setAcquirerFeeAmount(int64_t amountAcquirerFee) override;

            int64_t getTerminalFeeAmount() const override;

            void setTerminalFeeAmount(int64_t amountTerminalFee) override;

            int64_t getTipsAmount() const override;

            void setTipsAmount(int64_t tipsAmount) override;

            int16_t getCurrencyCode() const override;

            void setCurrencyCode(int16_t currencyCode) override;

            const std::string &getReceiptReference() const override;

            void setReceiptReference(const std::string &receiptReference) override;

            const std::string &getRRN() const override;

            void setRRN(const std::string &rrn) override;

            Response::Status getStatus() const override;

            void setStatus(Response::Status status) override;

            Response::Status getOriginalOperationStatus() const override;

            void setOriginalOperationStatus(Response::Status originalOperationStatus) override;

            const std::string &getTransDateTime() const override;

            void setTransDateTime(const std::string &transDateTime) override;

            const std::string &getTerminalDateTime() const override;

            void setTerminalDateTime(const std::string &terminalDateTime) override;

            const std::string &getCardPan() const override;

            void setCardPan(const std::string &cardPan) override;

            const std::string &getExpireDate() const override;

            void setExpireDate(const std::string &expireDate) override;

            const std::string &getCardholderName() const override;

            void setCardholderName(const std::string &cardholderName) override;

            Response::CardholderAuthMethod getCardholderAuthMethod() const override;

            void setCardholderAuthMethod(Response::CardholderAuthMethod cardholderAuthMethod) override;

            const std::string &getAuthCode() const override;

            void setAuthCode(const std::string &authCode) override;

            const std::string &getResponseCode() const override;

            void setResponseCode(const std::string &responseCode) override;

            const std::string &getResponseText() const override;

            void setResponseText(const std::string &responseText) override;

            const std::string &getSTAN() const override;

            void setSTAN(const std::string &stan) override;

            const std::string &getTransactionID() const override;

            void setTransactionID(const std::string &transactionId) override;

            const std::string &getTerminalID() const override;

            void setTerminalID(const std::string &terminalId) override;

            const std::string &getCardEmvAid() const override;

            void setCardEmvAid(const std::string &cardEmvAid) override;

            const std::string &getCardAppName() const override;

            void setCardAppName(const std::string &cardAppName) override;

            Response::CardInputMethod getCardInputMethod() const override;

            void setCardInputMethod(Response::CardInputMethod cardInputMethod) override;

            const std::string &getIssuerName() const override;

            void setIssuerName(const std::string &issuerName) override;

            const std::string &getAdditionalInfo() const override;

            void setAdditionalInfo(const std::string &additionalInfo) override;

            const std::string &getCardData() const override;

            void setCardData(const std::string &cardData) override;

            const std::string &getCardDataEnc() const override;

            void setCardDataEnc(const std::string &cardDataEnc) override;

            const std::string &getMerchantID() const override;

            void setMerchantID(const std::string &merchantId) override;

            const std::string &getTVR() const override;

            void setTVR(const std::string &tvr) override;

            const std::string &getTSI() const override;

            void setTSI(const std::string &tsi) override;

            const std::string &getTC() const override;

            void setTC(const std::string &tc) override;

            const std::string &getCID() const override;

            void setCID(const std::string &cid) override;

            const std::string &getKVR() const override;

            void setKVR(const std::string &kvr) override;

            const std::string &getCDAResult() const override;

            void setCDAResult(const std::string &cdaResult) override;

            int32_t getSalesCount() const override;

            void setSalesCount(int32_t salesCount) override;

            int32_t getVoidCount() const override;

            void setVoidCount(int32_t voidCount) override;

            int32_t getRefundCount() const override;

            void setRefundCount(int32_t refundCount) override;

            const std::vector<std::shared_ptr<IResponseData> > &getSalesArray() const override;

            void setSalesArray(const std::vector<std::shared_ptr<IResponseData> > &salesArray) override;

            const std::vector<std::shared_ptr<IResponseData> > &getVoidArray() const override;

            void setVoidArray(const std::vector<std::shared_ptr<IResponseData> > &voidArray) override;

            const std::vector<std::shared_ptr<IResponseData> > &getRefundArray() const override;

            void setRefundArray(const std::vector<std::shared_ptr<IResponseData> > &refundArray) override;

        private:
            void initValidator();
            std::set<ResponseFields> m_FieldsSet; ///< Список установленных полей

            std::shared_ptr<IValidator> m_Validator; ///< Валидатор полей операц

            int16_t m_EcrNumber = -1;
            int16_t m_EcrMerchantNumber = -1;

            OperationCodes m_OperationCode = OperationCodes::NoOperation;
            OperationCodes m_OriginalOperationCode = OperationCodes::NoOperation;

            int64_t m_TotalAmount = -1;
            int64_t m_PartialAmount = -1;
            int64_t m_AmountAcquirerFee = -1;
            int64_t m_AmountTerminalFee = -1;
            int64_t m_TipsAmount = -1;

            int16_t m_CurrencyCode = -1;
            std::string m_ReceiptReference;
            std::string m_RRN;
            Status m_Status = Status::NoStatus;
            Status m_OriginalOperationStatus = Status::NoStatus;

            std::string m_TransDateTime;
            std::string m_TerminalDateTime;
            std::string m_CardPAN;
            std::string m_ExpireDate;
            std::string m_CardholderName;
            CardholderAuthMethod m_CardholderAuthMethod = CardholderAuthMethod::NoMethod;
            std::string m_AuthCode;
            std::string m_ResponseCode;
            std::string m_ResponseText;
            std::string m_STAN;
            std::string m_TransactionID;
            std::string m_TerminalID;
            std::string m_CardEmvAid;
            std::string m_CardAppName;
            CardInputMethod m_CardInputMethod = CardInputMethod::NoMethod;
            std::string m_IssuerName;
            std::string m_AdditionalInfo;
            std::string m_CardData;
            std::string m_CardDataEnc;
            std::string m_MerchantID;
            std::string m_TVR;
            std::string m_TSI;
            std::string m_TC;
            std::string m_CID;
            std::string m_KVR;
            std::string m_CDAResult;
            int32_t m_SalesCount = -1;
            int32_t m_VoidCount = -1;
            int32_t m_RefundCount = -1;
            std::vector<std::shared_ptr<IResponseData> > m_SalesArray;
            std::vector<std::shared_ptr<IResponseData> > m_VoidArray;
            std::vector<std::shared_ptr<IResponseData> > m_RefundArray;

            std::set<ResponseFields> m_EmptyFieldsPlaceholder; ///< Пустая коллекция для полей при отсутствии валидатора
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_RESPONSEDATA_H
