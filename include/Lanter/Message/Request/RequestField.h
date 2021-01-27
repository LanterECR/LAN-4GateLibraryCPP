#ifndef LAN_4GATELIBRARYCPP_REQUESTFIELDS_H
#define LAN_4GATELIBRARYCPP_REQUESTFIELDS_H

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
                CardDataEnc, ///< Зашированные данные карты
                OpenTags, ///< Теги, которые необходимо получить в открытом виде (формат TLV) в операции FastTrack
                EncTags, ///< Теги, которые необходимо получить в зашифрованном виде в операции FastTrack
                ProviderCode, ///< Код вендора платежа
                AdditionalInfo, ///< Дополнительные данные операции
                //диапазон полей
                FirstValue = EcrNumber, ///< Ссылка на первый элемент перечисления
                LastValue = AdditionalInfo ///< Ссылка на последний элемент перечисления
            };//enum RequestField
        }//namespace Request
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_REQUESTFIELDS_H
