#pragma once
#include "raylib.h"
#include "raymath.h"

enum class Direction {
	UP, DOWN, LEFT, RIGHT
};

class Block
{
protected:
	Vector2 position;
private:
	Vector2 velocity;
	float size;
	Direction state;
public:
	Block(Vector2 pos, Vector2 vel, float size);
	~Block();
	void Draw(Color color);
	void Update();
	void Move(const Direction& dir);
	void Stop();
	void TakeInput();
	void Follow(const Block& parent);
	bool isCollided(const Block& other);
	bool isCollided(const Rectangle& rec);
	bool checkWallCollision(const int& width, const int& height);
	friend class Snake;
};

