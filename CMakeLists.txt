cmake_minimum_required(VERSION 3.10)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

# Подключение и загрузка пакетного менеджера Hunter
# Если данный проект подключен через add_subdirectory, то загрузить и инициировать Hunter не выйдет
if(NOT IS_SUBPROJECT)

    if("$ENV{HUNTER_ROOT}" STREQUAL "")
        set(ENV{HUNTER_ROOT} ${CMAKE_BINARY_DIR}/cmake/hunter)
    endif()
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
endif()

project(LAN_4GateLib VERSION 0.9.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

option(L4G_TESTS "Enable unit-testing" OFF)
option(L4G_BUILD_SHARED "Build shared library" ON)
option(L4G_BUILD_STATIC "Build static library" ON)

if(NOT L4G_BUILD_SHARED AND NOT L4G_BUILD_STATIC)
    message(FATAL_ERROR "This library must be static or shared. Enable L4G_BUILD_STATIC or L4G_BUILD_SHARED flag")
endif()


hunter_add_package(asio)
hunter_add_package(jsoncpp)

find_package(Threads REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)
find_package(asio CONFIG REQUIRED)

include_directories(include;Impl)
#поиск всех заголовочников
file(GLOB_RECURSE INCLUDE_FILES include/*.h)
#поиск всех исходников
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

#поиск заголовочников имплементации
file(GLOB_RECURSE IMPL_INCLUDE_FILES Impl/*.h)
#поиск исходников имплементации
file(GLOB_RECURSE IMPL_SOURCE_FILES Impl/*.cpp)

add_compile_definitions(L4G_VERSION="${PROJECT_VERSION}")
#список зависимостей библиотеки
set(DEPENDENCIES_LIST jsoncpp_object asio::asio_headeronly)

set(INSTALLATION_TARGETS "")
#Исходники будут скомпилированы дважды из-за разных дефайнов
if(L4G_BUILD_STATIC)
    add_library(l4g_static STATIC ${INCLUDE_FILES} ${SOURCE_FILES} ${IMPL_INCLUDE_FILES} ${IMPL_SOURCE_FILES})

    target_include_directories(l4g_static INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>)

    target_compile_features(l4g_static INTERFACE cxx_std_11)

    target_link_libraries(l4g_static ${DEPENDENCIES_LIST})

    add_library(L4G::l4g_static ALIAS l4g_static)

    list(APPEND INSTALLATION_TARGETS l4g_static)
endif()

if(L4G_BUILD_SHARED)
    add_library(l4g_shared SHARED ${INCLUDE_FILES} ${SOURCE_FILES} ${IMPL_INCLUDE_FILES} ${IMPL_SOURCE_FILES})

    target_include_directories(l4g_shared INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>)

    target_compile_features(l4g_shared INTERFACE cxx_std_11)

    target_link_libraries(l4g_shared ${DEPENDENCIES_LIST})

    target_compile_definitions(l4g_shared PUBLIC LANTER_BUILD_SHARED)

    add_library(L4G::l4g_shared ALIAS l4g_shared)

    list(APPEND INSTALLATION_TARGETS l4g_shared)
endif()

if(L4G_TESTS AND L4G_BUILD_STATIC AND NOT IS_SUBPROJECT)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    option(INSTALL_GTEST OFF)
    enable_testing()

    hunter_add_package(GTest)

    add_subdirectory(tests)
endif()

install(DIRECTORY include/Lanter DESTINATION include)

install(TARGETS ${INSTALLATION_TARGETS} EXPORT LAN_4GateLibConfig
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )

install(EXPORT LAN_4GateLibConfig NAMESPACE L4G:: DESTINATION share/LAN_4GateLib/cmake)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/LAN_4GateLibConfigVersion.cmake"
        VERSION
        ${PROJECT_VERSION}
        COMPATIBILITY
        AnyNewerVersion
        )
install(FILES "${PROJECT_BINARY_DIR}/LAN_4GateLibConfigVersion.cmake" DESTINATION share/LAN_4GateLib/cmake)