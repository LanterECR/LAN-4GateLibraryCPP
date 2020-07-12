//
// Created by Владимир Лысенков on 12.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_JSONRESPONSEBUILDER_H
#define LAN_4GATELIBRARYCPP_JSONRESPONSEBUILDER_H

#include <map>
#include <functional>

#include "json/json.h"

#include "Lanter/Message/Response/ResponseFields.h"
#include "Lanter/Message/Response/IResponseData.h"

namespace Lanter {
    using namespace Message;
    using namespace Message::Response;
    namespace MessageProcessor {
        class JSONResponseBuilder {
        public:
            JSONResponseBuilder();

            bool createObject(const IResponseData & responseData, Json::Value & object);
            const std::map<ResponseFields, std::function<bool(const IResponseData &, Json::Value &)>> & getFunctions() const;

            bool addFieldEcrNumber(const IResponseData & responseData, Json::Value & object);
            bool addFieldEcrMerchantNumber(const IResponseData & responseData, Json::Value & object);
            bool addFieldOperationCode(const IResponseData & responseData, Json::Value & object);
            bool addFieldOriginalOperationCode(const IResponseData & responseData, Json::Value & object);
            bool addFieldTotalAmount(const IResponseData & responseData, Json::Value & object);
            bool addFieldPartialAmount(const IResponseData & responseData, Json::Value & object);
            bool addFieldAcquirerFeeAmount(const IResponseData & responseData, Json::Value & object);
            bool addFieldTerminalFeeAmount(const IResponseData & responseData, Json::Value & object);
            bool addFieldTipsAmount(const IResponseData & responseData, Json::Value & object);
            bool addFieldCurrencyCode(const IResponseData & responseData, Json::Value & object);
            bool addFieldReceiptReference(const IResponseData & responseData, Json::Value & object);
            bool addFieldRRN(const IResponseData & responseData, Json::Value & object);
            bool addFieldStatus(const IResponseData & responseData, Json::Value & object);
            bool addFieldOriginalOperationStatus(const IResponseData & responseData, Json::Value & object);
            bool addFieldTransDateTime(const IResponseData & responseData, Json::Value & object);
            bool addFieldTerminalDateTime(const IResponseData & responseData, Json::Value & object);
            bool addFieldCardPAN(const IResponseData & responseData, Json::Value & object);
            bool addFieldExpireDate(const IResponseData & responseData, Json::Value & object);
            bool addFieldCardholderName(const IResponseData & responseData, Json::Value & object);
            bool addFieldCardholderAuthMethod(const IResponseData & responseData, Json::Value & object);
            bool addFieldAuthCode(const IResponseData & responseData, Json::Value & object);
            bool addFieldResponseCode(const IResponseData & responseData, Json::Value & object);
            bool addFieldResponseText(const IResponseData & responseData, Json::Value & object);
            bool addFieldSTAN(const IResponseData & responseData, Json::Value & object);
            bool addFieldTransactionID(const IResponseData & responseData, Json::Value & object);
            bool addFieldTerminalID(const IResponseData & responseData, Json::Value & object);
            bool addFieldCardEmvAid(const IResponseData & responseData, Json::Value & object);
            bool addFieldCardAppName(const IResponseData & responseData, Json::Value & object);
            bool addFieldCardInputMethod(const IResponseData & responseData, Json::Value & object);
            bool addFieldIssuerName(const IResponseData & responseData, Json::Value & object);
            bool addFieldAdditionalInfo(const IResponseData & responseData, Json::Value & object);
            bool addFieldCardData(const IResponseData & responseData, Json::Value & object);
            bool addFieldCardDataEnc(const IResponseData & responseData, Json::Value & object);
            bool addFieldMerchantID(const IResponseData & responseData, Json::Value & object);
            bool addFieldTVR(const IResponseData & responseData, Json::Value & object);
            bool addFieldTSI(const IResponseData & responseData, Json::Value & object);
            bool addFieldTC(const IResponseData & responseData, Json::Value & object);
            bool addFieldCID(const IResponseData & responseData, Json::Value & object);
            bool addFieldKVR(const IResponseData & responseData, Json::Value & object);
            bool addFieldCDAResult(const IResponseData & responseData, Json::Value & object);
            bool addFieldSalesCount(const IResponseData & responseData, Json::Value & object);
            bool addFieldVoidCount(const IResponseData & responseData, Json::Value & object);
            bool addFieldRefundCount(const IResponseData & responseData, Json::Value & object);
            bool addFieldSalesArray(const IResponseData & responseData, Json::Value & object);
            bool addFieldVoidArray(const IResponseData & responseData, Json::Value & object);
            bool addFieldRefundArray(const IResponseData & responseData, Json::Value & object);
            
        private:
            void initFunctionsMap();
            bool addFields(const IResponseData & responseData, Json::Value & object);
            std::map<ResponseFields, std::function<bool(const IResponseData &, Json::Value &)> > m_InsertFunctions;
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONRESPONSEBUILDER_H
