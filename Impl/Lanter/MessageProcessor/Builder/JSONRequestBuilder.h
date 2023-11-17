#ifndef LAN_4GATELIBRARYCPP_JSONREQUESTBUILDER_H
#define LAN_4GATELIBRARYCPP_JSONREQUESTBUILDER_H

#include <map>
#include <functional>
#include "json/json.h"
#include "Lanter/Message/Request/RequestField.h"
#include "Lanter/Message/Request/IRequestData.h"

namespace Lanter
{
    using namespace Message;
    using namespace Message::Request;

    namespace MessageProcessor
    {
        namespace Builder
        {
            class JSONRequestBuilder
            {
            public:
                JSONRequestBuilder();

                bool createObject(const IRequestData &requestData, Json::Value &object);

                const std::map<RequestField, std::function<bool(const IRequestData &, Json::Value &)>> &
                getFunctions() const;

                bool addFieldEcrNumber(const IRequestData &requestData, Json::Value &object);

                bool addFieldEcrMerchantNumber(const IRequestData &requestData, Json::Value &object);

                bool addFieldOperationCode(const IRequestData &requestData, Json::Value &object);

                bool addFieldAmount(const IRequestData &requestData, Json::Value &object);

                bool addFieldPartialAmount(const IRequestData &requestData, Json::Value &object);

                bool addFieldTipsAmount(const IRequestData &requestData, Json::Value &object);

                bool addFieldCashbackAmount(const IRequestData &requestData, Json::Value &object);

                bool addFieldCurrencyCode(const IRequestData &requestData, Json::Value &object);

                bool addFieldRRN(const IRequestData &requestData, Json::Value &object);

                bool addFieldAuthCode(const IRequestData &requestData, Json::Value &object);

                bool addFieldReceiptReference(const IRequestData &requestData, Json::Value &object);

                bool addFieldTransactionID(const IRequestData &requestData, Json::Value &object);

                bool addFieldCardDataEnc(const IRequestData &requestData, Json::Value &object);

                bool addFieldOpenTags(const IRequestData &requestData, Json::Value &object);

                bool addFieldEncTags(const IRequestData &requestData, Json::Value &object);

                bool addFieldSBP_RN(const IRequestData& requestData, Json::Value& object);

                bool addFieldSBP_ReqID(const IRequestData& requestData, Json::Value& object);

                bool addFieldPaymentPurpose(const IRequestData& requestData, Json::Value& object);

                bool addFieldProviderCode(const IRequestData &requestData, Json::Value &object);

                bool addFieldAdditionalInfo(const IRequestData &requestData, Json::Value &object);

                bool addFieldBonusBalance(const IRequestData &requestData, Json::Value &object);

                bool addFieldBonusAmount(const IRequestData &requestData, Json::Value &object);

                bool addFieldHashCardTrack2(const IRequestData &requestData, Json::Value &object);

                bool addFieldPaymentProviderCode(const IRequestData &requestData, Json::Value &object);

                bool addFieldPaymentParam1(const IRequestData &requestData, Json::Value &object);

                bool addFieldPaymentParam2(const IRequestData &requestData, Json::Value &object);

                bool addFieldPaymentParam3(const IRequestData &requestData, Json::Value &object);

                bool addFieldAdditionalChoice(const IRequestData &requestData, Json::Value &object);

                bool addFieldTransportControlStation(const IRequestData& requestData, Json::Value& object);

                bool addFieldTransportControlArea(const IRequestData& requestData, Json::Value& object);

                bool addFieldTransportControlID(const IRequestData& requestData, Json::Value& object);

				bool addFieldCardPANHash(const IRequestData &requestData, Json::Value &object);

				bool addFieldECertAmount(const IRequestData &requestData, Json::Value &object);

				bool addFieldBasketID(const IRequestData &requestData, Json::Value &object);

			private:
                void initFunctionsMap();

                bool addFields(const IRequestData &requestData, Json::Value &object);

                std::map<RequestField, std::function<bool(const IRequestData &, Json::Value &)> > m_InsertFunctions;
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_JSONREQUESTBUILDER_H