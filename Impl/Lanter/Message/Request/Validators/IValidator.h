//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_IVALIDATOR_H
#define LAN_4GATELIBRARYCPP_IVALIDATOR_H

#include <set>

#include "Lanter/Message/Request/RequestFields.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            class IValidator {
            public:
                virtual ~IValidator() = default;

                virtual void appendMandatoryField(RequestFields field) = 0;

                virtual const std::set<RequestFields> &getMandatoryFields() const = 0;

                virtual void appendOptionalField(RequestFields field) = 0;

                virtual const std::set<RequestFields> &getOptionalFields() const = 0;

                virtual bool validate(const std::set<RequestFields> &fields) = 0;
            };
        }
    }
}

#endif //LAN_4GATELIBRARYCPP_IVALIDATOR_H
