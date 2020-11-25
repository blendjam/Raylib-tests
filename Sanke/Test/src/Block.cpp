#include "Block.h"
Vector2 offset;
float screenWidth = GetScreenWidth();
float screenHeight = GetScreenHeight();
Block::Block(Vector2 pos, Vector2 vel, float size) : position(pos), velocity(vel), size(size)
{
	state = Direction::DOWN;
}

Block::~Block()
{
}

void Block::Draw(Color color)
{
	DrawRectangleV(position, Vector2{ size, size }, color);
}

void Block::Update()
{
	position.x += velocity.x;
	position.y += velocity.y;
}

void Block::Move(const Direction& dir)
{
	if (dir == Direction::UP && state != Direction::DOWN)
	{
		state = Direction::UP;
		velocity.y = -size;
		velocity.x = 0;
	}
	if (dir == Direction::DOWN && state != Direction::UP)
	{
		state = Direction::DOWN;
		velocity.y = size;
		velocity.x = 0;
	}
	if (dir == Direction::LEFT && state != Direction::RIGHT)
	{
		state = Direction::LEFT;
		velocity.x = -size;
		velocity.y = 0;
	}
	if (dir == Direction::RIGHT && state != Direction::LEFT)
	{
		state = Direction::RIGHT;
		velocity.x = size;
		velocity.y = 0;
	}
}

void Block::TakeInput()
{
	if (IsKeyDown(KEY_UP))
		Move(Direction::UP);
	if (IsKeyDown(KEY_DOWN))
		Move(Direction::DOWN);
	if (IsKeyDown(KEY_RIGHT))
		Move(Direction::RIGHT);
	if (IsKeyDown(KEY_LEFT))
		Move(Direction::LEFT);
}

bool Block::isCollided(const Block& other)
{
	float dist = Vector2Distance(position, other.position);
	if (dist < size)
		return true;
	else
		return false;
}
bool Block::isCollided(const Rectangle& rec)
{
	float dist = Vector2Distance(position, Vector2{ rec.x, rec.y });
	if (dist < size)
		return true;
	else
		return false;

}

bool Block::checkWallCollision(const int& width, const int& height)
{
	if ((position.x + size > width) || (position.x < size) || (position.y + size > height) || (position.y < size))
		return true;
	else
		return false;

}

void Block::Follow(const Block& parent)
{
	position = parent.position;
}

void Block::Stop()
{
	velocity.x = 0;
	velocity.y = 0;
}
