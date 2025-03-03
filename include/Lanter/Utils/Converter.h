#ifndef LAN_4GATELIB_CONVERTER_H
#define LAN_4GATELIB_CONVERTER_H

#include "string"
#include "vector"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter
{
    namespace Utils
    {
        /// \brief Класс для получения информации о версии библиотеки
        class LANTER_VISIBILITY Conveter
        {
        public:
            /// \brief Преобразовать вектор байт в формат Base64
            /// \return строку в формате Base64
            static std::string bytesToBase64(const std::vector<int8_t>& value);

            /// \brief Преобразовать из строки Base64 в вектор байт
            /// \return вектор байт
            static std::vector<int8_t> bytesFromBase64(const std::string& value);
        };
    }
}
#endif //LAN_4GATELIB_CONVERTER_H