cmake_minimum_required(VERSION 3.10)
project(Highest_product)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

# Google Test requires threading support
find_package(Threads REQUIRED)

# Add Google Test as a submodule
add_subdirectory(lib/googletest)

# Include Google Test headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Include the GoogleTest module
include(GoogleTest)

# Create a library from src/highest_product.cpp
add_library(highest_product_library src/highest_product.cpp)

# Create an executable from src/main.cpp and link it to the highest_product_library
add_executable(highest_product_run src/main.cpp)
target_link_libraries(highest_product_run highest_product_library)

# Enable testing
enable_testing()

# Add test source files
set(TEST_SOURCES test/highest_product_test.cpp)

# Create test executable
add_executable(main_test ${TEST_SOURCES})

# Link test executable with Google Test libraries, Threads, and highest_product_library
target_link_libraries(main_test gtest gtest_main Threads::Threads highest_product_library)

# Discover and register tests with CTest
gtest_discover_tests(main_test)
