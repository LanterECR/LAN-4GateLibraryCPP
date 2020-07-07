//
// Created by Владимир Лысенков on 21.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_BASICVALIDATOR_H
#define LAN_4GATELIBRARYCPP_BASICVALIDATOR_H

#include <set>

#include "Lanter/Message/Request/RequestFields.h"

#include "Lanter/Message/Request/Validators/IValidator.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            class BasicValidator : public IValidator {
            public:
                BasicValidator();

                ~BasicValidator() override = default;

                void appendMandatoryField(RequestFields field) override;

                const std::set<RequestFields> &getMandatoryFields() const override;

                void appendOptionalField(RequestFields field) override;

                const std::set<RequestFields> &getOptionalFields() const override;


                bool validate(const std::set<RequestFields> &fields) override;

                virtual void addSpecificFields();

            private:
                void addBasicMandatoryFields();

                std::set<RequestFields> m_MandatoryFields;
                std::set<RequestFields> m_OptionalFields;
            };
        }//Request
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_BASICVALIDATOR_H
