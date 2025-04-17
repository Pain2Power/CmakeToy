# Set minimum required version of cmake, project name and compile options
cmake_minimum_required(VERSION 3.8)
project(proj1 VERSION 0.1.0 LANGUAGES C CXX)

if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpendantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Build
add_executable(proj1_subscriber src/proj1_subscriber.cpp)
ament_target_dependencies(proj1_subscriber rclcpp std_msgs)

# Install
install(TARGETS
    proj1_subscriber
    DESTINATION lib/${PROJECT_NAME})

# Test
if(BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    ament_lint_auto_find_test_dependencies()
endif()

# Macro for ament package
ament_package()
