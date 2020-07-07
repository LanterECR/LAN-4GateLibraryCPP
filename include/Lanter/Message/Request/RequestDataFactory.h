//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_REQUESTDATAFACTORY_H
#define LAN_4GATELIBRARYCPP_REQUESTDATAFACTORY_H

#include <memory>

#include "IRequestData.h"
#include "Lanter/Message/OperationCodes.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            /// \brief Фабричный класс, возвращающий предварительно заполненный обхект IRequestData
            class RequestDataFactory {
            public:
                /// \brief Возвращает указатель на объект интерфейса IRequestData, предварительно заполненный
                /// переданными кодом операции и логическим номером кассового ПО
                /// \param operationCode Код операции из списка OperationCodes
                /// \sa OperationCodes
                /// \param ecrNumber Логический номер кассового ПО в диапазоне [1, 999]
                /// \return Указатель на объект интерфейса IRequestData
                /// \throws invalid_argument, если operationCode или ecrNumber вне разрешенного диапазона
                static std::shared_ptr<IRequestData> getRequestData(OperationCodes operationCode, int16_t ecrNumber);
            };//RequestDataFactory
        }//Request
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_REQUESTDATAFACTORY_H
