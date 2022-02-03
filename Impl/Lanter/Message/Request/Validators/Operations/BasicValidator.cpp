#include <stdexcept>

#include <algorithm>

#include "BasicValidator.h"

#include <Lanter/Utils/RangeChecker.h>

namespace Lanter {
    namespace Message {
        namespace Request {

            BasicValidator::BasicValidator() {
                addBasicMandatoryFields();
            }//BasicValidator()

            void BasicValidator::appendMandatoryField(RequestField field) {
                auto value = static_cast<int64_t>(field);
                auto minValue = static_cast<int64_t>(getFirstRequestField());
                auto maxValue = static_cast<int64_t>(getLastRequestField());

                if (Utils::checkValueRange(value, minValue, maxValue)) {
                    m_MandatoryFields.insert(field);
                } else {
                    throw std::invalid_argument("Invalid field");
                }//check range

            }//appendMandatoryField()

            const std::set<RequestField> &BasicValidator::getMandatoryFields() const {
                return m_MandatoryFields;
            }//getMandatoryFields()

            void BasicValidator::appendOptionalField(RequestField field) {
                auto value = static_cast<int64_t>(field);
                auto minValue = static_cast<int64_t>(getFirstRequestField());
                auto maxValue = static_cast<int64_t>(getLastRequestField());

                if (Utils::checkValueRange(value, minValue, maxValue)) {
                    m_OptionalFields.insert(field);
                } else {
                    throw std::invalid_argument("Invalid field");
                }//check range

            }//appendOptionalField(

            const std::set<RequestField> &BasicValidator::getOptionalFields() const {
                return m_OptionalFields;
            }//getOptionalFields()

            bool BasicValidator::validate(const std::set<RequestField> &fields) {
                return std::all_of(m_MandatoryFields.begin(), m_MandatoryFields.end(),
                                   [&](RequestField field){
                                        return fields.find(field) != fields.end();
                                    });
            }//validate()


            void BasicValidator::addBasicMandatoryFields() {
                appendMandatoryField(RequestField::EcrNumber);
                appendMandatoryField(RequestField::OperationCode);
            }//addBasicMandatoryFields()

            void BasicValidator::addSpecificFields() {
                //Пустая реализация, чтобы можно было создать пустой валидатор
            }//addSpecificFields()
        }//namespace Request
    }//namespace Message
}//namespace Lanter