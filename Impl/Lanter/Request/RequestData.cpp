//
// Created by Владимир Лысенков on 20.06.2020.
//

#include "RequestData.h"

#include <exception>

#include "Validators/ValidatorFactory.h"
#include "Lanter/Utils/RangeChecker.h"

namespace Lanter
{
    namespace Request {
        //вспомогательные функции
        static const int64_t minimumAmount = 0;
        static const int64_t maximumAmount = 999999999999;

        RequestData::RequestData() {
            initValidator();
        }

        int16_t RequestData::getEcrNumber() const {
            return m_EcrNumber;
        }

        void RequestData::setEcrNumber(int16_t ecrNumber) {
            int16_t minimumValue = 1;
            int16_t maximumValue = 999;
            if (Utils::checkValueRange(ecrNumber, minimumValue, maximumValue)) {
                m_EcrNumber = ecrNumber;
                m_FieldsSet.insert(RequestFields::EcrNumber);
            }
        }

        int16_t RequestData::getEcrMerchantNumber() const {
            return m_EcrMerchantNumber;
        }

        void RequestData::setEcrMerchantNumber(int16_t ecrMerchantNumber) {
            int16_t minimumValue = 1;
            int16_t maximumValue = 999;
            if (Utils::checkValueRange(ecrMerchantNumber, minimumValue, maximumValue)) {
                m_EcrMerchantNumber = ecrMerchantNumber;
                m_FieldsSet.insert(RequestFields::EcrMerchantNumber);
            }
        }

        OperationCodes RequestData::getOperationCode() const {
            return m_OperationCode;
        }

        void RequestData::setOperationCode(OperationCodes operationCode) {
            if (Utils::checkValueRange(static_cast<int64_t>(operationCode),
                                static_cast<int64_t>(OperationCodes::FirstValue),
                                static_cast<int64_t>(OperationCodes::LastValue))) {
                m_OperationCode = operationCode;
                m_FieldsSet.insert(RequestFields::OperationCode);
                initValidator();
            }
        }

        int64_t RequestData::getAmount() const {
            return m_Amount;
        }

        void RequestData::setAmount(int64_t amount) {
            if (Utils::checkValueRange(amount, minimumAmount, maximumAmount)) {
                m_Amount = amount;
                m_FieldsSet.insert(RequestFields::Amount);
            }
        }

        int64_t RequestData::getPartialAmount() const {
            return m_PartialAmount;
        }

        void RequestData::setPartialAmount(int64_t partialAmount) {
            if (Utils::checkValueRange(partialAmount, minimumAmount, maximumAmount)) {
                m_PartialAmount = partialAmount;
                m_FieldsSet.insert(RequestFields::PartialAmount);
            }
        }

        int64_t RequestData::getTipsAmount() const {
            return m_TipsAmount;
        }

        void RequestData::setTipsAmount(int64_t tipsAmount) {
            if (Utils::checkValueRange(tipsAmount, minimumAmount, maximumAmount)) {
                m_TipsAmount = tipsAmount;
                m_FieldsSet.insert(RequestFields::TipsAmount);
            }
        }

        int64_t RequestData::getCashbackAmount() const {
            return m_CashbackAmount;
        }

        void RequestData::setCashbackAmount(int64_t cashbackAmount) {
            if (Utils::checkValueRange(cashbackAmount, minimumAmount, maximumAmount)) {
                m_CashbackAmount = cashbackAmount;
                m_FieldsSet.insert(RequestFields::CashbackAmount);
            }
        }

        int16_t RequestData::getCurrencyCode() const {
            return m_CurrencyCode;
        }

        void RequestData::setCurrencyCode(int16_t currencyCode) {
            int64_t minimumCurrencyCode = 1;
            int64_t maximumCurrencyCode = 999;
            if (Utils::checkValueRange(currencyCode, minimumCurrencyCode, maximumCurrencyCode)) {
                m_CurrencyCode = currencyCode;
                m_FieldsSet.insert(RequestFields::CurrencyCode);
            }
        }

        const std::string &RequestData::getRRN() const {
            return m_RRN;
        }

        void RequestData::setRRN(const std::string &RRN) {
            if (!RRN.empty()) {
                m_RRN = RRN;
                m_FieldsSet.insert(RequestFields::RRN);
            } else {
                throw std::invalid_argument("Invalid RRN length");
            }
        }

        const std::string &RequestData::getAuthCode() const {
            return m_AuthCode;
        }

        void RequestData::setAuthCode(const std::string &authCode) {
            if (!authCode.empty()) {
                m_AuthCode = authCode;
                m_FieldsSet.insert(RequestFields::AuthCode);
            } else {
                throw std::invalid_argument("Invalid AuthCode length");
            }
        }

        const std::string &RequestData::getReceiptReference() const {
            return m_ReceiptReference;
        }

        void RequestData::setReceiptReference(const std::string &receiptReference) {
            if (!receiptReference.empty()) {
                m_ReceiptReference = receiptReference;
                m_FieldsSet.insert(RequestFields::ReceiptReference);
            } else {
                throw std::invalid_argument("Invalid ReceiptReference length");
            }
        }

        const std::string &RequestData::getTransactionId() const {
            return m_TransactionID;
        }

        void RequestData::setTransactionId(const std::string &transactionId) {
            if (!transactionId.empty()) {
                m_TransactionID = transactionId;
                m_FieldsSet.insert(RequestFields::TransactionID);
            } else {
                throw std::invalid_argument("Invalid TransactionID length");
            }
        }

        const std::string &RequestData::getCardDataEnc() const {
            return m_CardDataEnc;
        }

        void RequestData::setCardDataEnc(const std::string &cardDataEnc) {
            if (!cardDataEnc.empty()) {
                m_CardDataEnc = cardDataEnc;
                m_FieldsSet.insert(RequestFields::CardDataEnc);
            } else {
                throw std::invalid_argument("Invalid CardDataEnc length");
            }
        }

        const std::string &RequestData::getOpenTags() const {
            return m_OpenTags;
        }

        void RequestData::setOpenTags(const std::string &openTags) {
            if (!openTags.empty()) {
                m_OpenTags = openTags;
                m_FieldsSet.insert(RequestFields::OpenTags);
            } else {
                throw std::invalid_argument("Invalid OpenTags length");
            }
        }

        const std::string &RequestData::getEncTags() const {
            return m_EncTags;
        }

        void RequestData::setEncTags(const std::string &encTags) {
            if (!encTags.empty()) {
                m_EncTags = encTags;
                m_FieldsSet.insert(RequestFields::EncTags);
            } else {
                throw std::invalid_argument("Invalid EncTags length");
            }
        }

        const std::string &RequestData::getProviderCode() const {
            return m_ProviderCode;
        }

        void RequestData::setProviderCode(const std::string &providerCode) {
            if (!providerCode.empty()) {
                m_ProviderCode = providerCode;
                m_FieldsSet.insert(RequestFields::ProviderCode);
            } else {
                throw std::invalid_argument("Invalid ProviderCode length");
            }
        }

        const std::string &RequestData::getAdditionalInfo() const {
            return m_AdditionalInfo;
        }

        void RequestData::setAdditionalInfo(const std::string &additionalInfo) {
            if (!additionalInfo.empty()) {
                m_AdditionalInfo = additionalInfo;
                m_FieldsSet.insert(RequestFields::AdditionalInfo);
            } else {
                throw std::invalid_argument("Invalid AdditionalInfo length");
            }
        }

        const std::set<RequestFields> &RequestData::getFieldsSet() const {
            return m_FieldsSet;
        }

        const std::set<RequestFields> &RequestData::getMandatoryFields() const {
            if(m_Validator) {
                return m_Validator->getMandatoryFields();
            }
            return m_EmptyFieldsPlaceholder;
        }

        const std::set<RequestFields> &RequestData::getOptionalFields() const {
            if(m_Validator) {
                return m_Validator->getOptionalFields();
            }
            return m_EmptyFieldsPlaceholder;
        }

        bool RequestData::validateMandatoryFields() {
            if(m_Validator) {
                return m_Validator->validate(getFieldsSet());
            }
            return false;
        }

        void RequestData::initValidator() {
            m_Validator = ValidatorFactory::getValidator(getOperationCode());
        }


    }//Request
}//Lanter
