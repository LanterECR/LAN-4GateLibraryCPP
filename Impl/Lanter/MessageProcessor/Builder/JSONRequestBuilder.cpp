#include "JSONRequestBuilder.h"

#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"
#include "Lanter/MessageProcessor/JSONFields/JSONRequestFields.h"

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

            bool JSONRequestBuilder::addFieldBonusBalance(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::BonusBalance)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getBonusBalance(),
                                              requestData.getBonusBalance());
                }
                return fieldExists(object, JSONRequestFields::getBonusBalance());
            }

            bool JSONRequestBuilder::addFieldBonusAmount(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::BonusAmount)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getBonusAmount(),
                                              requestData.getBonusAmount());
                }
                return fieldExists(object, JSONRequestFields::getBonusAmount());
            }

            bool JSONRequestBuilder::addFieldHashCardTrack2(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::HashCardTrack2)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getHashCardTrack2(),
                                              requestData.getHashCardTrack2());
                }
                return fieldExists(object, JSONRequestFields::getHashCardTrack2());
            }

            bool JSONRequestBuilder::addFieldPaymentProviderCode(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::HashCardTrack2)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getHashCardTrack2(),
                                              requestData.getHashCardTrack2());
                }
                return fieldExists(object, JSONRequestFields::getHashCardTrack2());
            }

            bool JSONRequestBuilder::addFieldPaymentParam1(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::PaymentParam1)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getPaymentParam1(),
                                              requestData.getPaymentParam1());
                }
                return fieldExists(object, JSONRequestFields::getPaymentParam1());
            }

            bool JSONRequestBuilder::addFieldPaymentParam2(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::PaymentParam2)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getPaymentParam2(),
                                              requestData.getPaymentParam2());
                }
                return fieldExists(object, JSONRequestFields::getPaymentParam2());
            }

            bool JSONRequestBuilder::addFieldPaymentParam3(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::PaymentParam3)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getPaymentParam3(),
                                              requestData.getPaymentParam3());
                }
                return fieldExists(object, JSONRequestFields::getPaymentParam3());
            }

            bool JSONRequestBuilder::addFieldAdditionalChoice(const IRequestData &requestData, Json::Value &object) {
                if (requestData.isFieldSet(RequestField::AdditionalChoice)) {
                    AddFieldsHelper::addField(object, JSONRequestFields::getAdditionalChoice(),
                                              requestData.getAdditionalChoice());
                }
                return fieldExists(object, JSONRequestFields::getAdditionalChoice());
            }

            void JSONRequestBuilder::initFunctionsMap() {
                m_InsertFunctions[RequestField::EcrNumber] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldEcrNumber(requestData, object); };
                m_InsertFunctions[RequestField::EcrMerchantNumber] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldEcrMerchantNumber(requestData, object); };
                m_InsertFunctions[RequestField::OperationCode] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldOperationCode(requestData, object); };
                m_InsertFunctions[RequestField::Amount] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldAmount(requestData, object); };
                m_InsertFunctions[RequestField::PartialAmount] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldPartialAmount(requestData, object); };
                m_InsertFunctions[RequestField::TipsAmount] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldTipsAmount(requestData, object); };
                m_InsertFunctions[RequestField::CashbackAmount] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldCashbackAmount(requestData, object); };
                m_InsertFunctions[RequestField::CurrencyCode] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldCurrencyCode(requestData, object); };
                m_InsertFunctions[RequestField::RRN] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldRRN(requestData, object); };
                m_InsertFunctions[RequestField::AuthCode] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldAuthCode(requestData, object); };
                m_InsertFunctions[RequestField::ReceiptReference] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldReceiptReference(requestData, object); };
                m_InsertFunctions[RequestField::TransactionID] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldTransactionID(requestData, object); };
                m_InsertFunctions[RequestField::CardDataEnc] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldCardDataEnc(requestData, object); };
                m_InsertFunctions[RequestField::OpenTags] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldOpenTags(requestData, object); };
                m_InsertFunctions[RequestField::EncTags] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldEncTags(requestData, object); };
                m_InsertFunctions[RequestField::ProviderCode] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldProviderCode(requestData, object); };
                m_InsertFunctions[RequestField::AdditionalInfo] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldAdditionalInfo(requestData, object); };
                m_InsertFunctions[RequestField::BonusBalance] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldBonusBalance(requestData, object); };
                m_InsertFunctions[RequestField::BonusAmount] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldBonusAmount(requestData, object); };
                m_InsertFunctions[RequestField::HashCardTrack2] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldHashCardTrack2(requestData, object); };
                m_InsertFunctions[RequestField::PaymentProviderCode] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldPaymentProviderCode(requestData, object); };
                m_InsertFunctions[RequestField::PaymentParam1] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldPaymentParam1(requestData, object); };
                m_InsertFunctions[RequestField::PaymentParam2] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldPaymentParam2(requestData, object); };
                m_InsertFunctions[RequestField::PaymentParam3] = [this](const IRequestData &requestData, Json::Value &object) { return addFieldPaymentParam3(requestData, object); };
                m_InsertFunctions[RequestField::AdditionalChoice] = [this](const IRequestData& requestData, Json::Value& object) { return addFieldAdditionalChoice(requestData, object); };
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