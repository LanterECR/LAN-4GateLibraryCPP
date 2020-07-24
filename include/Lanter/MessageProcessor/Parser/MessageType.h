#ifndef LAN_4GATELIBRARYCPP_MESSAGETYPE_H
#define LAN_4GATELIBRARYCPP_MESSAGETYPE_H


namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            /// \brief Перечисление содержит возможные состояния парсинга
            enum class MessageType {
                Unknown, ///< Неизвестный тип сообщения
                Error, ///< Ошибка при разборе сообщения
                Request, ///< Запрос к финансовому ПО LAN-4Tap
                Response, ///< Ответ финансового ПО LAN-4Tap
                Notification, ///< Уведомление от финансового ПО LAN-4Tap
                Communication, ///< Коммуникационное сообщение от финансового ПО LAN-4Tap

                //Границы
                FirstValue = Unknown, ///< Ссылка на первый элемент перечисления
                LastValue = Communication ///< Ссылка на последний элемент перечисления
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_MESSAGETYPE_H
