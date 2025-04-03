cmake_minimum_required(VERSION 3.0.0)

# set the project name
project(MyCMakeproject VERSION 0.1.0 LANGUAGES C CXX)

# add the executable
add_executable(MyCMakeproject helloworld.cpp)

# set_property(TARGET MyCMakeproject PROPERTY CXX_STANDARD 17)