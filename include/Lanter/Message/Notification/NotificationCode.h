#ifndef LAN_4GATELIBRARYCPP_NotificationCode_H
#define LAN_4GATELIBRARYCPP_NotificationCode_H

namespace Lanter {
    namespace Message {
        namespace Notification {
            /// \brief Список поддерживаемых уведомлений
            enum class NotificationCode {
                NoNotification, ///< Значение по умолчанию. Уведомления нет
                ReversalUploadingError, ///< Ошибка выгрузки реверса
                IncorrectVoidAmount, ///< Некорректная сумма отмены
                IncorrectRefundAmount, ///< Некорректная сумма возврата
                PrinterError, ///< Ошибка принтера
                ReceiptPrintingError, ///< Ошибка печати чека
                PaperOut, ///< Закончилась бумага
                CurrencyNotSupported, ///< Валюта не поддерживается
                Connecting, ///< Установка соединения с сервером
                Executing, ///< Выполнение операции
                TapOrInsertCard, ///< Приложите или вставьте карту
                InsertCard, ///< Вставьте карту
                EjectCard, ///< Извлеките карту
                InsertMagStripe, ///< Проведите карту магнитной полосой
                CardReading, ///< Чтение карты
                CardReadingError, ///< Ошибка чтения карты
                CardReadingErrorTryAgain, ///< Ошибка чтения карты, повторите попытку
                CardReadingErrorUseAnother, ///< Ошибка чтения карты, используйте другую карту
                MagStripeReadingError, ///< Ошибка чтения магнитной полосы
                CtlsDeclinedUseChip, ///< Операция по бесконтактному интерфейсу отклонена, используйте контактный интерфейс
                ChipDeclinedUseMagStripe, ///< Операция по контактному интерфейсу отклонена, используйте магнитную полосу
                ReaderError, ///< Ошибка ридера карт
                ChipPaymentNotAllowed, ///< Оплата по контактному интерфейсу запрещена
                CtlsPaymentNotAllowed, ///< Оплата по бесконтактному интерфейсу запрещена
                MagStripePaymentNotAllowed, ///< Оплата магнитной полосой запрещена
                FallbackNotAllowed, ///< Фолбэк запрещен
                CardBlocked, ///< Карта заблокирована
                AccountBlocked, ///< Счет заблокирован
                CardInBlackList, ///< Карта находится в черном списке
                DeclinedCardExpired, ///< Отклонено. Срок действия карты истек
                DeclinedSuspectedFraud, ///< Отклонено. Подозревается мошенничество
                DeclinedCallAcquirer, ///< Отклонено. Обратитесь в обслуживающий банк
                DeclinedCardRestricted, ///< Отклонено. Ограничения карты
                DeclinedCallIssuerBank, ///< Отклонено. Свяжитесь с эмитентом карты
                DeclinedNotAllowedForCard, ///< Отклонено. Запрещено для карты
                DeclinedNotAllowedForCardholder, ///< Отклонено. Запрещено для держателя карты
                DeclinedSecurityViolation, ///< Отклонено. Нарушение безопасности
                EnterPin, ///< Введите пин-код
                PinEntered, ///< Пин-код введен
                OfflinePinEntered, ///< Введен офлайн пин-код
                IncorrectPinTryAgain, ///< Неверный пин-код, повторите попытку
                OfflinePinBlocked, ///< Офлайн пин-код заблокирован
                OfflinePinLastTry, ///< Последняя попытка ввода офлайн пин-кода
                OfflinePinTryCount, ///< Осталось попыток ввода офлайн пин-кода
                DeclinedPinEntryLimitReached, ///< Отклонено. Достигнут предел попыток ввода пин-кода
                DeclinedIncorrectPin, ///< Отклонено. Неверный пин-код
                CriticalBatteryLevel, ///< Критический уровень заряда батареи. Выполнение операции невозможно
                DangerBatteryLevel, ///< Опасный уровень заряда батареи
                ErrorPinMandatory, ///< Ошибка. Ввод пин-кода обязателен
                ErrorPinInput, ///< Ошибка ввода пин-кода
                MsrDeclinedUseChip, ///< Операция по магнитной полосе отклонена. Используйте контактный интерфейс
                PinEntryTimeout, ///< Тайм-аут ввода пин-кода
                QrShowing, ///< Отображение QR кода
                //Диапазон
                FirstValue = ReversalUploadingError, ///< Ссылка на первый элемент перечисления
                LastValue = QrShowing ///< Ссылка на последний элемент перечисления
            };//enum NotificationCode
        }//namespace Notification
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_NotificationCode_H
