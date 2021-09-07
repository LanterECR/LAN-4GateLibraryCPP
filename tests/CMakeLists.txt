project(${CMAKE_PROJECT_NAME}_tests)

find_package(GTest CONFIG REQUIRED)

add_subdirectory(unit_tests)