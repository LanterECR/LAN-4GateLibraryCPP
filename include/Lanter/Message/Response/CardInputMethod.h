#ifndef LAN_4GATELIBRARYCPP_CARDINPUTMETHOD_H
#define LAN_4GATELIBRARYCPP_CARDINPUTMETHOD_H

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            /// \brief Список возможных значений поля ResponseField::CardInputMethod в ответе финансового ПО LAN-4Tap
            enum class CardInputMethod
            {
                NoMethod,
                TerminalManualEntry = 1, ///< Данные карты введены вручную в финансовом ПО LAN-4Tap
                ExternalManualEntry, ///< Данные карты введены вручную за пределами финансового ПО LAN-4Tap
                MagStrip, ///< Использована магнитная полоса
                MagStripFallback, ///< Произошел фолбэк на магнитную полосу
                ChipFullGrade, ///< Использована полная схема работы с чипом (контактным интерфейсом)
                ChipPartialGrade, ///< Использована сокращенная схема работы с чипом (контактным интерфейсом)
                ContactlessMagStripMode, ///< Использован бесконтактный интерфейс в режиме эмуляции магнитной полосы
                ContactlessChipMode ///< Использован бесконтактный интерфейс в режиме эмуляции чипа
            };//enum CardInputMethod
            
            /// Функция, возвращающая первый значимый элемент перечисления CardInputMethod
            /// \return Первый элемент значимый перечисления CardInputMethod
            constexpr CardInputMethod getFirstCardInputMethod()
            {
                return CardInputMethod::TerminalManualEntry;
            }

            /// Функция, возвращающая последний значимый элемент перечисления CardInputMethod
            /// \return Последний элемент значимый перечисления CardInputMethod
            constexpr CardInputMethod getLastCardInputMethod()
            {
                return CardInputMethod::ContactlessChipMode;
            }
        }//namespace Response
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_CARDINPUTMETHOD_H