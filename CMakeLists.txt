cmake_minimum_required(VERSION 3.8)
project(ros2_pong_semiautomatic)

# Alapértelmezett C++ verzió
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Fordítási figyelmeztetések
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Kötelező ROS2 csomagok
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# Függőségek
set(ament_dependencies
  rclcpp
  std_msgs
  geometry_msgs
)

# Fejléc mappák
include_directories(include)

# 🔧 A saját node-od: game_manager
add_executable(game_manager src/game_manager.cpp)
ament_target_dependencies(game_manager ${ament_dependencies})

# Telepítés
install(TARGETS
  game_manager
  DESTINATION lib/${PROJECT_NAME}
)

# Launch fájlok (ha vannak)
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
