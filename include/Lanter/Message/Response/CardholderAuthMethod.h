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
        }//namespace Response
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_CARDHOLDERAUTHMETHOD_H
