Реализация кассового протокола LAN-4Gate
===========================================

![Сборка Linux](../..//workflows/Linux/badge.svg) 
![Сборка macOS](../..//workflows/macOS/badge.svg) 
![Сборка Windows](../..//workflows/Windows/badge.svg)

[![Release](https://img.shields.io/badge/release-v0.9.5-blue.svg?style=flat)](https://github.com/LanterECR/LAN-4GateLibraryCPP/releases/tag/v0.9.5)
[![badge](https://img.shields.io/badge/document-doxygen-blue)](https://LanterECR.github.io/LAN-4GateLibraryCPP/doxygen/index.html)

[![Total alerts](https://img.shields.io/lgtm/alerts/g/LanterECR/LAN-4GateLibraryCPP.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/LanterECR/LAN-4GateLibraryCPP/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/LanterECR/LAN-4GateLibraryCPP.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/LanterECR/LAN-4GateLibraryCPP/context:cpp)

### Список [будущих изменений](TODO.md) и расширения функционала

Содержание
----------
1. [Описание](#Описание)
2. [Требования](#Требования)
   1. [Стандарт](#Стандарт)
   2. [CMake](#CMake)
   3. [Компиляторы](#Компиляторы)
   4. [Зависимости](#Зависимости)
3. [Тесты](#Тесты)
4. [Переменные CMake](#Переменные-CMake)
   1. [CMAKE_INSTALL_PREFIX](#CMAKE_INSTALL_PREFIX)
   2. [CMAKE_BUILD_TYPE](#CMAKE_BUILD_TYPE)
   3. [L4G_BUILD_STATIC](#L4G_BUILD_STATIC)
   4. [L4G_BUILD_SHARED](#L4G_BUILD_SHARED)
   5. [L4G_BUILD_MODULE](#L4G_BUILD_MODULE)
   6. [L4G_BUILD_SWIG](#L4G_BUILD_SWIG)
   7. [L4G_SWIG_TARGET_LANGUAGE](#L4G_SWIG_TARGET_LANGUAGE)
   8. [ENV{HUNTER_ROOT}](#ENV{HUNTER_ROOT})
5. [Сборка и установка](#Сборка-и-установка)
6. [Подключение к проекту](#Подключение-к-проекту)
   1. [Подключение к CMake](#Подключение-к-CMake)
      1. [Поддиректория проекта](#Поддиректория-проекта))
      2. [Поиск пакета](#Поиск-пакета))
   2. [Другие системы сборки](#Другие-системы-сборки)
   3. [Использование совместно с языками, отличными от C++](#Использование-совместно-с-языками,-отличными-от-C++)
7. [Использование](#Использование)
   1. [C++](#C++)
   2. [C#](#C#)


Описание
--------
Библиотека реализует протокол кассового взаимодействия LAN-4Gate компании ЛАНТЕР.

Для разрешения зависимостей используется пакетный менеджер [Hunter](https://hunter.readthedocs.io/en/latest) версии 0.23.313

Подробная документация сгенерирована [Doxygen](https://www.doxygen.nl/index.html). Доступна по [ссылке](https://LanterECR.github.io/LAN-4GateLibraryCPP/doxygen/index.html) и в шапке файла

Требования
----------

### Стандарт
Библиотека реализована на С++11. Для компиляции требуется поддержка данной версии.
### CMake
Для генерации необходим [CMake](https://cmake.org/download/) версии 3.10 и старше
### Компиляторы
Требования к компиляторам соответствуют таковым у библиотеки [GTest](https://github.com/google/googletest)

Для компиляции требуются версии компиляторов не ниже следующих:
- MSVC 2015
- GCC 5
- clang 5.0

### Зависимости
Проект зависит от нижеперечисленных библиотек. Зависимости разрешаются пакетным менеджером Hunter.cmake
- jsoncpp. Используется Object версия библиотеки
- asio. Используется статическая версия библиотеки
- GTest

Тесты
------

Работа библиотеки проверена на нижеперечисленных компиляторах. Работа с другими версиями не гарантируется
- MSVC версий 2015, 2017 и 2019
- GCC версий 5, 6, 7, 8 и 9
- clang версий 5.0, 6.0, 7, 8, 9 и 10

Переменные CMake
-----------
Для управления сборкой используются следующие переменные CMake. Переменные могут быть опущены

### CMAKE_INSTALL_PREFIX
Стандартная переменная [CMake](https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html), указывающая путь установки библиотеки

По указанному пути будут установлены компоненты библиотеки при вызове команды установки

Без указания переменной установка будет выполнена в директорию по умолчанию. 

### CMAKE_BUILD_TYPE
Стандартная переменная [CMake](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html), указывающая тип сборки библиотек - Debug, Release, MinSizeRel, RelWithDebInfo

### L4G_BUILD_STATIC
Включает или отключает сборку статической версии библиотеки. Включена опция fpic

Значение по умолчанию - ON 
```shell
cmake -DL4G_BUILD_STATIC=[ON|OFF] [прочие опции...]
```
### L4G_BUILD_SHARED
Включает или отключает сборку динамической версии библиотеки. Включена опция fpic

Значение по умолчанию - ON

```shell
cmake -DL4G_BUILD_SHARED=[ON|OFF] [прочие опции...]
```
### L4G_BUILD_MODULE
Включает или отключает сборку динамической модульной библиотеки. Включена опция fpic

Значение по умолчанию - ON

### L4G_BUILD_SWIG
Включает сборку библиотеки с использованием [SWIG](http://www.swig.org). Включение данной опции отключает остальные сборки L4G_BUILD_*.
Будет собрана библиотека с интегрированным интерфейсом доступа из целевого языка и файл, содержащий API на целевом языке

Значение по умолчанию - OFF
```shell
cmake -DL4G_BUILD_SWIG=[ON|OFF] [прочие опции...]
```
### L4G_SWIG_TARGET_LANGUAGE
Указывает целевой язык для генерации обертки с помощью SWIG. Имеет действие только при включенной опции L4G_BUILD_SWIG

В текущей версии поддерживается генерация оберток только для языка C# 

Значение по умолчанию - csharp

```shell
cmake -L4G_BUILD_SWIG=ON -DL4G_SWIG_TARGET_LANGUAGE=csharp [прочие опции...]
```
### L4G_TESTS
Включает или отключает сборку unit-тестов с помощью GTest

Значение по умолчанию - OFF

```shell
cmake -DL4G_TESTS=[ON|OFF] [прочие опции...]
```

### ENV{HUNTER_ROOT}
Переменная окружения, указывающая путь расположения Hunter. 
Если не задана, то Hunter будет скачан и развернут внутри сборочной директории 

Сборка и установка
--------
Для сборки необходимо клонировать репозиторий, выполнить генерацию, сборку и установку
```shell
git clone https://github.com/LanterECR/LAN-4GateLibraryCPP.git
```
Для сборки библиотеки необходимо выполнить одно из нижеперечисленных действий

Без указания опции -G будет использован системный [генератор](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html). 
Сборка и установка с параметрами по умолчанию.
```shell
cd LAN-4GateLibraryCPP
mkdir build
cd build
cmake ..
cmake --build . --target install
```

В директории установки будет создана нижеприведенная иерархия папок. 

Папка bin будет создана только на Windows. В ней находится dll.

Иерархия соответствует ОС Windows.

Список библиотек Windows
- l4g_module.dll - динамическая библиотека
- l4g_shared.dll - динамическая библиотека
- l4g_shared.lib - статическая библиотека для линовки динамической 
- l4g_static.lib - статическая библиотека

ВНИМАНИЕ: Для библиотек Windows в сборке Debug добавляется суффикс d перед точкой.

В папке share находятся модули cmake, используемые командой [find_package()](https://cmake.org/cmake/help/latest/command/find_package.html)
```
Install_dir  
│
└───bin
│   │ l4g_shared.dll
│   
└───include
│   │ Lanter
│     └─── ...    
│
└───lib
|   | l4g_shared.lib
|   | l4g_static.lib
|
└───share
    | LAN_4GateLib
      └───cmake
          | LAN_4GateLibConfig.cmake
          | LAN_4GateLibConfig-release.cmake
          | LAN_4GateLibConfigVersion.cmake
```

В случае сборки SWIG будет сгенерирована библиотека Lan4Gate.dll. Используется совместно с интерфейсным файлом для целевого языка. В случае Debug сборки необходимо удалить суффикс d.

Иерархия каталога установки будет следующей (на примере генерации интерфейса для C#): 
```
Install_dir  
│
└───bin
│   │ Lan4Gate.dll
│   
└───csharp
    | Lan4gateInterface.cs
```
Цели сборки
-----------
После генерации кэша, создаются следующие цели сборки:
- l4g_shared - сборка динамической библиотеки
- l4g_static - сборка статической библиотеки
- install - сборка всех целей и установка в директорию из [CMAKE_INSTALL_PREFIX](#CMAKE_INSTALL_PREFIX)

Подключение к проекту
---------------------
### Подключение к CMake
Для линковки используются следующие [интерфейсные библиотеки](https://cmake.org/cmake/help/latest/command/add_library.html#interface-libraries):
1. L4G::l4g_shared - подключит динамическую библиотеку
2. L4G::l4g_static - подключит статическую библиотеку

Линковка выполняется аналогично примеру:
```cmake
...
add_executable(SomeAwesomeProgram source1.cpp source2.cpp)

target_link_libraries(SomeAwesomeProgram L4G::l4g_shared)
# or
target_link_libraries(SomeAwesomeProgram L4G::l4g_static)
...
```

Интерфейсные библиотеки содержат путь к заголовочным файлам, соответствующим библиотекам и зависимостям.

Вся информация будет автоматически доступна после добавление к линковке

#### Поддиректория проекта
Проект может быть подключен как поддиректория проекта, например [git submodule](https://git-scm.com/book/ru/v2/%D0%98%D0%BD%D1%81%D1%82%D1%80%D1%83%D0%BC%D0%B5%D0%BD%D1%82%D1%8B-Git-%D0%9F%D0%BE%D0%B4%D0%BC%D0%BE%D0%B4%D1%83%D0%BB%D0%B8)

В таком случае предварительная сборка библиотеки не требуется и будет выполнена автоматически вместе с проектом.

Для корректного использования требуется подключение менеджера Hunter ПЕРЕД директивой project. Возможность отключения Hunter появится в следующих версиях.

Пример для следующей иерархии директорий
```
Project
│
└───3rdparty
│   │ LAN-4GateLibraryCPP
|
| CMakeLists.txt
| source.cpp
```

```cmake
set(HUNTER_GATE_PATH ${CMAKE_BINARY_DIR}/cmake/HunterGate.cmake)

if(NOT EXISTS ${HUNTER_GATE_PATH})
   file(DOWNLOAD
           https://raw.githubusercontent.com/cpp-pm/gate/master/cmake/HunterGate.cmake
           ${HUNTER_GATE_PATH})
endif()
include(${HUNTER_GATE_PATH})

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.313.tar.gz"
        SHA1 "6c369e5aab2749a616917df3b23511535f413604"
)

project(Example)

add_subdirectory(3rdparty/LAN-4GateLibraryCPP)

add_executable(Example source.cpp)

target_link_libraries(Example L4G::l4g_shared)
```

#### Поиск пакета
Используется при предварительно скомпилированной библиотеке. 
Поисковые модули из директории shared должны быть доступны в переменной [CMAKE_MODULE_PATH](#https://cmake.org/cmake/help/latest/variable/CMAKE_MODULE_PATH.html), переменной [LAN-4GateLib_ROOT](https://cmake.org/cmake/help/latest/variable/PackageName_ROOT.html) или через PATH

```cmake
project(Example)

find_package(LAN-4GateLib)

add_executable(Example source.cpp)

target_link_libraries(Example L4G::l4g_shared)
```
### Другие системы сборки
Для подключения к системам сборки, отличным от CMake необходимо указать путь к заголовочным файлам и конкретной версии библиотеки

При работе под Windows линковаться должна статическая библиотека l4g_shared.lib

### Использование совместно с языками, отличными от C++
При сборке библиотеки с включённой опцией L4G_BUILD_SWIG будет сгенерирован интерфейсный файл, содержащий API доступа к библиотеке с помощью целевого языка.
Данный файл необходимо подключить к проекту согласно правилам используемого языка


Использование
-------

### C++
Для использования функционала библиотеки с языком C++ необходимо подключить заголовочный файл Lanter/Lan4GateInclude.h

Данный файл подключает фабрику соединений, фабрику менеджера ILan4Gate и функцию получения версии библиотеки.

В следующем примере создается менеджер ILan4Gate с логическим идентификатором 1. Ему передается TCP сервер, обслуживающий единственное соединение, который слушает порт по умолчанию - 20501.


В качестве колбеков передаются реализации интерфейсов из пространства имен Lanter::Manager::Callback; 

Менеджер запускает отдельный поток.

После ожидается ввод пользователя. Если введен символ "q", то происходит выход. В остальных случаях отправляется Sale на 1 рубль

```c++
#include <iostream>

#include "Lanter/Lan4GateIncude.h"

class ConnectionCallback : public Lanter::Manager::Callback::IConnectionCallback {
public:
    ~ConnectionCallback() override = default;

    void newState(bool state) override {
        if(state) {
            std::cout << "==== Gate connected ====" << std::endl;
        } else {
            std::cout << "==== Gate disconnected ====" << std::endl;
        }
    }
};

class RequestCallback : public Lanter::Manager::Callback::IRequestCallback {
public:
    ~RequestCallback() override = default;

    void newData(std::shared_ptr<Lanter::Message::Request::IRequestData> data) override {
        std::cout << std::endl << "===== REQUEST ====" << std::endl;
    }
};

class ResponseCallback : public Lanter::Manager::Callback::IResponseCallback {
public:
    ~ResponseCallback() override = default;

    void newData(std::shared_ptr<Lanter::Message::Response::IResponseData> data) override {
        std::cout << std::endl << "===== RESPONSE ====" << std::endl;
    }
};

class NotificationCallback : public Lanter::Manager::Callback::INotificationCallback{
public:
    ~NotificationCallback() override = default;

    void newData(std::shared_ptr<Lanter::Message::Notification::INotificationData> data) override {
        std::cout << std::endl << "===== NOTIFICATION ====" << std::endl;
    }
};


int main(int argc, char* argv[])
{

    std::cout << " +++++ Lan4Gate library version is " << Lanter::Utils::Version::getVersion() << " +++++" << std::endl;
    auto manager = Lanter::Manager::Lan4GateFactory::getLan4Gate(1, Lanter::Communication::CommunicationFactory::getSingleTcpServer());


    ConnectionCallback connectionCallback;
    manager->addConnectionCallback(connectionCallback);

    RequestCallback requestCallback;
    manager->addRequestCallback(requestCallback);

    ResponseCallback responseCallback;
    manager->addResponseCallback(responseCallback);

    NotificationCallback notificationCallback;
    manager->addNotificationCallback(notificationCallback);

    if(manager->runOnThread() ==Lanter::Manager::ILan4Gate::Status::Success) {
        std::cout << "+++++ Gate started +++++" << std::endl;
    }

    std::string str;
    while(true) {
        std::cin >> str;
        if(str == "q") {
            break;
        }
        auto sale = manager->getPreparedRequest(Lanter::Message::OperationCode::Sale);
        
        sale->setAmount(100); //1 рубль
        sale->setCurrencyCode(643); //Российский рубль
        sale->setEcrMerchantNumber(1);//Логический номер мерчанта
        
        manager->sendMessage(sale);
    }
    return 0;
}
```

### C#
Для использования функционала библиотеки с языком C# необходимо подключить файл Lan4gateInterface.cs, 
содержащий интерфейс доступа, к проекту, а библиотеку Lan4Gate.dll добавить в зависимости проекта. Библиотека должна находиться в одном каталоге с исполняемым файлом

Интерфейс доступа находится в пространстве имен Lanter.Lan4Gate;

ВНИМАНИЕ: SWIG не генерирует interface для C#. Вместо interface генерируются полноценные классы. Анонимная реализация или множественная имплементация невозможна. 

В следующем примере создается менеджер ILan4Gate с логическим идентификатором 1. Ему передается TCP сервер, обслуживающий единственное соединение, который слушает порт по умолчанию - 20501.

В качестве колбеков передаются реализации интерфейсов из пространства имен Lanter.Lan4Gate;

Менеджер запускает отдельный поток.

После ожидается ввод пользователя. Если введен символ "q", то происходит выход. В остальных случаях отправляется FinalizeTransaction

```C#
using System;

namespace Lan4GateExample
{
    class ConnectionCallback : Lanter.Lan4Gate.IConnectionCallback
    {
        public override void newState(bool state)
        {
            if (state)
            {
                Console.WriteLine("==== Gate connected ====");
            }
            else
            {
                Console.WriteLine("==== Gate disconnected ====");
            }
        }
    }

    class RequestCallback : Lanter.Lan4Gate.IRequestCallback
    {
        public override void newData(Lanter.Lan4Gate.IRequestData data)
        {
            Console.WriteLine("===== REQUEST ====");
        }
    }

    class ResponseCallback : Lanter.Lan4Gate.IResponseCallback
    {
        public override void newData(Lanter.Lan4Gate.IResponseData data)
        {
            Console.WriteLine("===== RESPONSE ====");
        }
    }

    class NotificationCallback : Lanter.Lan4Gate.INotificationCallback
    {
        public override void newData(Lanter.Lan4Gate.INotificationData data)
        {
            Console.WriteLine("===== NOTIFICATION ====");
        }
    } 

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(" +++++ Lan4Gate library version is " + Lanter.Lan4Gate.Version.getVersion() + " +++++");

            var manager = Lanter.Lan4Gate.Lan4GateFactory.getLan4Gate(1, Lanter.Lan4Gate.CommunicationFactory.getSingleTcpServer());

            manager.addConnectionCallback(new ConnectionCallback());

            manager.addRequestCallback(new RequestCallback());

            manager.addResponseCallback(new ResponseCallback());

            manager.addNotificationCallback(new NotificationCallback());

            if (manager.runOnThread() == Lanter.Lan4Gate.ILan4Gate.Status.Success)
            {
                Console.WriteLine("+++++ Gate started +++++");
            }

            while(true)
            {
                string str = Console.ReadLine();

                if(str == "q")
                {
                    break;
                }

                manager.sendMessage(manager.getPreparedRequest(Lanter.Lan4Gate.OperationCode.FinalizeTransaction));
            }
        }
    }
}
```