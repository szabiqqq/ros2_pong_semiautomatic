#include "ros2_pong_semiautomatic/game_manager.hpp"

GameManager::GameManager()
: Node("game_manager")
{
  RCLCPP_INFO(this->get_logger(), "GameManager node elindult!");
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GameManager>());
  rclcpp::shutdown();
  return 0;
}
