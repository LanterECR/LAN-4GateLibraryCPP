#ifndef LAN_4GATELIBRARYCPP_REQUESTFIELDS_H
#define LAN_4GATELIBRARYCPP_REQUESTFIELDS_H

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            /// \brief Список полей, используемых для запроса к финансовому ПО LAN-4Tap
            enum class RequestField {
                EcrNumber, ///< Логический номер кассы, используемый для взаимодействия с LAN-4Tap
                EcrMerchantNumber, ///< Логический номер мерчанта в кассовом ПО
                OperationCode, ///< Код запрашиваемой операции
                Amount, ///< Сумма операции
                PartialAmount, ///< Часть оригинальной суммы. Используется в операциях отмены и возврата
                TipsAmount, ///< Сумма чаевых
                CashbackAmount, ///< Сумма кэшбека
                CurrencyCode, ///< Код валюты согласно ISO 4217
                RRN, ///< Retrieval Reference Number, полученный в ответ на предыдущую операцию
                AuthCode, ///< Код авторизации на хосте, полученный в ответ на предыдущю операцию
                ReceiptReference, ///< Номер чека в финансовом ПО LAN-4Tap. Может отличаться от номера чека в кассовом ПО
                TransactionID, ///< Идентификатор транзакции на хосте, полученный в ответ на предыдущую операцию
                CardDataEnc, ///< Зашифрованные данные карты
                OpenTags, ///< Теги, которые необходимо получить в открытом виде (формат TLV) в операции FastTrack
                EncTags, ///< Теги, которые необходимо получить в зашифрованном виде в операции FastTrack
                ProviderCode, ///< Код вендора платежа
                AdditionalInfo, ///< Дополнительные данные операции
                BonusBalance, ///< Баланс бонусного счета
                BonusAmount, ///< Сумма бонусов к оплате
                HashCardTrack2, ///< Кэшированный Track2
                PaymentProviderCode, ///< Код провайдера платежа
                PaymentParam1, ///< Первый параметр платежа
                PaymentParam2, ///< Второй параметр платежа
                PaymentParam3 ///< Третий параметр платежа

            };//enum RequestField

            /// Функция, возвращающая первый значимый элемент перечисления RequestField
            /// \return Первый элемент значимый перечисления RequestField
            constexpr RequestField getFirstRequestField() {
                return RequestField::EcrNumber;
            }

            /// Функция, возвращающая последний значимый элемент перечисления RequestField
            /// \return Последний элемент значимый перечисления RequestField
            constexpr RequestField getLastRequestField() {
                return RequestField::PaymentParam3;
            }
        }//namespace Request
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_REQUESTFIELDS_H
