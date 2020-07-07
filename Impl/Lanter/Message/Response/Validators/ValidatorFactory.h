//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_VALIDATORFACTORY_H
#define LAN_4GATELIBRARYCPP_VALIDATORFACTORY_H

#include <memory>

#include "IValidator.h"

#include "Lanter/Message/OperationCodes.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class ValidatorFactory {
            public:
                static std::shared_ptr<IValidator> getValidator(OperationCodes operationCode);
            };
        }//Response
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_VALIDATORFACTORY_H
