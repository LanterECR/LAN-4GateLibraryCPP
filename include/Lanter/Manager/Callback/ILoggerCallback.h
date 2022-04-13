#ifndef LAN_4GATELIB_LOGGER_CALLBACK_H
#define LAN_4GATELIB_LOGGER_CALLBACK_H

#include "Lanter/Utils/VisibilityMacroses.h"
#include <string>

namespace Lanter {
    namespace Manager {
        namespace Callback {
            /// \brief Колбэк для приема состояния соединения
            class LANTER_VISIBILITY ILoggerCallback {
            public:
                virtual ~ILoggerCallback() = default;
                /// \brief Метод, в который будет передано сообщение
                /// \param message сообщение
                virtual void message(const std::string& text) = 0;
            };
        }
    }
}

#endif //LAN_4GATELIB_LOGGER_CALLBACK_H
