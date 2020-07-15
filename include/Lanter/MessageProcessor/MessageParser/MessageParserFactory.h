//
// Created by Владимир Лысенков on 12.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_MESSAGEPARSERFACTORY_H
#define LAN_4GATELIBRARYCPP_MESSAGEPARSERFACTORY_H

#include <memory>

#include "IMessageParser.h"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace MessageProcessor {
        /// \brief Фабричный класс, возвращающий текущий парсер сообщений
        class LANTER_VISIBILITY MessageParserFactory {
        public:
            /// \brief Возвращает указатель на созданный объект парсера
            /// \return nullptr, если не удалось создать парсер
            static std::shared_ptr<IMessageParser> getMessageParser();
        };
    }
}
#endif //LAN_4GATELIBRARYCPP_MESSAGEPARSERFACTORY_H
