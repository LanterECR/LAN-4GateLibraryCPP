#ifndef LAN_4GATELIB_INTERACTIONFACTORY_H
#define LAN_4GATELIB_INTERACTIONFACTORY_H

#include "IInteractionData.h"
#include "Lanter/Utils/VisibilityMacroses.h"

#include <memory>

namespace Lanter
{
    namespace Message
    {
        namespace Interaction
        {
            /// \brief Фабричный класс, возвращающий объект взаимодействия
            class LANTER_VISIBILITY InteractionDataFactory
            {
            public:
                /// \brief Возвращает указатель на объект интерфейс IInteractionData и заполняет поле Code
                /// \param code Код взаимодействия
                /// \sa InteractionCode
                /// \return Указатель на объект IInteractionData
                static std::shared_ptr<IInteractionData> getInteractionData(InteractionCode code);

                /// \brief Возвращает указатель на объект интерфейс IInteractionData
                /// \return Указатель на объект IInteractionData
                static std::shared_ptr<IInteractionData> getInteractionData();
            }; //class InteractionDataFactory
        }
    }
}
#endif //LAN_4GATELIB_INTERACTIONFACTORY_H