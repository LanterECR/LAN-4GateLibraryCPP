#ifndef LAN_4GATELIB_ILAN4GATE_H
#define LAN_4GATELIB_ILAN4GATE_H

#include <cstddef>
#include <memory>

#include "Lanter/Utils/VisibilityMacroses.h"

#include "Lanter/Communication/ICommunication.h"

#include "Lanter/Message/Request/IRequestData.h"
#include "Lanter/Message/Response/IResponseData.h"
#include "Lanter/Message/Notification/INotificationData.h"
#include "Lanter/Message/Interaction/IInteractionData.h"

#include "Callback/RequestCallback.h"
#include "Callback/ResponseCallback.h"
#include "Callback/NotificationCallback.h"
#include "Callback/InteractionCallback.h"
#include "Callback/ConnectionCallback.h"

namespace Lanter {
    namespace Manager {
        /// \brief Предоставляет интерфейс взаимодействия с функционалом библиотеки
        class LANTER_VISIBILITY ILan4Gate {
        public:
            /// \brief Статус запуска ILan4Gate
            enum class Status {
                Success, //!< Успешно запущено
                Error //!< Произошла ошибка при запуске
            };

            /// \brief Способ вызова колбеков
            /// Объединение Async | Sync будет интерпретировано, как Sync
            enum class CallbackNotificationType {
                Async, //!< Все колбеки вызываются из того же потока, в котором работает метод doLan4Gate
                Sync///< Все колбеки вызываются из нового потока
            };

             virtual ~ILan4Gate() = default;

            /// \brief Устанавливает логический идентификатор кассового ПО. Значение по умолчанию 1
            /// \param[in] ecrNumber Логический идентификатор кассового ПО в диапазоне [1, 999]
            /// \return true, если поле успешно установлено
             virtual bool setEcrNumber(int16_t ecrNumber) = 0;

             /// \brief Возвращает логический идентификатор кассового ПО
             /// \return Логический идентификатор в диапазоне [1,999]. По умолчанию равен 1
             virtual int16_t getEcrNumber() const = 0;

            /// \brief Запускает цикл обработки запросов библиотеки
            /// \return Одно из значений перечисления Status
            /// \sa Status
            virtual Status start() = 0;

            /// \brief Останавливает цикл обработки
            /// \return Одно из значений перечисления Status
            virtual Status stop() = 0;

            /// \brief Возвращает состояние цикла обработки
            /// \return true, если цикл запущен и выполняется
            /// \sa Status
            virtual bool isStarted() const = 0;

            /// \brief Выполняет одну итерацию цикла обработки запросов.
            /// Используется потоком библиотеки.
            /// Может быть использован в потоке приложения
            virtual void doLan4Gate() = 0;

            /// \brief Запускает цикл обработки запросов в отдельном потоке
            /// Если планируется встраивание цикла обработки в собственный поток, то данный метод не нужно вызывать
            /// \return Одно из значений перечисления Status
            /// \sa Status
            virtual Status runOnThread() = 0;

            /// \brief Устанавливает соединение в качестве основного используемого
            /// \param[in] communication указатель на используемое соединение
            /// \return true, если соединение успешно установлено
            /// \sa Communication::ICommunication
            virtual bool setCommunication(std::shared_ptr<Communication::ICommunication> communication) = 0;

            /// \brief Сбрасывает указатель переданного соединения
            /// \return true, если успешно сброшен указатель
            virtual bool resetCommunication() = 0;

            /// \brief Возвращает указатель установленного соединения
            /// \return nullptr, если соединение не установлено или было сброшено
            virtual std::shared_ptr<Communication::ICommunication> getCommunication() const = 0;

            /// \brief Устанавливает способ вызова колбеков
            /// \param[in] type
            /// \return ture, если удалось сменить тип
            /// \sa CallbackNotificationType
            virtual bool setCallbackNotificationType(CallbackNotificationType type) = 0;

            /// \brief Возвращает установленный способ вызова колбеков
            /// \return Установленный способ вызова колбеков. По умолчанию Async
            /// \sa CallbackNotificationType
            virtual CallbackNotificationType getCallbackNotificationType() const = 0;

            /// \brief Добавляет колбек в список слушателей для получения данных запроса
            /// \param[in] callback имплементация интерфейса Callback::RequestCallback
            /// \return id зарегистрированного колбека
            /// \sa Message::Request::IRequestData
            /// \sa Callback::RequestCallback
            virtual size_t addRequestCallback(Callback::RequestCallback &callback) = 0;

            /// \brief Удаляет колбек запроса из списка
            /// \param[in] id идентификатор колбека
            /// \return true, если успешно удалено
            virtual bool removeRequestCallback(size_t id) = 0;

            /// \brief Возвращает количество зарегистрированных колбеков для получения данных запроса
            /// \return количество зарегистрированных колбеков
            virtual size_t requestCallbacksCount() const = 0;

            /// \brief Добавляет колбек в список слушателей для получения данных ответа
            /// \param[in] callback имплементация интерфейса Callback::ResponseCallback
            /// \return id зарегистрированного колбека
            /// \sa Message::Response::IResponseData
            /// \sa Callback::ResponseCallback
            virtual size_t addResponseCallback(Callback::ResponseCallback &callback) = 0;

            /// \brief Удаляет колбек ответа из списка
            /// \param[in] id идентификатор колбека
            /// \return true, если успешно удалено
            virtual bool removeResponseCallback(size_t id) = 0;

            /// \brief Возвращает количество зарегистрированных колбеков для получения данных ответа
            /// \return количество зарегистрированных колбеков
            virtual size_t responseCallbacksCount() const = 0;

            /// \brief Добавляет колбек в список слушателей для получения данных уведомления
            /// \param[in] callback имплементация интерфейса Callback::NotificationCallback
            /// \return id зарегистрированного колбека
            /// \sa Message::Notification::INotificationData
            /// \sa Callback::NotificationCallback
            virtual size_t addNotificationCallback(Callback::NotificationCallback &callback) = 0;

            /// \brief Удаляет колбек уведомления из списка
            /// \param[in] id идентификатор колбека
            /// \return true, если успешно удалено
            virtual bool removeNotificationCallback(size_t id) = 0;

            /// \brief Возвращает количество зарегистрированных колбеков для получения данных уведомления
            /// \return количество зарегистрированных колбеков
            virtual size_t notificationCallbacksCount() const = 0;

            /// \brief Добавляет колбек в список слушателей для получения данных команд взаимодействия
            /// \param[in] callback имплементация интерфейса Callback::InteractionCallback
            /// \return id зарегистрированного колбека
            /// \sa Message::Interaction::IInteractionData
            /// \sa Callback::InteractionCallback
            virtual size_t addInteractionCallback(Callback::InteractionCallback &callback) = 0;

            /// \brief Удаляет колбек команд взаимодействия из списка
            /// \param[in] id идентификатор колбека
            /// \return true, если успешно удалено
            virtual bool removeInteractionCallback(size_t id) = 0;

            /// \brief Возвращает количество зарегистрированных колбеков для получения данных команд взаимодействия
            /// \return количество зарегистрированных колбеков
            virtual size_t interactionCallbacksCount() const = 0;

            /// \brief Добавляет колбек в список слушателей для получения уведомления о подключении
            /// \param[in] callback имплементация интерфейса Callback::ConnectionCallback
            /// \return id зарегистрированного колбека
            /// \sa Callback::ConnectionCallback
            virtual size_t addConnectionCallback(Callback::ConnectionCallback &callback) = 0;

            /// \brief Удаляет колбек уведомления из списка
            /// \param[in] id идентификатор колбека
            /// \return true, если успешно удалено
            virtual bool removeConnectionCallback(size_t id) = 0;

            /// \brief Возвращает количество зарегистрированных колбеков для получения уведомления о подключении
            /// \return количество зарегистрированных колбеков
            virtual size_t connectionCallbacksCount() const = 0;

            /// \brief Возвращает подготовленный объект запроса с заполненными полями EcrNumber и OperationCode
            /// \param[in] operationCode Код операции, для которой необходимо подготовить объект
            /// \return nullptr, если не удалось создать объект запроса
            /// \sa Message::Request::RequestDataFactory
            virtual std::shared_ptr<Message::Request::IRequestData> getPreparedRequest(Message::OperationCode operationCode) = 0;


            /// \brief Возвращает подготовленный объект ответа с заполненными полями EcrNumber и OperationCode
            /// \param[in] operationCode Код операции, для которой необходимо подготовить объект ответа
            /// \return nullptr, если не удалось создать объект
            /// \sa Message::Response::ResponseDataFactory
            virtual std::shared_ptr<Message::Response::IResponseData> getPreparedResponse(Message::OperationCode operationCode) = 0;

            /// \brief Возвращает подготовленный объект уведомления с заполненным полем NotificationCode
            /// \param[in] notificationCode Код уведомления, для которого необходимо создать объект. По умолчанию NoNotification
            /// \return nullptr, если не удалось создать объект
            /// \sa Message::Notification::NotificationDataFactory
            virtual std::shared_ptr<Message::Notification::INotificationData> getPreparedNotification(Message::Notification::NotificationCode notificationCode) = 0;

            /// \brief Возвращает подготовленный объект взаимодействия с заполненным полем InteractionCode
            /// \param[in] interactionCode Код взаимодействия, для которого необходимо создать объект. По умолчанию NoInteraction
            /// \return nullptr, если не удалось создать объект
            /// \sa Message::Interaction::InteractionDataFactory
            virtual std::shared_ptr<Message::Interaction::IInteractionData> getPreparedInteraction(Message::Interaction::InteractionCode interactionCode) = 0;

            /// \brief Отправляет сообщение запроса
            /// \param[in] request объект запроса, который необходимо отправить
            /// \return true если сообщение отправлено
            virtual bool sendMessage(std::shared_ptr<Message::Request::IRequestData> request) = 0;

            /// \brief Отправляет сообщение ответа
            /// \param[in] response объект ответа, который необходимо отправить
            /// \return true если сообщение отправлено
            virtual bool sendMessage(std::shared_ptr<Message::Response::IResponseData> response) = 0;

            /// \brief Отправляет сообщение уведомления
            /// \param[in] notification объект уведомления, который необходимо отправить
            /// \return true если сообщение отправлено
            virtual bool sendMessage(std::shared_ptr<Message::Notification::INotificationData> notification) = 0;

            /// \brief Отправляет сообщение взаимодействия
            /// \param[in] interaction объект взаимодействия, который необходимо отправить
            /// \return true если сообщение отправлено
            virtual bool sendMessage(std::shared_ptr<Message::Interaction::IInteractionData> interaction) = 0;
        };
    }
}

#endif //LAN_4GATELIB_ILAN4GATE_H
