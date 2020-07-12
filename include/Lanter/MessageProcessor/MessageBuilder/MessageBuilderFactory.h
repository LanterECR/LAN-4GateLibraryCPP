//
// Created by Владимир Лысенков on 07.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_MESSAGEBUILDERFACTORY_H
#define LAN_4GATELIBRARYCPP_MESSAGEBUILDERFACTORY_H

#include <memory>

#include "IMessageBuilder.h"

namespace Lanter {
    namespace MessageProcessor {
        /// \brief Фабричный класс, возвращающий текущий сборщик сообщений
        class MessageBuilderFactory {
        public:
            /// \brief Возвращает указатель на созданный объект сборщика
            /// \return nullptr, если не удалось создать сборщик
            static std::shared_ptr<IMessageBuilder> getMessageBuilder();
        };
    }
}
#endif //LAN_4GATELIBRARYCPP_MESSAGEBUILDERFACTORY_H
