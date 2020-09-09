#ifndef BALL_H
#define BALL_H
#include "Vector2.hpp"

class Ball
{
  raylib::Vector2 ballMaxSpeed;
  raylib::Vector2 ballPosition;
  raylib::Vector2 ballCurrentSpeed;
  float ballRadius;
  float deltaTime;

public:
  Ball(raylib::Vector2 position, float radius);
  void draw(Color);
  void update();
  void moveRight();
  void moveLeft();
  void moveDown();
  void moveUP();
  void stopX();
  void stopY();
  raylib::Vector2 getCurrentSpeed();
};

#endif //BALL_H