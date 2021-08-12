if(BUILD_TESTS)
    project(${CMAKE_PROJECT_NAME}_tests)

    #Подключение GTest
    hunter_add_package(GTest)
    find_package(GTest CONFIG REQUIRED)

    add_subdirectory(unit_tests)
endif()