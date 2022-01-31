#ifndef LAN_4GATELIB_ICOMMUNICATION_H
#define LAN_4GATELIB_ICOMMUNICATION_H

#include <cstddef>
#include <cstdint>
#include <vector>

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Communication {
        ///\brief Интерфейс класса коммуникаций, используемый в работе Lan4Gate
        /// \sa Lan4Gate
        class LANTER_VISIBILITY ICommunication {
        public:
            virtual ~ICommunication() = default;
            /// \brief Выполняет один цикл асинхронного соединения. Может быть не реализован
            virtual void doCommunication() = 0;

            /// \brief Открывает соединение
            /// \return true, если соединение успешно открыто
            virtual bool open() = 0;

            /// \brief Закрывает соединение
            /// \return true, если соединение успешно закрыто
            virtual bool close() = 0;

            /// \brief Возвращает признак открытого соединения
            /// \return true - открыто, false - закрыто
            virtual bool isOpen() = 0;

            /// \brief Пытается выполнить подключение соединения
            /// \return true, если удалось подключиться
            virtual bool connect() = 0;

            /// \brief Отключает соединение
            /// \return true, если успешно отключено
            virtual bool disconnect() = 0;

            /// \brief Возвращает статус подключения
            /// \return true, если подключено
            virtual bool isConnected() = 0;

            /// \brief Отправляет данные в соединение
            /// \param[in] in отправляемые данные
            /// \return размер отправленных данных
            virtual size_t send(const std::vector<uint8_t> & in) = 0;

            /// \brief Принимает данные из соединения
            /// \param out контейнер для полученных данных
            /// \return размер полученных данных
            virtual size_t receive(std::vector<uint8_t> & out) = 0;
        };//class ICommunication
    }//namespace Communication
}//namespace Lanter

#endif //LAN_4GATELIB_ICOMMUNICATION_H
