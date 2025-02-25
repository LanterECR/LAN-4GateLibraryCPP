#ifndef LAN_4GATELIB_DOXYGENMAINPAGE_H
#define LAN_4GATELIB_DOXYGENMAINPAGE_H

///\mainpage
/// Для использования библиотеки подключите заголовочный файл Lanter/Lan4GateInclude.h \n
/// Данный файл подключает следующие классы: \n
/// Lanter::Manager::Lan4GateFactory - Фабрика главного менеджера библиотеки, инкапсулирующий весь функционал \n
/// Lanter::Communication::CommunicationFactory - Фабрика соединений \n
/// Lanter::Utils::Version - Класс для получения версии библиотеки \n

/// \brief Главное пространство имен. Содержит весь код библиотеки
namespace Lanter
{
    /// \brief Пространство имен сообщений.
    /// \details Содержит пространства имен конкретных сообщений и перечисление с кодами операций Message::OperationCode
    namespace Message
    {
        /// \brief Пространство имен уведомлений от финансового ПО LAN-4Tap.
        /// \details Содержит контейнер INotificationData, его фабрику NotificationDataFactory и перечисление с кодами
        /// уведомлений Notification::NotificationCode
        namespace Notification { }

        /// \brief Пространство имен команд взаимодействия к финансовому ПО LAN-4Tap.
        /// \details Содержит контейнер IInteractionData, его фабрику InteractionDataFactory и перечисление с кодами
        /// уведомлений Interaction::InteractionCode
        namespace Interaction { }

        /// \brief Пространство имен уведомлений от финансового ПО LAN-4Tap.
        /// \details Содержит контейнер IReceiptData, его фабрику ReceiptDataFactory и перечисление с кодами
        /// уведомлений Receipt::ReceiptCode
        namespace Receipt {}

        /// \brief Пространство имен запросов к финансовому ПО LAN-4Tap.
        /// \details Содержит контейнер IRequestData, его фабрику RequestDataFactory и перечисление с
        /// доступными полями запроса Request::RequestField
        namespace Request { }

        /// \brief Пространство имен ответов от финансового ПО LAN-4Tap.
        /// \details Содержит контейнер IResponseData, его фабрику ResponseDataFactory и следующие перечисления:\n
        /// Response::ResponseField - доступные поля ответа;\n
        /// Response::CardholderAuthMethod - значения поля ResponseField::CardholderAuthMethod; \n
        /// Response::CardInputMethod - значения поля ResponseField::CardInputMethod \n
        /// Response::Status - значения поля ResponseField::Status и ResponseField::OriginalOperationStatus \n
        namespace Response { }
    }

    /// \brief Пространство имен процессора сообщений
    namespace MessageProcessor
    {
        /// \brief Пространство имен сборщика сообщений.
        /// \details Содержит интерфейс IMessageBuilder и его фабрику MessageBuilderFactory
        namespace Builder { }
        /// \brief Пространство имен парсера сообщений.
        /// \details Содержит интерфейс IMessageParser, его фабрику MessageParserFactory и
        /// перечисление Parser::MessageType с типами сообщений
        namespace Parser { }
    }

    /// \brief Пространство имен для менеджеров библиотеки
    /// На текущий момент содержит только основной менеджер ILan4Gate
    namespace Manager {}
}
#endif //LAN_4GATELIB_DOXYGENMAINPAGE_H