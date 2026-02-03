#ifndef RAYCASTER_H
#define RAYCASTER_H

#include <raylib.h>
#include "player.h"
#include "map.h"

#define TILE_SIZE 64
#define SCREEN_WIDTH (MAP_WIDTH * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_HEIGHT * TILE_SIZE)

void render3D(void);

#endif