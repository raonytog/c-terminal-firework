#include "includes/map_utils.h"
#include <stdio.h>
#include <stdlib.h>

struct tMap {
    int weight;
    int hight;
    char ** grid;
};

tMap * CreateMap() {
    tMap * map = malloc(sizeof(tMap));
    if (!map) {
        printf("Error in map malloc");
        exit(EXIT_FAILURE);
    }
    
    printf("Type the map's weight: ");
    scanf("%d%*c", &map->weight);

    printf("Type the map's hight: ");
    scanf("%d%*c", &map->hight);

    map->grid = malloc(map->hight * sizeof(char *));
    if (!map->grid) {
        printf("Error in grid malloc");
        exit(EXIT_FAILURE);
    }

    return map;
}