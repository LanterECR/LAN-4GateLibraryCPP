#ifndef LAN_4GATELIBRARYCPP_STATUS_H
#define LAN_4GATELIBRARYCPP_STATUS_H

#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            /// \brief Список возможных значений поля ResponseField::Status в ответе финансового ПО LAN-4Tap
            enum class Status {
                NoStatus, ///< Значение-заглушка. Соответствует неизвестному статусу
                Success = 1, ///< Операция успешно выполнена
                Error, ///< Ошибка выполнения операции
                Decline, ///< Операция отклонена хостом
                CommunicationError, ///< Ошибка связи
                OperationIsAutoReversal, ///< Операция находится в состоянии автореверса
                EcrAlreadyRegistered, ///< Данный логический номер кассового ПО уже зарегистрирован в сервисе LAN-4Gate
                ConnectionLimitReached, ///< Достигнут предел подключений к сервису LAN-4Gate
                ReceiptNotFound, ///< Чек не найден
                TotalsNotAgreed, ///< Итоги не совпали
                NeedSettlement, ///< Необходима сверка итогов
                CanceledByTerminal, ///< Выполнение операции отменено в финансовом ПО LAN-4Tap
                FastTrackKeyError,///< Ошибка ключей шифрования для операции FastTrack
                OperationPending, ///< Операция отложена
                UploadPendingRequired, ///< Требуется выгрузка операций
                UnknownPaymentProvider, ///< Неизвестный платежный провайдер
                InvalidTAK, ///< Неверный ТАК
                LicenseAbsent, ///< Отсутствует лицензия
                TrVoidHasCanceled ///< Транзакция отмены была отменена
            };//enum Status
            /// Функция, возвращающая первый значимый элемент перечисления Status
            /// \return Первый элемент значимый перечисления Status
            constexpr Status getFirstStatus() {
                return Status::Success;
            }

            /// Функция, возвращающая последний значимый элемент перечисления Status
            /// \return Последний элемент значимый перечисления Status
            constexpr Status getLastStatus() {
                return Status::TrVoidHasCanceled;
            }
        }//namespace Response
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_STATUS_H
