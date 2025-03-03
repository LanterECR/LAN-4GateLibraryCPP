#ifndef LAN_4GATELIB_IGATEWAYCALLBACK_H
#define LAN_4GATELIB_IGATEWAYCALLBACK_H

#include <memory>
#include "Lanter/Utils/VisibilityMacroses.h"
#include "Lanter/Message/Gateway/IGatewayData.h"

namespace Lanter
{
    namespace Manager
    {
        namespace Callback
        {
            /// \brief Колбэк для организации шлюза
            class LANTER_VISIBILITY IGatewayCallback
            {
            public:
                virtual ~IGatewayCallback() = default;
                /// \brief Метод, в который будет переданы данные шлюза
                /// \param data данные уведомления
                /// \sa Message::Gateway::IGatewayData
                virtual int newData(std::shared_ptr<Message::Gateway::IGatewayData> data) = 0;
            };
        }
    }
}
#endif //LAN_4GATELIB_IGATEWAYCALLBACK_H