#ifndef LAN_4GATELIB_INTERACTIONCODE_H
#define LAN_4GATELIB_INTERACTIONCODE_H

namespace Lanter
{
    namespace Message
    {
        namespace Interaction
        {
            enum class InteractionCode
            {
                NoInteraction, ///< Значение по умолчанию
                Abort ///< Прервать выполняемую операцию
            };

            /// Функция, возвращающая первый значимый элемент перечисления InteractionCode
            /// \return Первый элемент значимый перечисления InteractionCode
            constexpr InteractionCode getFirstInteractionCode()
            {
                return InteractionCode::Abort;
            }

            /// Функция, возвращающая последний значимый элемент перечисления InteractionCode
            /// \return Последний элемент значимый перечисления InteractionCode
            constexpr InteractionCode getLastInteractionCode()
            {
                return InteractionCode::Abort;
            }
        }
    }
}
#endif //LAN_4GATELIB_INTERACTIONCODE_H