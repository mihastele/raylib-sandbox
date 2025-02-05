#include <cstdio>
#include "raylib.h"

int main()
{
    int windowWidth{800};
    int windowHeight{450};

    const int gravity{1};

    // rectangle dimensions
    const int width{50};
    const int height{80};

    bool isInAir{};
    int jumpVal{-18};

    int posY{windowHeight - height};
    int velocity{0};

    InitWindow(windowWidth, windowHeight, "Hello, Raylib!");

    SetTargetFPS(50);
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // perform ground check
        if (posY >= windowHeight - height)
        {
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // rectangle is in the air
            velocity += gravity;
        }

        if (!isInAir && IsKeyPressed(KEY_SPACE))
        {
            isInAir = true;
            velocity += jumpVal;
        }

        posY += velocity;

        DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

        EndDrawing();
    }
}