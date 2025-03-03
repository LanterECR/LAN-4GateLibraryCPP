#ifndef LAN_4GATELIBRARYCPP_InterfaceType_H
#define LAN_4GATELIBRARYCPP_InterfaceType_H

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter
{
    namespace Message
    {
        namespace Interface
        {
            /// \brief Список поддерживаемых уведомлений
            enum class InterfaceType
            {
                Unknown,    ///< Код экрана не известен
                YesNo,      ///< Код экрана выбора Yes или No
                Amount,     ///< Код экрана для запросы суммы
                DataEntry,  ///< Код экрана для запроса данных
                Menu        ///< Код экрана для меню
            };//enum InterfaceType

            /// Функция, возвращающая первый значимый элемент перечисления InterfaceType
            /// \return Первый элемент значимый перечисления InterfaceType
            constexpr InterfaceType getFirstInterfaceType()
            {
                return InterfaceType::YesNo;
            }

            /// Функция, возвращающая последний значимый элемент перечисления InterfaceType
            /// \return Последний элемент значимый перечисления InterfaceType
            constexpr InterfaceType getLastInterfaceType()
            {
                return InterfaceType::Menu;
            }
        }//namespace Interface
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_InterfaceType_H