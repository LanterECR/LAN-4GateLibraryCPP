#ifndef TESTL4G_COMMUNICATINFACTORY_H
#define TESTL4G_COMMUNICATINFACTORY_H

#include <memory>

#include "Lanter/Utils/VisibilityMacroses.h"

#include "ICommunication.h"

namespace Lanter {
    namespace Communication {
        /// \brief Фабричный класс для создания экземпляров соединения
        class LANTER_VISIBILITY CommunicationFactory {
        public:
            /// \brief Создает экземпляр TCP сервера, который обслуживает единственное соединение
            /// \param[in] port Порт, который будет слушать сервер
            /// \return nullptr, если не удалось создать соединение
            static std::shared_ptr<ICommunication> getSingleTcpServer(int port = 20501);
        };
    }
}
#endif //TESTL4G_COMMUNICATINFACTORY_H
