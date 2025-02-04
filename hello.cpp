#include <cstdio>
#include "raylib.h"

int main()
{
    InitWindow(800, 450, "Hello, Raylib!");

    int offsetX, offsetY = 0;
    SetTargetFPS(50);
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT))
            offsetX++;
        if (IsKeyDown(KEY_LEFT))
            offsetX--;
        if (IsKeyDown(KEY_UP))
            offsetY--;
        if (IsKeyDown(KEY_DOWN))
            offsetY++;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, World!", 100, 100, 20, RED);
        DrawFPS(10, 10);
        DrawCircle(GetMouseX() + offsetX, GetMouseY() + offsetY, 10, GREEN);
        EndDrawing();
    }
}