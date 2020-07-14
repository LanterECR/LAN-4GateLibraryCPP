//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "Lanter/Message/Request/RequestDataFactory.h"

#include "Lanter/Message/Request/RequestData.h"

namespace Lanter {
    namespace Message {
        namespace Request {

            std::shared_ptr<IRequestData>
            RequestDataFactory::getRequestData(OperationCodes operationCode, int16_t ecrNumber) {
                auto data = std::make_shared<RequestData>();
                bool result = false;
                if (data) {
                    result = data->setOperationCode(operationCode);
                    if(ecrNumber != -1) {
                        result = result && data->setEcrNumber(ecrNumber);
                    }
                    if(!result) {
                        data.reset();
                    }
                }
                return data;
            }
        }
    }
}