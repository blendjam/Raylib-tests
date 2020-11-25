#include "Snake.h"

Snake::Snake(Vector2 pos, Vector2 vel, float size)
{
	body.push_back(Block(pos, vel, size));
	for (int i = 0; i < 500; i++)
		oldPos[i] = Vector2{ 0.0, 0.0 };
}

Snake::~Snake()
{
}

void Snake::Draw()
{
	for (int i = 0; i < body.size(); i++)
	{
		if (i == 0)
			body[i].Draw(DARKBLUE);
		else
			body[i].Draw(BLUE);

	}
}

void Snake::Update()
{
	for (int i = 0; i < body.size(); i++)
	{
		if (i == 0)
			body[i].Update();
		else
			body[i].position = oldPos[i - 1];
	}
}
void Snake::TakeInput()
{
	for (int i = 0; i < body.size(); i++) oldPos[i] = body[i].position;
	body[0].TakeInput();
}

void Snake::Grow()
{
	Block parent = body[body.size() - 1];
	body.push_back(parent);
}
bool Snake::isCollided(const Rectangle& other)
{
	return body[0].isCollided(other);
}
bool Snake::checkWallCollision(const int& width, const int& height)
{
	Block head = body[0];
	return head.checkWallCollision(width, height);
}

bool Snake::checkSelfCollision()
{
	for (int i = 2; i < body.size(); i++)
	{
		if (body[0].isCollided(body[i]))
			return true;
	}
	return false;
}
