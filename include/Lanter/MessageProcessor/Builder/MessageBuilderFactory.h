#ifndef LAN_4GATELIBRARYCPP_MESSAGEBUILDERFACTORY_H
#define LAN_4GATELIBRARYCPP_MESSAGEBUILDERFACTORY_H

#include <memory>

#include "IMessageBuilder.h"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Builder {
            /// \brief Фабричный класс, возвращающий текущий сборщик сообщений
            class LANTER_VISIBILITY MessageBuilderFactory {
            public:
                /// \brief Возвращает указатель на созданный объект сборщика
                /// \return nullptr, если не удалось создать сборщик
                static std::shared_ptr<IMessageBuilder> getMessageBuilder();
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_MESSAGEBUILDERFACTORY_H
