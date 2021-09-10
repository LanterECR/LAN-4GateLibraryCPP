#include "Lanter/Message/Request/RequestDataFactory.h"

#include "Lanter/Message/Request/RequestData.h"

namespace Lanter {
    namespace Message {
        namespace Request {

            std::shared_ptr<IRequestData>
            RequestDataFactory::getRequestData(OperationCode operationCode, int16_t ecrNumber) {
                auto data = std::make_shared<RequestData>();

                bool result = false;

                bool isNoOperation = operationCode == OperationCode::NoOperation;

                if (data) {

                    result = data->setOperationCode(operationCode) || isNoOperation;

                    if(ecrNumber != -1) {
                        result = result && data->setEcrNumber(ecrNumber);
                    }//if ecrNumber

                    if(!result) {
                        data.reset();
                    }//if result

                }//if data
                return data;
            }//getRequestData()
        }//namespace Request
    }//namespace Message
}//namespace Lanter
