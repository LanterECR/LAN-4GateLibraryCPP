#ifndef LAN_4GATELIBRARYCPP_CARDINPUTMETHOD_H
#define LAN_4GATELIBRARYCPP_CARDINPUTMETHOD_H

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            /// \brief Список возможных значений поля ResponseField::CardInputMethod в ответе финансового ПО LAN-4Tap
            enum class LANTER_VISIBILITY CardInputMethod {
                NoMethod,
                TerminalManualEntry = 1, ///< Данные карты введены вручную в финансовом ПО LAN-4Tap
                ExternalManualEntry, ///< Данные карты введены вручную за пределами финансового ПО LAN-4Tap
                MagStrip, ///< Использована магнитная полоса
                MagStripFallback, ///< Произошел фолбэк на магнитную полосу
                ChipFullGrade, ///< Использована полная схема работы с чипом (контактным интерфейсом)
                ChipPartialGrade, ///< Использована сокращенная схема работы с чипом (контактным интерфейсом)
                ContactlessMagStripMode, ///< Использован бесконтактный интерфейс в режиме эмуляции магнитной полосы
                ContactlessChipMode, ///< Использован бесконтактный интерфейс в режиме эмуляции чипа
                //Диапазон значений
                FirstValue = TerminalManualEntry, ///< Ссылка на первый элемент перечисления
                LastValue = ContactlessChipMode ///< Ссылка на последний элемент перечисления
            };//enum CardInputMethod
        }//namespace Response
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_CARDINPUTMETHOD_H
