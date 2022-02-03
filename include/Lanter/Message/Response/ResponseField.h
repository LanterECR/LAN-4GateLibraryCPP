#ifndef LAN_4GATELIBRARYCPP_RESPONSEFIELDS_H
#define LAN_4GATELIBRARYCPP_RESPONSEFIELDS_H

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            /// \brief Перечисление содержит все поля, используемые в ответах от финансового ПО LAN-4Tap
            enum class ResponseField {
                EcrNumber, ///< Логический номер кассы, используемый для взаимодействия с LAN-4Tap
                EcrMerchantNumber, ///< Логический номер мерчанта в кассовом ПО
                OperationCode, ///< Код запрашиваемой операции
                OriginalOperationCode, ///< Номер оригинальной операции
                TotalAmount, ///< Общая сумма операции
                PartialAmount, ///< Часть оригинальной суммы. Используется в операциях отмены и возврата
                AcquirerFeeAmount, ///< Комиссия эквайера
                TerminalFeeAmount, ///< Комиссия терминала
                TipsAmount, ///< Сумма чаевых
                CurrencyCode, ///< Код валюты согласно ISO 4217
                ReceiptReference, ///< Номер чека в финансовом ПО LAN-4Tap.
                RRN, ///< Retrieval Reference Number, полученный в ответ от хоста
                Status, ///< Статус выполнения операции
                OriginalOperationStatus, ///< Статус выполнения оригинальной операции
                TransDateTime, ///< Время выполнения операции на хосте
                TerminalDateTime, ///< Время выполнения операции на терминале
                CardPAN, ///< Маскированный PAN карты
                ExpireDate, ///< Срок действия карты
                CardholderName, ///< Имя держателя карты
                CardholderAuthMethod, ///< Способ авторизации держателя карты
                AuthCode, ///< Код авторизации на хосте
                ResponseCode, ///< Код ответа хоста или финансового ПО LAN-4Tap
                ResponseText, ///< Дополнительные данные ответа
                STAN, ///< Идентификатор транзакции в финансовом ПО LAN-4Tap
                TransactionID, ///< Идентификатор транзакции на хосте, полученный в ответ на предыдущую операцию
                TerminalID, ///< Идентификатор терминала на хосте
                CardEmvAid, ///< Идентификатор приложения карты
                CardAppName, ///< Название приложения карты
                CardInputMethod, ///< Метод обработки карты
                IssuerName, ///< Название платежной системы
                AdditionalInfo, ///< Дополнительные данные операции
                CardData, ///< Открытые данные карты
                CardDataEnc, ///< Зашифрованные данные карты
                MerchantID, ///< Идентификатор мерчанта на хосте
                TVR, ///< Данные работы с картой
                TSI, ///< Данные работы с картой
                TC, ///< Данные работы с картой
                CID, ///< Данные работы с картой
                KVR, ///< Данные работы с картой
                CDAResult, ///< Данные работы с картой
                SalesAmount, ///< Общая сумма оплат
                SaleCount, ///< Количество операций оплаты, выполненных с момента последней сверки итогов
                VoidAmount, ///< Общая сумма отмен
                VoidCount, ///< Количество операций отмены, выполненных с момента последней сверки итогов
                RefundAmount, ///< Общая сумма возвратов
                RefundCount, ///< Количество операций возврата, выполненных с момента последней сверки итогов
                SaleArray, ///< Массив, содержащий краткие сведения операций оплаты
                VoidArray, ///< Массив, содержащий краткие сведения операций отмены
                RefundArray ///< Массив, содержащий краткие сведения операций возврата
            };//enum ResponseField

            /// Функция, возвращающая первый значимый элемент перечисления ResponseField
            /// \return Первый элемент значимый перечисления ResponseField
            constexpr ResponseField getFirstResponseField() {
                return ResponseField::EcrNumber;
            }

            /// Функция, возвращающая последний значимый элемент перечисления ResponseField
            /// \return Последний элемент значимый перечисления ResponseField
            constexpr ResponseField getLastResponseField() {
                return ResponseField::RefundArray;
            }
        }//namespace Response
    }//namespace Message
}//namespace Lanter

#endif //LAN_4GATELIBRARYCPP_RESPONSEFIELDS_H
