//
// Created by Владимир Лысенков on 21.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_FIELDSVALIDATOR_H
#define LAN_4GATELIBRARYCPP_FIELDSVALIDATOR_H

#include <set>

#include "Lanter/Requests/RequestFields.h"

namespace Lanter {
    namespace Requests {
        class FieldsValidator {
        public:
            void appendMandatoryField(RequestFields field);

            const std::set<RequestFields> &getMandatoryFields() const;

        private:
            std::set<RequestFields> m_MandatoryFields;
            std::set<RequestFields> m_OptionalFields;
        };
    }
}
#endif //LAN_4GATELIBRARYCPP_FIELDSVALIDATOR_H
