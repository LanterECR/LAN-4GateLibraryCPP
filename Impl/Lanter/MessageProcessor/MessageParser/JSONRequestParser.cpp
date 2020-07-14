//
// Created by Владимир Лысенков on 14.07.2020.
//


#include "JSONRequestParser.h"

#include "JSONGetFieldHelper.h"

namespace Lanter {
    namespace MessageProcessor {
        using namespace std::placeholders;

        std::shared_ptr<IRequestData> JSONRequestParser::parseData(const Json::Value &object) {
            return std::shared_ptr<IRequestData>();
        }

        const std::map<RequestFields, std::function<bool(const Json::Value&,IRequestData&)> > &
                JSONRequestParser::getFunctions() const {
            return m_ExtractFunctions;
        }

        bool JSONRequestParser::getFieldEcrNumber(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldEcrMerchantNumber(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldOperationCode(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldAmount(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldPartialAmount(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldTipsAmount(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldCashbackAmount(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldCurrencyCode(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldRRN(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldAuthCode(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldReceiptReference(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldTransactionID(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldCardDataEnc(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldOpenTags(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldEncTags(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldProviderCode(const Json::Value &object, IRequestData &requestData) {
            return false;
        }

        bool JSONRequestParser::getFieldAdditionalInfo(const Json::Value &object, IRequestData &requestData) {
            return false;
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
            return false;
        }
    }
}