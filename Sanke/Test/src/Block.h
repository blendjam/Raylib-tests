#pragma once
#include "raylib.h"
#include "raymath.h"

enum class Direction {
	UP, DOWN, LEFT, RIGHT
};

class Block
{
private:
public:
	Vector2 position;
	Vector2 velocity;
	float size;
	Direction state;
	float angle;
public:
	Block(Vector2 pos, Vector2 vel, float size);
	~Block();
	void Draw(Color color);
	void Update();
	void Move(const Direction& dir);
	void Stop();
	void TakeInput();
	void Follow(const Block& parent);
	bool isCollided(const Rectangle& other);
};

