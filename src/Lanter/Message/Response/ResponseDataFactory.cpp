#include "Lanter/Message/Response/ResponseDataFactory.h"
#include "Lanter/Message/Response/ResponseData.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            std::shared_ptr<IResponseData> ResponseDataFactory::getResponseData(OperationCode operationCode, int16_t ecrNumber)
            {
                auto data = std::make_shared<ResponseData>();
                const bool isNoOperation = operationCode == OperationCode::NoOperation;

                if (data)
                {
                    bool result = data->setOperationCode(operationCode) || isNoOperation;

                    if(ecrNumber != -1)
                    {
                        result = result && data->setEcrNumber(ecrNumber);
                    }//if ecrNumber

                    if(!result)
                    {
                        data.reset();
                    }//if result

                }//if data

                return data;
            }//getResponseData()
        }//namespace Response
    }//namespace Message
}//namespace Lanter