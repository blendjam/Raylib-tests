#include "./inputHandler.h"

void InputHandler::HandleInput(Ball &b1)
{
  if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT))
  {
    if (currentDir == 1)
      b1.moveLeft();
    else if (currentDir == -1)
      b1.moveRight();
  }
  else if (IsKeyDown(KEY_LEFT))
  {
    currentDir = -1;
    b1.moveLeft();
  }
  else if (IsKeyDown(KEY_RIGHT))
  {
    currentDir = 1;
    b1.moveRight();
  }
  else
  {
    b1.stopX();
    currentDir = 0;
  }
  if (IsKeyDown(KEY_DOWN))
  {
    b1.moveDown();
  }
  else if (IsKeyDown(KEY_UP))
  {
    b1.moveUP();
  }
  else
  {
    b1.stopY();
  }
}