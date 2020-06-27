//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_CARDINPUTMETHOD_H
#define LAN_4GATELIBRARYCPP_CARDINPUTMETHOD_H
namespace Lanter {
    namespace Response {
        /// \brief Список возможных значений поля CardInputMethod в ответе финансового ПО LAN-4Tap
        enum class CardInputMethod {
            NoMethod,
            TerminalManualEntry = 1, ///< Данные карты введены вручную в финансовом ПО LAN-4Tap
            ExternalManualEntry, ///< Данные карты введены вручную за пределами финансового ПО LAN-4Tap
            MagStrip, ///< Использована магнитная полоса
            MagStripFallback, ///< Произошел фолбэк на магнитную полосу
            ChipFullGrade, ///< Использована полная схема работы с чипом (контактным интерфейсом)
            ChipPartialGrade, ///< Использована сокращенная схема работы с чипом (контактным интерфейсом)
            ContactlessMagStripMode, ///< Использован бексонтактный интерфейс в режиме эмуляции магнитной полосы
            ContactlessChipMode, ///< Использован бесконтактный интерфейс в режиме эмуляции чипа
            //Диапазон значений
            FirstValue = TerminalManualEntry, ///< Ссылка на первое поле в enum
            LastValue = ContactlessChipMode ///< Ссылка на последнее поле в enum
        };
    }
}
#endif //LAN_4GATELIBRARYCPP_CARDINPUTMETHOD_H
