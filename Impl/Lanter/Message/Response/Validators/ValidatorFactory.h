#ifndef LAN_4GATELIBRARYCPP_VALIDATORFACTORY_H
#define LAN_4GATELIBRARYCPP_VALIDATORFACTORY_H

#include <memory>

#include "IValidator.h"

#include "Lanter/Message/OperationCode.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class ValidatorFactory {
            public:
                static std::shared_ptr<IValidator> getValidator(OperationCode operationCode);
            };
        }//Response
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_VALIDATORFACTORY_H
