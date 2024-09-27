#ifndef LAN_4GATELIBRARYCPP_IVALIDATOR_H
#define LAN_4GATELIBRARYCPP_IVALIDATOR_H

#include <set>

#include "Lanter/Message/Response/ResponseField.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            class IValidator
            {
            public:
                virtual ~IValidator() = default;

                virtual void appendMandatoryField(ResponseField field) = 0;

                virtual const std::set<ResponseField> &getMandatoryFields() const = 0;

                virtual void appendOptionalField(ResponseField field) = 0;

                virtual const std::set<ResponseField> &getOptionalFields() const = 0;

                virtual bool validate(const std::set<ResponseField> &fields) = 0;
            };
        }
    }
}
#endif //LAN_4GATELIBRARYCPP_IVALIDATOR_H