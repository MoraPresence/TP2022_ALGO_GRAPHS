cmake_minimum_required(VERSION 3.0)
project(Graphs_tests CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunreachable-code -pedantic -pthread")

if (ENABLE_TESTING)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -fprofile-arcs -ftest-coverage -fPIC")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
endif ()

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} tests.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${GRAPHS_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GRAPHS_LIBRARIES} GTest::gtest_main)

enable_testing()
add_test(NAME GRAPHS_tests COMMAND GRAPHS_tests)
