#include <cstdio>
#include "raylib.h"

int main()
{
    int windowWidth{800};
    int windowHeight{450};

    const int gravity{1};

    bool isInAir{};
    int jumpVal{-18};

    Texture2D playerTexture = LoadTexture("textures/player.png");
    Rectangle playerRec;
    playerRec.width = playerTexture.width / 6;
    playerRec.height = playerTexture.height;
    playerRec.x = 0;
    playerRec.y = 0;
    Vector2 playerPos;
    playerPos.x = windowWidth / 2 - playerTexture.width / 2;
    playerPos.y = windowHeight - playerTexture.height;

    int velocity{0};

    InitWindow(windowWidth, windowHeight, "Hello, Raylib!");

    SetTargetFPS(50);
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // perform ground check
        if (playerPos.y >= windowHeight - playerRec.height)
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

        playerPos.y += velocity;

        DrawTextureRec(playerTexture, playerRec, playerPos, WHITE);

        EndDrawing();
    }
}