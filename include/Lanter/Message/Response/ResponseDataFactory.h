#ifndef LAN_4GATELIBRARYCPP_RESPONSEDATAFACTORY_H
#define LAN_4GATELIBRARYCPP_RESPONSEDATAFACTORY_H
#include <memory>

#include "Lanter/Utils/VisibilityMacroses.h"

#include "Lanter/Message/OperationCode.h"

#include "IResponseData.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            /// \brief Фабричный класс, возвращающий предварительно заполненный объект IResponseData
            class LANTER_VISIBILITY ResponseDataFactory {
            public:
                /// \brief Возвращает указатель на объект интерфейса IResponseData, предварительно заполненный
                /// переданными кодом операции и логическим номером кассового ПО
                /// \param operationCode Код операции из списка OperationCode. Значение NoOperation не будет передано объекту
                /// \sa OperationCode
                /// \param ecrNumber Логический номер кассового ПО в диапазоне [1, 999].
                /// Если установить значение -1, то ecrNumber не будет установлен в IResponseData
                /// \return Указатель на объект интерфейса IResponseData
                static std::shared_ptr<IResponseData> getResponseData(OperationCode operationCode = OperationCode::NoOperation, int16_t ecrNumber = -1);
            };//class ResponseDataFactory
        }//namespace Response
    }//namespace Message
}//namespace Lanter

#endif //LAN_4GATELIBRARYCPP_RESPONSEDATAFACTORY_H
