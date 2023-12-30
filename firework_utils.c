#include "includes/firework_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tFirework {
    char color[6];
    int explosionDelay, size, x, y;
};

tFirework * CreateFirework () {
    tFirework * firework = malloc(sizeof(tFirework));
    if (!firework) {
        printf("Error in map malloc");
        exit(EXIT_FAILURE);
    }
    
    printf("Type firework'color: ");                   scanf("%[^\n]%*c", firework->color);

    printf("Type firework's explosion delay: ");        scanf("%d%*c", &firework->explosionDelay);

    printf("Type firework's size: ");                   scanf("%d%*c", &firework->size);

    printf("Type firework's initial position: ");       scanf("%d %d%*c", &firework->x, &firework->y);

    return firework;
}

void SetTerminalColor (tFirework * firework) {
    if (strcmp(firework->color, "white") == 0) printf("\033[0;37m");
    else if (strcmp(firework->color, "cyan") == 0) printf("\033[0;36m");
    else if (strcmp(firework->color, "purple") == 0) printf("\033[0;35m");
    else if (strcmp(firework->color, "blue") == 0) printf("\033[0;34m");
    else if (strcmp(firework->color, "yellow") == 0) printf("\033[0;33m");
    else if (strcmp(firework->color, "green") == 0) printf("\033[0;32m");
    else if (strcmp(firework->color, "red") == 0) printf("\033[0;31m");
    else if (strcmp(firework->color, "black") == 0) printf("\033[0;30m");
}

void SetDefaultColor () {
    printf("\033[0m");
}

int GetFireworkExplosionDelay (tFirework * firework) {
    if (!firework) {
        printf("Firework do not exist ( GetFireworkExplosionDelay )");
        exit(EXIT_FAILURE);
    }

    return firework->explosionDelay;
}

int GetFireworkSize (tFirework * firework) {
    if (!firework) {
        printf("Firework do not exist ( GetFireworkSize )");
        exit(EXIT_FAILURE);
    }
    
    return firework->size;
}

int GetFireworkPositionX (tFirework * firework) {
    if (!firework) {
        printf("Firework do not exist ( GetFireworkPositionX )");
        exit(EXIT_FAILURE);
    }
    return firework->x;
}

int GetFireworkPositionY (tFirework * firework) {
    if (!firework) {
        printf("Firework do not exist ( GetFireworkPositionY )");
        exit(EXIT_FAILURE);
    }
    return firework->y;
}

void UpdateFireworkPosition (tFirework * firework, int x, int y) {
    if (!firework) {
        printf("Firework do not exist ( UpdateFireworkPosition )");
        exit(EXIT_FAILURE);
    }
    firework->x = x;
    firework->y = y;
}

char * GetFireWorkHexColor (tFirework * firework) {
    if (!firework) {
        printf("Firework do not exist ( GetFireWorkHexColor )");
        exit(EXIT_FAILURE);
    }
    char * color = firework->color;
    return color;
}

void DestroyFirework (tFirework * firework) {
    if (!firework) {
        printf("Firework was freed or do not existed");
        exit(EXIT_FAILURE);
    }

    free(firework);
}