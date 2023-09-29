#include "ResponseData.h"
#include "Lanter/Utils/FieldRangeChecker.h"
#include "Lanter/Message/Response/Validators/ValidatorFactory.h"

using namespace Lanter::Utils;

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            ResponseData::ResponseData()
            {
                initValidator();
            }

            const std::set<ResponseField> &ResponseData::getFieldsSet() const
            {
                return m_FieldsSet;
            }

            bool ResponseData::isFieldSet(ResponseField field) const
            {
                return m_FieldsSet.find(field) != m_FieldsSet.end();
            }

            const std::set<ResponseField> &ResponseData::getMandatoryFields() const
            {
                if (m_Validator)
                {
                    return m_Validator->getMandatoryFields();
                }
                return m_EmptyFieldsPlaceholder;
            }

            const std::set<ResponseField> &ResponseData::getOptionalFields() const
            {
                if (m_Validator)
                {
                    return m_Validator->getOptionalFields();
                }
                return m_EmptyFieldsPlaceholder;
            }

            bool ResponseData::validateMandatoryFields() const
            {
                if (m_Validator)
                {
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
                    m_FieldsSet.insert(ResponseField::EcrNumber);
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
                    m_FieldsSet.insert(ResponseField::EcrMerchantNumber);
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
                        m_FieldsSet.insert(ResponseField::OperationCode);
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
                    m_FieldsSet.insert(ResponseField::OriginalOperationCode);
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
                    m_FieldsSet.insert(ResponseField::TotalAmount);
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
                    m_FieldsSet.insert(ResponseField::PartialAmount);
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
                    m_FieldsSet.insert(ResponseField::AcquirerFeeAmount);
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
                    m_FieldsSet.insert(ResponseField::TerminalFeeAmount);
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
                    m_FieldsSet.insert(ResponseField::TipsAmount);
                    result = true;
                }
                return result;
            }

            const std::string & ResponseData::getCurrencyCode() const {
                return m_CurrencyCode;
            }

            bool ResponseData::setCurrencyCode(const std::string &currencyCode) {
                bool result = false;
                if (checkCurrencyCodeRange(currencyCode)) {
                    m_CurrencyCode = currencyCode;
                    m_FieldsSet.insert(ResponseField::CurrencyCode);
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
                    m_FieldsSet.insert(ResponseField::ReceiptReference);
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
                    m_FieldsSet.insert(ResponseField::RRN);
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
                    m_FieldsSet.insert(ResponseField::Status);
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
                    m_FieldsSet.insert(ResponseField::OriginalOperationStatus);
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
                    m_FieldsSet.insert(ResponseField::TransDateTime);
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
                    m_FieldsSet.insert(ResponseField::TerminalDateTime);
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
                    m_FieldsSet.insert(ResponseField::CardPAN);
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
                    m_FieldsSet.insert(ResponseField::ExpireDate);
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
                    m_FieldsSet.insert(ResponseField::CardholderName);
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
                    m_FieldsSet.insert(ResponseField::CardholderAuthMethod);
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
                    m_FieldsSet.insert(ResponseField::AuthCode);
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
                    m_FieldsSet.insert(ResponseField::ResponseCode);
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
                    m_FieldsSet.insert(ResponseField::ResponseText);
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
                    m_FieldsSet.insert(ResponseField::STAN);
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
                    m_FieldsSet.insert(ResponseField::TransactionID);
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
                    m_FieldsSet.insert(ResponseField::TerminalID);
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
                    m_FieldsSet.insert(ResponseField::CardEmvAid);
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
                    m_FieldsSet.insert(ResponseField::CardAppName);
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
                    m_FieldsSet.insert(ResponseField::CardInputMethod);
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
                    m_FieldsSet.insert(ResponseField::IssuerName);
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
                    m_FieldsSet.insert(ResponseField::AdditionalInfo);
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
                    m_FieldsSet.insert(ResponseField::CardData);
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
                    m_FieldsSet.insert(ResponseField::CardDataEnc);
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
                    m_FieldsSet.insert(ResponseField::MerchantID);
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
                    m_FieldsSet.insert(ResponseField::TVR);
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
                    m_FieldsSet.insert(ResponseField::TSI);
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
                    m_FieldsSet.insert(ResponseField::TC);
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
                    m_FieldsSet.insert(ResponseField::CID);
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
                    m_FieldsSet.insert(ResponseField::KVR);
                    result = true;
                }
                return result;
            }

            const std::string &ResponseData::getCDAResult() const {
                return m_CDAResult;
            }

            bool ResponseData::setCDAResult(const std::string &cdaResult)
            {
                bool result = false;
                if (checkCDAResultRange(cdaResult))
                {
                    m_CDAResult = cdaResult;
                    m_FieldsSet.insert(ResponseField::CDAResult);
                    result = true;
                }
                return result;
            }

            int32_t ResponseData::getSalesCount() const
            {
                return m_SalesCount;
            }

            bool ResponseData::setSalesCount(int32_t salesCount)
            {
                bool result = false;
                if (checkSalesCountRange(salesCount))
                {
                    m_SalesCount = salesCount;
                    m_FieldsSet.insert(ResponseField::SalesCount);
                    result = true;
                }
                return result;
            }

            int32_t ResponseData::getVoidCount() const
            {
                return m_VoidCount;
            }

            bool ResponseData::setVoidCount(int32_t voidCount)
            {
                bool result = false;
                if (checkVoidCountRange(voidCount))
                {
                    m_VoidCount = voidCount;
                    m_FieldsSet.insert(ResponseField::VoidCount);
                    result = true;
                }
                return result;
            }

            int32_t ResponseData::getRefundCount() const
            {
                return m_RefundCount;
            }

            bool ResponseData::setRefundCount(int32_t refundCount)
            {
                bool result = false;
                if (checkRefundCountRange(refundCount))
                {
                    m_RefundCount = refundCount;
                    m_FieldsSet.insert(ResponseField::RefundCount);
                    result = true;
                }
                return result;
            }

            const std::vector<std::shared_ptr<IResponseData> > &ResponseData::getSalesArray() const
            {
                return m_SalesArray;
            }

            bool ResponseData::setSalesArray(const std::vector<std::shared_ptr<IResponseData> > &salesArray)
            {
                bool result = false;
                if(!salesArray.empty()) {
                    m_SalesArray = salesArray;
                    m_FieldsSet.insert(ResponseField::SalesArray);
                    result = true;
                }
                return result;
            }

            const std::vector<std::shared_ptr<IResponseData> > &ResponseData::getVoidArray() const
            {
                return m_VoidArray;
            }

            bool ResponseData::setVoidArray(const std::vector<std::shared_ptr<IResponseData> > &voidArray)
            {
                bool result = false;
                if(!voidArray.empty())
                {
                    m_VoidArray = voidArray;
                    m_FieldsSet.insert(ResponseField::VoidArray);
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
                    m_FieldsSet.insert(ResponseField::RefundArray);
                    result = true;
                }
                return result;
            }

			int64_t ResponseData::getECertAmount() const {
				return m_ECertAmount;
			}

			bool ResponseData::setECertAmount(int64_t amount) {
				bool result = false;
				if (checkAmountRange(amount)) {
					m_ECertAmount = amount;
					m_FieldsSet.insert(ResponseField::ECertAmount);
					result = true;
				}
				return result;
			}
			bool ResponseData::resetECertAmount() {
				m_ECertAmount = -1;
				m_FieldsSet.erase(ResponseField::ECertAmount);
				return !isFieldSet(ResponseField::ECertAmount);
			}

			const std::string &ResponseData::getBasketID() const {
				return m_BasketID;
			}

			bool ResponseData::setBasketID(const std::string &id) {
				bool result = false;
				//TODO добавить чекер
				if (!id.empty()) {
					m_BasketID = id;
					m_FieldsSet.insert(ResponseField::BasketID);
					result = true;
				}
				return result;
			}

			bool ResponseData::resetBasketID() {
				m_BasketID.clear();
				m_FieldsSet.erase(ResponseField::BasketID);
				return !isFieldSet(ResponseField::BasketID);
			}

            void ResponseData::initValidator() {
                m_Validator = ValidatorFactory::getValidator(getOperationCode());
            }

            void ResponseData::deinitValidator() {
                m_Validator.reset();
            }

            bool ResponseData::resetField(ResponseField field) {
                bool result = false;

                switch (field) {

                    case ResponseField::EcrNumber:
                        result = resetEcrNumber();
                        break;
                    case ResponseField::EcrMerchantNumber:
                        result = resetEcrMerchantNumber();
                        break;
                    case ResponseField::OperationCode:
                        result = resetOperationCode();
                        break;
                    case ResponseField::OriginalOperationCode:
                        result = resetOriginalOperationCode();
                        break;
                    case ResponseField::TotalAmount:
                        result = resetTotalAmount();
                        break;
                    case ResponseField::PartialAmount:
                        result = resetPartialAmount();
                        break;
                    case ResponseField::AcquirerFeeAmount:
                        result = resetAcquirerFeeAmount();
                        break;
                    case ResponseField::TerminalFeeAmount:
                        result = resetTerminalFeeAmount();
                        break;
                    case ResponseField::TipsAmount:
                        result = resetTipsAmount();
                        break;
                    case ResponseField::CurrencyCode:
                        result = resetCurrencyCode();
                        break;
                    case ResponseField::ReceiptReference:
                        result = resetReceiptReference();
                        break;
                    case ResponseField::RRN:
                        result = resetRRN();
                        break;
                    case ResponseField::Status:
                        result = resetStatus();
                        break;
                    case ResponseField::OriginalOperationStatus:
                        result = resetOriginalOperationStatus();
                        break;
                    case ResponseField::TransDateTime:
                        result = resetTransDateTime();
                        break;
                    case ResponseField::TerminalDateTime:
                        result = resetTerminalDateTime();
                        break;
                    case ResponseField::CardPAN:
                        result = resetCardPAN();
                        break;
                    case ResponseField::ExpireDate:
                        result = resetExpireDate();
                        break;
                    case ResponseField::CardholderName:
                        result = resetCardholderName();
                        break;
                    case ResponseField::CardholderAuthMethod:
                        result = resetCardholderAuthMethod();
                        break;
                    case ResponseField::AuthCode:
                        result = resetAuthCode();
                        break;
                    case ResponseField::ResponseCode:
                        result = resetResponseCode();
                        break;
                    case ResponseField::ResponseText:
                        result = resetResponseText();
                        break;
                    case ResponseField::STAN:
                        result = resetSTAN();
                        break;
                    case ResponseField::TransactionID:
                        result = resetTransactionID();
                        break;
                    case ResponseField::TerminalID:
                        result = resetTerminalID();
                        break;
                    case ResponseField::CardEmvAid:
                        result = resetCardEmvAid();
                        break;
                    case ResponseField::CardAppName:
                        result = resetCardAppName();
                        break;
                    case ResponseField::CardInputMethod:
                        result = resetCardInputMethod();
                        break;
                    case ResponseField::IssuerName:
                        result = resetIssuerName();
                        break;
                    case ResponseField::AdditionalInfo:
                        result = resetAdditionalInfo();
                        break;
                    case ResponseField::CardData:
                        result = resetCardData();
                        break;
                    case ResponseField::CardDataEnc:
                        result = resetCardDataEnc();
                        break;
                    case ResponseField::MerchantID:
                        result = resetMerchantID();
                        break;
                    case ResponseField::TVR:
                        result = resetTVR();
                        break;
                    case ResponseField::TSI:
                        result = resetTSI();
                        break;
                    case ResponseField::TC:
                        result = resetTC();
                        break;
                    case ResponseField::CID:
                        result = resetCID();
                        break;
                    case ResponseField::KVR:
                        result = resetKVR();
                        break;
                    case ResponseField::CDAResult:
                        result = resetCDAResult();
                        break;
                    case ResponseField::SalesCount:
                        result = resetSalesCount();
                        break;
                    case ResponseField::VoidCount:
                        result = resetVoidCount();
                        break;
                    case ResponseField::RefundCount:
                        result = resetRefundCount();
                        break;
                    case ResponseField::SalesArray:
                        result = resetSalesArray();
                        break;
                    case ResponseField::VoidArray:
                        result = resetVoidArray();
                        break;
                    case ResponseField::RefundArray:
                        result = resetRefundArray();
                        break;
                    case ResponseField::SalesAmount:
                        result = resetSalesAmount();
                        break;
                    case ResponseField::VoidAmount:
                        result = resetVoidAmount();
                        break;
                    case ResponseField::RefundAmount:
                        result = resetRefundAmount();
                        break;
					case ResponseField::ECertAmount:
						result = resetECertAmount();
						break;
					case ResponseField::BasketID:
						result = resetBasketID();
						break;
					default:
						break;
				}

                return result;
            }

            bool ResponseData::resetEcrNumber() {
                m_EcrNumber = -1;
                m_FieldsSet.erase(ResponseField::EcrNumber);
                return !isFieldSet(ResponseField::EcrNumber);
            }

            bool ResponseData::resetEcrMerchantNumber() {
                m_EcrMerchantNumber = -1;
                m_FieldsSet.erase(ResponseField::EcrMerchantNumber);
                return !isFieldSet(ResponseField::EcrMerchantNumber);
            }

            bool ResponseData::resetOperationCode() {
                m_OperationCode = OperationCode::NoOperation;
                m_FieldsSet.erase(ResponseField::OperationCode);
                deinitValidator();
                return !isFieldSet(ResponseField::OperationCode);
            }

            bool ResponseData::resetOriginalOperationCode() {
                m_OriginalOperationCode = OperationCode::NoOperation;
                m_FieldsSet.erase(ResponseField::OriginalOperationCode);
                return !isFieldSet(ResponseField::OriginalOperationCode);
            }

            bool ResponseData::resetTotalAmount() {
                m_TotalAmount = -1;
                m_FieldsSet.erase(ResponseField::TotalAmount);
                return !isFieldSet(ResponseField::TotalAmount);
            }

            bool ResponseData::resetPartialAmount() {
                m_PartialAmount = -1;
                m_FieldsSet.erase(ResponseField::PartialAmount);
                return !isFieldSet(ResponseField::PartialAmount);
            }

            bool ResponseData::resetAcquirerFeeAmount() {
                m_AcquirerFeeAmount = -1;
                m_FieldsSet.erase(ResponseField::AcquirerFeeAmount);
                return !isFieldSet(ResponseField::AcquirerFeeAmount);
            }

            bool ResponseData::resetTerminalFeeAmount() {
                m_TerminalFeeAmount = -1;
                m_FieldsSet.erase(ResponseField::TerminalFeeAmount);
                return !isFieldSet(ResponseField::TerminalFeeAmount);
            }

            bool ResponseData::resetTipsAmount() {
                m_TipsAmount = -1;
                m_FieldsSet.erase(ResponseField::TipsAmount);
                return !isFieldSet(ResponseField::TipsAmount);
            }

            bool ResponseData::resetCurrencyCode() {
                m_CurrencyCode.clear();
                m_FieldsSet.erase(ResponseField::CurrencyCode);
                return !isFieldSet(ResponseField::CurrencyCode);
            }

            bool ResponseData::resetReceiptReference() {
                m_ReceiptReference.clear();
                m_FieldsSet.erase(ResponseField::ReceiptReference);
                return !isFieldSet(ResponseField::ReceiptReference);
            }

            bool ResponseData::resetRRN() {
                m_RRN.clear();
                m_FieldsSet.erase(ResponseField::RRN);
                return !isFieldSet(ResponseField::RRN);
            }

            bool ResponseData::resetStatus() {
                m_Status = Status::NoStatus;
                m_FieldsSet.erase(ResponseField::Status);
                return !isFieldSet(ResponseField::Status);
            }

            bool ResponseData::resetOriginalOperationStatus() {
                m_OriginalOperationStatus = Status::NoStatus;
                m_FieldsSet.erase(ResponseField::OriginalOperationStatus);
                return !isFieldSet(ResponseField::OriginalOperationStatus);
            }

            bool ResponseData::resetTransDateTime() {
                m_TransDateTime.clear();
                m_FieldsSet.erase(ResponseField::TransDateTime);
                return !isFieldSet(ResponseField::TransDateTime);
            }

            bool ResponseData::resetTerminalDateTime() {
                m_TerminalDateTime.clear();
                m_FieldsSet.erase(ResponseField::TerminalDateTime);
                return !isFieldSet(ResponseField::TerminalDateTime);
            }

            bool ResponseData::resetCardPAN() {
                m_CardPAN.clear();
                m_FieldsSet.erase(ResponseField::CardPAN);
                return !isFieldSet(ResponseField::CardPAN);
            }

            bool ResponseData::resetExpireDate() {
                m_ExpireDate.clear();
                m_FieldsSet.erase(ResponseField::ExpireDate);
                return !isFieldSet(ResponseField::ExpireDate);
            }

            bool ResponseData::resetCardholderName() {
                m_CardholderName.clear();
                m_FieldsSet.erase(ResponseField::CardholderName);
                return !isFieldSet(ResponseField::CardholderName);
            }

            bool ResponseData::resetCardholderAuthMethod() {
                m_CardholderAuthMethod = CardholderAuthMethod::NoMethod;
                m_FieldsSet.erase(ResponseField::CardholderAuthMethod);
                return !isFieldSet(ResponseField::CardholderAuthMethod);
            }

            bool ResponseData::resetAuthCode() {
                m_AuthCode.clear();
                m_FieldsSet.erase(ResponseField::AuthCode);
                return !isFieldSet(ResponseField::AuthCode);
            }

            bool ResponseData::resetResponseCode() {
                m_ResponseCode.clear();
                m_FieldsSet.erase(ResponseField::ResponseCode);
                return !isFieldSet(ResponseField::ResponseCode);
            }

            bool ResponseData::resetResponseText() {
                m_ResponseText.clear();
                m_FieldsSet.erase(ResponseField::ResponseText);
                return !isFieldSet(ResponseField::ResponseText);
            }

            bool ResponseData::resetSTAN() {
                m_STAN.clear();
                m_FieldsSet.erase(ResponseField::STAN);
                return !isFieldSet(ResponseField::STAN);
            }

            bool ResponseData::resetTransactionID() {
                m_TransactionID.clear();
                m_FieldsSet.erase(ResponseField::TransactionID);
                return !isFieldSet(ResponseField::TransactionID);
            }

            bool ResponseData::resetTerminalID() {
                m_TerminalID.clear();
                m_FieldsSet.erase(ResponseField::TerminalID);
                return !isFieldSet(ResponseField::TerminalID);
            }

            bool ResponseData::resetCardEmvAid() {
                m_CardEmvAid.clear();
                m_FieldsSet.erase(ResponseField::CardEmvAid);
                return !isFieldSet(ResponseField::CardEmvAid);
            }

            bool ResponseData::resetCardAppName() {
                m_CardAppName.clear();
                m_FieldsSet.erase(ResponseField::CardAppName);
                return !isFieldSet(ResponseField::CardAppName);
            }

            bool ResponseData::resetCardInputMethod() {
                m_CardInputMethod = CardInputMethod::NoMethod;
                m_FieldsSet.erase(ResponseField::CardInputMethod);
                return !isFieldSet(ResponseField::CardInputMethod);
            }

            bool ResponseData::resetIssuerName() {
                m_IssuerName.clear();
                m_FieldsSet.erase(ResponseField::IssuerName);
                return !isFieldSet(ResponseField::IssuerName);
            }

            bool ResponseData::resetAdditionalInfo() {
                m_AdditionalInfo.clear();
                m_FieldsSet.erase(ResponseField::AdditionalInfo);
                return !isFieldSet(ResponseField::AdditionalInfo);
            }

            bool ResponseData::resetCardData() {
                m_CardData.clear();
                m_FieldsSet.erase(ResponseField::CardData);
                return !isFieldSet(ResponseField::CardData);
            }

            bool ResponseData::resetCardDataEnc() {
                m_CardDataEnc.clear();
                m_FieldsSet.erase(ResponseField::CardDataEnc);
                return !isFieldSet(ResponseField::CardDataEnc);
            }

            bool ResponseData::resetMerchantID() {
                m_MerchantID.clear();
                m_FieldsSet.erase(ResponseField::MerchantID);
                return !isFieldSet(ResponseField::MerchantID);
            }

            bool ResponseData::resetTVR() {
                m_TVR.clear();
                m_FieldsSet.erase(ResponseField::TVR);
                return !isFieldSet(ResponseField::TVR);
            }

            bool ResponseData::resetTSI() {
                m_TSI.clear();
                m_FieldsSet.erase(ResponseField::TSI);
                return !isFieldSet(ResponseField::TSI);
            }

            bool ResponseData::resetTC() {
                m_TC.clear();
                m_FieldsSet.erase(ResponseField::TC);
                return !isFieldSet(ResponseField::TC);
            }

            bool ResponseData::resetCID() {
                m_CID.clear();
                m_FieldsSet.erase(ResponseField::CID);
                return !isFieldSet(ResponseField::CID);
            }

            bool ResponseData::resetKVR()
            {
                m_KVR.clear();
                m_FieldsSet.erase(ResponseField::KVR);
                return !isFieldSet(ResponseField::KVR);
            }

            bool ResponseData::resetCDAResult()
            {
                m_CDAResult.clear();
                m_FieldsSet.erase(ResponseField::CDAResult);
                return !isFieldSet(ResponseField::CDAResult);
            }

            bool ResponseData::resetSalesCount()
            {
                m_SalesCount = -1;
                m_FieldsSet.erase(ResponseField::SalesCount);
                return !isFieldSet(ResponseField::SalesCount);
            }

            bool ResponseData::resetVoidCount()
            {
                m_VoidCount = -1;
                m_FieldsSet.erase(ResponseField::VoidCount);
                return !isFieldSet(ResponseField::VoidCount);
            }

            bool ResponseData::resetRefundCount()
            {
                m_RefundCount = -1;
                m_FieldsSet.erase(ResponseField::RefundCount);
                return !isFieldSet(ResponseField::RefundCount);
            }

            bool ResponseData::resetSalesArray()
            {
                m_SalesArray.clear();
                m_FieldsSet.erase(ResponseField::SalesArray);
                return !isFieldSet(ResponseField::SalesArray);
            }

            bool ResponseData::resetVoidArray()
            {
                m_VoidArray.clear();
                m_FieldsSet.erase(ResponseField::VoidArray);
                return !isFieldSet(ResponseField::VoidArray);
            }

            bool ResponseData::resetRefundArray()
            {
                m_RefundArray.clear();
                m_FieldsSet.erase(ResponseField::RefundArray);
                return !isFieldSet(ResponseField::RefundArray);
            }

            int64_t ResponseData::getSalesAmount() cons
            {
                return m_SalesAmount;
            }

            bool ResponseData::setSalesAmount(int64_t amount) {
                bool result = false;
                if (checkAmountRange(amount)) {
                    m_SalesAmount = amount;
                    m_FieldsSet.insert(ResponseField::SalesAmount);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetSalesAmount() {
                m_SalesAmount = -1;
                m_FieldsSet.erase(ResponseField::SalesAmount);
                return !isFieldSet(ResponseField::SalesAmount);
            }

            int64_t ResponseData::getVoidAmount() const {
                return m_VoidAmount;
            }

            bool ResponseData::setVoidAmount(int64_t amount) {
                bool result = false;
                if (checkAmountRange(amount)) {
                    m_VoidAmount = amount;
                    m_FieldsSet.insert(ResponseField::VoidAmount);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetVoidAmount() {
                m_VoidAmount = -1;
                m_FieldsSet.erase(ResponseField::VoidAmount);
                return !isFieldSet(ResponseField::VoidAmount);
            }

            int64_t ResponseData::getRefundAmount() const {
                return m_RefundAmount;
            }

            bool ResponseData::setRefundAmount(int64_t amount) {
                bool result = false;
                if (checkAmountRange(amount)) {
                    m_RefundAmount = amount;
                    m_FieldsSet.insert(ResponseField::RefundAmount);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetRefundAmount() {
                m_RefundAmount = -1;
                m_FieldsSet.erase(ResponseField::RefundAmount);
                return !isFieldSet(ResponseField::RefundAmount);
            }

            const std::string &ResponseData::getCardPANHash() const {
                return m_CardPANHash;
            }

            bool ResponseData::setCardPANHash(const std::string &pan) {
                bool result = false;
                //TODO добавить чекер
                if (!pan.empty()) {
                    m_CardPANHash = pan;
                    m_FieldsSet.insert(ResponseField::CardPANHash);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetCardPANHash() {
                m_CardPANHash.clear();
                m_FieldsSet.erase(ResponseField::CardPANHash);
                return !isFieldSet(ResponseField::CardPANHash);
            }

            const std::string &ResponseData::getReceiptLine1() const {
                return m_ReceiptLine1;
            }

            bool ResponseData::setReceiptLine1(const std::string &text) {
                bool result = false;
                //TODO добавить чекер
                if (!text.empty()) {
                    m_ReceiptLine1 = text;
                    m_FieldsSet.insert(ResponseField::ReceiptLine1);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetReceiptLine1() {
                m_ReceiptLine1.clear();
                m_FieldsSet.erase(ResponseField::ReceiptLine1);
                return !isFieldSet(ResponseField::ReceiptLine1);
            }

            const std::string &ResponseData::getReceiptLine2() const {
                return m_ReceiptLine2;
            }

            bool ResponseData::setReceiptLine2(const std::string &text) {
                bool result = false;
                //TODO добавить чекер
                if (!text.empty()) {
                    m_ReceiptLine2 = text;
                    m_FieldsSet.insert(ResponseField::ReceiptLine2);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetReceiptLine2() {
                m_ReceiptLine2.clear();
                m_FieldsSet.erase(ResponseField::ReceiptLine2);
                return !isFieldSet(ResponseField::ReceiptLine2);
            }

            const std::string &ResponseData::getReceiptLine3() const {
                return m_ReceiptLine3;
            }

            bool ResponseData::setReceiptLine3(const std::string &text) {
                bool result = false;
                //TODO добавить чекер
                if (!text.empty()) {
                    m_ReceiptLine3 = text;
                    m_FieldsSet.insert(ResponseField::ReceiptLine3);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetReceiptLine3() {
                m_ReceiptLine3.clear();
                m_FieldsSet.erase(ResponseField::ReceiptLine3);
                return !isFieldSet(ResponseField::ReceiptLine3);
            }

            const std::string &ResponseData::getReceiptLine4() const {
                return m_ReceiptLine4;
            }

            bool ResponseData::setReceiptLine4(const std::string &text) {
                bool result = false;
                //TODO добавить чекер
                if (!text.empty()) {
                    m_ReceiptLine4 = text;
                    m_FieldsSet.insert(ResponseField::ReceiptLine4);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetReceiptLine4() {
                m_ReceiptLine4.clear();
                m_FieldsSet.erase(ResponseField::ReceiptLine4);
                return !isFieldSet(ResponseField::ReceiptLine4);
            }

            const std::string &ResponseData::getReceiptLine5() const {
                return m_ReceiptLine5;
            }

            bool ResponseData::setReceiptLine5(const std::string &text) {
                bool result = false;
                //TODO добавить чекер
                if (!text.empty()) {
                    m_ReceiptLine5 = text;
                    m_FieldsSet.insert(ResponseField::ReceiptLine5);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetReceiptLine5() {
                m_ReceiptLine5.clear();
                m_FieldsSet.erase(ResponseField::ReceiptLine5);
                return !isFieldSet(ResponseField::ReceiptLine5);
            }

            const std::string &ResponseData::getApplicationLabel() const {
                return m_ApplicationLabel;
            }

            bool ResponseData::setApplicationLabel(const std::string &label) {
                bool result = false;
                //TODO добавить чекер
                if (!label.empty()) {
                    m_ApplicationLabel = label;
                    m_FieldsSet.insert(ResponseField::ApplicationLabel);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetApplicationLabel() {
                m_ApplicationLabel.clear();
                m_FieldsSet.erase(ResponseField::ApplicationLabel);
                return !isFieldSet(ResponseField::ApplicationLabel);
            }

            int64_t ResponseData::getBonusBalance() const {
                return m_BonusBalance;
            }

            bool ResponseData::setBonusBalance(int64_t balance) {
                bool result = false;
                if (checkAmountRange(balance)) {
                    m_BonusBalance = balance;
                    m_FieldsSet.insert(ResponseField::BonusBalance);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetBonusBalance() {
                m_BonusBalance = -1;
                m_FieldsSet.erase(ResponseField::BonusBalance);
                return !isFieldSet(ResponseField::BonusBalance);
            }

            int64_t ResponseData::getBonusAmount() const {
                return m_BonusAmount;
            }

            bool ResponseData::setBonusAmount(int64_t amount) {
                bool result = false;
                if (checkAmountRange(amount)) {
                    m_BonusAmount = amount;
                    m_FieldsSet.insert(ResponseField::BonusAmount);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetBonusAmount() {
                m_BonusAmount = -1;
                m_FieldsSet.erase(ResponseField::BonusAmount);
                return !isFieldSet(ResponseField::BonusAmount);
            }

            const std::string &ResponseData::getHashCardTrack2() const {
                return m_HashCardTrack2;
            }

            bool ResponseData::setHashCardTrack2(const std::string &hashTrack2) {
                bool result = false;
                //TODO добавить чекер
                if (!hashTrack2.empty()) {
                    m_HashCardTrack2 = hashTrack2;
                    m_FieldsSet.insert(ResponseField::HashCardTrack2);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetHashCardTrack2() {
                m_HashCardTrack2.clear();
                m_FieldsSet.erase(ResponseField::HashCardTrack2);
                return !isFieldSet(ResponseField::HashCardTrack2);
            }

            bool ResponseData::getFinalizationRequired() const {
                return m_FinalizationRequired;
            }

            bool ResponseData::setFinalizationRequired(bool required)
            {
                m_FinalizationRequired = required;
                m_FieldsSet.insert(ResponseField::FinalizationRequired);

                //Тут невозможно ничего проверить, только установить поле и флаг
                return isFieldSet(ResponseField::FinalizationRequired);
            }

            bool ResponseData::resetFinalizationRequired()
            {
                m_FinalizationRequired = false;
                m_FieldsSet.erase(ResponseField::FinalizationRequired);
                return !isFieldSet(ResponseField::FinalizationRequired);
            }

            const std::string &ResponseData::getCfgTerminalID() const
            {
                return m_CfgTerminalID;
            }

            bool ResponseData::setCfgTerminalID(const std::string &terminalId)
            {
                bool result = false;
                if (checkTerminalIDRange(terminalId))
                {
                    m_CfgTerminalID = terminalId;
                    m_FieldsSet.insert(ResponseField::CfgTerminalID);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetCfgTerminalID()
            {
                m_CfgTerminalID.clear();
                m_FieldsSet.erase(ResponseField::CfgTerminalID);
                return !isFieldSet(ResponseField::CfgTerminalID);
            }

            int64_t ResponseData::getAdditionalChoiceResult() const
            {
                return m_ChoiceResult;
            }

            bool ResponseData::setAdditionalChoiceResult(int64_t additionalChoiceResult)
            {
                bool result = false;
                if (checkAmountRange(additionalChoiceResult))
                {
                    m_ChoiceResult = additionalChoiceResult;
                    m_FieldsSet.insert(ResponseField::AdditionalChoiceResult);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetAdditionalChoiceResult()
            {
                m_ChoiceResult = -1;
                m_FieldsSet.erase(ResponseField::AdditionalChoiceResult);
                return !isFieldSet(ResponseField::AdditionalChoiceResult);
            }

            const std::string& ResponseData::getSBP_RN() const
            {
                return m_SBP_RN;
            }

            bool ResponseData::setSBP_RN(const std::string& SBP_RN)
            {
                bool result = false;
                if (checkSBP_RN(SBP_RN))
                {
                    m_SBP_RN = SBP_RN;
                    m_FieldsSet.insert(ResponseField::SBP_RN);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetSBP_RN()
            {
                m_SBP_RN.clear();
                m_FieldsSet.erase(ResponseField::SBP_RN);
                return !isFieldSet(ResponseField::SBP_RN);
            }

            const std::string& ResponseData::getQRCode() const
            {
                return m_QRCode;
            }

            bool ResponseData::setQRCode(const std::string& QRCode)
            {
                bool result = false;
                if (checkQRCode(QRCode))
                {
                    m_QRCode = QRCode;
                    m_FieldsSet.insert(ResponseField::QRCode);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetQRCode()
            {
                m_QRCode.clear();
                m_FieldsSet.erase(ResponseField::QRCode);
                return !isFieldSet(ResponseField::QRCode);
            }

            const std::string& ResponseData::getSBP_KZO() const
            {
                return m_SBP_KZO;
            }

            bool ResponseData::setSBP_KZO(const std::string& SBP_KZO)
            {
                bool result = false;
                if (checkSBP_KZO(SBP_KZO))
                {
                    m_SBP_KZO = SBP_KZO;
                    m_FieldsSet.insert(ResponseField::SBP_KZO);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetSBP_KZO()
            {
                m_SBP_KZO.clear();
                m_FieldsSet.erase(ResponseField::SBP_KZO);
                return !isFieldSet(ResponseField::SBP_KZO);
            }

            const std::string& ResponseData::getSBP_ReqId() const
            {
                return m_SBP_ReqId;
            }

            bool ResponseData::setSBP_ReqId(const std::string& SBP_ReqId)
            {
                bool result = false;
                if (checkSBP_ReqId(SBP_ReqId))
                {
                    m_SBP_ReqId = SBP_ReqId;
                    m_FieldsSet.insert(ResponseField::SBP_ReqId);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetSBP_ReqId()
            {
                m_SBP_ReqId.clear();
                m_FieldsSet.erase(ResponseField::SBP_ReqId);
                return !isFieldSet(ResponseField::SBP_ReqId);
            }

            const std::string& ResponseData::getSBP_Code() const
            {
                return m_SBP_Code;
            }

            bool ResponseData::setSBP_Code(const std::string& SBP_Code)
            {
                bool result = false;
                if (checkSBP_Code(SBP_Code))
                {
                    m_SBP_Code = SBP_Code;
                    m_FieldsSet.insert(ResponseField::SBP_Code);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetSBP_Code()
            {
                m_SBP_Code.clear();
                m_FieldsSet.erase(ResponseField::SBP_Code);
                return !isFieldSet(ResponseField::SBP_Code);
            }

            const std::string& ResponseData::getSBP_Status() const
            {
                return m_SBP_Status;
            }

            bool ResponseData::setSBP_Status(const std::string& SBP_Status)
            {
                bool result = false;
                if (checkSBP_Status(SBP_Status))
                {
                    m_SBP_Status = SBP_Status;
                    m_FieldsSet.insert(ResponseField::SBP_Status);
                    result = true;
                }
                return result;
            }

            bool ResponseData::resetSBP_Status()
            {
                m_SBP_Status.clear();
                m_FieldsSet.erase(ResponseField::SBP_Status);
                return !isFieldSet(ResponseField::SBP_Status);
            }
        }
    }
}