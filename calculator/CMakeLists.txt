cmake_minimum_required(VERSION 3.10)

project(CalculatorApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Debug
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wpedantic")

# Release
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Add gtest lib to project
include(FetchContent)
FetchContent_Declare(
  googletest 
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

#
# Make lib with math functions
#
add_library(mathlib SHARED ./src/math_func.cpp)

target_include_directories(mathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#
# Unit tests
#
add_executable(tests tests/test_math.cpp)

target_link_libraries(tests gtest_main mathlib)

#
# Calculator app
#
add_executable(calculator ./src/calculator.cpp)

target_link_libraries(calculator PRIVATE mathlib)
