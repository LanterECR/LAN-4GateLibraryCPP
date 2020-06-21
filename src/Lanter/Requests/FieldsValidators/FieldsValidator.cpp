//
// Created by Владимир Лысенков on 21.06.2020.
//

#include "Lanter/Requests/FieldsValidators/FieldsValidator.h"

namespace Lanter {
    namespace Requests {
        void FieldsValidator::appendMandatoryField(RequestFields field) {
            m_MandatoryFields.insert(field);
        }

        const std::set<RequestFields> &FieldsValidator::getMandatoryFields() const {
            return m_MandatoryFields;
        }
    }
}