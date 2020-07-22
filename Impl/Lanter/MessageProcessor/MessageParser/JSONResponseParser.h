//
// Created by Владимир Лысенков on 19.07.2020.
//

#ifndef LAN_4GATELIB_JSONRESPONSEPARSER_H
#define LAN_4GATELIB_JSONRESPONSEPARSER_H


#include <functional>
#include <memory>

#include "json/json.h"

#include "Lanter/Message/Response/IResponseData.h"

namespace Lanter {
    namespace MessageProcessor {
        using namespace Message;
        using namespace Message::Response;
        class JSONResponseParser {
        public:
            JSONResponseParser();
            std::shared_ptr<IResponseData> parseData(const Json::Value & object);

            const std::map<ResponseFields, std::function<bool(const Json::Value&,IResponseData&)> > & getFunctions() const;
            bool getFieldEcrNumber(const Json::Value & object, IResponseData & requestData);
            bool getFieldEcrMerchantNumber(const Json::Value & object, IResponseData & requestData);
            bool getFieldOperationCode(const Json::Value & object, IResponseData & requestData);
            bool getFieldOriginalOperationCode(const Json::Value & object, IResponseData & requestData);
            bool getFieldTotalAmount(const Json::Value & object, IResponseData & requestData);
            bool getFieldPartialAmount(const Json::Value & object, IResponseData & requestData);
            bool getFieldAcquirerFeeAmount(const Json::Value & object, IResponseData & requestData);
            bool getFieldTerminalFeeAmount(const Json::Value & object, IResponseData & requestData);
            bool getFieldTipsAmount(const Json::Value & object, IResponseData & requestData);
            bool getFieldCurrencyCode(const Json::Value & object, IResponseData & requestData);
            bool getFieldReceiptReference(const Json::Value & object, IResponseData & requestData);
            bool getFieldRRN(const Json::Value & object, IResponseData & requestData);
            bool getFieldStatus(const Json::Value & object, IResponseData & requestData);
            bool getFieldOriginalOperationStatus(const Json::Value & object, IResponseData & requestData);
            bool getFieldTransDateTime(const Json::Value & object, IResponseData & requestData);
            bool getFieldTerminalDateTime(const Json::Value & object, IResponseData & requestData);
            bool getFieldCardPAN(const Json::Value & object, IResponseData & requestData);
            bool getFieldExpireDate(const Json::Value & object, IResponseData & requestData);
            bool getFieldCardholderName(const Json::Value & object, IResponseData & requestData);
            bool getFieldCardholderAuthMethod(const Json::Value & object, IResponseData & requestData);
            bool getFieldAuthCode(const Json::Value & object, IResponseData & requestData);
            bool getFieldResponseCode(const Json::Value & object, IResponseData & requestData);
            bool getFieldResponseText(const Json::Value & object, IResponseData & requestData);
            bool getFieldSTAN(const Json::Value & object, IResponseData & requestData);
            bool getFieldTransactionID(const Json::Value & object, IResponseData & requestData);
            bool getFieldTerminalID(const Json::Value & object, IResponseData & requestData);
            bool getFieldCardEmvAid(const Json::Value & object, IResponseData & requestData);
            bool getFieldCardAppName(const Json::Value & object, IResponseData & requestData);
            bool getFieldCardInputMethod(const Json::Value & object, IResponseData & requestData);
            bool getFieldIssuerName(const Json::Value & object, IResponseData & requestData);
            bool getFieldAdditionalInfo(const Json::Value & object, IResponseData & requestData);
            bool getFieldCardData(const Json::Value & object, IResponseData & requestData);
            bool getFieldCardDataEnc(const Json::Value & object, IResponseData & requestData);
            bool getFieldMerchantID(const Json::Value & object, IResponseData & requestData);
            bool getFieldTVR(const Json::Value & object, IResponseData & requestData);
            bool getFieldTSI(const Json::Value & object, IResponseData & requestData);
            bool getFieldTC(const Json::Value & object, IResponseData & requestData);
            bool getFieldCID(const Json::Value & object, IResponseData & requestData);
            bool getFieldKVR(const Json::Value & object, IResponseData & requestData);
            bool getFieldCDAResult(const Json::Value & object, IResponseData & requestData);
            bool getFieldSalesCount(const Json::Value & object, IResponseData & requestData);
            bool getFieldVoidCount(const Json::Value & object, IResponseData & requestData);
            bool getFieldRefundCount(const Json::Value & object, IResponseData & requestData);
            bool getFieldSalesArray(const Json::Value & object, IResponseData & requestData);
            bool getFieldVoidArray(const Json::Value & object, IResponseData & requestData);
            bool getFieldRefundArray(const Json::Value & object, IResponseData & requestData);
        private:
            void initFunctionsMap();
            bool getFields(const Json::Value &object, IResponseData &requestData);

            std::map<ResponseFields, std::function<bool(const Json::Value&,IResponseData&)> > m_ExtractFunctions;
        };
    }
}


#endif //LAN_4GATELIB_JSONRESPONSEPARSER_H
