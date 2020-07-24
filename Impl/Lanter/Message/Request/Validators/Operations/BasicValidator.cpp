#include <stdexcept>

#include "BasicValidator.h"

#include <Lanter/Utils/RangeChecker.h>

namespace Lanter {
    namespace Message {
        namespace Request {

            BasicValidator::BasicValidator() {
                addBasicMandatoryFields();
            }

            void BasicValidator::appendMandatoryField(RequestField field) {
                auto value = static_cast<int64_t>(field);
                auto minValue = static_cast<int64_t>(RequestField::FirstValue);
                auto maxValue = static_cast<int64_t>(RequestField::LastValue);

                if (Utils::checkValueRange(value, minValue, maxValue)) {
                    m_MandatoryFields.insert(field);
                } else {
                    throw std::invalid_argument("Invalid field");
                }
            }

            const std::set<RequestField> &BasicValidator::getMandatoryFields() const {
                return m_MandatoryFields;
            }

            void BasicValidator::appendOptionalField(RequestField field) {
                auto value = static_cast<int64_t>(field);
                auto minValue = static_cast<int64_t>(RequestField::FirstValue);
                auto maxValue = static_cast<int64_t>(RequestField::LastValue);

                if (Utils::checkValueRange(value, minValue, maxValue)) {
                    m_OptionalFields.insert(field);
                } else {
                    throw std::invalid_argument("Invalid field");
                }
            }

            const std::set<RequestField> &BasicValidator::getOptionalFields() const {
                return m_OptionalFields;
            }

            bool BasicValidator::validate(const std::set<RequestField> &fields) {
                for (auto field : m_MandatoryFields) {
                    auto iterator = fields.find(field);
                    if (iterator == fields.end()) {
                        return false;
                    }
                }
                return true;
            }


            void BasicValidator::addBasicMandatoryFields() {
                appendMandatoryField(RequestField::EcrNumber);
                appendMandatoryField(RequestField::OperationCode);
            }

            void BasicValidator::addSpecificFields() {

            }
        }//Request
    }
}//Lanter