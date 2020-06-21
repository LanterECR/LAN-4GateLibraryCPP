include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


file(GLOB_RECURSE TESTS_SOURCES *.cpp)

foreach(TEST_SOURCE ${TESTS_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})

    target_link_libraries(${TEST_NAME} gtest gtest_main ${CMAKE_PROJECT_NAME})

    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()