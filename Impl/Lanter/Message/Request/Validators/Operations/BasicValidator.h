#ifndef LAN_4GATELIBRARYCPP_BASICVALIDATOR_H
#define LAN_4GATELIBRARYCPP_BASICVALIDATOR_H

#include <set>

#include "Lanter/Message/Request/RequestField.h"

#include "Lanter/Message/Request/Validators/IValidator.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            /// \brief Базовый валидатор для всех типов операций
            class BasicValidator : public IValidator {
            public:
                /// \brief Конструктор вызывает метод addBasicMandatoryFields
                /// \sa addBasicMandatoryFields
                BasicValidator();

                ~BasicValidator() override = default;

                void appendMandatoryField(RequestField field) override;

                const std::set<RequestField> &getMandatoryFields() const override;

                void appendOptionalField(RequestField field) override;

                const std::set<RequestField> &getOptionalFields() const override;


                bool validate(const std::set<RequestField> &fields) override;

                /// \brief Добавляет специфичные для каждой операции мандатные поля. В данном классе пустой
                virtual void addSpecificFields();

            private:
                void addBasicMandatoryFields();

                std::set<RequestField> m_MandatoryFields;
                std::set<RequestField> m_OptionalFields;
            };//class BasicValidator
        }//namespace Request
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_BASICVALIDATOR_H
