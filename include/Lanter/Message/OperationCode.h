#ifndef LAN_4GATELIBRARYCPP_OPERATIONCODES_H
#define LAN_4GATELIBRARYCPP_OPERATIONCODES_H

namespace Lanter {
    namespace Message {
        /// \brief Список поддерживаемых операций
        enum class OperationCode {
            NoOperation, ///< Значение-заглушка. Нет кода операции
            //Операции оплаты
            Sale = 1, ///< Оплата
            MOTO, ///< Mail order/Telephone order - оплата заказа через e-mail или телефон
            QuickPayment, ///< Оплата через систему быстрых платежей ЦБ РФ
            AliPay, ///< Оплата через систему AliPay
            Payment, ///< Операция оплаты счета

            PreAuth = 200, ///< Преавторизация
            SalesCompletion, ///< Завершение преавторизации
            QuickPaymentStatus, ///< Проверка статуса оплаты через СБП
            RequestCS, ///< Запрос задолжности на CashService
            NotificationCS, ///< Оповещение CashService об оплате
            RepeatLastN, ///< Запрос статуса на CashService

            FastTrack = 300, ///< Получение зашифрованный и открытых тегов карты
			ECertGetRequisites, ///< запрос реквизитов по карте
			ECertPayment, ///< оплата электронным сертификатом
			ECertRefund, ///< возврат по электронным сертификатам
            CardVerification, ///< Верефикация карты на хосте(для траспортного проекта)

            //Операции отмены
            Void = 400, ///< Отмена по номеру чека
            VoidPartialSale, ///< Частичная отмена по номеру чека
            VoidPreAuth, ///< Отмена преавторизации

            //Операции возврата
            Refund = 500, ///< Возврат с m_RRN
            RefundWithoutRRN, ///< Возврат без m_RRN
            QuickPaymentRefund, ///< Возврат через СБП
            QuickPaymentRefundStatus, ///<  Проверка статуса возврата через СБП

            //Служебные операции
            Registration = 800, ///< Регистрация в транспортом сервисе LAN-4Gate
            TestCommunication, ///< Проверка связи с финансовым ПО LAN-4Tap
            Test, ///< Проверки связи финансового ПО LAN-4Tap с хостом
            PrintLastReceipt, ///< Печать копии чека и получение данных последней выполненной финансовой операции
            GetLastOperation, ///< Получение данных последней выполненной финансовой операции
            PrintReceiptCopy, ///< Печать копии чека и получение данных операции по номеру чека
            PrintDetailReport, ///< Печать детального отчета и получение сведений о нем
            PrintSummaryReport, ///< Печать краткого отчета и получение сведений о нем
            Settlement, ///< Сверка итогов
            KeyDownload, ///< Загрузка рабочих ключей финансовым ПО LAN-4Tap
            Initialization, ///< Загрузка параметров финансового ПО LAN-4Tap
            UpdateSW, ///< Обновление финансового ПО LAN-4Tap
            PrintCommsInfo, ///< Печать и получение данных о настроенных коммуникациях в финансовом ПО LAN-4Tap
            PrintSoftInfo, ///< Печать и получение данных о финансовом ПО LAN-4Tap
            FinalizeTransaction, ///< Подтверждение на завершение финансовой операции финансовым ПО LAN-4Tap
            GetCurrentPrinter, ///< Получение информации о текущем устройстве печати
            SetCurrentPrinter, ///< Установка текущего устройства печати
            SelfTest, ///< Самопроверка финансового ПО LAN-4Tap
            GetOperationCopy, ///< Получение данных операции по номеру чека
            DisplayQR, ///< Отображение информации в виде QR кода финансовым ПО LAN-4Tap
            SendLogs, ///< Отправка логов с терминала на сервер
            SetLogLevel, ///< Установка уровня логирования
            LicenseActivationFile, ///< Лицензирование ПО LAN-4Tap с помощью файла активации
            LicenseActivationServer, ///< Лицензирование ПО LAN-4Tap с помощью сервера активации
            ClearReversal, ///< Удаление реверса в финансовом ПО LAN-4Tap
            ClearAllJournals, ///< Очистка всех журналов в финансовом ПО LAN-4Tap
            TakeLockCard, ///< Захватить карту внешним ридером
            EjectCard,  ///< Возврат карты из внешнего ридера с возвратом ответа на кассу без ожидания изъятия карты
            EjectWaitCard, ///< Возврат карты из внешнего ридера с возвратом ответа на кассу с ожиданием изъятия карты
            IsCardPresent, ///< Статус наличия карты во внешнем ридере
            UploadPending = 830, ///< Выгрузка отложенной операции на финансовый хост
            BonusBalance, ///< Запрос баланса бонусов
            GrabEjectCard, ///< Протягивание карты в лоток карт
            GetMerchantList, ///< Возвращает наименования ErcNumber
            PrintMerchantSettlement, ///< Запрос печати чека сверки по мерчанту, чек берётся из памяти.
            UploadDelayed, ///< Доавторизация отложенных операций

            //Отдельный тип операции для представления массивов операции DetailReport
            ArrayElement = 1000 ///< Фиктивный код операции для создания элементов массива
        };//enum OperationCode

        /// Функция, возвращающая первый значимый элемент перечисления OperationCode
        /// \return Первый элемент значимый перечисления OperationCode
        constexpr OperationCode getFirstOperationCode()
        {
            return OperationCode::Sale;
        }

        /// Функция, возвращающая последний значимый элемент перечисления OperationCode
        /// \return Последний элемент значимый перечисления OperationCode
        constexpr OperationCode getLastOperationCode()
        {
            return OperationCode::ArrayElement;
        }

    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_OPERATIONCODES_H
