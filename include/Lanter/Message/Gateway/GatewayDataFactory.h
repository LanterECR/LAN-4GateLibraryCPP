#ifndef LAN_4GATELIBRARYCPP_GATEWAYDATAFACTORY_H
#define LAN_4GATELIBRARYCPP_GATEWAYDATAFACTORY_H

#include "IGatewayData.h"
#include "Lanter/Utils/VisibilityMacroses.h"
#include <memory>

namespace Lanter
{
    namespace Message
    {
        namespace Gateway
        {
            /// \brief Фабричный класс, возвращающий объект уведомления
            class LANTER_VISIBILITY GatewayDataFactory
            {
            public:
                /// \brief Возвращает указатель на объект интерфейса IGatewayData и заполняет поле GatewayCode
                /// \param[in] code Код команды
                /// \return Указатель на объект интерфейса IGatewayData
                static std::shared_ptr<IGatewayData> getGatewayData(GatewayCode code);

                /// \brief Возвращает указатель на объект интерфейса IGatewayData
                /// \return Указатель на объект интерфейса IGatewayData
                static std::shared_ptr<IGatewayData> getGatewayData();
            };//class GatewayDataFactory
        }//namespace Gateway
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_GATEWAYDATAFACTORY_H