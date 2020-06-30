//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "Lanter/Response/ResponseDataFactory.h"
#include "Lanter/Response/ResponseData.h"

namespace Lanter {
    namespace Response {

        std::shared_ptr<IResponseData>
        ResponseDataFactory::getResponseData(OperationCodes operationCode, int16_t ecrNumber) {
            auto data = std::make_shared<ResponseData>();
            if(data) {
                data->setOperationCode(operationCode);
                data->setEcrNumber(ecrNumber);
            }
            return data;
        }
    }
}