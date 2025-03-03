#include "Lanter/Message/Gateway/GatewayData.h"
#include "Lanter/Message/Gateway/GatewayDataFactory.h"

namespace Lanter
{
    namespace Message
    {
        namespace Gateway
        {
            std::shared_ptr<IGatewayData> GatewayDataFactory::getGatewayData(GatewayCode code)
            {
                auto gateway = std::make_shared<GatewayData>();
                if(gateway != nullptr)
                {
                    gateway->setCode(code);
                }

                return gateway;
            }

            std::shared_ptr <IGatewayData> GatewayDataFactory::getGatewayData()
            {
                return getGatewayData(GatewayCode::NoCode);
            } //getGatewayData()
        }//namespace Gateway
    }//namespace Message
}//namespace Lanter