#ifndef LAN_4GATELIBRARYCPP_VALIDATORFACTORY_H
#define LAN_4GATELIBRARYCPP_VALIDATORFACTORY_H

#include "IValidator.h"

#include <memory>

#include "Lanter/Message/OperationCode.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            class ValidatorFactory
            {
            public:
                /// Создает экземпляр валидатора для операции
                /// \param operationCode Операция, для которой необходим экземпляр валидатора
                /// \return nullptr, если валидатор не был создан
                static std::shared_ptr<IValidator> getValidator(OperationCode operationCode);
            };//class ValidatorFactory
        }//namespace Request
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_VALIDATORFACTORY_H