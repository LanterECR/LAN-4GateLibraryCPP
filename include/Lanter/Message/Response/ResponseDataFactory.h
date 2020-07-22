//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_RESPONSEDATAFACTORY_H
#define LAN_4GATELIBRARYCPP_RESPONSEDATAFACTORY_H
#include <memory>

#include "IResponseData.h"
#include "Lanter/Message/OperationCode.h"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            /// \brief Фабричный класс, возвращающий предварительно заполненный обхект IResponseData
            class LANTER_VISIBILITY ResponseDataFactory {
            public:
                /// \brief Возвращает указатель на объект интерфейса IResponseData, предварительно заполненный
                /// переданными кодом операции и логическим номером кассового ПО
                /// \param operationCode Код операции из списка OperationCodes
                /// \sa OperationCodes
                /// \param ecrNumber Логический номер кассового ПО в диапазоне [1, 999].
                /// Если установить значение -1, то ecrNumber не будет установлен в IResponseData
                /// \return Указатель на объект интерфейса IResponseData
                /// \throws invalid_argument, если operationCode или ecrNumber вне разрешенного диапазона
                static std::shared_ptr<IResponseData> getResponseData(OperationCode operationCode, int16_t ecrNumber = -1);
            };//ResponseDataFactory
        }//Response
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_RESPONSEDATAFACTORY_H
