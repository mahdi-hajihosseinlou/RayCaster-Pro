#ifndef PLAYER_H
#define PLAYER_H

typedef struct
{
    double x, y;
} Vector2D;

extern Vector2D dir;
extern Vector2D pos;
extern Vector2D plane;

void MovePlayer(int direction, float moveSpeed);
void RotatePlayer(double rotSpeed);

#endif
