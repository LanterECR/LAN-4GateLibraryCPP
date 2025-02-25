#include <stdexcept>

#include "BasicValidator.h"

#include <Lanter/Utils/RangeChecker.h>

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            BasicValidator::BasicValidator()
            {
                addBasicMandatoryFields();
            }

            void BasicValidator::appendMandatoryField(ResponseField field)
            {
                auto value = static_cast<int64_t>(field);
                auto minValue = static_cast<int64_t>(getFirstResponseField());
                auto maxValue = static_cast<int64_t>(getLastResponseField());

                if (Utils::checkValueRange(value, minValue, maxValue))
                {
                    m_MandatoryFields.insert(field);
                }
                else
                {
                    throw std::invalid_argument("Invalid field");
                }
            }

            const std::set<ResponseField> &BasicValidator::getMandatoryFields() const
            {
                return m_MandatoryFields;
            }

            void BasicValidator::appendOptionalField(ResponseField field)
            {
                auto value = static_cast<int64_t>(field);
                auto minValue = static_cast<int64_t>(getFirstResponseField());
                auto maxValue = static_cast<int64_t>(getLastResponseField());

                if (Utils::checkValueRange(value, minValue, maxValue))
                {
                    m_OptionalFields.insert(field);
                }
                else
                {
                    throw std::invalid_argument("Invalid field");
                }
            }

            const std::set<ResponseField> &BasicValidator::getOptionalFields() const
            {
                return m_OptionalFields;
            }

            bool BasicValidator::validate(const std::set<ResponseField> &fields)
            {
                for (auto field : m_MandatoryFields)
                {
                    auto iterator = fields.find(field);
                    if (iterator == fields.end())
                    {
                        return false;
                    }
                }

                return true;
            }

            void BasicValidator::addBasicMandatoryFields()
            {
                appendMandatoryField(ResponseField::EcrNumber);
                appendMandatoryField(ResponseField::OperationCode);
                appendMandatoryField(ResponseField::Status);
                appendOptionalField(ResponseField::ReceiptLine1);
                appendOptionalField(ResponseField::ReceiptLine2);
                appendOptionalField(ResponseField::ReceiptLine3);
                appendOptionalField(ResponseField::ReceiptLine4);
                appendOptionalField(ResponseField::ReceiptLine5);
                appendOptionalField(ResponseField::ApplicationLabel);
                appendOptionalField(ResponseField::FinalizationRequired);
            }

            void BasicValidator::addSpecificFields()
            {
            }

            void BasicValidator::clearMandatoryFields()
            {
                m_MandatoryFields.clear();
            }

            void BasicValidator::clearOptionalFields()
            {
                m_OptionalFields.clear();
            }
        }//Response
    }
}//Lanter