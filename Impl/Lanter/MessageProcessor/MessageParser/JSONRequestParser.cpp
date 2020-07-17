//
// Created by Владимир Лысенков on 14.07.2020.
//


#include "JSONRequestParser.h"

#include "JSONGetFieldHelper.h"
#include "Lanter/MessageProcessor/JSONMessageFields.h"
#include "Lanter/Message/Request/RequestDataFactory.h"

namespace Lanter {
    namespace MessageProcessor {
        using namespace std::placeholders;

        JSONRequestParser::JSONRequestParser() {
            initFunctionsMap();
        }

        std::shared_ptr<IRequestData> JSONRequestParser::parseData(const Json::Value &object) {
            std::shared_ptr<IRequestData> result = RequestDataFactory::getRequestData();

            if(result) {
                if(!getFields(object, *result)) {
                    result.reset();
                }
            }
            return result;
        }

        const std::map<RequestFields, std::function<bool(const Json::Value&,IRequestData&)> > &
                JSONRequestParser::getFunctions() const {
            return m_ExtractFunctions;
        }

        bool JSONRequestParser::getFieldEcrNumber(const Json::Value &object, IRequestData &requestData) {
            int ecrNumber;

            bool exists = JSONGetFieldHelper::getFieldInt(object, JSONRequestFields::getEcrNumber(), ecrNumber);
            bool result = exists && requestData.setEcrNumber(ecrNumber);

            return result;
        }

        bool JSONRequestParser::getFieldEcrMerchantNumber(const Json::Value &object, IRequestData &requestData) {
            int ecrMerchantNumber;

            bool exists = JSONGetFieldHelper::getFieldInt(object, JSONRequestFields::getEcrMerchantNumber(), ecrMerchantNumber);
            bool result = exists && requestData.setEcrMerchantNumber(ecrMerchantNumber);

            return result;
        }

        bool JSONRequestParser::getFieldOperationCode(const Json::Value &object, IRequestData &requestData) {
            int operationCode;

            bool exists = JSONGetFieldHelper::getFieldInt(object, JSONRequestFields::getOperationCode(), operationCode);
            bool result = exists && requestData.setOperationCode(static_cast<OperationCodes>(operationCode));

            return result;
        }

        bool JSONRequestParser::getFieldAmount(const Json::Value &object, IRequestData &requestData) {
            int64_t amount;

            bool exists = JSONGetFieldHelper::getFieldInt64(object, JSONRequestFields::getAmount(), amount);
            bool result = exists && requestData.setAmount(amount);

            return result;
        }

        bool JSONRequestParser::getFieldPartialAmount(const Json::Value &object, IRequestData &requestData) {
            int64_t partialAmount;

            bool exists = JSONGetFieldHelper::getFieldInt64(object, JSONRequestFields::getPartialAmount(), partialAmount);
            bool result = exists && requestData.setPartialAmount(partialAmount);

            return result;
        }

        bool JSONRequestParser::getFieldTipsAmount(const Json::Value &object, IRequestData &requestData) {
            int64_t tipsAmount;

            bool exists = JSONGetFieldHelper::getFieldInt64(object, JSONRequestFields::getTipsAmount(), tipsAmount);
            bool result = exists && requestData.setTipsAmount(tipsAmount);

            return result;
        }

        bool JSONRequestParser::getFieldCashbackAmount(const Json::Value &object, IRequestData &requestData) {
            int64_t cashbackAmount;

            bool exists = JSONGetFieldHelper::getFieldInt64(object, JSONRequestFields::getCashbackAmount(), cashbackAmount);
            bool result = exists && requestData.setCashbackAmount(cashbackAmount);

            return result;
        }

        bool JSONRequestParser::getFieldCurrencyCode(const Json::Value &object, IRequestData &requestData) {
            int currencyCode;

            bool exists = JSONGetFieldHelper::getFieldInt(object, JSONRequestFields::getCurrencyCode(), currencyCode);
            bool result = exists && requestData.setCurrencyCode(currencyCode);

            return result;
        }

        bool JSONRequestParser::getFieldRRN(const Json::Value &object, IRequestData &requestData) {
            std::string RRN;

            bool exists = JSONGetFieldHelper::getFieldString(object, JSONRequestFields::getRRN(), RRN);
            bool result = exists && requestData.setRRN(RRN);

            return result;
        }

        bool JSONRequestParser::getFieldAuthCode(const Json::Value &object, IRequestData &requestData) {
            std::string authCode;

            bool exists = JSONGetFieldHelper::getFieldString(object, JSONRequestFields::getAuthCode(), authCode);
            bool result = exists && requestData.setAuthCode(authCode);

            return result;
        }

        bool JSONRequestParser::getFieldReceiptReference(const Json::Value &object, IRequestData &requestData) {
            std::string receiptReference;

            bool exists = JSONGetFieldHelper::getFieldString(object, JSONRequestFields::getReceiptReference(), receiptReference);
            bool result = exists && requestData.setReceiptReference(receiptReference);

            return result;
        }

        bool JSONRequestParser::getFieldTransactionID(const Json::Value &object, IRequestData &requestData) {
            std::string transactionID;

            bool exists = JSONGetFieldHelper::getFieldString(object, JSONRequestFields::getTransactionID(), transactionID);
            bool result = exists && requestData.setTransactionID(transactionID);

            return result;
        }

        bool JSONRequestParser::getFieldCardDataEnc(const Json::Value &object, IRequestData &requestData) {
            std::string cardDataEnc;

            bool exists = JSONGetFieldHelper::getFieldString(object, JSONRequestFields::getCardDataEnc(), cardDataEnc);
            bool result = exists && requestData.setCardDataEnc(cardDataEnc);

            return result;
        }

        bool JSONRequestParser::getFieldOpenTags(const Json::Value &object, IRequestData &requestData) {
            std::string openTags;

            bool exists = JSONGetFieldHelper::getFieldString(object, JSONRequestFields::getOpenTags(), openTags);
            bool result = exists && requestData.setOpenTags(openTags);

            return result;
        }

        bool JSONRequestParser::getFieldEncTags(const Json::Value &object, IRequestData &requestData) {
            std::string encTags;

            bool exists = JSONGetFieldHelper::getFieldString(object, JSONRequestFields::getEncTags(), encTags);
            bool result = exists && requestData.setEncTags(encTags);

            return result;
        }

        bool JSONRequestParser::getFieldProviderCode(const Json::Value &object, IRequestData &requestData) {
            std::string providerCode;

            bool exists = JSONGetFieldHelper::getFieldString(object, JSONRequestFields::getProviderCode(), providerCode);
            bool result = exists && requestData.setProviderCode(providerCode);

            return result;
        }

        bool JSONRequestParser::getFieldAdditionalInfo(const Json::Value &object, IRequestData &requestData) {
            std::string additionalInfo;

            bool exists = JSONGetFieldHelper::getFieldString(object, JSONRequestFields::getAdditionalInfo(), additionalInfo);
            bool result = exists && requestData.setAdditionalInfo(additionalInfo);

            return result;
        }

        void JSONRequestParser::initFunctionsMap() {

            m_ExtractFunctions[RequestFields::EcrNumber] = std::bind(&JSONRequestParser::getFieldEcrNumber, this, _1, _2);
            m_ExtractFunctions[RequestFields::EcrMerchantNumber] = std::bind(&JSONRequestParser::getFieldEcrMerchantNumber, this, _1, _2);
            m_ExtractFunctions[RequestFields::OperationCode] = std::bind(&JSONRequestParser::getFieldOperationCode, this, _1, _2);
            m_ExtractFunctions[RequestFields::Amount] = std::bind(&JSONRequestParser::getFieldAmount, this, _1, _2);
            m_ExtractFunctions[RequestFields::PartialAmount] = std::bind(&JSONRequestParser::getFieldPartialAmount, this, _1, _2);
            m_ExtractFunctions[RequestFields::TipsAmount] = std::bind(&JSONRequestParser::getFieldTipsAmount, this, _1, _2);
            m_ExtractFunctions[RequestFields::CashbackAmount] = std::bind(&JSONRequestParser::getFieldCashbackAmount, this, _1, _2);
            m_ExtractFunctions[RequestFields::CurrencyCode] = std::bind(&JSONRequestParser::getFieldCurrencyCode, this, _1, _2);
            m_ExtractFunctions[RequestFields::RRN] = std::bind(&JSONRequestParser::getFieldRRN, this, _1, _2);
            m_ExtractFunctions[RequestFields::AuthCode] = std::bind(&JSONRequestParser::getFieldAuthCode, this, _1, _2);
            m_ExtractFunctions[RequestFields::ReceiptReference] = std::bind(&JSONRequestParser::getFieldReceiptReference, this, _1, _2);
            m_ExtractFunctions[RequestFields::TransactionID] = std::bind(&JSONRequestParser::getFieldTransactionID, this, _1, _2);
            m_ExtractFunctions[RequestFields::CardDataEnc] = std::bind(&JSONRequestParser::getFieldCardDataEnc, this, _1, _2);
            m_ExtractFunctions[RequestFields::OpenTags] = std::bind(&JSONRequestParser::getFieldOpenTags, this, _1, _2);
            m_ExtractFunctions[RequestFields::EncTags] = std::bind(&JSONRequestParser::getFieldEncTags, this, _1, _2);
            m_ExtractFunctions[RequestFields::ProviderCode] = std::bind(&JSONRequestParser::getFieldProviderCode, this, _1, _2);
            m_ExtractFunctions[RequestFields::AdditionalInfo] = std::bind(&JSONRequestParser::getFieldAdditionalInfo, this, _1, _2);
        }

        bool JSONRequestParser::getFields(const Json::Value &object, IRequestData &requestData) {
            if(getFieldOperationCode(object, requestData)) {
                for(auto field : requestData.getMandatoryFields()) {
                    auto function = m_ExtractFunctions.at(field);
                    function(object, requestData);
                }

                for(auto field : requestData.getOptionalFields()) {
                    auto function = m_ExtractFunctions.at(field);
                    function( object, requestData);
                }
            }
            return requestData.validateMandatoryFields();
        }
    }
}