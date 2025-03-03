#ifndef LAN_4GATELIB_IInterfaceCALLBACK_H
#define LAN_4GATELIB_IInterfaceCALLBACK_H

#include <memory>
#include "Lanter/Utils/VisibilityMacroses.h"
#include "Lanter/Message/Interface/IInterfaceData.h"

namespace Lanter
{
    namespace Manager
    {
        namespace Callback
        {
            /// \brief Колбэк для приема данных Interface от терминала
            class LANTER_VISIBILITY IInterfaceCallback
            {
            public:
                virtual ~IInterfaceCallback() = default;
                /// \brief Метод, в который будет переданы данные Interface
                /// \param data данные Interface
                /// \sa Message::Interface::IInterfaceData
                virtual std::string newData(std::shared_ptr<Message::Interface::IInterfaceData> data) = 0;
            };
        }
    }
}
#endif //LAN_4GATELIB_IInterfaceCALLBACK_H