#ifndef LAN_4GATELIB_JSONRESPONSEPARSER_H
#define LAN_4GATELIB_JSONRESPONSEPARSER_H


#include <functional>
#include <memory>

#include "json/json.h"

#include "Lanter/Message/Response/IResponseData.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            using namespace Message;
            using namespace Message::Response;

            class JSONResponseParser {
            public:
                JSONResponseParser();

                std::shared_ptr<IResponseData> parseData(const Json::Value &object);

                const std::map<ResponseField, std::function<bool(const Json::Value &, IResponseData &)> > &
                getFunctions() const;

                bool getFieldEcrNumber(const Json::Value &object, IResponseData &responseData);

                bool getFieldEcrMerchantNumber(const Json::Value &object, IResponseData &responseData);

                bool getFieldOperationCode(const Json::Value &object, IResponseData &responseData);

                bool getFieldOriginalOperationCode(const Json::Value &object, IResponseData &responseData);

                bool getFieldTotalAmount(const Json::Value &object, IResponseData &responseData);

                bool getFieldPartialAmount(const Json::Value &object, IResponseData &responseData);

                bool getFieldAcquirerFeeAmount(const Json::Value &object, IResponseData &responseData);

                bool getFieldTerminalFeeAmount(const Json::Value &object, IResponseData &responseData);

                bool getFieldTipsAmount(const Json::Value &object, IResponseData &responseData);

                bool getFieldCurrencyCode(const Json::Value &object, IResponseData &responseData);

                bool getFieldReceiptReference(const Json::Value &object, IResponseData &responseData);

                bool getFieldRRN(const Json::Value &object, IResponseData &responseData);

                bool getFieldStatus(const Json::Value &object, IResponseData &responseData);

                bool getFieldOriginalOperationStatus(const Json::Value &object, IResponseData &responseData);

                bool getFieldTransDateTime(const Json::Value &object, IResponseData &responseData);

                bool getFieldTerminalDateTime(const Json::Value &object, IResponseData &responseData);

                bool getFieldCardPAN(const Json::Value &object, IResponseData &responseData);

                bool getFieldExpireDate(const Json::Value &object, IResponseData &responseData);

                bool getFieldCardholderName(const Json::Value &object, IResponseData &responseData);

                bool getFieldCardholderAuthMethod(const Json::Value &object, IResponseData &responseData);

                bool getFieldAuthCode(const Json::Value &object, IResponseData &responseData);

                bool getFieldResponseCode(const Json::Value &object, IResponseData &responseData);

                bool getFieldResponseText(const Json::Value &object, IResponseData &responseData);

                bool getFieldSTAN(const Json::Value &object, IResponseData &responseData);

                bool getFieldTransactionID(const Json::Value &object, IResponseData &responseData);

                bool getFieldTerminalID(const Json::Value &object, IResponseData &responseData);

                bool getFieldCardEmvAid(const Json::Value &object, IResponseData &responseData);

                bool getFieldCardAppName(const Json::Value &object, IResponseData &responseData);

                bool getFieldCardInputMethod(const Json::Value &object, IResponseData &responseData);

                bool getFieldIssuerName(const Json::Value &object, IResponseData &responseData);

                bool getFieldAdditionalInfo(const Json::Value &object, IResponseData &responseData);

                bool getFieldCardData(const Json::Value &object, IResponseData &responseData);

                bool getFieldCardDataEnc(const Json::Value &object, IResponseData &responseData);

                bool getFieldMerchantID(const Json::Value &object, IResponseData &responseData);

                bool getFieldTVR(const Json::Value &object, IResponseData &responseData);

                bool getFieldTSI(const Json::Value &object, IResponseData &responseData);

                bool getFieldTC(const Json::Value &object, IResponseData &responseData);

                bool getFieldCID(const Json::Value &object, IResponseData &responseData);

                bool getFieldKVR(const Json::Value &object, IResponseData &responseData);

                bool getFieldCDAResult(const Json::Value &object, IResponseData &responseData);

                bool getFieldSalesAmount(const Json::Value &object, IResponseData &responseData);

                bool getFieldSalesCount(const Json::Value &object, IResponseData &responseData);

                bool getFieldVoidAmount(const Json::Value &object, IResponseData &responseData);

                bool getFieldVoidCount(const Json::Value &object, IResponseData &responseData);

                bool getFieldRefundAmount(const Json::Value &object, IResponseData &responseData);

                bool getFieldRefundCount(const Json::Value &object, IResponseData &responseData);

                bool getFieldSaleArray(const Json::Value &object, IResponseData &responseData);

                bool getFieldVoidArray(const Json::Value &object, IResponseData &responseData);

                bool getFieldRefundArray(const Json::Value &object, IResponseData &responseData);

                bool getFieldCfgTerminalID(const Json::Value &object, IResponseData &responseData);
                bool getFieldCardPANHash(const Json::Value &object, IResponseData &responseData);

                bool getFieldReceiptLine1(const Json::Value &object, IResponseData &responseData);

                bool getFieldReceiptLine2(const Json::Value &object, IResponseData &responseData);

                bool getFieldReceiptLine3(const Json::Value &object, IResponseData &responseData);

                bool getFieldReceiptLine4(const Json::Value &object, IResponseData &responseData);

                bool getFieldReceiptLine5(const Json::Value &object, IResponseData &responseData);

                bool getFieldApplicationLabel(const Json::Value &object, IResponseData &responseData);

                bool getFieldBonusBalance(const Json::Value &object, IResponseData &responseData);

                bool getFieldBonusAmount(const Json::Value &object, IResponseData &responseData);

                bool getFieldHashCardTrack2(const Json::Value &object, IResponseData &responseData);

                bool getFieldFinalizationRequired(const Json::Value &object, IResponseData &responseData);

                bool getFieldAdditionalChoiceResult(const Json::Value &object, IResponseData &responseData);

				bool getFieldECertAmount(const Json::Value &object, IResponseData &responseData);

				bool getFieldBasketID(const Json::Value &object, IResponseData &responseData);
			private:
                void initFunctionsMap();

                bool getFields(const Json::Value &object, IResponseData &responseData);

                std::map<ResponseField, std::function<bool(const Json::Value &, IResponseData &)> > m_ExtractFunctions;
            };
        }
    }
}


#endif //LAN_4GATELIB_JSONRESPONSEPARSER_H
