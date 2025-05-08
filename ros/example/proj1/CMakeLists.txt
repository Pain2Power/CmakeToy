cmake_minimum_required(VERSION 3.11)
project(proj1)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(turtlesim REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(talker src/topic_test/publisher_member_function.cpp)
add_executable(listen src/topic_test/subscriber_member_function.cpp)
add_executable(turtle_pose_listen src/turtlesim_listen/subscriber_turtle_pose_function.cpp)

ament_target_dependencies(talker rclcpp std_msgs)
ament_target_dependencies(listen rclcpp std_msgs)
ament_target_dependencies(turtle_pose_listen rclcpp std_msgs turtlesim)

install(TARGETS
  talker
  listen
  turtle_pose_listen
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
