#include "Apple.h"
#include "raymath.h"
#include <iostream>

int width;
int height;
void InitApple(Rectangle& apple, float size)
{
	width = GetScreenWidth();
	height = GetScreenHeight();
	apple.x = GetRandomValue(1, width / size - 2) * size;
	apple.y = GetRandomValue(1, height / size - 2) * size;
	apple.width = size;
	apple.height = size;
}
void SpawnNew(Rectangle& apple)
{
	apple.x = GetRandomValue(1, width / apple.width - 2) * apple.width;
	apple.y = GetRandomValue(1, height / apple.width - 2) * apple.width;
}
