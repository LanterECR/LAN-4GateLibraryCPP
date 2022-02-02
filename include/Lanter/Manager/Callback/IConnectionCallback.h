#ifndef LAN_4GATELIB_ICONNECTIONCALLBACK_H
#define LAN_4GATELIB_ICONNECTIONCALLBACK_H

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Manager {
        namespace Callback {
            /// \brief Колбэк для приема состояния соединения
            class LANTER_VISIBILITY IConnectionCallback {
            public:
                    virtual ~IConnectionCallback() = default;
                    /// \brief Метод, в который будет передано новое состояние соединения
                    /// \param state Состояние соединения. true - связь между терминалом и кассой установлена
                    virtual void newState(bool state) = 0;
            };
        }
    }
}

#endif //LAN_4GATELIB_ICONNECTIONCALLBACK_H
