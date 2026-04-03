cmake_minimum_required(VERSION 3.28.3)
project(server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG         52eb8108c5bdec04579160ae17225d66034bd723
    GIT_SHALLOW     TRUE
)

FetchContent_MakeAvailable(googletest)

enable_testing()

set(SOURCE_FILES
    src/main.cpp
    src/Header.cpp
)

set(HEADER_FILES
    include/Header.h
)

add_executable(server ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(server PRIVATE include)

add_subdirectory(tests)