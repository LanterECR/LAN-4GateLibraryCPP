#ifndef LAN_4GATELIBRARYCPP_IVALIDATOR_H
#define LAN_4GATELIBRARYCPP_IVALIDATOR_H

#include <set>

#include "Lanter/Message/Request/RequestField.h"

namespace Lanter
{
    namespace Message
    {
        namespace Request
        {
            ///\brief Интерфейсный класс для валидатора полей запроса
            class IValidator
            {
            public:
                virtual ~IValidator() = default;

                /// Добавить обязательное поле к списку
                /// \param[in] field Поле, добавляемое к списку
                /// \sa RequestField
                virtual void appendMandatoryField(RequestField field) = 0;

                /// Получить список обязательных полей
                /// \return Список установленных обязательных полей
                /// \sa RequestField
                virtual const std::set<RequestField> &getMandatoryFields() const = 0;

                /// Добавить опциональное поле к списку
                /// \param[in] field Поле, добавляемое к списку
                /// \sa RequestField
                virtual void appendOptionalField(RequestField field) = 0;

                /// Получить список опциональных полей
                /// \return Список установленных опциональных полей
                /// \sa RequestField
                virtual const std::set<RequestField> &getOptionalFields() const = 0;

                /// Провести валидацию полей запроса в соответствии с установленными обязательным и опциональными полями
                /// \param[in] fields
                /// \return True, если все обязательные поля установлены
                virtual bool validate(const std::set<RequestField> &fields) = 0;
            };//class IValidator
        }//namespace Request
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_IVALIDATOR_H