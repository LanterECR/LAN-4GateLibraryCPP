//
// Created by Владимир Лысенков on 19.07.2020.
//

#include "JSONResponseParser.h"

#include "JSONGetFieldHelper.h"
#include "Lanter/MessageProcessor/JSONMessageFields.h"
#include "Lanter/Message/Request/RequestDataFactory.h"

namespace Lanter {
    namespace MessageProcessor {
        using namespace std::placeholders;
        JSONResponseParser::JSONResponseParser() {
            initFunctionsMap();
        }

        std::shared_ptr<IResponseData> JSONResponseParser::parseData(const Json::Value &object) {
            return std::shared_ptr<IResponseData>();
        }

        const std::map<ResponseFields, std::function<bool(const Json::Value &, IResponseData &)> > &
        JSONResponseParser::getFunctions() const {
            return m_ExtractFunctions;
        }

        bool JSONResponseParser::getFieldEcrNumber(const Json::Value & object, IResponseData & requestData) {
            int ecrNumber;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getEcrNumber(), ecrNumber);
            bool result = exists && requestData.setEcrNumber(ecrNumber);

            return result;
        }
        bool JSONResponseParser::getFieldEcrMerchantNumber(const Json::Value & object, IResponseData & requestData) {
            int ecrMerchantNumber;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getEcrMerchantNumber(),
                                                       ecrMerchantNumber);
            bool result = exists && requestData.setEcrMerchantNumber(ecrMerchantNumber);

            return result;
        }
        bool JSONResponseParser::getFieldOperationCode(const Json::Value & object, IResponseData & requestData) {
            int operationCode;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getOperationCode(), operationCode);
            bool result = exists && requestData.setOperationCode(static_cast<OperationCode>(operationCode));

            return result;
        }
        bool JSONResponseParser::getFieldOriginalOperationCode(const Json::Value & object, IResponseData & requestData) {
            int originalOperationCode;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getOriginalOperationCode(),
                                                       originalOperationCode);
            bool result = exists && requestData.setOriginalOperationCode(static_cast<OperationCode>(originalOperationCode));

            return result;
        }
        bool JSONResponseParser::getFieldTotalAmount(const Json::Value & object, IResponseData & requestData) {
            int64_t totalAmount;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTotalAmount(), totalAmount);
            bool result = exists && requestData.setTotalAmount(totalAmount);

            return result;
        }
        bool JSONResponseParser::getFieldPartialAmount(const Json::Value & object, IResponseData & requestData) {
            int64_t partialAmount;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getPartialAmount(), partialAmount);
            bool result = exists && requestData.setPartialAmount(partialAmount);

            return result;
        }
        bool JSONResponseParser::getFieldAcquirerFeeAmount(const Json::Value & object, IResponseData & requestData) {
            int64_t acquirerFeeAmount;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getAcquirerFeeAmount(),
                                                       acquirerFeeAmount);
            bool result = exists && requestData.setAcquirerFeeAmount(acquirerFeeAmount);

            return result;
        }
        bool JSONResponseParser::getFieldTerminalFeeAmount(const Json::Value & object, IResponseData & requestData) {
            int64_t terminalFeeAmount;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTerminalFeeAmount(),
                                                       terminalFeeAmount);
            bool result = exists && requestData.setTerminalFeeAmount(terminalFeeAmount);

            return result;
        }
        bool JSONResponseParser::getFieldTipsAmount(const Json::Value & object, IResponseData & requestData) {
            int64_t tipsAmount;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTipsAmount(), tipsAmount);
            bool result = exists && requestData.setTipsAmount(tipsAmount);

            return result;
        }
        bool JSONResponseParser::getFieldCurrencyCode(const Json::Value & object, IResponseData & requestData) {
            int currencyCode;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCurrencyCode(), currencyCode);
            bool result = exists && requestData.setCurrencyCode(currencyCode);

            return result;
        }
        bool JSONResponseParser::getFieldReceiptReference(const Json::Value & object, IResponseData & requestData) {
            std::string receiptReference;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getReceiptReference(),
                                                       receiptReference);
            bool result = exists && requestData.setReceiptReference(receiptReference);

            return result;
        }
        bool JSONResponseParser::getFieldRRN(const Json::Value & object, IResponseData & requestData) {
            std::string rrn;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getRRN(), rrn);
            bool result = exists && requestData.setRRN(rrn);

            return result;
        }
        bool JSONResponseParser::getFieldStatus(const Json::Value & object, IResponseData & requestData) {
            int status;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getStatus(), status);
            bool result = exists && requestData.setStatus(static_cast<Status>(status));

            return result;
        }
        bool JSONResponseParser::getFieldOriginalOperationStatus(const Json::Value & object, IResponseData & requestData) {
            int originalOperationStatus;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getOriginalOperationStatus(),
                                                       originalOperationStatus);
            bool result = exists && requestData.setOriginalOperationStatus(static_cast<Status>(originalOperationStatus));

            return result;
        }
        bool JSONResponseParser::getFieldTransDateTime(const Json::Value & object, IResponseData & requestData) {
            std::string transDateTime;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTransDateTime(), transDateTime);
            bool result = exists && requestData.setTransDateTime(transDateTime);

            return result;
        }
        bool JSONResponseParser::getFieldTerminalDateTime(const Json::Value & object, IResponseData & requestData) {
            std::string terminalDateTime;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTerminalDateTime(),
                                                       terminalDateTime);
            bool result = exists && requestData.setTerminalDateTime(terminalDateTime);

            return result;
        }
        bool JSONResponseParser::getFieldCardPAN(const Json::Value & object, IResponseData & requestData) {
            std::string cardPAN;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardPAN(), cardPAN);
            bool result = exists && requestData.setCardPAN(cardPAN);

            return result;
        }
        bool JSONResponseParser::getFieldExpireDate(const Json::Value & object, IResponseData & requestData) {
            std::string expireDate;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getExpireDate(), expireDate);
            bool result = exists && requestData.setExpireDate(expireDate);

            return result;
        }
        bool JSONResponseParser::getFieldCardholderName(const Json::Value & object, IResponseData & requestData) {
            std::string cardholderName;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardholderName(), cardholderName);
            bool result = exists && requestData.setCardholderName(cardholderName);

            return result;
        }
        bool JSONResponseParser::getFieldCardholderAuthMethod(const Json::Value & object, IResponseData & requestData) {
            int cardholderAuthMethod;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardholderAuthMethod(),
                                                       cardholderAuthMethod);
            bool result = exists && requestData.setCardholderAuthMethod(static_cast<CardholderAuthMethod>(cardholderAuthMethod));

            return result;
        }
        bool JSONResponseParser::getFieldAuthCode(const Json::Value & object, IResponseData & requestData) {
            std::string authCode;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getAuthCode(), authCode);
            bool result = exists && requestData.setAuthCode(authCode);

            return result;
        }
        bool JSONResponseParser::getFieldResponseCode(const Json::Value & object, IResponseData & requestData) {
            std::string responseCode;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getResponseCode(), responseCode);
            bool result = exists && requestData.setResponseCode(responseCode);

            return result;
        }
        bool JSONResponseParser::getFieldResponseText(const Json::Value & object, IResponseData & requestData) {
            std::string responseText;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getResponseText(), responseText);
            bool result = exists && requestData.setResponseText(responseText);

            return result;
        }
        bool JSONResponseParser::getFieldSTAN(const Json::Value & object, IResponseData & requestData) {
            std::string STAN;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSTAN(), STAN);
            bool result = exists && requestData.setSTAN(STAN);

            return result;
        }
        bool JSONResponseParser::getFieldTransactionID(const Json::Value & object, IResponseData & requestData) {
            std::string transactionID;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTransactionID(), transactionID);
            bool result = exists && requestData.setTransactionID(transactionID);

            return result;
        }
        bool JSONResponseParser::getFieldTerminalID(const Json::Value & object, IResponseData & requestData) {
            std::string terminalID;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTerminalID(), terminalID);
            bool result = exists && requestData.setTerminalID(terminalID);

            return result;
        }
        bool JSONResponseParser::getFieldCardEmvAid(const Json::Value & object, IResponseData & requestData) {
            std::string cardEmvAid;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardEmvAid(), cardEmvAid);
            bool result = exists && requestData.setCardEmvAid(cardEmvAid);

            return result;
        }
        bool JSONResponseParser::getFieldCardAppName(const Json::Value & object, IResponseData & requestData) {
            std::string cardAppName;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardAppName(), cardAppName);
            bool result = exists && requestData.setCardAppName(cardAppName);

            return result;
        }
        bool JSONResponseParser::getFieldCardInputMethod(const Json::Value & object, IResponseData & requestData) {
            int cardInputMethod;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardInputMethod(),
                                                       cardInputMethod);
            bool result = exists && requestData.setCardInputMethod(static_cast<CardInputMethod>(cardInputMethod));

            return result;
        }
        bool JSONResponseParser::getFieldIssuerName(const Json::Value & object, IResponseData & requestData) {
            std::string issuerName;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getIssuerName(), issuerName);
            bool result = exists && requestData.setIssuerName(issuerName);

            return result;
        }
        bool JSONResponseParser::getFieldAdditionalInfo(const Json::Value & object, IResponseData & requestData) {
            std::string additionalInfo;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getAdditionalInfo(), additionalInfo);
            bool result = exists && requestData.setAdditionalInfo(additionalInfo);

            return result;
        }
        bool JSONResponseParser::getFieldCardData(const Json::Value & object, IResponseData & requestData) {
            std::string cardData;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardData(), cardData);
            bool result = exists && requestData.setCardData(cardData);

            return result;
        }
        bool JSONResponseParser::getFieldCardDataEnc(const Json::Value & object, IResponseData & requestData) {
            std::string cardDataEnc;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardDataEnc(), cardDataEnc);
            bool result = exists && requestData.setCardDataEnc(cardDataEnc);

            return result;
        }
        bool JSONResponseParser::getFieldMerchantID(const Json::Value & object, IResponseData & requestData) {
            std::string merchantId;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getMerchantID(), merchantId);
            bool result = exists && requestData.setMerchantID(merchantId);

            return result;
        }
        bool JSONResponseParser::getFieldTVR(const Json::Value & object, IResponseData & requestData) {
            std::string TVR;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTVR(), TVR);
            bool result = exists && requestData.setTVR(TVR);

            return result;
        }
        bool JSONResponseParser::getFieldTSI(const Json::Value & object, IResponseData & requestData) {
            std::string TSI;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTSI(), TSI);
            bool result = exists && requestData.setTSI(TSI);

            return result;
        }
        bool JSONResponseParser::getFieldTC(const Json::Value & object, IResponseData & requestData) {
            std::string TC;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTC(), TC);
            bool result = exists && requestData.setTC(TC);

            return result;
        }
        bool JSONResponseParser::getFieldCID(const Json::Value & object, IResponseData & requestData) {
            std::string CID;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCID(), CID);
            bool result = exists && requestData.setCID(CID);

            return result;
        }
        bool JSONResponseParser::getFieldKVR(const Json::Value & object, IResponseData & requestData) {
            std::string KVR;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getKVR(), KVR);
            bool result = exists && requestData.setKVR(KVR);

            return result;
        }
        bool JSONResponseParser::getFieldCDAResult(const Json::Value & object, IResponseData & requestData) {
            std::string CDAResult;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCDAResult(), CDAResult);
            bool result = exists && requestData.setCDAResult(CDAResult);

            return result;
        }
        bool JSONResponseParser::getFieldSalesCount(const Json::Value & object, IResponseData & requestData) {
            int salesCount;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSalesCount(), salesCount);
            bool result = exists && requestData.setSalesCount(salesCount);

            return result;
        }
        bool JSONResponseParser::getFieldVoidCount(const Json::Value & object, IResponseData & requestData) {
            int voidCount;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getVoidCount(), voidCount);
            bool result = exists && requestData.setVoidCount(voidCount);

            return result;
        }
        bool JSONResponseParser::getFieldRefundCount(const Json::Value & object, IResponseData & requestData) {
            int refundCount;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getRefundCount(), refundCount);
            bool result = exists && requestData.setRefundCount(refundCount);

            return result;
        }
        bool JSONResponseParser::getFieldSalesArray(const Json::Value & object, IResponseData & requestData) {
            /*Json::Value SalesArray;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSalesArray(), SalesArray);
            bool result = exists && requestData.setSalesArray(SalesArray);*/

            return false;
        }
        bool JSONResponseParser::getFieldVoidArray(const Json::Value & object, IResponseData & requestData) {
            /*int VoidArray;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getVoidArray(), VoidArray);
            bool result = exists && requestData.setVoidArray(VoidArray);*/

            return false;
        }
        bool JSONResponseParser::getFieldRefundArray(const Json::Value & object, IResponseData & requestData) {
            /*int RefundArray;

            bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getRefundArray(), RefundArray);
            bool result = exists && requestData.setRefundArray(RefundArray);*/

            return false;
        }

        void JSONResponseParser::initFunctionsMap() {
            m_ExtractFunctions[ResponseFields::EcrNumber] = std::bind(&JSONResponseParser::getFieldEcrNumber, this, _1, _2);
            m_ExtractFunctions[ResponseFields::EcrMerchantNumber] = std::bind(&JSONResponseParser::getFieldEcrMerchantNumber, this, _1, _2);
            m_ExtractFunctions[ResponseFields::OperationCode] = std::bind(&JSONResponseParser::getFieldOperationCode, this, _1, _2);
            m_ExtractFunctions[ResponseFields::OriginalOperationCode] = std::bind(&JSONResponseParser::getFieldOriginalOperationCode, this, _1, _2);
            m_ExtractFunctions[ResponseFields::TotalAmount] = std::bind(&JSONResponseParser::getFieldTotalAmount, this, _1, _2);
            m_ExtractFunctions[ResponseFields::PartialAmount] = std::bind(&JSONResponseParser::getFieldPartialAmount, this, _1, _2);
            m_ExtractFunctions[ResponseFields::AcquirerFeeAmount] = std::bind(&JSONResponseParser::getFieldAcquirerFeeAmount, this, _1, _2);
            m_ExtractFunctions[ResponseFields::TerminalFeeAmount] = std::bind(&JSONResponseParser::getFieldTerminalFeeAmount, this, _1, _2);
            m_ExtractFunctions[ResponseFields::TipsAmount] = std::bind(&JSONResponseParser::getFieldTipsAmount, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CurrencyCode] = std::bind(&JSONResponseParser::getFieldCurrencyCode, this, _1, _2);
            m_ExtractFunctions[ResponseFields::ReceiptReference] = std::bind(&JSONResponseParser::getFieldReceiptReference, this, _1, _2);
            m_ExtractFunctions[ResponseFields::RRN] = std::bind(&JSONResponseParser::getFieldRRN, this, _1, _2);
            m_ExtractFunctions[ResponseFields::Status] = std::bind(&JSONResponseParser::getFieldStatus, this, _1, _2);
            m_ExtractFunctions[ResponseFields::OriginalOperationStatus] = std::bind(&JSONResponseParser::getFieldOriginalOperationStatus, this, _1, _2);
            m_ExtractFunctions[ResponseFields::TransDateTime] = std::bind(&JSONResponseParser::getFieldTransDateTime, this, _1, _2);
            m_ExtractFunctions[ResponseFields::TerminalDateTime] = std::bind(&JSONResponseParser::getFieldTerminalDateTime, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CardPAN] = std::bind(&JSONResponseParser::getFieldCardPAN, this, _1, _2);
            m_ExtractFunctions[ResponseFields::ExpireDate] = std::bind(&JSONResponseParser::getFieldExpireDate, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CardholderName] = std::bind(&JSONResponseParser::getFieldCardholderName, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CardholderAuthMethod] = std::bind(&JSONResponseParser::getFieldCardholderAuthMethod, this, _1, _2);
            m_ExtractFunctions[ResponseFields::AuthCode] = std::bind(&JSONResponseParser::getFieldAuthCode, this, _1, _2);
            m_ExtractFunctions[ResponseFields::ResponseCode] = std::bind(&JSONResponseParser::getFieldResponseCode, this, _1, _2);
            m_ExtractFunctions[ResponseFields::ResponseText] = std::bind(&JSONResponseParser::getFieldResponseText, this, _1, _2);
            m_ExtractFunctions[ResponseFields::STAN] = std::bind(&JSONResponseParser::getFieldSTAN, this, _1, _2);
            m_ExtractFunctions[ResponseFields::TransactionID] = std::bind(&JSONResponseParser::getFieldTransactionID, this, _1, _2);
            m_ExtractFunctions[ResponseFields::TerminalID] = std::bind(&JSONResponseParser::getFieldTerminalID, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CardEmvAid] = std::bind(&JSONResponseParser::getFieldCardEmvAid, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CardAppName] = std::bind(&JSONResponseParser::getFieldCardAppName, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CardInputMethod] = std::bind(&JSONResponseParser::getFieldCardInputMethod, this, _1, _2);
            m_ExtractFunctions[ResponseFields::IssuerName] = std::bind(&JSONResponseParser::getFieldIssuerName, this, _1, _2);
            m_ExtractFunctions[ResponseFields::AdditionalInfo] = std::bind(&JSONResponseParser::getFieldAdditionalInfo, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CardData] = std::bind(&JSONResponseParser::getFieldCardData, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CardDataEnc] = std::bind(&JSONResponseParser::getFieldCardDataEnc, this, _1, _2);
            m_ExtractFunctions[ResponseFields::MerchantID] = std::bind(&JSONResponseParser::getFieldMerchantID, this, _1, _2);
            m_ExtractFunctions[ResponseFields::TVR] = std::bind(&JSONResponseParser::getFieldTVR, this, _1, _2);
            m_ExtractFunctions[ResponseFields::TSI] = std::bind(&JSONResponseParser::getFieldTSI, this, _1, _2);
            m_ExtractFunctions[ResponseFields::TC] = std::bind(&JSONResponseParser::getFieldTC, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CID] = std::bind(&JSONResponseParser::getFieldCID, this, _1, _2);
            m_ExtractFunctions[ResponseFields::KVR] = std::bind(&JSONResponseParser::getFieldKVR, this, _1, _2);
            m_ExtractFunctions[ResponseFields::CDAResult] = std::bind(&JSONResponseParser::getFieldCDAResult, this, _1, _2);
            m_ExtractFunctions[ResponseFields::SalesCount] = std::bind(&JSONResponseParser::getFieldSalesCount, this, _1, _2);
            m_ExtractFunctions[ResponseFields::VoidCount] = std::bind(&JSONResponseParser::getFieldVoidCount, this, _1, _2);
            m_ExtractFunctions[ResponseFields::RefundCount] = std::bind(&JSONResponseParser::getFieldRefundCount, this, _1, _2);
            m_ExtractFunctions[ResponseFields::SalesArray] = std::bind(&JSONResponseParser::getFieldSalesArray, this, _1, _2);
            m_ExtractFunctions[ResponseFields::VoidArray] = std::bind(&JSONResponseParser::getFieldVoidArray, this, _1, _2);
            m_ExtractFunctions[ResponseFields::RefundArray] = std::bind(&JSONResponseParser::getFieldRefundArray, this, _1, _2);
        }

        bool JSONResponseParser::getFields(const Json::Value &object, IResponseData &requestData) {
            return false;
        }
    }
}