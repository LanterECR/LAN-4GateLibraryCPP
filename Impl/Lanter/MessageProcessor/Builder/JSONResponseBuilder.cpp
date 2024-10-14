#include "JSONResponseBuilder.h"
#include "JSONAddFieldHelper.h"

#include "Lanter/MessageProcessor/JSONFields/JSONResponseFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Builder
        {
            using namespace std::placeholders;

            JSONResponseBuilder::JSONResponseBuilder()
            {
                initFunctionsMap();
            }

            bool JSONResponseBuilder::createObject(const IResponseData &responseData, Json::Value &object)
            {
                bool result = false;
                try
                {
                    result = addFields(responseData, object);
                }
                catch (std::exception &)
                {
                }

                return result;
            }

            const std::map<ResponseField, std::function<bool(const IResponseData &, Json::Value &)>> &
            JSONResponseBuilder::getFunctions() const
            {
                return m_InsertFunctions;
            }

            bool JSONResponseBuilder::addFieldEcrNumber(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::EcrNumber))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getEcrNumber(), responseData.getEcrNumber());
                }
                return fieldExists(object, JSONResponseFields::getEcrNumber());
            }

            bool JSONResponseBuilder::addFieldEcrMerchantNumber(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::EcrMerchantNumber))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getEcrMerchantNumber(), responseData.getEcrMerchantNumber());
                }
                return fieldExists(object, JSONResponseFields::getEcrMerchantNumber());
            }

            bool JSONResponseBuilder::addFieldOperationCode(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::OperationCode))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getOperationCode(), static_cast<int>(responseData.getOperationCode()));
                }
                return fieldExists(object, JSONResponseFields::getOperationCode());
            }

            bool JSONResponseBuilder::addFieldOriginalOperationCode(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::OriginalOperationCode))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getOriginalOperationCode(), static_cast<int>(responseData.getOriginalOperationCode()));
                }
                return fieldExists(object, JSONResponseFields::getOriginalOperationCode());
            }

            bool JSONResponseBuilder::addFieldTotalAmount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::TotalAmount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTotalAmount(), responseData.getTotalAmount());
                }
                return fieldExists(object, JSONResponseFields::getTotalAmount());
            }

            bool JSONResponseBuilder::addFieldPartialAmount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::PartialAmount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getPartialAmount(), responseData.getPartialAmount());
                }
                return fieldExists(object, JSONResponseFields::getPartialAmount());
            }

            bool JSONResponseBuilder::addFieldAcquirerFeeAmount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::AcquirerFeeAmount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getAcquirerFeeAmount(), responseData.getAcquirerFeeAmount());
                }
                return fieldExists(object, JSONResponseFields::getAcquirerFeeAmount());
            }

            bool JSONResponseBuilder::addFieldTerminalFeeAmount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::TerminalFeeAmount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTerminalFeeAmount(), responseData.getTerminalFeeAmount());
                }
                return fieldExists(object, JSONResponseFields::getTerminalFeeAmount());
            }

            bool JSONResponseBuilder::addFieldTipsAmount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::TipsAmount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTipsAmount(), responseData.getTipsAmount());
                }
                return fieldExists(object, JSONResponseFields::getTipsAmount());
            }

            bool JSONResponseBuilder::addFieldCurrencyCode(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::CurrencyCode))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCurrencyCode(), responseData.getCurrencyCode());
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

            bool JSONResponseBuilder::addFieldCDAResult(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::CDAResult))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCDAResult(), responseData.getCDAResult());
                }
                return fieldExists(object, JSONResponseFields::getCDAResult());
            }

            bool JSONResponseBuilder::addFieldSalesAmount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::SalesAmount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getSalesAmount(), responseData.getSalesAmount());
                }
                return fieldExists(object, JSONResponseFields::getSalesAmount());
            }

            bool JSONResponseBuilder::addFieldSalesCount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::SalesCount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getSalesCount(), responseData.getSalesCount());
                }
                return fieldExists(object, JSONResponseFields::getSalesCount());
            }


            bool JSONResponseBuilder::addFieldVoidAmount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::VoidAmount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getVoidAmount(), responseData.getVoidAmount());
                }
                return fieldExists(object, JSONResponseFields::getVoidAmount());
            }

            bool JSONResponseBuilder::addFieldVoidCount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::VoidCount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getVoidCount(), responseData.getVoidCount());
                }
                return fieldExists(object, JSONResponseFields::getVoidCount());
            }


            bool JSONResponseBuilder::addFieldRefundAmount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::RefundAmount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getRefundAmount(), responseData.getRefundAmount());
                }
                return fieldExists(object, JSONResponseFields::getRefundAmount());
            }

            bool JSONResponseBuilder::addFieldRefundCount(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::RefundCount))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getRefundCount(),
                                              responseData.getRefundCount());
                }
                return fieldExists(object, JSONResponseFields::getRefundCount());
            }

            bool JSONResponseBuilder::addFieldSalesArray(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::SalesArray))
                {
                    Json::Value array;
                    for (const auto &arrayResponseData : responseData.getSalesArray())
                    {
                        Json::Value arrayElement;
                        if (!createObject(*arrayResponseData, arrayElement))
                        {
                            return false;
                        }
                        AddFieldsHelper::addArrayElement(array, arrayElement);
                    } //for
                    AddFieldsHelper::addField(object, JSONResponseFields::getSalesArray(), array);
                }
                return fieldExists(object, JSONResponseFields::getSalesArray());
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

            bool JSONResponseBuilder::addFieldCfgTerminalID(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CfgTerminalID)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCfgTerminalID(), responseData.getCfgTerminalID());
                }
                return fieldExists(object, JSONResponseFields::getCfgTerminalID());
            }

            bool JSONResponseBuilder::addFieldCardPANHash(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::CardPANHash)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getCardPANHash(), responseData.getCardPANHash());
                }
                return fieldExists(object, JSONResponseFields::getCardPANHash());
            }

            bool JSONResponseBuilder::addFieldReceiptLine1(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::ReceiptLine1)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine1(), responseData.getReceiptLine1());
                }
                return fieldExists(object, JSONResponseFields::getReceiptLine1());
            }

            bool JSONResponseBuilder::addFieldReceiptLine2(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::ReceiptLine2)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine2(), responseData.getReceiptLine2());
                }
                return fieldExists(object, JSONResponseFields::getReceiptLine2());
            }

            bool JSONResponseBuilder::addFieldReceiptLine3(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::ReceiptLine3)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine3(), responseData.getReceiptLine3());
                }
                return fieldExists(object, JSONResponseFields::getReceiptLine3());
            }

            bool JSONResponseBuilder::addFieldReceiptLine4(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::ReceiptLine4)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine4(), responseData.getReceiptLine4());
                }
                return fieldExists(object, JSONResponseFields::getReceiptLine4());
            }

            bool JSONResponseBuilder::addFieldReceiptLine5(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::ReceiptLine5)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getReceiptLine5(), responseData.getReceiptLine5());
                }
                return fieldExists(object, JSONResponseFields::getReceiptLine5());
            }

            bool JSONResponseBuilder::addFieldApplicationLabel(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::ApplicationLabel)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getApplicationLabel(), responseData.getApplicationLabel());
                }
                return fieldExists(object, JSONResponseFields::getApplicationLabel());
            }

            bool JSONResponseBuilder::addFieldBonusBalance(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::BonusBalance)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getBonusBalance(), responseData.getBonusBalance());
                }
                return fieldExists(object, JSONResponseFields::getBonusBalance());
            }

            bool JSONResponseBuilder::addFieldBonusAmount(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::BonusAmount)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getBonusAmount(), responseData.getBonusAmount());
                }
                return fieldExists(object, JSONResponseFields::getBonusAmount());
            }

            bool JSONResponseBuilder::addFieldHashCardTrack2(const IResponseData &responseData, Json::Value &object) {
                if (responseData.isFieldSet(ResponseField::HashCardTrack2)) {
                    AddFieldsHelper::addField(object, JSONResponseFields::getHashCardTrack2(), responseData.getHashCardTrack2());
                }
                return fieldExists(object, JSONResponseFields::getHashCardTrack2());
            }

            bool JSONResponseBuilder::addFieldFinalizationRequired(const IResponseData &responseData, Json::Value &object)
            {
                if (responseData.isFieldSet(ResponseField::FinalizationRequired))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getFinalizationRequired(), responseData.getFinalizationRequired());
                }
                return fieldExists(object, JSONResponseFields::getFinalizationRequired());
            }

            bool JSONResponseBuilder::addFieldAdditionalChoiceResult(const IResponseData& responseData, Json::Value& object)
            {
                if (responseData.isFieldSet(ResponseField::AdditionalChoiceResult))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getAdditionalChoiceResult(), responseData.getAdditionalChoiceResult());
                }
                return fieldExists(object, JSONResponseFields::getAdditionalChoiceResult());
            }

            bool JSONResponseBuilder::addFieldTransportControlDateTime(const IResponseData& responseData, Json::Value& object)
            {
                if (responseData.isFieldSet(ResponseField::TransportControlDateTime))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getTransportControlDateTime(), responseData.getTransportControlDateTime());
                }
                return fieldExists(object, JSONResponseFields::getTransportControlDateTime());
            }

			bool JSONResponseBuilder::addFieldECertAmount(const IResponseData &responseData, Json::Value &object)
            {
				if (responseData.isFieldSet(ResponseField::ECertAmount))
                {
					AddFieldsHelper::addField(object, JSONResponseFields::getECertAmount(),	responseData.getECertAmount());
				}
				return fieldExists(object, JSONResponseFields::getECertAmount());
			}

			bool JSONResponseBuilder::addFieldBasketID(const IResponseData &responseData, Json::Value &object)
            {
				if (responseData.isFieldSet(ResponseField::BasketID))
                {
					AddFieldsHelper::addField(object, JSONResponseFields::getBasketID(), responseData.getBasketID());
				}
				return fieldExists(object, JSONResponseFields::getBasketID());
			}

            bool JSONResponseBuilder::addFieldSBP_RN(const IResponseData& responseData, Json::Value& object)
            {
                if (responseData.isFieldSet(ResponseField::SBP_RN))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getSBP_RN(), responseData.getSBP_RN());
                }
                return fieldExists(object, JSONResponseFields::getSBP_RN());
            }

            bool JSONResponseBuilder::addFieldQRCode(const IResponseData& responseData, Json::Value& object)
            {
                if (responseData.isFieldSet(ResponseField::QRCode))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getQRCode(), responseData.getQRCode());
                }
                return fieldExists(object, JSONResponseFields::getQRCode());
            }

            bool JSONResponseBuilder::addFieldSBP_KZO(const IResponseData& responseData, Json::Value& object)
            {
                if (responseData.isFieldSet(ResponseField::SBP_KZO))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getSBP_KZO(), responseData.getSBP_KZO());
                }
                return fieldExists(object, JSONResponseFields::getSBP_KZO());
            }

            bool JSONResponseBuilder::addFieldSBP_ReqId(const IResponseData& responseData, Json::Value& object)
            {
                if (responseData.isFieldSet(ResponseField::SBP_ReqId))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getSBP_ReqId(), responseData.getSBP_ReqId());
                }
                return fieldExists(object, JSONResponseFields::getSBP_ReqId());
            }

            bool JSONResponseBuilder::addFieldSBP_Code(const IResponseData& responseData, Json::Value& object)
            {
                if (responseData.isFieldSet(ResponseField::SBP_Code))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getSBP_Code(), responseData.getSBP_Code());
                }
                return fieldExists(object, JSONResponseFields::getSBP_Code());
            }

            bool JSONResponseBuilder::addFieldSBP_Status(const IResponseData& responseData, Json::Value& object)
            {
                if (responseData.isFieldSet(ResponseField::SBP_Status))
                {
                    AddFieldsHelper::addField(object, JSONResponseFields::getSBP_Status(), responseData.getSBP_Status());
                }
                return fieldExists(object, JSONResponseFields::getSBP_Status());
            }

            bool JSONResponseBuilder::addFields(const IResponseData &responseData, Json::Value &object)
            {
                bool result = false;

                if (responseData.validateMandatoryFields())
                {
                    result = true;

                    for (auto field : responseData.getMandatoryFields())
                    {
                        if (responseData.getFieldsSet().find(field) != responseData.getFieldsSet().end())
                        {
                            auto function = m_InsertFunctions.at(field);
                            result = result && function(responseData, object);
                        }
                    }

                    for (auto field : responseData.getOptionalFields())
                    {
                        if (responseData.getFieldsSet().find(field) != responseData.getFieldsSet().end())
                        {
                            auto function = m_InsertFunctions.at(field);
                            function(responseData, object);
                        }
                    }
                }
                return result;
            }

            void JSONResponseBuilder::initFunctionsMap()
            {
                m_InsertFunctions[ResponseField::EcrNumber] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldEcrNumber(responseData, object); };
                m_InsertFunctions[ResponseField::EcrMerchantNumber] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldEcrMerchantNumber(responseData, object); };
                m_InsertFunctions[ResponseField::OperationCode] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldOperationCode(responseData, object); };
                m_InsertFunctions[ResponseField::OriginalOperationCode] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldOriginalOperationCode(responseData, object); };
                m_InsertFunctions[ResponseField::TotalAmount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldTotalAmount(responseData, object); };
                m_InsertFunctions[ResponseField::PartialAmount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldPartialAmount(responseData, object); };
                m_InsertFunctions[ResponseField::AcquirerFeeAmount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldAcquirerFeeAmount(responseData, object); };
                m_InsertFunctions[ResponseField::TerminalFeeAmount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldTerminalFeeAmount(responseData, object); };
                m_InsertFunctions[ResponseField::TipsAmount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldTipsAmount(responseData, object); };
                m_InsertFunctions[ResponseField::CurrencyCode] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCurrencyCode(responseData, object); };
                m_InsertFunctions[ResponseField::ReceiptReference] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldReceiptReference(responseData, object); };
                m_InsertFunctions[ResponseField::RRN] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldRRN(responseData, object); };
                m_InsertFunctions[ResponseField::Status] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldStatus(responseData, object); };
                m_InsertFunctions[ResponseField::OriginalOperationStatus] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldOriginalOperationStatus(responseData, object); };
                m_InsertFunctions[ResponseField::TransDateTime] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldTransDateTime(responseData, object); };
                m_InsertFunctions[ResponseField::TerminalDateTime] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldTerminalDateTime(responseData, object); };
                m_InsertFunctions[ResponseField::CardPAN] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCardPAN(responseData, object); };
                m_InsertFunctions[ResponseField::ExpireDate] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldExpireDate(responseData, object); };
                m_InsertFunctions[ResponseField::CardholderName] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCardholderName(responseData, object); };
                m_InsertFunctions[ResponseField::CardholderAuthMethod] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCardholderAuthMethod(responseData, object); };
                m_InsertFunctions[ResponseField::AuthCode] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldAuthCode(responseData, object); };
                m_InsertFunctions[ResponseField::ResponseCode] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldResponseCode(responseData, object); };
                m_InsertFunctions[ResponseField::ResponseText] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldResponseText(responseData, object); };
                m_InsertFunctions[ResponseField::STAN] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldSTAN(responseData, object); };
                m_InsertFunctions[ResponseField::TransactionID] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldTransactionID(responseData, object); };
                m_InsertFunctions[ResponseField::TerminalID] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldTerminalID(responseData, object); };
                m_InsertFunctions[ResponseField::CardEmvAid] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCardEmvAid(responseData, object); };
                m_InsertFunctions[ResponseField::CardAppName] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCardAppName(responseData, object); };
                m_InsertFunctions[ResponseField::CardInputMethod] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCardInputMethod(responseData, object); };
                m_InsertFunctions[ResponseField::IssuerName] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldIssuerName(responseData, object); };
                m_InsertFunctions[ResponseField::AdditionalInfo] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldAdditionalInfo(responseData, object); };
                m_InsertFunctions[ResponseField::CardData] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCardData(responseData, object); };
                m_InsertFunctions[ResponseField::CardDataEnc] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCardDataEnc(responseData, object); };
                m_InsertFunctions[ResponseField::MerchantID] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldMerchantID(responseData, object); };
                m_InsertFunctions[ResponseField::TVR] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldTVR(responseData, object); };
                m_InsertFunctions[ResponseField::TSI] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldTSI(responseData, object); };
                m_InsertFunctions[ResponseField::TC] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldTC(responseData, object); };
                m_InsertFunctions[ResponseField::CID] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCID(responseData, object); };
                m_InsertFunctions[ResponseField::KVR] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldKVR(responseData, object); };
                m_InsertFunctions[ResponseField::CDAResult] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCDAResult(responseData, object); };
                m_InsertFunctions[ResponseField::SalesAmount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldSalesAmount(responseData, object); };
                m_InsertFunctions[ResponseField::SalesCount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldSalesCount(responseData, object); };
                m_InsertFunctions[ResponseField::VoidAmount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldVoidAmount(responseData, object); };
                m_InsertFunctions[ResponseField::VoidCount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldVoidCount(responseData, object); };
                m_InsertFunctions[ResponseField::RefundAmount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldRefundAmount(responseData, object); };
                m_InsertFunctions[ResponseField::RefundCount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldRefundCount(responseData, object); };
                m_InsertFunctions[ResponseField::SalesArray] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldSalesArray(responseData, object); };
                m_InsertFunctions[ResponseField::VoidArray] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldVoidArray(responseData, object); };
                m_InsertFunctions[ResponseField::RefundArray] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldRefundArray(responseData, object); };
                m_InsertFunctions[ResponseField::CfgTerminalID] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCfgTerminalID(responseData, object); };
                m_InsertFunctions[ResponseField::CardPANHash] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldCardPANHash(responseData, object); };
                m_InsertFunctions[ResponseField::ReceiptLine1] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldReceiptLine1(responseData, object); };
                m_InsertFunctions[ResponseField::ReceiptLine2] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldReceiptLine2(responseData, object); };
                m_InsertFunctions[ResponseField::ReceiptLine3] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldReceiptLine3(responseData, object); };
                m_InsertFunctions[ResponseField::ReceiptLine4] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldReceiptLine4(responseData, object); };
                m_InsertFunctions[ResponseField::ReceiptLine5] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldReceiptLine5(responseData, object); };
                m_InsertFunctions[ResponseField::ApplicationLabel] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldApplicationLabel(responseData, object); };
                m_InsertFunctions[ResponseField::BonusBalance] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldBonusBalance(responseData, object); };
                m_InsertFunctions[ResponseField::BonusAmount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldBonusAmount(responseData, object); };
                m_InsertFunctions[ResponseField::HashCardTrack2] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldHashCardTrack2(responseData, object); };
                m_InsertFunctions[ResponseField::FinalizationRequired] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldFinalizationRequired(responseData, object); };
                m_InsertFunctions[ResponseField::AdditionalChoiceResult] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldAdditionalChoiceResult(responseData, object); };
                m_InsertFunctions[ResponseField::TransportControlDateTime] = [this](const IResponseData& responseData, Json::Value& object) { return addFieldTransportControlDateTime(responseData, object); };
				m_InsertFunctions[ResponseField::ECertAmount] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldECertAmount(responseData, object); };
				m_InsertFunctions[ResponseField::BasketID] = [this](const IResponseData &responseData, Json::Value &object) { return addFieldBasketID(responseData, object); };
                m_InsertFunctions[ResponseField::SBP_RN] = [this](const IResponseData& responseData, Json::Value& object) { return addFieldSBP_RN(responseData, object); };
                m_InsertFunctions[ResponseField::QRCode] = [this](const IResponseData& responseData, Json::Value& object) { return addFieldQRCode(responseData, object); };
                m_InsertFunctions[ResponseField::SBP_KZO] = [this](const IResponseData& responseData, Json::Value& object) { return addFieldSBP_KZO(responseData, object); };
                m_InsertFunctions[ResponseField::SBP_ReqId] = [this](const IResponseData& responseData, Json::Value& object) { return addFieldSBP_ReqId(responseData, object); };
                m_InsertFunctions[ResponseField::SBP_Code] = [this](const IResponseData& responseData, Json::Value& object) { return addFieldSBP_Code(responseData, object); };
                m_InsertFunctions[ResponseField::SBP_Status] = [this](const IResponseData& responseData, Json::Value& object) { return addFieldSBP_Status(responseData, object); };
			}
        }
    }
}