#ifndef LAN_4GATELIB_INTERACTIONCODE_H
#define LAN_4GATELIB_INTERACTIONCODE_H

namespace Lanter {
    namespace Message {
        namespace Interaction {
            enum class InteractionCode {
                NoInteraction, ///< Значение по умолчанию
                Abort, ///< Прервать выполняемую операцию
                FirstValue = Abort, ///< Ссылка на первый элемент перечисления
                LastValue = Abort ///< Ссылка на последний элемент перечисления
            };
        }
    }
}
#endif //LAN_4GATELIB_INTERACTIONCODE_H
