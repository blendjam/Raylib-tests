#include "./ball.h"

Ball::Ball(raylib::Vector2 position, float radius) : ballMaxSpeed(400.5f, 400.5f),
                                                     ballCurrentSpeed(0.0f, 0.0f),
                                                     ballPosition(position),
                                                     ballRadius(radius)
{
}

void Ball::draw(Color color)
{
  ballPosition.DrawCircle(ballRadius, color);
}

void Ball::update()
{
  deltaTime = GetFrameTime();
  ballPosition += ballCurrentSpeed;
}

void Ball::moveRight()
{
  ballCurrentSpeed.x = deltaTime * ballMaxSpeed.x;
}

void Ball::moveLeft()
{
  ballCurrentSpeed.x = -(deltaTime * ballMaxSpeed.x);
}

void Ball::moveDown()
{
  ballCurrentSpeed.y = (deltaTime * ballMaxSpeed.y);
}

void Ball::moveUP()
{
  ballCurrentSpeed.y = -(deltaTime * ballMaxSpeed.y);
}

void Ball::stopX()
{
  ballCurrentSpeed.x = 0;
}
void Ball::stopY()
{
  ballCurrentSpeed.y = 0;
}
raylib::Vector2 Ball::getCurrentSpeed()
{
  return ballCurrentSpeed;
}