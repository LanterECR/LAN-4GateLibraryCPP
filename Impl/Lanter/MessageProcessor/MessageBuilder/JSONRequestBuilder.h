//
// Created by Владимир Лысенков on 09.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_JSONREQUESTBUILDER_H
#define LAN_4GATELIBRARYCPP_JSONREQUESTBUILDER_H

#include <map>
#include <functional>

#include "json/json.h"

#include "Lanter/Message/Request/RequestFields.h"
#include "Lanter/Message/Request/IRequestData.h"

namespace Lanter {
    using namespace Message;
    using namespace Message::Request;
    namespace MessageProcessor {
        class JSONRequestBuilder {
        public:
            JSONRequestBuilder();

            bool createObject(const IRequestData & requestData, Json::Value & object);
            const std::map<RequestFields, std::function<bool(const IRequestData &, Json::Value &)>> & getFunctions() const;
            bool addFieldEcrNumber(const IRequestData & requestData, Json::Value & object);
            bool addFieldEcrMerchantNumber(const IRequestData & requestData, Json::Value & object);
            bool addFieldOperationCode(const IRequestData & requestData, Json::Value & object);
            bool addFieldAmount(const IRequestData & requestData, Json::Value & object);
            bool addFieldPartialAmount(const IRequestData & requestData, Json::Value & object);
            bool addFieldTipsAmount(const IRequestData & requestData, Json::Value & object);
            bool addFieldCashbackAmount(const IRequestData & requestData, Json::Value & object);
            bool addFieldCurrencyCode(const IRequestData & requestData, Json::Value & object);
            bool addFieldRRN(const IRequestData & requestData, Json::Value & object);
            bool addFieldAuthCode(const IRequestData & requestData, Json::Value & object);
            bool addFieldReceiptReference(const IRequestData & requestData, Json::Value & object);
            bool addFieldTransactionID(const IRequestData & requestData, Json::Value & object);
            bool addFieldCardDataEnc(const IRequestData & requestData, Json::Value & object);
            bool addFieldOpenTags(const IRequestData & requestData, Json::Value & object);
            bool addFieldEncTags(const IRequestData & requestData, Json::Value & object);
            bool addFieldProviderCode(const IRequestData & requestData, Json::Value & object);
            bool addFieldAdditionalInfo(const IRequestData & requestData, Json::Value & object);
        private:
            void initFunctionsMap();
            bool addFields(const IRequestData & requestData, Json::Value & object);
            std::map<RequestFields, std::function<bool(const IRequestData &, Json::Value &)> > m_InsertFunctions;
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_JSONREQUESTBUILDER_H
