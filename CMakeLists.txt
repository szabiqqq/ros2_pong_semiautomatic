cmake_minimum_required(VERSION 3.8)
project(ros2_pong_semiautomatic)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/GameState.msg"
  DEPENDENCIES builtin_interfaces
)

include_directories(include)

add_executable(game_manager src/game_manager.cpp)
ament_target_dependencies(game_manager rclcpp std_msgs geometry_msgs)
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(game_manager ${cpp_typesupport_target})

install(TARGETS
  game_manager
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
