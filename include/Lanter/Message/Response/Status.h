#ifndef LAN_4GATELIBRARYCPP_STATUS_H
#define LAN_4GATELIBRARYCPP_STATUS_H
namespace Lanter {
    namespace Message {
        namespace Response {
            /// \brief Список возможных значений поля ResponseField::Status в ответе финансового ПО LAN-4Tap
            enum class Status {
                NoStatus,
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
                //Диапазон значений
                FirstValue = Success, ///< Ссылка на первый элемент перечисления
                LastValue = FastTrackKeyError ///< Ссылка на последний элемент перечисления
            };
        } //Response
    }
} //Lanter
#endif //LAN_4GATELIBRARYCPP_STATUS_H
