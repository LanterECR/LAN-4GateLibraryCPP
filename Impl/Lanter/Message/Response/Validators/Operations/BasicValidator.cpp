//
// Created by Владимир Лысенков on 21.06.2020.
//

#include <stdexcept>

#include "BasicValidator.h"

#include <Lanter/Utils/RangeChecker.h>

namespace Lanter {
    namespace Message {
        namespace Response {

            BasicValidator::BasicValidator() {
                addBasicMandatoryFields();
            }

            void BasicValidator::appendMandatoryField(ResponseFields field) {
                auto value = static_cast<int64_t>(field);
                auto minValue = static_cast<int64_t>(ResponseFields::FirstValue);
                auto maxValue = static_cast<int64_t>(ResponseFields::LastValue);

                if (Utils::checkValueRange(value, minValue, maxValue)) {
                    m_MandatoryFields.insert(field);
                } else {
                    throw std::invalid_argument("Invalid field");
                }
            }

            const std::set<ResponseFields> &BasicValidator::getMandatoryFields() const {
                return m_MandatoryFields;
            }

            void BasicValidator::appendOptionalField(ResponseFields field) {
                auto value = static_cast<int64_t>(field);
                auto minValue = static_cast<int64_t>(ResponseFields::FirstValue);
                auto maxValue = static_cast<int64_t>(ResponseFields::LastValue);

                if (Utils::checkValueRange(value, minValue, maxValue)) {
                    m_OptionalFields.insert(field);
                } else {
                    throw std::invalid_argument("Invalid field");
                }
            }

            const std::set<ResponseFields> &BasicValidator::getOptionalFields() const {
                return m_OptionalFields;
            }

            bool BasicValidator::validate(const std::set<ResponseFields> &fields) {
                for (auto field : m_MandatoryFields) {
                    auto iterator = fields.find(field);
                    if (iterator == fields.end()) {
                        return false;
                    }
                }
                return true;
            }


            void BasicValidator::addBasicMandatoryFields() {
                appendMandatoryField(ResponseFields::EcrNumber);
                appendMandatoryField(ResponseFields::OperationCode);
                appendMandatoryField(ResponseFields::Status);
            }

            void BasicValidator::addSpecificFields() {

            }
        }//Response
    }
}//Lanter