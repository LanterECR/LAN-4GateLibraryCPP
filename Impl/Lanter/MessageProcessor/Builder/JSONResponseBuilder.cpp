#include "JSONResponseBuilder.h"

#include "JSONAddFieldHelper.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"
namespace Lanter {
    namespace MessageProcessor {
        namespace Builder {
            using namespace std::placeholders;

            JSONResponseBuilder::JSONResponseBuilder() {
                initFunctionsMap();
            }

            bool JSONResponseBuilder::createObject(const IResponseData &responseData, Json::Value &object) {
                bool result = false;
                try {
                    result = addFields(responseData, object);
                } catch (std::exception &) {}
                return result;
            }

            const std::map<ResponseField, std::function<bool(const IResponseData &, Json::Value &)>> &
            JSONResponseBuilder::getFunctions() const {
                return m_InsertFunctions;
            }

            bool JSONResponseBuilder::addFieldEcrNumber(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::EcrNumber)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getEcrNumber(), responseData.getEcrNumber());
                }
                return fieldExists(object, JSONResponseFields::getEcrNumber());
            }

            bool
            JSONResponseBuilder::addFieldEcrMerchantNumber(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::EcrMerchantNumber)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getEcrMerchantNumber(),
                                              responseData.getEcrMerchantNumber());
                }
                return fieldExists(object, JSONResponseFields::getEcrMerchantNumber());
            }

            bool JSONResponseBuilder::addFieldOperationCode(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::OperationCode)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(),
                                              static_cast<int>(responseData.getOperationCode()));
                }
                return fieldExists(object, JSONResponseFields::getOperationCode());
            }

            bool
            JSONResponseBuilder::addFieldOriginalOperationCode(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::OriginalOperationCode)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(),
                                              static_cast<int>(responseData.getOriginalOperationCode()));
                }
                return fieldExists(object, JSONResponseFields::getOriginalOperationCode());
            }

            bool JSONResponseBuilder::addFieldTotalAmount(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::TotalAmount)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTotalAmount(),
                                              responseData.getTotalAmount());
                }
                return fieldExists(object, JSONResponseFields::getTotalAmount());
            }

            bool JSONResponseBuilder::addFieldPartialAmount(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::PartialAmount)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getPartialAmount(),
                                              responseData.getPartialAmount());
                }
                return fieldExists(object, JSONResponseFields::getPartialAmount());
            }

            bool
            JSONResponseBuilder::addFieldAcquirerFeeAmount(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::AcquirerFeeAmount)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getAcquirerFeeAmount(),
                                              responseData.getAcquirerFeeAmount());
                }
                return fieldExists(object, JSONResponseFields::getAcquirerFeeAmount());
            }

            bool
            JSONResponseBuilder::addFieldTerminalFeeAmount(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::TerminalFeeAmount)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalFeeAmount(),
                                              responseData.getTerminalFeeAmount());
                }
                return fieldExists(object, JSONResponseFields::getTerminalFeeAmount());
            }

            bool JSONResponseBuilder::addFieldTipsAmount(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::TipsAmount)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTipsAmount(),
                                              responseData.getTipsAmount());
                }
                return fieldExists(object, JSONResponseFields::getTipsAmount());
            }

            bool JSONResponseBuilder::addFieldCurrencyCode(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CurrencyCode)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(),
                                              responseData.getCurrencyCode());
                }
                return fieldExists(object, JSONResponseFields::getCurrencyCode());
            }

            bool JSONResponseBuilder::addFieldReceiptReference(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::ReceiptReference)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptReference(),
                                              responseData.getReceiptReference());
                }
                return fieldExists(object, JSONResponseFields::getReceiptReference());
            }

            bool JSONResponseBuilder::addFieldRRN(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::RRN)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getRRN(), responseData.getRRN());
                }
                return fieldExists(object, JSONResponseFields::getRRN());
            }

            bool JSONResponseBuilder::addFieldStatus(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::Status)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getStatus(),
                                              static_cast<int>(responseData.getStatus()));
                }
                return fieldExists(object, JSONResponseFields::getStatus());
            }

            bool JSONResponseBuilder::addFieldOriginalOperationStatus(const IResponseData &responseData,
                                                                      Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::OriginalOperationStatus)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationStatus(),
                                              static_cast<int>(responseData.getOriginalOperationStatus()));
                }
                return fieldExists(object, JSONResponseFields::getOriginalOperationStatus());
            }

            bool JSONResponseBuilder::addFieldTransDateTime(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::TransDateTime)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTransDateTime(),
                                              responseData.getTransDateTime());
                }
                return fieldExists(object, JSONResponseFields::getTransDateTime());
            }

            bool JSONResponseBuilder::addFieldTerminalDateTime(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::TerminalDateTime)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalDateTime(),
                                              responseData.getTerminalDateTime());
                }
                return fieldExists(object, JSONResponseFields::getTerminalDateTime());
            }

            bool JSONResponseBuilder::addFieldCardPAN(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CardPAN)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCardPAN(), responseData.getCardPAN());
                }
                return fieldExists(object, JSONResponseFields::getCardPAN());
            }

            bool JSONResponseBuilder::addFieldExpireDate(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::ExpireDate)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getExpireDate(),
                                              responseData.getExpireDate());
                }
                return fieldExists(object, JSONResponseFields::getExpireDate());
            }

            bool JSONResponseBuilder::addFieldCardholderName(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CardholderName)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderName(),
                                              responseData.getCardholderName());
                }
                return fieldExists(object, JSONResponseFields::getCardholderName());
            }

            bool
            JSONResponseBuilder::addFieldCardholderAuthMethod(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CardholderAuthMethod)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCardholderAuthMethod(),
                                              static_cast<int>(responseData.getCardholderAuthMethod()));
                }
                return fieldExists(object, JSONResponseFields::getCardholderAuthMethod());
            }

            bool JSONResponseBuilder::addFieldAuthCode(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::AuthCode)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getAuthCode(), responseData.getAuthCode());
                }
                return fieldExists(object, JSONResponseFields::getAuthCode());
            }

            bool JSONResponseBuilder::addFieldResponseCode(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::ResponseCode)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getResponseCode(),
                                              responseData.getResponseCode());
                }
                return fieldExists(object, JSONResponseFields::getResponseCode());
            }

            bool JSONResponseBuilder::addFieldResponseText(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::ResponseText)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getResponseText(),
                                              responseData.getResponseText());
                }
                return fieldExists(object, JSONResponseFields::getResponseText());
            }

            bool JSONResponseBuilder::addFieldSTAN(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::STAN)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getSTAN(), responseData.getSTAN());
                }
                return fieldExists(object, JSONResponseFields::getSTAN());
            }

            bool JSONResponseBuilder::addFieldTransactionID(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::TransactionID)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTransactionID(),
                                              responseData.getTransactionID());
                }
                return fieldExists(object, JSONResponseFields::getTransactionID());
            }

            bool JSONResponseBuilder::addFieldTerminalID(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::TerminalID)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalID(),
                                              responseData.getTerminalID());
                }
                return fieldExists(object, JSONResponseFields::getTerminalID());
            }

            bool JSONResponseBuilder::addFieldCardEmvAid(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CardEmvAid)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCardEmvAid(),
                                              responseData.getCardEmvAid());
                }
                return fieldExists(object, JSONResponseFields::getCardEmvAid());
            }

            bool JSONResponseBuilder::addFieldCardAppName(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CardAppName)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCardAppName(),
                                              responseData.getCardAppName());
                }
                return fieldExists(object, JSONResponseFields::getCardAppName());
            }

            bool JSONResponseBuilder::addFieldCardInputMethod(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CardInputMethod)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCardInputMethod(),
                                              static_cast<int>(responseData.getCardInputMethod()));
                }
                return fieldExists(object, JSONResponseFields::getCardInputMethod());
            }

            bool JSONResponseBuilder::addFieldIssuerName(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::IssuerName)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getIssuerName(),
                                              responseData.getIssuerName());
                }
                return fieldExists(object, JSONResponseFields::getIssuerName());
            }

            bool JSONResponseBuilder::addFieldAdditionalInfo(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::AdditionalInfo)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getAdditionalInfo(),
                                              responseData.getAdditionalInfo());
                }
                return fieldExists(object, JSONResponseFields::getAdditionalInfo());
            }

            bool JSONResponseBuilder::addFieldCardData(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CardData)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCardData(), responseData.getCardData());
                }
                return fieldExists(object, JSONResponseFields::getCardData());
            }

            bool JSONResponseBuilder::addFieldCardDataEnc(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CardDataEnc)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCardDataEnc(),
                                              responseData.getCardDataEnc());
                }
                return fieldExists(object, JSONResponseFields::getCardDataEnc());
            }

            bool JSONResponseBuilder::addFieldMerchantID(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::MerchantID)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getMerchantID(),
                                              responseData.getMerchantID());
                }
                return fieldExists(object, JSONResponseFields::getMerchantID());
            }

            bool JSONResponseBuilder::addFieldTVR(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::TVR)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTVR(), responseData.getTVR());
                }
                return fieldExists(object, JSONResponseFields::getTVR());
            }

            bool JSONResponseBuilder::addFieldTSI(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::TSI)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTSI(), responseData.getTSI());
                }
                return fieldExists(object, JSONResponseFields::getTSI());
            }

            bool JSONResponseBuilder::addFieldTC(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::TC)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTC(), responseData.getTC());
                }
                return fieldExists(object, JSONResponseFields::getTC());
            }

            bool JSONResponseBuilder::addFieldCID(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CID)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCID(), responseData.getCID());
                }
                return fieldExists(object, JSONResponseFields::getCID());
            }

            bool JSONResponseBuilder::addFieldKVR(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::KVR)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getKVR(), responseData.getKVR());
                }
                return fieldExists(object, JSONResponseFields::getKVR());
            }

            bool JSONResponseBuilder::addFieldCDAResult(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CDAResult)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCDAResult(), responseData.getCDAResult());
                }
                return fieldExists(object, JSONResponseFields::getCDAResult());
            }

            bool JSONResponseBuilder::addFieldSalesCount(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::SaleCount)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getSaleCount(), responseData.getSaleCount());
                }
                return fieldExists(object, JSONResponseFields::getSaleCount());
            }

            bool JSONResponseBuilder::addFieldVoidCount(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::VoidCount)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getVoidCount(), responseData.getVoidCount());
                }
                return fieldExists(object, JSONResponseFields::getVoidCount());
            }

            bool JSONResponseBuilder::addFieldRefundCount(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::RefundCount)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getRefundCount(),
                                              responseData.getRefundCount());
                }
                return fieldExists(object, JSONResponseFields::getRefundCount());
            }

            bool JSONResponseBuilder::addFieldSalesArray(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::SaleArray)) {
                    Json::Value array;
                    for (const auto &arrayResponseData : responseData.getSaleArray()) {
                        Json::Value arrayElement;
                        if (!createObject(*arrayResponseData, arrayElement)) {
                            return false;
                        }
                        AddFieldsHelper::addArrayElement(array, arrayElement);
                    } //for
                    AddFieldsHelper::addField(object, JSONResponseFields::getSaleArray(), array);
                }
                return fieldExists(object, JSONResponseFields::getSaleArray());
            }

            bool JSONResponseBuilder::addFieldVoidArray(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::VoidArray)) {
                    Json::Value array;
                    for (const auto &arrayResponseData : responseData.getVoidArray()) {
                        Json::Value arrayElement;
                        if (!createObject(*arrayResponseData, arrayElement)) {
                            return false;
                        }
                        AddFieldsHelper::addArrayElement(array, arrayElement);
                    } //for
                    AddFieldsHelper::addField(object, JSONResponseFields::getVoidArray(), array);
                }
                return fieldExists(object, JSONResponseFields::getVoidArray());
            }

            bool JSONResponseBuilder::addFieldRefundArray(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::RefundArray)) {
                    Json::Value array;
                    for (const auto &arrayResponseData : responseData.getRefundArray()) {
                        Json::Value arrayElement;
                        if (!createObject(*arrayResponseData, arrayElement)) {
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

                if (responseData.validateMandatoryFields()) {
                    result = true;

                    for (auto field : responseData.getMandatoryFields()) {
                        if (responseData.getFieldsSet().find(field) != responseData.getFieldsSet().end()) {
                            auto function = m_InsertFunctions.at(field);
                            result = result && function(responseData, object);
                        }
                    }

                    for (auto field : responseData.getOptionalFields()) {
                        if (responseData.getFieldsSet().find(field) != responseData.getFieldsSet().end()) {
                            auto function = m_InsertFunctions.at(field);
                            function(responseData, object);
                        }
                    }
                }
                return result;
            }

            void JSONResponseBuilder::initFunctionsMap() {
                m_InsertFunctions[ResponseField::EcrNumber] = std::bind(&JSONResponseBuilder::addFieldEcrNumber, this,
                                                                        _1, _2);
                m_InsertFunctions[ResponseField::EcrMerchantNumber] = std::bind(
                        &JSONResponseBuilder::addFieldEcrMerchantNumber, this, _1, _2);
                m_InsertFunctions[ResponseField::OperationCode] = std::bind(&JSONResponseBuilder::addFieldOperationCode,
                                                                            this, _1, _2);
                m_InsertFunctions[ResponseField::OriginalOperationCode] = std::bind(
                        &JSONResponseBuilder::addFieldOriginalOperationCode, this, _1, _2);
                m_InsertFunctions[ResponseField::TotalAmount] = std::bind(&JSONResponseBuilder::addFieldTotalAmount,
                                                                          this, _1, _2);
                m_InsertFunctions[ResponseField::PartialAmount] = std::bind(&JSONResponseBuilder::addFieldPartialAmount,
                                                                            this, _1, _2);
                m_InsertFunctions[ResponseField::AcquirerFeeAmount] = std::bind(
                        &JSONResponseBuilder::addFieldAcquirerFeeAmount, this, _1, _2);
                m_InsertFunctions[ResponseField::TerminalFeeAmount] = std::bind(
                        &JSONResponseBuilder::addFieldTerminalFeeAmount, this, _1, _2);
                m_InsertFunctions[ResponseField::TipsAmount] = std::bind(&JSONResponseBuilder::addFieldTipsAmount, this,
                                                                         _1, _2);
                m_InsertFunctions[ResponseField::CurrencyCode] = std::bind(&JSONResponseBuilder::addFieldCurrencyCode,
                                                                           this, _1, _2);
                m_InsertFunctions[ResponseField::ReceiptReference] = std::bind(
                        &JSONResponseBuilder::addFieldReceiptReference, this, _1, _2);
                m_InsertFunctions[ResponseField::RRN] = std::bind(&JSONResponseBuilder::addFieldRRN, this, _1, _2);
                m_InsertFunctions[ResponseField::Status] = std::bind(&JSONResponseBuilder::addFieldStatus, this, _1,
                                                                     _2);
                m_InsertFunctions[ResponseField::OriginalOperationStatus] = std::bind(
                        &JSONResponseBuilder::addFieldOriginalOperationStatus, this, _1, _2);
                m_InsertFunctions[ResponseField::TransDateTime] = std::bind(&JSONResponseBuilder::addFieldTransDateTime,
                                                                            this, _1, _2);
                m_InsertFunctions[ResponseField::TerminalDateTime] = std::bind(
                        &JSONResponseBuilder::addFieldTerminalDateTime, this, _1, _2);
                m_InsertFunctions[ResponseField::CardPAN] = std::bind(&JSONResponseBuilder::addFieldCardPAN, this, _1,
                                                                      _2);
                m_InsertFunctions[ResponseField::ExpireDate] = std::bind(&JSONResponseBuilder::addFieldExpireDate, this,
                                                                         _1, _2);
                m_InsertFunctions[ResponseField::CardholderName] = std::bind(
                        &JSONResponseBuilder::addFieldCardholderName, this, _1, _2);
                m_InsertFunctions[ResponseField::CardholderAuthMethod] = std::bind(
                        &JSONResponseBuilder::addFieldCardholderAuthMethod, this, _1, _2);
                m_InsertFunctions[ResponseField::AuthCode] = std::bind(&JSONResponseBuilder::addFieldAuthCode, this, _1,
                                                                       _2);
                m_InsertFunctions[ResponseField::ResponseCode] = std::bind(&JSONResponseBuilder::addFieldResponseCode,
                                                                           this, _1, _2);
                m_InsertFunctions[ResponseField::ResponseText] = std::bind(&JSONResponseBuilder::addFieldResponseText,
                                                                           this, _1, _2);
                m_InsertFunctions[ResponseField::STAN] = std::bind(&JSONResponseBuilder::addFieldSTAN, this, _1, _2);
                m_InsertFunctions[ResponseField::TransactionID] = std::bind(&JSONResponseBuilder::addFieldTransactionID,
                                                                            this, _1, _2);
                m_InsertFunctions[ResponseField::TerminalID] = std::bind(&JSONResponseBuilder::addFieldTerminalID, this,
                                                                         _1, _2);
                m_InsertFunctions[ResponseField::CardEmvAid] = std::bind(&JSONResponseBuilder::addFieldCardEmvAid, this,
                                                                         _1, _2);
                m_InsertFunctions[ResponseField::CardAppName] = std::bind(&JSONResponseBuilder::addFieldCardAppName,
                                                                          this, _1, _2);
                m_InsertFunctions[ResponseField::CardInputMethod] = std::bind(
                        &JSONResponseBuilder::addFieldCardInputMethod, this, _1, _2);
                m_InsertFunctions[ResponseField::IssuerName] = std::bind(&JSONResponseBuilder::addFieldIssuerName, this,
                                                                         _1, _2);
                m_InsertFunctions[ResponseField::AdditionalInfo] = std::bind(
                        &JSONResponseBuilder::addFieldAdditionalInfo, this, _1, _2);
                m_InsertFunctions[ResponseField::CardData] = std::bind(&JSONResponseBuilder::addFieldCardData, this, _1,
                                                                       _2);
                m_InsertFunctions[ResponseField::CardDataEnc] = std::bind(&JSONResponseBuilder::addFieldCardDataEnc,
                                                                          this, _1, _2);
                m_InsertFunctions[ResponseField::MerchantID] = std::bind(&JSONResponseBuilder::addFieldMerchantID, this,
                                                                         _1, _2);
                m_InsertFunctions[ResponseField::TVR] = std::bind(&JSONResponseBuilder::addFieldTVR, this, _1, _2);
                m_InsertFunctions[ResponseField::TSI] = std::bind(&JSONResponseBuilder::addFieldTSI, this, _1, _2);
                m_InsertFunctions[ResponseField::TC] = std::bind(&JSONResponseBuilder::addFieldTC, this, _1, _2);
                m_InsertFunctions[ResponseField::CID] = std::bind(&JSONResponseBuilder::addFieldCID, this, _1, _2);
                m_InsertFunctions[ResponseField::KVR] = std::bind(&JSONResponseBuilder::addFieldKVR, this, _1, _2);
                m_InsertFunctions[ResponseField::CDAResult] = std::bind(&JSONResponseBuilder::addFieldCDAResult, this,
                                                                        _1, _2);
                m_InsertFunctions[ResponseField::SaleCount] = std::bind(&JSONResponseBuilder::addFieldSalesCount, this,
                                                                        _1, _2);
                m_InsertFunctions[ResponseField::VoidCount] = std::bind(&JSONResponseBuilder::addFieldVoidCount, this,
                                                                        _1, _2);
                m_InsertFunctions[ResponseField::RefundCount] = std::bind(&JSONResponseBuilder::addFieldRefundCount,
                                                                          this, _1, _2);
                m_InsertFunctions[ResponseField::SaleArray] = std::bind(&JSONResponseBuilder::addFieldSalesArray, this,
                                                                        _1, _2);
                m_InsertFunctions[ResponseField::VoidArray] = std::bind(&JSONResponseBuilder::addFieldVoidArray, this,
                                                                        _1, _2);
                m_InsertFunctions[ResponseField::RefundArray] = std::bind(&JSONResponseBuilder::addFieldRefundArray,
                                                                          this, _1, _2);
            }
        }
    }
}