#ifndef LAN_4GATELIBRARYCPP_CARDHOLDERAUTHMETHOD_H
#define LAN_4GATELIBRARYCPP_CARDHOLDERAUTHMETHOD_H

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            /// \brief Список возможных значений поля ResponseField::CardholderAuthMethod в ответе финансового ПО LAN-4Tap
            enum class CardholderAuthMethod {
                NoMethod = -1,
                NoVerification, ///< Операция не требует подтверждения
                PinVerification, ///< Введен пин-код
                PaperSignatureVerification, ///< Необходимо получить подпись клиента на чеке и проверить ее
                ClientDeviceVerification, ///< Клиент выполнил проверку на своем устройстве
                //Диапазоны значений
                FirstValue = NoVerification, ///< Ссылка на первый элемент перечисления
                LastValue = ClientDeviceVerification ///< Ссылка на последний элемент перечисления
            };

            /// Функция, возвращающая первый значимый элемент перечисления CardholderAuthMethod
            /// \return Первый элемент значимый перечисления CardholderAuthMethod
            constexpr CardholderAuthMethod getFirstCardholderAuthMethod() {
                return CardholderAuthMethod::NoVerification;
            }

            /// Функция, возвращающая последний значимый элемент перечисления CardholderAuthMethod
            /// \return Последний элемент значимый перечисления CardholderAuthMethod
            constexpr CardholderAuthMethod getLastCardholderAuthMethod() {
                return CardholderAuthMethod::ClientDeviceVerification;
            }
            
        }//namespace Response
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_CARDHOLDERAUTHMETHOD_H
