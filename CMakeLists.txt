cmake_minimum_required(VERSION 3.0.0)
project(bignum VERSION 0.1.0)

include(CTest)
enable_testing()

include(CPack)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB source_files "${source_dir}/*.cpp")


set(build_dir "${CMAKE_CURRENT_BINARY_DIR}/build")

file(MAKE_DIRECTORY "${build_dir}")

list(REMOVE_ITEM source_files "${source_dir}/BigIntOld.cpp")

add_executable(bignum ${source_files})