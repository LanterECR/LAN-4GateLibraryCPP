cmake_minimum_required(VERSION 3.10)

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


#поиск Python 3.4+
find_package (Python3 COMPONENTS Interpreter)
if(NOT Python3_FOUND OR NOT Python3_Interpreter_FOUND)
    message(FATAL_ERROR "Python 3 not found. Check PATH variable")
elseif(${Python3_VERSION_MINOR} LESS 4)
    message(FATAL_ERROR "Python 3 found, but old version. Python 3.4 or newer required")
endif()

#Путь к JSONCPP в 3rdparty
set(JSONCPP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/jsoncpp)
set(JSONCPP_AMALGAMATE_SCRIPT_PATH ${JSONCPP_PATH}/amalgamate.py)
if(EXISTS ${JSONCPP_AMALGAMATE_SCRIPT_PATH})
    execute_process(COMMAND ${Python3_EXECUTABLE} ${JSONCPP_AMALGAMATE_SCRIPT_PATH}
                    WORKING_DIRECTORY ${JSONCPP_PATH})
else()
    message(FATAL_ERROR "JSONCPP amalgamate script not found in ${JSONCPP_AMALGAMATE_SCRIPT_PATH}. Use git submodule update --init command for submodule init.")
endif()
#Подключение amalgamation версии jsoncpp
#EXISTS проверят полный путь
set(JSONCPP_AMALGAMATION_PATH ${JSONCPP_PATH}/dist)
if(EXISTS ${JSONCPP_AMALGAMATION_PATH})
    set(JSONCPP_INCLUDE_PATH ${JSONCPP_AMALGAMATION_PATH})

    file(GLOB_RECURSE JSONCPP_SOURCES ${JSONCPP_AMALGAMATION_PATH}/*.cpp)
    if("${JSONCPP_SOURCES}" STREQUAL "")
        message(FATAL_ERROR "JSONCPP amalgamation source files not exists")
    endif()

    file(GLOB_RECURSE JSONCPP_HEADERS ${JSONCPP_AMALGAMATION_PATH}/*.h)
    if("${JSONCPP_HEADERS}" STREQUAL "")
        message(FATAL_ERROR "JSONCPP amalgamation header files not exists")
    endif()

else()
    message(FATAL_ERROR "Directory contains JSONCPP amalgamation sources not exists")
endif()

include_directories(${JSONCPP_INCLUDE_PATH};include;Impl)
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
            ${JSONCPP_HEADERS} ${JSONCPP_SOURCES} #Amalgamation исходники JSONCpp
            ${INCLUDE_FILES} ${SOURCE_FILES} #Файлы интерфейсной части
            ${IMPL_INCLUDE_FILES} ${IMPL_SOURCE_FILES} #Файлы реализации
           )
if("${LIB_BUILD_TYPE}" STREQUAL "SHARED")
    target_compile_definitions(${PROJECT_NAME} PUBLIC LANTER_BUILD_SHARED)
endif()

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