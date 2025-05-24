#ifndef ROS2_PONG_SEMIAUTOMATIC__GAME_MANAGER_HPP_
#define ROS2_PONG_SEMIAUTOMATIC__GAME_MANAGER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "ros2_pong_semiautomatic/msg/game_state.hpp"

class GameManager : public rclcpp::Node
{
public:
  GameManager();

private:
  void update_game();

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<ros2_pong_semiautomatic::msg::GameState>::SharedPtr state_pub_;

  float ball_x_;
  float ball_y_;
  float ball_vx_;
  float ball_vy_;
};

#endif  // ROS2_PONG_SEMIAUTOMATIC__GAME_MANAGER_HPP_
