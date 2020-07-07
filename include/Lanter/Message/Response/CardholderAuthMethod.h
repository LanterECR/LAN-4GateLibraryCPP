//
// Created by Владимир Лысенков on 25.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_CARDHOLDERAUTHMETHOD_H
#define LAN_4GATELIBRARYCPP_CARDHOLDERAUTHMETHOD_H
namespace Lanter {
    namespace Response {
        /// \brief Список возможных значений поля CardholderAuthMethod в ответе финансового ПО LAN-4Tap
        enum class CardholderAuthMethod {
            NoMethod = -1,
            NoVerification, ///< Операция не требует подтверждения
            PinVerification, ///< Введен пин-код
            PaperSignatureVerification, ///< Необходимо получить подпись клиента на чеке и проверить ее
            ClientDeviceVerification, ///< Клиент выполнил проверку на своем устройстве
            //Диапазоны значений
            FirstValue = NoVerification,
            LastValue = ClientDeviceVerification
        };
    }
}
#endif //LAN_4GATELIBRARYCPP_CARDHOLDERAUTHMETHOD_H
