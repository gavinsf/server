cmake_minimum_required(VERSION 3.28.3)

project(server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    src/main.cpp
    src/Header.cpp
)

set(HEADER_FILES
    include/Header.h
)

add_executable(server ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(server PRIVATE include)