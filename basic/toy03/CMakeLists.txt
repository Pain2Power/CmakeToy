cmake_minimum_required(VERSION 3.0.0)

# set the project name
project(MyCMakeproject VERSION 0.1.0 LANGUAGES C CXX)

# add the executable
add_executable(MyCMakeproject helloworld.cpp)

# set_property(TARGET MyCMakeproject PROPERTY CXX_STANDARD 17)

# Register boost include path
INCLUDE_DIRECTORIES(include . ${Boost_INCLUDE_DIR})

# Bring boost package
add_definitions(-DBOOST_ALL_NO_LIB)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS thread system)

# Register lib
target_link_libraries(JHNET ${Boost_LIBRARIES})