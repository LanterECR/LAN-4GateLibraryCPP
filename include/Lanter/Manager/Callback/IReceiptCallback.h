#ifndef LAN_4GATELIB_RECEIPTCALLBACK_H
#define LAN_4GATELIB_RECEIPTCALLBACK_H

#include <memory>
#include "Lanter/Utils/VisibilityMacroses.h"
#include "Lanter/Message/Receipt/IReceiptData.h"

namespace Lanter
{
    namespace Manager
    {
        namespace Callback
        {
            /// \brief Колбэк для приема данных команд взаимодействия
            class LANTER_VISIBILITY IReceiptCallback
            {
            public:
                virtual ~IReceiptCallback() = default;
                /// \brief Метод, в который будет переданы данные команды взаимодействия
                /// \param data данные команды взаимодействия
                /// \sa Message::Receipt::IReceiptData
                virtual void newData(std::shared_ptr<Message::Receipt::IReceiptData> data) = 0;
            };
        }
    }
}
#endif //LAN_4GATELIB_RECEIPTCALLBACK_H