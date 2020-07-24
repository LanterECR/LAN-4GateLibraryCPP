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
                    m_FieldsSet.insert(RequestField::EcrNumber);
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
                    m_FieldsSet.insert(RequestField::EcrMerchantNumber);
                    result = true;
                }
                return result;
            }

            OperationCode RequestData::getOperationCode() const {
                return m_OperationCode;
            }

            bool RequestData::setOperationCode(OperationCode operationCode) {
                bool result = false;
                if (checkOperationCodeRange(static_cast<int32_t>(operationCode))) {
                    if (m_OperationCode != operationCode) {
                        m_OperationCode = operationCode;
                        m_FieldsSet.insert(RequestField::OperationCode);
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
                    m_FieldsSet.insert(RequestField::Amount);
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
                    m_FieldsSet.insert(RequestField::PartialAmount);
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
                    m_FieldsSet.insert(RequestField::TipsAmount);
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
                    m_FieldsSet.insert(RequestField::CashbackAmount);
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
                    m_FieldsSet.insert(RequestField::CurrencyCode);
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
                    m_FieldsSet.insert(RequestField::RRN);
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
                    m_FieldsSet.insert(RequestField::AuthCode);
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
                    m_FieldsSet.insert(RequestField::ReceiptReference);
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
                    m_FieldsSet.insert(RequestField::TransactionID);
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
                    m_FieldsSet.insert(RequestField::CardDataEnc);
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
                    m_FieldsSet.insert(RequestField::OpenTags);
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
                    m_FieldsSet.insert(RequestField::EncTags);
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
                    m_FieldsSet.insert(RequestField::ProviderCode);
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
                    m_FieldsSet.insert(RequestField::AdditionalInfo);
                    result = true;
                }
                return result;
            }

            const std::set<RequestField> &RequestData::getFieldsSet() const {
                return m_FieldsSet;
            }

            const std::set<RequestField> &RequestData::getMandatoryFields() const {
                if (m_Validator) {
                    return m_Validator->getMandatoryFields();
                }
                return m_EmptyFieldsPlaceholder;
            }

            const std::set<RequestField> &RequestData::getOptionalFields() const {
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

            bool RequestData::isFieldSet(RequestField field) const {
                return m_FieldsSet.find(field) != m_FieldsSet.end();
            }

            bool RequestData::resetField(RequestField field) {
                bool result = false;
                switch (field) {
                    case RequestField::EcrNumber:
                        result = resetEcrNumber();
                        break;
                    case RequestField::EcrMerchantNumber:
                        result = resetEcrMerchantNumber();
                        break;
                    case RequestField::OperationCode:
                        result = resetOperationCode();
                        break;
                    case RequestField::Amount:
                        result = resetAmount();
                        break;
                    case RequestField::PartialAmount:
                        result = resetPartialAmount();
                        break;
                    case RequestField::TipsAmount:
                        result = resetTipsAmount();
                        break;
                    case RequestField::CashbackAmount:
                        result = resetCashbackAmount();
                        break;
                    case RequestField::CurrencyCode:
                        result = resetCurrencyCode();
                        break;
                    case RequestField::RRN:
                        result = resetRRN();
                        break;
                    case RequestField::AuthCode:
                        result = resetAuthCode();
                        break;
                    case RequestField::ReceiptReference:
                        result = resetReceiptReference();
                        break;
                    case RequestField::TransactionID:
                        result = resetTransactionID();
                        break;
                    case RequestField::CardDataEnc:
                        result = resetCardDataEnc();
                        break;
                    case RequestField::OpenTags:
                        result = resetOpenTags();
                        break;
                    case RequestField::EncTags:
                        result = resetEncTags();
                        break;
                    case RequestField::ProviderCode:
                        result = resetProviderCode();
                        break;
                    case RequestField::AdditionalInfo:
                        result = resetAdditionalInfo();
                        break;
                }
                return result;
            }

            bool RequestData::resetEcrNumber() {
                m_EcrNumber = -1;
                m_FieldsSet.erase(RequestField::EcrNumber);
                return !isFieldSet(RequestField::EcrNumber);
            }

            bool RequestData::resetEcrMerchantNumber() {
                m_EcrMerchantNumber = -1;
                m_FieldsSet.erase(RequestField::EcrMerchantNumber);
                return !isFieldSet(RequestField::EcrMerchantNumber);
            }

            bool RequestData::resetOperationCode() {
                m_OperationCode = OperationCode::NoOperation;
                m_FieldsSet.erase(RequestField::OperationCode);
                deinitValidator();
                return !isFieldSet(RequestField::OperationCode);
            }

            bool RequestData::resetAmount() {
                m_Amount = -1;
                m_FieldsSet.erase(RequestField::Amount);
                return !isFieldSet(RequestField::Amount);
            }

            bool RequestData::resetPartialAmount() {
                m_PartialAmount = -1;
                m_FieldsSet.erase(RequestField::PartialAmount);
                return !isFieldSet(RequestField::PartialAmount);
            }

            bool RequestData::resetTipsAmount() {
                m_TipsAmount = -1;
                m_FieldsSet.erase(RequestField::TipsAmount);
                return !isFieldSet(RequestField::TipsAmount);
            }

            bool RequestData::resetCashbackAmount() {
                m_CashbackAmount = -1;
                m_FieldsSet.erase(RequestField::CashbackAmount);
                return !isFieldSet(RequestField::CashbackAmount);
            }

            bool RequestData::resetCurrencyCode() {
                m_CurrencyCode = -1;
                m_FieldsSet.erase(RequestField::CurrencyCode);
                return !isFieldSet(RequestField::CurrencyCode);
            }

            bool RequestData::resetRRN() {
                m_RRN.clear();
                m_FieldsSet.erase(RequestField::RRN);
                return !isFieldSet(RequestField::RRN);
            }

            bool RequestData::resetAuthCode() {
                m_AuthCode.clear();
                m_FieldsSet.erase(RequestField::AuthCode);
                return !isFieldSet(RequestField::AuthCode);
            }

            bool RequestData::resetReceiptReference() {
                m_ReceiptReference.clear();
                m_FieldsSet.erase(RequestField::ReceiptReference);
                return !isFieldSet(RequestField::ReceiptReference);
            }

            bool RequestData::resetTransactionID() {
                m_TransactionID.clear();
                m_FieldsSet.erase(RequestField::TransactionID);
                return !isFieldSet(RequestField::TransactionID);
            }

            bool RequestData::resetCardDataEnc() {
                m_CardDataEnc.clear();
                m_FieldsSet.erase(RequestField::CardDataEnc);
                return !isFieldSet(RequestField::CardDataEnc);
            }

            bool RequestData::resetOpenTags() {
                m_OpenTags.clear();
                m_FieldsSet.erase(RequestField::OpenTags);
                return !isFieldSet(RequestField::OpenTags);
            }

            bool RequestData::resetEncTags() {
                m_EncTags.clear();
                m_FieldsSet.erase(RequestField::EncTags);
                return !isFieldSet(RequestField::EncTags);
            }

            bool RequestData::resetProviderCode() {
                m_ProviderCode.clear();
                m_FieldsSet.erase(RequestField::ProviderCode);
                return !isFieldSet(RequestField::ProviderCode);
            }

            bool RequestData::resetAdditionalInfo() {
                m_AdditionalInfo.clear();
                m_FieldsSet.erase(RequestField::AdditionalInfo);
                return !isFieldSet(RequestField::AdditionalInfo);
            }

            void RequestData::deinitValidator() {
                m_Validator.reset();
            }
        }//Request
    }
}//Lanter
