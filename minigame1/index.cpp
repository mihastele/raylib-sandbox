#include <cstdio>
#include "raylib.h"

int main()
{
    int windowWidth{800};
    int windowHeight{450};

    const int gravity{1'000};

    bool isInAir{};
    int jumpVal{-600};

    int velocity{0};

    InitWindow(windowWidth, windowHeight, "Hello, Raylib!");

    Texture2D playerTexture = LoadTexture("textures/player.png");
    Rectangle playerRec;
    playerRec.width = playerTexture.width / 6;
    playerRec.height = playerTexture.height;
    playerRec.x = 0;
    playerRec.y = 0;
    Vector2 playerPos;
    playerPos.x = windowWidth / 2 - playerTexture.width / 2;
    playerPos.y = windowHeight - playerTexture.height;

    // animation frame
    int frame{};
    // amount of time before we update the animation frame
    const float updateTime{1.0 / 12.0};
    float runningTime{};

    SetTargetFPS(50);
    while (!WindowShouldClose())
    {

        const float dT{GetFrameTime()};

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
            velocity += gravity * dT;
        }

        if (!isInAir && IsKeyPressed(KEY_SPACE))
        {
            isInAir = true;
            velocity += jumpVal;
        }

        playerPos.y += velocity * dT;

        // update running time
        runningTime += dT;
        if (runningTime >= updateTime)
        {
            runningTime = 0.0;
            // update animation frame
            playerRec.x = frame * playerRec.width;
            frame = ++frame % 6;
        }

        DrawTextureRec(playerTexture, playerRec, playerPos, WHITE);

        EndDrawing();
    }
}