# Название проекта
project(LanLogger LANGUAGES CXX)  #указать версию и языки
# Определим стандарт
set(CMAKE_CXX_STANDARD 17)

# Поиск всех заголовочников
file(GLOB_RECURSE INCLUDE_FILES include/*.h)
# Поиск всех исходников
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

# Defines
add_definitions(-DLOG_ADD_CONSOLE)

# Создаем библиотеку
add_library(LanLogger STATIC ${INCLUDE_FILES} ${SOURCE_FILES})

# Линковка p7
target_link_libraries(LanLogger p7)

# Линковка jsoncpp
string(TOUPPER ${CMAKE_BUILD_TYPE} CUR_BUILD_TYPE)
if(${CUR_BUILD_TYPE} MATCHES DEBUG)
  if (WIN32)
    target_link_libraries(LanLogger ${PATH_TO_3RDPARTY}/jsoncpp/libs/windows/jsoncppd.lib)
  else()
    target_link_libraries(LanLogger ${PATH_TO_3RDPARTY}/jsoncpp/libs/linux/jsoncpp.so)
  endif()
else()
  if (WIN32)
    target_link_libraries(LanLogger ${PATH_TO_3RDPARTY}/jsoncpp/libs/windows/jsoncpp.lib)
  else()
    target_link_libraries(LanLogger ${PATH_TO_3RDPARTY}/jsoncpp/libs/linux/jsoncpp.so)
  endif()
endif()
