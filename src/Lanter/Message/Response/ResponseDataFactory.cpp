//
// Created by Владимир Лысенков on 24.06.2020.
//

#include "Lanter/Message/Response/ResponseDataFactory.h"
#include "Lanter/Message/Response/ResponseData.h"

namespace Lanter {
    namespace Message {
        namespace Response {

            std::shared_ptr<IResponseData>
            ResponseDataFactory::getResponseData(OperationCodes operationCode, int16_t ecrNumber) {
                auto data = std::make_shared<ResponseData>();
                if (data) {
                    data->setOperationCode(operationCode);
                    if(ecrNumber != -1) {
                        data->setEcrNumber(ecrNumber);
                    }
                }
                return data;
            }
        }
    }
}