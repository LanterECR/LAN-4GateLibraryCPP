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

            void RequestData::setEcrNumber(int16_t ecrNumber) {
                if (checkEcrNumberRange(ecrNumber)) {
                    m_EcrNumber = ecrNumber;
                    m_FieldsSet.insert(RequestFields::EcrNumber);
                }
            }

            int16_t RequestData::getEcrMerchantNumber() const {
                return m_EcrMerchantNumber;
            }

            void RequestData::setEcrMerchantNumber(int16_t ecrMerchantNumber) {
                if (checkEcrMerchantNumberRange(ecrMerchantNumber)) {
                    m_EcrMerchantNumber = ecrMerchantNumber;
                    m_FieldsSet.insert(RequestFields::EcrMerchantNumber);
                }
            }

            OperationCodes RequestData::getOperationCode() const {
                return m_OperationCode;
            }

            void RequestData::setOperationCode(OperationCodes operationCode) {
                if (checkOperationCodeRange(static_cast<int32_t>(operationCode))) {
                    m_OperationCode = operationCode;
                    m_FieldsSet.insert(RequestFields::OperationCode);
                    initValidator();
                }
            }

            int64_t RequestData::getAmount() const {
                return m_Amount;
            }

            void RequestData::setAmount(int64_t amount) {
                if (checkAmountRange(amount)) {
                    m_Amount = amount;
                    m_FieldsSet.insert(RequestFields::Amount);
                }
            }

            int64_t RequestData::getPartialAmount() const {
                return m_PartialAmount;
            }

            void RequestData::setPartialAmount(int64_t partialAmount) {
                if (checkAmountRange(partialAmount)) {
                    m_PartialAmount = partialAmount;
                    m_FieldsSet.insert(RequestFields::PartialAmount);
                }
            }

            int64_t RequestData::getTipsAmount() const {
                return m_TipsAmount;
            }

            void RequestData::setTipsAmount(int64_t tipsAmount) {
                if (checkAmountRange(tipsAmount)) {
                    m_TipsAmount = tipsAmount;
                    m_FieldsSet.insert(RequestFields::TipsAmount);
                }
            }

            int64_t RequestData::getCashbackAmount() const {
                return m_CashbackAmount;
            }

            void RequestData::setCashbackAmount(int64_t cashbackAmount) {
                if (checkAmountRange(cashbackAmount)) {
                    m_CashbackAmount = cashbackAmount;
                    m_FieldsSet.insert(RequestFields::CashbackAmount);
                }
            }

            int16_t RequestData::getCurrencyCode() const {
                return m_CurrencyCode;
            }

            void RequestData::setCurrencyCode(int16_t currencyCode) {
                if (checkCurrencyCodeRange(currencyCode)) {
                    m_CurrencyCode = currencyCode;
                    m_FieldsSet.insert(RequestFields::CurrencyCode);
                }
            }

            const std::string &RequestData::getRRN() const {
                return m_RRN;
            }

            void RequestData::setRRN(const std::string &RRN) {
                if (checkRRNRange(RRN)) {
                    m_RRN = RRN;
                    m_FieldsSet.insert(RequestFields::RRN);
                }
            }

            const std::string &RequestData::getAuthCode() const {
                return m_AuthCode;
            }

            void RequestData::setAuthCode(const std::string &authCode) {
                if (checkAuthCodeRange(authCode)) {
                    m_AuthCode = authCode;
                    m_FieldsSet.insert(RequestFields::AuthCode);
                }
            }

            const std::string &RequestData::getReceiptReference() const {
                return m_ReceiptReference;
            }

            void RequestData::setReceiptReference(const std::string &receiptReference) {
                if (checkAuthCodeRange(receiptReference)) {
                    m_ReceiptReference = receiptReference;
                    m_FieldsSet.insert(RequestFields::ReceiptReference);
                }
            }

            const std::string &RequestData::getTransactionID() const {
                return m_TransactionID;
            }

            void RequestData::setTransactionID(const std::string &transactionId) {
                if (checkTransactionIDRange(transactionId)) {
                    m_TransactionID = transactionId;
                    m_FieldsSet.insert(RequestFields::TransactionID);
                }
            }

            const std::string &RequestData::getCardDataEnc() const {
                return m_CardDataEnc;
            }

            void RequestData::setCardDataEnc(const std::string &cardDataEnc) {
                if (checkCardDataEncRange(cardDataEnc)) {
                    m_CardDataEnc = cardDataEnc;
                    m_FieldsSet.insert(RequestFields::CardDataEnc);
                }
            }

            const std::string &RequestData::getOpenTags() const {
                return m_OpenTags;
            }

            void RequestData::setOpenTags(const std::string &openTags) {
                if (checkOpenTagsRange(openTags)) {
                    m_OpenTags = openTags;
                    m_FieldsSet.insert(RequestFields::OpenTags);
                }
            }

            const std::string &RequestData::getEncTags() const {
                return m_EncTags;
            }

            void RequestData::setEncTags(const std::string &encTags) {
                if (checkEncTagsRange(encTags)) {
                    m_EncTags = encTags;
                    m_FieldsSet.insert(RequestFields::EncTags);
                }
            }

            const std::string &RequestData::getProviderCode() const {
                return m_ProviderCode;
            }

            void RequestData::setProviderCode(const std::string &providerCode) {
                if (checkProviderCodeRange(providerCode)) {
                    m_ProviderCode = providerCode;
                    m_FieldsSet.insert(RequestFields::ProviderCode);
                }
            }

            const std::string &RequestData::getAdditionalInfo() const {
                return m_AdditionalInfo;
            }

            void RequestData::setAdditionalInfo(const std::string &additionalInfo) {
                if (checkAdditionalInfoRange(additionalInfo)) {
                    m_AdditionalInfo = additionalInfo;
                    m_FieldsSet.insert(RequestFields::AdditionalInfo);
                }
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

            bool RequestData::validateMandatoryFields() {
                if (m_Validator) {
                    return m_Validator->validate(getFieldsSet());
                }
                return false;
            }

            void RequestData::initValidator() {
                m_Validator = ValidatorFactory::getValidator(getOperationCode());
            }


        }//Request
    }
}//Lanter
