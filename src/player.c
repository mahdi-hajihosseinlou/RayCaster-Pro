#include <math.h>
#include "player.h"
#include "map.h"

Vector2D pos = {2, 2};
Vector2D dir = {1, 0};
Vector2D plane = {0, 0.66};

void RotatePlayer(double rotSpeed)
{
    double oldDirX = dir.x;
    dir.x = dir.x * cos(-rotSpeed) - dir.y * sin(-rotSpeed);
    dir.y = oldDirX * sin(-rotSpeed) + dir.y * cos(-rotSpeed);
    double oldPlaneX = plane.x;
    plane.x = plane.x * cos(-rotSpeed) - plane.y * sin(-rotSpeed);
    plane.y = oldPlaneX * sin(-rotSpeed) + plane.y * cos(-rotSpeed);
}

void MovePlayer(int direction, float moveSpeed)
{
    double moveX = 0, moveY = 0;
    if (direction == 1 || direction == -1)
    {
        moveX = dir.x * moveSpeed * direction;
        moveY = dir.y * moveSpeed * direction;
    }
    else if (direction == 2 || direction == -2)
    {
        moveX = dir.y * moveSpeed * (direction / 2);
        moveY = -dir.x * moveSpeed * (direction / 2);
    }

    double newPosX = pos.x + moveX;
    double newPosY = pos.y + moveY;

    if (map[(int)pos.y][(int)newPosX] == 0)
        pos.x = newPosX;
    if (map[(int)newPosY][(int)pos.x] == 0)
        pos.y = newPosY;
}