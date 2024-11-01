#ifndef LAN_4GATELIB_IINTERACTIONDATA_H
#define LAN_4GATELIB_IINTERACTIONDATA_H

#include "InteractionCode.h"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter
{
    namespace Message
    {
        namespace Interaction
        {
            ///\brief Базовый класс-контейнер для передачи команд взаимодействия
            class LANTER_VISIBILITY IInteractionData
            {
            public:
                /// \brief Возвращает установленный код команды взаимодействия
                /// \return Код команды взаимодействия. По умолчанию NoInteraction
                /// \sa InteractionCode
                virtual InteractionCode getCode() const = 0;

                /// \brief Устанавливает код команды взаимодействия
                /// \param code Код команды взаимодействия из enum InteractionCode
                /// \sa InteractionCode
                virtual bool setCode(InteractionCode code) = 0;

                /// \brief Устанавливает код команды взаимодействия на значение по умолчанию
                /// \return true, если код успешно убран
                virtual bool resetCode() = 0;
            };
        }
    }
}
#endif //LAN_4GATELIB_IINTERACTIONDATA_H