Реализация кассового протокола LAN-4Gate
===========================================



![Сборка Linux](https://github.com/dolbaster/LAN-4GateLibraryCPP/workflows/Linux/badge.svg) 
![Сборка macOS](https://github.com/dolbaster/LAN-4GateLibraryCPP/workflows/macOS/badge.svg) 
![Сборка Windows](https://github.com/dolbaster/LAN-4GateLibraryCPP/workflows/Windows/badge.svg)

### Список [будущих изменений](TODO.md) и расширения функионала

Содержание
----------
1. [Описание](#Описание)
2. [Требования](#Требования)
   1. [Стандарт](#Стандарт)
   2. [CMake](#CMake)
   3. [Компиляторы](#Компиляторы)
   4. [Зависимости](#Зависимости)
   5. [Тесты](#Тесты)
3. [Переменные CMake](#Переменные-CMake)
   1. [CMAKE_INSTALL_PREFIX](#CMAKE_INSTALL_PREFIX)
   2. [CMAKE_BUILD_TYPE](#CMAKE_BUILD_TYPE)
   3. [L4G_BUILD_STATIC](#L4G_BUILD_STATIC)
   4. [L4G_BUILD_SHARED](#L4G_BUILD_SHARED)
   5. [ENV{HUNTER_ROOT}](#ENV{HUNTER_ROOT})
4. [Сборка и установка](#Сборка-и-установка)
5. [Подключение к проекту](#Подключение-к-проекту)
   1. [Подключение к CMake](#Подключение-к-CMake)
      1. [add_subdirectory()](#add_subdirecotry())
      2. [find_package()](#find_package())
   2. [Другие системы сборки](#Другие-системы-сборки)
6. [Примеры](#Примеры)


Описание
--------
Библиотека реализует протокол кассового взаимодействия LAN-4Gate компании ЛАНТЕР.

Для разрешения зависимостей используется пакетный менеджер [Hunter](https://hunter.readthedocs.io/en/latest) версии 0.23.313

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

### Тесты
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
Для сборки необходимо склонировать репозиторий, выполнить генерацию, сборку и установку
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
- l4g_shared.dll - динамическая библиотека
- l4g_shared.lib - статическая библиотека для линовки динамической 
- l4g_static.lib - статическая библиотека

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
#### add_subdirectory()
Проект может быть подключен как поддиректория проекта, например [git submodule](https://git-scm.com/book/ru/v2/%D0%98%D0%BD%D1%81%D1%82%D1%80%D1%83%D0%BC%D0%B5%D0%BD%D1%82%D1%8B-Git-%D0%9F%D0%BE%D0%B4%D0%BC%D0%BE%D0%B4%D1%83%D0%BB%D0%B8)

В таком случае предварительная сборка библиотеки не требуется и будет выполнена автоматически вместе с проектом.

Для корректного использования требуется подключение менеджера Hunter ПЕРЕД директивой project 

Пример для следующей иерархии директорий
```
Project
│
└───3rdparty
│   │ LAN-4GateLibraryCPP
| CMakeLists.txt
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

#### find_package()
Используется при предварительно скомпилированной библиотеке. 
Поисковые модули из shared должны быть доступны в переменной [CMAKE_MODULE_PATH](#https://cmake.org/cmake/help/latest/variable/CMAKE_MODULE_PATH.html), переменной [LAN-4GateLib_ROOT](https://cmake.org/cmake/help/latest/variable/PackageName_ROOT.html) или через PATH

```cmake
project(Example)

find_package(LAN-4GateLib)

add_executable(Example source.cpp)

target_link_libraries(Example L4G::l4g_shared)
```
### Другие системы сборки
Примеры
-------

