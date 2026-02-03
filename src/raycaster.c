#include "raycaster.h"
#include <math.h>



void render3D(void)
{
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;

        double rayDirX = dir.x + plane.x * cameraX;
        double rayDirY = dir.y + plane.y * cameraX;

        int mapX = (int)pos.x;
        int mapY = (int)pos.y;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

        double sideDistX;
        double sideDistY;

        int stepX;
        int stepY;

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (pos.x - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - pos.x) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (pos.y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - pos.y) * deltaDistY;
        }

        int hit = 0;
        int side;

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (map[mapY][mapX] > 0)
                hit = 1;
        }

        double perpWallDist;
        if (side == 0)
            perpWallDist = (sideDistX - deltaDistX);
        else
            perpWallDist = (sideDistY - deltaDistY);

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;

        if (drawStart < 0)
            drawStart = 0;

        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;

        if (drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;

        Color color = RED;

        if (side == 1)
        {
            color = MAROON;
        }

        DrawLine(x, 0, x, drawStart, SKYBLUE);

        DrawLine(x, drawStart, x, drawEnd, color);

        DrawLine(x, drawEnd, x, SCREEN_HEIGHT, BROWN);
    }
}