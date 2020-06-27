//
// Created by Владимир Лысенков on 20.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_REQUESTFIELDS_H
#define LAN_4GATELIBRARYCPP_REQUESTFIELDS_H
namespace Lanter {
    namespace Request {
        /// \brief Перечисление содержит все поля, используемые для запросов к финансовому ПО LAN-4Tap
        enum class RequestFields {
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
            FirstValue = EcrNumber, ///< Ссылка на первое поле в enum
            LastValue = AdditionalInfo ///< Ссылка на последнее поле в enum
        };
    }
}
#endif //LAN_4GATELIBRARYCPP_REQUESTFIELDS_H
