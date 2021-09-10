#ifndef LAN_4GATELIB_LAN4GATEFACTORY_H
#define LAN_4GATELIB_LAN4GATEFACTORY_H

#include <memory>

#include "Lanter/Utils/VisibilityMacroses.h"

#include "ILan4Gate.h"
#include "Lanter/Communication/ICommunication.h"

namespace Lanter {
    namespace Manager {
        /// \brief Фабричный класс для создания экземпляров менеджера ILan4Gate
        class LANTER_VISIBILITY Lan4GateFactory {
        public:
            /// \brief Создает экземпляр менеджера ILan4Gate
            /// \param[in] ecrNumber логический идентификатор кассы
            /// \param[in] communication указатель на используемые коммуникации
            /// \return nullptr, если не удалось создать менеджер
            /// \sa Communication::ICommunication
            static std::shared_ptr<ILan4Gate>  getLan4Gate(int16_t ecrNumber, std::shared_ptr<Communication::ICommunication> communication = nullptr);
        };
    }
}

#endif //LAN_4GATELIB_LAN4GATEFACTORY_H
