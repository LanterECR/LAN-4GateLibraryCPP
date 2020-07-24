#ifndef LAN_4GATELIBRARYCPP_IVALIDATOR_H
#define LAN_4GATELIBRARYCPP_IVALIDATOR_H

#include <set>

#include "Lanter/Message/Request/RequestField.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            class IValidator {
            public:
                virtual ~IValidator() = default;

                virtual void appendMandatoryField(RequestField field) = 0;

                virtual const std::set<RequestField> &getMandatoryFields() const = 0;

                virtual void appendOptionalField(RequestField field) = 0;

                virtual const std::set<RequestField> &getOptionalFields() const = 0;

                virtual bool validate(const std::set<RequestField> &fields) = 0;
            };
        }
    }
}

#endif //LAN_4GATELIBRARYCPP_IVALIDATOR_H
