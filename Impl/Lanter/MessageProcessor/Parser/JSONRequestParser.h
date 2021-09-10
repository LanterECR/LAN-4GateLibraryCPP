#ifndef LAN_4GATELIBRARYCPP_JSONREQUESTPARSER_H
#define LAN_4GATELIBRARYCPP_JSONREQUESTPARSER_H

#include <functional>
#include <memory>

#include "json/json.h"

#include "Lanter/Message/Request/IRequestData.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            using namespace Message;
            using namespace Message::Request;

            class JSONRequestParser {
            public:
                JSONRequestParser();

                std::shared_ptr<IRequestData> parseData(const Json::Value &object);

                const std::map<RequestField, std::function<bool(const Json::Value &, IRequestData &)> > &
                getFunctions() const;

                bool getFieldEcrNumber(const Json::Value &object, IRequestData &requestData);

                bool getFieldEcrMerchantNumber(const Json::Value &object, IRequestData &requestData);

                bool getFieldOperationCode(const Json::Value &object, IRequestData &requestData);

                bool getFieldAmount(const Json::Value &object, IRequestData &requestData);

                bool getFieldPartialAmount(const Json::Value &object, IRequestData &requestData);

                bool getFieldTipsAmount(const Json::Value &object, IRequestData &requestData);

                bool getFieldCashbackAmount(const Json::Value &object, IRequestData &requestData);

                bool getFieldCurrencyCode(const Json::Value &object, IRequestData &requestData);

                bool getFieldRRN(const Json::Value &object, IRequestData &requestData);

                bool getFieldAuthCode(const Json::Value &object, IRequestData &requestData);

                bool getFieldReceiptReference(const Json::Value &object, IRequestData &requestData);

                bool getFieldTransactionID(const Json::Value &object, IRequestData &requestData);

                bool getFieldCardDataEnc(const Json::Value &object, IRequestData &requestData);

                bool getFieldOpenTags(const Json::Value &object, IRequestData &requestData);

                bool getFieldEncTags(const Json::Value &object, IRequestData &requestData);

                bool getFieldProviderCode(const Json::Value &object, IRequestData &requestData);

                bool getFieldAdditionalInfo(const Json::Value &object, IRequestData &requestData);

            private:
                void initFunctionsMap();

                bool getFields(const Json::Value &object, IRequestData &requestData);

                std::map<RequestField, std::function<bool(const Json::Value &, IRequestData &)> > m_ExtractFunctions;
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_JSONREQUESTPARSER_H
