#ifndef LAN_4GATELIBRARYCPP_RESPONSEDATA_H
#define LAN_4GATELIBRARYCPP_RESPONSEDATA_H

#include "Lanter/Message/Response/IResponseData.h"

#include "Validators/IValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class ResponseData : public IResponseData {
            public:
                ResponseData();

                ~ResponseData() override = default;

                const std::set<ResponseField> &getFieldsSet() const override;

                bool isFieldSet(ResponseField field) const override;

                const std::set<ResponseField> &getMandatoryFields() const override;

                const std::set<ResponseField> &getOptionalFields() const override;

                bool validateMandatoryFields() const override;

                int16_t getEcrNumber() const override;

                bool setEcrNumber(int16_t ecrNumber) override;

                int16_t getEcrMerchantNumber() const override;

                bool setEcrMerchantNumber(int16_t ecrMerchantNumber) override;

                OperationCode getOperationCode() const override;

                bool setOperationCode(OperationCode operationCode) override;

                OperationCode getOriginalOperationCode() const override;

                bool setOriginalOperationCode(OperationCode originalOperationCode) override;

                int64_t getTotalAmount() const override;

                bool setTotalAmount(int64_t totalAmount) override;

                int64_t getPartialAmount() const override;

                bool setPartialAmount(int64_t partialAmount) override;

                int64_t getAcquirerFeeAmount() const override;

                bool setAcquirerFeeAmount(int64_t amountAcquirerFee) override;

                int64_t getTerminalFeeAmount() const override;

                bool setTerminalFeeAmount(int64_t amountTerminalFee) override;

                int64_t getTipsAmount() const override;

                bool setTipsAmount(int64_t tipsAmount) override;

                const std::string & getCurrencyCode() const override;

                bool setCurrencyCode(const std::string &currencyCode) override;

                const std::string &getReceiptReference() const override;

                bool setReceiptReference(const std::string &receiptReference) override;

                const std::string &getRRN() const override;

                bool setRRN(const std::string &rrn) override;

                Response::Status getStatus() const override;

                bool setStatus(Response::Status status) override;

                Response::Status getOriginalOperationStatus() const override;

                bool setOriginalOperationStatus(Response::Status originalOperationStatus) override;

                const std::string &getTransDateTime() const override;

                bool setTransDateTime(const std::string &transDateTime) override;

                const std::string &getTerminalDateTime() const override;

                bool setTerminalDateTime(const std::string &terminalDateTime) override;

                const std::string &getCardPAN() const override;

                bool setCardPAN(const std::string &cardPan) override;

                const std::string &getExpireDate() const override;

                bool setExpireDate(const std::string &expireDate) override;

                const std::string &getCardholderName() const override;

                bool setCardholderName(const std::string &cardholderName) override;

                Response::CardholderAuthMethod getCardholderAuthMethod() const override;

                bool setCardholderAuthMethod(Response::CardholderAuthMethod cardholderAuthMethod) override;

                const std::string &getAuthCode() const override;

                bool setAuthCode(const std::string &authCode) override;

                const std::string &getResponseCode() const override;

                bool setResponseCode(const std::string &responseCode) override;

                const std::string &getResponseText() const override;

                bool setResponseText(const std::string &responseText) override;

                const std::string &getSTAN() const override;

                bool setSTAN(const std::string &stan) override;

                const std::string &getTransactionID() const override;

                bool setTransactionID(const std::string &transactionId) override;

                const std::string &getTerminalID() const override;

                bool setTerminalID(const std::string &terminalId) override;

                const std::string &getCardEmvAid() const override;

                bool setCardEmvAid(const std::string &cardEmvAid) override;

                const std::string &getCardAppName() const override;

                bool setCardAppName(const std::string &cardAppName) override;

                Response::CardInputMethod getCardInputMethod() const override;

                bool setCardInputMethod(Response::CardInputMethod cardInputMethod) override;

                const std::string &getIssuerName() const override;

                bool setIssuerName(const std::string &issuerName) override;

                const std::string &getAdditionalInfo() const override;

                bool setAdditionalInfo(const std::string &additionalInfo) override;

                const std::string &getCardData() const override;

                bool setCardData(const std::string &cardData) override;

                const std::string &getCardDataEnc() const override;

                bool setCardDataEnc(const std::string &cardDataEnc) override;

                const std::string &getMerchantID() const override;

                bool setMerchantID(const std::string &merchantId) override;

                const std::string &getTVR() const override;

                bool setTVR(const std::string &tvr) override;

                const std::string &getTSI() const override;

                bool setTSI(const std::string &tsi) override;

                const std::string &getTC() const override;

                bool setTC(const std::string &tc) override;

                const std::string &getCID() const override;

                bool setCID(const std::string &cid) override;

                const std::string &getKVR() const override;

                bool setKVR(const std::string &kvr) override;

                const std::string &getCDAResult() const override;

                bool setCDAResult(const std::string &cdaResult) override;

                int64_t getSalesAmount() const override;

                bool setSalesAmount(int64_t amount) override;

                int32_t getSaleCount() const override;

                bool setSalesCount(int32_t salesCount) override;


                int64_t getVoidAmount() const override;

                bool setVoidAmount(int64_t amount) override;

                int32_t getVoidCount() const override;

                bool setVoidCount(int32_t voidCount) override;

                int64_t getRefundAmount() const override;

                bool setRefundAmount(int64_t amount) override;

                int32_t getRefundCount() const override;

                bool setRefundCount(int32_t refundCount) override;

                const std::vector<std::shared_ptr<IResponseData> > &getSaleArray() const override;

                bool setSalesArray(const std::vector<std::shared_ptr<IResponseData> > &salesArray) override;

                const std::vector<std::shared_ptr<IResponseData> > &getVoidArray() const override;

                bool setVoidArray(const std::vector<std::shared_ptr<IResponseData> > &voidArray) override;

                const std::vector<std::shared_ptr<IResponseData> > &getRefundArray() const override;

                bool setRefundArray(const std::vector<std::shared_ptr<IResponseData> > &refundArray) override;

                bool resetField(ResponseField field) override;

                bool resetEcrNumber() override;

                bool resetEcrMerchantNumber() override;

                bool resetOperationCode() override;

                bool resetOriginalOperationCode() override;

                bool resetTotalAmount() override;

                bool resetPartialAmount() override;

                bool resetAcquirerFeeAmount() override;

                bool resetTerminalFeeAmount() override;

                bool resetTipsAmount() override;

                bool resetCurrencyCode() override;

                bool resetReceiptReference() override;

                bool resetRRN() override;

                bool resetStatus() override;

                bool resetOriginalOperationStatus() override;

                bool resetTransDateTime() override;

                bool resetTerminalDateTime() override;

                bool resetCardPAN() override;

                bool resetExpireDate() override;

                bool resetCardholderName() override;

                bool resetCardholderAuthMethod() override;

                bool resetAuthCode() override;

                bool resetResponseCode() override;

                bool resetResponseText() override;

                bool resetSTAN() override;

                bool resetTransactionID() override;

                bool resetTerminalID() override;

                bool resetCardEmvAid() override;

                bool resetCardAppName() override;

                bool resetCardInputMethod() override;

                bool resetIssuerName() override;

                bool resetAdditionalInfo() override;

                bool resetCardData() override;

                bool resetCardDataEnc() override;

                bool resetMerchantID() override;

                bool resetTVR() override;

                bool resetTSI() override;

                bool resetTC() override;

                bool resetCID() override;

                bool resetKVR() override;

                bool resetCDAResult() override;

                bool resetSalesAmount() override;

                bool resetSalesCount() override;

                bool resetVoidAmount() override;

                bool resetVoidCount() override;

                bool resetRefundAmount() override;

                bool resetRefundCount() override;

                bool resetSalesArray() override;

                bool resetVoidArray() override;

                bool resetRefundArray() override;

            private:
                void initValidator();
                void deinitValidator();

                std::set<ResponseField> m_FieldsSet; ///< Список установленных полей

                std::shared_ptr<IValidator> m_Validator; ///< Валидатор полей операц

                int16_t m_EcrNumber = -1;
                int16_t m_EcrMerchantNumber = -1;

                OperationCode m_OperationCode = OperationCode::NoOperation;
                OperationCode m_OriginalOperationCode = OperationCode::NoOperation;

                int64_t m_TotalAmount = -1;
                int64_t m_PartialAmount = -1;
                int64_t m_AcquirerFeeAmount = -1;
                int64_t m_TerminalFeeAmount = -1;
                int64_t m_TipsAmount = -1;

                std::string m_CurrencyCode;
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
                int64_t m_SalesAmount = -1;
                int32_t m_SalesCount = -1;
                int64_t m_VoidAmount = -1;
                int32_t m_VoidCount = -1;
                int64_t m_RefundAmount = -1;
                int32_t m_RefundCount = -1;
                std::vector<std::shared_ptr<IResponseData> > m_SalesArray;
                std::vector<std::shared_ptr<IResponseData> > m_VoidArray;
                std::vector<std::shared_ptr<IResponseData> > m_RefundArray;

                std::set<ResponseField> m_EmptyFieldsPlaceholder; ///< Пустая коллекция для полей при отсутствии валидатора
            };
        }
    }//Message
}

#endif //LAN_4GATELIBRARYCPP_RESPONSEDATA_H
