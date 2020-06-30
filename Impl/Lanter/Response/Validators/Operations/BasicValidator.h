//
// Created by Владимир Лысенков on 21.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_BASICVALIDATOR_H
#define LAN_4GATELIBRARYCPP_BASICVALIDATOR_H

#include <set>

#include "Lanter/Response/ResponseFields.h"

#include "Lanter/Response/Validators/IValidator.h"

namespace Lanter {
    namespace Response {
        class BasicValidator : public IValidator{
        public:
            BasicValidator();

            ~BasicValidator() override = default;
            void appendMandatoryField(ResponseFields field) override;

            const std::set<ResponseFields> &getMandatoryFields() const override;

            void appendOptionalField(ResponseFields field) override;

            const std::set<ResponseFields> &getOptionalFields() const override;


            bool validate(const std::set<ResponseFields> &fields) override;

            virtual void addSpecificFields();

        private:
            void addBasicMandatoryFields();

            std::set<ResponseFields> m_MandatoryFields;
            std::set<ResponseFields> m_OptionalFields;
        };
    }//Response
}//Lanter
#endif //LAN_4GATELIBRARYCPP_BASICVALIDATOR_H
