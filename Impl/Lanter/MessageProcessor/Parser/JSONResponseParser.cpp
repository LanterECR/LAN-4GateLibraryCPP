#include "JSONResponseParser.h"
#include "JSONGetFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFields/JSONResponseFields.h"
#include "Lanter/Message/Response/ResponseDataFactory.h"

namespace Lanter
{
	namespace MessageProcessor
	{
		namespace Parser
		{
			using namespace std::placeholders;

			JSONResponseParser::JSONResponseParser()
			{
				initFunctionsMap();
			}

			std::shared_ptr<IResponseData> JSONResponseParser::parseData(const Json::Value& object)
			{
				std::shared_ptr<IResponseData> result = ResponseDataFactory::getResponseData();
				if (result)
				{
					if (!getFields(object, *result))
					{
						result.reset();
					}
				}

				return result;
			}

			const std::map<ResponseField, std::function<bool(const Json::Value&, IResponseData&)> > &
			JSONResponseParser::getFunctions() const
			{
				return m_ExtractFunctions;
			}

			bool JSONResponseParser::getFieldEcrNumber(const Json::Value& object, IResponseData& responseData)
			{
				int ecrNumber;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getEcrNumber(), ecrNumber);
				return exists && responseData.setEcrNumber(ecrNumber);
			}

			bool JSONResponseParser::getFieldEcrMerchantNumber(const Json::Value& object, IResponseData& responseData)
			{
				int ecrMerchantNumber;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getEcrMerchantNumber(), ecrMerchantNumber);
				const bool result = exists && responseData.setEcrMerchantNumber(ecrMerchantNumber);

				return result;
			}

			bool JSONResponseParser::getFieldOperationCode(const Json::Value& object, IResponseData& responseData)
			{
				int operationCode;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getOperationCode(), operationCode);
				const bool result = exists && responseData.setOperationCode(static_cast<OperationCode>(operationCode));

				return result;
			}

			bool JSONResponseParser::getFieldOriginalOperationCode(const Json::Value& object, IResponseData& responseData)
			{
				int originalOperationCode;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getOriginalOperationCode(), originalOperationCode);
				const bool result = exists && responseData.setOriginalOperationCode(static_cast<OperationCode>(originalOperationCode));

				return result;
			}

			bool JSONResponseParser::getFieldTotalAmount(const Json::Value& object, IResponseData& responseData)
			{
				int64_t totalAmount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTotalAmount(), totalAmount);
				const bool result = exists && responseData.setTotalAmount(totalAmount);

				return result;
			}

			bool JSONResponseParser::getFieldPartialAmount(const Json::Value& object, IResponseData& responseData)
			{
				int64_t partialAmount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getPartialAmount(), partialAmount);
				const bool result = exists && responseData.setPartialAmount(partialAmount);

				return result;
			}

			bool JSONResponseParser::getFieldAcquirerFeeAmount(const Json::Value& object, IResponseData& responseData)
			{
				int64_t acquirerFeeAmount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getAcquirerFeeAmount(), acquirerFeeAmount);
				const bool result = exists && responseData.setAcquirerFeeAmount(acquirerFeeAmount);

				return result;
			}

			bool JSONResponseParser::getFieldTerminalFeeAmount(const Json::Value& object, IResponseData& responseData)
			{
				int64_t terminalFeeAmount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTerminalFeeAmount(), terminalFeeAmount);
				const bool result = exists && responseData.setTerminalFeeAmount(terminalFeeAmount);

				return result;
			}

			bool JSONResponseParser::getFieldTipsAmount(const Json::Value& object, IResponseData& responseData)
			{
				int64_t tipsAmount;
				const const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTipsAmount(), tipsAmount);
				const bool result = exists && responseData.setTipsAmount(tipsAmount);

				return result;
			}

			bool JSONResponseParser::getFieldCurrencyCode(const Json::Value& object, IResponseData& responseData)
			{
				int currencyCode;
				bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCurrencyCode(), currencyCode);
				bool result = exists && responseData.setCurrencyCode(std::to_string(currencyCode));

				if (!result)
				{
					std::string currencyCode;
					exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCurrencyCode(), currencyCode);
					result = exists && responseData.setCurrencyCode(currencyCode);
				}
				return result;
			}

			bool JSONResponseParser::getFieldReceiptReference(const Json::Value& object, IResponseData& responseData)
			{
				std::string receiptReference;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getReceiptReference(), receiptReference);
				const bool result = exists && responseData.setReceiptReference(receiptReference);

				return result;
			}

			bool JSONResponseParser::getFieldRRN(const Json::Value& object, IResponseData& responseData)
			{
				std::string rrn;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getRRN(), rrn);
				const bool result = exists && responseData.setRRN(rrn);

				return result;
			}

			bool JSONResponseParser::getFieldStatus(const Json::Value& object, IResponseData& responseData)
			{
				int status;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getStatus(), status);
				const bool result = exists && responseData.setStatus(static_cast<Status>(status));

				return result;
			}

			bool JSONResponseParser::getFieldOriginalOperationStatus(const Json::Value& object, IResponseData& responseData)
			{
				int originalOperationStatus;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getOriginalOperationStatus(), originalOperationStatus);
				const bool result = exists && responseData.setOriginalOperationStatus(static_cast<Status>(originalOperationStatus));

				return result;
			}

			bool JSONResponseParser::getFieldTransDateTime(const Json::Value& object, IResponseData& responseData)
			{
				std::string transDateTime;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTransDateTime(), transDateTime);
				const bool result = exists && responseData.setTransDateTime(transDateTime);

				return result;
			}

			bool JSONResponseParser::getFieldTerminalDateTime(const Json::Value& object, IResponseData& responseData)
			{
				std::string terminalDateTime;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTerminalDateTime(), terminalDateTime);
				const bool result = exists && responseData.setTerminalDateTime(terminalDateTime);

				return result;
			}

			bool JSONResponseParser::getFieldCardPAN(const Json::Value& object, IResponseData& responseData)
			{
				std::string cardPAN;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardPAN(), cardPAN);
				const bool result = exists && responseData.setCardPAN(cardPAN);

				return result;
			}

			bool JSONResponseParser::getFieldExpireDate(const Json::Value& object, IResponseData& responseData)
			{
				std::string expireDate;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getExpireDate(), expireDate);
				const bool result = exists && responseData.setExpireDate(expireDate);

				return result;
			}

			bool JSONResponseParser::getFieldCardholderName(const Json::Value& object, IResponseData& responseData)
			{
				std::string cardholderName;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardholderName(), cardholderName);
				const bool result = exists && responseData.setCardholderName(cardholderName);

				return result;
			}

			bool JSONResponseParser::getFieldCardholderAuthMethod(const Json::Value& object, IResponseData& responseData)
			{
				int cardholderAuthMethod;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardholderAuthMethod(), cardholderAuthMethod);
				const bool result = exists && responseData.setCardholderAuthMethod(static_cast<CardholderAuthMethod>(cardholderAuthMethod));

				return result;
			}

			bool JSONResponseParser::getFieldAuthCode(const Json::Value& object, IResponseData& responseData)
			{
				std::string authCode;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getAuthCode(), authCode);
				const bool result = exists && responseData.setAuthCode(authCode);

				return result;
			}

			bool JSONResponseParser::getFieldResponseCode(const Json::Value& object, IResponseData& responseData)
			{
				std::string responseCode;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getResponseCode(), responseCode);
				const bool result = exists && responseData.setResponseCode(responseCode);

				return result;
			}

			bool JSONResponseParser::getFieldResponseText(const Json::Value& object, IResponseData& responseData)
			{
				std::string responseText;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getResponseText(), responseText);
				const bool result = exists && responseData.setResponseText(responseText);

				return result;
			}

			bool JSONResponseParser::getFieldSTAN(const Json::Value& object, IResponseData& responseData)
			{
				std::string STAN;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSTAN(), STAN);
				const bool result = exists && responseData.setSTAN(STAN);

				return result;
			}

			bool JSONResponseParser::getFieldTransactionID(const Json::Value& object, IResponseData& responseData)
			{
				std::string transactionID;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTransactionID(), transactionID);
				const bool result = exists && responseData.setTransactionID(transactionID);

				return result;
			}

			bool JSONResponseParser::getFieldTerminalID(const Json::Value& object, IResponseData& responseData)
			{
				std::string terminalID;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTerminalID(), terminalID);
				const bool result = exists && responseData.setTerminalID(terminalID);

				return result;
			}

			bool JSONResponseParser::getFieldCfgTerminalID(const Json::Value& object, IResponseData& responseData)
			{
				std::string terminalID;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCfgTerminalID(), terminalID);
				const bool result = exists && responseData.setCfgTerminalID(terminalID);

				return result;
			}

			bool JSONResponseParser::getFieldCardEmvAid(const Json::Value& object, IResponseData& responseData)
			{
				std::string cardEmvAid;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardEmvAid(), cardEmvAid);
				const bool result = exists && responseData.setCardEmvAid(cardEmvAid);

				return result;
			}

			bool JSONResponseParser::getFieldCardAppName(const Json::Value& object, IResponseData& responseData)
			{
				std::string cardAppName;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardAppName(), cardAppName);
				const bool result = exists && responseData.setCardAppName(cardAppName);

				return result;
			}

			bool JSONResponseParser::getFieldCardInputMethod(const Json::Value& object, IResponseData& responseData)
			{
				int cardInputMethod;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardInputMethod(), cardInputMethod);
				const bool result = exists && responseData.setCardInputMethod(static_cast<CardInputMethod>(cardInputMethod));

				return result;
			}

			bool JSONResponseParser::getFieldIssuerName(const Json::Value& object, IResponseData& responseData)
			{
				std::string issuerName;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getIssuerName(), issuerName);
				const bool result = exists && responseData.setIssuerName(issuerName);

				return result;
			}

			bool JSONResponseParser::getFieldAdditionalInfo(const Json::Value& object, IResponseData& responseData)			{
				std::string additionalInfo;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getAdditionalInfo(), additionalInfo);
				const bool result = exists && responseData.setAdditionalInfo(additionalInfo);

				return result;
			}

			bool JSONResponseParser::getFieldCardData(const Json::Value& object, IResponseData& responseData)			{
				std::string cardData;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardData(), cardData);
				const bool result = exists && responseData.setCardData(cardData);

				return result;
			}

			bool JSONResponseParser::getFieldCardDataEnc(const Json::Value& object, IResponseData& responseData)			{
				std::string cardDataEnc;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardDataEnc(), cardDataEnc);
				const bool result = exists && responseData.setCardDataEnc(cardDataEnc);

				return result;
			}

			bool JSONResponseParser::getFieldMerchantID(const Json::Value& object, IResponseData& responseData)			{
				std::string merchantId;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getMerchantID(), merchantId);
				const bool result = exists && responseData.setMerchantID(merchantId);

				return result;
			}

			bool JSONResponseParser::getFieldTVR(const Json::Value& object, IResponseData& responseData)			{
				std::string TVR;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTVR(), TVR);
				const bool result = exists && responseData.setTVR(TVR);

				return result;
			}

			bool JSONResponseParser::getFieldTSI(const Json::Value& object, IResponseData& responseData)			{
				std::string TSI;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTSI(), TSI);
				const bool result = exists && responseData.setTSI(TSI);

				return result;
			}

			bool JSONResponseParser::getFieldTC(const Json::Value& object, IResponseData& responseData)			{
				std::string TC;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTC(), TC);
				const bool result = exists && responseData.setTC(TC);

				return result;
			}

			bool JSONResponseParser::getFieldCID(const Json::Value& object, IResponseData& responseData)			{
				std::string CID;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCID(), CID);
				const bool result = exists && responseData.setCID(CID);

				return result;
			}

			bool JSONResponseParser::getFieldKVR(const Json::Value& object, IResponseData& responseData)			{
				std::string KVR;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getKVR(), KVR);
				const bool result = exists && responseData.setKVR(KVR);

				return result;
			}

			bool JSONResponseParser::getFieldCDAResult(const Json::Value& object, IResponseData& responseData)			{
				std::string CDAResult;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCDAResult(), CDAResult);
				const bool result = exists && responseData.setCDAResult(CDAResult);

				return result;
			}

			bool JSONResponseParser::getFieldSalesAmount(const Json::Value& object, IResponseData& responseData)			{
				int64_t salesAmount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSalesAmount(), salesAmount);
				const bool result = exists && responseData.setSalesAmount(salesAmount);

				return result;
			}

			bool JSONResponseParser::getFieldSalesCount(const Json::Value& object, IResponseData& responseData)			{
				int salesCount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSalesCount(), salesCount);
				const bool result = exists && responseData.setSalesCount(salesCount);

				return result;
			}

			bool JSONResponseParser::getFieldVoidAmount(const Json::Value& object, IResponseData& responseData)			{
				int64_t voidAmount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getVoidAmount(), voidAmount);
				const bool result = exists && responseData.setVoidAmount(voidAmount);

				return result;
			}

			bool JSONResponseParser::getFieldVoidCount(const Json::Value& object, IResponseData& responseData)			{
				int voidCount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getVoidCount(), voidCount);
				const bool result = exists && responseData.setVoidCount(voidCount);

				return result;
			}

			bool JSONResponseParser::getFieldRefundAmount(const Json::Value& object, IResponseData& responseData)			{
				int64_t refundAmount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getRefundAmount(), refundAmount);
				const bool result = exists && responseData.setRefundAmount(refundAmount);

				return result;
			}

			bool JSONResponseParser::getFieldRefundCount(const Json::Value& object, IResponseData& responseData)			{
				int refundCount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getRefundCount(), refundCount);
				const bool result = exists && responseData.setRefundCount(refundCount);

				return result;
			}

			bool JSONResponseParser::getFieldSalesArray(const Json::Value& object, IResponseData& responseData)
			{
				bool result = false;
				Json::Value salesArray;

				std::vector<std::shared_ptr<IResponseData> > sales;
				if (JSONGetFieldHelper::getField(object, JSONResponseFields::getSalesArray(), salesArray))
				{
					if (salesArray.isArray())
					{
						for (auto& i : salesArray)
						{
							auto sale = ResponseDataFactory::getResponseData(OperationCode::ArrayElement);
							if (sale && getFields(i, *sale))
							{
								sale->resetOperationCode();
								sales.push_back(sale);
							}
						} //for

						result = salesArray.size() == sales.size();
						if (result)
						{
							responseData.setSalesArray(sales);
						}
					}
				}

				return result;
			}

			bool JSONResponseParser::getFieldVoidArray(const Json::Value& object, IResponseData& responseData)			{
				bool result = false;
				Json::Value voidArray;

				std::vector<std::shared_ptr<IResponseData> > voids;
				if (JSONGetFieldHelper::getField(object, JSONResponseFields::getVoidArray(), voidArray))				{
					if (voidArray.isArray())					{
						for (auto& i : voidArray)						{
							auto sale = ResponseDataFactory::getResponseData(OperationCode::ArrayElement);
							if (sale && getFields(i, *sale))							{
								sale->resetOperationCode();
								voids.push_back(sale);
							}
						} //for

						result = voidArray.size() == voids.size();
						if (result)						{
							responseData.setVoidArray(voids);
						}
					}
				}

				return result;
			}

			bool JSONResponseParser::getFieldRefundArray(const Json::Value& object, IResponseData& responseData)			{
				bool result = false;
				Json::Value refundArray;

				std::vector<std::shared_ptr<IResponseData> > refunds;
				if (JSONGetFieldHelper::getField(object, JSONResponseFields::getRefundArray(), refundArray))				{
					if (refundArray.isArray())					{
						for (auto& i : refundArray)						{
							auto sale = ResponseDataFactory::getResponseData(OperationCode::ArrayElement);
							if (sale && getFields(i, *sale))							{
								sale->resetOperationCode();
								refunds.push_back(sale);
							}
						} //for

						result = refundArray.size() == refunds.size();
						if (result)						{
							responseData.setRefundArray(refunds);
						}
					}
				}

				return result;
			}

			bool JSONResponseParser::getFieldCardPANHash(const Json::Value& object, IResponseData& responseData)			{
				std::string cardPanHash;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getCardPANHash(), cardPanHash);
				const bool result = exists && responseData.setCardPANHash(cardPanHash);

				return result;
			}

			bool JSONResponseParser::getFieldReceiptLine1(const Json::Value& object, IResponseData& responseData)			{
				std::string receiptLine;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getReceiptLine1(), receiptLine);
				const bool result = exists && responseData.setReceiptLine1(receiptLine);

				return result;
			}

			bool JSONResponseParser::getFieldReceiptLine2(const Json::Value& object, IResponseData& responseData)			{
				std::string receiptLine;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getReceiptLine2(), receiptLine);
				const bool result = exists && responseData.setReceiptLine2(receiptLine);

				return result;
			}

			bool JSONResponseParser::getFieldReceiptLine3(const Json::Value& object, IResponseData& responseData)			{
				std::string receiptLine;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getReceiptLine3(), receiptLine);
				const bool result = exists && responseData.setReceiptLine3(receiptLine);

				return result;
			}

			bool JSONResponseParser::getFieldReceiptLine4(const Json::Value& object, IResponseData& responseData)			{
				std::string receiptLine;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getReceiptLine4(), receiptLine);
				const bool result = exists && responseData.setReceiptLine4(receiptLine);

				return result;
			}

			bool JSONResponseParser::getFieldReceiptLine5(const Json::Value& object, IResponseData& responseData)			{
				std::string receiptLine;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getReceiptLine5(), receiptLine);
				const bool result = exists && responseData.setReceiptLine5(receiptLine);

				return result;
			}

			bool JSONResponseParser::getFieldApplicationLabel(const Json::Value& object, IResponseData& responseData)			{
				std::string applicationLabel;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getApplicationLabel(), applicationLabel);
				const bool result = exists && responseData.setApplicationLabel(applicationLabel);

				return result;
			}

			bool JSONResponseParser::getFieldBonusBalance(const Json::Value& object, IResponseData& responseData)			{
				int64_t bonusBalance;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getBonusBalance(), bonusBalance);
				const bool result = exists && responseData.setBonusBalance(bonusBalance);

				return result;
			}

			bool JSONResponseParser::getFieldBonusAmount(const Json::Value& object, IResponseData& responseData)			{
				int64_t bonusAmount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getBonusAmount(), bonusAmount);
				const bool result = exists && responseData.setBonusAmount(bonusAmount);

				return result;
			}

			bool JSONResponseParser::getFieldHashCardTrack2(const Json::Value& object, IResponseData& responseData)			{
				std::string hashCardTrack2;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getHashCardTrack2(), hashCardTrack2);
				const bool result = exists && responseData.setHashCardTrack2(hashCardTrack2);

				return result;
			}

			bool JSONResponseParser::getFieldFinalizationRequired(const Json::Value& object, IResponseData& responseData)
			{
				bool finalizationRequired;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getFinalizationRequired(), finalizationRequired);
				const bool result = exists && responseData.setFinalizationRequired(finalizationRequired);

				return result;
			}

			bool JSONResponseParser::getFieldAdditionalChoiceResult(const Json::Value& object, IResponseData& responseData)
			{
				int64_t choiceResult;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getAdditionalChoiceResult(), choiceResult);
				const bool result = exists && responseData.setFinalizationRequired(choiceResult);

				return result;
			}

			bool JSONResponseParser::getFieldTransportControlDateTime(const Json::Value& object, IResponseData& responseData)
			{
				std::string transportControlDateTime;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTransportControlDateTime(), transportControlDateTime);
				const bool result = exists && responseData.setTransportControlDateTime(transportControlDateTime);

				return result;
			}

			bool JSONResponseParser::getFieldECertAmount(const Json::Value& object, IResponseData& responseData)
			{
				int64_t amount;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getTotalAmount(), amount);
				const bool result = exists && responseData.setECertAmount(amount);

				return result;
			}

			bool JSONResponseParser::getFieldBasketID(const Json::Value& object, IResponseData& responseData)
			{
				std::string id;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getBasketID(), id);
				const bool result = exists && responseData.setBasketID(id);

				return result;
			}

			bool JSONResponseParser::getFieldSBP_RN(const Json::Value& object, IResponseData& responseData)
			{
				std::string SBP_RN;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSBP_RN(), SBP_RN);
				const bool result = exists && responseData.setSBP_RN(SBP_RN);

				return result;
			}

			bool JSONResponseParser::getFieldQRCode(const Json::Value& object, IResponseData& responseData)
			{
				std::string QRCode;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getQRCode(), QRCode);
				const bool result = exists && responseData.setQRCode(QRCode);

				return result;
			}

			bool JSONResponseParser::getFieldSBP_KZO(const Json::Value& object, IResponseData& responseData)
			{
				std::string SBP_KZO;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSBP_KZO(), SBP_KZO);
				const bool result = exists && responseData.setSBP_KZO(SBP_KZO);

				return result;
			}

			bool JSONResponseParser::getFieldSBP_ReqId(const Json::Value& object, IResponseData& responseData)
			{
				std::string SBP_ReqId;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSBP_ReqId(), SBP_ReqId);
				const bool result = exists && responseData.setSBP_ReqId(SBP_ReqId);

				return result;
			}

			bool JSONResponseParser::getFieldSBP_Code(const Json::Value& object, IResponseData& responseData)
			{
				std::string SBP_Code;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSBP_Code(), SBP_Code);
				const bool result = exists && responseData.setSBP_Code(SBP_Code);

				return result;
			}

			bool JSONResponseParser::getFieldSBP_Status(const Json::Value& object, IResponseData& responseData)
			{
				std::string SBP_Status;
				const bool exists = JSONGetFieldHelper::getField(object, JSONResponseFields::getSBP_Status(), SBP_Status);
				const bool result = exists && responseData.setSBP_Status(SBP_Status);

				return result;
			}

			void JSONResponseParser::initFunctionsMap()
			{
				m_ExtractFunctions[ResponseField::EcrNumber] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldEcrNumber(object, responseData); };
				m_ExtractFunctions[ResponseField::EcrMerchantNumber] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldEcrMerchantNumber(object, responseData); };
				m_ExtractFunctions[ResponseField::OperationCode] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldOperationCode(object, responseData); };
				m_ExtractFunctions[ResponseField::OriginalOperationCode] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldOriginalOperationCode(object, responseData); };
				m_ExtractFunctions[ResponseField::TotalAmount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTotalAmount(object, responseData); };
				m_ExtractFunctions[ResponseField::PartialAmount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldPartialAmount(object, responseData); };
				m_ExtractFunctions[ResponseField::AcquirerFeeAmount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldAcquirerFeeAmount(object, responseData); };
				m_ExtractFunctions[ResponseField::TerminalFeeAmount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTerminalFeeAmount(object, responseData); };
				m_ExtractFunctions[ResponseField::TipsAmount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTipsAmount(object, responseData); };
				m_ExtractFunctions[ResponseField::CurrencyCode] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCurrencyCode(object, responseData); };
				m_ExtractFunctions[ResponseField::ReceiptReference] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldReceiptReference(object, responseData); };
				m_ExtractFunctions[ResponseField::RRN] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldRRN(object, responseData); };
				m_ExtractFunctions[ResponseField::Status] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldStatus(object, responseData); };
				m_ExtractFunctions[ResponseField::OriginalOperationStatus] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldOriginalOperationStatus(object, responseData); };
				m_ExtractFunctions[ResponseField::TransDateTime] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTransDateTime(object, responseData); };
				m_ExtractFunctions[ResponseField::TerminalDateTime] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTerminalDateTime(object, responseData); };
				m_ExtractFunctions[ResponseField::CardPAN] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCardPAN(object, responseData); };
				m_ExtractFunctions[ResponseField::ExpireDate] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldExpireDate(object, responseData); };
				m_ExtractFunctions[ResponseField::CardholderName] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCardholderName(object, responseData); };
				m_ExtractFunctions[ResponseField::CardholderAuthMethod] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCardholderAuthMethod(object, responseData); };
				m_ExtractFunctions[ResponseField::AuthCode] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldAuthCode(object, responseData); };
				m_ExtractFunctions[ResponseField::ResponseCode] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldResponseCode(object, responseData); };
				m_ExtractFunctions[ResponseField::ResponseText] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldResponseText(object, responseData); };
				m_ExtractFunctions[ResponseField::STAN] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldSTAN(object, responseData); };
				m_ExtractFunctions[ResponseField::TransactionID] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTransactionID(object, responseData); };
				m_ExtractFunctions[ResponseField::TerminalID] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTerminalID(object, responseData); };
				m_ExtractFunctions[ResponseField::CfgTerminalID] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCfgTerminalID(object, responseData); };
				m_ExtractFunctions[ResponseField::CardEmvAid] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCardEmvAid(object, responseData); };
				m_ExtractFunctions[ResponseField::CardAppName] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCardAppName(object, responseData); };
				m_ExtractFunctions[ResponseField::CardInputMethod] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCardInputMethod(object, responseData); };
				m_ExtractFunctions[ResponseField::IssuerName] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldIssuerName(object, responseData); };
				m_ExtractFunctions[ResponseField::AdditionalInfo] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldAdditionalInfo(object, responseData); };
				m_ExtractFunctions[ResponseField::CardData] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCardData(object, responseData); };
				m_ExtractFunctions[ResponseField::CardDataEnc] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCardDataEnc(object, responseData); };
				m_ExtractFunctions[ResponseField::MerchantID] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldMerchantID(object, responseData); };
				m_ExtractFunctions[ResponseField::TVR] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTVR(object, responseData); };
				m_ExtractFunctions[ResponseField::TSI] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTSI(object, responseData); };
				m_ExtractFunctions[ResponseField::TC] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTC(object, responseData); };
				m_ExtractFunctions[ResponseField::CID] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCID(object, responseData); };
				m_ExtractFunctions[ResponseField::KVR] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldKVR(object, responseData); };
				m_ExtractFunctions[ResponseField::CDAResult] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCDAResult(object, responseData); };
				m_ExtractFunctions[ResponseField::SalesAmount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldSalesAmount(object, responseData); };
				m_ExtractFunctions[ResponseField::SalesCount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldSalesCount(object, responseData); };
				m_ExtractFunctions[ResponseField::VoidAmount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldVoidAmount(object, responseData); };
				m_ExtractFunctions[ResponseField::VoidCount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldVoidCount(object, responseData); };
				m_ExtractFunctions[ResponseField::RefundAmount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldRefundAmount(object, responseData); };
				m_ExtractFunctions[ResponseField::RefundCount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldRefundCount(object, responseData); };
				m_ExtractFunctions[ResponseField::SalesArray] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldSalesArray(object, responseData); };
				m_ExtractFunctions[ResponseField::VoidArray] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldVoidArray(object, responseData); };
				m_ExtractFunctions[ResponseField::RefundArray] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldRefundArray(object, responseData); };

				m_ExtractFunctions[ResponseField::CardPANHash] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldCardPANHash(object, responseData); };
				m_ExtractFunctions[ResponseField::ReceiptLine1] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldReceiptLine1(object, responseData); };
				m_ExtractFunctions[ResponseField::ReceiptLine2] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldReceiptLine2(object, responseData); };
				m_ExtractFunctions[ResponseField::ReceiptLine3] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldReceiptLine3(object, responseData); };
				m_ExtractFunctions[ResponseField::ReceiptLine4] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldReceiptLine4(object, responseData); };
				m_ExtractFunctions[ResponseField::ReceiptLine5] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldReceiptLine5(object, responseData); };
				m_ExtractFunctions[ResponseField::ApplicationLabel] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldApplicationLabel(object, responseData); };
				m_ExtractFunctions[ResponseField::BonusBalance] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldBonusBalance(object, responseData); };
				m_ExtractFunctions[ResponseField::BonusAmount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldBonusAmount(object, responseData); };
				m_ExtractFunctions[ResponseField::HashCardTrack2] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldHashCardTrack2(object, responseData); };
				m_ExtractFunctions[ResponseField::FinalizationRequired] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldFinalizationRequired(object, responseData); };
				m_ExtractFunctions[ResponseField::AdditionalChoiceResult] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldAdditionalChoiceResult(object, responseData); };
				m_ExtractFunctions[ResponseField::ECertAmount] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldECertAmount(object, responseData); };
				m_ExtractFunctions[ResponseField::BasketID] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldBasketID(object, responseData); };
				
				m_ExtractFunctions[ResponseField::SBP_RN] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldSBP_RN(object, responseData); };
				m_ExtractFunctions[ResponseField::QRCode] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldQRCode(object, responseData); };
				m_ExtractFunctions[ResponseField::SBP_KZO] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldSBP_KZO(object, responseData); };
				m_ExtractFunctions[ResponseField::SBP_ReqId] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldSBP_ReqId(object, responseData); };
				m_ExtractFunctions[ResponseField::SBP_Code] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldSBP_Code(object, responseData); };
				m_ExtractFunctions[ResponseField::SBP_Status] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldSBP_Status(object, responseData); };

				m_ExtractFunctions[ResponseField::TransportControlDateTime] = [this](const Json::Value& object, IResponseData& responseData) { return getFieldTransportControlDateTime(object, responseData); };
			}

			bool JSONResponseParser::getFields(const Json::Value& object, IResponseData& responseData)
			{
				if (responseData.isFieldSet(ResponseField::OperationCode) || getFieldOperationCode(object, responseData))
				{
					for (auto field : responseData.getMandatoryFields())
					{
						auto function = m_ExtractFunctions.at(field);
						function(object, responseData);
					}

					for (auto field : responseData.getOptionalFields())
					{
						auto function = m_ExtractFunctions.at(field);
						function(object, responseData);
					}
				}

				return responseData.validateMandatoryFields();
			}//bool JSONResponseParser::getFields
		}
	}
}