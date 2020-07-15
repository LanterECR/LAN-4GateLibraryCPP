//
// Created by Владимир Лысенков on 12.07.2020.
//

#include "JSONResponseBuilder.h"

#include "JSONAddFieldHelper.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"
namespace Lanter {
    namespace MessageProcessor {
        using namespace std::placeholders;

        JSONResponseBuilder::JSONResponseBuilder() {
            initFunctionsMap();
        }

        bool JSONResponseBuilder::createObject(const IResponseData &responseData, Json::Value &object) {
            bool result = false;
            try {
                result = addFields(responseData, object);
            } catch (std::exception &) { }
            return result;
        }

        const std::map<ResponseFields, std::function<bool(const IResponseData &, Json::Value &)>> &
        JSONResponseBuilder::getFunctions() const {
            return m_InsertFunctions;
        }

        bool JSONResponseBuilder::addFieldEcrNumber(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::EcrNumber)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getEcrNumber(), responseData.getEcrNumber());
            }
            return fieldExists(object, JSONResponseFields::getEcrNumber());
        }
        bool JSONResponseBuilder::addFieldEcrMerchantNumber(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::EcrMerchantNumber)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getEcrMerchantNumber(), responseData.getEcrMerchantNumber());
            }
            return fieldExists(object, JSONResponseFields::getEcrMerchantNumber());
        }
        bool JSONResponseBuilder::addFieldOperationCode(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::OperationCode)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), static_cast<int>(responseData.getOperationCode()));
            }
            return fieldExists(object, JSONResponseFields::getOperationCode());
        }
        bool JSONResponseBuilder::addFieldOriginalOperationCode(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::OriginalOperationCode)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(), static_cast<int>(responseData.getOriginalOperationCode()));
            }
            return fieldExists(object, JSONResponseFields::getOriginalOperationCode());
        }
        bool JSONResponseBuilder::addFieldTotalAmount(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::TotalAmount)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getTotalAmount(), responseData.getTotalAmount());
            }
            return fieldExists(object, JSONResponseFields::getTotalAmount());
        }
        bool JSONResponseBuilder::addFieldPartialAmount(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::PartialAmount)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getPartialAmount(), responseData.getPartialAmount());
            }
            return fieldExists(object, JSONResponseFields::getPartialAmount());
        }
        bool JSONResponseBuilder::addFieldAcquirerFeeAmount(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::AcquirerFeeAmount)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getAcquirerFeeAmount(), responseData.getAcquirerFeeAmount());
            }
            return fieldExists(object, JSONResponseFields::getAcquirerFeeAmount());
        }
        bool JSONResponseBuilder::addFieldTerminalFeeAmount(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::TerminalFeeAmount)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getTerminalFeeAmount(), responseData.getTerminalFeeAmount());
            }
            return fieldExists(object, JSONResponseFields::getTerminalFeeAmount());
        }
        bool JSONResponseBuilder::addFieldTipsAmount(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::TipsAmount)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getTipsAmount(), responseData.getTipsAmount());
            }
            return fieldExists(object, JSONResponseFields::getTipsAmount());
        }
        bool JSONResponseBuilder::addFieldCurrencyCode(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CurrencyCode)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(), responseData.getCurrencyCode());
            }
            return fieldExists(object, JSONResponseFields::getCurrencyCode());
        }
        bool JSONResponseBuilder::addFieldReceiptReference(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::ReceiptReference)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getReceiptReference(), responseData.getReceiptReference());
            }
            return fieldExists(object, JSONResponseFields::getReceiptReference());
        }
        bool JSONResponseBuilder::addFieldRRN(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::RRN)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getRRN(), responseData.getRRN());
            }
            return fieldExists(object, JSONResponseFields::getRRN());
        }
        bool JSONResponseBuilder::addFieldStatus(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::Status)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getStatus(), static_cast<int>(responseData.getStatus()));
            }
            return fieldExists(object, JSONResponseFields::getStatus());
        }
        bool JSONResponseBuilder::addFieldOriginalOperationStatus(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::OriginalOperationStatus)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationStatus(), static_cast<int>(responseData.getOriginalOperationStatus()));
            }
            return fieldExists(object, JSONResponseFields::getOriginalOperationStatus());
        }
        bool JSONResponseBuilder::addFieldTransDateTime(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::TransDateTime)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getTransDateTime(), responseData.getTransDateTime());
            }
            return fieldExists(object, JSONResponseFields::getTransDateTime());
        }
        bool JSONResponseBuilder::addFieldTerminalDateTime(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::TerminalDateTime)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getTerminalDateTime(), responseData.getTerminalDateTime());
            }
            return fieldExists(object, JSONResponseFields::getTerminalDateTime());
        }
        bool JSONResponseBuilder::addFieldCardPAN(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CardPAN)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCardPAN(), responseData.getCardPAN());
            }
            return fieldExists(object, JSONResponseFields::getCardPAN());
        }
        bool JSONResponseBuilder::addFieldExpireDate(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::ExpireDate)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getExpireDate(), responseData.getExpireDate());
            }
            return fieldExists(object, JSONResponseFields::getExpireDate());
        }
        bool JSONResponseBuilder::addFieldCardholderName(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CardholderName)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCardholderName(), responseData.getCardholderName());
            }
            return fieldExists(object, JSONResponseFields::getCardholderName());
        }
        bool JSONResponseBuilder::addFieldCardholderAuthMethod(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CardholderAuthMethod)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCardholderAuthMethod(), static_cast<int>(responseData.getCardholderAuthMethod()));
            }
            return fieldExists(object, JSONResponseFields::getCardholderAuthMethod());
        }
        bool JSONResponseBuilder::addFieldAuthCode(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::AuthCode)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getAuthCode(), responseData.getAuthCode());
            }
            return fieldExists(object, JSONResponseFields::getAuthCode());
        }
        bool JSONResponseBuilder::addFieldResponseCode(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::ResponseCode)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getResponseCode(), responseData.getResponseCode());
            }
            return fieldExists(object, JSONResponseFields::getResponseCode());
        }
        bool JSONResponseBuilder::addFieldResponseText(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::ResponseText)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getResponseText(), responseData.getResponseText());
            }
            return fieldExists(object, JSONResponseFields::getResponseText());
        }
        bool JSONResponseBuilder::addFieldSTAN(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::STAN)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getSTAN(), responseData.getSTAN());
            }
            return fieldExists(object, JSONResponseFields::getSTAN());
        }
        bool JSONResponseBuilder::addFieldTransactionID(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::TransactionID)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getTransactionID(), responseData.getTransactionID());
            }
            return fieldExists(object, JSONResponseFields::getTransactionID());
        }
        bool JSONResponseBuilder::addFieldTerminalID(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::TerminalID)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getTerminalID(), responseData.getTerminalID());
            }
            return fieldExists(object, JSONResponseFields::getTerminalID());
        }
        bool JSONResponseBuilder::addFieldCardEmvAid(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CardEmvAid)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCardEmvAid(), responseData.getCardEmvAid());
            }
            return fieldExists(object, JSONResponseFields::getCardEmvAid());
        }
        bool JSONResponseBuilder::addFieldCardAppName(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CardAppName)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCardAppName(), responseData.getCardAppName());
            }
            return fieldExists(object, JSONResponseFields::getCardAppName());
        }
        bool JSONResponseBuilder::addFieldCardInputMethod(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CardInputMethod)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(), static_cast<int>(responseData.getCardInputMethod()));
            }
            return fieldExists(object, JSONResponseFields::getCardInputMethod());
        }
        bool JSONResponseBuilder::addFieldIssuerName(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::IssuerName)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getIssuerName(), responseData.getIssuerName());
            }
            return fieldExists(object, JSONResponseFields::getIssuerName());
        }
        bool JSONResponseBuilder::addFieldAdditionalInfo(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::AdditionalInfo)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getAdditionalInfo(), responseData.getAdditionalInfo());
            }
            return fieldExists(object, JSONResponseFields::getAdditionalInfo());
        }
        bool JSONResponseBuilder::addFieldCardData(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CardData)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCardData(), responseData.getCardData());
            }
            return fieldExists(object, JSONResponseFields::getCardData());
        }
        bool JSONResponseBuilder::addFieldCardDataEnc(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CardDataEnc)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCardDataEnc(), responseData.getCardDataEnc());
            }
            return fieldExists(object, JSONResponseFields::getCardDataEnc());
        }
        bool JSONResponseBuilder::addFieldMerchantID(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::MerchantID)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getMerchantID(), responseData.getMerchantID());
            }
            return fieldExists(object, JSONResponseFields::getMerchantID());
        }
        bool JSONResponseBuilder::addFieldTVR(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::TVR)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getTVR(), responseData.getTVR());
            }
            return fieldExists(object, JSONResponseFields::getTVR());
        }
        bool JSONResponseBuilder::addFieldTSI(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::TSI)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getTSI(), responseData.getTSI());
            }
            return fieldExists(object, JSONResponseFields::getTSI());
        }
        bool JSONResponseBuilder::addFieldTC(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::TC)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getTC(), responseData.getTC());
            }
            return fieldExists(object, JSONResponseFields::getTC());
        }
        bool JSONResponseBuilder::addFieldCID(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CID)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCID(), responseData.getCID());
            }
            return fieldExists(object, JSONResponseFields::getCID());
        }
        bool JSONResponseBuilder::addFieldKVR(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::KVR)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getKVR(), responseData.getKVR());
            }
            return fieldExists(object, JSONResponseFields::getKVR());
        }
        bool JSONResponseBuilder::addFieldCDAResult(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::CDAResult)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getCDAResult(), responseData.getCDAResult());
            }
            return fieldExists(object, JSONResponseFields::getCDAResult());
        }
        bool JSONResponseBuilder::addFieldSalesCount(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::SalesCount)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getSalesCount(), responseData.getSalesCount());
            }
            return fieldExists(object, JSONResponseFields::getSalesCount());
        }
        bool JSONResponseBuilder::addFieldVoidCount(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::VoidCount)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getVoidCount(), responseData.getVoidCount());
            }
            return fieldExists(object, JSONResponseFields::getVoidCount());
        }
        bool JSONResponseBuilder::addFieldRefundCount(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::RefundCount)) {
                AddFieldsHelper::addField(object, JSONResponseFields::getRefundCount(), responseData.getRefundCount());
            }
            return fieldExists(object, JSONResponseFields::getRefundCount());
        }
        bool JSONResponseBuilder::addFieldSalesArray(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::SalesArray)) {
                Json::Value array;
                for(const auto& arrayResponseData : responseData.getSalesArray()) {
                    Json::Value arrayElement;
                    if(!createObject(*arrayResponseData, arrayElement)) {
                        return false;
                    }
                    AddFieldsHelper::addArrayElement(array, arrayElement);
                } //for
                AddFieldsHelper::addField(object, JSONResponseFields::getSalesArray(), array);
            }
            return fieldExists(object, JSONResponseFields::getSalesArray());
        }
        bool JSONResponseBuilder::addFieldVoidArray(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::VoidArray)) {
                Json::Value array;
                for(const auto& arrayResponseData : responseData.getVoidArray()) {
                    Json::Value arrayElement;
                    if(!createObject(*arrayResponseData, arrayElement)) {
                        return false;
                    }
                    AddFieldsHelper::addArrayElement(array, arrayElement);
                } //for
                AddFieldsHelper::addField(object, JSONResponseFields::getVoidArray(), array);
            }
            return fieldExists(object, JSONResponseFields::getVoidArray());
        }
        bool JSONResponseBuilder::addFieldRefundArray(const IResponseData &responseData, Json::Value &object) {
            if(responseData.isFieldSet(ResponseFields::RefundArray)) {
                Json::Value array;
                for(const auto& arrayResponseData : responseData.getRefundArray()) {
                    Json::Value arrayElement;
                    if(!createObject(*arrayResponseData, arrayElement)) {
                        return false;
                    }
                    AddFieldsHelper::addArrayElement(array, arrayElement);
                } //for
                AddFieldsHelper::addField(object, JSONResponseFields::getRefundArray(), array);
            }
            return fieldExists(object, JSONResponseFields::getRefundArray());
        }

        bool JSONResponseBuilder::addFields(const IResponseData &responseData, Json::Value &object) {
            bool result = false;

            if(responseData.validateMandatoryFields()) {
                result = true;

                for(auto field : responseData.getMandatoryFields()) {
                    if(responseData.getFieldsSet().find(field) != responseData.getFieldsSet().end()) {
                        auto function = m_InsertFunctions.at(field);
                        result = result && function(responseData, object);
                    }
                }

                for(auto field : responseData.getOptionalFields()) {
                    if(responseData.getFieldsSet().find(field) != responseData.getFieldsSet().end()) {
                        auto function = m_InsertFunctions.at(field);
                        function(responseData, object);
                    }
                }
            }
            return result;
        }

        void JSONResponseBuilder::initFunctionsMap() {
            m_InsertFunctions[ResponseFields::EcrNumber] = std::bind(&JSONResponseBuilder::addFieldEcrNumber,this,  _1, _2);
            m_InsertFunctions[ResponseFields::EcrMerchantNumber] = std::bind(&JSONResponseBuilder::addFieldEcrMerchantNumber,this,  _1, _2);
            m_InsertFunctions[ResponseFields::OperationCode] = std::bind(&JSONResponseBuilder::addFieldOperationCode,this,  _1, _2);
            m_InsertFunctions[ResponseFields::OriginalOperationCode] = std::bind(&JSONResponseBuilder::addFieldOriginalOperationCode,this,  _1, _2);
            m_InsertFunctions[ResponseFields::TotalAmount] = std::bind(&JSONResponseBuilder::addFieldTotalAmount,this,  _1, _2);
            m_InsertFunctions[ResponseFields::PartialAmount] = std::bind(&JSONResponseBuilder::addFieldPartialAmount,this,  _1, _2);
            m_InsertFunctions[ResponseFields::AcquirerFeeAmount] = std::bind(&JSONResponseBuilder::addFieldAcquirerFeeAmount,this,  _1, _2);
            m_InsertFunctions[ResponseFields::TerminalFeeAmount] = std::bind(&JSONResponseBuilder::addFieldTerminalFeeAmount,this,  _1, _2);
            m_InsertFunctions[ResponseFields::TipsAmount] = std::bind(&JSONResponseBuilder::addFieldTipsAmount,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CurrencyCode] = std::bind(&JSONResponseBuilder::addFieldCurrencyCode,this,  _1, _2);
            m_InsertFunctions[ResponseFields::ReceiptReference] = std::bind(&JSONResponseBuilder::addFieldReceiptReference,this,  _1, _2);
            m_InsertFunctions[ResponseFields::RRN] = std::bind(&JSONResponseBuilder::addFieldRRN,this,  _1, _2);
            m_InsertFunctions[ResponseFields::Status] = std::bind(&JSONResponseBuilder::addFieldStatus,this,  _1, _2);
            m_InsertFunctions[ResponseFields::OriginalOperationStatus] = std::bind(&JSONResponseBuilder::addFieldOriginalOperationStatus,this,  _1, _2);
            m_InsertFunctions[ResponseFields::TransDateTime] = std::bind(&JSONResponseBuilder::addFieldTransDateTime,this,  _1, _2);
            m_InsertFunctions[ResponseFields::TerminalDateTime] = std::bind(&JSONResponseBuilder::addFieldTerminalDateTime,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CardPAN] = std::bind(&JSONResponseBuilder::addFieldCardPAN,this,  _1, _2);
            m_InsertFunctions[ResponseFields::ExpireDate] = std::bind(&JSONResponseBuilder::addFieldExpireDate,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CardholderName] = std::bind(&JSONResponseBuilder::addFieldCardholderName,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CardholderAuthMethod] = std::bind(&JSONResponseBuilder::addFieldCardholderAuthMethod,this,  _1, _2);
            m_InsertFunctions[ResponseFields::AuthCode] = std::bind(&JSONResponseBuilder::addFieldAuthCode,this,  _1, _2);
            m_InsertFunctions[ResponseFields::ResponseCode] = std::bind(&JSONResponseBuilder::addFieldResponseCode,this,  _1, _2);
            m_InsertFunctions[ResponseFields::ResponseText] = std::bind(&JSONResponseBuilder::addFieldResponseText,this,  _1, _2);
            m_InsertFunctions[ResponseFields::STAN] = std::bind(&JSONResponseBuilder::addFieldSTAN,this,  _1, _2);
            m_InsertFunctions[ResponseFields::TransactionID] = std::bind(&JSONResponseBuilder::addFieldTransactionID,this,  _1, _2);
            m_InsertFunctions[ResponseFields::TerminalID] = std::bind(&JSONResponseBuilder::addFieldTerminalID,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CardEmvAid] = std::bind(&JSONResponseBuilder::addFieldCardEmvAid,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CardAppName] = std::bind(&JSONResponseBuilder::addFieldCardAppName,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CardInputMethod] = std::bind(&JSONResponseBuilder::addFieldCardInputMethod,this,  _1, _2);
            m_InsertFunctions[ResponseFields::IssuerName] = std::bind(&JSONResponseBuilder::addFieldIssuerName,this,  _1, _2);
            m_InsertFunctions[ResponseFields::AdditionalInfo] = std::bind(&JSONResponseBuilder::addFieldAdditionalInfo,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CardData] = std::bind(&JSONResponseBuilder::addFieldCardData,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CardDataEnc] = std::bind(&JSONResponseBuilder::addFieldCardDataEnc,this,  _1, _2);
            m_InsertFunctions[ResponseFields::MerchantID] = std::bind(&JSONResponseBuilder::addFieldMerchantID,this,  _1, _2);
            m_InsertFunctions[ResponseFields::TVR] = std::bind(&JSONResponseBuilder::addFieldTVR,this,  _1, _2);
            m_InsertFunctions[ResponseFields::TSI] = std::bind(&JSONResponseBuilder::addFieldTSI,this,  _1, _2);
            m_InsertFunctions[ResponseFields::TC] = std::bind(&JSONResponseBuilder::addFieldTC,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CID] = std::bind(&JSONResponseBuilder::addFieldCID,this,  _1, _2);
            m_InsertFunctions[ResponseFields::KVR] = std::bind(&JSONResponseBuilder::addFieldKVR,this,  _1, _2);
            m_InsertFunctions[ResponseFields::CDAResult] = std::bind(&JSONResponseBuilder::addFieldCDAResult,this,  _1, _2);
            m_InsertFunctions[ResponseFields::SalesCount] = std::bind(&JSONResponseBuilder::addFieldSalesCount,this,  _1, _2);
            m_InsertFunctions[ResponseFields::VoidCount] = std::bind(&JSONResponseBuilder::addFieldVoidCount,this,  _1, _2);
            m_InsertFunctions[ResponseFields::RefundCount] = std::bind(&JSONResponseBuilder::addFieldRefundCount,this,  _1, _2);
            m_InsertFunctions[ResponseFields::SalesArray] = std::bind(&JSONResponseBuilder::addFieldSalesArray,this,  _1, _2);
            m_InsertFunctions[ResponseFields::VoidArray] = std::bind(&JSONResponseBuilder::addFieldVoidArray,this,  _1, _2);
            m_InsertFunctions[ResponseFields::RefundArray] = std::bind(&JSONResponseBuilder::addFieldRefundArray,this,  _1, _2);
        }
    }
}