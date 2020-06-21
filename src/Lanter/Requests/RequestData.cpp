//
// Created by Владимир Лысенков on 20.06.2020.
//

#include "Lanter/Requests/RequestData.h"

#include <sstream>

#include <exception>

namespace Lanter
{
    namespace Requests {
        //вспомогательные функции
        static const int64_t minimumAmount = 0;
        static const int64_t maximumAmount = 999999999999;

        bool checkValueRange(int64_t value, int64_t min, int64_t max);

        void createRangeMessage(int64_t value, int64_t minimumValue, int64_t maximumValue, std::string &outputMessage);

        int16_t RequestData::getEcrNumber() const {
            return m_EcrNumber;
        }

        void RequestData::setEcrNumber(int16_t ecrNumber) {
            int16_t minimumValue = 1;
            int16_t maximumValue = 999;
            if (checkValueRange(ecrNumber, minimumValue, maximumValue)) {
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
            if (checkValueRange(ecrMerchantNumber, minimumValue, maximumValue)) {
                m_EcrMerchantNumber = ecrMerchantNumber;
                m_FieldsSet.insert(RequestFields::EcrMerchantNumber);
            }
        }

        OperationCodes RequestData::getOperationCode() const {
            return m_OperationCode;
        }

        void RequestData::setOperationCode(OperationCodes operationCode) {
            if (checkValueRange(static_cast<int64_t>(operationCode),
                                static_cast<int64_t>(OperationCodes::FirstValue),
                                static_cast<int64_t>(OperationCodes::LastValue))) {
                m_OperationCode = operationCode;
                m_FieldsSet.insert(RequestFields::OperationCode);
            }
        }

        int64_t RequestData::getAmount() const {
            return m_Amount;
        }

        void RequestData::setAmount(int64_t amount) {
            if (checkValueRange(amount, minimumAmount, maximumAmount)) {
                m_Amount = amount;
                m_FieldsSet.insert(RequestFields::Amount);
            }
        }

        int64_t RequestData::getPartialAmount() const {
            return m_PartialAmount;
        }

        void RequestData::setPartialAmount(int64_t partialAmount) {
            if (checkValueRange(partialAmount, minimumAmount, maximumAmount)) {
                m_PartialAmount = partialAmount;
                m_FieldsSet.insert(RequestFields::PartialAmount);
            }
        }

        int64_t RequestData::getTipsAmount() const {
            return m_TipsAmount;
        }

        void RequestData::setTipsAmount(int64_t tipsAmount) {
            if (checkValueRange(tipsAmount, minimumAmount, maximumAmount)) {
                m_TipsAmount = tipsAmount;
                m_FieldsSet.insert(RequestFields::TipsAmount);
            }
        }

        int64_t RequestData::getCashbackAmount() const {
            return m_CashbackAmount;
        }

        void RequestData::setCashbackAmount(int64_t cashbackAmount) {
            if (checkValueRange(cashbackAmount, minimumAmount, maximumAmount)) {
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
            if (checkValueRange(currencyCode, minimumCurrencyCode, maximumCurrencyCode)) {
                m_CurrencyCode = currencyCode;
                m_FieldsSet.insert(RequestFields::CurrencyCode);
            }
        }

        const std::string &RequestData::getRRN() const {
            return m_RRN;
        }

        void RequestData::setRRN(const std::string &RRN) {
            int maxLen = 12;
            if (!RRN.empty() && RRN.size() <= maxLen) {
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
            int maxLen = 6;
            if (!authCode.empty() && authCode.size() <= maxLen) {
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
            int maxLen = 6;
            if (!receiptReference.empty() && receiptReference.size() <= maxLen) {
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
            int maxLen = 40;
            if (!transactionId.empty() && transactionId.size() <= maxLen) {
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
            int maxLen = 4;
            if (!providerCode.empty() && providerCode.size() <= maxLen) {
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

        bool checkValueRange(int64_t value, int64_t min, int64_t max) {
            if (value < min || value > max) {
                std::string message;
                createRangeMessage(value, min, max, message);
                throw std::invalid_argument(message);
            }
            return true;
        }

        void createRangeMessage(int64_t value, int64_t min, int64_t max, std::string &outputMessage) {
            std::stringstream messageStream;
            messageStream << value << " is invalid value.";
            messageStream << "Correct value in range starts from " << min << " to " << max;
            outputMessage = messageStream.str();
        }
    }
}
