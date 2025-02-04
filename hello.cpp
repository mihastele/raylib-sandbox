#include <cstdio>
#include "raylib.h"

int main()
{
    InitWindow(800, 450, "Hello, Raylib!");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, World!", 100, 100, 20, RED);
        DrawFPS(10, 10);
        DrawCircle(GetMouseX(), GetMouseY(), 10, GREEN);
        EndDrawing();
    }
}