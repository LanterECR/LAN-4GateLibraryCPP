//
// Created by Владимир Лысенков on 21.06.2020.
//

#include <stdexcept>

#include "BasicValidator.h"

#include <Lanter/Utils/RangeChecker.h>

namespace Lanter {
    namespace Request {

        BasicValidator::BasicValidator() {
            addBasicMandatoryFields();
        }

        void BasicValidator::appendMandatoryField(RequestFields field) {
            auto value = static_cast<int64_t>(field);
            auto minValue = static_cast<int64_t>(RequestFields::FirstValue);
            auto maxValue = static_cast<int64_t>(RequestFields::LastValue);

            if (Utils::checkValueRange(value, minValue, maxValue)) {
                m_MandatoryFields.insert(field);
            } else {
                throw std::invalid_argument("Invalid field");
            }
        }

        const std::set<RequestFields> &BasicValidator::getMandatoryFields() const {
            return m_MandatoryFields;
        }

        void BasicValidator::appendOptionalField(RequestFields field) {
            auto value = static_cast<int64_t>(field);
            auto minValue = static_cast<int64_t>(RequestFields::FirstValue);
            auto maxValue = static_cast<int64_t>(RequestFields::LastValue);

            if (Utils::checkValueRange(value, minValue, maxValue)) {
                m_OptionalFields.insert(field);
            } else {
                throw std::invalid_argument("Invalid field");
            }
        }

        const std::set<RequestFields> &BasicValidator::getOptionalFields() const {
            return m_OptionalFields;
        }

        bool BasicValidator::validate(const std::set<RequestFields> &fields) {
            for (auto field : m_MandatoryFields) {
                auto iterator = fields.find(field);
                if (iterator == fields.end()) {
                    return false;
                }
            }
            return true;
        }


        void BasicValidator::addBasicMandatoryFields() {
            appendMandatoryField(RequestFields::EcrNumber);
            appendMandatoryField(RequestFields::OperationCode);
        }

        void BasicValidator::addSpecificFields() {

        }
    }//Request
}//Lanter