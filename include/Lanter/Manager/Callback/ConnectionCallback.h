#ifndef LAN_4GATELIB_CONNECTIONCALLBACK_H
#define LAN_4GATELIB_CONNECTIONCALLBACK_H

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Manager {
        namespace Callback {
            /// \brief Колбэк для приема состояния соединения
            class LANTER_VISIBILITY ConnectionCallback {
                    public:
                    /// \brief Метод, в который будет передано новое состояние соединения
                    /// \param state Состояние соединения. true - связь между терминалом и кассой установлена
                    virtual void newState(bool state) = 0;
            };
        }
    }
}

#endif //LAN_4GATELIB_CONNECTIONCALLBACK_H
