//
// Created by Владимир Лысенков on 25.06.2020.
//

#include "ResponseData.h"

#include "Lanter/Utils/FieldRangeChecker.h"
#include "Lanter/Message/Response/Validators/ValidatorFactory.h"

using namespace Lanter::Utils;

namespace Lanter {
    namespace Message {
        namespace Response {
            ResponseData::ResponseData() {
                initValidator();
            }

            const std::set<ResponseFields> &ResponseData::getFieldsSet() const {
                return m_FieldsSet;
            }

            bool ResponseData::isFieldSet(ResponseFields field) const {
                return m_FieldsSet.find(field) != m_FieldsSet.end();
            }

            const std::set<ResponseFields> &ResponseData::getMandatoryFields() const {
                if (m_Validator) {
                    return m_Validator->getMandatoryFields();
                }
                return m_EmptyFieldsPlaceholder;
            }

            const std::set<ResponseFields> &ResponseData::getOptionalFields() const {
                if (m_Validator) {
                    return m_Validator->getOptionalFields();
                }
                return m_EmptyFieldsPlaceholder;
            }

            bool ResponseData::validateMandatoryFields() const {
                if (m_Validator) {
                    return m_Validator->validate(getFieldsSet());
                }
                return false;
            }

            int16_t ResponseData::getEcrNumber() const {
                return m_EcrNumber;
            }

            bool ResponseData::setEcrNumber(int16_t ecrNumber) {
                bool result = false;
                if (checkEcrNumberRange(ecrNumber)) {
                    m_EcrNumber = ecrNumber;
                    m_FieldsSet.insert(ResponseFields::EcrNumber);
                    result = true;
                }
                return result;
            }

            int16_t ResponseData::getEcrMerchantNumber() const {
                return m_EcrMerchantNumber;
            }

            bool ResponseData::setEcrMerchantNumber(int16_t ecrMerchantNumber) {
                bool result = false;
                if (checkEcrMerchantNumberRange(ecrMerchantNumber)) {
                    m_EcrMerchantNumber = ecrMerchantNumber;
                    m_FieldsSet.insert(ResponseFields::EcrMerchantNumber);
                    result = true;
                }
                return result;
            }

            OperationCode ResponseData::getOperationCode() const {
                return m_OperationCode;
            }

            bool ResponseData::setOperationCode(OperationCode operationCode) {
                bool result = false;
                if (checkOperationCodeRange(static_cast<int32_t>(operationCode))) {
                    if (m_OperationCode != operationCode) {
                        m_OperationCode = operationCode;
                        m_FieldsSet.insert(ResponseFields::OperationCode);
                        initValidator();
                    }
                    result = true;
                }
                return result;
            }

            OperationCode ResponseData::getOriginalOperationCode() const {
                return m_OriginalOperationCode;
            }

            bool ResponseData::setOriginalOperationCode(OperationCode originalOperationCode) {
                bool result = false;
                if (checkOperationCodeRange(static_cast<uint32_t>(originalOperationCode))) {
                    m_OriginalOperationCode = originalOperationCode;
                    m_FieldsSet.insert(ResponseFields::OriginalOperationCode);
                    result = true;
                }
                return result;
            }

            int64_t ResponseData::getTotalAmount() const {
                return m_TotalAmount;
            }

            bool ResponseData::setTotalAmount(int64_t totalAmount) {
                bool result = false;
                if (checkAmountRange(totalAmount)) {
                    m_TotalAmount = totalAmount;
                    m_FieldsSet.insert(ResponseFields::TotalAmount);
                    result = true;
                }
                return result;
            }

            int64_t ResponseData::getPartialAmount() const {
                return m_PartialAmount;
            }

            bool ResponseData::setPartialAmount(int64_t partialAmount) {
                bool result = false;
                if (checkAmountRange(partialAmount)) {
                    m_PartialAmount = partialAmount;
                    m_FieldsSet.insert(ResponseFields::PartialAmount);
                    result = true;
                }
                return result;
            }

            int64_t ResponseData::getAcquirerFeeAmount() const {
                return m_AcquirerFeeAmount;
            }

            bool ResponseData::setAcquirerFeeAmount(int64_t amountAcquirerFee) {
                bool result = false;
                if (checkAmountRange(amountAcquirerFee)) {
                    m_AcquirerFeeAmount = amountAcquirerFee;
                    m_FieldsSet.insert(ResponseFields::AcquirerFeeAmount);
                    result = true;
                }
                return result;
            }

            int64_t ResponseData::getTerminalFeeAmount() const {
                return m_TerminalFeeAmount;
            }

            bool ResponseData::setTerminalFeeAmount(int64_t amountTerminalFee) {
                bool result = false;
                if (checkAmountRange(amountTerminalFee)) {
                    m_TerminalFeeAmount = amountTerminalFee;
                    m_FieldsSet.insert(ResponseFields::TerminalFeeAmount);
                    result = true;
                }
                return result;
            }

            int64_t ResponseData::getTipsAmount() const {
                return m_TipsAmount;
            }

            bool ResponseData::setTipsAmount(int64_t tipsAmount) {
                bool result = false;
                if (checkAmountRange(tipsAmount)) {
                    m_TipsAmount = tipsAmount;
                    m_FieldsSet.insert(ResponseFields::TipsAmount);
                    result = true;
                }
                return result;
            }

            int16_t ResponseData::getCurrencyCode() const {
                return m_CurrencyCode;
            }

            bool ResponseData::setCurrencyCode(int16_t currencyCode) {
                bool result = false;
                if (checkCurrencyCodeRange(currencyCode)) {
                    m_CurrencyCode = currencyCode;
                    m_FieldsSet.insert(ResponseFields::CurrencyCode);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getReceiptReference() const {
                return m_ReceiptReference;
            }

            bool ResponseData::setReceiptReference(const std::string &receiptReference) {
                bool result = false;
                if (checkReceiptReferenceRange(receiptReference)) {
                    m_ReceiptReference = receiptReference;
                    m_FieldsSet.insert(ResponseFields::ReceiptReference);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getRRN() const {
                return m_RRN;
            }

            bool ResponseData::setRRN(const std::string &rrn) {
                bool result = false;
                if (checkRRNRange(rrn)) {
                    m_RRN = rrn;
                    m_FieldsSet.insert(ResponseFields::RRN);
                    result = true;
                }
                return result;
            }

            Status ResponseData::getStatus() const {
                return m_Status;
            }

            bool ResponseData::setStatus(Status status) {
                bool result = false;
                if (checkStatusRange(static_cast<int32_t>(status))) {
                    m_Status = status;
                    m_FieldsSet.insert(ResponseFields::Status);
                    result = true;
                }
                return result;
            }

            Status ResponseData::getOriginalOperationStatus() const {
                return m_OriginalOperationStatus;
            }

            bool ResponseData::setOriginalOperationStatus(Status originalOperationStatus) {
                bool result = false;
                if (checkStatusRange(static_cast<int32_t>(originalOperationStatus))) {
                    m_OriginalOperationStatus = originalOperationStatus;
                    m_FieldsSet.insert(ResponseFields::OriginalOperationStatus);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getTransDateTime() const {
                return m_TransDateTime;
            }

            bool ResponseData::setTransDateTime(const std::string &transDateTime) {
                bool result = false;
                if (checkTransDateTimeRange(transDateTime)) {
                    m_TransDateTime = transDateTime;
                    m_FieldsSet.insert(ResponseFields::TransDateTime);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getTerminalDateTime() const {
                return m_TerminalDateTime;
            }

            bool ResponseData::setTerminalDateTime(const std::string &terminalDateTime) {
                bool result = false;
                if (checkTerminalDateTimeRange(terminalDateTime)) {
                    m_TerminalDateTime = terminalDateTime;
                    m_FieldsSet.insert(ResponseFields::TerminalDateTime);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getCardPAN() const {
                return m_CardPAN;
            }

            bool ResponseData::setCardPAN(const std::string &cardPan) {
                bool result = false;
                if (checkCardPANRange(cardPan)) {
                    m_CardPAN = cardPan;
                    m_FieldsSet.insert(ResponseFields::CardPAN);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getExpireDate() const {
                return m_ExpireDate;
            }

            bool ResponseData::setExpireDate(const std::string &expireDate) {
                bool result = false;
                if (checkExpireDateRange(expireDate)) {
                    m_ExpireDate = expireDate;
                    m_FieldsSet.insert(ResponseFields::ExpireDate);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getCardholderName() const {
                return m_CardholderName;
            }

            bool ResponseData::setCardholderName(const std::string &cardholderName) {
                bool result = false;
                if (checkCardholderNameRange(cardholderName)) {
                    m_CardholderName = cardholderName;
                    m_FieldsSet.insert(ResponseFields::CardholderName);
                    result = true;
                }
                return result;
            }

            CardholderAuthMethod ResponseData::getCardholderAuthMethod() const {
                return m_CardholderAuthMethod;
            }

            bool ResponseData::setCardholderAuthMethod(CardholderAuthMethod cardholderAuthMethod) {
                bool result = false;
                if (checkCardholderAuthMethodRange(static_cast<int32_t>(cardholderAuthMethod))) {
                    m_CardholderAuthMethod = cardholderAuthMethod;
                    m_FieldsSet.insert(ResponseFields::CardholderAuthMethod);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getAuthCode() const {
                return m_AuthCode;
            }

            bool ResponseData::setAuthCode(const std::string &authCode) {
                bool result = false;
                if (checkAuthCodeRange(authCode)) {
                    m_AuthCode = authCode;
                    m_FieldsSet.insert(ResponseFields::AuthCode);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getResponseCode() const {
                return m_ResponseCode;
            }

            bool ResponseData::setResponseCode(const std::string &responseCode) {
                bool result = false;
                if (checkResponseCodeRange(responseCode)) {
                    m_ResponseCode = responseCode;
                    m_FieldsSet.insert(ResponseFields::ResponseCode);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getResponseText() const {
                return m_ResponseText;
            }

            bool ResponseData::setResponseText(const std::string &responseText) {
                bool result = false;
                if (checkResponseTextRange(responseText)) {
                    m_ResponseText = responseText;
                    m_FieldsSet.insert(ResponseFields::ResponseText);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getSTAN() const {
                return m_STAN;
            }

            bool ResponseData::setSTAN(const std::string &stan) {
                bool result = false;
                if (checkSTANRange(stan)) {
                    m_STAN = stan;
                    m_FieldsSet.insert(ResponseFields::STAN);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getTransactionID() const {
                return m_TransactionID;
            }

            bool ResponseData::setTransactionID(const std::string &transactionId) {
                bool result = false;
                if (checkTransactionIDRange(transactionId)) {
                    m_TransactionID = transactionId;
                    m_FieldsSet.insert(ResponseFields::TransactionID);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getTerminalID() const {
                return m_TerminalID;
            }

            bool ResponseData::setTerminalID(const std::string &terminalId) {
                bool result = false;
                if (checkTerminalIDRange(terminalId)) {
                    m_TerminalID = terminalId;
                    m_FieldsSet.insert(ResponseFields::TerminalID);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getCardEmvAid() const {
                return m_CardEmvAid;
            }

            bool ResponseData::setCardEmvAid(const std::string &cardEmvAid) {
                bool result = false;
                if (checkCardEmvAidRange(cardEmvAid)) {
                    m_CardEmvAid = cardEmvAid;
                    m_FieldsSet.insert(ResponseFields::CardEmvAid);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getCardAppName() const {
                return m_CardAppName;
            }

            bool ResponseData::setCardAppName(const std::string &cardAppName) {
                bool result = false;
                if (checkCardAppNameRange(cardAppName)) {
                    m_CardAppName = cardAppName;
                    m_FieldsSet.insert(ResponseFields::CardAppName);
                    result = true;
                }
                return result;
            }

            CardInputMethod ResponseData::getCardInputMethod() const {
                return m_CardInputMethod;
            }

            bool ResponseData::setCardInputMethod(Response::CardInputMethod cardInputMethod) {
                bool result = false;
                if (checkCardInputMethodRange(static_cast<uint32_t>(cardInputMethod))) {
                    m_CardInputMethod = cardInputMethod;
                    m_FieldsSet.insert(ResponseFields::CardInputMethod);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getIssuerName() const {
                return m_IssuerName;
            }

            bool ResponseData::setIssuerName(const std::string &issuerName) {
                bool result = false;
                if (checkIssuerNameRange(issuerName)) {
                    m_IssuerName = issuerName;
                    m_FieldsSet.insert(ResponseFields::IssuerName);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getAdditionalInfo() const {
                return m_AdditionalInfo;
            }

            bool ResponseData::setAdditionalInfo(const std::string &additionalInfo) {
                bool result = false;
                if (checkAdditionalInfoRange(additionalInfo)) {
                    m_AdditionalInfo = additionalInfo;
                    m_FieldsSet.insert(ResponseFields::AdditionalInfo);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getCardData() const {
                return m_CardData;
            }

            bool ResponseData::setCardData(const std::string &cardData) {
                bool result = false;
                if (checkCardDataRange(cardData)) {
                    m_CardData = cardData;
                    m_FieldsSet.insert(ResponseFields::CardData);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getCardDataEnc() const {
                return m_CardDataEnc;
            }

            bool ResponseData::setCardDataEnc(const std::string &cardDataEnc) {
                bool result = false;
                if (checkCardDataEncRange(cardDataEnc)) {
                    m_CardDataEnc = cardDataEnc;
                    m_FieldsSet.insert(ResponseFields::CardDataEnc);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getMerchantID() const {
                return m_MerchantID;
            }

            bool ResponseData::setMerchantID(const std::string &merchantId) {
                bool result = false;
                if (checkMerchantIDRange(merchantId)) {
                    m_MerchantID = merchantId;
                    m_FieldsSet.insert(ResponseFields::MerchantID);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getTVR() const {
                return m_TVR;
            }

            bool ResponseData::setTVR(const std::string &tvr) {
                bool result = false;
                if (checkTVRRange(tvr)) {
                    m_TVR = tvr;
                    m_FieldsSet.insert(ResponseFields::TVR);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getTSI() const {
                return m_TSI;
            }

            bool ResponseData::setTSI(const std::string &tsi) {
                bool result = false;
                if (checkTSIRange(tsi)) {
                    m_TSI = tsi;
                    m_FieldsSet.insert(ResponseFields::TSI);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getTC() const {
                return m_TC;
            }

            bool ResponseData::setTC(const std::string &tc) {
                bool result = false;
                if (checkTCRange(tc)) {
                    m_TC = tc;
                    m_FieldsSet.insert(ResponseFields::TC);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getCID() const {
                return m_CID;
            }

            bool ResponseData::setCID(const std::string &cid) {
                bool result = false;
                if (checkCIDRange(cid)) {
                    m_CID = cid;
                    m_FieldsSet.insert(ResponseFields::CID);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getKVR() const {
                return m_KVR;
            }

            bool ResponseData::setKVR(const std::string &kvr) {
                bool result = false;
                if (checkKVRRange(kvr)) {
                    m_KVR = kvr;
                    m_FieldsSet.insert(ResponseFields::KVR);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getCDAResult() const {
                return m_CDAResult;
            }

            bool ResponseData::setCDAResult(const std::string &cdaResult) {
                bool result = false;
                if (checkCDAResultRange(cdaResult)) {
                    m_CDAResult = cdaResult;
                    m_FieldsSet.insert(ResponseFields::CDAResult);
                    result = true;
                }
                return result;
            }

            int32_t ResponseData::getSalesCount() const {
                return m_SalesCount;
            }

            bool ResponseData::setSalesCount(int32_t salesCount) {
                bool result = false;
                if (checkSalesCountRange(salesCount)) {
                    m_SalesCount = salesCount;
                    m_FieldsSet.insert(ResponseFields::SaleCount);
                    result = true;
                }
                return result;
            }

            int32_t ResponseData::getVoidCount() const {
                return m_VoidCount;
            }

            bool ResponseData::setVoidCount(int32_t voidCount) {
                bool result = false;
                if (checkVoidCountRange(voidCount)) {
                    m_VoidCount = voidCount;
                    m_FieldsSet.insert(ResponseFields::VoidCount);
                    result = true;
                }
                return result;
            }

            int32_t ResponseData::getRefundCount() const {
                return m_RefundCount;
            }

            bool ResponseData::setRefundCount(int32_t refundCount) {
                bool result = false;
                if (checkRefundCountRange(refundCount)) {
                    m_RefundCount = refundCount;
                    m_FieldsSet.insert(ResponseFields::RefundCount);
                    result = true;
                }
                return result;
            }

            const std::vector<std::shared_ptr<IResponseData> > &ResponseData::getSaleArray() const {
                return m_SalesArray;
            }

            bool ResponseData::setSalesArray(const std::vector<std::shared_ptr<IResponseData> > &salesArray) {
                bool result = false;
                if(!salesArray.empty()) {
                    m_SalesArray = salesArray;
                    m_FieldsSet.insert(ResponseFields::SaleArray);
                    result = true;
                }
                return result;
            }

            const std::vector<std::shared_ptr<IResponseData> > &ResponseData::getVoidArray() const {
                return m_VoidArray;
            }

            bool ResponseData::setVoidArray(const std::vector<std::shared_ptr<IResponseData> > &voidArray) {
                bool result = false;
                if(!voidArray.empty()) {
                    m_VoidArray = voidArray;
                    m_FieldsSet.insert(ResponseFields::VoidArray);
                    result = true;
                }
                return result;
            }

            const std::vector<std::shared_ptr<IResponseData> > &ResponseData::getRefundArray() const {
                return m_RefundArray;
            }

            bool ResponseData::setRefundArray(const std::vector<std::shared_ptr<IResponseData> > &refundArray) {
                bool result = false;
                if(!refundArray.empty()) {
                    m_RefundArray = refundArray;
                    m_FieldsSet.insert(ResponseFields::RefundArray);
                    result = true;
                }
                return result;
            }

            void ResponseData::initValidator() {
                m_Validator = ValidatorFactory::getValidator(getOperationCode());
            }

            void ResponseData::deinitValidator() {
                m_Validator.reset();
            }

            bool ResponseData::resetField(ResponseFields field) {
                bool result = false;

                switch (field) {

                    case ResponseFields::EcrNumber:
                        result = resetEcrNumber();
                        break;
                    case ResponseFields::EcrMerchantNumber:
                        result = resetEcrMerchantNumber();
                        break;
                    case ResponseFields::OperationCode:
                        result = resetOperationCode();
                        break;
                    case ResponseFields::OriginalOperationCode:
                        result = resetOriginalOperationCode();
                        break;
                    case ResponseFields::TotalAmount:
                        result = resetTotalAmount();
                        break;
                    case ResponseFields::PartialAmount:
                        result = resetPartialAmount();
                        break;
                    case ResponseFields::AcquirerFeeAmount:
                        result = resetAcquirerFeeAmount();
                        break;
                    case ResponseFields::TerminalFeeAmount:
                        result = resetTerminalFeeAmount();
                        break;
                    case ResponseFields::TipsAmount:
                        result = resetTipsAmount();
                        break;
                    case ResponseFields::CurrencyCode:
                        result = resetCurrencyCode();
                        break;
                    case ResponseFields::ReceiptReference:
                        result = resetReceiptReference();
                        break;
                    case ResponseFields::RRN:
                        result = resetRRN();
                        break;
                    case ResponseFields::Status:
                        result = resetStatus();
                        break;
                    case ResponseFields::OriginalOperationStatus:
                        result = resetOriginalOperationStatus();
                        break;
                    case ResponseFields::TransDateTime:
                        result = resetTransDateTime();
                        break;
                    case ResponseFields::TerminalDateTime:
                        result = resetTerminalDateTime();
                        break;
                    case ResponseFields::CardPAN:
                        result = resetCardPAN();
                        break;
                    case ResponseFields::ExpireDate:
                        result = resetExpireDate();
                        break;
                    case ResponseFields::CardholderName:
                        result = resetCardholderName();
                        break;
                    case ResponseFields::CardholderAuthMethod:
                        result = resetCardholderAuthMethod();
                        break;
                    case ResponseFields::AuthCode:
                        result = resetAuthCode();
                        break;
                    case ResponseFields::ResponseCode:
                        result = resetResponseCode();
                        break;
                    case ResponseFields::ResponseText:
                        result = resetResponseText();
                        break;
                    case ResponseFields::STAN:
                        result = resetSTAN();
                        break;
                    case ResponseFields::TransactionID:
                        result = resetTransactionID();
                        break;
                    case ResponseFields::TerminalID:
                        result = resetTerminalID();
                        break;
                    case ResponseFields::CardEmvAid:
                        result = resetCardEmvAid();
                        break;
                    case ResponseFields::CardAppName:
                        result = resetCardAppName();
                        break;
                    case ResponseFields::CardInputMethod:
                        result = resetCardInputMethod();
                        break;
                    case ResponseFields::IssuerName:
                        result = resetIssuerName();
                        break;
                    case ResponseFields::AdditionalInfo:
                        result = resetAdditionalInfo();
                        break;
                    case ResponseFields::CardData:
                        result = resetCardData();
                        break;
                    case ResponseFields::CardDataEnc:
                        result = resetCardDataEnc();
                        break;
                    case ResponseFields::MerchantID:
                        result = resetMerchantID();
                        break;
                    case ResponseFields::TVR:
                        result = resetTVR();
                        break;
                    case ResponseFields::TSI:
                        result = resetTSI();
                        break;
                    case ResponseFields::TC:
                        result = resetTC();
                        break;
                    case ResponseFields::CID:
                        result = resetCID();
                        break;
                    case ResponseFields::KVR:
                        result = resetKVR();
                        break;
                    case ResponseFields::CDAResult:
                        result = resetCDAResult();
                        break;
                    case ResponseFields::SaleCount:
                        result = resetSalesCount();
                        break;
                    case ResponseFields::VoidCount:
                        result = resetVoidCount();
                        break;
                    case ResponseFields::RefundCount:
                        result = resetRefundCount();
                        break;
                    case ResponseFields::SaleArray:
                        result = resetSalesArray();
                        break;
                    case ResponseFields::VoidArray:
                        result = resetVoidArray();
                        break;
                    case ResponseFields::RefundArray:
                        result = resetRefundArray();
                        break;
                }

                return result;
            }

            bool ResponseData::resetEcrNumber() {
                m_EcrNumber = -1;
                m_FieldsSet.erase(ResponseFields::EcrNumber);
                return !isFieldSet(ResponseFields::EcrNumber);
            }

            bool ResponseData::resetEcrMerchantNumber() {
                m_EcrMerchantNumber = -1;
                m_FieldsSet.erase(ResponseFields::EcrMerchantNumber);
                return !isFieldSet(ResponseFields::EcrMerchantNumber);
            }

            bool ResponseData::resetOperationCode() {
                m_OperationCode = OperationCode::NoOperation;
                m_FieldsSet.erase(ResponseFields::OperationCode);
                deinitValidator();
                return !isFieldSet(ResponseFields::OperationCode);
            }

            bool ResponseData::resetOriginalOperationCode() {
                m_OriginalOperationCode = OperationCode::NoOperation;
                m_FieldsSet.erase(ResponseFields::OriginalOperationCode);
                return !isFieldSet(ResponseFields::OriginalOperationCode);
            }

            bool ResponseData::resetTotalAmount() {
                m_TotalAmount = -1;
                m_FieldsSet.erase(ResponseFields::TotalAmount);
                return !isFieldSet(ResponseFields::TotalAmount);
            }

            bool ResponseData::resetPartialAmount() {
                m_PartialAmount = -1;
                m_FieldsSet.erase(ResponseFields::PartialAmount);
                return !isFieldSet(ResponseFields::PartialAmount);
            }

            bool ResponseData::resetAcquirerFeeAmount() {
                m_AcquirerFeeAmount = -1;
                m_FieldsSet.erase(ResponseFields::AcquirerFeeAmount);
                return !isFieldSet(ResponseFields::AcquirerFeeAmount);
            }

            bool ResponseData::resetTerminalFeeAmount() {
                m_TerminalFeeAmount = -1;
                m_FieldsSet.erase(ResponseFields::TerminalFeeAmount);
                return !isFieldSet(ResponseFields::TerminalFeeAmount);
            }

            bool ResponseData::resetTipsAmount() {
                m_TipsAmount = -1;
                m_FieldsSet.erase(ResponseFields::TipsAmount);
                return !isFieldSet(ResponseFields::TipsAmount);
            }

            bool ResponseData::resetCurrencyCode() {
                m_CurrencyCode = -1;
                m_FieldsSet.erase(ResponseFields::CurrencyCode);
                return !isFieldSet(ResponseFields::CurrencyCode);
            }

            bool ResponseData::resetReceiptReference() {
                m_ReceiptReference.clear();
                m_FieldsSet.erase(ResponseFields::ReceiptReference);
                return !isFieldSet(ResponseFields::ReceiptReference);
            }

            bool ResponseData::resetRRN() {
                m_RRN.clear();
                m_FieldsSet.erase(ResponseFields::RRN);
                return !isFieldSet(ResponseFields::RRN);
            }

            bool ResponseData::resetStatus() {
                m_Status = Status::NoStatus;
                m_FieldsSet.erase(ResponseFields::Status);
                return !isFieldSet(ResponseFields::Status);
            }

            bool ResponseData::resetOriginalOperationStatus() {
                m_OriginalOperationStatus = Status::NoStatus;
                m_FieldsSet.erase(ResponseFields::OriginalOperationStatus);
                return !isFieldSet(ResponseFields::OriginalOperationStatus);
            }

            bool ResponseData::resetTransDateTime() {
                m_TransDateTime.clear();
                m_FieldsSet.erase(ResponseFields::TransDateTime);
                return !isFieldSet(ResponseFields::TransDateTime);
            }

            bool ResponseData::resetTerminalDateTime() {
                m_TerminalDateTime.clear();
                m_FieldsSet.erase(ResponseFields::TerminalDateTime);
                return !isFieldSet(ResponseFields::TerminalDateTime);
            }

            bool ResponseData::resetCardPAN() {
                m_CardPAN.clear();
                m_FieldsSet.erase(ResponseFields::CardPAN);
                return !isFieldSet(ResponseFields::CardPAN);
            }

            bool ResponseData::resetExpireDate() {
                m_ExpireDate.clear();
                m_FieldsSet.erase(ResponseFields::ExpireDate);
                return !isFieldSet(ResponseFields::ExpireDate);
            }

            bool ResponseData::resetCardholderName() {
                m_CardholderName.clear();
                m_FieldsSet.erase(ResponseFields::CardholderName);
                return !isFieldSet(ResponseFields::CardholderName);
            }

            bool ResponseData::resetCardholderAuthMethod() {
                m_CardholderAuthMethod = CardholderAuthMethod::NoMethod;
                m_FieldsSet.erase(ResponseFields::CardholderAuthMethod);
                return !isFieldSet(ResponseFields::CardholderAuthMethod);
            }

            bool ResponseData::resetAuthCode() {
                m_AuthCode.clear();
                m_FieldsSet.erase(ResponseFields::AuthCode);
                return !isFieldSet(ResponseFields::AuthCode);
            }

            bool ResponseData::resetResponseCode() {
                m_ResponseCode.clear();
                m_FieldsSet.erase(ResponseFields::ResponseCode);
                return !isFieldSet(ResponseFields::ResponseCode);
            }

            bool ResponseData::resetResponseText() {
                m_ResponseText.clear();
                m_FieldsSet.erase(ResponseFields::ResponseText);
                return !isFieldSet(ResponseFields::ResponseText);
            }

            bool ResponseData::resetSTAN() {
                m_STAN.clear();
                m_FieldsSet.erase(ResponseFields::STAN);
                return !isFieldSet(ResponseFields::STAN);
            }

            bool ResponseData::resetTransactionID() {
                m_TransactionID.clear();
                m_FieldsSet.erase(ResponseFields::TransactionID);
                return !isFieldSet(ResponseFields::TransactionID);
            }

            bool ResponseData::resetTerminalID() {
                m_TerminalID.clear();
                m_FieldsSet.erase(ResponseFields::TerminalID);
                return !isFieldSet(ResponseFields::TerminalID);
            }

            bool ResponseData::resetCardEmvAid() {
                m_CardEmvAid.clear();
                m_FieldsSet.erase(ResponseFields::CardEmvAid);
                return !isFieldSet(ResponseFields::CardEmvAid);
            }

            bool ResponseData::resetCardAppName() {
                m_CardAppName.clear();
                m_FieldsSet.erase(ResponseFields::CardAppName);
                return !isFieldSet(ResponseFields::CardAppName);
            }

            bool ResponseData::resetCardInputMethod() {
                m_CardInputMethod = CardInputMethod::NoMethod;
                m_FieldsSet.erase(ResponseFields::CardInputMethod);
                return !isFieldSet(ResponseFields::CardInputMethod);
            }

            bool ResponseData::resetIssuerName() {
                m_IssuerName.clear();
                m_FieldsSet.erase(ResponseFields::IssuerName);
                return !isFieldSet(ResponseFields::IssuerName);
            }

            bool ResponseData::resetAdditionalInfo() {
                m_AdditionalInfo.clear();
                m_FieldsSet.erase(ResponseFields::AdditionalInfo);
                return !isFieldSet(ResponseFields::AdditionalInfo);
            }

            bool ResponseData::resetCardData() {
                m_CardData.clear();
                m_FieldsSet.erase(ResponseFields::CardData);
                return !isFieldSet(ResponseFields::CardData);
            }

            bool ResponseData::resetCardDataEnc() {
                m_CardDataEnc.clear();
                m_FieldsSet.erase(ResponseFields::CardDataEnc);
                return !isFieldSet(ResponseFields::CardDataEnc);
            }

            bool ResponseData::resetMerchantID() {
                m_MerchantID.clear();
                m_FieldsSet.erase(ResponseFields::MerchantID);
                return !isFieldSet(ResponseFields::MerchantID);
            }

            bool ResponseData::resetTVR() {
                m_TVR.clear();
                m_FieldsSet.erase(ResponseFields::TVR);
                return !isFieldSet(ResponseFields::TVR);
            }

            bool ResponseData::resetTSI() {
                m_TSI.clear();
                m_FieldsSet.erase(ResponseFields::TSI);
                return !isFieldSet(ResponseFields::TSI);
            }

            bool ResponseData::resetTC() {
                m_TC.clear();
                m_FieldsSet.erase(ResponseFields::TC);
                return !isFieldSet(ResponseFields::TC);
            }

            bool ResponseData::resetCID() {
                m_CID.clear();
                m_FieldsSet.erase(ResponseFields::CID);
                return !isFieldSet(ResponseFields::CID);
            }

            bool ResponseData::resetKVR() {
                m_KVR.clear();
                m_FieldsSet.erase(ResponseFields::KVR);
                return !isFieldSet(ResponseFields::KVR);
            }

            bool ResponseData::resetCDAResult() {
                m_CDAResult.clear();
                m_FieldsSet.erase(ResponseFields::CDAResult);
                return !isFieldSet(ResponseFields::CDAResult);
            }

            bool ResponseData::resetSalesCount() {
                m_SalesCount = -1;
                m_FieldsSet.erase(ResponseFields::SaleCount);
                return !isFieldSet(ResponseFields::SaleCount);
            }

            bool ResponseData::resetVoidCount() {
                m_VoidCount = -1;
                m_FieldsSet.erase(ResponseFields::VoidCount);
                return !isFieldSet(ResponseFields::VoidCount);
            }

            bool ResponseData::resetRefundCount() {
                m_RefundCount = -1;
                m_FieldsSet.erase(ResponseFields::RefundCount);
                return !isFieldSet(ResponseFields::RefundCount);
            }

            bool ResponseData::resetSalesArray() {
                m_SalesArray.clear();
                m_FieldsSet.erase(ResponseFields::SaleArray);
                return !isFieldSet(ResponseFields::SaleArray);
            }

            bool ResponseData::resetVoidArray() {
                m_VoidArray.clear();
                m_FieldsSet.erase(ResponseFields::VoidArray);
                return !isFieldSet(ResponseFields::VoidArray);
            }

            bool ResponseData::resetRefundArray() {
                m_RefundArray.clear();
                m_FieldsSet.erase(ResponseFields::RefundArray);
                return !isFieldSet(ResponseFields::RefundArray);
            }
        }
    }
}