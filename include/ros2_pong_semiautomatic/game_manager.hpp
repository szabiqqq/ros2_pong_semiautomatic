#ifndef ROS2_PONG_SEMIAUTOMATIC__GAME_MANAGER_HPP_
#define ROS2_PONG_SEMIAUTOMATIC__GAME_MANAGER_HPP_

#include "rclcpp/rclcpp.hpp"

class GameManager : public rclcpp::Node
{
public:
  GameManager();

private:
  void update_game();

  rclcpp::TimerBase::SharedPtr timer_;

  float ball_x_;
  float ball_y_;
  float ball_vx_;
  float ball_vy_;
};

#endif  // ROS2_PONG_SEMIAUTOMATIC__GAME_MANAGER_HPP_
