#ifndef TESTL4G_COMMUNICATINFACTORY_H
#define TESTL4G_COMMUNICATINFACTORY_H

#include <memory>
#include <string>

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

            /// Создает экземпляр TCP клиента.
            /// \param ip Адрес, к которому необходимо подключиться. В формате IP4 (1.1.1.1 - 255.255.255.255)
            /// На данный момент нет валидации IP. При неправильном формате ASIO может кинуть исключение
            /// \param port Порт, по которому будет выполнено подключение
            /// \return nullptr, если не удалось создать соединение
            static std::shared_ptr<ICommunication> getTcpClient(const std::string & ip, int port = 20501);

            /// \brief Создает декоратор, контролирующий длину сообщений
            /// \param communication декорируемое соединение
            /// \return nullptr, если не удалось создать декоратор
            static std::shared_ptr<ICommunication> getSizeControlDecorator(std::shared_ptr<ICommunication> communication);
        };
    }
}
#endif //TESTL4G_COMMUNICATINFACTORY_H
