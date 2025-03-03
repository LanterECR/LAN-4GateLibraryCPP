#ifndef LAN_4GATELIBRARYCPP_IGATEWAYDATA_H
#define LAN_4GATELIBRARYCPP_IGATEWAYDATA_H

#include "Lanter/Utils/VisibilityMacroses.h"
#include "GatewayCode.h"
#include <string>
#include <vector>

namespace Lanter
{
    namespace Message
    {
        namespace Gateway
        {
            /// \brief Базовый класс-контейнер для шлюза от финансового ПО LAN-4Tap
            class LANTER_VISIBILITY IGatewayData
            {
            public:
                virtual ~IGatewayData() = default;

                /// \brief Возвращает код полученной команды
                /// \return Если поле не установлено - NoCode
                /// \sa Gateways
                virtual GatewayCode getCode() const = 0;

                /// \brief Устанавливает код команды
                /// \param[in] GatewayCode Код команды из перечисления Gateway за исключением NoCode
                /// \return true, если поле успешно установлено
                virtual bool setCode(GatewayCode gatewayCode) = 0;

                /// \brief Устанавливает код команды на значение по умолчанию
                /// \return true, если код успешно убран
                virtual bool resetCode() = 0;

                /// \brief Возвращает текст с IP адресом, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая текст с IP адресом, если он был передан
                virtual const std::string &getIP() const = 0;

                /// \brief Устанавливает текст с IP адресом
                /// \param[in] ip текст с IP адресом
                /// \return true, если поле успешно установлено
                virtual bool setIP(const std::string &ip) = 0;

                /// \brief Очищает поле с IP адресом
                /// \return true, если сообщение успешно очищено
                virtual bool resetIP() = 0;

                /// \brief Возвращает порт, по которому необходимо установить соединение
                /// \return значение порта
                virtual const int& getPort() const = 0;

                /// \brief Устанавливает порт, по которому необходимо установить соединение
                /// \param[in] port значение порта
                /// \return true, если поле успешно установлено
                virtual bool setPort(const int& port) = 0;

                /// \brief Очищает порт, по которому необходимо установить соединение
                /// \return true, если данные успешно очищены
                virtual bool resetPort() = 0;

                /// \brief Возвращает Link(уникальный идентификатор соединения)
                /// \return значение
                virtual const int& getLink() const = 0;

                /// \brief Устанавливает Link(уникальный идентификатор соединения)
                /// \param[in] link значение
                /// \return true, если поле успешно установлено
                virtual bool setLink(const int& link) = 0;

                /// \brief Очищает Link(уникальный идентификатор соединения)
                /// \return true, если данные успешно очищены
                virtual bool resetLink() = 0;

                /// \brief Возвращает Status(результат выполнения команды)
                /// \return значение
                virtual const int& getStatus() const = 0;

                /// \brief Устанавливает Status(результат выполнения команды)
                /// \param[in] status значение
                /// \return true, если поле успешно установлено
                virtual bool setStatus(const int& status) = 0;

                /// \brief Очищает Status(результат выполнения команды)
                /// \return true, если данные успешно очищены
                virtual bool resetStatus() = 0;

                /// \brief Возвращает Data(данные)
                /// \return значение
                virtual const std::vector<int8_t>& getData() const = 0;

                /// \brief Устанавливает Data(данные)
                /// \param[in] data значение
                /// \return true, если поле успешно установлено
                virtual bool setData(const std::vector<int8_t>& data) = 0;

                /// \brief Очищает Data(данные)
                /// \return true, если данные успешно очищены
                virtual bool resetData() = 0;
            };//class IGatewayData
        }//namespace Gateways
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_IGATEWAYDATA_H