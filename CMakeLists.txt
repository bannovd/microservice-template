cmake_minimum_required(VERSION 3.5)

project(microservice-template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(Poco_INCLUDE_DIRS "/usr/local/include/Poco")
set(PostgreSQL_INCLUDE_DIRS "/usr/include/postgresql")
set(OpenSSL_INCLUDE_DIRS "/usr/include/openssl")

#find_library(Poco_LIBRARIES NAMES PocoFoundation PocoJSON PocoUtil PocoNet PocoSQL)
#find_library(PostgreSQL_LIBRARIES NAMES pq)

include_directories(
    ${Poco_INCLUDE_DIRS}
    ${PostgreSQL_INCLUDE_DIRS}
    ${OpenSSL_INCLUDE_DIRS}
)

add_executable(microservice-template src/main.cpp
                         src/database.cpp
                         src/server.cpp
                         src/check.cpp
                         src/database.h
                         src/server.h
                         src/check.h)

target_link_libraries(microservice-template PUBLIC PocoFoundation PocoJSON PocoUtil PocoNet pq)


