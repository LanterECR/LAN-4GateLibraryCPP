#ifndef LAN_4GATELIB_IINTERACTIONCALLBACK_H
#define LAN_4GATELIB_IINTERACTIONCALLBACK_H

#include <memory>

#include "Lanter/Utils/VisibilityMacroses.h"

#include "Lanter/Message/Interaction/IInteractionData.h"

namespace Lanter {
    namespace Manager {
        namespace Callback {
            /// \brief Колбэк для приема данных команд взаимодействия
            class LANTER_VISIBILITY IInteractionCallback {
            public:
                virtual ~IInteractionCallback() = default;
                /// \brief Метод, в который будет переданы данные команды взаимодействия
                /// \param data данные команды взаимодействия
                /// \sa Message::Interaction::IInteractionData
                virtual void newData(std::shared_ptr<Message::Interaction::IInteractionData> data) = 0;
            };
        }
    }
}

#endif //LAN_4GATELIB_IINTERACTIONCALLBACK_H
