include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


file(GLOB_RECURSE IMPL_SOURCES Impl_tests/*.cpp)

file(GLOB_RECURSE INTERFACE_SOURCES InterfaceTest/*.cpp)

set(TEST_SOURCES ${INTERFACE_SOURCES})

list(APPEND TEST_SOURCES ${IMPL_SOURCES})

add_executable(${CMAKE_PROJECT_NAME}Tests ${TEST_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}Tests GTest::gtest GTest::gtest_main GTest::gmock_main L4G::l4g_static)

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

    add_test(NAME ${TEST_NAME} COMMAND ${CMAKE_PROJECT_NAME}Tests --gtest_filter=${TEST_NAME}*)
endforeach()
