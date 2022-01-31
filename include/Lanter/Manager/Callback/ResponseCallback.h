#ifndef LAN_4GATELIB_RESPONSECALLBACK_H
#define LAN_4GATELIB_RESPONSECALLBACK_H

#include <memory>

#include "Lanter/Utils/VisibilityMacroses.h"

#include "Lanter/Message/Response/IResponseData.h"

namespace Lanter {
    namespace Manager {
        namespace Callback {
            /// \brief Колбэк для приема данных ответа от терминала
            class LANTER_VISIBILITY ResponseCallback {
            public:
                virtual ~ResponseCallback() = default;
                /// \brief Метод, в который будет переданы данные ответа
                /// \param data данные ответа
                /// \sa Message::Response::IResponseData
                virtual void newData(std::shared_ptr<Message::Response::IResponseData> data) = 0;
            };
        }
    }
}

#endif //LAN_4GATELIB_RESPONSECALLBACK_H
