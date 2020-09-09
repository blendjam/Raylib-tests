#include "raylib-cpp.hpp"
#include <iostream>
#include <GLFW/glfw3.h>
#include "./Includes/ball.h"
#include "./Includes/inputHandler.h"

int main(void)
{
    int screenWidth = 800;
    int screenHeight = 450;
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    raylib::Color background(RAYWHITE);
    raylib::Window w(screenWidth, screenHeight, "Ball Example");
    SetTargetFPS(60);

    // Ball player(raylib::Vector2((float)screenWidth / 2, (float)screenHeight / 2), 50.0f);
    raylib::Vector2 ballPosition = raylib::Vector2((float)screenWidth / 2, (float)screenHeight / 2);
    raylib::Font f1;
    Ball player(ballPosition, 20.0f);
    InputHandler ip;
    while (!w.ShouldClose())
    {
        ip.HandleInput(player);
        BeginDrawing();
        //------------------------------------------------

        player.draw(MAROON);
        f1.DrawText(std::to_string(GetFPS()), raylib::Vector2(10, 10), 20, 1.5, raylib::Color::Green);

        //------------------------------------------------
        player.update();
        background.ClearBackground();
        EndDrawing();
    }

    return 0;
}