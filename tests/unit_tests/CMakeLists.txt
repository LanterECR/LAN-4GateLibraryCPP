include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


if(NOT ${LIB_BUILD_TYPE} STREQUAL SHARED)
    file(GLOB_RECURSE IMPL_SOURCES Impl_tests/*.cpp)
endif()

file(GLOB_RECURSE INTERFACE_SOURCES InterfaceTest/*.cpp)

set(TEST_SOURCES ${INTERFACE_SOURCES})

list(APPEND TEST_SOURCES ${IMPL_SOURCES})


foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})

    target_link_libraries(${TEST_NAME} gtest gtest_main ${CMAKE_PROJECT_NAME})

    if(${LIB_BUILD_TYPE} STREQUAL SHARED)
        target_compile_definitions(${TEST_NAME} PUBLIC LANTER_USE_SHARED)
    endif()

    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
