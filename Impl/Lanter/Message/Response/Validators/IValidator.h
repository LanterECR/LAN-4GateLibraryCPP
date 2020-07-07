//
// Created by Владимир Лысенков on 25.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_IVALIDATOR_H
#define LAN_4GATELIBRARYCPP_IVALIDATOR_H

#include <set>

#include "Lanter/Message/Response/ResponseFields.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class IValidator {
            public:
                virtual ~IValidator() = default;

                virtual void appendMandatoryField(ResponseFields field) = 0;

                virtual const std::set<ResponseFields> &getMandatoryFields() const = 0;

                virtual void appendOptionalField(ResponseFields field) = 0;

                virtual const std::set<ResponseFields> &getOptionalFields() const = 0;

                virtual bool validate(const std::set<ResponseFields> &fields) = 0;
            };
        }
    }
}

#endif //LAN_4GATELIBRARYCPP_IVALIDATOR_H
