file(GLOB TEST_SOURCES *.cpp)

add_executable(unit_tests 
    ${TEST_SOURCES}
    ../src/Header.cpp
)

target_include_directories(unit_tests PRIVATE ../include)

target_link_libraries(unit_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)