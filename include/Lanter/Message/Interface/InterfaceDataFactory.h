#ifndef LAN_4GATELIBRARYCPP_InterfaceDATAFACTORY_H
#define LAN_4GATELIBRARYCPP_InterfaceDATAFACTORY_H

#include "IInterfaceData.h"
#include "Lanter/Utils/VisibilityMacroses.h"
#include <memory>

namespace Lanter
{
    namespace Message
    {
        namespace Interface
        {
            /// \brief Фабричный класс, возвращающий объект Interface
            class LANTER_VISIBILITY InterfaceDataFactory
            {
            public:
                /// \brief Возвращает указатель на объект интерфейса IInterfaceData и заполняет поле InterfacenCode
                /// \param[in] code Код экрана
                /// \return Указатель на объект интерфейса IInterfaceData
                static std::shared_ptr<IInterfaceData> getInterfaceData(InterfaceType type);

                /// \brief Возвращает указатель на объект интерфейса IInterfaceData
                /// \return Указатель на объект интерфейса IInterfaceData
                static std::shared_ptr<IInterfaceData> getInterfaceData();
            };//class InterfaceDataFactory
        }//namespace Interface
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_InterfaceDATAFACTORY_H