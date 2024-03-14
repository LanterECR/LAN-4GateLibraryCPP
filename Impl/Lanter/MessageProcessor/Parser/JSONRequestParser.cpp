#include "JSONRequestParser.h"
#include "JSONGetFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFields/JSONRequestFields.h"
#include "Lanter/Message/Request/RequestDataFactory.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            using namespace std::placeholders;

            JSONRequestParser::JSONRequestParser()
            {
                initFunctionsMap();
            }

            std::shared_ptr<IRequestData> JSONRequestParser::parseData(const Json::Value &object)
            {
                std::shared_ptr<IRequestData> result = RequestDataFactory::getRequestData();

                if (result)
                {
                    if (!getFields(object, *result))
                    {
                        result.reset();
                    }
                }
                return result;
            }

            const std::map<RequestField, std::function<bool(const Json::Value &, IRequestData &)> > &
            JSONRequestParser::getFunctions() const
            {
                return m_ExtractFunctions;
            }

            bool JSONRequestParser::getFieldEcrNumber(const Json::Value &object, IRequestData &requestData)
            {
                int64_t ecrNumber;
                const bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getEcrNumber(), ecrNumber);

                return (exists && requestData.setEcrNumber(ecrNumber));
            }

            bool JSONRequestParser::getFieldEcrMerchantNumber(const Json::Value &object, IRequestData &requestData)
            {
                int64_t ecrMerchantNumber;
                const bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getEcrMerchantNumber(), ecrMerchantNumber);

                return (exists && requestData.setEcrMerchantNumber(ecrMerchantNumber));
            }

            bool JSONRequestParser::getFieldOperationCode(const Json::Value &object, IRequestData &requestData)
            {
                int operationCode;
                const bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getOperationCode(), operationCode);

                return (exists && requestData.setOperationCode(static_cast<OperationCode>(operationCode)));
            }

            bool JSONRequestParser::getFieldAmount(const Json::Value &object, IRequestData &requestData)
            {
                int64_t amount;
                const bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getAmount(), amount);

                return (exists && requestData.setAmount(amount));
            }

            bool JSONRequestParser::getFieldPartialAmount(const Json::Value &object, IRequestData &requestData)
            {
                int64_t partialAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getPartialAmount(),
                                                           partialAmount);
                bool result = exists && requestData.setPartialAmount(partialAmount);

                return result;
            }

            bool JSONRequestParser::getFieldTipsAmount(const Json::Value &object, IRequestData &requestData) {
                int64_t tipsAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getTipsAmount(), tipsAmount);
                bool result = exists && requestData.setTipsAmount(tipsAmount);

                return result;
            }

            bool JSONRequestParser::getFieldCashbackAmount(const Json::Value &object, IRequestData &requestData) {
                int64_t cashbackAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getCashbackAmount(),
                                                           cashbackAmount);
                bool result = exists && requestData.setCashbackAmount(cashbackAmount);

                return result;
            }

            bool JSONRequestParser::getFieldCurrencyCode(const Json::Value &object, IRequestData &requestData) {
                std::string currencyCode;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getCurrencyCode(), currencyCode);
                bool result = exists && requestData.setCurrencyCode(currencyCode);

                return result;
            }

            bool JSONRequestParser::getFieldRRN(const Json::Value &object, IRequestData &requestData) {
                std::string rrn;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getRRN(), rrn);
                bool result = exists && requestData.setRRN(rrn);

                return result;
            }

            bool JSONRequestParser::getFieldAuthCode(const Json::Value &object, IRequestData &requestData) {
                std::string authCode;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getAuthCode(), authCode);
                bool result = exists && requestData.setAuthCode(authCode);

                return result;
            }

            bool JSONRequestParser::getFieldReceiptReference(const Json::Value &object, IRequestData &requestData) {
                std::string receiptReference;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getReceiptReference(),
                                                           receiptReference);
                bool result = exists && requestData.setReceiptReference(receiptReference);

                return result;
            }

            bool JSONRequestParser::getFieldTransactionID(const Json::Value &object, IRequestData &requestData) {
                std::string transactionID;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getTransactionID(),
                                                           transactionID);
                bool result = exists && requestData.setTransactionID(transactionID);

                return result;
            }

            bool JSONRequestParser::getFieldCardDataEnc(const Json::Value &object, IRequestData &requestData) {
                std::string cardDataEnc;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getCardDataEnc(), cardDataEnc);
                bool result = exists && requestData.setCardDataEnc(cardDataEnc);

                return result;
            }

            bool JSONRequestParser::getFieldOpenTags(const Json::Value &object, IRequestData &requestData) {
                std::string openTags;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getOpenTags(), openTags);
                bool result = exists && requestData.setOpenTags(openTags);

                return result;
            }

            bool JSONRequestParser::getFieldEncTags(const Json::Value &object, IRequestData &requestData) {
                std::string encTags;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getEncTags(), encTags);
                bool result = exists && requestData.setEncTags(encTags);

                return result;
            }

            bool JSONRequestParser::getFieldProviderCode(const Json::Value &object, IRequestData &requestData) {
                std::string providerCode;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getProviderCode(), providerCode);
                bool result = exists && requestData.setProviderCode(providerCode);

                return result;
            }

            bool JSONRequestParser::getFieldAdditionalInfo(const Json::Value &object, IRequestData &requestData) {
                std::string additionalInfo;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getAdditionalInfo(),
                                                           additionalInfo);
                bool result = exists && requestData.setAdditionalInfo(additionalInfo);

                return result;
            }

            bool JSONRequestParser::getFieldBonusBalance(const Json::Value &object, IRequestData &requestData) {
                int64_t bonusBalance;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getBonusBalance(),
                                                           bonusBalance);
                bool result = exists && requestData.setBonusBalance(bonusBalance);

                return result;
            }

            bool JSONRequestParser::getFieldBonusAmount(const Json::Value &object, IRequestData &requestData) {
                int64_t bonusAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getBonusAmount(),
                                                           bonusAmount);
                bool result = exists && requestData.setBonusAmount(bonusAmount);

                return result;
            }

            bool JSONRequestParser::getFieldHashCardTrack2(const Json::Value &object, IRequestData &requestData) {
                std::string hashCardTrack2;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getHashCardTrack2(),
                                                           hashCardTrack2);
                bool result = exists && requestData.setHashCardTrack2(hashCardTrack2);

                return result;
            }

            bool JSONRequestParser::getFieldPaymentProviderCode(const Json::Value &object, IRequestData &requestData) {
                std::string paymentProviderCode;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getPaymentProviderCode(),
                                                           paymentProviderCode);
                bool result = exists && requestData.setPaymentProviderCode(paymentProviderCode);

                return result;
            }

            bool JSONRequestParser::getFieldPaymentParam1(const Json::Value &object, IRequestData &requestData) {
                std::string paymentParam;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getPaymentParam1(),
                                                           paymentParam);
                bool result = exists && requestData.setPaymentParam1(paymentParam);

                return result;
            }

            bool JSONRequestParser::getFieldPaymentParam2(const Json::Value &object, IRequestData &requestData) {
                std::string paymentParam;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getPaymentParam2(),
                                                           paymentParam);
                bool result = exists && requestData.setPaymentParam2(paymentParam);

                return result;
            }

            bool JSONRequestParser::getFieldPaymentParam3(const Json::Value &object, IRequestData &requestData)
            {
                std::string paymentParam;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getPaymentParam3(), paymentParam);
                bool result = exists && requestData.setPaymentParam3(paymentParam);

                return result;
            }

            bool JSONRequestParser::getFieldAdditionalChoice(const Json::Value &object, IRequestData &requestData)
            {
                std::string AdditionalChoice;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getAdditionalChoice(), AdditionalChoice);
                bool result = exists && requestData.setAdditionalChoice(AdditionalChoice);

                return result;
            }

            bool JSONRequestParser::getFieldTransportControlStation(const Json::Value& object, IRequestData& requestData)
            {
                std::string TransportControlStation;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getTransportControlStation(), TransportControlStation);
                bool result = exists && requestData.setTransportControlStation(TransportControlStation);

                return result;
            }

            bool JSONRequestParser::getFieldTransportControlArea(const Json::Value& object, IRequestData& requestData)
            {
                std::string TransportControlArea;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getTransportControlArea(), TransportControlArea);
                bool result = exists && requestData.setTransportControlArea(TransportControlArea);

                return result;
            }

            bool JSONRequestParser::getFieldTransportControlID(const Json::Value& object, IRequestData& requestData)
            {
                std::string TransportControlID;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getTransportControlID(), TransportControlID);
                bool result = exists && requestData.setTransportControlID(TransportControlID);

                return result;
            }

			bool JSONRequestParser::getFieldCardPANHash(const Json::Value &object, IRequestData &requestData)
            {
				std::string val;

				bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getCardPANHash(), val);
				bool result = exists && requestData.setCardPANHash(val);

				return result;
			}

			bool JSONRequestParser::getFieldECertAmount(const Json::Value &object, IRequestData &requestData)
            {
				int64_t amount;

				bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getECertAmount(), amount);
				bool result = exists && requestData.setECertAmount(amount);

				return result;
			}

			bool JSONRequestParser::getFieldBasketID(const Json::Value &object, IRequestData &requestData) {
				std::string val;

				bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getBasketID(), val);
				bool result = exists && requestData.setBasketID(val);

				return result;
			}

            void JSONRequestParser::initFunctionsMap() {

                m_ExtractFunctions[RequestField::EcrNumber] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldEcrNumber(object, requestData); };
                m_ExtractFunctions[RequestField::EcrMerchantNumber] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldEcrMerchantNumber(object, requestData); };
                m_ExtractFunctions[RequestField::OperationCode] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldOperationCode(object, requestData); };
                m_ExtractFunctions[RequestField::Amount] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldAmount(object, requestData); };
                m_ExtractFunctions[RequestField::PartialAmount] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldPartialAmount(object, requestData); };
                m_ExtractFunctions[RequestField::TipsAmount] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldTipsAmount(object, requestData); };
                m_ExtractFunctions[RequestField::CashbackAmount] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldCashbackAmount(object, requestData); };
                m_ExtractFunctions[RequestField::CurrencyCode] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldCurrencyCode(object, requestData); };
                m_ExtractFunctions[RequestField::RRN] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldRRN(object, requestData); };
                m_ExtractFunctions[RequestField::AuthCode] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldAuthCode(object, requestData); };
                m_ExtractFunctions[RequestField::ReceiptReference] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldReceiptReference(object, requestData); };
                m_ExtractFunctions[RequestField::TransactionID] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldTransactionID(object, requestData); };
                m_ExtractFunctions[RequestField::CardDataEnc] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldCardDataEnc(object, requestData); };
                m_ExtractFunctions[RequestField::OpenTags] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldOpenTags(object, requestData); };
                m_ExtractFunctions[RequestField::EncTags] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldEncTags(object, requestData); };
                m_ExtractFunctions[RequestField::ProviderCode] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldProviderCode(object, requestData); };
                m_ExtractFunctions[RequestField::AdditionalInfo] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldAdditionalInfo(object, requestData); };
                m_ExtractFunctions[RequestField::BonusBalance] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldBonusBalance(
                        object, requestData); };
                m_ExtractFunctions[RequestField::BonusAmount] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldBonusAmount(
                        object, requestData); };
                m_ExtractFunctions[RequestField::HashCardTrack2] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldHashCardTrack2(
                        object, requestData); };
                m_ExtractFunctions[RequestField::PaymentProviderCode] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldPaymentProviderCode(
                        object, requestData); };
                m_ExtractFunctions[RequestField::PaymentParam1] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldPaymentParam1(
                        object, requestData); };
                m_ExtractFunctions[RequestField::PaymentParam2] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldPaymentParam2(
                        object, requestData); };
                m_ExtractFunctions[RequestField::PaymentParam3] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldPaymentParam3(
                        object, requestData); };
                m_ExtractFunctions[RequestField::AdditionalChoice] = [this](const Json::Value& object, IRequestData& requestData) { return getFieldAdditionalChoice(
                        object, requestData); };

				m_ExtractFunctions[RequestField::CardPANHash] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldCardPANHash(object, requestData); };
				m_ExtractFunctions[RequestField::ECertAmount] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldECertAmount(object, requestData); };
				m_ExtractFunctions[RequestField::BasketID] = [this](const Json::Value &object, IRequestData &requestData) { return getFieldBasketID(object, requestData); };
			}

            bool JSONRequestParser::getFields(const Json::Value &object, IRequestData &requestData) {
                if (getFieldOperationCode(object, requestData)) {
                    for (auto field : requestData.getMandatoryFields()) {
                        auto function = m_ExtractFunctions.at(field);
                        function(object, requestData);
                    }

                    for (auto field : requestData.getOptionalFields()) {
                        auto function = m_ExtractFunctions.at(field);
                        function(object, requestData);
                    }
                }
                return requestData.validateMandatoryFields();
            }
        }
    }
}