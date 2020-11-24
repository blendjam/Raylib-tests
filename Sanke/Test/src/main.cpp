#include <raylib.h>
#include <iostream>
#include "Apple.h"
#include <vector>
#include "Snake.h"

const unsigned int width = 800;
const unsigned int height = 600;
const unsigned int size = 25;

int counter;
bool lost;

void DrawGrid();

Rectangle apple;
Snake snake;

void InitGame()
{
	InitApple(apple, size);
	snake = Snake(Vector2{ 25, 25 }, Vector2{ 0.0f, 0.0f }, size);
	counter = 0;
	lost = false;
}
int main()
{
	InitWindow(width, height, "Sanke Game");
	SetTargetFPS(60);
	InitGame();
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		float deltaTime = GetFrameTime();
		if (!lost)
		{
			DrawGrid();

			DrawRectangleRec(apple, MAROON);
			snake.Draw();
			snake.TakeInput();
			if (counter % 5 == 0)
				snake.Update();
			if (snake.isCollided(apple))
			{
				snake.Grow();
				SpawnNew(apple);
			}
		}
		if (snake.checkWallCollision(width, height))
		{
			lost = true;
			DrawText("PRESS [ENTER] TO PLAY AGAIN", width / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, height / 2 - 50, 20, GRAY);
			if (IsKeyPressed(KEY_ENTER))
				InitGame();
		}
		EndDrawing();
		counter++;
	}


	CloseWindow();
	return 0;
}
void DrawGrid()
{
	for (int i = 1; i <= width / size; i++)
	{
		DrawLine(i * size, 0, i * size, height, GRAY);
		DrawLine(0, i * size, width, i * size, GRAY);
	}

}