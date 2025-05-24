#include "ros2_pong_semiautomatic/game_manager.hpp"
#include "ros2_pong_semiautomatic/msg/game_state.hpp"

using std::placeholders::_1;
using ros2_pong_semiautomatic::msg::GameState;

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

  state_pub_ = this->create_publisher<GameState>("game_state", 10);
}

void GameManager::update_game()
{
  // Labda mozgás frissítés
  ball_x_ += ball_vx_;
  ball_y_ += ball_vy_;

  // Visszapattanás
  if (ball_x_ > 1.0 || ball_x_ < -1.0) {
    ball_vx_ *= -1.0;
  }
  if (ball_y_ > 1.0 || ball_y_ < -1.0) {
    ball_vy_ *= -1.0;
  }

  // Üzenet publikálása
  GameState state_msg;
  state_msg.ball_x = ball_x_;
  state_msg.ball_y = ball_y_;
  state_pub_->publish(state_msg);

  RCLCPP_INFO(this->get_logger(), "Labda: [%.2f, %.2f]", ball_x_, ball_y_);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GameManager>());
  rclcpp::shutdown();
  return 0;
}
