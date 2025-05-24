#include "ros2_pong_semiautomatic/game_manager.hpp"

GameManager::GameManager()
: Node("game_manager"),
  ball_x_(0.0),
  ball_y_(0.0),
  ball_vx_(0.01),  // vízszintes sebesség
  ball_vy_(0.01)   // függőleges sebesség
{
  RCLCPP_INFO(this->get_logger(), "GameManager node elindult!");

  timer_ = this->create_wall_timer(
    std::chrono::milliseconds(50),  // 20 Hz
    std::bind(&GameManager::update_game, this)
  );
}

void GameManager::update_game()
{
  // egyszerű mozgás: csak halad a labda
  ball_x_ += ball_vx_;
  ball_y_ += ball_vy_;

  RCLCPP_INFO(this->get_logger(), "Ball position: [%.2f, %.2f]", ball_x_, ball_y_);

  // egyszerű "fal" visszapattanás logika
  if (ball_x_ > 1.0 || ball_x_ < -1.0) {
    ball_vx_ *= -1.0;
  }
  if (ball_y_ > 1.0 || ball_y_ < -1.0) {
    ball_vy_ *= -1.0;
  }
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GameManager>());
  rclcpp::shutdown();
  return 0;
}
