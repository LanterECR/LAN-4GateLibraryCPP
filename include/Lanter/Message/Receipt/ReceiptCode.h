#ifndef LAN_4GATELIB_RECEIPTCODE_H
#define LAN_4GATELIB_RECEIPTCODE_H

namespace Lanter
{
    namespace Message
    {
        namespace Receipt
        {
            enum class ReceiptCode
            {
                NoReceipt, ///< Значение по умолчанию
                Begin, ///< Начало печати чека
                Print, ///< Печать чека
                End ///< Конец печати чека
            };

            /// Функция, возвращающая первый значимый элемент перечисления ReceiptCode
            /// \return Первый элемент значимый перечисления ReceiptCode
            constexpr ReceiptCode getFirstReceiptCode()
            {
                return ReceiptCode::Begin;
            }

            /// Функция, возвращающая последний значимый элемент перечисления ReceiptCode
            /// \return Последний элемент значимый перечисления ReceiptCode
            constexpr ReceiptCode getLastReceiptCode()
            {
                return ReceiptCode::End;
            }
        }
    }
}
#endif //LAN_4GATELIB_RECEIPTCODE_H