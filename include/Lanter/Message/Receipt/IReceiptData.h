#ifndef LAN_4GATELIB_IRECEIPTDATA_H
#define LAN_4GATELIB_IRECEIPTDATA_H

#include "ReceiptCode.h"
#include "Lanter/Utils/VisibilityMacroses.h"
#include <string>
#include <vector>

namespace Lanter
{
    namespace Message
    {
        namespace Receipt
        {
            ///\brief Базовый класс-контейнер для передачи команд взаимодействия
            class LANTER_VISIBILITY IReceiptData
            {
            public:
                /// \brief Возвращает установленный код команды взаимодействия
                /// \return Код команды взаимодействия. По умолчанию NoReceipt
                /// \sa ReceiptCode
                virtual ReceiptCode getCode() const = 0;

                /// \brief Устанавливает код команды взаимодействия
                /// \param code Код команды взаимодействия из enum ReceiptCode
                /// \sa ReceiptCode
                virtual bool setCode(const ReceiptCode& code) = 0;

                /// \brief Устанавливает код команды взаимодействия на значение по умолчанию
                /// \return true, если код успешно убран
                virtual bool resetCode() = 0;

                /// \brief Возвращает текст уведомления, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая текст уведомления, если он был передан
                virtual const std::vector<std::string>& getMessage() const = 0;

                /// \brief Устанавливает текст уведомления
                /// \param[in] message текст уведомления
                /// \return true, если поле успешно установлено
                virtual bool setMessage(const std::vector<std::string>& message) = 0;

                /// \brief Очищает сообщение уведомления
                /// \return true, если сообщение успешно очищено
                virtual bool resetMessage() = 0;
            };// class IReceiptData
        }
    }
}
#endif //LAN_4GATELIB_IRECEIPTDATA_H