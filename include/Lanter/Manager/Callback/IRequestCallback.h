#ifndef LAN_4GATELIB_IREQUESTCALLBACK_H
#define LAN_4GATELIB_IREQUESTCALLBACK_H

#include <memory>

#include "Lanter/Utils/VisibilityMacroses.h"

#include "Lanter/Message/Request/IRequestData.h"

namespace Lanter {
    namespace Manager {
        namespace Callback {
            /// \brief Колбэк для приема данных запроса от кассы
            class LANTER_VISIBILITY IRequestCallback {
            public:
                virtual ~IRequestCallback() = default;
                /// \brief Метод, в который будет переданы данные запроса
                /// \param data данные запроса
                /// \sa Message::Request::IRequestData
                virtual void newData(std::shared_ptr<Message::Request::IRequestData> data) = 0;
            };
        }
    }
}
#endif //LAN_4GATELIB_IREQUESTCALLBACK_H
