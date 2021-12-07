#ifndef LAN_4GATELIB_INTERACTIONFACTORY_H
#define LAN_4GATELIB_INTERACTIONFACTORY_H

#include <memory>
#include "IInteractionData.h"

namespace Lanter {
    namespace Message {
        namespace Interaction {
            /// \brief Фабричный класс, возвращающий объект взаимодействия
            class InteractionDataFactory {
            public:
                /// \brief Возвращает указатель на объект интерфейс IInteractionData и заполняет поле Code
                /// \param code Код взаимодействия
                /// \sa InteractionCode
                /// \return Указатель на объект IInteractionData
                static std::shared_ptr<IInteractionData> getInteractionData(InteractionCode code);

                /// \brief Возвращает указатель на объект интерфейс IInteractionData
                /// \return Указатель на объект IInteractionData
                static std::shared_ptr<IInteractionData> getInteractionData();
            };
        }
    }
}

#endif //LAN_4GATELIB_INTERACTIONFACTORY_H
