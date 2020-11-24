#include "Snake.h"

Snake::Snake(Vector2 pos, Vector2 vel, float size)
{
	body.push_back(Block(pos, vel, size));
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
bool Snake::checkWallCollision(int width, int height)
{
	Block head = body[0];
	if ((head.position.x + head.size > width) || (head.position.x < 0) || (head.position.y + head.size > height) || (head.position.y < 0))
		return true;
	else
		return false;
}
