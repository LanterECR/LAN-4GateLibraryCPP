#include "RequestData.h"

#include "Validators/ValidatorFactory.h"
#include "Lanter/Utils/FieldRangeChecker.h"

namespace Lanter {
    using namespace Utils;

    namespace Message {
        namespace Request {

            RequestData::RequestData() {
                initValidator();
            }//RequestData()

            const std::set<RequestField> &RequestData::getMandatoryFields() const {
                if (m_Validator) {
                    return m_Validator->getMandatoryFields();
                }//if validator

                return m_EmptyFieldsPlaceholder;
            }//getMandatoryFields()

            const std::set<RequestField> &RequestData::getOptionalFields() const {
                if (m_Validator) {
                    return m_Validator->getOptionalFields();
                }//if validator

                return m_EmptyFieldsPlaceholder;
            }//getOptionalFields()

            bool RequestData::validateMandatoryFields() const {
                if (m_Validator) {
                    return m_Validator->validate(getFieldsSet());
                }//if validator

                return false;
            }//validateMandatoryFields()

           int16_t RequestData::getEcrNumber() const {
                return m_EcrNumber;
            }//getEcrNumber()

            bool RequestData::setEcrNumber(int16_t ecrNumber) {
                bool result = false;

                if (checkEcrNumberRange(ecrNumber)) {
                    m_EcrNumber = ecrNumber;
                    m_FieldsSet.insert(RequestField::EcrNumber);
                    result = true;
                }//if check ecrNumber

                return result;
            }//setEcrNumber()

            bool RequestData::resetEcrNumber() {
                m_EcrNumber = -1;
                m_FieldsSet.erase(RequestField::EcrNumber);
                return !isFieldSet(RequestField::EcrNumber);
            }//resetEcrNumber()

            int16_t RequestData::getEcrMerchantNumber() const {
                return m_EcrMerchantNumber;
            }//getEcrMerchantNumber()

            bool RequestData::setEcrMerchantNumber(int16_t ecrMerchantNumber) {
                bool result = false;

                if (checkEcrMerchantNumberRange(ecrMerchantNumber)) {
                    m_EcrMerchantNumber = ecrMerchantNumber;
                    m_FieldsSet.insert(RequestField::EcrMerchantNumber);
                    result = true;
                }//if ecrMerchantNumber

                return result;
            }//setEcrMerchantNumber()

            bool RequestData::resetEcrMerchantNumber() {
                m_EcrMerchantNumber = -1;
                m_FieldsSet.erase(RequestField::EcrMerchantNumber);
                return !isFieldSet(RequestField::EcrMerchantNumber);
            }//resetEcrMerchantNumber()

            OperationCode RequestData::getOperationCode() const {
                return m_OperationCode;
            }//getOperationCode()

            bool RequestData::setOperationCode(OperationCode operationCode) {
                bool result = false;

                if (checkOperationCodeRange(static_cast<int32_t>(operationCode))) {
                    if (m_OperationCode != operationCode) {
                        m_OperationCode = operationCode;
                        m_FieldsSet.insert(RequestField::OperationCode);
                        initValidator(); //необходима инициализация нового валидатора при смене кода операции
                    }
                    result = true;
                }//if OperationCode

                return result;
            }//setOperationCode()

            bool RequestData::resetOperationCode() {
                m_OperationCode = OperationCode::NoOperation;
                m_FieldsSet.erase(RequestField::OperationCode);
                deinitValidator();//вместе с кодом необходим сброс валидатора

                return !isFieldSet(RequestField::OperationCode);
            }//resetOperationCode()

            int64_t RequestData::getAmount() const {
                return m_Amount;
            }//getAmount()

            bool RequestData::setAmount(int64_t amount) {
                bool result = false;

                if (checkAmountRange(amount)) {
                    m_Amount = amount;
                    m_FieldsSet.insert(RequestField::Amount);
                    result = true;
                }//if check amount

                return result;
            }//setAmount()

			bool RequestData::resetAmount() {
                m_Amount = -1;
                m_FieldsSet.erase(RequestField::Amount);
                return !isFieldSet(RequestField::Amount);
            }//resetAmount()

			int64_t RequestData::getECertAmount() const {
				return m_ECertAmount;
			}//getECertAmount()

			bool RequestData::setECertAmount(int64_t amount) {
				bool result = false;

				if (checkAmountRange(amount)) {
					m_ECertAmount = amount;
					m_FieldsSet.insert(RequestField::ECertAmount);
					result = true;
				}//if check amount

				return result;
			}//setECertAmount()

			bool RequestData::resetECertAmount() {
				m_ECertAmount = -1;
				m_FieldsSet.erase(RequestField::ECertAmount);
				return !isFieldSet(RequestField::ECertAmount);
			}//resetECertAmount()

			int64_t RequestData::getPartialAmount() const {
                return m_PartialAmount;
            }//getPartialAmount()

            bool RequestData::setPartialAmount(int64_t partialAmount) {
                bool result = false;

                if (checkAmountRange(partialAmount)) {
                    m_PartialAmount = partialAmount;
                    m_FieldsSet.insert(RequestField::PartialAmount);
                    result = true;
                }//if check partial amount

                return result;
            }//setPartialAmount(

            bool RequestData::resetPartialAmount() {
                m_PartialAmount = -1;
                m_FieldsSet.erase(RequestField::PartialAmount);
                return !isFieldSet(RequestField::PartialAmount);
            }//resetPartialAmount()

            int64_t RequestData::getTipsAmount() const {
                return m_TipsAmount;
            }//getTipsAmount()

            bool RequestData::setTipsAmount(int64_t tipsAmount) {
                bool result = false;

                if (checkAmountRange(tipsAmount)) {
                    m_TipsAmount = tipsAmount;
                    m_FieldsSet.insert(RequestField::TipsAmount);
                    result = true;
                }//if check tips amount

                return result;
            }//setTipsAmount(

            bool RequestData::resetTipsAmount() {
                m_TipsAmount = -1;
                m_FieldsSet.erase(RequestField::TipsAmount);
                return !isFieldSet(RequestField::TipsAmount);
            }//resetTipsAmount()

            int64_t RequestData::getCashbackAmount() const {
                return m_CashbackAmount;
            }//getCashbackAmount()

            bool RequestData::setCashbackAmount(int64_t cashbackAmount) {
                bool result = false;

                if (checkAmountRange(cashbackAmount)) {
                    m_CashbackAmount = cashbackAmount;
                    m_FieldsSet.insert(RequestField::CashbackAmount);
                    result = true;
                }//if check cashback amount

                return result;
            }//setCashbackAmount(

            bool RequestData::resetCashbackAmount() {
                m_CashbackAmount = -1;
                m_FieldsSet.erase(RequestField::CashbackAmount);
                return !isFieldSet(RequestField::CashbackAmount);
            }//resetCashbackAmount()

            const std::string & RequestData::getCurrencyCode() const {
                return m_CurrencyCode;
            }//getCurrencyCode()

            bool RequestData::setCurrencyCode(const std::string &currencyCode) {
                bool result = false;

                if (checkCurrencyCodeRange(currencyCode)) {
                    m_CurrencyCode = currencyCode;
                    m_FieldsSet.insert(RequestField::CurrencyCode);
                    result = true;
                }//if check currency code

                return result;
            }//setCurrencyCode(

            bool RequestData::resetCurrencyCode() {
                m_CurrencyCode.clear();
                m_FieldsSet.erase(RequestField::CurrencyCode);
                return !isFieldSet(RequestField::CurrencyCode);
            }//resetCurrencyCode()

            const std::string &RequestData::getRRN() const {
                return m_RRN;
            }//getRRN()

            bool RequestData::setRRN(const std::string &RRN) {
                bool result = false;

                if (checkRRNRange(RRN)) {
                    m_RRN = RRN;
                    m_FieldsSet.insert(RequestField::RRN);
                    result = true;
                }//if check RRN

                return result;
            }//setRRN(

            bool RequestData::resetRRN() {
                m_RRN.clear();
                m_FieldsSet.erase(RequestField::RRN);
                return !isFieldSet(RequestField::RRN);
            }//resetRRN()

            const std::string &RequestData::getAuthCode() const {
                return m_AuthCode;
            }//getAuthCode()

            bool RequestData::setAuthCode(const std::string &authCode) {
                bool result = false;

                if (checkAuthCodeRange(authCode)) {
                    m_AuthCode = authCode;
                    m_FieldsSet.insert(RequestField::AuthCode);
                    result = true;
                }//if check auth code

                return result;
            }//setAuthCode()

            bool RequestData::resetAuthCode() {
                m_AuthCode.clear();
                m_FieldsSet.erase(RequestField::AuthCode);
                return !isFieldSet(RequestField::AuthCode);
            }//resetAuthCode()


            const std::string &RequestData::getReceiptReference() const {
                return m_ReceiptReference;
            }//getReceiptReference()

            bool RequestData::setReceiptReference(const std::string &receiptReference) {
                bool result = false;

                if (checkReceiptReferenceRange(receiptReference)) {
                    m_ReceiptReference = receiptReference;
                    m_FieldsSet.insert(RequestField::ReceiptReference);
                    result = true;
                }//if check receipt reference

                return result;
            }//setReceiptReference(

            bool RequestData::resetReceiptReference() {
                m_ReceiptReference.clear();
                m_FieldsSet.erase(RequestField::ReceiptReference);
                return !isFieldSet(RequestField::ReceiptReference);
            }//resetReceiptReference()

            const std::string &RequestData::getTransactionID() const {
                return m_TransactionID;
            }//getTransactionID()

            bool RequestData::setTransactionID(const std::string &transactionId) {
                bool result = false;

                if (checkTransactionIDRange(transactionId)) {
                    m_TransactionID = transactionId;
                    m_FieldsSet.insert(RequestField::TransactionID);
                    result = true;
                }//if check transaction id

                return result;
            }//setTransactionID(

            bool RequestData::resetTransactionID() {
                m_TransactionID.clear();
                m_FieldsSet.erase(RequestField::TransactionID);
                return !isFieldSet(RequestField::TransactionID);
            }//resetTransactionID()

            const std::string &RequestData::getCardDataEnc() const {
                return m_CardDataEnc;
            }//getCardDataEnc()

            bool RequestData::setCardDataEnc(const std::string &cardDataEnc) {
                bool result = false;

                if (checkCardDataEncRange(cardDataEnc)) {
                    m_CardDataEnc = cardDataEnc;
                    m_FieldsSet.insert(RequestField::CardDataEnc);
                    result = true;
                }//if check card data enc

                return result;
            }//setCardDataEnc(

            bool RequestData::resetCardDataEnc() {
                m_CardDataEnc.clear();
                m_FieldsSet.erase(RequestField::CardDataEnc);
                return !isFieldSet(RequestField::CardDataEnc);
            }//resetCardDataEnc()

            const std::string &RequestData::getOpenTags() const {
                return m_OpenTags;
            }//getOpenTags()

            bool RequestData::setOpenTags(const std::string &openTags) {
                bool result = false;

                if (checkOpenTagsRange(openTags)) {
                    m_OpenTags = openTags;
                    m_FieldsSet.insert(RequestField::OpenTags);
                    result = true;
                }//if check open tags

                return result;
            }//setOpenTags()

            bool RequestData::resetOpenTags() {
                m_OpenTags.clear();
                m_FieldsSet.erase(RequestField::OpenTags);
                return !isFieldSet(RequestField::OpenTags);
            }//resetOpenTags()

            const std::string &RequestData::getEncTags() const {
                return m_EncTags;
            }//getEncTags()

            bool RequestData::setEncTags(const std::string &encTags) {
                bool result = false;

                if (checkEncTagsRange(encTags)) {
                    m_EncTags = encTags;
                    m_FieldsSet.insert(RequestField::EncTags);
                    result = true;
                }//if check enc tags

                return result;
            }//setEncTags(

            bool RequestData::resetEncTags() {
                m_EncTags.clear();
                m_FieldsSet.erase(RequestField::EncTags);
                return !isFieldSet(RequestField::EncTags);
            }//resetEncTags()

            const std::string &RequestData::getProviderCode() const {
                return m_ProviderCode;
            }//getProviderCode()

            bool RequestData::setProviderCode(const std::string &providerCode) {
                bool result = false;

                if (checkProviderCodeRange(providerCode)) {
                    m_ProviderCode = providerCode;
                    m_FieldsSet.insert(RequestField::ProviderCode);
                    result = true;
                }//if check provider code

                return result;
            }//setProviderCode()

            bool RequestData::resetProviderCode() {
                m_ProviderCode.clear();
                m_FieldsSet.erase(RequestField::ProviderCode);
                return !isFieldSet(RequestField::ProviderCode);
            }//resetProviderCode()

            const std::string &RequestData::getAdditionalInfo() const {
                return m_AdditionalInfo;
            }//getAdditionalInfo()

            bool RequestData::setAdditionalInfo(const std::string &additionalInfo) {
                bool result = false;

                if (checkAdditionalInfoRange(additionalInfo)) {
                    m_AdditionalInfo = additionalInfo;
                    m_FieldsSet.insert(RequestField::AdditionalInfo);
                    result = true;
                }//if check additional info

                return result;
            }//setAdditionalInfo()

            bool RequestData::resetAdditionalInfo() {
                m_AdditionalInfo.clear();
                m_FieldsSet.erase(RequestField::AdditionalInfo);
                return !isFieldSet(RequestField::AdditionalInfo);
            }//resetAdditionalInfo()

            int64_t RequestData::getBonusBalance() const {
                return m_BonusBalance;
            }

            bool RequestData::setBonusBalance(int64_t balance) {
                bool result = false;

                if (checkAmountRange(balance)) {
                    m_BonusBalance = balance;
                    m_FieldsSet.insert(RequestField::BonusBalance);
                    result = true;
                }//if check tips amount

                return result;
            }

            bool RequestData::resetBonusBalance() {
                m_BonusBalance = -1;
                m_FieldsSet.erase(RequestField::BonusBalance);
                return !isFieldSet(RequestField::BonusBalance);
            }

            int64_t RequestData::getBonusAmount() const {
                return m_BonusAmount;
            }

            bool RequestData::setBonusAmount(int64_t amount) {
                bool result = false;

                if (checkAmountRange(amount)) {
                    m_BonusAmount = amount;
                    m_FieldsSet.insert(RequestField::BonusAmount);
                    result = true;
                }//if check tips amount

                return result;
            }

            bool RequestData::resetBonusAmount() {
                m_BonusAmount = -1;
                m_FieldsSet.erase(RequestField::BonusAmount);
                return !isFieldSet(RequestField::BonusAmount);
            }

            const std::string &RequestData::getHashCardTrack2() const {
                return m_HashCardTrack2;
            }

            bool RequestData::setHashCardTrack2(const std::string &cardTrack2) {
                bool result = false;

                if (checkHashCardTrack2(cardTrack2)) {
                    m_HashCardTrack2 = cardTrack2;
                    m_FieldsSet.insert(RequestField::HashCardTrack2);
                    result = true;
                }//if check tips amount

                return result;
            }

            bool RequestData::resetHashCardTrack2() {
                m_HashCardTrack2.clear();
                m_FieldsSet.erase(RequestField::HashCardTrack2);
                return !isFieldSet(RequestField::HashCardTrack2);
            }

            const std::string& RequestData::getSBP_RN() const {
                return m_SBP_RN;
            }

            bool RequestData::setSBP_RN(const std::string& purpose) {
                bool result = false;

                if (checkSBP_RN(purpose)) {
                    m_SBP_RN = purpose;
                    m_FieldsSet.insert(RequestField::SBP_RN);
                    result = true;
                }//if check tips amount

                return result;
            }

            bool RequestData::resetSBP_RN() {
                m_SBP_RN.clear();
                m_FieldsSet.erase(RequestField::SBP_RN);
                return !isFieldSet(RequestField::SBP_RN);
            }

            const std::string& RequestData::getSBP_ReqID() const {
                return m_SBP_ReqID;
            }

            bool RequestData::setSBP_ReqID(const std::string& purpose) {
                bool result = false;

                if (checkSBP_ReqID(purpose)) {
                    m_SBP_ReqID = purpose;
                    m_FieldsSet.insert(RequestField::SBP_ReqID);
                    result = true;
                }//if check tips amount

                return result;
            }

            bool RequestData::resetSBP_ReqID() {
                m_SBP_ReqID.clear();
                m_FieldsSet.erase(RequestField::SBP_ReqID);
                return !isFieldSet(RequestField::SBP_ReqID);
            }

            const std::string& RequestData::getPaymentPurpose() const {
                return m_PaymentPurpose;
            }

            bool RequestData::setPaymentPurpose(const std::string& purpose) {
                bool result = false;

                if (checkPaymentPurpose(purpose)) {
                    m_PaymentPurpose = purpose;
                    m_FieldsSet.insert(RequestField::PaymentPurpose);
                    result = true;
                }//if check tips amount

                return result;
            }

            bool RequestData::resetPaymentPurpose() {
                m_PaymentPurpose.clear();
                m_FieldsSet.erase(RequestField::PaymentPurpose);
                return !isFieldSet(RequestField::PaymentPurpose);
            }

			const std::string &RequestData::getPaymentProviderCode() const {
                return m_PaymentProviderCode;
            }

            bool RequestData::setPaymentProviderCode(const std::string &code) {
                bool result = false;

                if (checkProviderCodeRange(code)) {
                    m_PaymentProviderCode = code;
                    m_FieldsSet.insert(RequestField::PaymentProviderCode);
                    result = true;
                }//if check tips amount

                return result;
            }

            bool RequestData::resetPaymentProviderCode() {
                m_PaymentProviderCode.clear();
                m_FieldsSet.erase(RequestField::PaymentProviderCode);
                return !isFieldSet(RequestField::PaymentProviderCode);
            }

            const std::string &RequestData::getPaymentParam1() const {
                return m_PaymentParam1;
            }

            bool RequestData::setPaymentParam1(const std::string &param) {
                bool result = false;

                if (!param.empty()) {
                    m_PaymentParam1 = param;
                    m_FieldsSet.insert(RequestField::PaymentParam1);
                    result = true;
                }//if check tips amount

                return result;
            }

            bool RequestData::resetPaymentParam1() {
                m_PaymentParam1.clear();
                m_FieldsSet.erase(RequestField::PaymentParam1);
                return !isFieldSet(RequestField::PaymentParam1);
            }

            const std::string &RequestData::getPaymentParam2() const {
                return m_PaymentParam2;
            }

            bool RequestData::setPaymentParam2(const std::string &param) {
                bool result = false;

                if (!param.empty()) {
                    m_PaymentParam2 = param;
                    m_FieldsSet.insert(RequestField::PaymentParam2);
                    result = true;
                }//if check tips amount

                return result;
            }

            bool RequestData::resetPaymentParam2() {
                m_PaymentParam2.clear();
                m_FieldsSet.erase(RequestField::PaymentParam2);
                return !isFieldSet(RequestField::PaymentParam2);
            }

			const std::string &RequestData::getBasketID() const {
				return m_BasketID;
			}

			bool RequestData::setBasketID(const std::string &id) {
				bool result = false;

				if (!id.empty()) {
					m_BasketID = id;
					m_FieldsSet.insert(RequestField::BasketID);
					result = true;
				}//if check tips amount

				return result;
			}

			bool RequestData::resetBasketID() {
				m_BasketID.clear();
				m_FieldsSet.erase(RequestField::BasketID);
				return !isFieldSet(RequestField::BasketID);
			}

			const std::string &RequestData::getCardPANHash() const {
				return m_CardPANHash;
			}

			bool RequestData::setCardPANHash(const std::string &hashPAN) {
				bool result = false;

				if (!hashPAN.empty()) {
					m_CardPANHash = hashPAN;
					m_FieldsSet.insert(RequestField::CardPANHash);
					result = true;
				}//if check tips amount

				return result;
			}

			bool RequestData::resetCardPANHash() {
				m_CardPANHash.clear();
				m_FieldsSet.erase(RequestField::CardPANHash);
				return !isFieldSet(RequestField::CardPANHash);
			}

			const std::string &RequestData::getPaymentParam3() const {
                return m_PaymentParam3;
            }

            bool RequestData::setPaymentParam3(const std::string &param) {
                bool result = false;

                if (!param.empty()) {
                    m_PaymentParam3 = param;
                    m_FieldsSet.insert(RequestField::PaymentParam3);
                    result = true;
                }//if check tips amount

                return result;
            }

            bool RequestData::resetPaymentParam3() {
                m_PaymentParam3.clear();
                m_FieldsSet.erase(RequestField::PaymentParam3);
                return !isFieldSet(RequestField::PaymentParam3);
            }

            const std::string &RequestData::getAdditionalChoice() const {
                return m_AdditionalChoice;
            }//getAdditionalChoice()

            bool RequestData::setAdditionalChoice(const std::string &additionalChoice) {
                bool result = false;

                if (checkAdditionalChoiceRange(additionalChoice)) {
                    m_AdditionalChoice = additionalChoice;
                    m_FieldsSet.insert(RequestField::AdditionalChoice);
                    result = true;
                }//if check additional choice

                return result;
            }//setAdditionalChoice()

            bool RequestData::resetAdditionalChoice() {
                m_AdditionalChoice.clear();
                m_FieldsSet.erase(RequestField::AdditionalChoice);
                return !isFieldSet(RequestField::AdditionalChoice);
            }//resetAdditionalChoice()


            const std::set<RequestField> &RequestData::getFieldsSet() const {
                return m_FieldsSet;
            }//getFieldsSet()

            bool RequestData::isFieldSet(RequestField field) const {
                return m_FieldsSet.find(field) != m_FieldsSet.end();
            }//isFieldSet()


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
                    case RequestField::BonusBalance:
                        result = resetBonusBalance();
                        break;
                    case RequestField::BonusAmount:
                        result = resetBonusAmount();
                        break;
                    case RequestField::HashCardTrack2:
                        result = resetHashCardTrack2();
                        break;
                    case RequestField::SBP_RN:
                        result = resetSBP_RN();
                        break;
                    case RequestField::SBP_ReqID:
                        result = resetSBP_ReqID();
                        break;
                    case RequestField::PaymentPurpose:
                        result = resetPaymentPurpose();
                        break;
                    case RequestField::PaymentProviderCode:
                        result = resetPaymentProviderCode();
                        break;
                    case RequestField::PaymentParam1:
                        result = resetPaymentParam1();
                        break;
                    case RequestField::PaymentParam2:
                        result = resetPaymentParam2();
                        break;
                    case RequestField::PaymentParam3:
                        result = resetPaymentParam3();
                        break;
                    case RequestField::AdditionalChoice:
                        result = resetAdditionalChoice();
                        break;
					case RequestField::ECertAmount:
						result = resetECertAmount();
						break;
					case RequestField::BasketID:
						result = resetBasketID();
						break;
				}//switch fields

                return result;
            }//resetField(

            void RequestData::initValidator() {
                m_Validator = ValidatorFactory::getValidator(getOperationCode());
            }//initValidator()

            void RequestData::deinitValidator() {
                m_Validator.reset();
            }//deinitValidator()
        }//namespace Request
    }//namespace Message
}//namespace Lanter
