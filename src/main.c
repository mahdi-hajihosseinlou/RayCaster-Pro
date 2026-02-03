#include <stdio.h>
#include <raylib.h>
#include "map.h"
#include "player.h"
#include "raycaster.h"

typedef enum
{
    STATE_PLAY_MODE,
    STATE_EDIT_MODE
} GameState;

int main(void)
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RayCasting");

    GameState mode = STATE_PLAY_MODE;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float deltatime = GetFrameTime();
        float moveSpeed = deltatime * 4.0f;
        float rotSpeed = deltatime * 2.0f;

        if (IsKeyPressed(KEY_M))
        {
            mode = (mode == STATE_PLAY_MODE) ? STATE_EDIT_MODE : STATE_PLAY_MODE;
        }

        if (IsKeyPressed(KEY_O))
        {
            SaveMap("CustomMap.txt");
        }

        if (IsKeyPressed(KEY_I))
        {
            LoadMap("CustomMap.txt");
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            RotatePlayer(-rotSpeed);
        }
        if (IsKeyDown(KEY_LEFT))
        {
            RotatePlayer(rotSpeed);
        }

        if (IsKeyDown(KEY_W))
        {
            MovePlayer(1, moveSpeed);
        }
        if (IsKeyDown(KEY_S))
        {
            MovePlayer(-1, moveSpeed);
        }
        if (IsKeyDown(KEY_D))
        {
            MovePlayer(-2, moveSpeed);
        }
        if (IsKeyDown(KEY_A))
        {
            MovePlayer(2, moveSpeed);
        }
        BeginDrawing();
        ClearBackground(BLACK);

        if (mode == STATE_PLAY_MODE)
        {
            render3D();

            int miniX = SCREEN_WIDTH - MINI_MAP_SIZE;
            int miniY = 0;
            int miniTile = MINI_TILE;

            for (int y = 0; y < MAP_HEIGHT; y++)
            {
                for (int x = 0; x < MAP_WIDTH; x++)
                {
                    Color c = (map[y][x] > 0) ? WHITE : DARKGRAY;
                    DrawRectangle(miniX + x * miniTile, miniY + y * miniTile, miniTile, miniTile, c);
                    DrawRectangleLines(miniX + x * miniTile, miniY + y * miniTile, miniTile, miniTile, GRAY);
                }
            }
            int pp3x = miniX + (int)(pos.x * miniTile);
            int pp3y = miniY + (int)(pos.y * miniTile);
            DrawCircle(pp3x, pp3y, 5, RED);

            double arrowLength = 0.4;
            float ex = miniX + (float)((pos.x + dir.x * arrowLength) * miniTile);
            float ey = miniY + (float)((pos.y + dir.y * arrowLength) * miniTile);
            DrawLineEx((Vector2){pp3x, pp3y}, (Vector2){ex, ey}, 2.0f, YELLOW);
        }
        else
        {
            for (int y = 0; y < MAP_HEIGHT; y++)
            {
                for (int x = 0; x < MAP_WIDTH; x++)
                {
                    Color c = (map[y][x] > 0) ? WHITE : BLACK;
                    DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, c);
                    DrawRectangleLines(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GRAY);
                }
            }

            int pp2x = (int)(pos.x * TILE_SIZE);
            int pp2y = (int)(pos.y * TILE_SIZE);
            DrawCircle(pp2x, pp2y, 10, RED);

            double arrowLenFull = 0.4;
            int exFull = (int)((pos.x + dir.x * arrowLenFull) * TILE_SIZE);
            int eyFull = (int)((pos.y + dir.y * arrowLenFull) * TILE_SIZE);
            DrawLineEx((Vector2){pp2x, pp2y}, (Vector2){exFull, eyFull}, 4.0f, RED);

            Vector2 mousePos = GetMousePosition();
            int mapX = (int)(mousePos.x / TILE_SIZE);
            int mapY = (int)(mousePos.y / TILE_SIZE);

            if (mapX >= 0 && mapX < MAP_WIDTH && mapY >= 0 && mapY < MAP_HEIGHT)
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    map[mapY][mapX] = 1;
                }
                if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
                {
                    map[mapY][mapX] = 0;
                }
            }
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}