cmake_minimum_required(VERSION 3.10)
project(echoserver_asio)

# Установка стандарта C++20
set(CMAKE_CXX_STANDARD 20)

# Путь к директории с Asio (предполагаем, что Asio клонирован в external/asio)
set(ASIO_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/asio/asio/include)

# Добавление пути к заголовкам Asio
include_directories(${ASIO_INCLUDE_DIR})

# Указание исходных файлов проекта
set(SOURCES
    src/main.cpp
    src/echo_server/Server.cpp
    src/echo_server/Session.cpp
)

# Определение исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(echoserver_asio PUBLIC ${CMAKE_SOURCE_DIR}/src/include())
