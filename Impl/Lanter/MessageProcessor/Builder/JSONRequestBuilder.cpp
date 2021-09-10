#include "JSONRequestBuilder.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"
#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/MessageProcessor/Builder/JSONAddFieldHelper.h"

using namespace std::placeholders;
namespace Lanter {
    namespace MessageProcessor {
        namespace Builder {
            JSONRequestBuilder::JSONRequestBuilder() {
                initFunctionsMap();
            }

            bool JSONRequestBuilder::createObject(const IRequestData &requestData, Json::Value &object) {
                return addFields(requestData, object);
            }

            const std::map<RequestField, std::function<bool(const IRequestData &, Json::Value &)>> &
            JSONRequestBuilder::getFunctions() const {
                return m_InsertFunctions;
            }

            bool JSONRequestBuilder::addFieldEcrNumber(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::EcrNumber)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getEcrNumber(), requestData.getEcrNumber());
                }
                return fieldExists(object, JSONRequestFields::getEcrNumber());
            }

            bool JSONRequestBuilder::addFieldEcrMerchantNumber(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::EcrMerchantNumber)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getEcrMerchantNumber(),
                                              requestData.getEcrMerchantNumber());
                }
                return fieldExists(object, JSONRequestFields::getEcrMerchantNumber());
            }

            bool JSONRequestBuilder::addFieldOperationCode(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::OperationCode)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getOperationCode(),
                                              static_cast<int>(requestData.getOperationCode()));
                }
                return fieldExists(object, JSONRequestFields::getOperationCode());
            }

            bool JSONRequestBuilder::addFieldAmount(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::Amount)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getAmount(), requestData.getAmount());
                }
                return fieldExists(object, JSONRequestFields::getAmount());
            }

            bool JSONRequestBuilder::addFieldPartialAmount(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::PartialAmount)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getPartialAmount(),
                                              requestData.getPartialAmount());
                }
                return fieldExists(object, JSONRequestFields::getPartialAmount());
            }

            bool JSONRequestBuilder::addFieldTipsAmount(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::TipsAmount)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getTipsAmount(), requestData.getTipsAmount());
                }
                return fieldExists(object, JSONRequestFields::getTipsAmount());
            }

            bool JSONRequestBuilder::addFieldCashbackAmount(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::CashbackAmount)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getCashbackAmount(),
                                              requestData.getCashbackAmount());
                }
                return fieldExists(object, JSONRequestFields::getCashbackAmount());
            }

            bool JSONRequestBuilder::addFieldCurrencyCode(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::CurrencyCode)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getCurrencyCode(),
                                              requestData.getCurrencyCode());
                }
                return fieldExists(object, JSONRequestFields::getCurrencyCode());
            }

            bool JSONRequestBuilder::addFieldRRN(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::RRN)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getRRN(), requestData.getRRN());
                }
                return fieldExists(object, JSONRequestFields::getRRN());
            }

            bool JSONRequestBuilder::addFieldAuthCode(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::AuthCode)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getAuthCode(), requestData.getAuthCode());
                }
                return fieldExists(object, JSONRequestFields::getAuthCode());
            }

            bool JSONRequestBuilder::addFieldReceiptReference(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::ReceiptReference)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getReceiptReference(),
                                              requestData.getReceiptReference());
                }
                return fieldExists(object, JSONRequestFields::getReceiptReference());
            }

            bool JSONRequestBuilder::addFieldTransactionID(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::TransactionID)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getTransactionID(),
                                              requestData.getTransactionID());
                }
                return fieldExists(object, JSONRequestFields::getTransactionID());
            }

            bool JSONRequestBuilder::addFieldCardDataEnc(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::CardDataEnc)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getCardDataEnc(),
                                              requestData.getCardDataEnc());
                }
                return fieldExists(object, JSONRequestFields::getCardDataEnc());
            }

            bool JSONRequestBuilder::addFieldOpenTags(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::OpenTags)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getOpenTags(), requestData.getOpenTags());
                }
                return fieldExists(object, JSONRequestFields::getOpenTags());
            }

            bool JSONRequestBuilder::addFieldEncTags(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::EncTags)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getEncTags(), requestData.getEncTags());
                }
                return fieldExists(object, JSONRequestFields::getEncTags());
            }

            bool JSONRequestBuilder::addFieldProviderCode(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::ProviderCode)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getProviderCode(),
                                              requestData.getProviderCode());
                }
                return fieldExists(object, JSONRequestFields::getProviderCode());
            }

            bool JSONRequestBuilder::addFieldAdditionalInfo(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::AdditionalInfo)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getAdditionalInfo(),
                                              requestData.getAdditionalInfo());
                }
                return fieldExists(object, JSONRequestFields::getAdditionalInfo());
            }

            void JSONRequestBuilder::initFunctionsMap() {
                m_InsertFunctions[RequestField::EcrNumber] = std::bind(&JSONRequestBuilder::addFieldEcrNumber, this, _1,
                                                                       _2);
                m_InsertFunctions[RequestField::EcrMerchantNumber] = std::bind(
                        &JSONRequestBuilder::addFieldEcrMerchantNumber, this, _1, _2);
                m_InsertFunctions[RequestField::OperationCode] = std::bind(&JSONRequestBuilder::addFieldOperationCode,
                                                                           this, _1, _2);
                m_InsertFunctions[RequestField::Amount] = std::bind(&JSONRequestBuilder::addFieldAmount, this, _1, _2);
                m_InsertFunctions[RequestField::PartialAmount] = std::bind(&JSONRequestBuilder::addFieldPartialAmount,
                                                                           this, _1, _2);
                m_InsertFunctions[RequestField::TipsAmount] = std::bind(&JSONRequestBuilder::addFieldTipsAmount, this,
                                                                        _1, _2);
                m_InsertFunctions[RequestField::CashbackAmount] = std::bind(&JSONRequestBuilder::addFieldCashbackAmount,
                                                                            this, _1, _2);
                m_InsertFunctions[RequestField::CurrencyCode] = std::bind(&JSONRequestBuilder::addFieldCurrencyCode,
                                                                          this, _1, _2);
                m_InsertFunctions[RequestField::RRN] = std::bind(&JSONRequestBuilder::addFieldRRN, this, _1, _2);
                m_InsertFunctions[RequestField::AuthCode] = std::bind(&JSONRequestBuilder::addFieldAuthCode, this, _1,
                                                                      _2);
                m_InsertFunctions[RequestField::ReceiptReference] = std::bind(
                        &JSONRequestBuilder::addFieldReceiptReference, this, _1, _2);
                m_InsertFunctions[RequestField::TransactionID] = std::bind(&JSONRequestBuilder::addFieldTransactionID,
                                                                           this, _1, _2);
                m_InsertFunctions[RequestField::CardDataEnc] = std::bind(&JSONRequestBuilder::addFieldCardDataEnc, this,
                                                                         _1, _2);
                m_InsertFunctions[RequestField::OpenTags] = std::bind(&JSONRequestBuilder::addFieldOpenTags, this, _1,
                                                                      _2);
                m_InsertFunctions[RequestField::EncTags] = std::bind(&JSONRequestBuilder::addFieldEncTags, this, _1,
                                                                     _2);
                m_InsertFunctions[RequestField::ProviderCode] = std::bind(&JSONRequestBuilder::addFieldProviderCode,
                                                                          this, _1, _2);
                m_InsertFunctions[RequestField::AdditionalInfo] = std::bind(&JSONRequestBuilder::addFieldAdditionalInfo,
                                                                            this, _1, _2);
            }

            //TODO переделать нормально
            bool JSONRequestBuilder::addFields(const IRequestData &requestData, Json::Value &object) {
                bool result = false;

                if (requestData.validateMandatoryFields()) {
                    result = true;

                    for (auto field : requestData.getMandatoryFields()) {
                        if (requestData.getFieldsSet().find(field) != requestData.getFieldsSet().end()) {
                            auto function = m_InsertFunctions.at(field);
                            result = result && function(requestData, object);
                        }
                    }

                    for (auto field : requestData.getOptionalFields()) {
                        if (requestData.getFieldsSet().find(field) != requestData.getFieldsSet().end()) {
                            auto function = m_InsertFunctions.at(field);
                            function(requestData, object);
                        }
                    }
                }
                return result;
            }
        }
    }
}