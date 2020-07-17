//
// Created by Владимир Лысенков on 20.06.2020.
//

#include "RequestData.h"
#include "Validators/ValidatorFactory.h"
#include "Lanter/Utils/FieldRangeChecker.h"

using namespace Lanter::Utils;

namespace Lanter
{
    namespace Message {
        namespace Request {

            RequestData::RequestData() {
                initValidator();
            }

            int16_t RequestData::getEcrNumber() const {
                return m_EcrNumber;
            }

            bool RequestData::setEcrNumber(int16_t ecrNumber) {
                bool result = false;
                if (checkEcrNumberRange(ecrNumber)) {
                    m_EcrNumber = ecrNumber;
                    m_FieldsSet.insert(RequestFields::EcrNumber);
                    result = true;
                }
                return result;
            }

            int16_t RequestData::getEcrMerchantNumber() const {
                return m_EcrMerchantNumber;
            }

            bool RequestData::setEcrMerchantNumber(int16_t ecrMerchantNumber) {
                bool result = false;
                if (checkEcrMerchantNumberRange(ecrMerchantNumber)) {
                    m_EcrMerchantNumber = ecrMerchantNumber;
                    m_FieldsSet.insert(RequestFields::EcrMerchantNumber);
                    result = true;
                }
                return result;
            }

            OperationCodes RequestData::getOperationCode() const {
                return m_OperationCode;
            }

            bool RequestData::setOperationCode(OperationCodes operationCode) {
                bool result = false;
                if (checkOperationCodeRange(static_cast<int32_t>(operationCode))) {
                    if (m_OperationCode != operationCode) {
                        m_OperationCode = operationCode;
                        m_FieldsSet.insert(RequestFields::OperationCode);
                        initValidator();
                    }
                    result = true;
                }
                return result;
            }

            int64_t RequestData::getAmount() const {
                return m_Amount;
            }

            bool RequestData::setAmount(int64_t amount) {
                bool result = false;
                if (checkAmountRange(amount)) {
                    m_Amount = amount;
                    m_FieldsSet.insert(RequestFields::Amount);
                    result = true;
                }
                return result;
            }

            int64_t RequestData::getPartialAmount() const {
                return m_PartialAmount;
            }

            bool RequestData::setPartialAmount(int64_t partialAmount) {
                bool result = false;
                if (checkAmountRange(partialAmount)) {
                    m_PartialAmount = partialAmount;
                    m_FieldsSet.insert(RequestFields::PartialAmount);
                    result = true;
                }
                return result;
            }

            int64_t RequestData::getTipsAmount() const {
                return m_TipsAmount;
            }

            bool RequestData::setTipsAmount(int64_t tipsAmount) {
                bool result = false;
                if (checkAmountRange(tipsAmount)) {
                    m_TipsAmount = tipsAmount;
                    m_FieldsSet.insert(RequestFields::TipsAmount);
                    result = true;
                }
                return result;
            }

            int64_t RequestData::getCashbackAmount() const {
                return m_CashbackAmount;
            }

            bool RequestData::setCashbackAmount(int64_t cashbackAmount) {
                bool result = false;
                if (checkAmountRange(cashbackAmount)) {
                    m_CashbackAmount = cashbackAmount;
                    m_FieldsSet.insert(RequestFields::CashbackAmount);
                    result = true;
                }
                return result;
            }

            int16_t RequestData::getCurrencyCode() const {
                return m_CurrencyCode;
            }

            bool RequestData::setCurrencyCode(int16_t currencyCode) {
                bool result = false;
                if (checkCurrencyCodeRange(currencyCode)) {
                    m_CurrencyCode = currencyCode;
                    m_FieldsSet.insert(RequestFields::CurrencyCode);
                    result = true;
                }
                return result;
            }

            const std::string &RequestData::getRRN() const {
                return m_RRN;
            }

            bool RequestData::setRRN(const std::string &RRN) {
                bool result = false;
                if (checkRRNRange(RRN)) {
                    m_RRN = RRN;
                    m_FieldsSet.insert(RequestFields::RRN);
                    result = true;
                }
                return result;
            }

            const std::string &RequestData::getAuthCode() const {
                return m_AuthCode;
            }

            bool RequestData::setAuthCode(const std::string &authCode) {
                bool result = false;
                if (checkAuthCodeRange(authCode)) {
                    m_AuthCode = authCode;
                    m_FieldsSet.insert(RequestFields::AuthCode);
                    result = true;
                }
                return result;
            }

            const std::string &RequestData::getReceiptReference() const {
                return m_ReceiptReference;
            }

            bool RequestData::setReceiptReference(const std::string &receiptReference) {
                bool result = false;
                if (checkAuthCodeRange(receiptReference)) {
                    m_ReceiptReference = receiptReference;
                    m_FieldsSet.insert(RequestFields::ReceiptReference);
                    result = true;
                }
                return result;
            }

            const std::string &RequestData::getTransactionID() const {
                return m_TransactionID;
            }

            bool RequestData::setTransactionID(const std::string &transactionId) {
                bool result = false;
                if (checkTransactionIDRange(transactionId)) {
                    m_TransactionID = transactionId;
                    m_FieldsSet.insert(RequestFields::TransactionID);
                    result = true;
                }
                return result;
            }

            const std::string &RequestData::getCardDataEnc() const {
                return m_CardDataEnc;
            }

            bool RequestData::setCardDataEnc(const std::string &cardDataEnc) {
                bool result = false;
                if (checkCardDataEncRange(cardDataEnc)) {
                    m_CardDataEnc = cardDataEnc;
                    m_FieldsSet.insert(RequestFields::CardDataEnc);
                    result = true;
                }
                return result;
            }

            const std::string &RequestData::getOpenTags() const {
                return m_OpenTags;
            }

            bool RequestData::setOpenTags(const std::string &openTags) {
                bool result = false;
                if (checkOpenTagsRange(openTags)) {
                    m_OpenTags = openTags;
                    m_FieldsSet.insert(RequestFields::OpenTags);
                    result = true;
                }
                return result;
            }

            const std::string &RequestData::getEncTags() const {
                return m_EncTags;
            }

            bool RequestData::setEncTags(const std::string &encTags) {
                bool result = false;
                if (checkEncTagsRange(encTags)) {
                    m_EncTags = encTags;
                    m_FieldsSet.insert(RequestFields::EncTags);
                    result = true;
                }
                return result;
            }

            const std::string &RequestData::getProviderCode() const {
                return m_ProviderCode;
            }

            bool RequestData::setProviderCode(const std::string &providerCode) {
                bool result = false;
                if (checkProviderCodeRange(providerCode)) {
                    m_ProviderCode = providerCode;
                    m_FieldsSet.insert(RequestFields::ProviderCode);
                    result = true;
                }
                return result;
            }

            const std::string &RequestData::getAdditionalInfo() const {
                return m_AdditionalInfo;
            }

            bool RequestData::setAdditionalInfo(const std::string &additionalInfo) {
                bool result = false;
                if (checkAdditionalInfoRange(additionalInfo)) {
                    m_AdditionalInfo = additionalInfo;
                    m_FieldsSet.insert(RequestFields::AdditionalInfo);
                    result = true;
                }
                return result;
            }

            const std::set<RequestFields> &RequestData::getFieldsSet() const {
                return m_FieldsSet;
            }

            const std::set<RequestFields> &RequestData::getMandatoryFields() const {
                if (m_Validator) {
                    return m_Validator->getMandatoryFields();
                }
                return m_EmptyFieldsPlaceholder;
            }

            const std::set<RequestFields> &RequestData::getOptionalFields() const {
                if (m_Validator) {
                    return m_Validator->getOptionalFields();
                }
                return m_EmptyFieldsPlaceholder;
            }

            bool RequestData::validateMandatoryFields() const {
                if (m_Validator) {
                    return m_Validator->validate(getFieldsSet());
                }
                return false;
            }

            void RequestData::initValidator() {
                m_Validator = ValidatorFactory::getValidator(getOperationCode());
            }

            bool RequestData::isFieldSet(RequestFields field) const {
                return m_FieldsSet.find(field) != m_FieldsSet.end();
            }
        }//Request
    }
}//Lanter
