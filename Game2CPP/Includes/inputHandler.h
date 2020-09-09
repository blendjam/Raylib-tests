#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "ball.h"

class InputHandler
{
  int currentDir = 0;

public:
  void HandleInput(Ball &);
};

#endif // INPUTHANDLER_H