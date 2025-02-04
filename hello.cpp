#include <cstdio>
#include "raylib.h"

int main()
{
    InitWindow(800, 450, "Hello, Raylib!");

    while (true)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, World!", 100, 100, 20, RED);
        EndDrawing();
    }
}