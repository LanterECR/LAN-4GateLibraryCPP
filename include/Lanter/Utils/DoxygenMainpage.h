#ifndef LAN_4GATELIB_DOXYGENMAINPAGE_H
#define LAN_4GATELIB_DOXYGENMAINPAGE_H

/// \mainpage Документация библиотеки LAN-4Gate
/// \section description Описание
/// Библиотека реализует протокол кассового взаимодействия LAN-4Gate компании ЛАНТЕР на языке C++ (стандарт C++11).\n
/// Библиотека может быть собрана, как статическая, так и как динамическая. \n
/// Если библиотека собрана в виде динамической, то интерфейсные классы будут экспортированы для возможности линковки с
/// библиотекой. \n
/// Для взаимодействия с библиотекой можно использовать любые языки, способные работать с классами C++
/// \section features Возможности
/// Библиотека поддерживает следующие функции:
/// 1. Валидация и хранение полей в контейнерах запросов (Lanter::Message::Request::IRequestData),
/// ответов (Lanter::Message::Response::IResponseData) и уведомлений (Lanter::Message::Notification::INotificationData);
/// 2. Сборка сообщений в вектор байтов (Lanter::MessageProcessor::Builder::IMessageBuilder);
/// 3. Парсинг сообщений из вектора байтов (Lanter::MessageProcessor::Parser::IMessageParser);
/// \section requirements_and_build Требования и сборка
/// \subsection build_requirements Требования для сборки
/// Для сборки библиотеки необходимо следующее программное обеспечение:
/// 1. CMake 2.8.8 или старше;
/// 2. Python 3.4 или старше;
/// 3. Компилятор с поддержкой стандарта C++11. Минимум MSVC 14.0, GCC 4.7, clang 3.3 или аналогичные
/// (см. C++11 core language features в https://en.cppreference.com/w/cpp/compiler_support).
/// \subsection build_preparation Подготовка к сборке
/// Для сборки библиотеки пути к перечисленному в предыдущем разделе программному обеспечению должны быть доступны через
/// переменную PATH.
/// Для Python должен быть доступен модуль Python3Config.cmake. Обычно он находится автоматически после установки пакета.
/// Если не доступен, то путь к нему можно прописать через параметр cmake "CMAKE_MODULE_PATH".
/// \subsection cmake_variables Пременные CMake
/// Для сборки библиотеки введены дополнительные переменные CMake:
/// - LIBRARY_TYPE=[STATIC|SHARED]. Тип собираемой библиотеки;
/// При значении STATIC будет собрана статическая библиотека (файлы с расширением *.a или *.lib, в зависимости от целевой ОС)ю\n
/// Если не указать данный параметр, будет использовано значение по умолчанию SHARED и собрана динамическая библиотеки;
/// - BUILD_TESTS=[ON|OFF]. Флаг для сборки и запуска модульных тестов. Если параметр LIBRARY_TYPE установлен в значение
/// SHARED, то будут созданы тесты только для внешнего интерфейса библиотеки;
/// - INSTALL_PATH=[path]. Путь к директории, в которой будет размещена библиотека после сборки и установки.
/// Внутри данной директории будут созданы папки include (содержит заголовочные файлы) и lib (содержит файлы библиотеки).\n
/// Если переменная не установлена, то используется путь по умолчанию - внутри сборочной директории будет создана директория
/// install/LAN_4GateLib;
///
/// В квадратных скобках [] указаны возможные значения переменной. При передаче в CMake необходимо использовать только один вариант.\n
/// Пути передаются в формате операционной системы. Например, на месте значения "/path/to/repo" может быть путь "~/repo" или
/// "D:\repo"
/// \subsection build Сборка
/// Для сборки библиотеки выполните следующие шаги (действия описываются для консоли):
/// 1. Склонируйте репозиторий в удобную директорию;
/// 2. Инициируйте сабмодули репозитория командой "git submodule update --init" или аналогичной в графическом интерфейсе;
/// 3. Создайте директорию для сборки в удобном месте и перейдите в нее;
/// 4. В созданной директории выполните команду "cmake -DLIBRARY_TYPE=[STATIC|SHARED] -DBUILD_TESTS=[ON|OFF]
/// -DINSTALL_PATH=/path/to/install -DCMAKE_BUILD_TYPE=[Debug|Release|MinSizeRel] /path/to/repo";
/// 5. Для сборки выполните команду "cmake --build .". Для сборки в несколько потоков после
/// данной команды необходимо указать опцию "--parallel n", где n - количество потоков сборки. Например, для 4 потоков
/// необходимо выполнить команду "cmake --build . --parallel 4"
/// 6. Для установки библиотеки по окончании сборки выполните команду "cmake install .". Заголовочные файлы и библиотека
/// будет перемещена по пути INSTALL_PATH
/// \section attaching Подключение
/// Для использования собранной библиотеки в проекте необходимо выполнить следующие действия:
/// - Добавить директорию include по пути INSTALL_PATH в список директорий поиска заголовочных файлов;
/// - Добавить директорию lib по пути INSTALL_PATH в список директорий поиска библиотек;
/// - Если целевая ОС - Windows, то, в случае, если библиотека собиралась с параметром "LIBRARY_TYPE=SHARED",
/// необходимо определить макрос препроцессора (definition) "LANTER_USE_SHARED".
/// \section using Использование
/// - Для создания сообщений необходимо подключить заголовочные файлы, содержащие фабрики
/// Lanter::Message::Request::RequestDataFactory и Lanter::MessageProcessor::Builder::MessageBuilderFactory.\n
/// Пример создания сообщения на основе запроса сообщения Lanter::Message::OperationCode::Sale:
/// \code{.cpp}
///#include <Lanter/Message/Request/RequestDataFactory.h> //Подключение фабрики контейнера IRequestData
///#include <Lanter/MessageProcessor/Builder/MessageBuilderFactory.h> //Подключение фабрики сборщика MessageBuilderFactory
///
///#include <iostream>
///
///using namespace Lanter::MessageProcessor::Builder;
///using namespace Lanter::Message;
///using namespace Lanter::Message::Request;
///
///int main(int argc, char** argv) {
///    std::vector<uint8_t> outputData; //Контейнер для данных запроса
///
///    std::shared_ptr<IMessageBuilder> builder = MessageBuilderFactory::getMessageBuilder(); //Получение сборщика сообщений
///
///    bool messageCreated = false; //Переменная для индикации результата сборки
///
///    if(builder) { ///Проверка создался ли сборщик
///
///        OperationCode operationCode = OperationCode::Sale; //код запрашиваемой операции
///        int16_t ecrNumber = 1; //Логический идентификатор кассового ПО, используемый для взаимодействия с LAN-4Tap
///        int16_t ecrMerchantNumber = 1; ///Логический идентификатор мерчанта в кассовом ПО
///        int64_t amount = 1000; //Сумма продажи. Сумма указывается в минимальных единицах валюты. В данном случае - 10 рублей
///        int16_t currencyCode = 643; //Цифровой код валюты согласно ISO 4217
///
///        //Получение контейнера для запроса. Код операции и логический идентификатор кассового ПО автоматически установятся
///        //при создании объекта
///        std::shared_ptr<IRequestData> requestData = RequestDataFactory::getRequestData(operationCode, ecrNumber);
///
///        bool dataOk = requestData &&//Проверка создался ли контейнер для запроса
///                      requestData->setEcrMerchantNumber(ecrMerchantNumber) && //и корректно ли установились поля запроса
///                      requestData->setAmount(amount) &&
///                      requestData->setCurrencyCode() &&
///                      requestData->validateMandatoryFields(); //Проверка все ли обязательные поля установлены
///
///        if(dataOk) {
///            messageCreated = builder->createMessage(requestData, outputData); //создание сообщения
///        }
///
///        if(messageCreated) {
///            std::cout << "Message created. Length = " << outputData.size() << std::endl;
///        } else {
///            std::cout << "Message creation error" << std::endl;
///        }
///    }
///    return 0;
///}
///\endcode
/// - TODO: Дописать ответы и уведомления

/// \brief Главное пространство имен. Содержит весь код библиотеки
namespace Lanter {

    /// \brief Пространство имен сообщений.
    /// \details Содержит пространства имен конкретных сообщений и перечисление с кодами операций Message::OperationCode
    namespace Message {

        /// \brief Пространство имен уведомлений от финансового ПО LAN-4Tap.
        /// \details Содержит контейнер INotificationData, его фабрику NotificationDataFactory и перечисление с кодами
        /// уведомлений Notification::NotificationCode
        namespace Notification { }

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
    namespace MessageProcessor {
        /// \brief Пространство имен сборщика сообщений.
        /// \details Содержит интерфейс IMessageBuilder и его фабрику MessageBuilderFactory
        namespace Builder { }
        /// \brief Пространство имен парсера сообщений.
        /// \details Содержит интерфейс IMessageParser, его фабрику MessageParserFactory и
        /// перечисление Parser::MessageType с типами сообщений
        namespace Parser { }
    }
}
#endif //LAN_4GATELIB_DOXYGENMAINPAGE_H
