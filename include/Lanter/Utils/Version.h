#ifndef LAN_4GATELIB_VERSION_H
#define LAN_4GATELIB_VERSION_H

#include "string"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter
{
    namespace Utils
    {
        /// \brief Класс для получения информации о версии библиотеки
        class LANTER_VISIBILITY Version
        {
        public:
            /// \brief Возвращает текущую версию библиотеки
            /// \return версия библиотеки
            static const std::string &getVersion();
        };
    }
}
#endif //LAN_4GATELIB_VERSION_H