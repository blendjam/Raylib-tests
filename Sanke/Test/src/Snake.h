#pragma once
#include <vector>
#include <iostream>
#include <raylib.h>
#include "Block.h"
class Snake
{
public:
	Snake() {}
	Snake(Vector2 pos, Vector2 vel, float size);
	~Snake();
	void Grow();
	void Draw();
	void Update();
	void TakeInput();
	bool checkWallCollision(int width, int height);
	bool isCollided(const Rectangle& other);
private:
	Vector2 oldPos[500];
	std::vector<Block> body;
};

