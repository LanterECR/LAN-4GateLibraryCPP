//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "Lanter/Request/RequestDataFactory.h"

#include "Lanter/Request/RequestData.h"

namespace Lanter {
    namespace Request {

        std::shared_ptr<IRequestData>
        RequestDataFactory::getRequestData(OperationCodes operationCode, int16_t ecrNumber) {
            auto data = std::make_shared<RequestData>();
            if(data) {
                data->setOperationCode(operationCode);
                data->setEcrNumber(ecrNumber);
            }
            return data;
        }
    }
}