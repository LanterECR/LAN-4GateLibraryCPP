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

project(LAN_4GateLib VERSION 0.9.6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

option(L4G_TESTS "Enable unit-testing" OFF)
option(L4G_BUILD_MODULE "Build module library" ON)
option(L4G_BUILD_SHARED "Build shared library" ON)
option(L4G_BUILD_STATIC "Build static library" ON)
option(L4G_BUILD_SWIG "Build shared library with SWIG integration. SWIG build disable other builds" OFF)
set(L4G_SWIG_TARGET_LANGUAGE "csharp" CACHE STRING  "Target language for SWIG" )

if(NOT L4G_BUILD_SHARED AND NOT L4G_BUILD_STATIC AND NOT L4G_BUILD_MODULE AND NOT L4G_BUILD_SWIG)
    message(FATAL_ERROR "This library must be static or shared. Enable L4G_BUILD_STATIC, L4G_BUILD_SHARED or L4G_BUILD_MODULE flag")
endif()

set(CMAKE_ANDROID_ARCH_ABI armeabi-v7a)

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

if(L4G_BUILD_SWIG)
	SET(SWIG_EXECUTABLE "C:/Toolchain/swigwin-4.0.2/swig.exe")
	SET(SWIG_DIR "C:/Toolchain/swigwin-4.0.2")

    if(NOT "${L4G_SWIG_TARGET_LANGUAGE}" STREQUAL "csharp" AND NOT "${L4G_SWIG_TARGET_LANGUAGE}" STREQUAL "java")
        message(FATAL_ERROR "${L4G_SWIG_TARGET_LANGUAGE} doesn`t support yet")
    endif()

    if("${L4G_SWIG_TARGET_LANGUAGE}" STREQUAL "csharp")
        set(SWIG_IFACE_RESULT_SUFFUX "cs")
        set(SWIG_LANG_PARAMS -${L4G_SWIG_TARGET_LANGUAGE} -namespace Lanter.Lan4Gate -outfile Lan4gateInterface.${SWIG_IFACE_RESULT_SUFFUX})
        set(L4G_SWIG_INTERFACE_OUTDIR ${L4G_SWIG_TARGET_LANGUAGE})
    elseif("${L4G_SWIG_TARGET_LANGUAGE}" STREQUAL "java")
        set(SWIG_IFACE_RESULT_SUFFUX "jar")
        set(SWIG_LANG_PARAMS -${L4G_SWIG_TARGET_LANGUAGE} -package org.lanter.lan4gate)

        find_package(JNI)
        include_directories(${JAVA_INCLUDE_PATH})

        if(JAVA_INCLUDE_PATH2)
            include_directories(${JAVA_INCLUDE_PATH2})
        endif()

        set(L4G_SWIG_INTERFACE_OUTDIR ${L4G_SWIG_TARGET_LANGUAGE}/org/lanter/lan4gate)
    endif()

    FIND_PACKAGE(SWIG REQUIRED)

#    add_custom_command(OUTPUT "Lan4GateSwig_wrap.cxx"
#            COMMAND ${CMAKE_COMMAND} -E make_directory ${L4G_SWIG_INTERFACE_OUTDIR}
#            COMMAND ${SWIG_EXECUTABLE} -outdir ${L4G_SWIG_INTERFACE_OUTDIR}
#            -c++
#            ${SWIG_LANG_PARAMS}
#            -outcurrentdir
#            -I${CMAKE_SOURCE_DIR}/include
#            ${CMAKE_SOURCE_DIR}/include/Lan4GateSwig.i)
			
	execute_process(
            COMMAND ${CMAKE_COMMAND} -E make_directory ${L4G_SWIG_INTERFACE_OUTDIR}
            COMMAND ${SWIG_EXECUTABLE} -outdir ${L4G_SWIG_INTERFACE_OUTDIR}
            -c++
            ${SWIG_LANG_PARAMS}
            -outcurrentdir
            -I${CMAKE_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/include/Lan4GateSwig.i 
			RESULT_VARIABLE res_var)

    add_library(l4g_swig MODULE ${INCLUDE_FILES} ${SOURCE_FILES} ${IMPL_INCLUDE_FILES} ${IMPL_SOURCE_FILES} Lan4GateSwig_wrap.cxx)

    target_include_directories(l4g_swig INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>)

    target_compile_features(l4g_swig INTERFACE cxx_std_11)

    target_link_libraries(l4g_swig ${DEPENDENCIES_LIST})

    target_compile_definitions(l4g_swig PUBLIC LANTER_BUILD_SHARED)
message("LANTER_BUILD_SHARED=${LANTER_BUILD_SHARED}")	

    set_target_properties(l4g_swig PROPERTIES OUTPUT_NAME "Lan4Gate")
    if("${L4G_SWIG_TARGET_LANGUAGE}" STREQUAL "java")
        find_package(Java COMPONENTS Development)

        #расскоментировать для создания списка классов. Результат вставить в JAVA_SRC
        #[[file(GLOB_RECURSE FOUND_JAVA_SRC ${L4G_SWIG_INTERFACE_OUTDIR}/*.java)
        message("!!!!!!!!!!!!!${FOUND_JAVA_SRC}")]]

        set(JAVA_SRC ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/ByteVector.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/CardInputMethod.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/CardholderAuthMethod.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/CommunicationFactory.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/ICommunication.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/IConnectionCallback.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/IInteractionCallback.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/IInteractionData.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/ILan4Gate.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/INotificationCallback.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/INotificationData.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/IRequestCallback.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/IRequestData.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/IResponseCallback.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/IResponseData.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/InteractionCode.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/Lan4Gate.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/Lan4GateFactory.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/Lan4GateJNI.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/NotificationCode.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/OperationCode.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/RequestField.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/RequestFieldsArray.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/ResponseArray.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/ResponseField.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/ResponseFieldsArray.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/SWIGTYPE_p_p_char.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/Status.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/Version.java
                ${CMAKE_CURRENT_BINARY_DIR}/java/org/lanter/lan4gate/imaxdiv_t.java)
        include(UseJava)
        add_jar(Lan4gateInterface
                SOURCES ${JAVA_SRC}
                OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/java)

        add_custom_command(TARGET l4g_swig POST_BUILD
                COMMAND ${CMAKE_COMMAND} --build ${CMAKE_CURRENT_BINARY_DIR} --target Lan4gateInterface)
    endif()


    install(FILES ${CMAKE_BINARY_DIR}/${L4G_SWIG_TARGET_LANGUAGE}/Lan4gateInterface.${SWIG_IFACE_RESULT_SUFFUX} DESTINATION ${L4G_SWIG_TARGET_LANGUAGE})

    install(TARGETS l4g_swig
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION bin
            )
else()
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

    if(L4G_BUILD_MODULE)
        add_library(l4g_module MODULE ${INCLUDE_FILES} ${SOURCE_FILES} ${IMPL_INCLUDE_FILES} ${IMPL_SOURCE_FILES})

        target_include_directories(l4g_module INTERFACE
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                $<INSTALL_INTERFACE:include>)

        target_compile_features(l4g_module INTERFACE cxx_std_11)

        target_link_libraries(l4g_module ${DEPENDENCIES_LIST})

        target_compile_definitions(l4g_module PUBLIC LANTER_BUILD_SHARED)

        add_library(L4G::l4g_module ALIAS l4g_module)

        list(APPEND INSTALLATION_TARGETS l4g_module)
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
endif()

