cmake_minimum_required(VERSION 3.0.0)
project(bignum VERSION 0.1.0 DESCRIPTION "Big Numbers" LANGUAGES CXX)


# Set path to include directory with header files
include_directories(bignum PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")

# *** Executable ***
add_executable(bignum src/main.cpp include/BigInt.hpp src/Arithmetics.cpp src/Assignment.cpp src/Comparison.cpp src/InputOutput.cpp src/PrivateUtils.cpp src/PublicUtils.cpp src/Constructors.cpp src/UnaryOperators.cpp)

# *** Library ***
add_library(bignum_lib STATIC src/main.cpp include/BigInt.hpp src/Arithmetics.cpp src/Assignment.cpp src/Comparison.cpp src/InputOutput.cpp src/PrivateUtils.cpp src/PublicUtils.cpp src/Constructors.cpp src/UnaryOperators.cpp)



# *** Test ***
add_executable(bignum_test tests/main.cpp  tests/Testing.hpp tests/ArithmeticsTest.hpp tests/AssignmentTest.hpp tests/ComparisonTest.hpp tests/PublicUtilsTest.hpp tests/ConstructorsTest.hpp)
# Linkig the test executable to the library
target_link_libraries(bignum_test PUBLIC bignum_lib)
