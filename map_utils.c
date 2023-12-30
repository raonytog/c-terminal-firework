#include "includes/map_utils.h"
#include "includes/firework_utils.h"

#include <stdio.h>
#include <stdlib.h>

#include "time.h"

#define DELAY_TIME 200
#define EMPITY ' '
#define FIREWORKS_PARTICLE '*'
#define TEMPORARY_PARTICLE '%'

void delay(int number_of_seconds) {
	// Converting time into milli_seconds
	int milli_seconds = 1000 * number_of_seconds;

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds);
}

struct tMap {
    int weight, hight; // y, x
    char ** grid;
    tFirework * firework;
};

tMap * CreateMap() {
    tMap * map = calloc(1, sizeof(tMap));
    if (!map) {
        printf("Error in map malloc");
        exit(EXIT_FAILURE);
    }

    printf("Type the map's weight: ");              scanf("%d%*c", &map->weight);
    printf("Type the map's hight: ");               scanf("%d%*c", &map->hight);

    map->grid = calloc(1, map->hight * sizeof(char *));
    for (int i = 0; i < GetMapHight(map); i++)
        map->grid[i] = calloc(GetMapWeight(map), sizeof(char));

    for (int i = 0; i < GetMapHight(map); i++)
        for (int j = 0; j < GetMapWeight(map); j++) 
            map->grid[i][j] = EMPITY;

    if (!map->grid) {
        printf("Error in grid malloc");
        exit(EXIT_FAILURE);
    }

    map->firework = CreateFirework();
    int x = GetFireworkPositionX(map->firework), y = GetFireworkPositionY(map->firework);
    map->grid[x][y] = FIREWORKS_PARTICLE;

    return map;
}

tFirework * GetMapFirework(tMap * map) {
    if (!map) {
        printf("Do not exist map");
        exit(EXIT_FAILURE);
    }
    return map->firework;
}

int GetMapHight (tMap * map) {
    if (!map) {
        printf("Do not exist map");
        exit(EXIT_FAILURE);
    }
    return map->hight;
}

int GetMapWeight (tMap * map) {
    if (!map) {
        printf("Do not exist map");
        exit(EXIT_FAILURE);
    }
    return map->weight;
}

void LaunchFireWorkOnMap (tMap * map) {
    SetTerminalColor(map->firework);

    int x = 0, y = 0;
    delay(DELAY_TIME);
    ClearTerminal();
    PrintMap(map);

    for (int i = 0; i < GetFireworkExplosionDelay(map->firework); i++) {
        x = GetFireworkPositionX(map->firework), y = GetFireworkPositionY(map->firework);
        if (x-1 >= 0) {
            map->grid[x-1][y] = FIREWORKS_PARTICLE;
            map->grid[x][y] = EMPITY;
            UpdateFireworkPosition(map->firework, x-1, y);

            delay(DELAY_TIME);
            ClearTerminal();
            PrintMap(map);
        }
    }

    x = GetFireworkPositionX(map->firework), y = GetFireworkPositionY(map->firework);
    for (int k = 0; k < GetFireworkSize(map->firework); k++) {
        for (int i = 0; i < GetMapHight(map); i++) {
            for (int j = 0; j < GetMapWeight(map); j++) {
                if (ThereIsParticleNextTo(map, i, j)) map->grid[i][j] = TEMPORARY_PARTICLE;
            }
        }

        ConvertTempToParticles(map);
        delay(DELAY_TIME);
        ClearTerminal();
        PrintMap(map);
    }

    SetDefaultColor();
    delay(400);
    ClearTerminal();
}

void DestroyMap(tMap * map) {
    if (!map) {
        printf("Map was freed or do not existed");
        exit(EXIT_FAILURE);
    }

    DestroyFirework(map->firework);

    for (int i = 0; i < GetMapHight(map); i++) 
        free(map->grid[i]);
    free(map->grid);

    free(map);
}

void PrintMap (tMap * map) {
    printf("\n");

    for (int i = 0; i < GetMapHight(map); i++) {
        printf("\t\t\t\t\t\t\t\t");
        for (int j = 0; j < GetMapWeight(map); j++) {
            printf("%c", map->grid[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void ConvertTempToParticles (tMap * map) {
    for (int i = 0; i < GetMapHight(map); i++)
        for (int j = 0; j < GetMapWeight(map); j++)
            if (map->grid[i][j] == TEMPORARY_PARTICLE) map->grid[i][j] = FIREWORKS_PARTICLE;
}

void ClearTerminal () {
    printf("\033[H\033[J");
}

bool IsInsideTheMap (tMap * map, int x, int y) {
    if ( (y >= 0 && y < map->weight) && (x >= 0 && x < map->hight)) return true;
    return false;
}

bool ThereIsParticleNextTo (tMap * map, int x, int y) {
    if ( (IsInsideTheMap(map, x-1, y)  &&  map->grid[x-1][y] == FIREWORKS_PARTICLE) || 
         (IsInsideTheMap(map, x+1, y)  &&  map->grid[x+1][y] == FIREWORKS_PARTICLE)  ||
         (IsInsideTheMap(map, x, y-1)  &&  map->grid[x][y-1] == FIREWORKS_PARTICLE) ||
         (IsInsideTheMap(map, x, y+1)) &&  map->grid[x][y+1] == FIREWORKS_PARTICLE) return 1;
    return false;
}