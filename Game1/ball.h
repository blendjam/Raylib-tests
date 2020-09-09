#ifndef BALL_H
#define BALL_H

class Ball
{
  Vector2 ballMaxSpeed;
  Vector2 ballCurrentSpeed;
  Vector2 ballPosition;
  Color color;
  float ballRadius;

public:
  Ball(float radius, Vector2 position, Color color);
};

#endif // BALL_H