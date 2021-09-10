#include "JSONRequestParser.h"

#include "JSONGetFieldHelper.h"
#include "Lanter/MessageProcessor/JSONMessageFields.h"
#include "Lanter/Message/Request/RequestDataFactory.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            using namespace std::placeholders;

            JSONRequestParser::JSONRequestParser() {
                initFunctionsMap();
            }

            std::shared_ptr<IRequestData> JSONRequestParser::parseData(const Json::Value &object) {
                std::shared_ptr<IRequestData> result = RequestDataFactory::getRequestData();

                if (result) {
                    if (!getFields(object, *result)) {
                        result.reset();
                    }
                }
                return result;
            }

            const std::map<RequestField, std::function<bool(const Json::Value &, IRequestData &)> > &
            JSONRequestParser::getFunctions() const {
                return m_ExtractFunctions;
            }

            bool JSONRequestParser::getFieldEcrNumber(const Json::Value &object, IRequestData &requestData) {
                int ecrNumber;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getEcrNumber(), ecrNumber);
                bool result = exists && requestData.setEcrNumber(ecrNumber);

                return result;
            }

            bool JSONRequestParser::getFieldEcrMerchantNumber(const Json::Value &object, IRequestData &requestData) {
                int ecrMerchantNumber;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getEcrMerchantNumber(),
                                                           ecrMerchantNumber);
                bool result = exists && requestData.setEcrMerchantNumber(ecrMerchantNumber);

                return result;
            }

            bool JSONRequestParser::getFieldOperationCode(const Json::Value &object, IRequestData &requestData) {
                int operationCode;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getOperationCode(),
                                                           operationCode);
                bool result = exists && requestData.setOperationCode(static_cast<OperationCode>(operationCode));

                return result;
            }

            bool JSONRequestParser::getFieldAmount(const Json::Value &object, IRequestData &requestData) {
                int64_t amount;

                bool exists = JSONGetFieldHelper::getField(object, JSONRequestFields::getAmount(), amount);
                bool result = exists && requestData.setAmount(amount);

                return result;
            }

            bool JSONRequestParser::getFieldPartialAmount(const Json::Value &object, IRequestData &requestData) {
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

            void JSONRequestParser::initFunctionsMap() {

                m_ExtractFunctions[RequestField::EcrNumber] = std::bind(&JSONRequestParser::getFieldEcrNumber, this, _1,
                                                                        _2);
                m_ExtractFunctions[RequestField::EcrMerchantNumber] = std::bind(
                        &JSONRequestParser::getFieldEcrMerchantNumber, this, _1, _2);
                m_ExtractFunctions[RequestField::OperationCode] = std::bind(&JSONRequestParser::getFieldOperationCode,
                                                                            this, _1, _2);
                m_ExtractFunctions[RequestField::Amount] = std::bind(&JSONRequestParser::getFieldAmount, this, _1, _2);
                m_ExtractFunctions[RequestField::PartialAmount] = std::bind(&JSONRequestParser::getFieldPartialAmount,
                                                                            this, _1, _2);
                m_ExtractFunctions[RequestField::TipsAmount] = std::bind(&JSONRequestParser::getFieldTipsAmount, this,
                                                                         _1, _2);
                m_ExtractFunctions[RequestField::CashbackAmount] = std::bind(&JSONRequestParser::getFieldCashbackAmount,
                                                                             this, _1, _2);
                m_ExtractFunctions[RequestField::CurrencyCode] = std::bind(&JSONRequestParser::getFieldCurrencyCode,
                                                                           this, _1, _2);
                m_ExtractFunctions[RequestField::RRN] = std::bind(&JSONRequestParser::getFieldRRN, this, _1, _2);
                m_ExtractFunctions[RequestField::AuthCode] = std::bind(&JSONRequestParser::getFieldAuthCode, this, _1,
                                                                       _2);
                m_ExtractFunctions[RequestField::ReceiptReference] = std::bind(
                        &JSONRequestParser::getFieldReceiptReference, this, _1, _2);
                m_ExtractFunctions[RequestField::TransactionID] = std::bind(&JSONRequestParser::getFieldTransactionID,
                                                                            this, _1, _2);
                m_ExtractFunctions[RequestField::CardDataEnc] = std::bind(&JSONRequestParser::getFieldCardDataEnc, this,
                                                                          _1, _2);
                m_ExtractFunctions[RequestField::OpenTags] = std::bind(&JSONRequestParser::getFieldOpenTags, this, _1,
                                                                       _2);
                m_ExtractFunctions[RequestField::EncTags] = std::bind(&JSONRequestParser::getFieldEncTags, this, _1,
                                                                      _2);
                m_ExtractFunctions[RequestField::ProviderCode] = std::bind(&JSONRequestParser::getFieldProviderCode,
                                                                           this, _1, _2);
                m_ExtractFunctions[RequestField::AdditionalInfo] = std::bind(&JSONRequestParser::getFieldAdditionalInfo,
                                                                             this, _1, _2);
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