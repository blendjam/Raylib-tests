#include <raylib.h>
#include <iostream>
#include <string>
#include "Apple.h"
#include "Snake.h"

const unsigned int width = 800;
const unsigned int height = 600;
const unsigned int size = 25;

int counter, score;
bool lost;

void DrawGrid();

Rectangle apple;
Snake snake;

void InitGame()
{
	InitApple(apple, size);
	snake = Snake(Vector2{ 25, 25 }, Vector2{ 0.0f, 0.0f }, size);
	score = 0;
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
			std::string scoreText = "Score: " + std::to_string(score);
			DrawText(scoreText.c_str(), width / 2 - MeasureText(scoreText.c_str(), 20) / 2, 5, 20, DARKGRAY);
			DrawRectangleRec(apple, MAROON);
			snake.Draw();
			snake.TakeInput();
			if (counter % 5 == 0)
				snake.Update();
			if (snake.isCollided(apple))
			{
				score++;
				snake.Grow();
				SpawnNew(apple);
			}
		}
		if (snake.checkWallCollision(width - size, height - size) || snake.checkSelfCollision())
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
	for (int i = 1; i < width / size; i++)
	{
		if (i == 1 || i == width / size - 1)
			DrawLineEx(Vector2{ (float)(i * size), (float)size }, Vector2{ (float)(i * size), (float)(height - size) }, 3, DARKGRAY);
		else
			DrawLine(i * size, size, i * size, height - size, GRAY);
	}
	for (int i = 1; i < height / size; i++)
	{
		if (i == 1 || i == height / size - 1)
			DrawLineEx(Vector2{ (float)size, (float)(i * size) }, Vector2{ (float)(width - size), (float)(i * size) }, 3, DARKGRAY);
		else
			DrawLine(size, i * size, width - size, i * size, GRAY);
	}

}