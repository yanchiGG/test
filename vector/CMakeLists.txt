cmake_minimum_required(VERSION 3.10)

project(VectorTestApp)

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
# Make lib with vector
#
add_library(vector STATIC ./src/vector/vector.cpp)

target_include_directories(vector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#
# Unit tests
#
add_executable(tests tests/test_vector.cpp)

target_link_libraries(tests gtest_main vector)

#
# vector app
#
add_executable(testVector ./src/main.cpp)

target_link_libraries(testVector PRIVATE vector)
