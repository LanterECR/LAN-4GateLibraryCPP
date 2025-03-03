#ifndef LAN_4GATELIBRARYCPP_GatewayCode_H
#define LAN_4GATELIBRARYCPP_GatewayCode_H

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter
{
    namespace Message
    {
        namespace Gateway
        {
            /// \brief Список поддерживаемых видов команд шлюза
            enum class GatewayCode
            {
                NoCode,     ///< Значение по умолчанию.
                Connect,    ///< Открыть соединение
                Disconnect, ///< Закрыть соединение
                Exchange    ///< Отправка/Прием данных
            };//enum GatewayCode

            /// Функция, возвращающая первый значимый элемент перечисления GatewayCode
            /// \return Первый элемент значимый перечисления GatewayCode
            constexpr GatewayCode getFirstGatewayCode()
            {
                return GatewayCode::Connect;
            }

            /// Функция, возвращающая последний значимый элемент перечисления GatewaynCode
            /// \return Последний элемент значимый перечисления GatewayCode
            constexpr GatewayCode getLastGatewayCode()
            {
                return GatewayCode::Exchange;
            }
        }//namespace Gateway
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_GatewayCode_H