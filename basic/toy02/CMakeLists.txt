cmake_minimum_required(VERSION 3.0.0)
project(toy02 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(main main.cpp)

enable_testing()
add_test(NAME SimpleTest COMMAND main)
