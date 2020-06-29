//
// Created by Владимир Лысенков on 25.06.2020.
//

#include "ResponseData.h"

#include "Lanter/Utils/FieldRangeChecker.h"

using namespace Lanter::Utils;

namespace Lanter {
    namespace Response {
        ResponseData::ResponseData() {
            initValidator();
        }

        const std::set<ResponseFields> &ResponseData::getFieldsSet() const {
            return m_FieldsSet;
        }

        const std::set<ResponseFields> &ResponseData::getMandatoryFields() const {
            if(m_Validator) {
                return m_Validator->getMandatoryFields();
            }
            return m_EmptyFieldsPlaceholder;
        }

        const std::set<ResponseFields> &ResponseData::getOptionalFields() const {
            if(m_Validator){
                return m_Validator->getOptionalFields();
            }
            return m_EmptyFieldsPlaceholder;
        }

        bool ResponseData::validateMandatoryFields() {
            if(m_Validator) {
                return m_Validator->validate(getFieldsSet());
            }
            return false;
        }

        int16_t ResponseData::getEcrNumber() const {
            return m_EcrNumber;
        }

        void ResponseData::setEcrNumber(int16_t ecrNumber) {
            if (checkEcrNumberRange(ecrNumber)) {
                m_EcrNumber = ecrNumber;
                m_FieldsSet.insert(ResponseFields::EcrNumber);
            }
        }

        int16_t ResponseData::getEcrMerchantNumber() const {
            return m_EcrMerchantNumber;
        }

        void ResponseData::setEcrMerchantNumber(int16_t ecrMerchantNumber) {
            if(checkEcrMerchantNumberRange(ecrMerchantNumber)) {
                m_EcrMerchantNumber = ecrMerchantNumber;
                m_FieldsSet.insert(ResponseFields::EcrMerchantNumber);
            }
        }

        OperationCodes ResponseData::getOperationCode() const {
            return m_OperationCode;
        }

        void ResponseData::setOperationCode(OperationCodes operationCode) {
            if(checkOperationCodeRange(static_cast<uint32_t>(operationCode))) {
                m_OperationCode = operationCode;
                m_FieldsSet.insert(ResponseFields::OperationCode);
                initValidator();
            }
        }

        OperationCodes ResponseData::getOriginalOperationCode() const {
            return m_OriginalOperationCode;
        }

        void ResponseData::setOriginalOperationCode(OperationCodes originalOperationCode) {
            if(checkOperationCodeRange(static_cast<uint32_t>(originalOperationCode))) {
                m_OriginalOperationCode = originalOperationCode;
                m_FieldsSet.insert(ResponseFields::OriginalOperationCode);
            }
        }

        int64_t ResponseData::getTotalAmount() const {
            return m_TotalAmount;
        }

        void ResponseData::setTotalAmount(int64_t totalAmount) {
            if(checkAmountRange(totalAmount)) {
                m_TotalAmount = totalAmount;
                m_FieldsSet.insert(ResponseFields::TotalAmount);
            }
        }

        int64_t ResponseData::getPartialAmount() const {
            return m_PartialAmount;
        }

        void ResponseData::setPartialAmount(int64_t partialAmount) {
            if(checkAmountRange(partialAmount)) {
                m_PartialAmount = partialAmount;
                m_FieldsSet.insert(ResponseFields::PartialAmount);
            }
        }

        int64_t ResponseData::getAcquirerFeeAmount() const {
            return m_AmountAcquirerFee;
        }

        void ResponseData::setAcquirerFeeAmount(int64_t amountAcquirerFee) {
            if(checkAmountRange(amountAcquirerFee)) {
                m_AmountAcquirerFee = amountAcquirerFee;
                m_FieldsSet.insert(ResponseFields::AmountAcquirerFee);
            }
        }

        int64_t ResponseData::getTerminalFeeAmount() const {
            return m_AmountTerminalFee;
        }

        void ResponseData::setTerminalFeeAmount(int64_t amountTerminalFee) {
            if(checkAmountRange(amountTerminalFee)) {
                m_AmountTerminalFee = amountTerminalFee;
                m_FieldsSet.insert(ResponseFields::AmountTerminalFee);
            }
        }

        int64_t ResponseData::getTipsAmount() const {
            return m_TipsAmount;
        }

        void ResponseData::setTipsAmount(int64_t tipsAmount) {
            if(checkAmountRange(tipsAmount)) {
                m_TipsAmount = tipsAmount;
                m_FieldsSet.insert(ResponseFields::TipsAmount);
            }
        }

        int16_t ResponseData::getCurrencyCode() const {
            return m_CurrencyCode;
        }

        void ResponseData::setCurrencyCode(int16_t currencyCode) {
            if(checkCurrencyCodeRange(currencyCode)) {
                m_CurrencyCode = currencyCode;
                m_FieldsSet.insert(ResponseFields::CurrencyCode);
            }
        }

        const std::string &ResponseData::getReceiptReference() const {
            return m_ReceiptReference;
        }

        void ResponseData::setReceiptReference(const std::string &receiptReference) {
            if(checkReceiptReferenceRange(receiptReference)) {
                m_ReceiptReference = receiptReference;
                m_FieldsSet.insert(ResponseFields::ReceiptReference);
            }
        }

        const std::string &ResponseData::getRRN() const {
            return m_RRN;
        }

        void ResponseData::setRRN(const std::string &rrn) {
            if(checkRRNRange(rrn)) {
                m_RRN = rrn;
                m_FieldsSet.insert(ResponseFields::RRN);
            }
        }

        Status ResponseData::getStatus() const {
            return m_Status;
        }

        void ResponseData::setStatus(Status status) {
            if(checkStatusRange(static_cast<int32_t>(status))) {
                m_Status = status;
                m_FieldsSet.insert(ResponseFields::Status);
            }
        }

        Status ResponseData::getOriginalOperationStatus() const {
            return m_OriginalOperationStatus;
        }

        void ResponseData::setOriginalOperationStatus(Status originalOperationStatus) {
            if(checkStatusRange(static_cast<int32_t>(originalOperationStatus))) {
                m_OriginalOperationStatus = originalOperationStatus;
                m_FieldsSet.insert(ResponseFields::OriginalOperationStatus);
            }
        }

        const std::string &ResponseData::getTransDateTime() const {
            return m_TransDateTime;
        }

        void ResponseData::setTransDateTime(const std::string &transDateTime) {
            if(checkTransDateTimeRange(transDateTime)) {
                m_TransDateTime = transDateTime;
                m_FieldsSet.insert(ResponseFields::TransDateTime);
            }
        }

        const std::string &ResponseData::getTerminalDateTime() const {
            return m_TerminalDateTime;
        }

        void ResponseData::setTerminalDateTime(const std::string &terminalDateTime) {
            if(checkTerminalDateTimeRange(terminalDateTime)) {
                m_TerminalDateTime = terminalDateTime;
                m_FieldsSet.insert(ResponseFields::TerminalDateTime);
            }
        }

        const std::string &ResponseData::getCardPan() const {
            return m_CardPAN;
        }

        void ResponseData::setCardPan(const std::string &cardPan) {
            if(checkCardPANRange(cardPan)) {
                m_CardPAN = cardPan;
                m_FieldsSet.insert(ResponseFields::CardPAN);
            }
        }

        const std::string &ResponseData::getExpireDate() const {
            return m_ExpireDate;
        }

        void ResponseData::setExpireDate(const std::string &expireDate) {
            if(checkExpireDateRange(expireDate)) {
                m_ExpireDate = expireDate;
                m_FieldsSet.insert(ResponseFields::ExpireDate);
            }
        }

        const std::string &ResponseData::getCardholderName() const {
            return m_CardholderName;
        }

        void ResponseData::setCardholderName(const std::string &cardholderName) {
            if(checkCardholderNameRange(cardholderName)) {
                m_CardholderName = cardholderName;
                m_FieldsSet.insert(ResponseFields::CardholderName);
            }
        }

        CardholderAuthMethod ResponseData::getCardholderAuthMethod() const {
            return m_CardholderAuthMethod;
        }

        void ResponseData::setCardholderAuthMethod(CardholderAuthMethod cardholderAuthMethod) {
            if(checkCardholderAuthMethodRange(static_cast<int32_t>(cardholderAuthMethod))) {
                m_CardholderAuthMethod = cardholderAuthMethod;
                m_FieldsSet.insert(ResponseFields::CardholderAuthMethod);
            }
        }

        const std::string &ResponseData::getAuthCode() const {
            return m_AuthCode;
        }

        void ResponseData::setAuthCode(const std::string &authCode) {
            if(checkAuthCodeRange(authCode)) {
                m_AuthCode = authCode;
                m_FieldsSet.insert(ResponseFields::AuthCode);
            }
        }

        const std::string &ResponseData::getResponseCode() const {
            return m_ResponseCode;
        }

        void ResponseData::setResponseCode(const std::string &responseCode) {
            if(checkResponseCodeRange(responseCode)) {
                m_ResponseCode = responseCode;
                m_FieldsSet.insert(ResponseFields::ResponseCode);
            }
        }

        const std::string &ResponseData::getResponseText() const {
            return m_ResponseText;
        }

        void ResponseData::setResponseText(const std::string &responseText) {
            if(checkResponseTextRange(responseText)) {
                m_ResponseText = responseText;
                m_FieldsSet.insert(ResponseFields::ResponseText);
            }
        }

        const std::string &ResponseData::getSTAN() const {
            return m_STAN;
        }

        void ResponseData::setSTAN(const std::string &stan) {
            if(checkSTANRange(stan)) {
                m_STAN = stan;
                m_FieldsSet.insert(ResponseFields::STAN);
            }
        }

        const std::string &ResponseData::getTransactionID() const {
            return m_TransactionID;
        }

        void ResponseData::setTransactionID(const std::string &transactionId) {
            if(checkTransactionIDRange(transactionId)) {
                m_TransactionID = transactionId;
                m_FieldsSet.insert(ResponseFields::TransactionID);
            }
        }

        const std::string &ResponseData::getTerminalID() const {
            return m_TerminalID;
        }

        void ResponseData::setTerminalID(const std::string &terminalId) {
            if(checkTerminalIDRange(terminalId)) {
                m_TerminalID = terminalId;
                m_FieldsSet.insert(ResponseFields::TerminalID);
            }
        }

        const std::string &ResponseData::getCardEmvAid() const {
            return m_CardEmvAid;
        }

        void ResponseData::setCardEmvAid(const std::string &cardEmvAid) {
            if(checkCardEmvAidRange(cardEmvAid)) {
                m_CardEmvAid = cardEmvAid;
                m_FieldsSet.insert(ResponseFields::CardEmvAid);
            }
        }

        const std::string &ResponseData::getCardAppName() const {
            return m_CardAppName;
        }

        void ResponseData::setCardAppName(const std::string &cardAppName) {
            if(checkCardAppNameRange(cardAppName)) {
                m_CardAppName = cardAppName;
                m_FieldsSet.insert(ResponseFields::CardAppName);
            }
        }

        CardInputMethod ResponseData::getCardInputMethod() const {
            return m_CardInputMethod;
        }

        void ResponseData::setCardInputMethod(Response::CardInputMethod cardInputMethod) {
            if(checkCardInputMethodRange(static_cast<uint32_t>(cardInputMethod))) {
                m_CardInputMethod = cardInputMethod;
                m_FieldsSet.insert(ResponseFields::CardInputMethod);
            }
        }

        const std::string &ResponseData::getIssuerName() const {
            return m_IssuerName;
        }

        void ResponseData::setIssuerName(const std::string &issuerName) {
            if(checkIssuerNameRange(issuerName)) {
                m_IssuerName = issuerName;
                m_FieldsSet.insert(ResponseFields::IssuerName);
            }
        }

        const std::string &ResponseData::getAdditionalInfo() const {
            return m_AdditionalInfo;
        }

        void ResponseData::setAdditionalInfo(const std::string &additionalInfo) {
            if(checkAdditionalInfoRange(additionalInfo)) {
                m_AdditionalInfo = additionalInfo;
                m_FieldsSet.insert(ResponseFields::AdditionalInfo);
            }
        }

        const std::string &ResponseData::getCardData() const {
            return m_CardData;
        }

        void ResponseData::setCardData(const std::string &cardData) {
            if(checkCardDataRange(cardData)) {
                m_CardData = cardData;
                m_FieldsSet.insert(ResponseFields::CardData);
            }
        }

        const std::string &ResponseData::getCardDataEnc() const {
            return m_CardDataEnc;
        }

        void ResponseData::setCardDataEnc(const std::string &cardDataEnc) {
            if(checkCardDataEncRange(cardDataEnc)) {
                m_CardDataEnc = cardDataEnc;
                m_FieldsSet.insert(ResponseFields::CardDataEnc);
            }
        }

        const std::string &ResponseData::getMerchantID() const {
            return m_MerchantID;
        }

        void ResponseData::setMerchantID(const std::string &merchantId) {
            if(checkMerchantIDRange(merchantId)) {
                m_MerchantID = merchantId;
                m_FieldsSet.insert(ResponseFields::MerchantID);
            }
        }

        const std::string &ResponseData::getTVR() const {
            return m_TVR;
        }

        void ResponseData::setTVR(const std::string &tvr) {
            if(checkTVRRange(tvr)) {
                m_TVR = tvr;
                m_FieldsSet.insert(ResponseFields::TVR);
            }
        }

        const std::string &ResponseData::getTSI() const {
            return m_TSI;
        }

        void ResponseData::setTSI(const std::string &tsi) {
            if(checkTSIRange(tsi)) {
                m_TSI = tsi;
                m_FieldsSet.insert(ResponseFields::TSI);
            }
        }

        const std::string &ResponseData::getTC() const {
            return m_TC;
        }

        void ResponseData::setTC(const std::string &tc) {
            if(checkTCRange(tc)) {
                m_TC = tc;
                m_FieldsSet.insert(ResponseFields::TC);
            }
        }

        const std::string &ResponseData::getCID() const {
            return m_CID;
        }

        void ResponseData::setCID(const std::string &cid) {
            if(checkCIDRange(cid)) {
                m_CID = cid;
                m_FieldsSet.insert(ResponseFields::CID);
            }
        }

        const std::string &ResponseData::getKVR() const {
            return m_KVR;
        }

        void ResponseData::setKVR(const std::string &kvr) {
            if(checkKVRRange(kvr)) {
                m_KVR = kvr;
                m_FieldsSet.insert(ResponseFields::KVR);
            }
        }

        const std::string &ResponseData::getCDAResult() const {
            return m_CDAResult;
        }

        void ResponseData::setCDAResult(const std::string &cdaResult) {
            if(checkCDAResultRange(cdaResult)) {
                m_CDAResult = cdaResult;
                m_FieldsSet.insert(ResponseFields::CDAResult);
            }
        }

        int32_t ResponseData::getSalesCount() const {
            return m_SalesCount;
        }

        void ResponseData::setSalesCount(int32_t salesCount) {
            if(checkSalesCountRange(salesCount)) {
                m_SalesCount = salesCount;
                m_FieldsSet.insert(ResponseFields::SalesCount);
            }
        }

        int32_t ResponseData::getVoidCount() const {
            return m_VoidCount;
        }

        void ResponseData::setVoidCount(int32_t voidCount) {
            if(checkVoidCountRange(voidCount)) {
                m_VoidCount = voidCount;
                m_FieldsSet.insert(ResponseFields::VoidCount);
            }
        }

        int32_t ResponseData::getRefundCount() const {
            return m_RefundCount;
        }

        void ResponseData::setRefundCount(int32_t refundCount) {
            if(checkRefundCountRange(refundCount)) {
                m_RefundCount = refundCount;
                m_FieldsSet.insert(ResponseFields::RefundCount);
            }
        }

        const std::vector<std::shared_ptr<IResponseData> > &ResponseData::getSalesArray() const {
            return m_SalesArray;
        }

        void ResponseData::setSalesArray(const std::vector<std::shared_ptr<IResponseData> > &salesArray) {
            m_SalesArray = salesArray;
            m_FieldsSet.insert(ResponseFields::SalesArray);
        }

        const std::vector<std::shared_ptr<IResponseData> > &ResponseData::getVoidArray() const {
            return m_VoidArray;
        }

        void ResponseData::setVoidArray(const std::vector<std::shared_ptr<IResponseData> > &voidArray) {
            m_VoidArray = voidArray;
            m_FieldsSet.insert(ResponseFields::VoidArray);
        }

        const std::vector<std::shared_ptr<IResponseData> > &ResponseData::getRefundArray() const {
            return m_RefundArray;
        }

        void ResponseData::setRefundArray(const std::vector<std::shared_ptr<IResponseData> > &refundArray) {
            m_RefundArray = refundArray;
            m_FieldsSet.insert(ResponseFields::RefundArray);
        }

        void ResponseData::initValidator() {

        }
    }
}