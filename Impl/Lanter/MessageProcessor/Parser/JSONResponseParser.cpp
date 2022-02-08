#include "JSONResponseParser.h"

#include "JSONGetFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFields/JSONResponseFields.h"
#include "Lanter/Message/Response/ResponseDataFactory.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            using namespace std::placeholders;

            JSONResponseParser::JSONResponseParser() {
                initFunctionsMap();
            }

            std::shared_ptr<IResponseData> JSONResponseParser::parseData(const Json::Value &object) {
                std::shared_ptr<IResponseData> result = ResponseDataFactory::getResponseData();

                if (result) {
                    if (!getFields(object, *result)) {
                        result.reset();
                    }
                }
                return result;
            }

            const std::map<ResponseField, std::function<bool(const Json::Value &, IResponseData &)> > &
            JSONResponseParser::getFunctions() const {
                return m_ExtractFunctions;
            }

            bool JSONResponseParser::getFieldEcrNumber(const Json::Value &object, IResponseData &responseData) {
                int ecrNumber;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getEcrNumber(), ecrNumber);
                bool result = exists && responseData.setEcrNumber(ecrNumber);

                return result;
            }

            bool JSONResponseParser::getFieldEcrMerchantNumber(const Json::Value &object, IResponseData &responseData) {
                int ecrMerchantNumber;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getEcrMerchantNumber(),
                                                           ecrMerchantNumber);
                bool result = exists && responseData.setEcrMerchantNumber(ecrMerchantNumber);

                return result;
            }

            bool JSONResponseParser::getFieldOperationCode(const Json::Value &object, IResponseData &responseData) {
                int operationCode;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getOperationCode(),
                                                           operationCode);
                bool result = exists && responseData.setOperationCode(static_cast<OperationCode>(operationCode));

                return result;
            }

            bool
            JSONResponseParser::getFieldOriginalOperationCode(const Json::Value &object, IResponseData &responseData) {
                int originalOperationCode;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getOriginalOperationCode(),
                                                           originalOperationCode);
                bool result = exists &&
                              responseData.setOriginalOperationCode(static_cast<OperationCode>(originalOperationCode));

                return result;
            }

            bool JSONResponseParser::getFieldTotalAmount(const Json::Value &object, IResponseData &responseData) {
                int64_t totalAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTotalAmount(), totalAmount);
                bool result = exists && responseData.setTotalAmount(totalAmount);

                return result;
            }

            bool JSONResponseParser::getFieldPartialAmount(const Json::Value &object, IResponseData &responseData) {
                int64_t partialAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getPartialAmount(),
                                                           partialAmount);
                bool result = exists && responseData.setPartialAmount(partialAmount);

                return result;
            }

            bool JSONResponseParser::getFieldAcquirerFeeAmount(const Json::Value &object, IResponseData &responseData) {
                int64_t acquirerFeeAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getAcquirerFeeAmount(),
                                                           acquirerFeeAmount);
                bool result = exists && responseData.setAcquirerFeeAmount(acquirerFeeAmount);

                return result;
            }

            bool JSONResponseParser::getFieldTerminalFeeAmount(const Json::Value &object, IResponseData &responseData) {
                int64_t terminalFeeAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTerminalFeeAmount(),
                                                           terminalFeeAmount);
                bool result = exists && responseData.setTerminalFeeAmount(terminalFeeAmount);

                return result;
            }

            bool JSONResponseParser::getFieldTipsAmount(const Json::Value &object, IResponseData &responseData) {
                int64_t tipsAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTipsAmount(), tipsAmount);
                bool result = exists && responseData.setTipsAmount(tipsAmount);

                return result;
            }

            bool JSONResponseParser::getFieldCurrencyCode(const Json::Value &object, IResponseData &responseData) {
                std::string currencyCode;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCurrencyCode(), currencyCode);
                bool result = exists && responseData.setCurrencyCode(currencyCode);

                return result;
            }

            bool JSONResponseParser::getFieldReceiptReference(const Json::Value &object, IResponseData &responseData) {
                std::string receiptReference;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getReceiptReference(),
                                                           receiptReference);
                bool result = exists && responseData.setReceiptReference(receiptReference);

                return result;
            }

            bool JSONResponseParser::getFieldRRN(const Json::Value &object, IResponseData &responseData) {
                std::string rrn;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getRRN(), rrn);
                bool result = exists && responseData.setRRN(rrn);

                return result;
            }

            bool JSONResponseParser::getFieldStatus(const Json::Value &object, IResponseData &responseData) {
                int status;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getStatus(), status);
                bool result = exists && responseData.setStatus(static_cast<Status>(status));

                return result;
            }

            bool JSONResponseParser::getFieldOriginalOperationStatus(const Json::Value &object,
                                                                     IResponseData &responseData) {
                int originalOperationStatus;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getOriginalOperationStatus(),
                                                           originalOperationStatus);
                bool result =
                        exists && responseData.setOriginalOperationStatus(static_cast<Status>(originalOperationStatus));

                return result;
            }

            bool JSONResponseParser::getFieldTransDateTime(const Json::Value &object, IResponseData &responseData) {
                std::string transDateTime;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTransDateTime(),
                                                           transDateTime);
                bool result = exists && responseData.setTransDateTime(transDateTime);

                return result;
            }

            bool JSONResponseParser::getFieldTerminalDateTime(const Json::Value &object, IResponseData &responseData) {
                std::string terminalDateTime;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTerminalDateTime(),
                                                           terminalDateTime);
                bool result = exists && responseData.setTerminalDateTime(terminalDateTime);

                return result;
            }

            bool JSONResponseParser::getFieldCardPAN(const Json::Value &object, IResponseData &responseData) {
                std::string cardPAN;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardPAN(), cardPAN);
                bool result = exists && responseData.setCardPAN(cardPAN);

                return result;
            }

            bool JSONResponseParser::getFieldExpireDate(const Json::Value &object, IResponseData &responseData) {
                std::string expireDate;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getExpireDate(), expireDate);
                bool result = exists && responseData.setExpireDate(expireDate);

                return result;
            }

            bool JSONResponseParser::getFieldCardholderName(const Json::Value &object, IResponseData &responseData) {
                std::string cardholderName;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardholderName(),
                                                           cardholderName);
                bool result = exists && responseData.setCardholderName(cardholderName);

                return result;
            }

            bool
            JSONResponseParser::getFieldCardholderAuthMethod(const Json::Value &object, IResponseData &responseData) {
                int cardholderAuthMethod;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardholderAuthMethod(),
                                                           cardholderAuthMethod);
                bool result = exists && responseData.setCardholderAuthMethod(
                        static_cast<CardholderAuthMethod>(cardholderAuthMethod));

                return result;
            }

            bool JSONResponseParser::getFieldAuthCode(const Json::Value &object, IResponseData &responseData) {
                std::string authCode;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getAuthCode(), authCode);
                bool result = exists && responseData.setAuthCode(authCode);

                return result;
            }

            bool JSONResponseParser::getFieldResponseCode(const Json::Value &object, IResponseData &responseData) {
                std::string responseCode;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getResponseCode(), responseCode);
                bool result = exists && responseData.setResponseCode(responseCode);

                return result;
            }

            bool JSONResponseParser::getFieldResponseText(const Json::Value &object, IResponseData &responseData) {
                std::string responseText;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getResponseText(), responseText);
                bool result = exists && responseData.setResponseText(responseText);

                return result;
            }

            bool JSONResponseParser::getFieldSTAN(const Json::Value &object, IResponseData &responseData) {
                std::string STAN;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSTAN(), STAN);
                bool result = exists && responseData.setSTAN(STAN);

                return result;
            }

            bool JSONResponseParser::getFieldTransactionID(const Json::Value &object, IResponseData &responseData) {
                std::string transactionID;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTransactionID(),
                                                           transactionID);
                bool result = exists && responseData.setTransactionID(transactionID);

                return result;
            }

            bool JSONResponseParser::getFieldTerminalID(const Json::Value &object, IResponseData &responseData) {
                std::string terminalID;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTerminalID(), terminalID);
                bool result = exists && responseData.setTerminalID(terminalID);

                return result;
            }

            bool JSONResponseParser::getFieldCardEmvAid(const Json::Value &object, IResponseData &responseData) {
                std::string cardEmvAid;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardEmvAid(), cardEmvAid);
                bool result = exists && responseData.setCardEmvAid(cardEmvAid);

                return result;
            }

            bool JSONResponseParser::getFieldCardAppName(const Json::Value &object, IResponseData &responseData) {
                std::string cardAppName;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardAppName(), cardAppName);
                bool result = exists && responseData.setCardAppName(cardAppName);

                return result;
            }

            bool JSONResponseParser::getFieldCardInputMethod(const Json::Value &object, IResponseData &responseData) {
                int cardInputMethod;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardInputMethod(),
                                                           cardInputMethod);
                bool result = exists && responseData.setCardInputMethod(static_cast<CardInputMethod>(cardInputMethod));

                return result;
            }

            bool JSONResponseParser::getFieldIssuerName(const Json::Value &object, IResponseData &responseData) {
                std::string issuerName;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getIssuerName(), issuerName);
                bool result = exists && responseData.setIssuerName(issuerName);

                return result;
            }

            bool JSONResponseParser::getFieldAdditionalInfo(const Json::Value &object, IResponseData &responseData) {
                std::string additionalInfo;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getAdditionalInfo(),
                                                           additionalInfo);
                bool result = exists && responseData.setAdditionalInfo(additionalInfo);

                return result;
            }

            bool JSONResponseParser::getFieldCardData(const Json::Value &object, IResponseData &responseData) {
                std::string cardData;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardData(), cardData);
                bool result = exists && responseData.setCardData(cardData);

                return result;
            }

            bool JSONResponseParser::getFieldCardDataEnc(const Json::Value &object, IResponseData &responseData) {
                std::string cardDataEnc;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardDataEnc(), cardDataEnc);
                bool result = exists && responseData.setCardDataEnc(cardDataEnc);

                return result;
            }

            bool JSONResponseParser::getFieldMerchantID(const Json::Value &object, IResponseData &responseData) {
                std::string merchantId;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getMerchantID(), merchantId);
                bool result = exists && responseData.setMerchantID(merchantId);

                return result;
            }

            bool JSONResponseParser::getFieldTVR(const Json::Value &object, IResponseData &responseData) {
                std::string TVR;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTVR(), TVR);
                bool result = exists && responseData.setTVR(TVR);

                return result;
            }

            bool JSONResponseParser::getFieldTSI(const Json::Value &object, IResponseData &responseData) {
                std::string TSI;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTSI(), TSI);
                bool result = exists && responseData.setTSI(TSI);

                return result;
            }

            bool JSONResponseParser::getFieldTC(const Json::Value &object, IResponseData &responseData) {
                std::string TC;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTC(), TC);
                bool result = exists && responseData.setTC(TC);

                return result;
            }

            bool JSONResponseParser::getFieldCID(const Json::Value &object, IResponseData &responseData) {
                std::string CID;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCID(), CID);
                bool result = exists && responseData.setCID(CID);

                return result;
            }

            bool JSONResponseParser::getFieldKVR(const Json::Value &object, IResponseData &responseData) {
                std::string KVR;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getKVR(), KVR);
                bool result = exists && responseData.setKVR(KVR);

                return result;
            }

            bool JSONResponseParser::getFieldCDAResult(const Json::Value &object, IResponseData &responseData) {
                std::string CDAResult;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCDAResult(), CDAResult);
                bool result = exists && responseData.setCDAResult(CDAResult);

                return result;
            }

            bool JSONResponseParser::getFieldSalesAmount(const Json::Value &object, IResponseData &responseData) {
                int64_t salesAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSalesAmount(), salesAmount);
                bool result = exists && responseData.setSalesAmount(salesAmount);

                return result;
            }

            bool JSONResponseParser::getFieldSalesCount(const Json::Value &object, IResponseData &responseData) {
                int salesCount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSaleCount(), salesCount);
                bool result = exists && responseData.setSalesCount(salesCount);

                return result;
            }

            bool JSONResponseParser::getFieldVoidAmount(const Json::Value &object, IResponseData &responseData) {
                int64_t voidAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getVoidAmount(), voidAmount);
                bool result = exists && responseData.setVoidAmount(voidAmount);

                return result;
            }

            bool JSONResponseParser::getFieldVoidCount(const Json::Value &object, IResponseData &responseData) {
                int voidCount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getVoidCount(), voidCount);
                bool result = exists && responseData.setVoidCount(voidCount);

                return result;
            }

            bool JSONResponseParser::getFieldRefundAmount(const Json::Value &object, IResponseData &responseData) {
                int64_t refundAmount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getRefundAmount(), refundAmount);
                bool result = exists && responseData.setRefundAmount(refundAmount);

                return result;
            }

            bool JSONResponseParser::getFieldRefundCount(const Json::Value &object, IResponseData &responseData) {
                int refundCount;

                bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getRefundCount(), refundCount);
                bool result = exists && responseData.setRefundCount(refundCount);

                return result;
            }

            bool JSONResponseParser::getFieldSaleArray(const Json::Value &object, IResponseData &responseData) {
                bool result = false;

                Json::Value salesArray;

                std::vector<std::shared_ptr<IResponseData> > sales;
                if (JSONGetFieldHelper::getField(object, JSONResponseFields::getSaleArray(), salesArray)) {
                    if (salesArray.isArray()) {
                        for (auto &i : salesArray) {
                            auto sale = ResponseDataFactory::getResponseData(OperationCode::ArrayElement);
                            if (sale && getFields(i, *sale)) {
                                sale->resetOperationCode();
                                sales.push_back(sale);
                            }
                        } //for

                        result = salesArray.size() == sales.size();
                        if (result) {
                            responseData.setSalesArray(sales);
                        }
                    }
                }
                return result;
            }

            bool JSONResponseParser::getFieldVoidArray(const Json::Value &object, IResponseData &responseData) {
                bool result = false;

                Json::Value voidArray;

                std::vector<std::shared_ptr<IResponseData> > voids;
                if (JSONGetFieldHelper::getField(object, JSONResponseFields::getVoidArray(), voidArray)) {
                    if (voidArray.isArray()) {
                        for (auto &i : voidArray) {
                            auto sale = ResponseDataFactory::getResponseData(OperationCode::ArrayElement);
                            if (sale && getFields(i, *sale)) {
                                sale->resetOperationCode();
                                voids.push_back(sale);
                            }
                        } //for

                        result = voidArray.size() == voids.size();
                        if (result) {
                            responseData.setVoidArray(voids);
                        }
                    }
                }
                return result;
            }

            bool JSONResponseParser::getFieldRefundArray(const Json::Value &object, IResponseData &responseData) {
                bool result = false;

                Json::Value refundArray;

                std::vector<std::shared_ptr<IResponseData> > refunds;
                if (JSONGetFieldHelper::getField(object, JSONResponseFields::getRefundArray(), refundArray)) {
                    if (refundArray.isArray()) {
                        for (auto &i : refundArray) {
                            auto sale = ResponseDataFactory::getResponseData(OperationCode::ArrayElement);
                            if (sale && getFields(i, *sale)) {
                                sale->resetOperationCode();
                                refunds.push_back(sale);
                            }
                        } //for

                        result = refundArray.size() == refunds.size();
                        if (result) {
                            responseData.setRefundArray(refunds);
                        }
                    }
                }
                return result;
            }

            void JSONResponseParser::initFunctionsMap() {
                m_ExtractFunctions[ResponseField::EcrNumber] = std::bind(&JSONResponseParser::getFieldEcrNumber, this,
                                                                         _1, _2);
                m_ExtractFunctions[ResponseField::EcrMerchantNumber] = std::bind(
                        &JSONResponseParser::getFieldEcrMerchantNumber, this, _1, _2);
                m_ExtractFunctions[ResponseField::OperationCode] = std::bind(&JSONResponseParser::getFieldOperationCode,
                                                                             this, _1, _2);
                m_ExtractFunctions[ResponseField::OriginalOperationCode] = std::bind(
                        &JSONResponseParser::getFieldOriginalOperationCode, this, _1, _2);
                m_ExtractFunctions[ResponseField::TotalAmount] = std::bind(&JSONResponseParser::getFieldTotalAmount,
                                                                           this, _1, _2);
                m_ExtractFunctions[ResponseField::PartialAmount] = std::bind(&JSONResponseParser::getFieldPartialAmount,
                                                                             this, _1, _2);
                m_ExtractFunctions[ResponseField::AcquirerFeeAmount] = std::bind(
                        &JSONResponseParser::getFieldAcquirerFeeAmount, this, _1, _2);
                m_ExtractFunctions[ResponseField::TerminalFeeAmount] = std::bind(
                        &JSONResponseParser::getFieldTerminalFeeAmount, this, _1, _2);
                m_ExtractFunctions[ResponseField::TipsAmount] = std::bind(&JSONResponseParser::getFieldTipsAmount, this,
                                                                          _1, _2);
                m_ExtractFunctions[ResponseField::CurrencyCode] = std::bind(&JSONResponseParser::getFieldCurrencyCode,
                                                                            this, _1, _2);
                m_ExtractFunctions[ResponseField::ReceiptReference] = std::bind(
                        &JSONResponseParser::getFieldReceiptReference, this, _1, _2);
                m_ExtractFunctions[ResponseField::RRN] = std::bind(&JSONResponseParser::getFieldRRN, this, _1, _2);
                m_ExtractFunctions[ResponseField::Status] = std::bind(&JSONResponseParser::getFieldStatus, this, _1,
                                                                      _2);
                m_ExtractFunctions[ResponseField::OriginalOperationStatus] = std::bind(
                        &JSONResponseParser::getFieldOriginalOperationStatus, this, _1, _2);
                m_ExtractFunctions[ResponseField::TransDateTime] = std::bind(&JSONResponseParser::getFieldTransDateTime,
                                                                             this, _1, _2);
                m_ExtractFunctions[ResponseField::TerminalDateTime] = std::bind(
                        &JSONResponseParser::getFieldTerminalDateTime, this, _1, _2);
                m_ExtractFunctions[ResponseField::CardPAN] = std::bind(&JSONResponseParser::getFieldCardPAN, this, _1,
                                                                       _2);
                m_ExtractFunctions[ResponseField::ExpireDate] = std::bind(&JSONResponseParser::getFieldExpireDate, this,
                                                                          _1, _2);
                m_ExtractFunctions[ResponseField::CardholderName] = std::bind(
                        &JSONResponseParser::getFieldCardholderName, this, _1, _2);
                m_ExtractFunctions[ResponseField::CardholderAuthMethod] = std::bind(
                        &JSONResponseParser::getFieldCardholderAuthMethod, this, _1, _2);
                m_ExtractFunctions[ResponseField::AuthCode] = std::bind(&JSONResponseParser::getFieldAuthCode, this, _1,
                                                                        _2);
                m_ExtractFunctions[ResponseField::ResponseCode] = std::bind(&JSONResponseParser::getFieldResponseCode,
                                                                            this, _1, _2);
                m_ExtractFunctions[ResponseField::ResponseText] = std::bind(&JSONResponseParser::getFieldResponseText,
                                                                            this, _1, _2);
                m_ExtractFunctions[ResponseField::STAN] = std::bind(&JSONResponseParser::getFieldSTAN, this, _1, _2);
                m_ExtractFunctions[ResponseField::TransactionID] = std::bind(&JSONResponseParser::getFieldTransactionID,
                                                                             this, _1, _2);
                m_ExtractFunctions[ResponseField::TerminalID] = std::bind(&JSONResponseParser::getFieldTerminalID, this,
                                                                          _1, _2);
                m_ExtractFunctions[ResponseField::CardEmvAid] = std::bind(&JSONResponseParser::getFieldCardEmvAid, this,
                                                                          _1, _2);
                m_ExtractFunctions[ResponseField::CardAppName] = std::bind(&JSONResponseParser::getFieldCardAppName,
                                                                           this, _1, _2);
                m_ExtractFunctions[ResponseField::CardInputMethod] = std::bind(
                        &JSONResponseParser::getFieldCardInputMethod, this, _1, _2);
                m_ExtractFunctions[ResponseField::IssuerName] = std::bind(&JSONResponseParser::getFieldIssuerName, this,
                                                                          _1, _2);
                m_ExtractFunctions[ResponseField::AdditionalInfo] = std::bind(
                        &JSONResponseParser::getFieldAdditionalInfo, this, _1, _2);
                m_ExtractFunctions[ResponseField::CardData] = std::bind(&JSONResponseParser::getFieldCardData, this, _1,
                                                                        _2);
                m_ExtractFunctions[ResponseField::CardDataEnc] = std::bind(&JSONResponseParser::getFieldCardDataEnc,
                                                                           this, _1, _2);
                m_ExtractFunctions[ResponseField::MerchantID] = std::bind(&JSONResponseParser::getFieldMerchantID, this,
                                                                          _1, _2);
                m_ExtractFunctions[ResponseField::TVR] = std::bind(&JSONResponseParser::getFieldTVR, this, _1, _2);
                m_ExtractFunctions[ResponseField::TSI] = std::bind(&JSONResponseParser::getFieldTSI, this, _1, _2);
                m_ExtractFunctions[ResponseField::TC] = std::bind(&JSONResponseParser::getFieldTC, this, _1, _2);
                m_ExtractFunctions[ResponseField::CID] = std::bind(&JSONResponseParser::getFieldCID, this, _1, _2);
                m_ExtractFunctions[ResponseField::KVR] = std::bind(&JSONResponseParser::getFieldKVR, this, _1, _2);
                m_ExtractFunctions[ResponseField::CDAResult] = std::bind(&JSONResponseParser::getFieldCDAResult, this,
                                                                         _1, _2);
                m_ExtractFunctions[ResponseField::SalesAmount] = std::bind(&JSONResponseParser::getFieldSalesAmount, this,
                                                                         _1, _2);
                m_ExtractFunctions[ResponseField::SaleCount] = std::bind(&JSONResponseParser::getFieldSalesCount, this,
                                                                         _1, _2);
                m_ExtractFunctions[ResponseField::VoidAmount] = std::bind(&JSONResponseParser::getFieldVoidAmount, this,
                                                                           _1, _2);
                m_ExtractFunctions[ResponseField::VoidCount] = std::bind(&JSONResponseParser::getFieldVoidCount, this,
                                                                         _1, _2);
                m_ExtractFunctions[ResponseField::RefundAmount] = std::bind(&JSONResponseParser::getFieldRefundAmount, this,
                                                                           _1, _2);
                m_ExtractFunctions[ResponseField::RefundCount] = std::bind(&JSONResponseParser::getFieldRefundCount,
                                                                           this, _1, _2);
                m_ExtractFunctions[ResponseField::SaleArray] = std::bind(&JSONResponseParser::getFieldSaleArray, this,
                                                                         _1, _2);
                m_ExtractFunctions[ResponseField::VoidArray] = std::bind(&JSONResponseParser::getFieldVoidArray, this,
                                                                         _1, _2);
                m_ExtractFunctions[ResponseField::RefundArray] = std::bind(&JSONResponseParser::getFieldRefundArray,
                                                                           this, _1, _2);
            }

            bool JSONResponseParser::getFields(const Json::Value &object, IResponseData &responseData) {
                if (responseData.isFieldSet(ResponseField::OperationCode) ||
                    getFieldOperationCode(object, responseData)) {
                    for (auto field : responseData.getMandatoryFields()) {
                        auto function = m_ExtractFunctions.at(field);
                        function(object, responseData);
                    }

                    for (auto field : responseData.getOptionalFields()) {
                        auto function = m_ExtractFunctions.at(field);
                        function(object, responseData);
                    }
                }
                return responseData.validateMandatoryFields();
            }
        }
    }
}