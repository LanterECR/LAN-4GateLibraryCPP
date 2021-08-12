cmake_minimum_required(VERSION 3.10)

#Подключение и загрузка пакетного менеджера Hunter
set(ENV{HUNTER_ROOT} ${CMAKE_BINARY_DIR}/cmake/hunter)
set(HUNTER_GATE_PATH ${CMAKE_BINARY_DIR}/cmake/HunterGate.cmake)

message("${HUNTER_GATE_PATH}")
if(NOT EXISTS ${HUNTER_GATE_PATH})
    file(DOWNLOAD
            https://raw.githubusercontent.com/cpp-pm/gate/master/cmake/HunterGate.cmake
            ${HUNTER_GATE_PATH})
endif()
include(${HUNTER_GATE_PATH})

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.297.tar.gz"
        SHA1 "3319fe6a3b08090df7df98dee75134d68e2ef5a3"
)


project(LAN_4GateLib)

set(CMAKE_CXX_STANDARD 11)

option(BUILD_TESTS "Enable unit-testing" OFF)

#проверка типа сборки
list(LENGTH LIBRARY_TYPE len)
if(len EQUAL 1)
    string(TOUPPER ${LIBRARY_TYPE} LIB_BUILD_TYPE)
    if(NOT "${LIB_BUILD_TYPE}" STREQUAL "SHARED" AND NOT "${LIB_BUILD_TYPE}" STREQUAL "STATIC")
        message(FATAL_ERROR "Unsupported library type \"${LIBRARY_TYPE}\"")
    endif()
elseif(len GREATER 1)
    message(FATAL_ERROR "Wrong arguments count for LIBRARY_TYPE variable")
else()
    message(WARNING "LIBRARY_TYPE variable does not set. Uses default value - SHARED")
    set(LIB_BUILD_TYPE SHARED include/Lanter/Utils/DoxygenMainpage.h)
endif()

hunter_add_package(asio)
hunter_add_package(jsoncpp)

find_package(jsoncpp CONFIG REQUIRED)

include_directories(include;Impl)
#поиск всех заголовочников
file(GLOB_RECURSE INCLUDE_FILES include/*.h)
#поиск всех исходников
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

#поиск заголовочников имплементации
file(GLOB_RECURSE IMPL_INCLUDE_FILES Impl/*.h)
#поиск исходников имплементации
file(GLOB_RECURSE IMPL_SOURCE_FILES Impl/*.cpp)


add_library(${PROJECT_NAME} #название проекта
            ${LIB_BUILD_TYPE} #тип библиотеки
            ${INCLUDE_FILES} ${SOURCE_FILES} #Файлы интерфейсной части
            ${IMPL_INCLUDE_FILES} ${IMPL_SOURCE_FILES} #Файлы реализации
           )
if("${LIB_BUILD_TYPE}" STREQUAL "SHARED")
    target_compile_definitions(${PROJECT_NAME} PUBLIC LANTER_BUILD_SHARED)
endif()

target_link_libraries(${PROJECT_NAME} jsoncpp_lib_static)

if(BUILD_TESTS)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    option(INSTALL_GTEST OFF)
    enable_testing()
    add_subdirectory(tests)
endif()

if(INSTALL_PATH)
    get_filename_component(ABSOLUTE_PATH ${INSTALL_PATH} ABSOLUTE)
    set(CMAKE_INSTALL_PREFIX ${ABSOLUTE_PATH})
else()
    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME})
endif()

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION lib)
INSTALL(DIRECTORY include/Lanter DESTINATION include)