#ifndef LAN_4GATELIBRARYCPP_BASICVALIDATOR_H
#define LAN_4GATELIBRARYCPP_BASICVALIDATOR_H

#include <set>

#include "Lanter/Message/Response/ResponseField.h"
#include "Lanter/Message/Response/Validators/IValidator.h"

namespace Lanter
{
    namespace Message
    {
        namespace Response
        {
            class BasicValidator : public IValidator
            {
            public:
                BasicValidator();

                ~BasicValidator() override = default;

                void appendMandatoryField(ResponseField field) override;

                const std::set<ResponseField> &getMandatoryFields() const override;

                void appendOptionalField(ResponseField field) override;

                const std::set<ResponseField> &getOptionalFields() const override;


                bool validate(const std::set<ResponseField> &fields) override;

                virtual void addSpecificFields();

            protected:
                virtual void clearMandatoryFields();
                virtual void clearOptionalFields();

            private:
                void addBasicMandatoryFields();

                std::set<ResponseField> m_MandatoryFields;
                std::set<ResponseField> m_OptionalFields;
            };
        }//Response
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_BASICVALIDATOR_H