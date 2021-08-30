#ifndef LAN_4GATELIB_ICOMMUNICATION_H
#define LAN_4GATELIB_ICOMMUNICATION_H

#include <cstddef>
#include <cstdint>
#include <vector>

namespace Lanter {
    namespace Communication {
        ///\brief Интерфейс класса коммуникаций, используемый в работе Lan4Gate
        /// \sa Lan4Gate
        class ICommunication {
        public:
            /// \brief Открывает соединение
            /// \return true, если соединение успешно открыто
            virtual bool open() = 0;

            /// \brief Закрывает соединение
            /// \return true, если соединение успешно закрыто
            virtual bool close() = 0;

            /// \brief Возвращает признак открытого соединения
            /// \return true - открыто, false - закрыто
            virtual bool isOpen() = 0;

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
