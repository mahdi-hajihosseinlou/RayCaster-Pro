#ifndef MAP_H
#define MAP_H

#define MAP_WIDTH 16
#define MAP_HEIGHT 16

#define MINI_MAP_SIZE 300
#define MINI_TILE (MINI_MAP_SIZE / MAP_WIDTH)

extern int map[MAP_WIDTH][MAP_HEIGHT];

void SaveMap(const char* customMap);
void LoadMap(const char* customMap);

#endif