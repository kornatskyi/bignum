cmake_minimum_required(VERSION 3.0.0)
project(bignum VERSION 0.1.0 DESCRIPTION "Big Numbers" LANGUAGES CXX)

include(CTest)
enable_testing()

include(CPack)

include_directories(include)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")

# *** Executable ***
add_executable(bignum src/main.cpp src/BigInt.cpp include/BigInt.hpp)

# *** Library ***
add_library(bignum_lib STATIC src/main.cpp src/BigInt.cpp include/BigInt.hpp)

target_include_directories(bignum_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(bignum PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# If you only include this third party in PRIVATE source files, you do not
# need to install it when your main project gets installed.
# set(JSON_Install OFF CACHE INTERNAL "")

# Don't use include(nlohmann_json/CMakeLists.txt) since that carries with it
# unintended consequences that will break the build.  It's generally
# discouraged (although not necessarily well documented as such) to use
# include(...) for pulling in other CMake projects anyways.
add_subdirectory(libs/json)

# *** Test ***
add_executable(bignum_test tests/main.cpp tests/TestBigInt.hpp tests/Testing.hpp)
# Linkig the test executable to the library
target_link_libraries(bignum_test PUBLIC bignum_lib)

target_link_libraries(bignum_test PRIVATE nlohmann_json::nlohmann_json)