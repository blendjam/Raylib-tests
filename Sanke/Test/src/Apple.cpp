#include "Apple.h"
#include "raymath.h"
#include <iostream>

int width;
int height;
void InitApple(Rectangle& apple, float size)
{
	width = GetScreenWidth();
	height = GetScreenHeight();
	apple.x = GetRandomValue(0, width / size - 1) * size;
	apple.y = GetRandomValue(0, height / size - 1) * size;
	apple.width = size;
	apple.height = size;
}
void SpawnNew(Rectangle& apple)
{
	apple.x = GetRandomValue(0, width / apple.width - 1) * apple.width;
	apple.y = GetRandomValue(0, height / apple.width - 1) * apple.width;
}
